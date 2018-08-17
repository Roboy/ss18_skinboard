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
/* See interrupt.c */

#ifndef INT_H
#define INT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "int_defines.h"
#include "scu_defines.h"
#include "uart_defines.h"
#include "ssc_defines.h"
#include "gpt12e_defines.h"
#include "adc2_defines.h"
#include "mon_defines.h"

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
/* NMI Flags */
#define NMI_WDT (1u << 0u)
#define NMI_PLL (1u << 1u)
#define NMI_NVM (1u << 2u)
#define NMI_OT  (1u << 3u)
#define NMI_OWT (1u << 4u)
#define NMI_MAP (1u << 5u)
#define NMI_ECC (1u << 6u)
#define NMI_SUP (1u << 7u)

/* Global Interrupt Enable/Disable Macros */
#define Global_Int_En()              (SCU->IEN0.reg = (uint8)1u << 7u)
#define Global_Int_Dis()             (SCU->IEN0.reg = (uint8)0x0)
/* ECC Interrupt Enable/Disable Macros */
#define ECC_RAM_DoubleBit_Int_En()   (SCU->EDCCON.bit.RIE = 1u)
#define ECC_RAM_DoubleBit_Int_Dis()  (SCU->EDCCON.bit.RIE = 0u)
#define ECC_NVM_DoubleBit_Int_En()   (SCU->EDCCON.bit.NVMIE = 1u)
#define ECC_NVM_DoubleBit_Int_Dis()  (SCU->EDCCON.bit.NVMIE = 0u)
/* ECC Interrupt Enable/Disable Macros */
#define ECC_RAM_SingleBit_Int_Clr()  (SCU->EDCSCLR.reg = (uint8)1u << 4u)
#define ECC_RAM_DoubleBit_Int_Clr()  (SCU->EDCSCLR.reg = (uint8)1u << 0u)
#define ECC_NVM_DoubleBit_Int_Clr()  (SCU->EDCSCLR.reg = (uint8)1u << 2u)
/* EXTINT Interrupt Enable/Disable Macros */
#define EXINT0_Rising_Edge_Int_En()   (SCU->EXICON0.reg |= (uint8)(1u << 0u))
#define EXINT0_Rising_Edge_Int_Dis()  (SCU->EXICON0.reg &= (uint8)~(1u << 0u))
#define EXINT0_Falling_Edge_Int_En()  (SCU->EXICON0.reg |= (uint8)(1u << 1u))
#define EXINT0_Falling_Edge_Int_Dis() (SCU->EXICON0.reg &= (uint8)~(1u << 1u))
#define EXINT1_Rising_Edge_Int_En()   (SCU->EXICON0.reg |= (uint8)(1u << 2u))
#define EXINT1_Rising_Edge_Int_Dis()  (SCU->EXICON0.reg &= (uint8)~(1u << 2u))
#define EXINT1_Falling_Edge_Int_En()  (SCU->EXICON0.reg |= (uint8)(1u << 3u))
#define EXINT1_Falling_Edge_Int_Dis() (SCU->EXICON0.reg &= (uint8)~(1u << 3u))
#define EXINT2_Rising_Edge_Int_En()   (SCU->EXICON0.reg |= (uint8)(1u << 4u))
#define EXINT2_Rising_Edge_Int_Dis()  (SCU->EXICON0.reg &= (uint8)~(1u << 4u))
#define EXINT2_Falling_Edge_Int_En()  (SCU->EXICON0.reg |= (uint8)(1u << 5u))
#define EXINT2_Falling_Edge_Int_Dis() (SCU->EXICON0.reg &= (uint8)~(1u << 5u))
/* EXINT Interrupt Clear Macros */
#define EXINT0_Rising_Edge_Int_Clr()  (SCU->IRCON0CLR.reg = (uint8)1u << 0u)
#define EXINT0_Falling_Edge_Int_Clr() (SCU->IRCON0CLR.reg = (uint8)1u << 1u)
#define EXINT1_Rising_Edge_Int_Clr()  (SCU->IRCON0CLR.reg = (uint8)1u << 2u)
#define EXINT1_Falling_Edge_Int_Clr() (SCU->IRCON0CLR.reg = (uint8)1u << 3u)
#define EXINT2_Rising_Edge_Int_Clr()  (SCU->IRCON0CLR.reg = (uint8)1u << 4u)
#define EXINT2_Falling_Edge_Int_Clr() (SCU->IRCON0CLR.reg = (uint8)1u << 5u)
/* NMI Enable/Disable Macros */         
#define NMI_WDT_Int_En()             (SCU->NMICON.bit.NMIWDT = 1u)
#define NMI_WDT_Int_Dis()            (SCU->NMICON.bit.NMIWDT = 0u)
#define NMI_PLL_Int_En()             (SCU->NMICON.bit.NMIPLL = 1u)
#define NMI_PLL_Int_Dis()            (SCU->NMICON.bit.NMIPLL = 0u)
#define NMI_NVM_Int_En()             (SCU->NMICON.bit.NMINVM = 1u)
#define NMI_NVM_Int_Dis()            (SCU->NMICON.bit.NMINVM = 0u)
#define NMI_ECC_Int_En()             (SCU->NMICON.bit.NMIECC = 1u)
#define NMI_ECC_Int_Dis()            (SCU->NMICON.bit.NMIECC = 0u)
#define NMI_MAP_Int_En()             (SCU->NMICON.bit.NMIMAP = 1u)
#define NMI_MAP_Int_Dis()            (SCU->NMICON.bit.NMIMAP = 0u)
#define NMI_SUP_Int_En()             (SCU->NMICON.bit.NMISUP = 1u)
#define NMI_SUP_Int_Dis()            (SCU->NMICON.bit.NMISUP = 0u)
#define NMI_OWD_Int_En()             (SCU->NMICON.bit.NMIOWD = 1u)
#define NMI_OWD_Int_Dis()            (SCU->NMICON.bit.NMIOWD = 0u)
#define NMI_OT_Int_En()              (SCU->NMICON.bit.NMIOT = 1u)
#define NMI_OT_Int_Dis()             (SCU->NMICON.bit.NMIOT = 0u)
/* NMI Interrupt Clear Macros */
#define NMI_WDT_Int_Clr()            (SCU->NMICLR.reg = (uint8)1u << 0u)
#define NMI_PLL_Int_Clr()            (SCU->NMICLR.reg = (uint8)1u << 1u)
#define NMI_NVM_Int_Clr()            (SCU->NMICLR.reg = (uint8)1u << 2u)
#define NMI_OT_Int_Clr()             (SCU->NMICLR.reg = (uint8)1u << 3u)
#define NMI_OWD_Int_Clr()            (SCU->NMICLR.reg = (uint8)1u << 4u)
#define NMI_MAP_Int_Clr()            (SCU->NMICLR.reg = (uint8)1u << 5u)
#define NMI_ECC_Int_Clr()            (SCU->NMICLR.reg = (uint8)1u << 6u)
#define NMI_SUP_Int_Clr()            (SCU->NMICLR.reg = (uint8)1u << 7u)
/* BEMF Interrupt Enable/Disable Macros */
#define BEMF_Phase_U_Hi_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.PHU_ZCHI_IE = 1u)
#define BEMF_Phase_U_Hi_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.PHU_ZCHI_IE = 0u)
#define BEMF_Phase_U_Lo_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.PHU_ZCLOW_IE = 1u)
#define BEMF_Phase_U_Lo_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.PHU_ZCLOW_IE = 0u)
#define BEMF_Phase_V_Hi_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.PHV_ZCHI_IE = 1u)
#define BEMF_Phase_V_Hi_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.PHV_ZCHI_IE = 0u)
#define BEMF_Phase_V_Lo_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.PHV_ZCLOW_IE = 1u)
#define BEMF_Phase_V_Lo_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.PHV_ZCLOW_IE = 0u)
#define BEMF_Phase_W_Hi_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.PHW_ZCHI_IE = 1u)
#define BEMF_Phase_W_Hi_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.PHW_ZCHI_IE = 0u)
#define BEMF_Phase_W_Lo_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.PHW_ZCLOW_IE = 1u)
#define BEMF_Phase_W_Lo_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.PHW_ZCLOW_IE = 0u)
/* BEMF Interrupt Clear Macros */
#define BEMF_Phase_U_Hi_Int_Clr()    (SCUPM->SYS_ISCLR.reg = (uint32)1u << 17u)
#define BEMF_Phase_U_Lo_Int_Clr()    (SCUPM->SYS_ISCLR.reg = (uint32)1u << 16u)
#define BEMF_Phase_V_Hi_Int_Clr()    (SCUPM->SYS_ISCLR.reg = (uint32)1u << 19u)
#define BEMF_Phase_V_Lo_Int_Clr()    (SCUPM->SYS_ISCLR.reg = (uint32)1u << 18u)
#define BEMF_Phase_W_Hi_Int_Clr()    (SCUPM->SYS_ISCLR.reg = (uint32)1u << 21u)
#define BEMF_Phase_W_Lo_Int_Clr()    (SCUPM->SYS_ISCLR.reg = (uint32)1u << 20u)


/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
__STATIC_INLINE uint8 INT_Get_NMI_Status(void);
__STATIC_INLINE void INT_Clr_NMI_Status(uint8 Flags);
__STATIC_INLINE void INT_Enable_Global_Int(void);
__STATIC_INLINE void INT_Disable_Global_Int(void);
void INT_Init(void);

/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/
/** \brief Reads out the NMI Status
 *
 * \param[in] none
 * \param[in] NMI status flags
 * \return None
 *
 * \ingroup int_api
 */
__STATIC_INLINE uint8 INT_Get_NMI_Status(void)
{
  return ((uint8) SCU->NMISR.reg);
}

/** \brief Clears the NMI Status flags
 *
 * \param[in] NMI Status bit mask
 * \param[in] none
 * \return None
 *
 * \ingroup int_api
 */
__STATIC_INLINE void INT_Clr_NMI_Status(uint8 Flags)
{
  SCU->NMICLR.reg = (uint8)Flags;
}

/** \brief enables the global interrupt IEN0.EA
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void INT_Enable_Global_Int(void)
{
  Global_Int_En();
}

/** \brief disables the global interrupt IEN0.EA
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void INT_Disable_Global_Int(void)
{
  Global_Int_Dis();
}

#endif
