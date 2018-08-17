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
/* See timer2x.c */

#ifndef TIMER2X_H
#define TIMER2X_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "timer2x_defines.h"

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef enum
{
  TIMER2_T2IN_P00 = 0u, 
  TIMER2_T2IN_P25 = 1u
} TTIMER2_T2IN_Pxx;

typedef enum
{
  TIMER2_T2EX_LIN = 0u,
  TIMER2_T2EX_P12 = 1u,
  TIMER2_T2EX_CCU6_CC60 = 2u,  
} TTIMER2_T2EX_Pxx;

typedef enum
{
  TIMER21_T2IN_P01 = 0u, 
  TIMER21_T2IN_P11 = 1u,
  TIMER21_T2IN_P04 = 2u
} TTIMER21_T2IN_Pxx;

typedef enum
{
  TIMER21_T2EX_P02 = 0u,
  TIMER21_T2EX_P14 = 1u,
  TIMER21_T2EX_P23 = 2u,
  TIMER21_T2EX_P12 = 3u,
  TIMER21_T2EX_CCU6_COUT60 = 4u
} TTIMER21_T2EX_Pxx;

typedef enum
{
  TIMER2x_Clk_Div_1   = 0u,
  TIMER2x_Clk_Div_2   = 1u,
  TIMER2x_Clk_Div_4   = 2u,
  TIMER2x_Clk_Div_8   = 3u,  
  TIMER2x_Clk_Div_16  = 4u,
  TIMER2x_Clk_Div_32  = 5u,
  TIMER2x_Clk_Div_64  = 6u,
  TIMER2x_Clk_Div_128 = 7u  
} TIMER2x_Clock_Prescaler;

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
/* TIMER2 macros */
#define TIMER2_Clk_Prescaler_En()        (TIMER2->T2MOD.reg |= (uint8) (1u << 4u))
#define TIMER2_Clk_Prescaler_Dis()       (TIMER2->T2MOD.reg &= (uint8)~(1u << 4u))
#define TIMER2_Clk_Prescaler_Sel(t2pre)  (TIMER2->T2MOD.bit.T2PRE = (uint16)(t2pre & 7u))
#define TIMER2_Clk_Prescaler_Get()      ((TIMER2->T2MOD.reg >> 1u) & 7u)

#define TIMER2_Overflow_Sts()           ((TIMER2->T2CON.reg >> 7u) & 1u)
#define TIMER2_External_Sts()           ((TIMER2->T2CON.reg >> 6u) & 1u)

#define TIMER2_External_Ctrl_En()        (TIMER2->T2CON.reg |= (uint8) (1u << 3u))
#define TIMER2_External_Ctrl_Dis()       (TIMER2->T2CON.reg &= (uint8)~(1u << 3u))

#define TIMER2_Reload_Capture_Rising_Sel() \
                                         (TIMER2->T2MOD.reg |= (uint8) (1u << 5u))
#define TIMER2_Reload_Capture_Falling_Sel() \
                                         (TIMER2->T2MOD.reg &= (uint8)~(1u << 5u))

#define TIMER2_ExtStart_Rising_Sel() \
                                         (TIMER2->T2MOD.reg |= (uint8) (1u << 7u))
#define TIMER2_ExtStart_Falling_Sel()\
                                         (TIMER2->T2MOD.reg &= (uint8)~(1u << 7u))

#define TIMER2_UpDownCount_En()          (TIMER2->T2MOD.reg |= (uint8) (1u << 0u))
#define TIMER2_UpDownCount_Dis()         (TIMER2->T2MOD.reg &= (uint8)~(1u << 0u))

#define TIMER2_Mode_Capture_Set()        (TIMER2->T2CON.reg |= (uint8) (1u << 0u))
#define TIMER2_Mode_Reload_Set()         (TIMER2->T2CON.reg &= (uint8)~(1u << 0u))

#define TIMER2_Mode_Counter_Set()        (TIMER2->T2CON.reg |= (uint8) (1u << 1u))
#define TIMER2_Mode_Timer_Set()          (TIMER2->T2CON.reg &= (uint8)~(1u << 1u))

#define TIMER2_Value_Get()               (((uint16)TIMER2->T2H.reg << 8u) | \
                                          ((uint16)TIMER2->T2L.reg & 0xFFu))
#define TIMER2_Value_Set(t2)             {(TIMER2->T2H.reg = ((t2) >> 8u) & 0xFFu); \
                                          (TIMER2->T2L.reg = ((t2) & 0xFFu));}
#define TIMER2_Capture_Value_Get()       (((uint16)TIMER2->RC2H.reg << 8u) | \
                                          ((uint16)TIMER2->RC2L.reg & 0xFFu))
#define TIMER2_Reload_Value_Set(t2)      {(TIMER2->RC2H.reg = ((t2) >> 8u) & 0xFFu); \
                                          (TIMER2->RC2L.reg = ((t2) & 0xFFu));}

/* TIMER21 macros */
#define TIMER21_Clk_Prescaler_En()        (TIMER21->T2MOD.reg |= (uint8) (1u << 4u))
#define TIMER21_Clk_Prescaler_Dis()       (TIMER21->T2MOD.reg &= (uint8)~(1u << 4u))
#define TIMER21_Clk_Prescaler_Sel(t2pre)  (TIMER21->T2MOD.bit.T2PRE = (uint16)(t2pre & 7u))
#define TIMER21_Clk_Prescaler_Get()      ((TIMER21->T2MOD.reg >> 1u) & 7u)

#define TIMER21_Overflow_Sts()           ((TIMER21->T2CON.reg >> 7u) & 1u)
#define TIMER21_External_Sts()           ((TIMER21->T2CON.reg >> 6u) & 1u)

#define TIMER21_ExternalCtrl_En()         (TIMER21->T2CON.reg |= (uint8) (1u << 3u))
#define TIMER21_ExternalCtrl_Dis()        (TIMER21->T2CON.reg &= (uint8)~(1u << 3u))

#define TIMER21_ReloadCapture_RisingEdge_Set() \
                                          (TIMER21->T2MOD.reg |= (uint8) (1u << 5u))
#define TIMER21_ReloadCapture_FallingEdge_Set() \
                                          (TIMER21->T2MOD.reg &= (uint8)~(1u << 5u))

#define TIMER21_ExtStart_RisingEdge_Set() \
                                          (TIMER21->T2MOD.reg |= (uint8) (1u << 7u))
#define TIMER21_ExtStart_FallingEdge_Set()\
                                          (TIMER21->T2MOD.reg &= (uint8)~(1u << 7u))

#define TIMER21_UpDownCount_En()          (TIMER21->T2MOD.reg |= (uint8) (1u << 0u))
#define TIMER21_UpDownCount_Dis()         (TIMER21->T2MOD.reg &= (uint8)~(1u << 0u))

#define TIMER21_Mode_Capture_Set()        (TIMER21->T2CON.reg |= (uint8) (1u << 0u))
#define TIMER21_Mode_Reload_Set()         (TIMER21->T2CON.reg &= (uint8)~(1u << 0u))

#define TIMER21_Mode_Counter_Set()        (TIMER21->T2CON.reg |= (uint8) (1u << 1u))
#define TIMER21_Mode_Timer_Set()          (TIMER21->T2CON.reg &= (uint8)~(1u << 1u))

/* TIMER2x Interrupt Clear Macros */
#define TIMER2_Overflow_Int_Clr()         (TIMER2->T2ICLR.reg = (uint8)1u << 7u)
#define TIMER2_External_Int_Clr()         (TIMER2->T2ICLR.reg = (uint8)1u << 6u)
#define TIMER21_Overflow_Int_Clr()        (TIMER21->T2ICLR.reg = (uint8)1u << 7u)
#define TIMER21_External_Int_Clr()        (TIMER21->T2ICLR.reg = (uint8)1u << 6u)

/* TIMER2x Interrupt Enable/Disable Macros */
#define TIMER2_Overflow_Int_En()          (TIMER2->T2CON1.bit.TF2EN = 1u)
#define TIMER2_Overflow_Int_Dis()         (TIMER2->T2CON1.bit.TF2EN = 0u)
#define TIMER2_External_Int_En()          (TIMER2->T2CON1.bit.EXF2EN = 1u)
#define TIMER2_External_Int_Dis()         (TIMER2->T2CON1.bit.EXF2EN = 0u)
#define TIMER21_Overflow_Int_En()         (TIMER21->T2CON1.bit.TF2EN = 1u)
#define TIMER21_Overflow_Int_Dis()        (TIMER21->T2CON1.bit.TF2EN = 0u)
#define TIMER21_External_Int_En()         (TIMER21->T2CON1.bit.EXF2EN = 1u)
#define TIMER21_External_Int_Dis()        (TIMER21->T2CON1.bit.EXF2EN = 0u)

#define TIMER21_Value_Get()               (((uint16)TIMER21->T2H.reg << 8u) | \
                                          ((uint16)TIMER21->T2L.reg & 0xFFu))
#define TIMER21_Value_Set(t2)             {(TIMER21->T2H.reg = ((t2) >> 8u) & 0xFFu); \
                                           (TIMER21->T2L.reg = ((t2) & 0xFFu));}
#define TIMER21_Capture_Value_Get()       (((uint16)TIMER21->RC2H.reg << 8u) | \
                                           ((uint16)TIMER21->RC2L.reg & 0xFFu))
#define TIMER21_Reload_Value_Set(t2)       {(TIMER21->RC2H.reg = ((t2) >> 8u) & 0xFFu); \
                                           (TIMER21->RC2L.reg = ((t2) & 0xFFu));}

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void TIMER2_Init(void);
__STATIC_INLINE void TIMER2_Start(void);
__STATIC_INLINE void TIMER2_Stop(void);
__STATIC_INLINE void TIMER2_ExtStart(void);
__STATIC_INLINE void TIMER2_ExtStop(void);
__STATIC_INLINE uint16 TIMER2_Get_Count(void);
__STATIC_INLINE uint16 TIMER2_Get_Capture(void);
__STATIC_INLINE void TIMER2_Clear_Count(void);
__STATIC_INLINE void TIMER2_Set_Reload(uint16 value);
__STATIC_INLINE void TIMER2_Select_T2IN(TTIMER2_T2IN_Pxx pinsel);
__STATIC_INLINE void TIMER2_Select_T2EX(TTIMER2_T2EX_Pxx pinsel);
bool TIMER2_Interval_Timer_Setup(uint32 timer_interval_us);

void TIMER21_Init(void);
__STATIC_INLINE void TIMER21_Start(void);
__STATIC_INLINE void TIMER21_Stop(void);
__STATIC_INLINE void TIMER21_ExtStart(void);
__STATIC_INLINE void TIMER21_ExtStop(void);
__STATIC_INLINE uint16 TIMER21_Get_Count(void);
__STATIC_INLINE uint16 TIMER21_Get_Capture(void);
__STATIC_INLINE void TIMER21_Clear_Count(void);
__STATIC_INLINE void TIMER21_Set_Reload(uint16 value);
__STATIC_INLINE void TIMER21_Select_T2IN(TTIMER21_T2IN_Pxx pinsel);
__STATIC_INLINE void TIMER21_Select_T2EX(TTIMER21_T2EX_Pxx pinsel);
bool TIMER21_Interval_Timer_Setup(uint32 timer_interval_us);

/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/
/** \brief starts the TIMER2 by software
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_Start(void)
{
  TIMER2->T2CON.bit.TR2 = 1u;
}

/** \brief stops the TIMER2 by software
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_Stop(void)
{
  TIMER2->T2CON.bit.TR2 = 0u;
}

/** \brief prepares TIMER2 to be started externally
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_ExtStart(void)
{
  TIMER2->T2MOD.bit.T2RHEN = 1u;
}

/** \brief disable TIMER2 to be started externally
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_ExtStop(void)
{
  TIMER2->T2MOD.bit.T2RHEN = 0u;
}

/** \brief reads the TIMER2 count value
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE uint16 TIMER2_Get_Count(void)
{
  return (((uint16) TIMER2->T2H.reg << 8u) | ((uint16) TIMER2->T2L.reg & 0xFFu));
}

/** \brief reads the TIMER2 capture value
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE uint16 TIMER2_Get_Capture(void)
{
  return (((uint16) TIMER2->RC2H.reg << 8u) | 
          ((uint16) TIMER2->RC2L.reg & 0xFFu));
}

/** \brief clears the TIMER2 count value
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_Clear_Count(void)
{
  TIMER2->T2H.reg = (uint8) 0u;
  TIMER2->T2L.reg = (uint8) 0u;
}

/** \brief sets TIMER2 reload value
 *
 * \param[in] reload value in ticks
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_Set_Reload(uint16 value)
{
  TIMER2->RC2H.reg = (uint8)(value >> 8u);
  TIMER2->RC2L.reg = (uint8)(value & 0xFFu);
}

/** \brief sets TIMER2 T2IN Pin
 *
 * \param[in] Pin select, TIMER2_T2IN_Pxy
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_Select_T2IN(TTIMER2_T2IN_Pxx pinsel)
{
  SCU->MODPISEL2.bit.T2IS = pinsel;
}

/** \brief sets TIMER2 T2EX Pin
 *
 * \param[in] Pin select, TIMER2_T2EX_Pxy
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER2_Select_T2EX(TTIMER2_T2EX_Pxx pinsel)
{
  if (pinsel < TIMER2_T2EX_CCU6_CC60)
  {
    SCU->MODPISEL1.bit.T2EXCON = 0u;
    SCU->MODPISEL2.bit.T2IS = (pinsel & 1u);
  }
  else
  {
    SCU->MODPISEL1.bit.T2EXCON = 1u;    
  }
}

/** \brief starts the TIMER21 by software
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER21_api
 */
__STATIC_INLINE void TIMER21_Start(void)
{
  TIMER21->T2CON.bit.TR2 = 1u;
}

/** \brief stops the TIMER21 by software
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER21_api
 */
__STATIC_INLINE void TIMER21_Stop(void)
{
  TIMER21->T2CON.bit.TR2 = 0u;
}

/** \brief prepares TIMER21 to be started externally
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER21_api
 */
__STATIC_INLINE void TIMER21_ExtStart(void)
{
  TIMER21->T2MOD.bit.T2RHEN = 1u;
}

/** \brief disable TIMER21 to be started externally
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER21_api
 */
__STATIC_INLINE void TIMER21_ExtStop(void)
{
  TIMER21->T2MOD.bit.T2RHEN = 0u;
}

/** \brief reads the TIMER21 count value
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER21_api
 */
__STATIC_INLINE uint16 TIMER21_Get_Count(void)
{
  return (((uint16) TIMER21->T2H.reg << 8u) | ((uint16) TIMER21->
      T2L.reg & 0xFFu));
}

/** \brief reads the TIMER21 capture value
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE uint16 TIMER21_Get_Capture(void)
{
  return (((uint16) TIMER21->RC2H.reg << 8u) | ((uint16) TIMER21->
      RC2L.reg & 0xFFu));
}

/** \brief clears the TIMER21 count value
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER21_Clear_Count(void)
{
  TIMER21->T2H.reg = (uint8) 0u;
  TIMER21->T2L.reg = (uint8) 0u;
}

/** \brief sets TIMER21 reload value
 *
 * \param[in] reload value in ticks
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER21_Set_Reload(uint16 value)
{
  TIMER21->RC2H.reg = (uint8)(value >> 8u);
  TIMER21->RC2L.reg = (uint8)(value & 0xFFu);
}

/** \brief sets TIMER21 T2IN Pin
 *
 * \param[in] Pin select, TIMER21_T2IN_Pxy
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER21_Select_T2IN(TTIMER21_T2IN_Pxx pinsel)
{
  SCU->MODPISEL2.bit.T21IS = pinsel;
}

/** \brief sets TIMER21 T2EX Pin
 *
 * \param[in] Pin select, TIMER21_T2EX_Pxy
 * \param[in] none
 * \return None
 *
 * \ingroup TIMER2x_api
 */
__STATIC_INLINE void TIMER21_Select_T2EX(TTIMER21_T2EX_Pxx pinsel)
{
  if (pinsel < TIMER21_T2EX_CCU6_COUT60)
  {
    SCU->MODPISEL1.bit.T21EXCON = 0u;
    SCU->MODPISEL2.bit.T21IS = (pinsel & 3u);
  }
  else
  {
    SCU->MODPISEL1.bit.T21EXCON = 1u;    
  }
}

#endif
