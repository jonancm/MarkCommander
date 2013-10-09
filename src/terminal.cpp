// Copyright 2011 Jonán C. Martín
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "terminal.hpp"
#include "rhinolang.hpp"

#include <ctime>

Terminal::Terminal()
{
    _serialPort = NULL;

    _waitTimer = new QTimer(this);
    QObject::connect(_waitTimer, SIGNAL(timeout()), this, SLOT(abortWaitResponse()));
    _pollTimer = new QTimer(this);
    QObject::connect(_pollTimer, SIGNAL(timeout()), this, SLOT(pollController()));

    setPromptTxt(">> ");

    setInputTxtColor("rgb(186, 186, 186);"); // gray
    setOutputTxtColor("");
    setBgColor("rgb(0, 0, 0);");             // black
    setTxtFontFamily("Courier New");
}

Terminal::~Terminal()
{
    if (isConnected())
        disconnect();
    delete _pollTimer;
    delete _waitTimer;
}

void Terminal::setPort(QString comPort)
{
    if (comPort.isEmpty())
        throw new InvalidComPortError();
    if (isConnected())
        throw new PortChangeWhileConnectedError();
    _portId = comPort;
}

void Terminal::connect()
{
    if (port().isEmpty())
        throw new InvalidComPortError();
    else
    {
        if (_serialPort == NULL)
        {
            _serialPort = new QextSerialPort(port());
            _serialPort->setBaudRate(BAUD9600);
            _serialPort->setDataBits(DATA_7);
            _serialPort->setParity(PAR_EVEN); // RoboTalk manual: even / Mark IV manual: odd
            _serialPort->setStopBits(STOP_2);
            _serialPort->setFlowControl(FLOW_HARDWARE);
        }
        if (!_serialPort->open(QIODevice::ReadWrite)) // has no effect if port is already open
            throw new ErrorOpeningComPort();
    }
}

void Terminal::disconnect()
{
    _serialPort->close(); // has no effect if port is already closed
    delete _serialPort;
    _serialPort = NULL;
    _waitTimer->stop();
}

bool Terminal::isConnected()
{
    return _serialPort != NULL && _serialPort->isOpen();
}

QString Terminal::port()
{
    return _portId;
}

QString Terminal::promptTxt()
{
    return _promptTxt;
}

void Terminal::setPromptTxt(QString newPrompt)
{
    _promptTxt = newPrompt;
}

bool Terminal::sendCmdAndTellMustWait(QString cmd)
{
    // send command to controller
    QByteArray cmdBytes = cmd.toAscii();
    _serialPort->write(cmdBytes);
    _serialPort->write(CMDEND);

    // get output from controller without blocking the GUI (using a QTimer)
    // (only if controller shall produce a response for the sent command)
    if (mustWaitResponseFromCmd(cmd.left(2)))
    {
        _pollTimer->start(POLL_INTERVAL);
        _waitTimer->start(CMD_TIMEOUT);
    }
    else
        return false; // tell must not wait

    return true; // tell must wait
}

QString Terminal::sendCmdSynchronous(QString cmd)
{
    QByteArray cmdBytes = cmd.toAscii();
    _serialPort->write(cmdBytes);
    _serialPort->write(CMDEND);
    if (mustWaitResponseFromCmd(cmd.left(2)))
    {
        int indexOfCmdEnd;
        time_t startTime = time(NULL);

        while ((_serialPort->bytesAvailable() == 0) && (time(NULL) - startTime < CMD_TIMEOUT/1000));

        if (_serialPort->bytesAvailable() > 0)
        {
            _comBuffer.append(_serialPort->readAll());
            indexOfCmdEnd = _comBuffer.indexOf(CMDEND); // cmd separator for command line
            if (indexOfCmdEnd != -1)
            {
                QByteArray responseBytes;

                responseBytes = _comBuffer.left(indexOfCmdEnd);
                _comBuffer = _comBuffer.right(_comBuffer.size() - (indexOfCmdEnd + strlen(CMDEND)));

                QString response;
                for (int i = 0; i < indexOfCmdEnd; i++)
                    response += responseBytes.at(i);
                return response;
            }
        }
        else
            emit timeout(CMD_TIMEOUT);
    }
    return "";
}

QString Terminal::inputTxtColor()
{
    return _inputTxtColor;
}

QString Terminal::outputTxtColor()
{
    return _outputTxtColor;
}

QString Terminal::bgColor()
{
    return _bgColor;
}

QString Terminal::txtFontFamily()
{
    return _txtFontFamily;
}

QString Terminal::txtFontSize()
{
    return _txtFontSize;
}

void Terminal::setInputTxtColor(QString color)
{
    _inputTxtColor = color;
}

void Terminal::setOutputTxtColor(QString color)
{
    _outputTxtColor = color;
}

void Terminal::setBgColor(QString color)
{
    _bgColor = color;
}

void Terminal::setTxtFontFamily(QString fontFamily)
{
    _txtFontFamily = fontFamily;
}

void Terminal::setTxtFontSize(QString fontSize)
{
    _txtFontSize = fontSize;
}

void Terminal::pollController()
{
    int  indexOfCmdEnd, indexOfFileEnd;

    if (_serialPort->bytesAvailable() > 0)
    {
        _pollTimer->stop();
        _waitTimer->stop();
        _comBuffer.append(_serialPort->readAll());
        indexOfCmdEnd = _comBuffer.indexOf(CMDEND); // cmd separator for command line
        if (indexOfCmdEnd != -1)
        {
            QByteArray responseBytes;

            responseBytes = _comBuffer.left(indexOfCmdEnd);
            _comBuffer = _comBuffer.right(_comBuffer.size() - (indexOfCmdEnd + strlen(CMDEND)));

            QString response;
            for (int i = 0; i < indexOfCmdEnd; i++)
                response += responseBytes.at(i);
            emit receivedFullResponse(response);
        }
        indexOfFileEnd = _comBuffer.lastIndexOf(FILEEND); // cmd separator for program files
        if (indexOfFileEnd != -1)
        {
            QByteArray responseBytes;

            responseBytes = _comBuffer.left(indexOfFileEnd);
            _comBuffer = _comBuffer.right(_comBuffer.size() - (indexOfFileEnd + strlen(FILEEND)));

            RhinoProg *prog = new RhinoProg(responseBytes);
            emit receivedProgram(prog);
        }
        if (indexOfCmdEnd == -1 && indexOfFileEnd == -1)
        {
            _pollTimer->start(POLL_INTERVAL);
            _waitTimer->start(FILE_TIMEOUT);
        }
    }
}

void Terminal::abortWaitResponse()
{
    _pollTimer->stop();
    _waitTimer->stop();
    emit timeout(_waitTimer->interval());
}

void Terminal::sendProgram(QByteArray code)
{
    _serialPort->write("FR");
    _serialPort->write(CMDEND);
    // send program
    _serialPort->write(code);
    _serialPort->write(FILEEND);
}

void Terminal::getProgram()
{
    _serialPort->write("FT");
    _serialPort->write(CMDEND);

    _pollTimer->start(POLL_INTERVAL);
    _waitTimer->start(FILE_TIMEOUT);
}

/*************************************************************************************************************
 *                                                    EXCEPTIONS
 ************************************************************************************************************/

InvalidComPortError::InvalidComPortError()
{
    _description = QObject::tr("Invalid port number");
    setMessage(QObject::tr("Invalid port number: port number must be non-negative"));
}

ErrorOpeningComPort::ErrorOpeningComPort()
{
    _description = QObject::tr("Error opening serial port");
    setMessage(QObject::tr("Error opening serial port"));
}

PortChangeWhileConnectedError::PortChangeWhileConnectedError()
{
    _description = QObject::tr("Port change while connection is open");
    setMessage(QObject::tr("Cannot change port number: connection is already "
                           "open, you should close it first"));
}
