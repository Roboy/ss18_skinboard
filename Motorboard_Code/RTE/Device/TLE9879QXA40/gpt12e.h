/**
 * @cond
 ***********************************************************************************************************************
 *
 * Copyright (c) 2015, Infineon Technologies AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,are permitted provided that the
 * following conditions are met:
 *
 *   Redistributions of source code must retain the above copyright notice, this list of conditions and the  following
 *   disclaimer.
 *
 *   Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
 *   following disclaimer in the documentation and/or other materials provided with the distribution.
 *
 *   Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote
 *   products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **********************************************************************************************************************/


/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* See gpt12e.c */

#ifndef GPT12E_H
#define GPT12E_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "gpt12e_defines.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

typedef enum
{
  GPT_Clk_Div_1   = 0,
  GPT_Clk_Div_2   = 1,
  GPT_Clk_Div_4   = 2,
  GPT_Clk_Div_8   = 3,  
  GPT_Clk_Div_16  = 4,
  GPT_Clk_Div_32  = 5,
  GPT_Clk_Div_64  = 6,
  GPT_Clk_Div_128 = 7  
} TGPT12E_Mode_Timer_Prescaler;

/****************************************************************************/
/* GPT1   *******************************************************************/
/****************************************************************************/

typedef enum
{
  GPT1_fSYS_Div_4  = 0u,
  GPT1_fSYS_Div_8  = 1u,
  GPT1_fSYS_Div_16 = 2u,  
  GPT1_fSYS_Div_32 = 3u
} TGPT1_Clk_Prescaler;

/* GPT1 Clock */
#define GPT12E_GPT1_Clk_Prescaler_Sel(bps1)              (GPT12E->T3CON.bit.BPS1 = (uint16)((bps1 & 3u) ^ 1u))
#define GPT12E_GPT1_Clk_Prescaler_Get()                (((GPT12E->T3CON.reg >> 11u) & 3u) ^ 1u)

typedef enum
{
  GPT12E_CCU6_CH0        = 0u,
  GPT12E_CCU6_CH1        = 1u,
  GPT12E_CCU6_CH2        = 2u,
  GPT12E_CCU6_T12_ZM     = 3u,
  GPT12E_CCU6_T12_PM     = 4u,
  GPT12E_CCU6_T12_CM_CH0 = 5u,
  GPT12E_CCU6_T12_CM_CH1 = 6u,
  GPT12E_CCU6_T12_CM_CH2 = 7u,
  GPT12E_CCU6_T13_PM     = 8u,
  GPT12E_CCU6_T13_ZM     = 9u,
  GPT12E_CCU6_T13_CM     = 10u,
  GPT12E_CCU6_ANY_CHx    = 11u  
} TGPT12E_CCU6_SEL;

#define GPT12E_T3_T4_CCU6_Sel(gpt)                       (SCU->GPT12PISEL.bit.GPT12 = (uint16)(gpt & 0xFu))
/****************************************************************************/
/* Timer2 *******************************************************************/
/****************************************************************************/
typedef enum
{
  GPT12E_T2INA_P12  = 0u,
  GPT12E_T2INB_P14  = 1u
} TGPT12E_T2IN;

typedef enum
{
  GPT12E_T2EUDA_P02 = 0u,
  GPT12E_T2EUDB_P24 = 1u
} TGPT12E_T2EUD;

/* T2 Mode */
#define GPT12E_T2_Mode_Timer_Sel()                       (GPT12E->T2CON.bit.T2M = 0u)
#define GPT12E_T2_Mode_Counter_Sel()                     (GPT12E->T2CON.bit.T2M = 1u)
#define GPT12E_T2_Mode_Gated_Timer_Low_Sel()             (GPT12E->T2CON.bit.T2M = 2u)
#define GPT12E_T2_Mode_Gated_Timer_High_Sel()            (GPT12E->T2CON.bit.T2M = 3u)
#define GPT12E_T2_Mode_Reload_Sel()                      (GPT12E->T2CON.bit.T2M = 4u)
#define GPT12E_T2_Mode_Capture_Sel()                     (GPT12E->T2CON.bit.T2M = 5u)
#define GPT12E_T2_Mode_IncEnc_Rot_Sel()                  (GPT12E->T2CON.bit.T2M = 6u)
#define GPT12E_T2_Mode_IncEnc_Edge_Sel()                 (GPT12E->T2CON.bit.T2M = 7u)

/* T2 Input Parameter Selection */
#define GPT12E_T2_Mode_Timer_Clk_Prescaler_Sel(t2i)      (GPT12E->T2CON.bit.T2I = (uint16)(t2i & 7u))
#define GPT12E_T2_Mode_Gated_Timer_Clk_Prescaler_Sel(t2i) \
                                                         (GPT12E->T2CON.bit.T2I = (uint16)(t2i & 7u))
#define GPT12E_T2_Mode_Counter_Input_T2In_Sel()          (GPT12E->T2CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T2_Mode_Counter_Input_Rising_T2In_En()    (GPT12E->T2CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T2_Mode_Counter_Input_Rising_T2In_Dis()   (GPT12E->T2CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T2_Mode_Counter_Input_Falling_T2In_En()   (GPT12E->T2CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T2_Mode_Counter_Input_Falling_T2In_Dis()  (GPT12E->T2CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T2_Mode_Counter_Input_T3Out_Sel()         (GPT12E->T2CON.reg |= (uint16) (1u << 2u))
#define GPT12E_T2_Mode_Counter_Input_Rising_T3Out_En()   (GPT12E->T2CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T2_Mode_Counter_Input_Rising_T3Out_Dis()  (GPT12E->T2CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T2_Mode_Counter_Input_Falling_T3Out_En()  (GPT12E->T2CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T2_Mode_Counter_Input_Falling_T3Out_Dis() (GPT12E->T2CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T2_Mode_Capture_Input_T2In_Sel()          (GPT12E->T2CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T2_Mode_Capture_Input_Rising_T2In_En()    (GPT12E->T2CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T2_Mode_Capture_Input_Rising_T2In_Dis()   (GPT12E->T2CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T2_Mode_Capture_Input_Falling_T2In_En()   (GPT12E->T2CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T2_Mode_Capture_Input_Falling_T2In_Dis()  (GPT12E->T2CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T2_Mode_Reload_Input_T2In_Sel()           (GPT12E->T2CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T2_Mode_Reload_Input_Rising_T2In_En()     (GPT12E->T2CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T2_Mode_Reload_Input_Rising_T2In_Dis()    (GPT12E->T2CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T2_Mode_Reload_Input_Falling_T2In_En()    (GPT12E->T2CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T2_Mode_Reload_Input_Falling_T2In_Dis()   (GPT12E->T2CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T2_Mode_Reload_Input_T3Out_Sel()          (GPT12E->T2CON.reg |= (uint16) (1u << 2u))
#define GPT12E_T2_Mode_Reload_Input_Rising_T3Out_En()    (GPT12E->T2CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T2_Mode_Reload_Input_Rising_T3Out_Dis()   (GPT12E->T2CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T2_Mode_Reload_Input_Falling_T3Out_En()   (GPT12E->T2CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T2_Mode_Reload_Input_Falling_T3Out_Dis()  (GPT12E->T2CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T2_Mode_IncEnc_Input_Sel()                (GPT12E->T2CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T2_Mode_IncEnc_Any_T3IN_En()              (GPT12E->T2CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T2_Mode_IncEnc_Any_T3IN_Dis()             (GPT12E->T2CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T2_Mode_IncEnc_Any_T3EUD_En()             (GPT12E->T2CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T2_Mode_IncEnc_Any_T3EUD_Dis()            (GPT12E->T2CON.reg &= (uint16)~(1u << 1u))

/* T2 Run Control */
#define GPT12E_T2_Start()                                (GPT12E->T2CON.reg |= (uint16) (1u << 6u))
#define GPT12E_T2_Stop()                                 (GPT12E->T2CON.reg &= (uint16)~(1u << 6u))
#define GPT12E_T2_Start_by_T3_Dis()                      (GPT12E->T2CON.reg |= (uint16) (1u << 9u))
#define GPT12E_T2_Start_by_T3_En()                       (GPT12E->T2CON.reg &= (uint16)~(1u << 9u))

/* T2 Up/Down Control */                              
#define GPT12E_T2_DownCount_Sel()                        (GPT12E->T2CON.reg |= (uint16) (1u << 7u))
#define GPT12E_T2_UpCount_Sel()                          (GPT12E->T2CON.reg &= (uint16)~(1u << 7u))
#define GPT12E_T2_UpDownCount_Ext_En()                   (GPT12E->T2CON.reg |= (uint16) (1u << 8u))
#define GPT12E_T2_UpDownCount_Ext_Dis()                  (GPT12E->T2CON.reg &= (uint16)~(1u << 8u))
#define GPT12E_T2_Mode_IncEnc_DownCount_RotDir_Sel()     (GPT12E->T2CON.reg |= (uint16) (1u << 15u))
#define GPT12E_T2_Mode_IncEnc_UpCount_RotDir_Sel()       (GPT12E->T2CON.reg &= (uint16)~(1u << 15u))

/* T2 Edge Detection Status/Clear (Inc. Encoder Mode) */
#define GPT12E_T2_Mode_IncEnc_Edge_Detect_Sts()         ((GPT12E->T2CON.reg >> 13u) & 1u)
#define GPT12E_T2_Mode_IncEnc_Edge_Detect_Clr()          (GPT12E->T2CON.reg &= (uint16)~(1u << 13u))

/* T2 Direction Change Status/Clear (Inc. Encoder Mode) */
#define GPT12E_T2_Mode_IncEnc_Dir_Change_Sts()          ((GPT12E->T2CON.reg >> 14u) & 1u)
#define GPT12E_T2_Mode_IncEnc_Dir_Change_Clr()           (GPT12E->T2CON.reg &= (uint16)~(1u << 14u))

/* T2 Timer Value */
#define GPT12E_T2_Value_Get()                            ((uint16)GPT12E->T2.reg)
#define GPT12E_T2_Value_Set(t2)                          (GPT12E->T2.reg = (uint16)t2)

/* T2 Pin Selection */
#define GPT12E_T2_T2In_Sel(ist2in)                       (GPT12E->PISEL.bit.IST2IN  = (uint16)(ist2in & 1u))
#define GPT12E_T2_T2EUD_Sel(ist2eud)                     (GPT12E->PISEL.bit.IST2EUD = (uint16)(ist2eud & 1u))

/****************************************************************************/
/* Timer3 * Core Timer ******************************************************/
/****************************************************************************/
typedef enum
{
  GPT12E_T3INA_CCU6_CH0 = 0u,
  GPT12E_T3INB_CCU6_SEL = 1u,
  GPT12E_T3INC_P10      = 2u,
  GPT12E_T3IND_MON      = 3u
} TGPT12E_T3IN;

typedef enum
{
  GPT12E_T3EUDA_P04     = 0u,
  GPT12E_T3EUDB_P25     = 1u
} TGPT12E_T3EUD;

/* T3 Mode */
#define GPT12E_T3_Mode_Timer_Sel()                       (GPT12E->T3CON.bit.T3M = 0u)
#define GPT12E_T3_Mode_Counter_Sel()                     (GPT12E->T3CON.bit.T3M = 1u)
#define GPT12E_T3_Mode_Gated_Timer_Low_Sel()             (GPT12E->T3CON.bit.T3M = 2u)
#define GPT12E_T3_Mode_Gated_Timer_High_Sel()            (GPT12E->T3CON.bit.T3M = 3u)
#define GPT12E_T3_Mode_IncEnc_Rot_Sel()                  (GPT12E->T3CON.bit.T3M = 6u)
#define GPT12E_T3_Mode_IncEnc_Edge_Sel()                 (GPT12E->T3CON.bit.T3M = 7u)

/* T3 Input Parameter Selection */
#define GPT12E_T3_Mode_Timer_Clk_Prescaler_Sel(t3i)      (GPT12E->T3CON.bit.T3I = (uint16)(t3i & 7u))
#define GPT12E_T3_Mode_Gated_Timer_Clk_Prescaler_Sel(t3i) \
                                                         (GPT12E->T3CON.bit.T3I = (uint16)(t3i & 7u))
#define GPT12E_T3_Mode_Counter_Input_Rising_T3In_En()    (GPT12E->T3CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T3_Mode_Counter_Input_Rising_T3In_Dis()   (GPT12E->T3CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T3_Mode_Counter_Input_Falling_T3In_En()   (GPT12E->T3CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T3_Mode_Counter_Input_Falling_T3In_Dis()  (GPT12E->T3CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T3_Mode_IncEnc_Any_T3In_En()              (GPT12E->T3CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T3_Mode_IncEnc_Any_T3In_Dis()             (GPT12E->T3CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T3_Mode_IncEnc_Any_T3EUD_En()             (GPT12E->T3CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T3_Mode_IncEnc_Any_T3EUD_Dis()            (GPT12E->T3CON.reg &= (uint16)~(1u << 1u))

/* T3 Run Control */
#define GPT12E_T3_Start()                                (GPT12E->T3CON.reg |= (uint16) (1u << 6u))
#define GPT12E_T3_Stop()                                 (GPT12E->T3CON.reg &= (uint16)~(1u << 6u))

/* T3 Output Toggle Latch */
#define GPT12E_T3_Output_En()                            (GPT12E->T3CON.reg |= (uint16) (1u << 9u))
#define GPT12E_T3_Output_Dis()                           (GPT12E->T3CON.reg &= (uint16)~(1u << 9u))
#define GPT12E_T3_Output_Set()                           (GPT12E->T3CON.reg |= (uint16) (1u << 10u))
#define GPT12E_T3_Output_Rst()                           (GPT12E->T3CON.reg &= (uint16)~(1u << 10u))

/* T3 Up/Down Control */
#define GPT12E_T3_DownCount_Sel()                        (GPT12E->T3CON.reg |= (uint16) (1u << 7u))
#define GPT12E_T3_UpCount_Sel()                          (GPT12E->T3CON.reg &= (uint16)~(1u << 7u))
#define GPT12E_T3_UpDownCount_Ext_En()                   (GPT12E->T3CON.reg |= (uint16) (1u << 8u))
#define GPT12E_T3_UpDownCount_Ext_Dis()                  (GPT12E->T3CON.reg &= (uint16)~(1u << 8u))
#define GPT12E_T3_Mode_IncEnc_DownCount_RotDir_Sel()     (GPT12E->T3CON.reg |= (uint16) (1u << 15u))
#define GPT12E_T3_Mode_IncEnc_UpCount_RotDir_Sel()       (GPT12E->T3CON.reg &= (uint16)~(1u << 15u))

/* T3 Edge Detection Status/Clear (Inc. Encoder Mode) */
#define GPT12E_T3_Mode_IncEnc_Edge_Detect_Sts()         ((GPT12E->T3CON.reg >> 13u) & 1u)
#define GPT12E_T3_Mode_IncEnc_Edge_Detect_Clr()          (GPT12E->T3CON.reg &= (uint16)~(1u << 13u))

/* T3 Direction Change Status/Clear (Inc. Encoder Mode) */
#define GPT12E_T3_Mode_IncEnc_Dir_Change_Sts()          ((GPT12E->T3CON.reg >> 14u) & 1u)
#define GPT12E_T3_Mode_IncEnc_Dir_Change_Clr()           (GPT12E->T3CON.reg &= (uint16)~(1u << 14u))

/* T3 Timer Value */
#define GPT12E_T3_Value_Get()                            ((uint16)GPT12E->T3.reg)
#define GPT12E_T3_Value_Set(t3)                          (GPT12E->T3.reg = (uint16)t3)

/* T3 Pin Selection */
#define GPT12E_T3_T3In_Sel(ist3in)                       (GPT12E->PISEL.bit.IST3IN = (uint16)(ist3in & 3u))
#define GPT12E_T3_T3EUD_Sel(ist3eud)                     (GPT12E->PISEL.bit.IST3EUD = (uint16)(ist3eud & 3u))

/****************************************************************************/
/* Timer4 *******************************************************************/
/****************************************************************************/
typedef enum
{
  GPT12E_T4INA_P00      = 0u,
  GPT12E_T4INB_CCU6_CH0 = 1u,
  GPT12E_T4INC_P01      = 2u,
  GPT12E_T4IND_CCU6_SEL = 3u
} TGPT12E_T4IN;

typedef enum
{
  GPT12E_T4EUDA_P03     = 0u,
  GPT12E_T4EUDB_P10     = 1u
} TGPT12E_T4EUD;

/* T4 Mode */
#define GPT12E_T4_Mode_Timer_Sel()                       (GPT12E->T4CON.bit.T4M = 0u)
#define GPT12E_T4_Mode_Counter_Sel()                     (GPT12E->T4CON.bit.T4M = 1u)
#define GPT12E_T4_Mode_Gated_Timer_Low_Sel()             (GPT12E->T4CON.bit.T4M = 2u)
#define GPT12E_T4_Mode_Gated_Timer_High_Sel()            (GPT12E->T4CON.bit.T4M = 3u)
#define GPT12E_T4_Mode_Reload_Sel()                      (GPT12E->T4CON.bit.T4M = 4u)
#define GPT12E_T4_Mode_Capture_Sel()                     (GPT12E->T4CON.bit.T4M = 5u)
#define GPT12E_T4_Mode_IncEnc_Rot_Sel()                  (GPT12E->T4CON.bit.T4M = 6u)
#define GPT12E_T4_Mode_IncEnc_Edge_Sel()                 (GPT12E->T4CON.bit.T4M = 7u)

/* T4 Input Parameter Selection */
#define GPT12E_T4_Mode_Timer_Clk_Prescaler_Sel(t4i)      (GPT12E->T4CON.bit.T4I = (uint16)(t4i & 7u))
#define GPT12E_T4_Mode_Gated_Timer_Clk_Prescaler_Sel(t4i) \
                                                         (GPT12E->T4CON.bit.T4I = (uint16)(t4i & 7u))
#define GPT12E_T4_Mode_Counter_Input_T4In_Sel()          (GPT12E->T4CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T4_Mode_Counter_Input_Rising_T4In_En()    (GPT12E->T4CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T4_Mode_Counter_Input_Rising_T4In_Dis()   (GPT12E->T4CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T4_Mode_Counter_Input_Falling_T4In_En()   (GPT12E->T4CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T4_Mode_Counter_Input_Falling_T4In_Dis()  (GPT12E->T4CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T4_Mode_Counter_Input_T3Out_Sel()         (GPT12E->T4CON.reg |= (uint16) (1u << 2u))
#define GPT12E_T4_Mode_Counter_Input_Rising_T3Out_En()   (GPT12E->T4CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T4_Mode_Counter_Input_Rising_T3Out_Dis()  (GPT12E->T4CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T4_Mode_Counter_Input_Falling_T3Out_En()  (GPT12E->T4CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T4_Mode_Counter_Input_Falling_T3Out_Dis() (GPT12E->T4CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T4_Mode_Capture_Input_T4In_Sel()          (GPT12E->T4CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T4_Mode_Capture_Input_Rising_T4In_En()    (GPT12E->T4CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T4_Mode_Capture_Input_Rising_T4In_Dis()   (GPT12E->T4CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T4_Mode_Capture_Input_Falling_T4In_En()   (GPT12E->T4CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T4_Mode_Capture_Input_Falling_T4In_Dis()  (GPT12E->T4CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T4_Mode_Reload_Input_T4In_Sel()           (GPT12E->T4CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T4_Mode_Reload_Input_Rising_T4In_En()     (GPT12E->T4CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T4_Mode_Reload_Input_Rising_T4In_Dis()    (GPT12E->T4CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T4_Mode_Reload_Input_Falling_T4In_En()    (GPT12E->T4CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T4_Mode_Reload_Input_Falling_T4In_Dis()   (GPT12E->T4CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T4_Mode_Reload_Input_T3Out_Sel()          (GPT12E->T4CON.reg |= (uint16) (1u << 2u))
#define GPT12E_T4_Mode_Reload_Input_Rising_T3Out_En()    (GPT12E->T4CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T4_Mode_Reload_Input_Rising_T3Out_Dis()   (GPT12E->T4CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T4_Mode_Reload_Input_Falling_T3Out_En()   (GPT12E->T4CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T4_Mode_Reload_Input_Falling_T3Out_Dis()  (GPT12E->T4CON.reg &= (uint16)~(1u << 1u))

#define GPT12E_T4_Mode_IncEnc_Any_T3In_En()              (GPT12E->T4CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T4_Mode_IncEnc_Any_T3In_Dis()             (GPT12E->T4CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T4_Mode_IncEnc_Any_T3EUD_En()             (GPT12E->T4CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T4_Mode_IncEnc_Any_T3EUD_Dis()            (GPT12E->T4CON.reg &= (uint16)~(1u << 1u))

/* T4 Run Control */
#define GPT12E_T4_Start()                                (GPT12E->T4CON.reg |= (uint16) (1u << 6u))
#define GPT12E_T4_Stop()                                 (GPT12E->T4CON.reg &= (uint16)~(1u << 6u))
#define GPT12E_T4_Start_by_T3_Dis()                      (GPT12E->T4CON.reg |= (uint16) (1u << 9u))
#define GPT12E_T4_Start_by_T3_En()                       (GPT12E->T4CON.reg &= (uint16)~(1u << 9u))

/* T4 Up/Down Control */
#define GPT12E_T4_DownCount_Sel()                        (GPT12E->T4CON.reg |= (uint16) (1u << 7u))
#define GPT12E_T4_UpCount_Sel()                          (GPT12E->T4CON.reg &= (uint16)~(1u << 7u))
#define GPT12E_T4_UpDownCount_Ext_En()                   (GPT12E->T4CON.reg |= (uint16) (1u << 8u))
#define GPT12E_T4_UpDownCount_Ext_Dis()                  (GPT12E->T4CON.reg &= (uint16)~(1u << 8u))
#define GPT12E_T4_Mode_IncEnc_DownCount_RotDir_Sel()     (GPT12E->T4CON.reg |= (uint16) (1u << 15u))
#define GPT12E_T4_Mode_IncEnc_UpCount_RotDir_Sel()       (GPT12E->T4CON.reg &= (uint16)~(1u << 15u))

/* T4 - Clear T2/T3 */
#define GPT12E_T4_Clr_T2_En()                            (GPT12E->T4CON.reg |= (uint16) (1u << 10u))
#define GPT12E_T4_Clr_T2_Dis()                           (GPT12E->T4CON.reg &= (uint16)~(1u << 10u))
#define GPT12E_T4_Clr_T3_En()                            (GPT12E->T4CON.reg |= (uint16) (1u << 11u))
#define GPT12E_T4_Clr_T3_Dis()                           (GPT12E->T4CON.reg &= (uint16)~(1u << 11u))

/* T4 Edge Detection Status/Clear (Inc. Encoder Mode) */
#define GPT12E_T4_Mode_IncEnc_Edge_Detect_Sts()         ((GPT12E->T4CON.reg >> 13u) & 1u)
#define GPT12E_T4_Mode_IncEnc_Edge_Detect_Clr()          (GPT12E->T4CON.reg &= (uint16)~(1u << 13u))

/* T4 Direction Change Status/Clear (Inc. Encoder Mode) */
#define GPT12E_T4_Mode_IncEnc_Dir_Change_Sts()          ((GPT12E->T4CON.reg >> 14u) & 1u)
#define GPT12E_T4_Mode_IncEnc_Dir_Change_Clr()           (GPT12E->T4CON.reg &= (uint16)~(1u << 14u))

/* T4 Timer Value */
#define GPT12E_T4_Value_Get()                            ((uint16)GPT12E->T4.reg)
#define GPT12E_T4_Value_Set(t4)                          (GPT12E->T4.reg = (uint16)t4)

/* T4 Pin Selection */
#define GPT12E_T4_T4In_Sel(ist4in)                       (GPT12E->PISEL.bit.IST4IN  = (uint16)(ist4in & 3u))
#define GPT12E_T4_T4EUD_Sel(ist4eud)                     (GPT12E->PISEL.bit.IST4EUD = (uint16)(ist4eud & 3u))

/****************************************************************************/
/* GPT2   *******************************************************************/
/****************************************************************************/
typedef enum
{
  GPT2_fSYS_Div_2  = 0u,
  GPT2_fSYS_Div_4  = 1u,
  GPT2_fSYS_Div_8  = 2u,
  GPT2_fSYS_Div_16 = 3u
} TGPT2_Clk_Prescaler;

/* GPT2 Clock */
#define GPT12E_GPT2_Clk_Prescaler_Sel(bps2)              (GPT12E->T6CON.bit.BPS2 = (uint16)((bps2 & 3u) ^ 1u))
#define GPT12E_GPT2_Clk_Prescaler_Get()                (((GPT12E->T6CON.reg >> 11u) & 3u) ^ 1u)

/****************************************************************************/
/* Timer5 *******************************************************************/
/****************************************************************************/
typedef enum
{
  GPT12E_T5INA_P03 = 0u,
  GPT12E_T5INB_P20 = 1u
} TGPT12E_T5IN;

typedef enum
{
  GPT12E_T5EUDA_P14 = 0u,
  GPT12E_T5EUDB_P20 = 1u
} TGPT12E_T5EUD;

/* T5 Mode */
#define GPT12E_T5_Mode_Timer_Sel()                       (GPT12E->T5CON.bit.T5M = 0u)
#define GPT12E_T5_Mode_Counter_Sel()                     (GPT12E->T5CON.bit.T5M = 1u)
#define GPT12E_T5_Mode_Gated_Timer_Low_Sel()             (GPT12E->T5CON.bit.T5M = 2u)
#define GPT12E_T5_Mode_Gated_Timer_High_Sel()            (GPT12E->T5CON.bit.T5M = 3u)

/* T5 Input Parameter Selection */
#define GPT12E_T5_Mode_Timer_Clk_Prescaler_Sel(t5i)      (GPT12E->T5CON.bit.T5I = (uint16)(t5i & 7u))
#define GPT12E_T5_Mode_Gated_Timer_Clk_Prescaler_Sel(t5i) \
                                                         (GPT12E->T5CON.bit.T5I = (uint16)(t5i & 7u))
#define GPT12E_T5_Mode_Counter_Input_T5In_Sel()          (GPT12E->T5CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T5_Mode_Counter_Input_Rising_T5In_Sel()   (GPT12E->T5CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T5_Mode_Counter_Input_Falling_T5In_Sel()  (GPT12E->T5CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T5_Mode_Counter_Input_Any_T5In_Sel()      (GPT12E->T5CON.reg |= (uint16) (3u << 0u))
#define GPT12E_T5_Mode_Counter_Input_T6Out_Sel()         (GPT12E->T5CON.reg |= (uint16) (1u << 2u))
#define GPT12E_T5_Mode_Counter_Input_Rising_T6Out_En()   (GPT12E->T5CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T5_Mode_Counter_Input_Rising_T6Out_Dis()  (GPT12E->T5CON.reg &= (uint16)~(1u << 0u))
#define GPT12E_T5_Mode_Counter_Input_Falling_T6Out_En()  (GPT12E->T5CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T5_Mode_Counter_Input_Falling_T6Out_Dis() (GPT12E->T5CON.reg &= (uint16)~(1u << 1u))

/* T5 Capture */
#define GPT12E_T5_Capture_En()                           (GPT12E->T5CON.reg |= (uint16) (1u << 15u))
#define GPT12E_T5_Capture_Dis()                          (GPT12E->T5CON.reg &= (uint16)~(1u << 15u))
#define GPT12E_T5_Capture_Trig_CapIn_Sel()               (GPT12E->T5CON.reg |= (uint16) (1u << 10u))
#define GPT12E_T5_Capture_Trig_Rising_CapIn_En()         (GPT12E->T5CON.reg |= (uint16) (1u << 12u))
#define GPT12E_T5_Capture_Trig_Rising_CapIn_Dis()        (GPT12E->T5CON.reg &= (uint16)~(1u << 12u))
#define GPT12E_T5_Capture_Trig_Falling_CapIn_En()        (GPT12E->T5CON.reg |= (uint16) (1u << 13u))
#define GPT12E_T5_Capture_Trig_Falling_CapIn_Dis()       (GPT12E->T5CON.reg &= (uint16)~(1u << 13u))
#define GPT12E_T5_Capture_Trig_T3In_T3EUD_Sel()          (GPT12E->T5CON.reg &= (uint16)~(1u << 10u))
#define GPT12E_T5_Capture_Trig_Any_T3In_En()             (GPT12E->T5CON.reg |= (uint16) (1u << 12u))
#define GPT12E_T5_Capture_Trig_Any_T3In_Dis()            (GPT12E->T5CON.reg &= (uint16)~(1u << 12u))
#define GPT12E_T5_Capture_Trig_Any_T3EUD_En()            (GPT12E->T5CON.reg |= (uint16) (1u << 13u))
#define GPT12E_T5_Capture_Trig_Any_T3EUD_Dis()           (GPT12E->T5CON.reg &= (uint16)~(1u << 13u))
#define GPT12E_T5_Cleared_On_Capture_En()                (GPT12E->T5CON.reg |= (uint16) (1u << 14u))
#define GPT12E_T5_Cleared_On_Capture_Dis()               (GPT12E->T5CON.reg &= (uint16)~(1u << 14u))
#define GPT12E_T5_Capture_Value_Get()                    ((uint16)GPT12E->CAPREL.reg)

/* T5 Run Control */
#define GPT12E_T5_Start()                                (GPT12E->T5CON.reg |= (uint16) (1u << 6u))
#define GPT12E_T5_Stop()                                 (GPT12E->T5CON.reg &= (uint16)~(1u << 6u))
#define GPT12E_T5_Start_by_T6_Dis()                      (GPT12E->T5CON.reg |= (uint16) (1u << 9u))
#define GPT12E_T5_Start_by_T6_En()                       (GPT12E->T5CON.reg &= (uint16)~(1u << 9u))

/* T5 Up/Down Control */
#define GPT12E_T5_DownCount_Sel()                        (GPT12E->T5CON.reg |= (uint16) (1u << 7u))
#define GPT12E_T5_UpCount_Sel()                          (GPT12E->T5CON.reg &= (uint16)~(1u << 7u))
#define GPT12E_T5_UpDownCount_Ext_En()                   (GPT12E->T5CON.reg |= (uint16) (1u << 8u))
#define GPT12E_T5_UpDownCount_Ext_Dis()                  (GPT12E->T5CON.reg &= (uint16)~(1u << 8u))

/* T5 Timer Value */
#define GPT12E_T5_Value_Get()                            ((uint16)GPT12E->T5.reg)
#define GPT12E_T5_Value_Set(t5)                          (GPT12E->T5.reg = (uint16)t5)

/* T5 Pin Selection */
#define GPT12E_T5_T5In_Sel(ist5in)                       (GPT12E->PISEL.bit.IST5IN  = (uint16)(ist5in & 1u))
#define GPT12E_T5_T5EUD_Sel(ist5eud)                     (GPT12E->PISEL.bit.IST5EUD = (uint16)(ist5eud & 1u))

/****************************************************************************/
/* Timer6 *******************************************************************/
/****************************************************************************/
typedef enum
{
  GPT12E_T6INA_P02 = 0u,
  GPT12E_T6INB_P13 = 1u
} TGPT12E_T6IN;

typedef enum
{
  GPT12E_T6EUDA_P11 = 0u,
  GPT12E_T6EUDB_P13 = 1u
} TGPT12E_T6EUD;

/* T6 Mode */
#define GPT12E_T6_Mode_Timer_Sel()                       (GPT12E->T6CON.bit.T6M = 0u)
#define GPT12E_T6_Mode_Counter_Sel()                     (GPT12E->T6CON.bit.T6M = 1u)
#define GPT12E_T6_Mode_Gated_Timer_Low_Sel()             (GPT12E->T6CON.bit.T6M = 2u)
#define GPT12E_T6_Mode_Gated_Timer_High_Sel()            (GPT12E->T6CON.bit.T6M = 3u)

/* T6 Input Parameter Selection */
#define GPT12E_T6_Mode_Timer_Clk_Prescaler_Sel(t6i)      (GPT12E->T6CON.bit.T6I = (uint16)(t6i & 7u))
#define GPT12E_T6_Mode_Gated_Timer_Clk_Prescaler_Sel(t6i) \
                                                         (GPT12E->T6CON.bit.T6I = (uint16)(t6i & 7u))
#define GPT12E_T6_Mode_Counter_Input_T6IN_Sel()          (GPT12E->T6CON.reg &= (uint16)~(1u << 2u))
#define GPT12E_T6_Mode_Counter_Input_Rising_T6IN_Sel()   (GPT12E->T6CON.reg |= (uint16) (1u << 0u))
#define GPT12E_T6_Mode_Counter_Input_Falling_T6IN_Sel()  (GPT12E->T6CON.reg |= (uint16) (1u << 1u))
#define GPT12E_T6_Mode_Counter_Input_Any_T6IN_Sel()      (GPT12E->T6CON.reg |= (uint16) (3u << 0u))

/* T6 Reload */
#define GPT12E_T6_Reload_En()                            (GPT12E->T6CON.reg |= (uint16) (1u << 15u))
#define GPT12E_T6_Reload_Dis()                           (GPT12E->T6CON.reg &= (uint16)~(1u << 15u))
#define GPT12E_T6_Reload_Value_Set(rl)                   (GPT12E->CAPREL.reg = (uint16)rl)

/* T6 Capture */
#define GPT12E_T6_On_Capture_Cleared_En()                (GPT12E->T6CON.reg |= (uint16) (1u << 14u))
#define GPT12E_T6_On_Capture_Cleared_Dis()               (GPT12E->T6CON.reg &= (uint16)~(1u << 14u))

/* T6 Run Control */
#define GPT12E_T6_Start()                                (GPT12E->T6CON.reg |= (uint16) (1u << 6u))
#define GPT12E_T6_Stop()                                 (GPT12E->T6CON.reg &= (uint16)~(1u << 6u))

/* T6 Output Toggle Latch */
#define GPT12E_T6_Output_En()                            (GPT12E->T6CON.reg |= (uint16) (1u << 9u))
#define GPT12E_T6_Output_Dis()                           (GPT12E->T6CON.reg &= (uint16)~(1u << 9u))
#define GPT12E_T6_Output_Set()                           (GPT12E->T6CON.reg |= (uint16) (1u << 10u))
#define GPT12E_T6_Output_Rst()                           (GPT12E->T6CON.reg &= (uint16)~(1u << 10u))

/* T6 Up/Down Control */
#define GPT12E_T6_DownCount_Sel()                        (GPT12E->T6CON.reg |= (uint16) (1u << 7u))
#define GPT12E_T6_UpCount_Sel()                          (GPT12E->T6CON.reg &= (uint16)~(1u << 7u))
#define GPT12E_T6_UpDownCount_Ext_En()                   (GPT12E->T6CON.reg |= (uint16) (1u << 8u))
#define GPT12E_T6_UpDownCount_Ext_Dis()                  (GPT12E->T6CON.reg &= (uint16)~(1u << 8u))

/* T6 Timer Value */
#define GPT12E_T6_Value_Get()                            ((uint16)GPT12E->T6.reg)
#define GPT12E_T6_Value_Set(t6)                          (GPT12E->T6.reg = (uint16)t6)

/* T6 Pin Selection */
#define GPT12E_T6_T6In_Sel(ist6in)                       (GPT12E->PISEL.bit.IST6IN = (uint16)(ist6in & 1u))
#define GPT12E_T6_T6EUD_Sel(ist6eud)                     (GPT12E->PISEL.bit.IST6EUD = (uint16)(ist6eud & 1u))

/****************************************************************************/
/* CAPREL *******************************************************************/
/****************************************************************************/
typedef enum
{
  GPT12E_CAPINA_P01           = 0u,
  GPT12E_CAPINB_P03           = 1u,
  GPT12E_CAPINC_T3_READ       = 2u,
  GPT12E_CAPIND_T2_T3_T4_READ = 3u
} TGPT12E_CAPIN;

/* CapRel Pin Selection */
#define GPT12E_CapRel_CAPIn_Sel(iscapin)                 (GPT12E->PISEL.bit.ISCAPIN = (uint16)(iscapin & 3u))

/****************************************************************************/
/* Interrupt ****************************************************************/
/****************************************************************************/
/* GPT12E Interrupt Status */
#define GPT12E_T2_Int_Sts()                              ((SCU->GPT12IRC.reg >> 0u) & 1u)
#define GPT12E_T3_Int_Sts()                              ((SCU->GPT12IRC.reg >> 1u) & 1u)
#define GPT12E_T4_Int_Sts()                              ((SCU->GPT12IRC.reg >> 2u) & 1u)
#define GPT12E_T5_Int_Sts()                              ((SCU->GPT12IRC.reg >> 3u) & 1u)
#define GPT12E_T6_Int_Sts()                              ((SCU->GPT12IRC.reg >> 4u) & 1u)
#define GPT12E_CapRel_Int_Sts()                          ((SCU->GPT12IRC.reg >> 5u) & 1u)

/* GPT12E Interrupt Clear Macros */
#define GPT12E_T2_Int_Clr()                              (SCU->GPT12ICLR.reg = (uint8) (1u << 0u))
#define GPT12E_T3_Int_Clr()                              (SCU->GPT12ICLR.reg = (uint8) (1u << 1u))
#define GPT12E_T4_Int_Clr()                              (SCU->GPT12ICLR.reg = (uint8) (1u << 2u))
#define GPT12E_T5_Int_Clr()                              (SCU->GPT12ICLR.reg = (uint8) (1u << 3u))
#define GPT12E_T6_Int_Clr()                              (SCU->GPT12ICLR.reg = (uint8) (1u << 4u))
#define GPT12E_CapRel_Int_Clr()                          (SCU->GPT12ICLR.reg = (uint8) (1u << 5u))

/* GPT12E Interrupt Enable/Disable Macros */
#define GPT12E_T2_Int_En()                               (SCU->GPT12IEN.bit.T2IE = 1u)
#define GPT12E_T2_Int_Dis()                              (SCU->GPT12IEN.bit.T2IE = 0u)
#define GPT12E_T3_Int_En()                               (SCU->GPT12IEN.bit.T3IE = 1u)
#define GPT12E_T3_Int_Dis()                              (SCU->GPT12IEN.bit.T3IE = 0u)
#define GPT12E_T4_Int_En()                               (SCU->GPT12IEN.bit.T4IE = 1u)
#define GPT12E_T4_Int_Dis()                              (SCU->GPT12IEN.bit.T4IE = 0u)
#define GPT12E_T5_Int_En()                               (SCU->GPT12IEN.bit.T5IE = 1u)
#define GPT12E_T5_Int_Dis()                              (SCU->GPT12IEN.bit.T5IE = 0u)
#define GPT12E_T6_Int_En()                               (SCU->GPT12IEN.bit.T6IE = 1u)
#define GPT12E_T6_Int_Dis()                              (SCU->GPT12IEN.bit.T6IE = 0u)
#define GPT12E_CapRel_Int_En()                           (SCU->GPT12IEN.bit.CRIE = 1u)
#define GPT12E_CapRel_Int_Dis()                          (SCU->GPT12IEN.bit.CRIE = 0u)
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void GPT12E_Init(void);
bool GPT12E_T3_Interval_Timer_Setup(uint32 timer_interval_us);
bool GPT12E_T6_Interval_Timer_Setup(uint32 timer_interval_us);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
#endif
