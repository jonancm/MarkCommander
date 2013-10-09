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

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>
#include <QObject>

class Exception
{
protected:
    QString    _description; // brief description (or name) of the exception
    QString    _message;     // longer message describing the exception
public:
               Exception(QString newMsg="");
    QString    description();
    QString    message();
    void       setMessage(QString newMsg);
    void       printMessage();
};

#endif // EXCEPTION_H
