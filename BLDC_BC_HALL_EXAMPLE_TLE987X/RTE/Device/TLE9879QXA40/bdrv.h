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
/* See bdrv.c */

#ifndef _BDR_H
#define _BDR_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "bdrv_defines.h"

/*******************************************************************************
**                        Global Macro Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef enum _TBdrv_Ch_Cfg
{
  Ch_Off = 0U, /**< \brief channel disabled                           */
  Ch_En = 1U,  /**< \brief channel enabled                            */
  Ch_PWM = 3U, /**< \brief channel enabled with PWM (CCU6 connection) */
  Ch_On = 5U,  /**< \brief channel enabled and static on              */
  Ch_DCS = 9U  /**< \brief channel enabled with Diag.-Current Source  */
} TBdrv_Ch_Cfg;

typedef enum _TBdrv_Ch
{
  LS1 = 0U,
  LS2 = 1U,
  HS1 = 2U,
  HS2 = 3U
#if (UC_SERIES == TLE987)
    ,
  LS3 = 4U,
  HS3 = 5U
#endif
} TBdrv_Ch;

typedef enum _TBdrv_Sts
{
  LS1_DS = 0x00000001U,
  LS2_DS = 0x00000002U,
  HS1_DS = 0x00000004U,
  HS2_DS = 0x00000008U,
  LS1_OC = 0x00000400U,
  LS2_OC = 0x00000800U,
  HS1_OC = 0x00001000U,
  HS2_OC = 0x00002000U
#if (UC_SERIES == TLE987)
    ,
  LS3_DS = 0x00000010U,
  HS3_DS = 0x00000020U,
  LS3_OC = 0x00004000U,
  HS3_OC = 0x00008000U
#endif
} TBdrv_Sts;

typedef enum _TBdrv_Ch_Int
{
  Int_Off = 0U,  /**< \brief all interrupts disable                         */
  Int_DS = 1U,   /**< \brief Drain-Source interrupt enable                  */
  Int_OC = 2U,   /**< \brief Over-Current interrupt enable                  */
  Int_DS_OC = 3U /**< \brief Drain-Source and Over-Current interrupt enable */
} TBdrv_Ch_Int;

#ifdef TLE987
#define BDRV_IRQ_BITS 0x00003C0F
#else
#define BDRV_IRQ_BITS 0x0000FC3F
#endif

/* BDRV Interrupt Enable/Disable Macros */
#define BDRV_HS1_OC_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 12u)
#define BDRV_LS1_OC_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 10u)
#define BDRV_HS2_OC_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 13u)
#define BDRV_LS2_OC_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 11u)
#if (UC_SERIES == TLE987)               
  #define BDRV_HS3_OC_Int_Clr()      (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 15u)
  #define BDRV_LS3_OC_Int_Clr()      (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 14u)
#endif                                  
#define BDRV_HS1_DS_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 2u)
#define BDRV_LS1_DS_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 0u)
#define BDRV_HS2_DS_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 3u)
#define BDRV_LS2_DS_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 1u)
#if (UC_SERIES == TLE987)               
  #define BDRV_HS3_DS_Int_Clr()      (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 5u)
  #define BDRV_LS3_DS_Int_Clr()      (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 4u)
#endif                                  
#define BDRV_VCP_LO_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 16u)

/* BDRV Interrupt Enable/Disable Macros */
#define BDRV_HS1_OC_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.HS1_OC_IE = 1u)
#define BDRV_HS1_OC_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.HS1_OC_IE = 0u)
#define BDRV_LS1_OC_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.LS1_OC_IE = 1u)
#define BDRV_LS1_OC_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.LS1_OC_IE = 0u)
#define BDRV_HS2_OC_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.HS2_OC_IE = 1u)
#define BDRV_HS2_OC_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.HS2_OC_IE = 0u)
#define BDRV_LS2_OC_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.LS2_OC_IE = 1u)
#define BDRV_LS2_OC_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.LS2_OC_IE = 0u)
#if (UC_SERIES == TLE987)               
  #define BDRV_HS3_OC_Int_En()      (SCUPM->BDRV_IRQ_CTRL.bit.HS3_OC_IE = 1u)
  #define BDRV_HS3_OC_Int_Dis()     (SCUPM->BDRV_IRQ_CTRL.bit.HS3_OC_IE = 0u)
  #define BDRV_LS3_OC_Int_En()      (SCUPM->BDRV_IRQ_CTRL.bit.LS3_OC_IE = 1u)
  #define BDRV_LS3_OC_Int_Dis()     (SCUPM->BDRV_IRQ_CTRL.bit.LS3_OC_IE = 0u)
#endif                                  
#define BDRV_HS1_DS_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.HS1_DS_IE = 1u)
#define BDRV_HS1_DS_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.HS1_DS_IE = 0u)
#define BDRV_LS1_DS_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.LS1_DS_IE = 1u)
#define BDRV_LS1_DS_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.LS1_DS_IE = 0u)
#define BDRV_HS2_DS_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.HS2_DS_IE = 1u)
#define BDRV_HS2_DS_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.HS2_DS_IE = 0u)
#define BDRV_LS2_DS_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.LS2_DS_IE = 1u)
#define BDRV_LS2_DS_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.LS2_DS_IE = 0u)
#if (UC_SERIES == TLE987)               
  #define BDRV_HS3_DS_Int_En()      (SCUPM->BDRV_IRQ_CTRL.bit.HS3_DS_IE = 1u)
  #define BDRV_HS3_DS_Int_Dis()     (SCUPM->BDRV_IRQ_CTRL.bit.HS3_DS_IE = 0u)
  #define BDRV_LS3_DS_Int_En()      (SCUPM->BDRV_IRQ_CTRL.bit.LS3_DS_IE = 1u)
  #define BDRV_LS3_DS_Int_Dis()     (SCUPM->BDRV_IRQ_CTRL.bit.LS3_DS_IE = 0u)
#endif                                  
#define BDRV_VCP_LO_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.VCP_LOWTH2_IE = 1u)
#define BDRV_VCP_LO_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.VCP_LOWTH2_IE = 0u)

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

void BDRV_Init(void);

#if (UC_SERIES == TLE987)
void BDRV_Set_Bridge(TBdrv_Ch_Cfg LS1_Cfg,
                     TBdrv_Ch_Cfg HS1_Cfg,
                     TBdrv_Ch_Cfg LS2_Cfg,
                     TBdrv_Ch_Cfg HS2_Cfg, 
                     TBdrv_Ch_Cfg LS3_Cfg, 
                     TBdrv_Ch_Cfg HS3_Cfg);
#else
void BDRV_Set_Bridge(TBdrv_Ch_Cfg LS1_Cfg,
                     TBdrv_Ch_Cfg HS1_Cfg, 
                     TBdrv_Ch_Cfg LS2_Cfg, 
                     TBdrv_Ch_Cfg HS2_Cfg);
#endif

void BDRV_Set_Channel(TBdrv_Ch BDRV_Ch, TBdrv_Ch_Cfg Ch_Cfg);

void BDRV_Clr_Sts(uint32 Sts_Bit);

void BDRV_Set_Int_Channel(TBdrv_Ch BDRV_Ch, TBdrv_Ch_Int Ch_Int);

bool BDRV_Diag_OpenLoad(void);

#endif
