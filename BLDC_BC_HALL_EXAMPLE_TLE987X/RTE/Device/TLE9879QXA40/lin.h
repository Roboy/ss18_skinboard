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
/* See lin.c */

#ifndef LIN_H
#define LIN_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "lin_defines.h"

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
#define LIN_MODE_SLEEP    (0u)
#define LIN_MODE_RCV_ONLY (1u)
#define LIN_MODE_NORMAL   (3u)

#define LIN_GET_MODE_SLEEP    (1u)
#define LIN_GET_MODE_RCV_ONLY (5u)
#define LIN_GET_MODE_NORMAL   (7u)

#define LIN_SLOPE_NORMAL  (0u)
#define LIN_SLOPE_FAST    (1u)
#define LIN_SLOPE_LOW     (2u)
#define LIN_SLOPE_FLASH   (3u)

/* LIN Interrupt Clear Macros */
#define LIN_Over_Curr_Int_Clr()            (SCUPM->SYS_ISCLR.reg = (uint8)1u << 0u)
#define LIN_Over_Temp_Int_Clr()            (SCUPM->SYS_ISCLR.reg = (uint8)1u << 1u)
#define LIN_Time_Out_Int_Clr()             (SCUPM->SYS_ISCLR.reg = (uint8)1u << 2u)
#define LIN_End_Of_Sync_Int_Clr()          (SCU->LINSCLR.reg = (uint8)1u << 4u)
#define LIN_Err_In_Sync_Int_Clr()          (SCU->LINSCLR.reg = (uint8)1u << 5u)
#define LIN_Break_Int_Clr()                (SCU->LINSCLR.reg = (uint8)1u << 3u)

/* LIN Interrupt Enable/Disable Macros */
#define LIN_Over_Curr_Int_En()             (SCUPM->SYS_IRQ_CTRL.bit.LIN_OC_IE = 1u)
#define LIN_Over_Curr_Int_Dis()            (SCUPM->SYS_IRQ_CTRL.bit.LIN_OC_IE = 0u)
#define LIN_Over_Temp_Int_En()             (SCUPM->SYS_IRQ_CTRL.bit.LIN_OT_IE = 1u)
#define LIN_Over_Temp_Int_Dis()            (SCUPM->SYS_IRQ_CTRL.bit.LIN_OT_IE = 0u)
#define LIN_Time_Out_Int_En()              (SCUPM->SYS_IRQ_CTRL.bit.LIN_TMOUT_IE = 1u)
#define LIN_Time_Out_Int_Dis()             (SCUPM->SYS_IRQ_CTRL.bit.LIN_TMOUT_IE = 0u)
#define LIN_Sync_Int_En()                  (SCU->LINST.bit.SYNEN = 1u)
#define LIN_Sync_Int_Dis()                 (SCU->LINST.bit.SYNEN = 0u)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void LIN_Init(void);

__STATIC_INLINE void LIN_Set_Mode(uint8 Mode);
__STATIC_INLINE uint8 LIN_Get_Mode(void);
__STATIC_INLINE void LIN_Set_Slope(uint8 SlopeMode);
/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/
/** \brief Sets LIN Trx. Mode
 *
 * \param[in] LIN Mode Selection
 * \param[in] none
 * \return None
 *
 * \ingroup lin_api
 */
__STATIC_INLINE void LIN_Set_Mode(uint8 Mode)
{
  LIN->CTRL_STS.bit.MODE = Mode;
}

/** \brief Gets LIN Trx. Mode
 *
 * \param[in] none
 * \param[in] none
 * \return Lin Trx Mode
 *
 * \ingroup lin_api
 */
__STATIC_INLINE uint8 LIN_Get_Mode(void)
{
  return(LIN->CTRL_STS.bit.MODE_FB);
}


/** \brief Sets LIN Trx. Slope Mode
 *
 * \param[in] LIN Trx Slope Mode Selection
 * \param[in] none
 * \return None
 *
 * \ingroup lin_api
 */
__STATIC_INLINE void LIN_Set_Slope(uint8 SlopeMode)
{
  LIN->CTRL_STS.bit.MODE = LIN_MODE_SLEEP;
  LIN->CTRL_STS.bit.SM = SlopeMode;
  LIN->CTRL_STS.bit.MODE = LIN_MODE_NORMAL;
}
#endif
