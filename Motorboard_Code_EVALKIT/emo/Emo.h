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
/* See Emo.c */

#ifndef EMO_H
#define EMO_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"
#include "bchall_defines.h"
#include "EmoMat.h"

/*******************************************************************************
**                      Global Macro Definitions not to be changed            **
*******************************************************************************/
/* Motor states */
#define EMO_MOTOR_STATE_UNINIT (0u)
#define EMO_MOTOR_STATE_STOP   (1u)
#define EMO_MOTOR_STATE_START  (2u)
#define EMO_MOTOR_STATE_SWITCH (3u)
#define EMO_MOTOR_STATE_RUN    (4u)

/* Error states */
#define EMO_ERROR_NONE              (0u)
#define EMO_ERROR_MOTOR_INIT        (1u)
#define EMO_ERROR_MOTOR_NOT_STOPPED (2u)
#define EMO_ERROR_MOTOR_NOT_STARTED (3u)

/* PWM period [PWM timer ticks] */
#define EMO_PWM_PERIOD_TICKS CCU6_T12PR

/* System frequency [Hz] */
#define EMO_FSYS_HZ SCU_FSYS

/*******************************************************************************
**                      Global Type Definitions                              **
*******************************************************************************/
/** \ingroup emo_type_definitions
 *  \brief TEmo_Ctrl 
 */
typedef struct
{
  sint16 UserRefSpeed;  /**< \brief User reference speed [rpm] */
  TMat_Pi SpeedPi;      /**< \brief Speed PI control */
  uint16 DutyCycle;     /**< \brief Duty cycle [PWM timer ticks] */ 
} TEmo_Ctrl;

/** \ingroup emo_type_definitions
 *  \brief TEmo_Status 
 *  Types involved in the interrupt loop are placed here.
 */
typedef struct
{
  uint8 MotorState;          /**< \brief Motor state */
} TEmo_Status;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/
extern TEmo_Status Emo_Status;
extern TEmo_Ctrl Emo_Ctrl;

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
extern void Emo_SetRefSpeed(sint16 RefSpeed);
extern uint32 Emo_Init(void);
extern uint32 Emo_StartMotor(void);
extern uint32 Emo_StopMotor(void);
extern void Emo_CtrlSpeed(void);
extern uint16 Emo_GetAbsSpeed(void);

__STATIC_INLINE uint8 Emo_GetMotorState(void);
__STATIC_INLINE void Emo_SetMotorState(uint8 MotorState);

 
/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/** \brief Returns the motor state.
 *
 * \return Motor state
 *
 * \ingroup emo_api
 */
__STATIC_INLINE uint8 Emo_GetMotorState(void)
{
  return Emo_Status.MotorState;
}
 
/** \brief Sets the motor state.
 *
 * \param[in] Motor state
 *
 * \ingroup emo_api
 */
__STATIC_INLINE void Emo_SetMotorState(uint8 MotorState)
{
  Emo_Status.MotorState = MotorState;
}


#endif /* EMO_H */

