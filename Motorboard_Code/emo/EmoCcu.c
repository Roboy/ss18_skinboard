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
 * V0.1.0: 2012-11-12, SS:   Initial version based on V0.9.5
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Emo.h"
#include "EmoCcu.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/* Function-like macro to set SFR MCMCTR */
#define Ccu6_lSetMCMCTR(SWSEL, SWSYN, STE12U, STE12D, STE13U) \
  ( (((uint32)(SWSEL)) << 0u) | \
    (((uint32)(SWSYN)) << 4u) | \
    (((uint32)(STE12U)) << 8u) | \
    (((uint32)(STE12D)) << 9u) | \
    (((uint32)(STE13U)) << 13u) )

/* Constants for MCMOUTS register */
#define CCU6_MASK_MCMOUTS_OUT_ALL (0x003Fu)

/* Constants for CCU6 interrupt registers */
#define CCU6_MASK_INT_T12PM (0x0080u)
#define CCU6_MASK_INT_CHE   (0x1000u)

/* Numerator for calculation of speed from commutation period:
 * speed [rpm] = numerator / (commutation period [256/fSYS in Hz])
 * numerator = CCU6 timer frequency [Hertz] * 60 / (6 * pole pairs), round to nearest */
#define SPEED_FROM_COMM_PERIOD_NUM ((uint32)((((EMO_FSYS_HZ / 256.0) * 60.0) / (6.0 * (float)BCHALL_POLE_PAIRS)) + 0.5))
	
/* BC speed low pass filter coefficient
 * Range: 1(slow update)..65535(fast update) */
#define POS_SPEED_LP_COEF ((uint16)((65536u + 3u) / 6u))

/* Hall filter time after Hall edge in timer ticks */
#define T13_HALL_FILTER_TIME_TICKS CCU6_T13PERIOD

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
TEmoCcu_HallStatus EmoCcu_HallStatus;

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/** \brief Starts PWM generation.
 *
 * \return None
 *
 * \ingroup emo_ccu_api
 */
void Ccu6_Start(void)
{
  uint32 HallOutPtn;
  uint16 InitDutyCycle;
  uint32 CurrentHallPtn;
  uint32 ExpHallPtn;
  
  /* Set common duty cycle */
  InitDutyCycle = (uint16)((((uint32)BCHALL_INIT_DUTY) * EMO_PWM_PERIOD_TICKS)/100);;

  CCU6_LoadShadowRegister_CC60(InitDutyCycle);
  CCU6_LoadShadowRegister_CC61(InitDutyCycle);
  CCU6_LoadShadowRegister_CC62(InitDutyCycle);

  /* Get current Hall pattern */
  CurrentHallPtn = CCU6_ReadHallReg();

  /* Set current/next T12MODEN and MCMEN in CCU60_MODCTR */
  CCU6_ConfigureGlobalModulation((uint16)EmoCcu_Cfg.T12Moden[CurrentHallPtn + EmoCcu_HallStatus.DirIdx]);

  /* Get current Hall and output patterns from table */
  HallOutPtn = EmoCcu_Cfg.HallOutPtns[CurrentHallPtn + EmoCcu_HallStatus.DirIdx];

  /* Set current Hall and output patterns immediately in MCMOUT */
  CCU6_WriteMultichannelPatterns((uint16)(HallOutPtn | CCU6_MASK_MCMOUTS_SHADOW_OUT | CCU6_MASK_MCMOUTS_SHADOW_HALL));

  /* Prepare next Hall and output patterns in CCU6_MCMOUTS */
  ExpHallPtn = (HallOutPtn >> 8u) & 0x7u;
  CCU6_WriteMultichannelPatterns(EmoCcu_Cfg.HallOutPtns[ExpHallPtn + EmoCcu_HallStatus.DirIdx]);

  /* Set Multi-Channel Mode Control register for switching on correct Hall pattern */
  CCU6_ConfigureMultichannelModulation((uint16)Ccu6_lSetMCMCTR
  (
    1, /* SWSEL Switching Selection(3 Bits): 
        * 0=No trigger request, 1=Correct Hall pattern, 2=T13 period match, 3=T12 one match, 
        * 4=T12 channel 1 compare match, 5=T12 period match, 6..7=reserved */
    0, /* SWSYN Switching Synchronization(2 Bits): 
        * 0=Direct, 1=T13 zero-match, 2=T12 zero-match (while counting up), 3=reserved */ 
    0, /* STE12U Shadow Transfer Enable for T12 Upcounting: 
        * 1=Enable transfer for T12 upcounting and MCMEN=1 */ 
    0, /* STE12D Shadow Transfer Enable for T12 Downcounting: 
        * 1=Enable transfer for T12 downcounting and MCMEN=1 */ 
    0  /* STE13U Shadow Transfer Enable for T13 Upcounting: 
        * 1=Enable transfer for T13 upcounting and MCMEN=1 */ 
  ));
	
  /* Start timer 3 */
  GPT12E_T3_Start();

  /* Clear status bits, enable interrupt for Hall event only */
  CCU6_ClearIntStatus(CCU6_MASK_INT_CHE);
  CCU6_EnableInt(CCU6_MASK_INT_CHE);

  /* Start T12, enable shadow transfer for T12 and T13 */
  CCU6_SetT12T13ControlBits((uint16)(CCU6_MASK_TCTR4_START_T12 | CCU6_MASK_TCTR4_SHADOW_T12 | CCU6_MASK_TCTR4_SHADOW_T13));
} /* End of Ccu6_Start */

/** \brief Stops PWM generation.
 *
 * \return None
 *
 * \ingroup emo_ccu_api
 */
void Ccu6_Stop(void)
{
  /* Disable multi-channel mode, will be set possibly during start */
  CCU6_ConfigureMultichannelModulation(0u);

  /* Clear output and Hall patterns immediately */
  CCU6_WriteMultichannelPatterns((uint16)(CCU6_MASK_MCMOUTS_SHADOW_OUT | CCU6_MASK_MCMOUTS_SHADOW_HALL));
  
  /* Stop timer 3 */
  GPT12E_T3_Stop();

  /* Stop and reset T12 and T13 */
  CCU6_SetT12T13ControlBits((uint16)(CCU6_MASK_TCTR4_STOP_T12 | CCU6_MASK_TCTR4_RESET_T12 | CCU6_MASK_TCTR4_STOP_T13 | CCU6_MASK_TCTR4_RESET_T13));
  
  /* Disable CCU6 interrupts */
  CCU6_EnableInt(0u);

} /* End of Ccu6_Stop */

/** \brief Handles CCU6 interrupt for correct Hall event.
 *
 * \return None
 *
 * \ingroup emo_ccu_api
 */
void EmoCcu_HandleHallEvent(void)
{
  uint32 ExpHallPtn;
  uint32 CurrentHallPtn;
  uint32 HallPtn;
  uint16 DiffTime;
  uint16 Speed;
  uint16 Time;
  uint16 DelayTime;
  
	/* Set current/next T12MODEN and MCMEN in CCU60_MODCTR */
	HallPtn = (uint32)(CCU6_ReadMultichannelPatterns() >> 8u);
	CurrentHallPtn = HallPtn >> 3u;
	CCU6_ConfigureGlobalModulation((uint16)EmoCcu_Cfg.T12Moden[CurrentHallPtn + EmoCcu_HallStatus.DirIdx]);

	/* Prepare next Hall patterns and output pattern */
	ExpHallPtn = HallPtn & 0x7u;
	CCU6_WriteMultichannelPatterns(EmoCcu_Cfg.HallOutPtns[ExpHallPtn + EmoCcu_HallStatus.DirIdx]);

  Time = GPT12E_T3_Value_Get();

  if(EmoCcu_HallStatus.StartCtr < 255u)
  {
    /* Increment start counter */
    EmoCcu_HallStatus.StartCtr++;
  }

  if(EmoCcu_HallStatus.StartCtr == 1u)
  {
    /* Start: */
    /* Do not calculate difference time and speed */
  }
  else
  {    
    /* Calculate difference time */
    DiffTime = Time - EmoCcu_HallStatus.EventTime;

    /* Calculate speed */
    Speed = (uint16)(SPEED_FROM_COMM_PERIOD_NUM / DiffTime);
    EmoCcu_HallStatus.Speed = Speed;

    if(EmoCcu_HallStatus.StartCtr == 2u)
    {
      /* Initialize average speed */
      EmoCcu_HallStatus.Speed = Mat_ExeSimpleLp(&EmoCcu_HallStatus.SpeedLong, Speed, 65535u);

      /* Set run mode */
      Emo_SetMotorState(EMO_MOTOR_STATE_RUN);
    }
    else /* (EmoCcu_HallStatus.StartCtr >= 2u) */
    {
      /* Calculate average speed */
      EmoCcu_HallStatus.Speed = Mat_ExeSimpleLp(&EmoCcu_HallStatus.SpeedLong, Speed, POS_SPEED_LP_COEF);
    }
    if(Speed >= EmoCcu_HallStatus.DelayMinSpeed)
    {
      /* Minimum speed reached: */
      /* Set T13 period to Hall delay time, limit to minimum = Hall filter time */
      DelayTime = (uint16)(((((uint32)DiffTime) * EmoCcu_HallStatus.DelayAngle) + 30u) / 60u);
      if(DelayTime < T13_HALL_FILTER_TIME_TICKS)
      { 
        DelayTime = T13_HALL_FILTER_TIME_TICKS;
      }        
      CCU6_LoadPeriodRegister_T13_Tick(DelayTime);
      CCU6_EnableST_T13();
      EmoCcu_HallStatus.DelayTime = DelayTime;
    }
  }
  EmoCcu_HallStatus.EventTime = Time;
  
} /* End of EmoCcu_HandleHallEvent */


/** \brief Initializes Hall status parameters.
 *
 * \return None
 *
 * \ingroup emo_ccu_api
 */
void EmoCcu_InitHallPar(void)
{
  /* Initialize BC Hall parameters */
  EmoCcu_HallStatus.DelayAngle = (BCHALL_ANGLE_DELAY_EN == 0)? ((uint8)0) : ((uint8)BCHALL_DELAY_ANGLE);
  EmoCcu_HallStatus.DelayMinSpeed = BCHALL_DELAY_MINSPEED;

} /* End of EmoCcu_InitHallPar */

/** \brief Initializes BC Hall status variables.
 *
 * \return None
 *
 * \ingroup emo_ccu_api
 */
void EmoCcu_InitHallVar(void)
{
  /* Initialize BC Hall variables */
  EmoCcu_HallStatus.SpeedLong = 0u;
  EmoCcu_HallStatus.EventTime = 0u;
  EmoCcu_HallStatus.DelayTime = T13_HALL_FILTER_TIME_TICKS;
  EmoCcu_HallStatus.Speed = 0u;
  EmoCcu_HallStatus.StartCtr = 0u;
  
	/* EmoCcu_HallStatus.DirIdx is kept. */

} /* End of EmoCcu_InitHallVar */



