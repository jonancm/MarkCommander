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

#ifndef ERRORCODES_H
#define ERRORCODES_H

/***********************************************************************
 *                            COMMAND ERRORS
 ***********************************************************************/

#define INV_CMD    10 // Invalid command
#define PAR_OUT    11 // Parameter out of bounds
#define MIS_PAR    12 // Missing parameter
#define NO_DLIM    13 // Expected delimiter not seen
#define TOO_MNY    14 // Command string too long
#define TP_ACTV    16 // The teach pendant is active or busy

/***********************************************************************
 *                         COMMUNICATION ERRORS
 ***********************************************************************/

#define HST_OVF    20    // Host input buffer overflow
#define HST_TMO    21    // Host USART timed out
#define HST_ERR    22    // Host USART error (framing, parity, etc.)
#define TP_OVF     23    // Teach pendant input buffer overflow
#define TP_TMO     24    // Teach pendant USART timed out
#define TP_ERRO    25    // Teach pendant USART error (framing, parity, etc.)
#define TP_OVRN    26    // Teach pendant USART overrun
#define HST_OVR    27    // Host USART overrun

/***********************************************************************
 *                          DIAGNOSTIC ERRORS
 ***********************************************************************/

#define BAD_RAM    30    // Bad RAM location
#define TP_ERR     32    // Teach pendant returned diagnostic error
#define NO_TP      34    // Teach pendant not present

/***********************************************************************
 *                    TEACH PENDANT PROGRAM ERRORS
 ***********************************************************************/

#define LAB_ERR    40    // Missing label
#define NO_PGRM    41    // No program in memory
#define MEM_FUL    42    // Insufficient teach pendant memory
#define EPM_FUL    43    // Insufficient EEPROM memory
#define RPL_ERR    44    // Can't replace first record
#define PROGRAM    45    // A pendant program already exists

/***********************************************************************
 *                          EXECUTION ERRORS
 ***********************************************************************/

#define HRD_ERR    50    // Hard home routine failed
#define NO_HARD    51    // Hard home not set
#define NO_SOFT    52    // Soft home not set
#define AR_OVFL    53    // Arithmetic overflow
#define TRG_ERR    54    // Trig function return error
#define STK_ERR    55    // Error stack overflow
#define BUSY       56    // Still executing a trapezoidal move
#define NO_MOTR    57    // Inactive motor referenced
#define MOV_DAT    58    // Insufficient move data (velocity or acceleration = 0)
#define BAD_MOD    59    // Improper motor mode for command
#define NO_A_SW    60    // Limit switch A not found
#define NO_B_SW    61    // Limit switch B not found
#define NO_C_SW    62    // Limit switch C not found
#define NO_D_SW    63    // Limit switch D not found
#define NO_E_SW    64    // Limit switch E not found
#define NO_F_SW    65    // Limit switch F not found
#define NO_G_SW    66    // Limit switch G not found
#define NO_H_SW    67    // Limit switch H not found
#define IMODE      69    // Interpolation move out of bounds
#define POS_OUT    70    // XYZ position out of bounds
#define STK_A_S    80    // Limit switch A stuck
#define STK_B_S    81    // Limit switch B stuck
#define STK_C_S    82    // Limit switch C stuck
#define STK_D_S    83    // Limit switch D stuck
#define STK_E_S    84    // Limit switch E stuck
#define STK_F_S    85    // Limit switch F stuck
#define STK_G_S    86    // Limit switch G stuck
#define STK_H_S    87    // Limit switch H stuck
#define INV_RBT    91    // Invalid robot type specifier
#define INV_MOT    92    // Invalid motor specifier
#define INV_CTL    93    // Invalid controller type
#define INV_PND    94    // Invalid pendant mode
#define STOP       95    // Emergency stop
#define INV_XYZ    96    // Invalid xyz specifier
#define XYZ_PAR    97    // Invalid xyz parameter

/***********************************************************************
 *                            MOTOR ERRORS
 ***********************************************************************/

#define A_STALL     100    // Motor A stalled
#define B_STALL     101    // Motor B stalled
#define C_STALL     102    // Motor C stalled
#define D_STALL     103    // Motor D stalled
#define E_STALL     104    // Motor E stalled
#define F_STALL     105    // Motor F stalled
#define G_STALL     106    // Motor G stalled
#define H_STALL     107    // Motor H stalled
#define A_CURLIM    110    // Motor A's current limit circuit was activated
#define B_CURLIM    111    // Motor B's current limit circuit was activated
#define C_CURLIM    112    // Motor C's current limit circuit was activated
#define D_CURLIM    113    // Motor D's current limit circuit was activated
#define E_CURLIM    114    // Motor E's current limit circuit was activated
#define F_CURLIM    115    // Motor F's current limit circuit was activated
#define G_CURLIM    116    // Motor G's current limit circuit was activated
#define H_CURLIM    117    // Motor H's current limit circuit was activated
#define I_CURLIM    118    // Aux Port 1's current limit circuit was activated
#define J_CURLIM    119    // Aux Port 2's current limit circuit was activated

const char * errcode_meaning(int errorno);

#endif // ERRORCODES_H
