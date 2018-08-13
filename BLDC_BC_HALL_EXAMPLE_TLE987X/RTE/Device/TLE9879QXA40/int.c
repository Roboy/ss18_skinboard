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
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** TA           Thomas Albersinger                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.1.4: 2016-10-10, DM:   Interrupt Enable/Disable macros added
 *                           CPU->SHPR3 init (SysTick Prio) added
 * V0.1.3: 2015-11-25, DM:   SCU_DMAIENx added, SCU_DMAIRCx clear added
 * V0.1.2: 2015-09-17, DM:   SYS_IRQ_CTRL register init added
 * V0.1.1: 2015-02-10, DM:   individual header file added
 * V0.1.0: 2014-05-11, DM:   Initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <int.h>

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the Interrupt module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void INT_Init(void)
{
  /**************************************************************************
  ** Interrupt Control                                                     **
  **************************************************************************/
  SCU->NMICLR.reg = (uint8) SCU_NMICON;
  SCU->NMICON.reg = (uint8) SCU_NMICON;
  SCU->EXICON0.reg = (uint8) SCU_EXICON0;
  SCU->MODIEN1.reg = (uint8) SCU_MODIEN1;
  SCU->MODIEN2.reg = (uint8) SCU_MODIEN2;
  SCU->MODIEN3.reg = (uint8) SCU_MODIEN3;
  SCU->MODIEN4.reg = (uint8) SCU_MODIEN4;
  SCU->GPT12IEN.reg = (uint8) SCU_GPT12IEN;
  SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32) 0x00FF00FF;
  SCUPM->SYS_ISCLR.reg = (uint32)0x3F3FFFC7;
  SCUPM->SYS_SUPPLY_IRQ_CTRL.reg = (uint32) SCU_SYS_SUPPLY_IRQ_CTRL;
  SCUPM->SYS_IRQ_CTRL.reg = SCU_SYS_IRQ_CTRL;
  SCU->EDCCON.reg = (uint8) SCU_EDCCON;
#ifdef SCU_BDRV_IRQ_CTRL
  SCUPM->BDRV_IRQ_CTRL.reg = (uint32) SCU_BDRV_IRQ_CTRL;
#endif
  CPU->NVIC_IPR0.reg = (uint32) CPU_NVIC_IPR0;
  CPU->NVIC_IPR1.reg = (uint32) CPU_NVIC_IPR1;
  CPU->NVIC_IPR2.reg = (uint32) CPU_NVIC_IPR2;
  CPU->NVIC_IPR3.reg = (uint32) CPU_NVIC_IPR3;
  CPU->NVIC_ISER0.reg = (uint32) CPU_NVIC_ISER0;
  SCU->IEN0.reg = (uint8) SCU_IEN0;
#if (INT_XML_VERSION >= 10109u)
  SCU->DMAIRC1CLR.reg = (uint8)0xFF;
  SCU->DMAIRC2CLR.reg = (uint8)0xFF;
#ifdef SCU_DMAIEN1
  SCU->DMAIEN1.reg = (uint8) SCU_DMAIEN1;
#endif
#ifdef SCU_DMAIEN2
  SCU->DMAIEN2.reg = (uint8) SCU_DMAIEN2;
#endif
#endif
#if (INT_XML_VERSION >= 10300u)
  CPU->SHPR3.reg = (uint32) CPU_NVIC_SHPR3;
#endif
}
