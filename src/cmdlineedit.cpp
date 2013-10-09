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

#include "cmdlineedit.hpp"

#include <QKeyEvent>

CmdLineEdit::CmdLineEdit(QWidget *parent) : QLineEdit(parent)
{
    historyIndex = 0;
}

void CmdLineEdit::addCmdToHistory(QString cmd)
{
    _cmdHistory.append(cmd);
    historyIndex++;
}

QStringList CmdLineEdit::cmdHistory()
{
    return _cmdHistory;
}

void CmdLineEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        if (!_cmdHistory.isEmpty() && historyIndex > 0)
        {
            historyIndex--;
            setText(_cmdHistory.at(historyIndex));
        }
    }
    else if (event->key() == Qt::Key_Down)
    {
        if (!_cmdHistory.isEmpty())
        {
            if (++historyIndex < _cmdHistory.size())
                setText(_cmdHistory.at(historyIndex));
            else
            {
                historyIndex = _cmdHistory.size();
                setText(currentCmd);
            }
        }
    }
    else
        QLineEdit::keyPressEvent(event);
}
