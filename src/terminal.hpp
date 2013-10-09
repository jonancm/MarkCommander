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

#ifndef TERMINAL_H
#define TERMINAL_H

#include <QObject>
#include <QString>
#include <QTimer>

#include "exception.hpp"
#include "rhinoprog.hpp"

#include <qextserialport.h>

#define POLL_INTERVAL    100   // poll serial port every 0.1 seconds
#define CMD_TIMEOUT      10000 // wait response from Mark IV for 10 seconds
#define FILE_TIMEOUT     20000 // wait response from Mark IV for 10 seconds

class Terminal : public QObject
{
    Q_OBJECT

private:
    QString            _portId;
    QextSerialPort *   _serialPort;
    QTimer         *   _pollTimer;
    QTimer         *   _waitTimer;
    QByteArray         _comBuffer;       // communication buffer
    QString            _inputTxtColor;
    QString            _outputTxtColor;
    QString            _bgColor;
    QString            _txtFontFamily;
    QString            _txtFontSize;
    QString            _promptTxt;       // text to use as prompt

public:
                  Terminal();
                 ~Terminal();
    void          setPort(QString comPort);
    void          connect();
    void          disconnect();
    bool          isConnected();
    QString       port();
    QString       promptTxt();
    void          setPromptTxt(QString newPrompt);
    bool          sendCmdAndTellMustWait(QString cmd);
    QString       sendCmdSynchronous(QString cmd);
    void          getProgram();
    void          sendProgram(QByteArray execCode);
    QString       inputTxtColor();
    QString       outputTxtColor();
    QString       bgColor();
    QString       txtFontFamily();
    QString       txtFontSize();
    void          setInputTxtColor(QString color);
    void          setOutputTxtColor(QString color);
    void          setBgColor(QString color);
    void          setTxtFontFamily(QString fontFamily);
    void          setTxtFontSize(QString fontSize);

signals:
    void receivedFullResponse(QString response);
    void timeout(int time);
    void receivedProgram(RhinoProg *prog);

private slots:
    void    pollController();
    void    abortWaitResponse();
};

/*************************************************************************************************************
 *                                                    EXCEPTIONS
 ************************************************************************************************************/

class InvalidComPortError : Exception
{
public:
    InvalidComPortError();
};

class ErrorOpeningComPort : Exception
{
public:
    ErrorOpeningComPort();
};

class PortChangeWhileConnectedError : Exception
{
public:
    PortChangeWhileConnectedError();
};

#endif // TERMINAL_H
