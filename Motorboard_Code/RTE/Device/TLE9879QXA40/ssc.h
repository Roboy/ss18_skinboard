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
/* See ssc.c */

#ifndef SSC_H
#define SSC_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "ssc_defines.h"

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
#define SSC1_tBit_us (1.0 / (SSC1_MAN_BAUDRATE / 1000.0))
#define SSC2_tBit_us (1.0 / (SSC2_MAN_BAUDRATE / 1000.0))

/* SSC Interrupt Clear Macros */
#define SSC1_TX_Int_Clr()            (SCU->IRCON1CLR.reg = (uint8)1u << 1u)
#define SSC1_RX_Int_Clr()            (SCU->IRCON1CLR.reg = (uint8)1u << 2u)
#define SSC1_Err_Int_Clr()           (SCU->IRCON1CLR.reg = (uint8)1u << 0u)
#define SSC2_TX_Int_Clr()            (SCU->IRCON2CLR.reg = (uint8)1u << 1u)
#define SSC2_RX_Int_Clr()            (SCU->IRCON2CLR.reg = (uint8)1u << 2u)
#define SSC2_Err_Int_Clr()           (SCU->IRCON2CLR.reg = (uint8)1u << 0u)

/* SSC Interrupt Enable/Disable Macros */
#define SSC1_TX_Int_En()            (SCU->MODIEN1.bit.TIREN1 = 1u)
#define SSC1_TX_Int_Dis()           (SCU->MODIEN1.bit.TIREN1 = 0u)
#define SSC1_RX_Int_En()            (SCU->MODIEN1.bit.RIREN1 = 1u)
#define SSC1_RX_Int_Dis()           (SCU->MODIEN1.bit.RIREN1 = 0u)
#define SSC1_Err_Int_En()           (SCU->MODIEN1.bit.EIREN1 = 1u)
#define SSC1_Err_Int_Dis()          (SCU->MODIEN1.bit.EIREN1 = 0u)
#define SSC2_TX_Int_En()            (SCU->MODIEN2.bit.TIREN2 = 1u)
#define SSC2_TX_Int_Dis()           (SCU->MODIEN2.bit.TIREN2 = 0u)
#define SSC2_RX_Int_En()            (SCU->MODIEN2.bit.RIREN2 = 1u)
#define SSC2_RX_Int_Dis()           (SCU->MODIEN2.bit.RIREN2 = 0u)
#define SSC2_Err_Int_En()           (SCU->MODIEN2.bit.EIREN2 = 1u)
#define SSC2_Err_Int_Dis()          (SCU->MODIEN2.bit.EIREN2 = 0u)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void SSC1_Init(void);
void SSC2_Init(void);
__STATIC_INLINE uint16 SSC1_SendWord(uint16 DataWord);
__STATIC_INLINE uint16 SSC1_ReadWord(void);
__STATIC_INLINE uint16 SSC2_SendWord(uint16 DataWord);
__STATIC_INLINE uint16 SSC2_ReadWord(void);

/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/
/** \brief SSC1: Send data word.
 *
 * \param[in] Data to send
 * \return Received data
 *
 * \ingroup ssc_api
 */
__STATIC_INLINE uint16 SSC1_SendWord(uint16 DataWord)
{
  SSC1->TB.reg = DataWord;
  return(SSC1->RB.reg);
}

/** \brief SSC1: Read data word from receive buffer.
 *
 * \return Received data
 *
 * \ingroup ssc_api
 */
__STATIC_INLINE uint16 SSC1_ReadWord(void)
{
  return SSC1->RB.reg;
}

/** \brief SSC2: Send data word.
 *
 * \param[in] Data to send
 * \return Received data
 *
 * \ingroup ssc_api
 */
__STATIC_INLINE uint16 SSC2_SendWord(uint16 DataWord)
{
  SSC2->TB.reg = DataWord;
  return(SSC2->RB.reg);
}

/** \brief SSC2: Read data word from receive buffer.
 *
 * \return Received data
 *
 * \ingroup ssc_api
 */
__STATIC_INLINE uint16 SSC2_ReadWord(void)
{
  return SSC2->RB.reg;
}

#endif
