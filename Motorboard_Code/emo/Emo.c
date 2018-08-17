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
**                                                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.1.0: 2015-08-15, SS: Initial version based on 0.9.4
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"
#include "Emo.h"
#include "EmoCcu.h"
#include "bchall_defines.h"

/******************************************************************************
**                      Private Macro Definitions                            **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void Emo_lInitPar(void);
static void Emo_lInitVar(void);

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
TEmo_Status Emo_Status;
TEmo_Ctrl Emo_Ctrl;

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes E-Motor HW and SW.
 *
 * \return Error or EMO_ERROR_NONE
 *
 * \ingroup emo_api
 */
uint32 Emo_Init(void)
{
  if(Emo_Status.MotorState != EMO_MOTOR_STATE_UNINIT)
  {
    /* Error detected: return with error */
    return EMO_ERROR_MOTOR_INIT;
  }

  /* Switch on VDDEXT */
  PMU->VDDEXT_CTRL.reg = 0x01u;
  
  /* Initialize Hall parameters */
  EmoCcu_InitHallPar();

  /* Initialize parameters */
  Emo_lInitPar();
  
  /* Initialize motor state */
  Emo_Status.MotorState = EMO_MOTOR_STATE_STOP;

  /* Return without error */
  return EMO_ERROR_NONE;

} /* End of Emo_Init */ 


/** \brief Sets the reference speed of the motor.
 *
 * \param[in] Reference speed
 * \return None
 *
 * \note Sign should only be changed when motor is stopped.
 *
 * \ingroup emo_api
 */
void Emo_SetRefSpeed(sint16 RefSpeed)
{
  /* Set direction index */
  EmoCcu_SetDirIdx((RefSpeed < 0) ? 8u : 0u);

  /* Set user reference speed to absolute value */
  Emo_Ctrl.UserRefSpeed = ((RefSpeed < 0) ? (-RefSpeed) : RefSpeed);  

} /* End of Emo_SetRefSpeed */


/** \brief Starts the motor.
 *
 * \param[in] Reference speed
 * \return Error or EMO_ERROR_NONE
 *
 * \note Service should only be called when motor is stopped.
 *
 * \ingroup emo_api
 */
uint32 Emo_StartMotor(void)
{
  if(Emo_Status.MotorState != EMO_MOTOR_STATE_STOP)
  {
    /* Error detected: return with error */
    return EMO_ERROR_MOTOR_NOT_STOPPED;
  }

  /* Start PWM */
  Ccu6_Start();

  /* Enable bridge (after starting PWM according to UM) */
	BDRV_Set_Bridge(Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM, Ch_PWM);
  
  /* Initialize variables */
  Emo_lInitVar();
  
  /* Initialize Hall variables */
  EmoCcu_InitHallVar();

  /* Set start state */
  Emo_Status.MotorState = EMO_MOTOR_STATE_START;

  /* Return without error */
  return EMO_ERROR_NONE;
} /* End of Emo_StartMotor */


/** \brief Stops the motor.
 *
 * \return Error code
 *
 * \note Service should only be called when motor was started before.
 *
 * \ingroup emo_api
 */
uint32 Emo_StopMotor(void)
{
  if(Emo_Status.MotorState < EMO_MOTOR_STATE_START)
  {
    /* Error detected: return with error */
    return EMO_ERROR_MOTOR_NOT_STARTED;
  }

  /* Disable bridge */
	BDRV_Set_Bridge(Ch_Off, Ch_Off, Ch_Off, Ch_Off, Ch_Off, Ch_Off);

  /* Stop PWM */
  Ccu6_Stop();

  /* Initialize bridge */
  BDRV_Init();

  /* Set stop state */
  Emo_Status.MotorState = EMO_MOTOR_STATE_STOP;
  
  /* Return without error */
  return EMO_ERROR_NONE;
} /* End of Emo_StopMotor */

/** \brief Controls speed/duty cycle for BC.
 *
 * \return None
 *
 * \ingroup emo_api
 */
void Emo_CtrlSpeed(void)
{
  uint16 DutyCycle;
  
  if(Emo_Status.MotorState == EMO_MOTOR_STATE_RUN)
  {
    /* Perform speed control */
    DutyCycle = (uint16)Mat_ExePi(&Emo_Ctrl.SpeedPi, Emo_Ctrl.UserRefSpeed - (sint16)Emo_GetAbsSpeed());
    
    /* Set new common duty cycle immediately */
		CCU6_LoadShadowRegister_CC60(DutyCycle);
		CCU6_LoadShadowRegister_CC61(DutyCycle);
		CCU6_LoadShadowRegister_CC62(DutyCycle);

		/* Enable shadow transfer for T12 */
		CCU6_EnableST_T12();

    /* Save new duty cycle */
    Emo_Ctrl.DutyCycle = DutyCycle;
  }    
} /* End of Emo_CtrlSpeed */

/** \brief Gets absolute motor speed.
 *
 * \return Absolute motor speed
 *
 * \ingroup emo_api
 */
uint16 Emo_GetAbsSpeed(void)
{
  return EmoCcu_GetSpeed();
} /* End of Emo_GetAbsSpeed() */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
static void Emo_lInitPar(void)
{
  /* Initialize user reference speed */
	Emo_Ctrl.UserRefSpeed = 0;
	
  /* Initialize PI control parameters for speed */
  Emo_Ctrl.SpeedPi.Kp = (sint16)BCHALL_SPEED_KP;
  Emo_Ctrl.SpeedPi.Ki = (sint16)BCHALL_SPEED_KI;

  /* Initialize PI control limits for speed according to PWM period */
  Emo_Ctrl.SpeedPi.IMin = (sint16)((((sint32)BCHALL_SPEED_IMIN) * EMO_PWM_PERIOD_TICKS)/100);
  Emo_Ctrl.SpeedPi.IMax = (sint16)((((sint32)BCHALL_SPEED_IMAX) * EMO_PWM_PERIOD_TICKS)/100);
  Emo_Ctrl.SpeedPi.PiMin = (sint16)((((sint32)BCHALL_SPEED_PIMIN) * EMO_PWM_PERIOD_TICKS)/100);
  Emo_Ctrl.SpeedPi.PiMax = (sint16)((((sint32)BCHALL_SPEED_PIMAX) * EMO_PWM_PERIOD_TICKS)/100);

} /* End of Emo_lInitPar */

static void Emo_lInitVar(void)
{
  Emo_Ctrl.SpeedPi.IOut = 0;
  Emo_Ctrl.DutyCycle = 0u;
 
} /* End of Emo_lInitVar */



