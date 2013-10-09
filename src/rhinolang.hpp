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

#ifndef RHINOLANG_H
#define RHINOLANG_H

#include <QString>

/********************************************************************************************************
 * SYNTAX FOR COMMANDS
 *******************************************************************************************************/

#define ARGSEP    "," // character that separates the command name from its arguments

/********************************************************************************************************
 * SYNTAX FOR PROGRAM FILES
 *******************************************************************************************************/

#define FILESTART         "\x30\x30\x31\x31\x31\x31\x31\x31\x31\x31\x30" // start of file
//#define FILEEND           "\x25\x1a\x1a"                                 // end of file
#define FILEEND           "\x25\x1a"                                 // end of file
#define CMDSEP            "\n"                                           // command separator

/********************************************************************************************************
 * SYNTAX FOR TERMINAL
 *******************************************************************************************************/

#define CMDEND         "\r" // command separator (end of command)

bool mustWaitResponseFromCmd(QString cmd);

#endif // RHINOLANG_H
