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

#include "rhinolang.hpp"

#include <QSet>

bool mustWaitResponseFromCmd(QString cmd)
{
    QSet<QString> matchingCmds;

    matchingCmds.insert("SE");
    matchingCmds.insert("SA");
    matchingCmds.insert("SC");
    matchingCmds.insert("SE");
    matchingCmds.insert("SM");
    matchingCmds.insert("SP");
    matchingCmds.insert("SS");
    matchingCmds.insert("SU");
    matchingCmds.insert("SV");
    matchingCmds.insert("SZ");
    matchingCmds.insert("AR");
    matchingCmds.insert("DR");
    matchingCmds.insert("GS");
    matchingCmds.insert("HR");
    matchingCmds.insert("PA");
    matchingCmds.insert("PW");
    matchingCmds.insert("PZ");
    matchingCmds.insert("RL");
    matchingCmds.insert("UA");
    matchingCmds.insert("UH");
    matchingCmds.insert("UO");
    matchingCmds.insert("UT");
    matchingCmds.insert("UY");
    matchingCmds.insert("VA");
    matchingCmds.insert("VR");
    matchingCmds.insert("VX");
    matchingCmds.insert("XR");
    matchingCmds.insert("FT");
    matchingCmds.insert("RA");
    matchingCmds.insert("RB");
    matchingCmds.insert("RC");
    matchingCmds.insert("IB");
    matchingCmds.insert("IP");
    matchingCmds.insert("IX");
    matchingCmds.insert("OR");

    return matchingCmds.contains(cmd.toLower()) || matchingCmds.contains(cmd.toUpper());
}
