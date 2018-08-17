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
 * V0.1.3: 2017-05-24, DM:   Interrupt APIs added
 * V0.1.2: 2015-06-24, DM:   SendWord functions return received data word
 * V0.1.1: 2015-02-10, DM:   individual header file added
 * V0.1.0: 2014-05-15, TA:   Initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <ssc.h>

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the SSC1 module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void SSC1_Init(void)
{
  SSC1->CON.reg = (uint16) SSC1_CON & (uint16)0x7FFF;
  SSC1->BR.reg = (uint16) SSC1_BR;
  SSC1->PISEL.reg = (uint16) SSC1_PISEL;
  SSC1->CON.reg |= (uint16)0x8000;
}

/** \brief Initializes the SSC2 module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void SSC2_Init(void)
{
  SSC2->CON.reg = (uint16) SSC2_CON & (uint16)0x7FFF;
  SSC2->BR.reg = (uint16) SSC2_BR;
  SSC2->PISEL.reg = (uint16) SSC2_PISEL;
  SSC2->CON.reg |= (uint16)0x8000;
}
