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
** SS           Steffen Storandt                                              **
** DM           Daniel Mysliwitz                                              **
** TL           Ted Lee                                                       **
** MK           Martin Kilian                                                 **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*
 * V0.1.6: 2017-03-23, DM:   ADC1 API extended
 * V0.1.5: 2017-02-16, DM:   the attenuator for Channel 6 (VDH) voltage 
 *                           calculation added
 *                           Adc1 prefix changed to ADC1
 * V0.1.4: 2015-11-26, DM:   VAREF enable function added
 * V0.1.3: 2015-03-22, DM:   ADC Busy function added
 * V0.1.2: 2015-03-10, DM:   MF->REF2_CTRL added
 * V0.1.1: 2015-02-10, DM:   individual header file added
 * V0.1.0: (?)
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <adc1.h>
#include <wdt1.h>

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the ADC1.
 *
 * \param None
 * \return None
 *
 * \ingroup ADC1_api
 */
void ADC1_Init(void)
{
  
/* Clock Configuration ********************************************************/
  ADC1->GLOBCTR.reg = (uint32) ADC1_GLOBCTR;

  /* Sequencer1-4 configuration */
  ADC1->SQ1_4.reg = (uint32) ADC1_SQ1_4;
  /* Sequencer5-8 configuration */
  ADC1->SQ5_8.reg = (uint32) ADC1_SQ5_8;

  ADC1->SQ_FB.reg = (uint32) ADC1_SQ_FB;

/* EIS / EMS configuration ***************************************************/
  ADC1->CHx_EIM.reg = (uint32) ADC1_CHX_EIM;
  ADC1->CHx_ESM.reg = (uint32) ADC1_ESM;

/* Channel control registers configuration ***********************************/
  /* DWSEL register */
  ADC1->DWSEL.reg = (uint32) ADC1_DWSEL;

  /* STC register */
  ADC1->STC_0_3.reg = (uint32) ADC1_STC_0_3;

  ADC1->STC_4_7.reg = (uint32) ADC1_STC_4_7;

/* Result Register Configuration **********************************************/
  ADC1->RES_OUT0.reg = (uint32) ADC1_RES0;
  ADC1->RES_OUT1.reg = (uint32) ADC1_RES1;
  ADC1->RES_OUT2.reg = (uint32) ADC1_RES2;
  ADC1->RES_OUT3.reg = (uint32) ADC1_RES3;
  ADC1->RES_OUT4.reg = (uint32) ADC1_RES4;
  ADC1->RES_OUT5.reg = (uint32) ADC1_RES5;
  ADC1->RES_OUT6.reg = (uint32) ADC1_RES6;
  ADC1->RES_OUT_EIM.reg = (uint32) ADC1_RES_EIM;

/* Interrupt configuration ****************************************************/
  ADC1->IE.reg = (uint32) ADC1_IE;

/* Set VMON Attenuator */
  MF->VMON_SEN_CTRL.reg = MF_VMON_SEN_CTRL;
/* Set VAREF */
  MF->REF2_CTRL.reg = MF_REF2_CTRL;

/* Enable ADC1 ****************************************************************/
  /* ADC1 is in normal operation. */
  SCU->PMCON1.bit.ADC1_DIS = 0;
  /* Normal Operation */
  ADC1_ANON_Set(ADC1_ANON_NORMAL);
  /* ADC1 is switched on */
  ADC1_Power_On();
}

/** \brief enable internal VAREF.
 *
 * \param None
 * \return true = VAREF enabled, false = VAREF enabling failed
 *
 * \ingroup ADC1_api
 */
bool VAREF_Enable(void)
{
  uint16 timeout;
  uint32 temp;
  bool res;
  /* set default result 'false' */
  res = false;
  /* disable VAREF */
  MF->REF2_CTRL.bit.VREF5V_PD_N = 0u;
  /* save lower threshold for ADC2.Ch6 (VAREF) */
  temp = ADC2->TH6_9_LOWER.reg;
  /* set lower threshold for ADC2.Ch6 to 0 */
  ADC2->TH6_9_LOWER.bit.CH6 = 0u;
  /* clear VAREF undervoltage/overload status flag */
  timeout = 5u;
  while ((timeout > 0u) && ((SCUPM->SYS_IS.reg & (uint32)0x5000u) != 0u))
  {
    SCUPM->SYS_ISCLR.reg = (uint32)0x5000u;
    Delay_us(100);
    timeout--;
  }
  if (timeout > 0u)
  {
    /* enable VAREF */
    MF->REF2_CTRL.bit.VREF5V_PD_N = 1u;
    /* wait until VAREF has reached at least 4.75V again */
    timeout = 10u;
    while ((timeout > 0) && (ADC2->FILT_OUT6.reg < (uint32)0x363u)) 
    { 
      Delay_us(100);
      timeout--;
    }
    if (timeout > 0u)
    {
      /* VAREF is enabled */
      res = true;
    }
  }
  /* restore ADC2.Ch6 lower threshold */
  ADC2->TH6_9_LOWER.reg = temp;
  return(res);
}
