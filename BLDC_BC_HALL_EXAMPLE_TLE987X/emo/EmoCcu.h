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
/* See EmoCcu.c */

#ifndef EMO_CCU_H_
#define EMO_CCU_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"
#include "Emo.h"

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
/* Function-like macro to set Hall and output pattern */
/* Function-like macro to set TCTR0 */
#define Ccu6_SetTCTR0(T12CLK, T12PRE, T12CTM, T13CLK, T13PRE) \
  ( (((uint32)(T12CLK)) << 0u) | \
  (((uint32)(T12PRE)) << 3u) | \
  (((uint32)(T12CTM)) << 7u) | \
  (((uint32)(T13CLK)) << 8u) | \
  (((uint32)(T13PRE)) << 11u) )

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef struct
{
  uint32 SpeedLong;     /**< \brief Speed, including fractional part */
  uint16 Speed;         /**< \brief Speed [rpm] */
  uint16 EventTime;     /**< \brief Last event time [T3 timer ticks] */
  uint16 DelayTime;     /**< \brief Delay time for Hall [T13 timer ticks] */
  uint16 DelayMinSpeed; /**< \brief Minimum (absolute) speed for Hall delay */
  uint8 DelayAngle;     /**< \brief Delay angle for Hall [degrees] */
  uint8 StartCtr;       /**< \brief Start counter */
  uint8 DirIdx;         /**< \brief Direction index, 0=Forward, 8=Reverse */
} TEmoCcu_HallStatus;

/** \brief CCU6 configuration for block commutation, active freewheeling
 */
typedef struct
{
  uint16 HallOutPtns[16];    /**< \brief Hall and output patterns */
  uint8 T12Moden[16];        /**< \brief T12 modulation enable patterns */
} TEmoCcu_Cfg;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
extern const TEmoCcu_Cfg EmoCcu_Cfg;
extern TEmoCcu_HallStatus EmoCcu_HallStatus;

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern void Ccu6_Start(void);
extern void Ccu6_Stop(void);
extern void EmoCcu_InitHallVar(void);
extern void EmoCcu_InitHallPar(void);

__STATIC_INLINE void EmoCcu_SetDirIdx(uint8 DirIdx);
__STATIC_INLINE uint8 EmoCcu_GetDirIdx(void);
__STATIC_INLINE uint16 EmoCcu_GetSpeed(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/** \brief Sets the motor direction index.
 *
 * \param[in] Direction index, 0=Forward, 8=Reverse
 * \return None
 *
 * \note Should be set before execution of Ccu6_Start.
 *
 * \ingroup emo_ccu_api
 */
__STATIC_INLINE void EmoCcu_SetDirIdx(uint8 DirIdx)
{
  EmoCcu_HallStatus.DirIdx = DirIdx;
} /* End of EmoCcu_SetDirIdx */


/** \brief Gets the motor direction index.
 *
 * \return Direction index, 0=Forward, 8=Reverse
 *
 * \ingroup emo_ccu_api
 */
__STATIC_INLINE uint8 EmoCcu_GetDirIdx(void)
{
  return EmoCcu_HallStatus.DirIdx;
} /* End of Ccu6_GetDirIdx */

/** \brief Gets motor speed.
 *
 * \return Motor speed
 *
 * \ingroup emo_ccu_api
 */
__STATIC_INLINE uint16 EmoCcu_GetSpeed(void)
{
  return EmoCcu_HallStatus.Speed;
} /* End of Ccu6_GetSpeed */


#endif /* #ifndef EMO_CCU_H_ */

