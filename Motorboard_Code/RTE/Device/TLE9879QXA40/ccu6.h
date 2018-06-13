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


/******************************************************************************
**                      Revision Control History                             **
******************************************************************************/
/* See ccu6.c */

#ifndef _CCU6_H
#define _CCU6_H

/******************************************************************************
**                      Includes                                             **
******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "ccu6_defines.h"

/******************************************************************************
**                      Global Macro Definitions                             **
******************************************************************************/
/* Constants for TCTR4 register */
#define CCU6_MASK_TCTR4_STOP_T12       (0x0001u)
#define CCU6_MASK_TCTR4_START_T12      (0x0002u)
#define CCU6_MASK_TCTR4_RESET_T12      (0x0004u)
#define CCU6_MASK_TCTR4_SHADOW_T12     (0x0040u)
#define CCU6_MASK_TCTR4_STOP_T13       (0x0100u)
#define CCU6_MASK_TCTR4_START_T13      (0x0200u)
#define CCU6_MASK_TCTR4_RESET_T13      (0x0400u)
#define CCU6_MASK_TCTR4_SHADOW_T13     (0x4000u)

/* Constants for MCMOUTS register */
#define CCU6_MASK_MCMOUTS_SHADOW_HALL  (0x8000u)
#define CCU6_MASK_MCMOUTS_SHADOW_OUT   (0x0080u)

/* Global Register Access Macros */

/* CCU6_TCTR4 Macros*/
#define CCU6_T12_Stop()            (CCU6->TCTR4.reg = (uint16) (1u << 0u))
#define CCU6_T12_Start()           (CCU6->TCTR4.reg = (uint16) (1u << 1u))
#define CCU6_T12_Rst()             (CCU6->TCTR4.reg = (uint16) (1u << 2u))
#define CCU6_Deadtime_Rst()        (CCU6->TCTR4.reg = (uint16) (1u << 3u))
#define CCU6_T12_Cnt()             (CCU6->TCTR4.reg = (uint16) (1u << 5u))
#define CCU6_T12_Str_En()          (CCU6->TCTR4.reg = (uint16) (1u << 6u))
#define CCU6_T12_Str_Dis()         (CCU6->TCTR4.reg = (uint16) (1u << 7u))
#define CCU6_T13_Stop()            (CCU6->TCTR4.reg = (uint16) (1u << 8u))
#define CCU6_T13_Start()           (CCU6->TCTR4.reg = (uint16) (1u << 9u))
#define CCU6_T13_Rst()             (CCU6->TCTR4.reg = (uint16) (1u << 10u))
#define CCU6_T13_Cnt()             (CCU6->TCTR4.reg = (uint16) (1u << 13u))
#define CCU6_T13_Str_En()          (CCU6->TCTR4.reg = (uint16) (1u << 14u))
#define CCU6_T13_Str_Dis()         (CCU6->TCTR4.reg = (uint16) (1u << 15u))

/* CCU6 Port Input Select Register 0 (CCU6->PISEL0) */
#define CCU6_Ch0_Input_Sel(iscc60)      (CCU6->PISEL0.bit.ISCC60  = (iscc60 & 3u))
#define CCU6_Ch1_Input_Sel(iscc61)      (CCU6->PISEL0.bit.ISCC61  = (iscc61 & 3u))
#define CCU6_Ch2_Input_Sel(iscc62)      (CCU6->PISEL0.bit.ISCC62  = (iscc62 & 3u))
#define CCU6_Trap_Input_Sel(istrp)      (CCU6->PISEL0.bit.ISTRP   = (istrp  & 3u))
#define CCU6_CCPOS0_Input_Sel(ispos0)   (CCU6->PISEL0.bit.ISPOS0  = (ispos0 & 3u))
#define CCU6_CCPOS1_Input_Sel(ispos1)   (CCU6->PISEL0.bit.ISPOS1  = (ispos1 & 3u))
#define CCU6_CCPOS2_Input_Sel(ispos2)   (CCU6->PISEL0.bit.ISPOS2  = (ispos2 & 3u))
#define CCU6_T12HR_Input_Sel(ist12hr)   (CCU6->PISEL0.bit.IST12HR = (ist12hr & 3u))
/* CCU6 Port Input Select Register 2 (CCU6->PISEL2) */
#define CCU6_T13HR_Input_Sel(ist13hr)   (CCU6->PISEL2.bit.IST13HR = (ist13hr & 3u))
#define CCU6_T12_Cnt_Input_Sel(iscnt12) (CCU6->PISEL2.bit.ISCNT12 = (iscnt12 & 3u))
#define CCU6_T13_Cnt_Input_Sel(iscnt13) (CCU6->PISEL2.bit.ISCNT13 = (iscnt13 & 3u))
#define CCU6_T12_Ext_Input_Sel(t12ext)  (CCU6->PISEL2.bit.T12EXT  = (t12ext & 3u))
#define CCU6_T13_Ext_Input_Sel(t13ext)  (CCU6->PISEL2.bit.T13EXT  = (t13ext & 3u))

/* CCU6 T12 Capture/Compare Mode Select Register */
#define CCU6_Hall_Delay_Bypass_En()         (CCU6->T12MSEL.reg |= (uint16)  (1u << 15u))
#define CCU6_Hall_Delay_Bypass_Dis()        (CCU6->T12MSEL.reg &= (uint16) ~(1u << 15u))
#define CCU6_Hall_Synchronizaion_Sel(hsync) (CCU6->T12MSEL.bit.HSYNC = (hsync & 7u))
#define CCU6_Ch2_CapCom_Mode_Sel(msel62)    (CCU6->T12MSEL.bit.MSEL62 = (msel62 & 0xFu))
#define CCU6_Ch1_CapCom_Mode_Sel(msel61)    (CCU6->T12MSEL.bit.MSEL61 = (msel61 & 0xFu))
#define CCU6_Ch0_CapCom_Mode_Sel(msel60)    (CCU6->T12MSEL.bit.MSEL60 = (msel60 & 0xFu))

/* CCU6 T12: Timer T12 Counter Register (CCU6->T12) */
#define CCU6_T12_Count_Value_Get()       (CCU6->T12.reg & 0xFFFFu)
#define CCU6_T12_Count_Value_Set(t12cv)  (CCU6->T12.reg = (uint16)(t12cv & 0xFFFFu))
/* CCU6 T12: Timer T12 Period Register (CCU6->T12PR) */
#define CCU6_T12_Period_Value_Get()      (CCU6->T12PR.reg & 0xFFFFu)
#define CCU6_T12_Period_Value_Set(t12pr) (CCU6->T12PR.reg = (uint16)(t12pr & 0xFFFFu))
/* CCU6 T12: Capture/Compare and Shadow Register for Channel CC60 */
#define CCU6_Ch0_Value_Get()        (CCU6->CC60R.reg & 0xFFFFu)
#define CCU6_Ch0_Value_Set(cc60sr)  (CCU6->CC60SR.reg = (uint16)(cc60sr & 0xFFFFu))
/* CCU6 T12: Capture/Compare and Shadow Register for Channel CC61 */
#define CCU6_Ch1_Value_Get()        (CCU6->CC61R.reg & 0xFFFFu)
#define CCU6_Ch1_Value_Set(cc61sr)  (CCU6->CC61SR.reg = (uint16)(cc61sr & 0xFFFFu))
/* CCU6 T12: Capture/Compare and Shadow Register for Channel CC62 */
#define CCU6_Ch2_Value_Get()        (CCU6->CC62R.reg & 0xFFFFu)
#define CCU6_Ch2_Value_Set(cc62sr)  (CCU6->CC62SR.reg = (uint16)(cc62sr & 0xFFFFu))

/* CCU6 Timer T12 Deadtime Control Register T12DTC */
#define CCU6_Deadtime_Get()         (CCU6->T12DTC.bit.DTM & 0xFFu)
#define CCU6_Deadtime_Set(dtm)      (CCU6->T12DTC.bit.DTM = dtm & 0xFFu)
#define CCU6_Ch0_Deadtime_En()      (CCU6->T12DTC.reg |= (uint16)  (1u << 8u))
#define CCU6_Ch1_Deadtime_En()      (CCU6->T12DTC.reg |= (uint16)  (1u << 9u))
#define CCU6_Ch2_Deadtime_En()      (CCU6->T12DTC.reg |= (uint16)  (1u << 10u))
#define CCU6_Ch0_Deadtime_Dis()     (CCU6->T12DTC.reg &= (uint16) ~(1u << 8u))
#define CCU6_Ch1_Deadtime_Dis()     (CCU6->T12DTC.reg &= (uint16) ~(1u << 9u))
#define CCU6_Ch2_Deadtime_Dis()     (CCU6->T12DTC.reg &= (uint16) ~(1u << 10u))
#define CCU6_Ch0_Deadtime_Sts()    ((CCU6->T12DTC.reg >> 12) & 1u)
#define CCU6_Ch1_Deadtime_Sts()    ((CCU6->T12DTC.reg >> 13) & 1u)
#define CCU6_Ch2_Deadtime_Sts()    ((CCU6->T12DTC.reg >> 14) & 1u)

/* CCU6 T13: Timer T13 Counter Register (CCU6->T13) */
#define CCU6_T13_Cnt_Val_Get()      (CCU6->T13.reg & 0xFFFFu)
#define CCU6_T13_Cnt_Val_Set(t13cv) (CCU6->T13.reg = (uint16)(t13cv & 0xFFFFu))
/* CCU6 T13: Timer T13 Period Register (CCU6->T13PR) */
#define CCU6_T13_Per_Val_Get()      (CCU6->T13PR.reg & 0xFFFFu)
#define CCU6_T13_Per_Val_Set(t13pr) (CCU6->T13PR.reg = (uint16)(t13pr & 0xFFFFu))
/* CCU6 T13: Capture/Compare and Shadow Register for Channel CC63 */
#define CCU6_Ch3_Value_Get()        (CCU6->CC63R.reg & 0xFFFFu)
#define CCU6_Ch3_Value_Set(cc63sr)  (CCU6->CC63SR.reg = (uint16)(cc63sr & 0xFFFFu))

/* CCU6 Compare State Register */
#define CCU6_Ch0_CompState_Sts()   ((CCU6->CMPSTAT.reg >> 0u) & 1u)
#define CCU6_Ch1_CompState_Sts()   ((CCU6->CMPSTAT.reg >> 1u) & 1u)
#define CCU6_Ch2_CompState_Sts()   ((CCU6->CMPSTAT.reg >> 2u) & 1u)
#define CCU6_Ch3_CompState_Sts()   ((CCU6->CMPSTAT.reg >> 6u) & 1u)
#define CCU6_Hall_Ch0_Sts()        ((CCU6->CMPSTAT.reg >> 3u) & 1u)
#define CCU6_Hall_Ch1_Sts()        ((CCU6->CMPSTAT.reg >> 4u) & 1u)
#define CCU6_Hall_Ch2_Sts()        ((CCU6->CMPSTAT.reg >> 5u) & 1u)
#define CCU6_Ch0t_Passive_State_After_Compare_Sel() \
                                {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 8u)) ;\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch1t_Passive_State_After_Compare_Sel() \
                                {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 10u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch2t_Passive_State_After_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 12u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch0c_Passive_State_After_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 9u)) ;\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch1c_Passive_State_After_Compare_Sel() \
                                {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 11u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch2c_Passive_State_After_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 13u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch3c_Passive_State_After_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 14u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch0t_Passive_State_Before_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 8u)) ;\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch1t_Passive_State_Before_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 10u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch2t_Passive_State_Before_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 12u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch0c_Passive_State_Before_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 9u)) ;\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch1c_Passive_State_Before_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 11u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch2c_Passive_State_Before_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 13u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_Ch3c_Passive_State_Before_Compare_Sel()\
                                {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 14u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_T13_Inv_Mod_En()   {(CCU6->CMPSTAT.reg |= (uint16)  (1u << 15u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}
#define CCU6_T13_Inv_Mod_Dis()  {(CCU6->CMPSTAT.reg &= (uint16) ~(1u << 15u));\
	                             (CCU6->TCTR4.reg = (uint16) (1u << 6u));}

/* CCU6 Compare State Modification Register */
#define CCU6_Ch0_CompState_Set()  (CCU6->CMPMODIF.reg = (uint16) (1u << 0u))
#define CCU6_Ch1_CompState_Set()  (CCU6->CMPMODIF.reg = (uint16) (1u << 1u))
#define CCU6_Ch2_CompState_Set()  (CCU6->CMPMODIF.reg = (uint16) (1u << 2u))
#define CCU6_Ch3_CompState_Set()  (CCU6->CMPMODIF.reg = (uint16) (1u << 6u))
#define CCU6_Ch0_CompState_Rst()  (CCU6->CMPMODIF.reg = (uint16) (1u << 8u))
#define CCU6_Ch1_CompState_Rst()  (CCU6->CMPMODIF.reg = (uint16) (1u << 9u))
#define CCU6_Ch2_CompState_Rst()  (CCU6->CMPMODIF.reg = (uint16) (1u << 10u))
#define CCU6_Ch3_CompState_Rst()  (CCU6->CMPMODIF.reg = (uint16) (1u << 14u))

/* CCU6 Timer Control Register 0 */
#define CCU6_T12_Edge_Aligned_Mode_En()   (CCU6->TCTR0.reg |= (uint16) (1u << 7u))
#define CCU6_T12_Center_Aligned_Mode_En() (CCU6->TCTR0.reg &= (uint16)~(1u << 7u))
#define CCU6_T12_Clk_Sel(t12clk)          (CCU6->TCTR0.bit.T12CLK = (uint16) (t12clk & 7u))
#define CCU6_T13_Clk_Sel(t13clk)          (CCU6->TCTR0.bit.T13CLK = (uint16) (t13clk & 7u))
#define CCU6_T12_Prescaler_En()           (CCU6->TCTR0.reg |= (uint16)  (1u << 3u))
#define CCU6_T12_Prescaler_Dis()          (CCU6->TCTR0.reg &= (uint16) ~(1u << 3u))
#define CCU6_T13_Prescaler_En()           (CCU6->TCTR0.reg |= (uint16)  (1u << 11u))
#define CCU6_T13_Prescaler_Dis()          (CCU6->TCTR0.reg &= (uint16) ~(1u << 11u))
#define CCU6_T12_Run_Sts()               ((CCU6->TCTR0.reg >> 4u)  & 1u) 
#define CCU6_T12_Str_Sts()               ((CCU6->TCTR0.reg >> 5u)  & 1u)
#define CCU6_T12_Count_Dir_Sts()         ((CCU6->TCTR0.reg >> 6u)  & 1u) 
#define CCU6_T13_Run_Sts()               ((CCU6->TCTR0.reg >> 12u) & 1u) 
#define CCU6_T13_Str_Sts()               ((CCU6->TCTR0.reg >> 13u) & 1u)


/* CCU6 Timer Control Register 2 */
#define CCU6_T12_Single_Shot_En()   (CCU6->TCTR2.reg |= (uint16)  (1u << 0u))
#define CCU6_T12_Single_Shot_Dis()  (CCU6->TCTR2.reg &= (uint16) ~(1u << 0u))
#define CCU6_T13_Trig_Event_Sel(t13tec) \
                                    (CCU6->TCTR2.bit.T13TEC = (t13tec & 7u))
#define CCU6_T13_Trig_Event_Dir_Sel(t13ted) \
                                    (CCU6->TCTR2.bit.T13TED = (t13ted & 3u))
#define CCU6_T12_Ext_Run_Sel(t12rsel) \
                                    (CCU6->TCTR2.bit.T12RSEL = (t12rsel & 3u))
#define CCU6_T13_Ext_Run_Sel(t13rsel) \
                                    (CCU6->TCTR2.bit.T13RSEL = (t13rsel & 3u))
							 
/* CCU6 Modulation Control */
#define CCU6_MASK_CC60   (uint16)(1u << 0u)
#define CCU6_MASK_COUT60 (uint16)(1u << 1u)
#define CCU6_MASK_CC61   (uint16)(1u << 2u)
#define CCU6_MASK_COUT61 (uint16)(1u << 3u)
#define CCU6_MASK_CC62   (uint16)(1u << 4u)
#define CCU6_MASK_COUT62 (uint16)(1u << 5u)

#define CCU6_MASK_Ch0t   CCU6_MASK_CC60   
#define CCU6_MASK_Ch0c   CCU6_MASK_COUT60 
#define CCU6_MASK_Ch1t   CCU6_MASK_CC61   
#define CCU6_MASK_Ch1c   CCU6_MASK_COUT61 
#define CCU6_MASK_Ch2t   CCU6_MASK_CC62   
#define CCU6_MASK_Ch2c   CCU6_MASK_COUT62 

#define CCU6_T12_Modulation_En(ccu6_mask) \
                           (CCU6->MODCTR.bit.T12MODEN = (ccu6_mask & 0x1Fu))

#define CCU6_T13_Modulation_En(ccu6_mask) \
                           (CCU6->MODCTR.bit.T13MODEN = (ccu6_mask & 0x1Fu))
						   			   
#define CCU6_Multi_Ch_Mode_En()     (CCU6->MODCTR.reg |= (uint16)  (1u << 7u))
#define CCU6_Multi_Ch_Mode_Dis()    (CCU6->MODCTR.reg &= (uint16) ~(1u << 7u))
#define CCU6_T13_Compare_Out_En()   (CCU6->MODCTR.reg |= (uint16)  (1u << 15u))
#define CCU6_T13_Compare_Out_Dis()  (CCU6->MODCTR.reg &= (uint16) ~(1u << 15u))
                                   
/* CCU6 Trap Control Register */   
#define CCU6_Trap_T12_ZM_Exit_En()  (CCU6->TRPCTR.reg &= (uint16) ~(3u << 0u))
#define CCU6_Trap_T13_ZM_Exit_En() {(CCU6->TRPCTR.reg &= (uint16) ~(3u << 0u));\
                                    (CCU6->TRPCTR.reg |= (uint16)  (1u << 0u));}
#define CCU6_Trap_Asynch_Exit_En()  (CCU6->TRPCTR.reg |= (uint16)  (3u << 0u))
#define CCU6_Trap_HW_Clr_En()       (CCU6->TRPCTR.reg &= (uint16) ~(1u << 2u))
#define CCU6_Trap_SW_Clr_En()       (CCU6->TRPCTR.reg |= (uint16)  (1u << 2u))
#define CCU6_Trap_T13_En()          (CCU6->TRPCTR.reg |= (uint16)  (1u << 14u))
#define CCU6_Trap_T13_Dis()         (CCU6->TRPCTR.reg &= (uint16) ~(1u << 14u))
#define CCU6_Trap_Pin_En()          (CCU6->TRPCTR.reg |= (uint16)  (1u << 15u))
#define CCU6_Trap_Pin_Dis()         (CCU6->TRPCTR.reg &= (uint16) ~(1u << 15u))
#define CCU6_Trap_Channel_En(ccu6_mask) \
                           (CCU6->TRPCTR.bit.TRPEN = (ccu6_mask & 0x1Fu))

/* CCU6 Passive State Level Register */
#define CCU6_Passive_Level_High_Sel(ccu6_mask) \
                           (CCU6->PSLR.bit.PSL = (ccu6_mask & 0x1Fu))
#define CCU6_Passiv_Level_Ch3_Sel(lvl) \
                           (CCU6->PSLR.bit.PSL63 = (lvl & 0x1u))

/* Multi-Channel Mode Output Shadow Register */
#define CCU6_Multi_Ch_PWM_Shadow_Reg_Load(ccu6_mask) \
                           (CCU6->MCMOUTS.bit.MCMPS = (ccu6_mask & 0x1Fu))
#define CCU6_MCM_PWM_Str_SW_En()    (CCU6->MCMOUTS.reg |= (uint16)  (1u << 7u))
#define CCU6_MCM_PWM_Str_HW_En()    (CCU6->MCMOUTS.reg &= (uint16) ~(1u << 7u))

#define MCM_MASK_CCPOS0 (0u)
#define MCM_MASK_CCPOS1 (2u)
#define MCM_MASK_CCPOS2 (4u)

#define CCU6_MCM_Expected_Hall_Shadow_Reg_Load(mcm_mask_ccpos) \
                             (CCU6->MCMOUTS.bit.EXPHS = (mcm_mask_ccpos & 7u))
#define CCU6_MCM_Current_Hall_Shadow_Reg_Load(mcm_mask_ccpos) \
                             (CCU6->MCMOUTS.bit.EXPHS = (mcm_mask_ccpos & 7u))
#define CCU6_MCM_Hall_Str_SW_En()   (CCU6->MCMOUTS.reg |= (uint16)  (1u << 15u))
#define CCU6_MCM_Hall_Str_HW_En()   (CCU6->MCMOUTS.reg &= (uint16) ~(1u << 15u))

/* Multi-Channel Mode Output Register */
#define CCU6_MCM_PWM_Pattern_Sts()       ((CCU6->MCMOUT.reg >> 0u) & 0x1Fu)
#define CCU6_MCM_PWM_Str_Req_Sts()       ((CCU6->MCMOUT.reg >> 6u) & 0x1Fu)
#define CCU6_MCM_Expected_Hall_Sts()     ((CCU6->MCMOUT.reg >> 8u) & 0x1Fu)
#define CCU6_MCM_Current_Hall_Sts()      ((CCU6->MCMOUT.reg >> 11u) & 0x1Fu)

/* Multi-Channel Mode Control Register */
#define CCU6_MCM_Switch_Sel(swsel)       (CCU6->MCMCTR.bit.SWSEL = (swsel & 7u))
#define CCU6_MCM_Switch_NoTrigger_Sel()   (CCU6->MCMCTR.bit.SWSEL = 0u)
#define CCU6_MCM_Switch_CorrectHall_Sel() (CCU6->MCMCTR.bit.SWSEL = 1u)
#define CCU6_MCM_Switch_T13_PM_Sel()      (CCU6->MCMCTR.bit.SWSEL = 2u)
#define CCU6_MCM_Switch_T12_ON_Sel()      (CCU6->MCMCTR.bit.SWSEL = 3u)
#define CCU6_MCM_Switch_T12_Ch1_CM_Sel()  (CCU6->MCMCTR.bit.SWSEL = 4u)
#define CCU6_MCM_Switch_T12_PM_Sel()      (CCU6->MCMCTR.bit.SWSEL = 5u)
#define CCU6_MCM_Switch_Sync_direct_Sel() (CCU6->MCMCTR.bit.SWSYN = 0u)
#define CCU6_MCM_Switch_Sync_T13_ZM_Sel() (CCU6->MCMCTR.bit.SWSYN = 1u)
#define CCU6_MCM_Switch_Sync_T12_ZM_Sel() (CCU6->MCMCTR.bit.SWSYN = 2u)
#define CCU6_MCM_Str_T12_UP_cnt_En()      (CCU6->MCMCTR.reg |= (uint16)  (1u << 8u))
#define CCU6_MCM_Str_T12_UP_cnt_Dis()     (CCU6->MCMCTR.reg &= (uint16) ~(1u << 8u))
#define CCU6_MCM_Str_T12_Down_cnt_En()    (CCU6->MCMCTR.reg |= (uint16)  (1u << 9u))
#define CCU6_MCM_Str_T12_Down_cnt_Dis()   (CCU6->MCMCTR.reg &= (uint16) ~(1u << 9u))
#define CCU6_MCM_Str_T13_UP_cnt_En()      (CCU6->MCMCTR.reg |= (uint16)  (1u << 10u))
#define CCU6_MCM_Str_T13_UP_cnt_Dis()     (CCU6->MCMCTR.reg &= (uint16) ~(1u << 10u))

/* CCU6 Interrupt Status Register */
#define CCU6_T12_CM_CC60_Int_Rise_Sts()  ((CCU6->IS.reg >> 0u) & 1u)
#define CCU6_T12_CM_CC61_Int_Rise_Sts()  ((CCU6->IS.reg >> 2u) & 1u)
#define CCU6_T12_CM_CC62_Int_Rise_Sts()  ((CCU6->IS.reg >> 4u) & 1u)
#define CCU6_T12_CM_CC60_Int_Fall_Sts()  ((CCU6->IS.reg >> 1u) & 1u)
#define CCU6_T12_CM_CC61_Int_Fall_Sts()  ((CCU6->IS.reg >> 3u) & 1u)
#define CCU6_T12_CM_CC62_Int_Fall_Sts()  ((CCU6->IS.reg >> 5u) & 1u)
#define CCU6_T12_OM_Int_Sts()            ((CCU6->IS.reg >> 6u) & 1u)
#define CCU6_T12_PM_Int_Sts()            ((CCU6->IS.reg >> 7u) & 1u)
#define CCU6_T13_CM_Int_Sts()            ((CCU6->IS.reg >> 8u) & 1u)
#define CCU6_T13_PM_Int_Sts()            ((CCU6->IS.reg >> 9u) & 1u)
#define CCU6_Trap_Flag_Int_Sts()         ((CCU6->IS.reg >> 10u) & 1u)
#define CCU6_Trap_State_Int_Sts()        ((CCU6->IS.reg >> 11u) & 1u)
#define CCU6_Hall_Correct_Int_Sts()      ((CCU6->IS.reg >> 12u) & 1u)
#define CCU6_Hall_Wrong_Int_Sts()        ((CCU6->IS.reg >> 13u) & 1u)
#define CCU6_MCM_Idle_Int_Sts()          ((CCU6->IS.reg >> 14u) & 1u)
#define CCU6_MCM_Str_Int_Sts()           ((CCU6->IS.reg >> 15u) & 1u)

#define CCU6_T12_CM_CC60_Int_Rise_Set()   (CCU6->ISS.reg = (uint16) (1u << 0u)) 
#define CCU6_T12_CM_CC61_Int_Rise_Set()   (CCU6->ISS.reg = (uint16) (1u << 2u)) 
#define CCU6_T12_CM_CC62_Int_Rise_Set()   (CCU6->ISS.reg = (uint16) (1u << 4u)) 
#define CCU6_T12_CM_CC60_Int_Fall_Set()   (CCU6->ISS.reg = (uint16) (1u << 1u)) 
#define CCU6_T12_CM_CC61_Int_Fall_Set()   (CCU6->ISS.reg = (uint16) (1u << 3u)) 
#define CCU6_T12_CM_CC62_Int_Fall_Set()   (CCU6->ISS.reg = (uint16) (1u << 5u)) 
#define CCU6_T12_OM_Int_Set()             (CCU6->ISS.reg = (uint16) (1u << 6u)) 
#define CCU6_T12_PM_Int_Set()             (CCU6->ISS.reg = (uint16) (1u << 7u)) 
#define CCU6_T13_CM_Int_Set()             (CCU6->ISS.reg = (uint16) (1u << 8u)) 
#define CCU6_T13_PM_Int_Set()             (CCU6->ISS.reg = (uint16) (1u << 9u)) 
#define CCU6_Trap_Flag_Int_Set()          (CCU6->ISS.reg = (uint16) (1u << 10u))
#define CCU6_Trap_SW_Hall_Int_Set()       (CCU6->ISS.reg = (uint16) (1u << 11u))
#define CCU6_Hall_Correct_Int_Set()       (CCU6->ISS.reg = (uint16) (1u << 12u))
#define CCU6_Hall_Wrong_Int_Set()         (CCU6->ISS.reg = (uint16) (1u << 13u))
#define CCU6_MCM_Idle_Int_Set()           (CCU6->ISS.reg = (uint16) (1u << 14u))
#define CCU6_MCM_Str_Int_Set()            (CCU6->ISS.reg = (uint16) (1u << 15u))

/* CCU6 Interrupt Node select */
#define CCU6_Ch0_Int_Node_Sel(srx)        (CCU6->INP.bit.INPCC60 = (srx & 3u))
#define CCU6_Ch1_Int_Node_Sel(srx)        (CCU6->INP.bit.INPCC61 = (srx & 3u))
#define CCU6_Ch2_Int_Node_Sel(srx)        (CCU6->INP.bit.INPCC62 = (srx & 3u))
#define CCU6_Error_Int_Node_Sel(srx)      (CCU6->INP.bit.INPERR  = (srx & 3u))
#define CCU6_T12_Int_Node_Sel(srx)        (CCU6->INP.bit.INPT12  = (srx & 3u))
#define CCU6_T13_Int_Node_Sel(srx)        (CCU6->INP.bit.INPT13  = (srx & 3u))
#define CCU6_Hall_Correct_Int_Node_Sel(srx) \
                                          (CCU6->INP.bit.INPCHE = (srx & 3u))
/* CCU6 Interrupt Clear Macros */
#define CCU6_CH0_CM_R_Int_Clr()      (CCU6->ISR.reg = (uint16)1u << 0u)
#define CCU6_CH0_CM_F_Int_Clr()      (CCU6->ISR.reg = (uint16)1u << 1u)
#define CCU6_CH1_CM_R_Int_Clr()      (CCU6->ISR.reg = (uint16)1u << 2u)
#define CCU6_CH1_CM_F_Int_Clr()      (CCU6->ISR.reg = (uint16)1u << 3u)
#define CCU6_CH2_CM_R_Int_Clr()      (CCU6->ISR.reg = (uint16)1u << 4u)
#define CCU6_CH2_CM_F_Int_Clr()      (CCU6->ISR.reg = (uint16)1u << 5u)
#define CCU6_T12_OM_Int_Clr()        (CCU6->ISR.reg = (uint16)1u << 6u)
#define CCU6_T12_PM_Int_Clr()        (CCU6->ISR.reg = (uint16)1u << 7u)
#define CCU6_T13_CM_Int_Clr()        (CCU6->ISR.reg = (uint16)1u << 8u)
#define CCU6_T13_PM_Int_Clr()        (CCU6->ISR.reg = (uint16)1u << 9u)
#define CCU6_TRAP_Int_Clr()          (CCU6->ISR.reg = (uint16)1u << 10u)
#define CCU6_CHE_Int_Clr()           (CCU6->ISR.reg = (uint16)1u << 12u)
#define CCU6_WHE_Int_Clr()           (CCU6->ISR.reg = (uint16)1u << 13u)
#define CCU6_STR_Int_Clr()           (CCU6->ISR.reg = (uint16)1u << 15u)

/* CCU6 Interrupt Enable/Disable Macros */
#define CCU6_CH0_CM_R_Int_En()      (CCU6->IEN.bit.ENCC60R = 1u)
#define CCU6_CH0_CM_R_Int_Dis()     (CCU6->IEN.bit.ENCC60R = 0u)
#define CCU6_CH0_CM_F_Int_En()      (CCU6->IEN.bit.ENCC60F = 1u)
#define CCU6_CH0_CM_F_Int_Dis()     (CCU6->IEN.bit.ENCC60F = 0u)
#define CCU6_CH1_CM_R_Int_En()      (CCU6->IEN.bit.ENCC61R = 1u)
#define CCU6_CH1_CM_R_Int_Dis()     (CCU6->IEN.bit.ENCC61R = 0u)
#define CCU6_CH1_CM_F_Int_En()      (CCU6->IEN.bit.ENCC61F = 1u)
#define CCU6_CH1_CM_F_Int_Dis()     (CCU6->IEN.bit.ENCC61F = 0u)
#define CCU6_CH2_CM_R_Int_En()      (CCU6->IEN.bit.ENCC62R = 1u)
#define CCU6_CH2_CM_R_Int_Dis()     (CCU6->IEN.bit.ENCC62R = 0u)
#define CCU6_CH2_CM_F_Int_En()      (CCU6->IEN.bit.ENCC62F = 1u)
#define CCU6_CH2_CM_F_Int_Dis()     (CCU6->IEN.bit.ENCC62F = 0u)
#define CCU6_T12_OM_Int_En()        (CCU6->IEN.bit.ENT12OM = 1u)
#define CCU6_T12_OM_Int_Dis()       (CCU6->IEN.bit.ENT12OM = 0u)
#define CCU6_T12_PM_Int_En()        (CCU6->IEN.bit.ENT12PM = 1u)
#define CCU6_T12_PM_Int_Dis()       (CCU6->IEN.bit.ENT12PM = 0u)
#define CCU6_T13_CM_Int_En()        (CCU6->IEN.bit.ENT13CM = 1u)
#define CCU6_T13_CM_Int_Dis()       (CCU6->IEN.bit.ENT13CM = 0u)
#define CCU6_T13_PM_Int_En()        (CCU6->IEN.bit.ENT13PM = 1u)
#define CCU6_T13_PM_Int_Dis()       (CCU6->IEN.bit.ENT13PM = 0u)
#define CCU6_TRAP_Int_En()          (CCU6->IEN.bit.ENTRPF = 1u)
#define CCU6_TRAP_Int_Dis()         (CCU6->IEN.bit.ENTRPF = 0u)
#define CCU6_CHE_Int_En()           (CCU6->IEN.bit.ENCHE = 1u)
#define CCU6_CHE_Int_Dis()          (CCU6->IEN.bit.ENCHE = 0u)
#define CCU6_WHE_Int_En()           (CCU6->IEN.bit.ENWHE = 1u)
#define CCU6_WHE_Int_Dis()          (CCU6->IEN.bit.ENWHE = 0u)
#define CCU6_STR_Int_En()           (CCU6->IEN.bit.ENSTR = 1u)
#define CCU6_STR_Int_Dis()          (CCU6->IEN.bit.ENSTR = 0u)

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void CCU6_Init(void);
__STATIC_INLINE void CCU6_StartTmr_T12(void);
__STATIC_INLINE void CCU6_StartTmr_T13(void);
__STATIC_INLINE void CCU6_StopTmr_T12(void);
__STATIC_INLINE void CCU6_StopTmr_T13(void);
__STATIC_INLINE void CCU6_EnableST_T12(void);
__STATIC_INLINE void CCU6_EnableST_T13(void);
__STATIC_INLINE void CCU6_LoadShadowRegister_CC60(uint16 tick);
__STATIC_INLINE void CCU6_LoadShadowRegister_CC61(uint16 tick);
__STATIC_INLINE void CCU6_LoadShadowRegister_CC62(uint16 tick);
__STATIC_INLINE void CCU6_LoadShadowRegister_CC63(uint16 tick);
__STATIC_INLINE void CCU6_LoadPeriodRegister_T13_Time(uint16 us);
__STATIC_INLINE void CCU6_LoadPeriodRegister_T13_Tick(uint16 tick);
__STATIC_INLINE bool CCU6_IsT13Running(void);
__STATIC_INLINE void CCU6_SetT13Trigger(uint16 Mask);
__STATIC_INLINE void CCU6_SetT13Compare(uint16 Compare);
__STATIC_INLINE void CCU6_SetT12T13ControlBits(uint16 Mask);
__STATIC_INLINE uint32 CCU6_ReadHallReg(void);
__STATIC_INLINE uint16 CCU6_ReadMultichannelPatterns(void);
__STATIC_INLINE void CCU6_WriteMultichannelPatterns(uint16 Patterns);
__STATIC_INLINE void CCU6_ConfigureMultichannelModulation(uint16 Mode);
__STATIC_INLINE void CCU6_ConfigureGlobalModulation(uint16 Mode);
__STATIC_INLINE void CCU6_EnableInt(uint16 Mask);
__STATIC_INLINE void CCU6_ClearIntStatus(uint16 Mask);

/******************************************************************************
**                      Global Inline Function Definitions                   **
******************************************************************************/
/** \brief Start CCU6 Timer
 *
 * \param[in] none
 * \return void
 * \ingroup ccu_api
 */
__STATIC_INLINE void CCU6_StartTmr_T12(void)
{
  CCU6->TCTR4.reg = CCU6_MASK_TCTR4_START_T12;
}

__STATIC_INLINE void CCU6_StartTmr_T13(void)
{
  CCU6->TCTR4.reg = CCU6_MASK_TCTR4_START_T13;
}


/** \brief Stop CCU6 Timer
 *
 * \param[in] TimerNr-T12, T13
 * \return void
 * \ingroup ccu_api
 */
__STATIC_INLINE void CCU6_StopTmr_T12(void)
{
  CCU6->TCTR4.reg = CCU6_MASK_TCTR4_STOP_T12;
}

__STATIC_INLINE void CCU6_StopTmr_T13(void)
{
  CCU6->TCTR4.reg = CCU6_MASK_TCTR4_STOP_T13;
}

/** \brief Enable Shadow Transfer
 *
 * \param[in] TimerNr-T12, T13
 * \return void
 * \ingroup ccu_api
 */
__STATIC_INLINE void CCU6_EnableST_T12(void)
{
  CCU6->TCTR4.reg = CCU6_MASK_TCTR4_SHADOW_T12;
}

__STATIC_INLINE void CCU6_EnableST_T13(void)
{
  CCU6->TCTR4.reg = CCU6_MASK_TCTR4_SHADOW_T13;
}

/** \brief Load compare value to the shadow register
 *
 * \param[in] compare value in clock ticks
 * \return void
 * \ingroup ccu_api
 */
__STATIC_INLINE void CCU6_LoadShadowRegister_CC60(uint16 tick)
{
  CCU6->CC60SR.reg = tick;
}

__STATIC_INLINE void CCU6_LoadShadowRegister_CC61(uint16 tick)
{
  CCU6->CC61SR.reg = tick;
}

__STATIC_INLINE void CCU6_LoadShadowRegister_CC62(uint16 tick)
{
  CCU6->CC62SR.reg = tick;
}

__STATIC_INLINE void CCU6_LoadShadowRegister_CC63(uint16 tick)
{
  CCU6->CC63SR.reg = tick;
}

/** \brief Load Timer13 Period Register as Time Value
 *
 * \param[in] Period in Time [us]
 * \return void
 * \ingroup ccu_api
 */
__STATIC_INLINE void CCU6_LoadPeriodRegister_T13_Time(uint16 us)
{
  CCU6->T13PR.reg = (uint16) (CCU6_T13_CLK * us);
}

/** \brief Load Timer13 Period Register as Time Value
 *
 * \param[in] Period in clock ticks
 * \return void
 * \ingroup ccu_api
 */
__STATIC_INLINE void CCU6_LoadPeriodRegister_T13_Tick(uint16 tick)
{
  CCU6->T13PR.reg = tick;
}

/** \brief Load Timer13 Period Register as Time Value
 *
 * \param[in] Period in Time [us]
 * \return void
 * \ingroup ccu_api
 */
__STATIC_INLINE bool CCU6_IsT13Running(void)
{
  return ((bool) (CCU6->TCTR0.bit.T13R == 1u));
}

/** \brief Sets trigger event for the T13 timer.
 *
 * \param[in] Mask Trigger mask
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_SetT13Trigger(uint16 Mask)
{
  /* Set trigger mask */
  CCU6->TCTR2.reg = Mask;
}

/** \brief Sets compare value for the T13 timer.
 *
 * \param[in] Compare Compare value
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_SetT13Compare(uint16 Compare)
{
  /* Set compare value */
  CCU6->CC63SR.reg = Compare;
  
  /* Set period value */
  CCU6->T13PR.reg = Compare + 10u;
  
  /* Enable shadow transfer */
  CCU6->TCTR4.reg = CCU6_MASK_TCTR4_SHADOW_T13;
}

/** \brief Sets write-only control bits for T12 and/or T13 timer.
 *
 * \param[in] Mask Control bit mask
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_SetT12T13ControlBits(uint16 Mask)
{
  CCU6->TCTR4.reg = Mask;
}

/** \brief Reads sampled Hall pattern from CCU6 CMPSTAT register.
 *
 * \return Sampled Hall pattern
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE uint32 CCU6_ReadHallReg(void)
{
  return ((uint32)(CCU6->CMPSTAT.reg) >> 3u) & 0x7u;
}

/** \brief Reads actual Hall and PWM patterns for Multi-Channel Mode.
 *
 * \return Hall and PWM patterns
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE uint16 CCU6_ReadMultichannelPatterns(void)
{
  return CCU6->MCMOUT.reg;
}

/** \brief Writes Hall and/or PWM patterns for Multi-Channel Mode to shadow register.
 *
 * \param[in] Patterns Hall and/or PWM patterns
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_WriteMultichannelPatterns(uint16 Patterns)
{
  CCU6->MCMOUTS.reg = Patterns;
}

/** \brief Sets Multi-Channel Mode control register.
 *
 * \param[in] Mode Multi-Channel mode control bits
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_ConfigureMultichannelModulation(uint16 Mode)
{
  CCU6->MCMCTR.reg = Mode;
}

/** \brief Sets global modulation control register.
 *
 * \param[in] Mode Global modulation control bits
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_ConfigureGlobalModulation(uint16 Mode)
{
  CCU6->MODCTR.reg = Mode;
}

/** \brief Enables/disables interrupt(s).
 *
 * \param[in] Mask for interrupt(s) to be enabled.
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_EnableInt(uint16 Mask)
{
  CCU6->IEN.reg = Mask;
}

/** \brief Clears interrupt status bit(s).
 *
 * \param[in] Mask for interrupt status bit(s) to be cleared.
 * \return None
 *
 * \ingroup ccu6_api
 */
__STATIC_INLINE void CCU6_ClearIntStatus(uint16 Mask)
{
  CCU6->ISR.reg = Mask;
}


#endif
