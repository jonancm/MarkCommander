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

#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QScrollBar>
#include <QTableWidget>
#include <QWebView>

#include "errorcodes.hpp"

QTableWidget * createErrorCodesTable()
{
    QTableWidget *errorCodesTable = new QTableWidget();
    QTableWidgetItem *newItem;

    QStringList horizontalHeaders;
    horizontalHeaders << QObject::tr("Código de error") << QObject::tr("Descripción");
    errorCodesTable->setColumnCount(2);
    errorCodesTable->setHorizontalHeaderLabels(horizontalHeaders);
    errorCodesTable->setColumnWidth(1, 300);
    errorCodesTable->verticalHeader()->hide();

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(10));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Invalid command"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(11));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Parameter out of bounds"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(12));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Missing parameter"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(13));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Expected delimiter not seen"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(14));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Command string too long"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(16));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("The teach pendant is active or busy"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(20));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Host input buffer overflow"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(21));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Host USART timed out"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(22));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Host USART error (framing, parity, etc.)"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(23));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Teach pendant input buffer overflow"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(24));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Teach pendant USART timed out"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(25));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Teach pendant USART error (framing, parity, etc.)"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(26));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Teach pendant USART overrun"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(27));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Host USART overrun"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(30));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Bad RAM location"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(32));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Teach pendant returned diagnostic error"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(34));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Teach pendant not present"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(40));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Missing label"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(41));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("No program in memory"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(42));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Insufficient teach pendant memory"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(43));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Insufficient EEPROM memory"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(44));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Can't replace first record"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(45));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("A pendant program already exists"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(50));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Hard home routine failed"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(51));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Hard home not set"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(52));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Soft home not set"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(53));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Arithmetic overflow"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(54));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Trig function return error"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(55));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Error stack overflow"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(56));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Still executing a trapezoidal move"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(57));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Inactive motor referenced"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(58));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Insufficient move data (velocity or acceleration = 0)"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(59));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Improper motor mode for command"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(60));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch A not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(61));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch B not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(62));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch C not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(63));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch D not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(64));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch E not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(65));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch F not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(66));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch G not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(67));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch H not found"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(69));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Interpolation move out of bounds"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(70));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("XYZ position out of bounds"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(80));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch A stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(81));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch B stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(82));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch C stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(83));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch D stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(84));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch E stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(85));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch F stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(86));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch G stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(87));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Limit switch H stuck"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(91));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Invalid robot type specifier"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(92));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Invalid motor specifier"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(93));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Invalid controller type"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(94));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Invalid pendant mode"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(95));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Emergency stop"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(96));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Invalid xyz specifier"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(97));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Invalid xyz parameter"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(100));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor A stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(101));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor B stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(102));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor C stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(103));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor D stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(104));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor E stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(105));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor F stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(106));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor G stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(107));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor H stalled"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(110));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor A's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(111));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor B's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(112));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor C's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(113));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor D's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(114));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor E's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(115));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor F's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(116));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor G's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(117));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Motor H's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(118));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Aux Port 1's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    errorCodesTable->insertRow(errorCodesTable->rowCount());
    newItem = new QTableWidgetItem(QString::number(119));
    newItem->setTextAlignment(Qt::AlignCenter);
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 0, newItem);
    newItem = new QTableWidgetItem(QString("Aux Port 2's current limit circuit was activated"));
    errorCodesTable->setItem(errorCodesTable->rowCount() - 1, 1, newItem);

    return errorCodesTable;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    editorProg = NULL;
    errorCodesDialog = NULL;
    cmdRefDialog = NULL;
    showFileOnTerminal = true;

    disableTerminalActions();
    disableKinematics();
    ui->tabWidget_ctrlView->setCurrentIndex(0);
    connectionStatus = new QLabel();
    connectionStatus->setText(tr("No hay ninguna conexión abierta"));
    ui->statusBar->addPermanentWidget(connectionStatus);
    editorFileStatus = new QLabel();
    editorFileStatus->setText(tr("No hay ningún fichero abierto"));
    ui->statusBar->setSizeGripEnabled(false);

    // Hide undesireable or unimplemented menu actions
    ui->actionSetSoftHome->setVisible(false);
    ui->actionManualCtrl->setVisible(false);
    ui->checkBox_dirkinKeepDirkin->setVisible(false);
    //ui->pushButton_computeDirKin->setVisible(false);
    //ui->pushButton_computeInvKin->setVisible(false);

    // Set minimum
    ui->doubleSpinBox_dirkinTheta1F->setMinimum(xr4.jointRangeDeg('F').min);
    ui->doubleSpinBox_dirkinTheta2E->setMinimum(xr4.jointRangeDeg('E').min);
    ui->doubleSpinBox_dirkinTheta3D->setMinimum(xr4.jointRangeDeg('D').min);
    ui->doubleSpinBox_dirkinTheta4C->setMinimum(xr4.jointRangeDeg('C').min);
    ui->doubleSpinBox_dirkinTheta5B->setMinimum(xr4.jointRangeDeg('B').min);
    // Set maximum
    ui->doubleSpinBox_dirkinTheta1F->setMaximum(xr4.jointRangeDeg('F', true).max);
    ui->doubleSpinBox_dirkinTheta2E->setMaximum(xr4.jointRangeDeg('E').max);
    ui->doubleSpinBox_dirkinTheta3D->setMaximum(xr4.jointRangeDeg('D').max);
    ui->doubleSpinBox_dirkinTheta4C->setMaximum(xr4.jointRangeDeg('C').max);
    ui->doubleSpinBox_dirkinTheta5B->setMaximum(xr4.jointRangeDeg('B').max);
    // Set minimum
    ui->dial_dirkinTheta1F->setMinimum(xr4.jointRangeDeg('F').min);
    ui->dial_dirkinTheta2E->setMinimum(xr4.jointRangeDeg('E').min);
    ui->dial_dirkinTheta3D->setMinimum(xr4.jointRangeDeg('D').min);
    ui->dial_dirkinTheta4C->setMinimum(xr4.jointRangeDeg('C').min);
    ui->dial_dirkinTheta5B->setMinimum(xr4.jointRangeDeg('B').min);
    // Set maximum
    ui->dial_dirkinTheta1F->setMaximum(xr4.jointRangeDeg('F', true).max);
    ui->dial_dirkinTheta2E->setMaximum(xr4.jointRangeDeg('E').max);
    ui->dial_dirkinTheta3D->setMaximum(xr4.jointRangeDeg('D').max);
    ui->dial_dirkinTheta4C->setMaximum(xr4.jointRangeDeg('C').max);
    ui->dial_dirkinTheta5B->setMaximum(xr4.jointRangeDeg('B').max);

    // Set minimum
    ui->doubleSpinBox_invkinTheta1F->setMinimum(xr4.jointRangeDeg('F').min);
    ui->doubleSpinBox_invkinTheta2E->setMinimum(xr4.jointRangeDeg('E').min);
    ui->doubleSpinBox_invkinTheta3D->setMinimum(xr4.jointRangeDeg('D').min);
    ui->doubleSpinBox_invkinTheta4C->setMinimum(xr4.jointRangeDeg('C').min);
    ui->doubleSpinBox_invkinTheta5B->setMinimum(xr4.jointRangeDeg('B').min);
    // Set maximum
    ui->doubleSpinBox_invkinTheta1F->setMaximum(xr4.jointRangeDeg('F', true).max);
    ui->doubleSpinBox_invkinTheta2E->setMaximum(xr4.jointRangeDeg('E').max);
    ui->doubleSpinBox_invkinTheta3D->setMaximum(xr4.jointRangeDeg('D').max);
    ui->doubleSpinBox_invkinTheta4C->setMaximum(xr4.jointRangeDeg('C').max);
    ui->doubleSpinBox_invkinTheta5B->setMaximum(xr4.jointRangeDeg('B').max);
    // Set minimum
    ui->dial_invkinTheta1F->setMinimum(xr4.jointRangeDeg('F').min);
    ui->dial_invkinTheta2E->setMinimum(xr4.jointRangeDeg('E').min);
    ui->dial_invkinTheta3D->setMinimum(xr4.jointRangeDeg('D').min);
    ui->dial_invkinTheta4C->setMinimum(xr4.jointRangeDeg('C').min);
    ui->dial_invkinTheta5B->setMinimum(xr4.jointRangeDeg('B').min);
    // Set maximum
    ui->dial_invkinTheta1F->setMaximum(xr4.jointRangeDeg('F', true).max);
    ui->dial_invkinTheta2E->setMaximum(xr4.jointRangeDeg('E').max);
    ui->dial_invkinTheta3D->setMaximum(xr4.jointRangeDeg('D').max);
    ui->dial_invkinTheta4C->setMaximum(xr4.jointRangeDeg('C').max);
    ui->dial_invkinTheta5B->setMaximum(xr4.jointRangeDeg('B').max);

    createConfigurationDialog();

    connect(&terminal, SIGNAL(receivedFullResponse(QString)),
            this, SLOT(getCmdResponse(QString)));
    connect(&terminal, SIGNAL(timeout(int)), this, SLOT(handleTimeout(int)));
    connect(&terminal, SIGNAL(receivedProgram(RhinoProg*)),
            this, SLOT(getProgram(RhinoProg*)));

    dirkinOldValue[0] = 0.0;
    dirkinOldValue[1] = 0.0;
    dirkinOldValue[2] = 0.0;
    dirkinOldValue[3] = 0.0;
    dirkinOldValue[4] = 0.0;

    //alreadyGoneToKinHome = false;
}

MainWindow::~MainWindow()
{
    if (editorProg != NULL)
        delete editorProg;
    if (connectionStatus != NULL)
        delete connectionStatus;
    if (cmdRefDialog != NULL)
        delete cmdRefDialog;
    if (errorCodesDialog != NULL)
        delete errorCodesDialog;
    delete ui;
}

void MainWindow::on_pushButton_sendCmd_clicked()
{
    ui->statusBar->clearMessage();
    if (!terminal.isConnected())
    {
        QMessageBox::warning(this,
                             tr("No se puede enviar el comando"),
                             tr("No se puede enviar el comando especificado porque no se ha"
                                " abierto una conexión al controlador. Primero debe abrir la"
                                "conexión al controlador."));
    }
    else
    {
        QString cmd = ui->lineEdit_cmd->text();
        insertPrompt();
        insertTxtIntoTerm(cmd + "\n");
        ui->lineEdit_cmd->setText("");
        if(terminal.sendCmdAndTellMustWait(cmd))
            lockTerminal();
        ui->lineEdit_cmd->addCmdToHistory(cmd);
    }
}

void MainWindow::on_actionTransmitProgram_triggered()
{
    if (!terminal.isConnected())
    {
        QMessageBox::warning(this,
                             tr("No se puede transmitir ningún programa"),
                             tr("No se puede transmitir ningún programa. "
                                "Primero debe abrir una conexión al controlador"
                                " Mark IV."));
    }
    else
    {
        QString progFilePath = QFileDialog::getOpenFileName(this,
                                                            tr("Transmitir programa"),
                                                            QDir::homePath(),
                                                            tr("Programa de Rhino Mark IV (*.mkc)"));
        if (!progFilePath.isEmpty())
        {
            RhinoProg *prog;

            // open program file and get code
            /*if (progFilePath == editorProg->path())
            prog = editorProg;
        else
        {*/
            QFile progFile(progFilePath);
            progFile.open(QFile::ReadOnly | QFile::Text);
            prog = new RhinoProg(progFile.readAll());
            progFile.close();
            /*}*/

            // transmit program
            terminal.sendProgram(prog->getCode());
            ui->statusBar->showMessage(tr("Programa transmitido correctamente"));

            // delete program file if it is not the file open in the editor
            if (prog != editorProg)
                delete prog;
        }
        ui->lineEdit_cmd->setFocus();
    }
}

void MainWindow::on_actionReceiveProgram_triggered()
{
    if (!terminal.isConnected())
    {
        QMessageBox::warning(this,
                             tr("No se puede transmitir ningún programa"),
                             tr("No se puede transmitir ningún programa. "
                                "Primero debe abrir una conexión al controlador"
                                " Mark IV."));
    }
    else
    {
        receivedProgFilePath = QFileDialog::getSaveFileName(this,
                                                            tr("Recibir programa"),
                                                            QDir::homePath(),
                                                            tr("Programa de Rhino Mark IV (*.mkc)"));

        if (!receivedProgFilePath.isEmpty())
        {
            terminal.getProgram();
            showFileOnTerminal = false;
            lockTerminal();
        }
        else
            ui->lineEdit_cmd->setFocus();
    }
}

void MainWindow::on_actionConnectToController_triggered()
{
    if (terminal.isConnected())
    {
        QMessageBox::warning(this,
                             tr("No se puede conectar el terminal"),
                             tr("No se puede conectar al controlador porque ya hay una conexión "
                                "abierta. Para poder abrir una nueva conexión, rimero debe "
                                "cerrar la conexión."));
    }
    else
    {
        QStringList comPorts;
        QString     selectedPort;
        bool        ok;

        comPorts << tr("COM1") << tr("COM2") << tr("COM3") << tr("COM4");
        selectedPort = QInputDialog::getItem(this,
                                             tr("Elija el puerto serie"),
                                             tr("Elija el puerto serie al que desea conectar el"
                                                " terminal"),
                                             comPorts, // list of items
                                             0,        // default item
                                             false,    // not editable
                                             &ok);
        if (ok)
        {
            try
            {
                terminal.setPort(selectedPort);
                terminal.connect();
                ui->plainTextEdit_terminalView->clear();
                connectionStatus->setText(tr("Conectado al puerto ") + selectedPort);
                enableTerminalActions();
                unlockTerminal();
                ui->lineEdit_cmd->setFocus();
            }
            catch (ErrorOpeningComPort *e)
            {
                QMessageBox::critical(this,
                                      tr("Error al abrir conexión"),
                                      tr("Se ha producido un error al intentar conectar al "
                                         "puerto %1. O bien el puerto no existe, o no está "
                                         "disponible en este momento. Asegúrese de que el "
                                         "puerto existe e inténtelo de nuevo mas tarde.").arg(selectedPort));
            }
            catch (Exception *e)
            {
                QMessageBox::critical(this,
                                      tr("Error desconocido"),
                                      tr("Se ha producido un error desconocido: %1").arg(e->message()));
                delete e;
            }
        }
    }
}

void MainWindow::on_actionCloseConnection_triggered()
{
    if (terminal.isConnected())
    {
        QMessageBox questionBox(this);
        QPushButton *closeBtn;
        questionBox.setIcon(QMessageBox::Question);
        questionBox.setText(tr("¿Desea cerrar la conexión?"));
        questionBox.setInformativeText(tr("¿Desea cerrar la conexión con el controlador Mark IV?"));
        closeBtn = questionBox.addButton(tr("Cerrar"), QMessageBox::YesRole);
        questionBox.addButton(tr("No cerrar"), QMessageBox::NoRole);
        questionBox.exec();
        if (questionBox.clickedButton() == closeBtn)
            closeConnection();
    }
}

void MainWindow::quitApp()
{
    bool quit = true;
    if (terminal.isConnected())
    {
        QMessageBox questionBox(this);
        QPushButton *closeBtn;
        questionBox.setIcon(QMessageBox::Question);
        questionBox.setText(tr("¿Desea cerrar la conexión?"));
        questionBox.setInformativeText(tr("Para salir del programa, deberá cerrar la conexión. "
                                          "¿Desea cerrar la conexión con el controlador Mark IV?"));
        closeBtn = questionBox.addButton(tr("Cerrar"), QMessageBox::YesRole);
        questionBox.addButton(tr("No cerrar"), QMessageBox::NoRole);
        questionBox.exec();
        if (questionBox.clickedButton() == closeBtn)
            closeConnection();
        else
            quit = false;
    }
    if (quit)
        qApp->quit();
}

void MainWindow::on_actionSaveTerminalOutput_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,
                                                    tr("Guardar texto del terminal"),
                                                    QDir::homePath(),
                                                    tr("Texto plano (*.txt)"));
    if (!filePath.isEmpty())
    {
        QFile outFile(filePath);
        outFile.open(QFile::WriteOnly | QFile::Truncate | QFile::Text);
        QTextStream outStream(&outFile);
        outStream << ui->plainTextEdit_terminalView->toPlainText();
        outStream.flush();
        outFile.close();
    }
    ui->lineEdit_cmd->setFocus();
}

void MainWindow::on_actionClearTerminal_triggered()
{
    QMessageBox questionBox(this);
    QPushButton *clearBtn;
    questionBox.setIcon(QMessageBox::Question);
    questionBox.setText(tr("¿Desea borrar la pantalla?"));
    questionBox.setInformativeText(tr("¿Desea borrar la pantalla del terminal?"));
    clearBtn = questionBox.addButton(tr("Borrar"), QMessageBox::YesRole);
    questionBox.addButton(tr("No borrar"), QMessageBox::NoRole);
    questionBox.exec();
    if (questionBox.clickedButton() == clearBtn)
        ui->plainTextEdit_terminalView->clear();
    ui->lineEdit_cmd->setFocus();
}

void MainWindow::insertPrompt()
{
    insertTxtIntoTerm(terminal.promptTxt());
}

void MainWindow::getCmdResponse(QString response)
{
    insertTxtIntoTerm(response + "\n");
    if (ui->lineEdit_cmd->cmdHistory().last().toLower() == "se")
    {
        int errCode = response.toInt();
        if (errCode != 0)
            ui->statusBar->showMessage(tr("Error %1: %2").arg(response, QString(errcode_meaning(errCode))));
    }
    unlockTerminal();
    ui->lineEdit_cmd->setFocus();
}

void MainWindow::handleTimeout(int time)
{
    insertTxtIntoTerm(tr("== TIMEOUT: Mark IV Controller has not responded yet, continuing... ==\n"));
    ui->statusBar->showMessage(tr("Timeout: No se ha obtenido respuesta del controlador en los últimos"
                                  " %1 segundo(s).").arg(QString::number(time / 1000)));
    unlockTerminal();
    ui->lineEdit_cmd->setFocus();
}

void MainWindow::lockTerminal()
{
    ui->lineEdit_cmd->setEnabled(false);
    ui->pushButton_sendCmd->setEnabled(false);
}

void MainWindow::unlockTerminal()
{
    ui->lineEdit_cmd->setEnabled(true);
    ui->pushButton_sendCmd->setEnabled(true);
}

void MainWindow::closeConnection()
{
    terminal.disconnect();
    connectionStatus->setText(tr("No hay ninguna conexión abierta"));
    lockTerminal();
    disableTerminalActions();
    disableKinematics();
}

void MainWindow::getProgram(RhinoProg *prog)
{
    if (showFileOnTerminal)
    {
        insertTxtIntoTerm(prog->getCode());
    }
    else
    {
        /*if (editorFile->path() == receivedProgFilePath)
        {
            QMessageBox questionBox(this);
            QPushButton *ovBtn; // overwrite button
            questionBox.setIcon(QMessageBox::Question);
            questionBox.setText(tr("¿Desea sobreescribir el fichero abierto en el editor?"));
            questionBox.setInformativeText(tr("Ha elegido guardar el programa recibido en el "
                                              "mismo archivo que hay abierto en el editor. ¿Seguro"
                                              " que desea sobreescribir el fichero abierto en "
                                              "el editor?"));
            ovBtn = questionBox.addButton(tr("Sobreescribir"), QMessageBox::YesRole);
            questionBox.addButton(tr("No sobreescribir"), QMessageBox::NoRole);
            questionBox.exec();
            if (questionBox.clickedButton() == ovBtn) // if overwrite
            {
                editorFile->close(true); // save file and then close
                delete editorFile;

                prog->setPath(receivedProgFilePath);
                prog->save();
                qDebug(prog->getTxtCode().toStdString().c_str());
                editorFile = prog;
            }
            else // if not overwrite
                delete prog;
        }
        else // if path of received file is different from file open in editor
        {
            prog->setPath(receivedProgFilePath);
            prog->close(true); // save file and then close
            qDebug(prog->getTxtCode().toStdString().c_str());
            delete prog;
        }*/
        bool save = true;

        if (QFile::exists(receivedProgFilePath))
        {
            QMessageBox questionBox(this);
            QPushButton *ovBtn; // overwrite button
            questionBox.setIcon(QMessageBox::Question);
            questionBox.setText(tr("¿Desea sobreescribir el fichero?"));
            questionBox.setInformativeText(tr("El fichero que ha seleccionado "
                                              "ya existe. ¿Seguro que desea "
                                              "sobreescribir el fichero?"));
            ovBtn = questionBox.addButton(tr("Sobreescribir"), QMessageBox::YesRole);
            questionBox.addButton(tr("No sobreescribir"), QMessageBox::NoRole);
            questionBox.exec();
            if (questionBox.clickedButton() == ovBtn) // if overwrite
                QFile::remove(receivedProgFilePath);
            else // if not overwrite
            {
                save = false;
                ui->statusBar->showMessage(tr("Ha elegido no sobreescribir el "
                                              "fichero"));
            }
        }

        if (save)
        {
            prog->saveToPath(receivedProgFilePath);
            ui->statusBar->showMessage(tr("Programa recibido correctamente"));
        }
        showFileOnTerminal = true;
    }
    unlockTerminal();
    ui->lineEdit_cmd->setFocus();
}

void MainWindow::insertTxtIntoTerm(QString txt)
{
    ui->plainTextEdit_terminalView->insertPlainText(txt);
    QScrollBar *sb = ui->plainTextEdit_terminalView->verticalScrollBar();
    sb->setValue(sb->maximum()-1);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    bool quit = true;
    if (terminal.isConnected())
    {
        QMessageBox questionBox(this);
        QPushButton *closeBtn;
        questionBox.setIcon(QMessageBox::Question);
        questionBox.setText(tr("¿Desea cerrar la conexión?"));
        questionBox.setInformativeText(tr("Para salir del programa, deberá cerrar la conexión. "
                                          "¿Desea cerrar la conexión con el controlador Mark IV?"));
        closeBtn = questionBox.addButton(tr("Cerrar"), QMessageBox::YesRole);
        questionBox.addButton(tr("No cerrar"), QMessageBox::NoRole);
        questionBox.exec();
        if (questionBox.clickedButton() == closeBtn)
            closeConnection();
        else
            quit = false;
    }
    if (quit)
        qApp->quit();
    else
        event->ignore();
}

void MainWindow::on_actionErrorCodes_triggered()
{
    if (errorCodesDialog == NULL)
    {
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(createErrorCodesTable());

        errorCodesDialog = new QDialog(this);
        errorCodesDialog->resize(500, 500);
        errorCodesDialog->setWindowTitle(tr("MarkCommander") + " - "
                                         + tr("Códigos de error de Rhino Mark IV"));
        errorCodesDialog->setLayout(layout);
        errorCodesDialog->show();
    }
    else
    {
        errorCodesDialog->show();
        errorCodesDialog->raise();
    }
}

void MainWindow::on_actionAboutThisApp_triggered()
{
    QHBoxLayout *layout = new QHBoxLayout();
    QLabel *appIcon = new QLabel();
    appIcon->setPixmap(QPixmap(":/icons/appicon3.png"));
    layout->addWidget(appIcon);
    QLabel *appInfo = new QLabel(tr("MarkCommander v0.1\n\n2011\nJonán Cruz Martín"));
    appInfo->setStyleSheet("font: 14px");
    layout->addWidget(appInfo);

    QDialog aboutDialog(this);
    aboutDialog.resize(200, 100);
    aboutDialog.setWindowTitle(tr("Sobre MarkCommander"));
    aboutDialog.setLayout(layout);
    aboutDialog.exec();
}

void MainWindow::on_actionCommandRef_triggered()
{
    if (cmdRefDialog == NULL)
    {
        QVBoxLayout *layout = new QVBoxLayout();
        QWebView *webView = new QWebView();
        QFile webPage(":/files/mark-iv-commands.html");
        webPage.open(QFile::ReadOnly);
        webView->setContent(webPage.readAll());
        layout->addWidget(webView);

        cmdRefDialog = new QDialog(this);
        cmdRefDialog->resize(800, 800);
        cmdRefDialog->setWindowTitle(tr("MarkCommander") + " - "
                                     + tr("Referencia de comandos de Rhino Mark IV"));
        cmdRefDialog->setLayout(layout);
        cmdRefDialog->show();
    }
    else
    {
        cmdRefDialog->show();
        cmdRefDialog->raise();
    }
}

void MainWindow::on_actionHardHome_triggered()
{
    terminal.sendCmdAndTellMustWait("th");
    terminal.sendCmdAndTellMustWait("hh");
}

void MainWindow::enableTerminalActions()
{
    ui->actionTransmitProgram->setEnabled(true);
    ui->actionReceiveProgram->setEnabled(true);
    ui->actionCloseConnection->setEnabled(true);
    ui->actionHardHome->setEnabled(true);
    ui->actionSoftHome->setEnabled(true);
    ui->actionConfigureController->setEnabled(true);
    //ui->pushButton_dirkinGoToPos->setEnabled(true);
    //ui->pushButton_invkinGoToPos->setEnabled(true);
    ui->actionGoToKinHome->setEnabled(true);
    ui->actionSetSoftHome->setEnabled(true);
}

void MainWindow::disableTerminalActions()
{
    ui->actionTransmitProgram->setEnabled(false);
    ui->actionReceiveProgram->setEnabled(false);
    ui->actionCloseConnection->setEnabled(false);
    ui->actionHardHome->setEnabled(false);
    ui->actionSoftHome->setEnabled(false);
    ui->actionConfigureController->setEnabled(false);
    //ui->pushButton_dirkinGoToPos->setEnabled(false);
    //ui->pushButton_invkinGoToPos->setEnabled(false);
    ui->actionGoToKinHome->setEnabled(false);
    ui->actionSetSoftHome->setEnabled(false);
}

void MainWindow::on_actionSoftHome_triggered()
{
    terminal.sendCmdAndTellMustWait("th");
    moveMotorB(0, false);
    moveMotorC(0, false);
    moveMotorD(0, false);
    moveMotorE(0, false);
    moveMotorF(0, false);
    terminal.sendCmdAndTellMustWait("mc");

    bool checked = ui->checkBox_dirkinKeepDirkin->isChecked();
    ui->checkBox_dirkinKeepDirkin->setChecked(false);

    ui->dial_dirkinTheta5B->setValue(xr4.steps2deg(0, 'B'));
    ui->dial_dirkinTheta4C->setValue(xr4.steps2deg(0, 'C'));
    ui->dial_dirkinTheta3D->setValue(xr4.steps2deg(0, 'D'));
    ui->dial_dirkinTheta2E->setValue(xr4.steps2deg(0, 'E'));
    ui->dial_dirkinTheta1F->setValue(xr4.steps2deg(0, 'F'));

    ui->checkBox_dirkinKeepDirkin->setChecked(checked);
}

void MainWindow::createConfigurationDialog()
{
    getConfigProgressDialog = new QProgressDialog(this, Qt::Popup);
    getConfigProgressDialog->setCancelButton(0);
    getConfigProgressDialog->setLabelText(tr("Esperando la configuración del controlador Mark IV"));
    getConfigProgressDialog->setWindowModality(Qt::WindowModal);
    getConfigProgressDialog->setMaximum(CMD_TIMEOUT/1000);

    getConfigTimer = new QTimer();
    getConfigTimer->setInterval(1000); // shoot timeout every second
    connect(getConfigTimer, SIGNAL(timeout()), this, SLOT(getConfigTimerTimeout()));

    layout = new QVBoxLayout();
    grid = new QGridLayout();
    hbox = new QHBoxLayout();
    applyBtn = new QPushButton(tr("Apply configuration"));
    closeBtn = new QPushButton(tr("Close"));
    revertBtn = new QPushButton(tr("Revert configuration"));

    configBits[0] =  new QComboBox(); // Bit 7
    configBits[0]->insertItem(0, tr("System is in pendant mode"));
    configBits[0]->insertItem(1, tr("System is in host mode"));

    configBits[1] =  new QComboBox(); // Bit 6
    configBits[1]->insertItem(0, tr("The pendant is disabled"));
    configBits[1]->insertItem(1, tr("The pendant is enabled"));
    configBits[1]->setEnabled(false);

    configBits[2] =  new QComboBox(); // Bit 5
    configBits[2]->insertItem(0, tr("Robot controller mode"));
    configBits[2]->insertItem(1, tr("Generic controller mode"));

    configBits[3] =  new QComboBox(); // Bit 4
    configBits[3]->insertItem(0, tr("XR-3 mode"));
    configBits[3]->insertItem(1, tr("SCARA mode"));

    configBits[4] =  new QComboBox(); // Bit 3
    configBits[4]->insertItem(0, tr("The gripper is enabled"));
    configBits[4]->insertItem(1, tr("The gripper is disabled"));

    configBits[5] =  new QComboBox(); // Bit 2
    configBits[5]->insertItem(0, tr("Joint mode"));
    configBits[5]->insertItem(1, tr("XYZ mode"));

    grid->addWidget(new QLabel(tr("System mode")), 0, 0); // Bit 7
    grid->addWidget(configBits[0], 0, 1);

    grid->addWidget(new QLabel(tr("Pendant status")), 1, 0); // Bit 6
    grid->addWidget(configBits[1], 1, 1);

    grid->addWidget(new QLabel(tr("Controller mode")), 2, 0); // Bit 5
    grid->addWidget(configBits[2], 2, 1);

    grid->addWidget(new QLabel(tr("Robot type")), 3, 0); // Bit 4
    grid->addWidget(configBits[3], 3, 1);

    grid->addWidget(new QLabel(tr("Gripper mode")), 4, 0); // Bit 3
    grid->addWidget(configBits[4], 4, 1);

    grid->addWidget(new QLabel(tr("Joint variables mode")), 5, 0); // Bit 2
    grid->addWidget(configBits[5], 5, 1);

    hbox->addWidget(applyBtn);
    hbox->addWidget(revertBtn);
    hbox->addWidget(closeBtn);

    layout->addLayout(grid);
    layout->addLayout(hbox);

    configureControllerDialog = new QDialog(this);
    configureControllerDialog->setWindowTitle(tr("Configuración del controlador Mark IV"));
    configureControllerDialog->setLayout(layout);

    connect(configBits[0], SIGNAL(currentIndexChanged(int)), this, SLOT(systemModeChanged(int)));
    // connect(configBits[1], SIGNAL(currentIndexChanged(int)), this, SLOT(pendantStatusChanged(int)));
    connect(configBits[2], SIGNAL(currentIndexChanged(int)), this, SLOT(controllerModeChanged(int)));
    connect(configBits[3], SIGNAL(currentIndexChanged(int)), this, SLOT(robotTypeChanged(int)));
    connect(configBits[4], SIGNAL(currentIndexChanged(int)), this, SLOT(gripperModeChanged(int)));
    connect(configBits[5], SIGNAL(currentIndexChanged(int)), this, SLOT(jointModeChanged(int)));

    connect(applyBtn, SIGNAL(clicked(bool)), this, SLOT(on_actionApplyConfiguration_triggered()));
    connect(revertBtn, SIGNAL(clicked(bool)), this, SLOT(on_actionRevertConfiguration_triggered()));
    connect(closeBtn, SIGNAL(clicked(bool)), this, SLOT(on_actionCloseConfiguration_triggered()));
    connect(configureControllerDialog, SIGNAL(rejected()), this, SLOT(restoreSlotsAfterConfig()));
}

void MainWindow::on_actionConfigureController_triggered()
{
    disconnect(&terminal, SIGNAL(receivedFullResponse(QString)),
            this, SLOT(getCmdResponse(QString)));
    disconnect(&terminal, SIGNAL(timeout(int)), this, SLOT(handleTimeout(int)));

    connect(&terminal, SIGNAL(receivedFullResponse(QString)),
            this, SLOT(getConfiguration(QString)));
    connect(&terminal, SIGNAL(timeout(int)), this, SLOT(handleConfigurationTimeout(int)));

    terminal.sendCmdAndTellMustWait("sc");
    showGetConfigProgressDialog();
}

void MainWindow::on_actionApplyConfiguration_triggered()
{
    terminal.sendCmdAndTellMustWait("th");

    // Robot controller mode: set robot type (XR-3 / SCARA)
    if ((configBitChanged[2] || configBitChanged[3])
        && configBits[2]->currentIndex() == 0)
    {
        terminal.sendCmdAndTellMustWait("cr," + QString::number(configBits[3]->currentIndex()));
    }
    // Generic controller mode
    else if (configBitChanged[2]
             && configBits[2]->currentIndex() == 1)
    {
        terminal.sendCmdAndTellMustWait("cr,2");
    }

    // Enable (1) / disable (0) gripper
    if (configBitChanged[4])
        terminal.sendCmdAndTellMustWait("cg," + QString::number(1 - configBits[4]->currentIndex()));

    // Joint mode (0) / XYZ mode (1)
    if (configBitChanged[5])
        terminal.sendCmdAndTellMustWait("cc," + QString::number(configBits[5]->currentIndex()));

    // Pendant (0) / Host (1) mode
    if (configBits[0]->currentIndex() == 0)
        terminal.sendCmdAndTellMustWait("tx");

    terminal.sendCmdAndTellMustWait("sc");
    showGetConfigProgressDialog();
}

void MainWindow::on_actionRevertConfiguration_triggered()
{
    configBits[0]->setCurrentIndex(0); // Bit 7
    configBits[1]->setCurrentIndex(0); // Bit 6
    configBits[2]->setCurrentIndex(0); // Bit 5
    configBits[3]->setCurrentIndex(0); // Bit 4
    configBits[4]->setCurrentIndex(0); // Bit 3
    configBits[5]->setCurrentIndex(0); // Bit 2
}

void MainWindow::on_actionCloseConfiguration_triggered()
{
    configureControllerDialog->close();
}

void MainWindow::getConfiguration(QString configString)
{
    closeGetConfigProgressDialog();

    int configByte = configString.toInt();

    configBits[0]->setCurrentIndex((configByte & 128) >> 7); // Bit 7
    configBits[1]->setCurrentIndex((configByte & 64) >> 6);  // Bit 6
    configBits[2]->setCurrentIndex((configByte & 32) >> 5);  // Bit 5
    configBits[3]->setCurrentIndex((configByte & 16) >> 4);  // Bit 4
    configBits[4]->setCurrentIndex((configByte & 8) >> 3);   // Bit 3
    configBits[5]->setCurrentIndex((configByte & 2) >> 2);   // Bit 2

    configBitChanged[0] = false;
    configBitChanged[1] = false;
    configBitChanged[2] = false;
    configBitChanged[3] = false;
    configBitChanged[4] = false;
    configBitChanged[5] = false;

    configureControllerDialog->exec();
}

void MainWindow::handleConfigurationTimeout(int time)
{
    qDebug("handleConfigurationTimeout");
    closeGetConfigProgressDialog();
    on_actionCloseConfiguration_triggered();
    restoreSlotsAfterConfig();
    QMessageBox::warning(this,
                          tr("Se ha agotado el tiempo"),
                          tr("Se ha agotado el tiempo de espera por los datos "
                             "de configuración. El controlador Mark IV no ha "
                             "respondido en los últimos %1 segundos.").arg(time/1000));
}

void MainWindow::restoreSlotsAfterConfig()
{
    qDebug("restoreSlotsAfterConfig");
    disconnect(&terminal, SIGNAL(receivedFullResponse(QString)),
            this, SLOT(getConfiguration(QString)));
    disconnect(&terminal, SIGNAL(timeout(int)), this, SLOT(handleConfigurationTimeout(int)));

    connect(&terminal, SIGNAL(receivedFullResponse(QString)),
            this, SLOT(getCmdResponse(QString)));
    connect(&terminal, SIGNAL(timeout(int)), this, SLOT(handleTimeout(int)));

    unlockTerminal();
}

void MainWindow::systemModeChanged(int curIndex)
{
    configBitChanged[0] = true;
}

// void MainWindow::pendantStatusChanged(int curIndex);

void MainWindow::controllerModeChanged(int curIndex)
{
    configBitChanged[2] = true;
    if (curIndex == 0) // Robot controller mode
        configBits[3]->setEnabled(true);
    else // Generic controller mode
        configBits[3]->setEnabled(false);
}

void MainWindow::robotTypeChanged(int curIndex)
{
    configBitChanged[3] = true;
}

void MainWindow::gripperModeChanged(int curIndex)
{
    configBitChanged[4] = true;
}

void MainWindow::jointModeChanged(int curIndex)
{
    configBitChanged[5] = true;
}

void MainWindow::getConfigTimerTimeout()
{
    getConfigProgressDialog->setValue(getConfigProgressDialog->value() + 1);
}

void MainWindow::showGetConfigProgressDialog()
{
    lockTerminal();
    getConfigProgressDialog->show();
    getConfigTimer->start();
}

void MainWindow::closeGetConfigProgressDialog()
{
    qDebug("closeGetconfigProgressDialog");
    getConfigTimer->stop();
    getConfigProgressDialog->close();
}

void MainWindow::on_actionTerminal_triggered()
{
    ui->tabWidget_ctrlView->setCurrentIndex(0);
}

void MainWindow::on_actionDirKin_triggered()
{
    ui->tabWidget_ctrlView->setCurrentIndex(1);
}

void MainWindow::on_actionInvKin_triggered()
{
    ui->tabWidget_ctrlView->setCurrentIndex(2);
}

void MainWindow::updateDirkin()
{
    double t1 = ui->doubleSpinBox_dirkinTheta1F->value();
    double t2 = ui->doubleSpinBox_dirkinTheta2E->value();
    double t3 = ui->doubleSpinBox_dirkinTheta3D->value();
    double t4 = ui->doubleSpinBox_dirkinTheta4C->value();
    double t5 = ui->doubleSpinBox_dirkinTheta5B->value();

    JointAngles angles = JointAngles(t1, t2, t3, t4, t5);
    const Matrix armMatrix = xr4.dirkin(angles);

    ui->lineEdit_dirkinArmMatrixN1->setText(QString::number((double)armMatrix.at(1, 1)));
    ui->lineEdit_dirkinArmMatrixN2->setText(QString::number((double)armMatrix.at(2, 1)));
    ui->lineEdit_dirkinArmMatrixN3->setText(QString::number((double)armMatrix.at(3, 1)));

    ui->lineEdit_dirkinArmMatrixS1->setText(QString::number((double)armMatrix.at(1, 2)));
    ui->lineEdit_dirkinArmMatrixS2->setText(QString::number((double)armMatrix.at(2, 2)));
    ui->lineEdit_dirkinArmMatrixS3->setText(QString::number((double)armMatrix.at(3, 2)));

    ui->lineEdit_dirkinArmMatrixA1->setText(QString::number((double)armMatrix.at(1, 3)));
    ui->lineEdit_dirkinArmMatrixA2->setText(QString::number((double)armMatrix.at(2, 3)));
    ui->lineEdit_dirkinArmMatrixA3->setText(QString::number((double)armMatrix.at(3, 3)));

    ui->lineEdit_dirkinArmMatrixP1->setText(QString::number((double)armMatrix.at(1, 4)));
    ui->lineEdit_dirkinArmMatrixP2->setText(QString::number((double)armMatrix.at(2, 4)));
    ui->lineEdit_dirkinArmMatrixP3->setText(QString::number((double)armMatrix.at(3, 4)));

    int incStepsE = xr4.deg2steps(t2 - 90, 'E', false);
    int corSign = (nullify(t2 - 90) == 0.0 ? 1 : -1);
    int incStepsD = corSign*(xr4.deg2steps(t3 + 90, 'D', false) + incStepsE);

    ui->plainTextEdit_dirkinCommands->setPlainText("pd,b," + QString::number((int)xr4.deg2steps(t5, 'B')));
    ui->plainTextEdit_dirkinCommands->appendPlainText("pd,c," + QString::number((int)xr4.deg2steps(t4, 'C') + incStepsD));
    ui->plainTextEdit_dirkinCommands->appendPlainText("pd,d," + QString::number((int)xr4.deg2steps(t3, 'D') + incStepsE));
    ui->plainTextEdit_dirkinCommands->appendPlainText("pd,e," + QString::number((int)xr4.deg2steps(t2, 'E')));
    ui->plainTextEdit_dirkinCommands->appendPlainText("pd,f," + QString::number((int)xr4.deg2steps(t1, 'F')));
    ui->plainTextEdit_dirkinCommands->appendPlainText("mc");

    /*dirkinOldValue[0] = t1;
    dirkinOldValue[1] = t2;
    dirkinOldValue[2] = t3;
    dirkinOldValue[3] = t4;
    dirkinOldValue[4] = t5;*/
}

void MainWindow::on_doubleSpinBox_dirkinTheta1F_valueChanged(double angle)
{
    ui->dial_dirkinTheta1F->setValue(angle);
    updateDirkin();
    /*dirkinOldValue[0] = angle;*/
}

void MainWindow::on_doubleSpinBox_dirkinTheta2E_valueChanged(double angle)
{
    ui->dial_dirkinTheta2E->setValue(angle);
    /*if (ui->checkBox_dirkinKeepDirkin->isChecked())
    {
        int inc = angle - dirkinOldValue[1];
        ui->doubleSpinBox_dirkinTheta3D->setValue(dirkinOldValue[2] - inc);
    }*/
    updateDirkin();
    /*dirkinOldValue[1] = angle;*/
}

void MainWindow::on_doubleSpinBox_dirkinTheta3D_valueChanged(double angle)
{
    ui->dial_dirkinTheta3D->setValue(angle);
    /*if (ui->checkBox_dirkinKeepDirkin->isChecked())
    {
        int inc = angle - dirkinOldValue[2];
        ui->doubleSpinBox_dirkinTheta4C->setValue(dirkinOldValue[3] + inc);
    }*/
    updateDirkin();
    /*dirkinOldValue[2] = angle;*/
}

void MainWindow::on_doubleSpinBox_dirkinTheta4C_valueChanged(double angle)
{
    ui->dial_dirkinTheta4C->setValue(angle);
    updateDirkin();
    /*dirkinOldValue[3] = angle;*/
}

void MainWindow::on_doubleSpinBox_dirkinTheta5B_valueChanged(double angle)
{
    ui->dial_dirkinTheta5B->setValue(angle);
    updateDirkin();
    /*dirkinOldValue[4] = angle;*/
}

void MainWindow::on_dial_dirkinTheta1F_valueChanged(int value)
{
    ui->doubleSpinBox_dirkinTheta1F->setValue(value);
}

void MainWindow::on_dial_dirkinTheta2E_valueChanged(int value)
{
    ui->doubleSpinBox_dirkinTheta2E->setValue(value);
}

void MainWindow::on_dial_dirkinTheta3D_valueChanged(int value)
{
    ui->doubleSpinBox_dirkinTheta3D->setValue(value);
}

void MainWindow::on_dial_dirkinTheta4C_valueChanged(int value)
{
    ui->doubleSpinBox_dirkinTheta4C->setValue(value);
}

void MainWindow::on_dial_dirkinTheta5B_valueChanged(int value)
{
    ui->doubleSpinBox_dirkinTheta5B->setValue(value);
}

void MainWindow::on_pushButton_dirkinGoToPos_clicked()
{
    /*if (alreadyGoneToKinHome)
    {*/
        terminal.sendCmdAndTellMustWait("th");
        QStringList cmds = ui->plainTextEdit_dirkinCommands->toPlainText().split('\n', QString::SkipEmptyParts);
        for (int i = 0; i < cmds.size(); i++)
            terminal.sendCmdAndTellMustWait(cmds.at(i));

        dirkinOldValue[0] = ui->doubleSpinBox_dirkinTheta1F->value();
        dirkinOldValue[1] = ui->doubleSpinBox_dirkinTheta2E->value();
        dirkinOldValue[2] = ui->doubleSpinBox_dirkinTheta3D->value();
        dirkinOldValue[3] = ui->doubleSpinBox_dirkinTheta4C->value();
        dirkinOldValue[4] = ui->doubleSpinBox_dirkinTheta5B->value();
    /*}
    else
    {
        QMessageBox::warning(this,
                             tr("El robot no ha hecho home"),
                             tr("El robot no ha hecho el home de la cinemática."
                                " Para poder usar la cinemática directa, debe "
                                "realizar el home de la cinemática."));
    }*/
}

void MainWindow::updateInvkin()
{
    Matrix matrix(4, 4);

    // N
    matrix.at(1, 1) = ui->lineEdit_invkinArmMatrixN1->text().toDouble();
    matrix.at(2, 1) = ui->lineEdit_invkinArmMatrixN2->text().toDouble();
    matrix.at(3, 1) = ui->lineEdit_invkinArmMatrixN3->text().toDouble();
    // S
    matrix.at(1, 2) = ui->lineEdit_invkinArmMatrixS1->text().toDouble();
    matrix.at(2, 2) = ui->lineEdit_invkinArmMatrixS2->text().toDouble();
    matrix.at(3, 2) = ui->lineEdit_invkinArmMatrixS3->text().toDouble();
    // A
    matrix.at(1, 3) = ui->lineEdit_invkinArmMatrixA1->text().toDouble();
    matrix.at(2, 3) = ui->lineEdit_invkinArmMatrixA2->text().toDouble();
    matrix.at(3, 3) = ui->lineEdit_invkinArmMatrixA3->text().toDouble();
    // P
    matrix.at(1, 4) = ui->lineEdit_invkinArmMatrixP1->text().toDouble();
    matrix.at(2, 4) = ui->lineEdit_invkinArmMatrixP2->text().toDouble();
    matrix.at(3, 4) = ui->lineEdit_invkinArmMatrixP3->text().toDouble();
    // Homogeneous coordinates
    matrix.at(4, 1) = 0.0;
    matrix.at(4, 2) = 0.0;
    matrix.at(4, 3) = 0.0;
    matrix.at(4, 4) = 1.0;

    JointAngles angles;
    if (ui->comboBox_invkinVersion->currentIndex())
        angles = xr4.invkin(matrix);
    else
        angles = xr4.invkin2(matrix);
    angles.t1 = rad2deg(angles.t1);
    angles.t2 = rad2deg(angles.t2);
    angles.t3 = rad2deg(angles.t3);
    angles.t4 = rad2deg(angles.t4);
    angles.t5 = rad2deg(angles.t5);

    ui->doubleSpinBox_invkinTheta1F->setValue(angles.t1);
    ui->doubleSpinBox_invkinTheta2E->setValue(angles.t2);
    ui->doubleSpinBox_invkinTheta3D->setValue(angles.t3);
    ui->doubleSpinBox_invkinTheta4C->setValue(angles.t4);
    ui->doubleSpinBox_invkinTheta5B->setValue(angles.t5);

    int incStepsE = xr4.deg2steps(angles.t2 - 90, 'E', false);
    int corSign = (nullify(angles.t2 - 90) == 0.0 ? 1 : -1);
    int incStepsD = corSign*(xr4.deg2steps(angles.t3 + 90, 'D', false) + incStepsE);

    ui->plainTextEdit_invkinCommands->setPlainText("pd,b," + QString::number((int)xr4.deg2steps(angles.t5, 'B')));
    ui->plainTextEdit_invkinCommands->appendPlainText("pd,c," + QString::number((int)xr4.deg2steps(angles.t4, 'C') + incStepsD));
    ui->plainTextEdit_invkinCommands->appendPlainText("pd,d," + QString::number((int)xr4.deg2steps(angles.t3, 'D') + incStepsE));
    ui->plainTextEdit_invkinCommands->appendPlainText("pd,e," + QString::number((int)xr4.deg2steps(angles.t2, 'E')));
    ui->plainTextEdit_invkinCommands->appendPlainText("pd,f," + QString::number((int)xr4.deg2steps(angles.t1, 'F')));
    ui->plainTextEdit_invkinCommands->appendPlainText("mc");

    /*dirkinOldValue[0] = angles.t1;
    dirkinOldValue[1] = angles.t2;
    dirkinOldValue[2] = angles.t3;
    dirkinOldValue[3] = angles.t4;
    dirkinOldValue[4] = angles.t5;*/
}

void MainWindow::on_doubleSpinBox_invkinTheta1F_valueChanged(double angle)
{
    ui->dial_invkinTheta1F->setValue(angle);
}

void MainWindow::on_doubleSpinBox_invkinTheta2E_valueChanged(double angle)
{
    ui->dial_invkinTheta2E->setValue(angle);
}

void MainWindow::on_doubleSpinBox_invkinTheta3D_valueChanged(double angle)
{
    ui->dial_invkinTheta3D->setValue(angle);
}

void MainWindow::on_doubleSpinBox_invkinTheta4C_valueChanged(double angle)
{
    ui->dial_invkinTheta4C->setValue(angle);
}

void MainWindow::on_doubleSpinBox_invkinTheta5B_valueChanged(double angle)
{
    ui->dial_invkinTheta5B->setValue(angle);
}

void MainWindow::on_lineEdit_invkinArmMatrixN1_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixN2_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixN3_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixS1_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixS2_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixS3_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixA1_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixA2_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixA3_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixP1_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixP2_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::on_lineEdit_invkinArmMatrixP3_textChanged(QString newText)
{
    updateInvkin();
}

void MainWindow::moveMotorB(int steps, bool keepKin)
{
    terminal.sendCmdAndTellMustWait("pd,b," + QString::number(steps));
    xr4.angles.t5 = xr4.steps2deg(steps, 'B');
}

void MainWindow::moveMotorC(int steps, bool keepKin)
{
    terminal.sendCmdAndTellMustWait("pd,c," + QString::number(steps));
    xr4.angles.t4 = xr4.steps2deg(steps, 'C');
}

void MainWindow::moveMotorD(int steps, bool keepKin)
{
    terminal.sendCmdAndTellMustWait("pd,d," + QString::number(steps));
    if (keepKin)
        moveMotorCRel(xr4.deg2steps(xr4.angles.t3, 'D') - steps, keepKin);
    xr4.angles.t3 = xr4.steps2deg(steps, 'D');
}

void MainWindow::moveMotorE(int steps, bool keepKin)
{
    terminal.sendCmdAndTellMustWait("pd,e," + QString::number(steps));
    if (keepKin)
        moveMotorDRel(xr4.deg2steps(xr4.angles.t2, 'E') - steps, keepKin);
    xr4.angles.t2 = xr4.steps2deg(steps, 'E');
}

void MainWindow::moveMotorF(int steps, bool keepKin)
{
    terminal.sendCmdAndTellMustWait("pd,f," + QString::number(steps));
    xr4.angles.t1 = xr4.steps2deg(steps, 'F');
}

void MainWindow::moveMotorCRel(int steps, bool keepKin)
{
    terminal.sendCmdAndTellMustWait("pr,c," + QString::number(steps));
    xr4.angles.t4 += xr4.steps2deg(steps, 'C');
}

void MainWindow::moveMotorDRel(int steps, bool keepKin)
{
    terminal.sendCmdAndTellMustWait("pr,d," + QString::number(steps));
    if (keepKin)
        moveMotorCRel(-steps, keepKin);
    xr4.angles.t3 += xr4.steps2deg(steps, 'D');
}

void MainWindow::on_pushButton_invkinGoToPos_clicked()
{
    /*if (alreadyGoneToKinHome)
    {*/
        terminal.sendCmdAndTellMustWait("th");
        QStringList cmds = ui->plainTextEdit_invkinCommands->toPlainText().split('\n', QString::SkipEmptyParts);
        for (int i = 0; i < cmds.size(); i++)
            terminal.sendCmdAndTellMustWait(cmds.at(i));

        dirkinOldValue[0] = ui->doubleSpinBox_invkinTheta1F->value();
        dirkinOldValue[1] = ui->doubleSpinBox_invkinTheta2E->value();
        dirkinOldValue[2] = ui->doubleSpinBox_invkinTheta3D->value();
        dirkinOldValue[3] = ui->doubleSpinBox_invkinTheta4C->value();
        dirkinOldValue[4] = ui->doubleSpinBox_invkinTheta5B->value();
    /*}
    else
    {
        QMessageBox::warning(this,
                             tr("El robot no ha hecho home"),
                             tr("El robot no ha hecho el home de la cinemática."
                                " Para poder usar la cinemática inversa, debe "
                                "realizar el home de la cinemática."));
    }*/
}

void MainWindow::on_pushButton_copyDirkin_clicked()
{
    // N
    ui->lineEdit_invkinArmMatrixN1->setText(ui->lineEdit_dirkinArmMatrixN1->text());
    ui->lineEdit_invkinArmMatrixN2->setText(ui->lineEdit_dirkinArmMatrixN2->text());
    ui->lineEdit_invkinArmMatrixN3->setText(ui->lineEdit_dirkinArmMatrixN3->text());
    // S
    ui->lineEdit_invkinArmMatrixS1->setText(ui->lineEdit_dirkinArmMatrixS1->text());
    ui->lineEdit_invkinArmMatrixS2->setText(ui->lineEdit_dirkinArmMatrixS2->text());
    ui->lineEdit_invkinArmMatrixS3->setText(ui->lineEdit_dirkinArmMatrixS3->text());
    // A
    ui->lineEdit_invkinArmMatrixA1->setText(ui->lineEdit_dirkinArmMatrixA1->text());
    ui->lineEdit_invkinArmMatrixA2->setText(ui->lineEdit_dirkinArmMatrixA2->text());
    ui->lineEdit_invkinArmMatrixA3->setText(ui->lineEdit_dirkinArmMatrixA3->text());
    // P
    ui->lineEdit_invkinArmMatrixP1->setText(ui->lineEdit_dirkinArmMatrixP1->text());
    ui->lineEdit_invkinArmMatrixP2->setText(ui->lineEdit_dirkinArmMatrixP2->text());
    ui->lineEdit_invkinArmMatrixP3->setText(ui->lineEdit_dirkinArmMatrixP3->text());
}

void MainWindow::on_actionGoToKinHome_triggered()
{
    terminal.sendCmdAndTellMustWait("th");
    moveMotorB(0, false);
    moveMotorC(0, false);
    moveMotorD(0, false);
    moveMotorE(1200, false); // Home de la cinemática: 1196
    moveMotorF(0, false);
    terminal.sendCmdAndTellMustWait("mc");
    while (terminal.sendCmdSynchronous("ss") == "128");
    terminal.sendCmdAndTellMustWait("ac,e");

    enableKinematics();

    //bool checked = ui->checkBox_dirkinKeepDirkin->isChecked();
    //ui->checkBox_dirkinKeepDirkin->setChecked(false);

    ui->dial_dirkinTheta5B->setValue(xr4.steps2deg(0, 'B'));
    ui->dial_dirkinTheta4C->setValue(xr4.steps2deg(0, 'C'));
    ui->dial_dirkinTheta3D->setValue(xr4.steps2deg(0, 'D'));
    ui->dial_dirkinTheta2E->setValue(xr4.steps2deg(0, 'E')); // antes: 1200 (por home cinemática)
    ui->dial_dirkinTheta1F->setValue(xr4.steps2deg(0, 'F'));

    dirkinOldValue[0] = 90;
    dirkinOldValue[1] = 90;
    dirkinOldValue[2] = -90;
    dirkinOldValue[3] = 0;
    dirkinOldValue[4] = 180;

    updateDirkin();

    //ui->checkBox_dirkinKeepDirkin->setChecked(checked);
}

void MainWindow::on_actionSetSoftHome_triggered()
{
    terminal.sendCmdAndTellMustWait("th");
    terminal.sendCmdAndTellMustWait("ac,b");
    terminal.sendCmdAndTellMustWait("ac,c");
    terminal.sendCmdAndTellMustWait("ac,d");
    terminal.sendCmdAndTellMustWait("ac,e");
    terminal.sendCmdAndTellMustWait("ac,f");
    on_actionSoftHome_triggered();
}

void MainWindow::on_pushButton_copyInvkin_clicked()
{
    ui->doubleSpinBox_dirkinTheta1F->setValue(ui->doubleSpinBox_invkinTheta1F->value());
    ui->doubleSpinBox_dirkinTheta2E->setValue(ui->doubleSpinBox_invkinTheta2E->value());
    ui->doubleSpinBox_dirkinTheta3D->setValue(ui->doubleSpinBox_invkinTheta3D->value());
    ui->doubleSpinBox_dirkinTheta4C->setValue(ui->doubleSpinBox_invkinTheta4C->value());
    ui->doubleSpinBox_dirkinTheta5B->setValue(ui->doubleSpinBox_invkinTheta5B->value());
}

void MainWindow::on_comboBox_invkinVersion_currentIndexChanged(int index)
{
    updateInvkin();
}

void MainWindow::on_pushButton_computeDirKin_clicked()
{
    updateDirkin();
}

void MainWindow::on_pushButton_computeInvKin_clicked()
{
    updateInvkin();
}

void MainWindow::enableKinematics()
{
    /*ui->doubleSpinBox_dirkinTheta1F->setEnabled(true);
    ui->doubleSpinBox_dirkinTheta2E->setEnabled(true);
    ui->doubleSpinBox_dirkinTheta3D->setEnabled(true);
    ui->doubleSpinBox_dirkinTheta4C->setEnabled(true);
    ui->doubleSpinBox_dirkinTheta5B->setEnabled(true);

    ui->dial_dirkinTheta1F->setEnabled(true);
    ui->dial_dirkinTheta2E->setEnabled(true);
    ui->dial_dirkinTheta3D->setEnabled(true);
    ui->dial_dirkinTheta4C->setEnabled(true);
    ui->dial_dirkinTheta5B->setEnabled(true);

    ui->pushButton_copyDirkin->setEnabled(true);
    ui->pushButton_computeDirKin->setEnabled(true);*/

    ui->label_dirkinWarning->setVisible(false);
    ui->label_invkinWarning->setVisible(false);
    ui->pushButton_dirkinGoToPos->setVisible(true);
    ui->pushButton_invkinGoToPos->setVisible(true);
}

void MainWindow::disableKinematics()
{
    ui->label_dirkinWarning->setVisible(true);
    ui->label_invkinWarning->setVisible(true);
    ui->pushButton_dirkinGoToPos->setVisible(false);
    ui->pushButton_invkinGoToPos->setVisible(false);
}
