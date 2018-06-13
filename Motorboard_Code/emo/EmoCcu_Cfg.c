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
**                      Includes                                              **
*******************************************************************************/
#include "EmoCcu.h"

/******************************************************************************
**                      Private Macro Definitions                            **
*******************************************************************************/

#define Ccu6_SetPtns(CURHS, EXPHS, MCMPS) \
  ( (((uint32)(MCMPS)) << 0u) | \
  (((uint32)(EXPHS)) << 8u) | \
  (((uint32)(CURHS)) << 11U ) )

/*******************************************************************************
**                      Global Constant Definitions to be changed             **
*******************************************************************************/
const TEmoCcu_Cfg EmoCcu_Cfg =
{
  /* HallOutPtns[16] - Hall and output patterns
   * Value = f(current Hall pattern, expected Hall pattern, output pattern)
   */
#if (BCHALL_OFFSET_60DEGREE_EN == 0) 
  { 
    (uint16)Ccu6_SetPtns(0, 0, 0x00), /* Hall pattern=0, forward direction (error) */
    (uint16)Ccu6_SetPtns(1, 3, 0x31), /* Hall pattern=1, forward direction */
    (uint16)Ccu6_SetPtns(2, 6, 0x07), /* Hall pattern=2, forward direction */
    (uint16)Ccu6_SetPtns(3, 2, 0x34), /* Hall pattern=3, forward direction */
    (uint16)Ccu6_SetPtns(4, 5, 0x1C), /* Hall pattern=4, forward direction */
    (uint16)Ccu6_SetPtns(5, 1, 0x0D), /* Hall pattern=5, forward direction */
    (uint16)Ccu6_SetPtns(6, 4, 0x13), /* Hall pattern=6, forward direction */
    (uint16)Ccu6_SetPtns(0, 0, 0x00), /* Hall pattern=7, forward direction (error) */
    (uint16)Ccu6_SetPtns(0, 0, 0x00), /* Hall pattern=0, reverse direction (error) */
    (uint16)Ccu6_SetPtns(1, 5, 0x13), /* Hall pattern=1, reverse direction */
    (uint16)Ccu6_SetPtns(2, 3, 0x0D), /* Hall pattern=2, reverse direction */
    (uint16)Ccu6_SetPtns(3, 1, 0x1C), /* Hall pattern=3, reverse direction */
    (uint16)Ccu6_SetPtns(4, 6, 0x34), /* Hall pattern=4, reverse direction */
    (uint16)Ccu6_SetPtns(5, 4, 0x07), /* Hall pattern=5, reverse direction */
    (uint16)Ccu6_SetPtns(6, 2, 0x31), /* Hall pattern=6, reverse direction */
    (uint16)Ccu6_SetPtns(0, 0, 0x00)  /* Hall pattern=7, reverse direction (error) */
  },
#else /* (BCHALL_OFFSET_60DEGREE_EN == 1) */
  { 
    (uint16)Ccu6_SetPtns(0, 0, 0x00), /* Hall pattern=0, forward direction (error) */
    (uint16)Ccu6_SetPtns(1, 3, 0x0D), /* Hall pattern=1, forward direction */
    (uint16)Ccu6_SetPtns(2, 6, 0x34), /* Hall pattern=2, forward direction */
    (uint16)Ccu6_SetPtns(3, 2, 0x31), /* Hall pattern=3, forward direction */
    (uint16)Ccu6_SetPtns(4, 5, 0x13), /* Hall pattern=4, forward direction */
    (uint16)Ccu6_SetPtns(5, 1, 0x1C), /* Hall pattern=5, forward direction */
    (uint16)Ccu6_SetPtns(6, 4, 0x07), /* Hall pattern=6, forward direction */
    (uint16)Ccu6_SetPtns(0, 0, 0x00), /* Hall pattern=7, forward direction (error) */
    (uint16)Ccu6_SetPtns(0, 0, 0x00), /* Hall pattern=0, reverse direction (error) */
    (uint16)Ccu6_SetPtns(1, 5, 0x07), /* Hall pattern=1, reverse direction */
    (uint16)Ccu6_SetPtns(2, 3, 0x1C), /* Hall pattern=2, reverse direction */
    (uint16)Ccu6_SetPtns(3, 1, 0x13), /* Hall pattern=3, reverse direction */
    (uint16)Ccu6_SetPtns(4, 6, 0x31), /* Hall pattern=4, reverse direction */
    (uint16)Ccu6_SetPtns(5, 4, 0x34), /* Hall pattern=5, reverse direction */
    (uint16)Ccu6_SetPtns(6, 2, 0x0D), /* Hall pattern=6, reverse direction */
    (uint16)Ccu6_SetPtns(0, 0, 0x00)  /* Hall pattern=7, reverse direction (error) */
  },
#endif /* (BCHALL_OFFSET_60DEGREE_EN == 1) */

  /* T12Moden - T12 modulation enable patterns 
   * Table value = 0x80(MCMEN) + pattern for T12MODEN
   * Pattern = COUT62*32 + CC62*16 + COUT61*8 + CC61*4 + COUT60*2 + CC60 */
#if (BCHALL_OFFSET_60DEGREE_EN == 0) 
  {
    (uint8)(0x00),        /* Hall pattern=0, forward direction (error) */
    (uint8)(0x80 + 0x30), /* Hall pattern=1, forward direction */
    (uint8)(0x80 + 0x03), /* Hall pattern=2, forward direction */
    (uint8)(0x80 + 0x33), /* Hall pattern=3, forward direction */
    (uint8)(0x80 + 0x0C), /* Hall pattern=4, forward direction */
    (uint8)(0x80 + 0x3C), /* Hall pattern=5, forward direction */
    (uint8)(0x80 + 0x0F), /* Hall pattern=6, forward direction */
    (uint8)(0x00),        /* Hall pattern=7, forward direction (error) */
    (uint8)(0x00),        /* Hall pattern=0, reverse direction (error) */
    (uint8)(0x80 + 0x03), /* Hall pattern=1, reverse direction */
    (uint8)(0x80 + 0x0C), /* Hall pattern=2, reverse direction */
    (uint8)(0x80 + 0x0F), /* Hall pattern=3, reverse direction */
    (uint8)(0x80 + 0x30), /* Hall pattern=4, reverse direction */
    (uint8)(0x80 + 0x33), /* Hall pattern=5, reverse direction */
    (uint8)(0x80 + 0x3C), /* Hall pattern=6, reverse direction */
    (uint8)(0x00)         /* Hall pattern=7, reverse direction (error) */
  },
#else /* (BCHALL_OFFSET_60DEGREE_EN == 1) */
  {
    (uint8)(0x00),        /* Hall pattern=0, forward direction (error) */
    (uint8)(0x80 + 0x3C), /* Hall pattern=1, forward direction */
    (uint8)(0x80 + 0x33), /* Hall pattern=2, forward direction */
    (uint8)(0x80 + 0x30), /* Hall pattern=3, forward direction */
    (uint8)(0x80 + 0x0F), /* Hall pattern=4, forward direction */
    (uint8)(0x80 + 0x0C), /* Hall pattern=5, forward direction */
    (uint8)(0x80 + 0x03), /* Hall pattern=6, forward direction */
    (uint8)(0x00),        /* Hall pattern=7, forward direction (error) */
    (uint8)(0x00),        /* Hall pattern=0, reverse direction (error) */
    (uint8)(0x80 + 0x33), /* Hall pattern=1, reverse direction */
    (uint8)(0x80 + 0x0F), /* Hall pattern=2, reverse direction */
    (uint8)(0x80 + 0x03), /* Hall pattern=3, reverse direction */
    (uint8)(0x80 + 0x3C), /* Hall pattern=4, reverse direction */
    (uint8)(0x80 + 0x30), /* Hall pattern=5, reverse direction */
    (uint8)(0x80 + 0x0C), /* Hall pattern=6, reverse direction */
    (uint8)(0x00)         /* Hall pattern=7, reverse direction (error) */
  },
#endif /* (BCHALL_OFFSET_60DEGREE_EN == 1) */
}; /* End of EmoCcu_Cfg */

