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

#include "rhinoprog.hpp"

#include <QFile>

RhinoProg::RhinoProg(QByteArray newCode)
{
    if (!newCode.isEmpty())
        setCode(newCode);
}

void RhinoProg::saveToPath(QString path)
{
    QFile outf(path);
    outf.open(QFile::WriteOnly | QFile::Text);
    outf.write(getCode());
    outf.close();
}

void RhinoProg::setCode(QByteArray newCode)
{
    code = newCode.trimmed();
    appendCode("\n");
}

void RhinoProg::appendCode(QByteArray newCode)
{
    code.append(newCode);
}

QByteArray RhinoProg::getCode()
{
    return code;
}
