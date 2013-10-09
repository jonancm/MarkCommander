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

#include "errorcodes.hpp"

// Reg exp for Notepad++'s Ctrl-H (Search & Replace):
// >>(\#define)( )([A-Z\_]+)([ ]+[0-9]+[ ]+//[ ])([A-Za-z0-9 \'\(\)\,\.=]+)<<
// >>        case \3: return "\5";<<

const char * errcode_meaning(int errorno)
{
    switch (errorno)
    {
        /***********************************************************************
         *                            COMMAND ERRORS
         ***********************************************************************/

        case INV_CMD: return "Invalid command";
        case PAR_OUT: return "Parameter out of bounds";
        case MIS_PAR: return "Missing parameter";
        case NO_DLIM: return "Expected delimiter not seen";
        case TOO_MNY: return "Command string too long";
        case TP_ACTV: return "The teach pendant is active or busy";

        /***********************************************************************
         *                         COMMUNICATION ERRORS
         ***********************************************************************/

        case HST_OVF: return "Host input buffer overflow";
        case HST_TMO: return "Host USART timed out";
        case HST_ERR: return "Host USART error (framing, parity, etc.)";
        case TP_OVF:  return "Teach pendant input buffer overflow";
        case TP_TMO:  return "Teach pendant USART timed out";
        case TP_ERRO: return "Teach pendant USART error (framing, parity, etc.)";
        case TP_OVRN: return "Teach pendant USART overrun";
        case HST_OVR: return "Host USART overrun";

        /***********************************************************************
         *                          DIAGNOSTIC ERRORS
         ***********************************************************************/

        case BAD_RAM: return "Bad RAM location";
        case TP_ERR:  return "Teach pendant returned diagnostic error";
        case NO_TP:   return "Teach pendant not present";

        /***********************************************************************
         *                    TEACH PENDANT PROGRAM ERRORS
         ***********************************************************************/

        case LAB_ERR: return "Missing label";
        case NO_PGRM: return "No program in memory";
        case MEM_FUL: return "Insufficient teach pendant memory";
        case EPM_FUL: return "Insufficient EEPROM memory";
        case RPL_ERR: return "Can't replace first record";
        case PROGRAM: return "A pendant program already exists";

        /***********************************************************************
         *                          EXECUTION ERRORS
         ***********************************************************************/

        case HRD_ERR: return "Hard home routine failed";
        case NO_HARD: return "Hard home not set";
        case NO_SOFT: return "Soft home not set";
        case AR_OVFL: return "Arithmetic overflow";
        case TRG_ERR: return "Trig function return error";
        case STK_ERR: return "Error stack overflow";
        case BUSY:    return "Still executing a trapezoidal move";
        case NO_MOTR: return "Inactive motor referenced";
        case MOV_DAT: return "Insufficient move data (velocity or acceleration = 0)";
        case BAD_MOD: return "Improper motor mode for command";
        case NO_A_SW: return "Limit switch A not found";
        case NO_B_SW: return "Limit switch B not found";
        case NO_C_SW: return "Limit switch C not found";
        case NO_D_SW: return "Limit switch D not found";
        case NO_E_SW: return "Limit switch E not found";
        case NO_F_SW: return "Limit switch F not found";
        case NO_G_SW: return "Limit switch G not found";
        case NO_H_SW: return "Limit switch H not found";
        case IMODE:   return "Interpolation move out of bounds";
        case POS_OUT: return "XYZ position out of bounds";
        case STK_A_S: return "Limit switch A stuck";
        case STK_B_S: return "Limit switch B stuck";
        case STK_C_S: return "Limit switch C stuck";
        case STK_D_S: return "Limit switch D stuck";
        case STK_E_S: return "Limit switch E stuck";
        case STK_F_S: return "Limit switch F stuck";
        case STK_G_S: return "Limit switch G stuck";
        case STK_H_S: return "Limit switch H stuck";
        case INV_RBT: return "Invalid robot type specifier";
        case INV_MOT: return "Invalid motor specifier";
        case INV_CTL: return "Invalid controller type";
        case INV_PND: return "Invalid pendant mode";
        case STOP:    return "Emergency stop";
        case INV_XYZ: return "Invalid xyz specifier";
        case XYZ_PAR: return "Invalid xyz parameter";

        /***********************************************************************
         *                            MOTOR ERRORS
         ***********************************************************************/

        case A_STALL:  return "Motor A stalled";
        case B_STALL:  return "Motor B stalled";
        case C_STALL:  return "Motor C stalled";
        case D_STALL:  return "Motor D stalled";
        case E_STALL:  return "Motor E stalled";
        case F_STALL:  return "Motor F stalled";
        case G_STALL:  return "Motor G stalled";
        case H_STALL:  return "Motor H stalled";
        case A_CURLIM: return "Motor A's current limit circuit was activated";
        case B_CURLIM: return "Motor B's current limit circuit was activated";
        case C_CURLIM: return "Motor C's current limit circuit was activated";
        case D_CURLIM: return "Motor D's current limit circuit was activated";
        case E_CURLIM: return "Motor E's current limit circuit was activated";
        case F_CURLIM: return "Motor F's current limit circuit was activated";
        case G_CURLIM: return "Motor G's current limit circuit was activated";
        case H_CURLIM: return "Motor H's current limit circuit was activated";
        case I_CURLIM: return "Aux Port 1's current limit circuit was activated";
        case J_CURLIM: return "Aux Port 2's current limit circuit was activated";

        default: return "Unknown error code";
    }
}
