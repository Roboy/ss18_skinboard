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
** TA           Thomas Albersinger                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.5.2: 2017-02-16, DM:   Port prefix changed to capital letters
 *                           API extended
 * V0.5.1: 2015-02-10, DM:   individual header file added
 * V0.5.0: 2014-04-25, TA:   Port_Init(): use #defines from "IFX Config Wizard"
 * V0.4.0: 2013-10-16, DM:   Port Configuration changed into header file
 *                           with Configuration Wizard
 *                           configuration stored into #defines
 *                           Port_Init() modified 
 * V0.3.0: 2013-02-10, DM:   function Port_ChangePin() enhanced by Port Dir    
 *                           adjustment, ne function added PORT_ChangePinAlt() 
 *                           to set the alternative settings for a Port Pin at 
 *                           runtime                                           
 * V0.2.0: 2012-12-13, SS:   New SFR format                                    
 * V0.1.0: 2012-11-12, SS:   Initial version                                   
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <port.h>

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the ports.
 *
 * \param None
 * \return None
 *
 * \ingroup PORT_api
 */
void PORT_Init(void)
{
  /* Initialize all ports */
  uint8 Value;

  /* Port 0 */
  PORT->P0_DIR.reg = (uint8) PORT_P0_DIR;
  PORT->P0_OD.reg = (uint8) PORT_P0_OD;

  Value  = (uint8) ((PORT_P0_0_PUD & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P0_1_PUD & 0x02u));
  Value |= (uint8) ((PORT_P0_2_PUD & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P0_3_PUD & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P0_4_PUD & 0x02u) << 3u);
  PORT->P0_PUDEN.reg = Value;

  Value  = (uint8) ((PORT_P0_0_PUD & 0x01u));
  Value |= (uint8) ((PORT_P0_1_PUD & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P0_2_PUD & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P0_3_PUD & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P0_4_PUD & 0x01u) << 4u);
  PORT->P0_PUDSEL.reg = Value;

	Value  = (uint8) ((PORT_P0_0_ALT & 0x01u));
  Value |= (uint8) ((PORT_P0_1_ALT & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P0_2_ALT & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P0_3_ALT & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P0_4_ALT & 0x01u) << 4u);
  PORT->P0_ALTSEL0.reg = Value;

	Value  = (uint8) ((PORT_P0_0_ALT & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P0_1_ALT & 0x02u));
  Value |= (uint8) ((PORT_P0_2_ALT & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P0_3_ALT & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P0_4_ALT & 0x02u) << 3u);
  PORT->P0_ALTSEL1.reg = Value;
  PORT->P0_DATA.reg = (uint8) PORT_P0_DATA;

  /* Port 1 */
  PORT->P1_DIR.reg = (uint8) PORT_P1_DIR;
  PORT->P1_OD.reg = (uint8) PORT_P1_OD;

	Value  = (uint8) ((PORT_P1_0_PUD & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P1_1_PUD & 0x02u));
  Value |= (uint8) ((PORT_P1_2_PUD & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P1_3_PUD & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P1_4_PUD & 0x02u) << 3u);
  PORT->P1_PUDEN.reg = Value;

	Value  = (uint8) ((PORT_P1_0_PUD & 0x01u));
  Value |= (uint8) ((PORT_P1_1_PUD & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P1_2_PUD & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P1_3_PUD & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P1_4_PUD & 0x01u) << 4u);
  PORT->P1_PUDSEL.reg = Value;

	Value  = (uint8) ((PORT_P1_0_ALT & 0x01u));
  Value |= (uint8) ((PORT_P1_1_ALT & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P1_2_ALT & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P1_3_ALT & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P1_4_ALT & 0x01u) << 4u);
  PORT->P1_ALTSEL0.reg = Value;

	Value  = (uint8) ((PORT_P1_0_ALT & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P1_1_ALT & 0x02u));
  Value |= (uint8) ((PORT_P1_2_ALT & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P1_3_ALT & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P1_4_ALT & 0x02u) << 3u);
  PORT->P1_ALTSEL1.reg = Value;
  PORT->P1_DATA.reg = (uint8) PORT_P1_DATA;

  /* Port 2 */
  PORT->P2_DIR.reg = (uint8) PORT_P2_DIR;

	Value  = (uint8) ((PORT_P2_0_PUD & 0x02u) >> 1u);
  Value |= (uint8) ((PORT_P2_1_PUD & 0x02u));
  Value |= (uint8) ((PORT_P2_2_PUD & 0x02u) << 1u);
  Value |= (uint8) ((PORT_P2_3_PUD & 0x02u) << 2u);
  Value |= (uint8) ((PORT_P2_4_PUD & 0x02u) << 3u);
  Value |= (uint8) ((PORT_P2_5_PUD & 0x02u) << 4u);
  Value |= (uint8) ((PORT_P2_7_PUD & 0x02u) << 6u);
  PORT->P2_PUDEN.reg = Value;

	Value  = (uint8) ((PORT_P2_0_PUD & 0x01u));
  Value |= (uint8) ((PORT_P2_1_PUD & 0x01u) << 1u);
  Value |= (uint8) ((PORT_P2_2_PUD & 0x01u) << 2u);
  Value |= (uint8) ((PORT_P2_3_PUD & 0x01u) << 3u);
  Value |= (uint8) ((PORT_P2_4_PUD & 0x01u) << 4u);
  Value |= (uint8) ((PORT_P2_5_PUD & 0x01u) << 5u);
  Value |= (uint8) ((PORT_P2_7_PUD & 0x01u) << 7u);
  PORT->P2_PUDSEL.reg = Value;
}
