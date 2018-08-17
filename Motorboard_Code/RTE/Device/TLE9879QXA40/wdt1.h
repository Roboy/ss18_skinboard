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
/* See wdt1.c */

#ifndef _WDT1_H
#define _WDT1_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "scu_defines.h"

/*******************************************************************************
**                      External Variable Declarations                        **
*******************************************************************************/
extern uint32 WD_Counter;

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
#define One_us ((uint32)SCU_FSYS / 1000000u)
#define SysTickRL ((sint32)SCU_FSYS / (sint32)SysTickFreq)

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/* SysTick 1kHz*/
#define SysTickFreq     1000u
/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void WDT1_Init(void);
void WDT1_Stop(void);
int WDT1_Service(void);
void WDT1_SOW_Service(uint32 NoOfSOW);
void Delay_us(uint32 delay_time_us);
__STATIC_INLINE void WDT1_Window_Count(void);

/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/

/** \brief WDT1 Window Counter
 *
 * \param none
 * \return None
 *
 * \ingroup wdt1_api
 */
__STATIC_INLINE void WDT1_Window_Count(void)
{
  WD_Counter++;
}

#endif
