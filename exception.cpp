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

#include "exception.hpp"

#include <QObject>

#include <iostream>
using namespace std;

Exception::Exception(QString newMsg)
{
    _description = QObject::tr("Generic exception");
    setMessage(newMsg);
}

QString Exception::description()
{
    return _description;
}

QString Exception::message()
{
    return _message;
}

void Exception::setMessage(QString newMsg)
{
    _message = newMsg;
}

void Exception::printMessage()
{
    cout << message().toStdString() << endl;
}
