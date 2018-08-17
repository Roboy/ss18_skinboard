/*sha256=1C60B011F39D512915AAB2AB838872AF978001A1D285B5EE0212065C914516AC*/
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

/*------------------------------------------------------------------------------
IFXConfigWizard output file
created on:Fri Aug 10 16:31:52 2018
------------------------------------------------------------------------------*/

#ifndef _INT_DEFINES_H
#define _INT_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef INT_XML_VERSION
  #define INT_XML_VERSION 10300
#endif

#ifndef CPU_BUSFAULT_EN
  #define CPU_BUSFAULT_EN 0
#endif

#ifndef CPU_HARDFAULT_EN
  #define CPU_HARDFAULT_EN 0
#endif

#ifndef CPU_MEMMANAGE_EN
  #define CPU_MEMMANAGE_EN 0
#endif

/*CPU_NVIC_IPR0: (2<<4)|(2<<12)|(2<<20)|(2<<28)*/
#ifndef CPU_NVIC_IPR0
  #define CPU_NVIC_IPR0 (0x20202020u)
#endif

/*CPU_NVIC_IPR1: (2<<4)|(2<<12)|(2<<20)|(2<<28)*/
#ifndef CPU_NVIC_IPR1
  #define CPU_NVIC_IPR1 (0x20202020u)
#endif

/*CPU_NVIC_IPR2: (1<<4)|(1<<12)|(2<<20)|(2<<28)*/
#ifndef CPU_NVIC_IPR2
  #define CPU_NVIC_IPR2 (0x20201010u)
#endif

/*CPU_NVIC_IPR3: (0<<4)|(0<<12)|(1<<20)|(1<<28)*/
#ifndef CPU_NVIC_IPR3
  #define CPU_NVIC_IPR3 (0x10100000u)
#endif

/*CPU_NVIC_ISER0: 0|(0<<1)|(0<<2)|(1<<3)|(1<<4)|(0<<5)|(0<<6)|(0<<7)|(0<<8)|(1<\
<9)|(0<<10)|(1<<11)|(1<<12)|(1<<13)|(0<<14)|(1<<15)*/
#ifndef CPU_NVIC_ISER0
  #define CPU_NVIC_ISER0 (0xBA18u)
#endif

/*CPU_NVIC_SHPR3: (1<<28)*/
#ifndef CPU_NVIC_SHPR3
  #define CPU_NVIC_SHPR3 (0x10000000u)
#endif

#ifndef CPU_SYSTICK_EN
  #define CPU_SYSTICK_EN 1
#endif

#ifndef CPU_USAGEFAULT_EN
  #define CPU_USAGEFAULT_EN 0
#endif

#ifndef PMU_VDDC_OL_EN
  #define PMU_VDDC_OL_EN 0
#endif

#ifndef PMU_VDDC_OV_EN
  #define PMU_VDDC_OV_EN 0
#endif

/*PMU_VDDEXT_FAIL: 0|(0<<1)|(0<<2)*/
#ifndef PMU_VDDEXT_FAIL
  #define PMU_VDDEXT_FAIL (0x0u)
#endif

#ifndef PMU_VDDP_OL_EN
  #define PMU_VDDP_OL_EN 0
#endif

#ifndef PMU_VDDP_OV_EN
  #define PMU_VDDP_OV_EN 0
#endif

/*SCU_BDRV_IRQ_CTRL: (0<<16)|(0<<12)|(0<<10)|(0<<13)|(0<<11)|(0<<15)|(0<<14)|(0\
<<2)|0|(0<<3)|(0<<1)|(0<<5)|(0<<4)|(0<<20)|(0<<19)|(0<<18)|(0<<17)*/
#ifndef SCU_BDRV_IRQ_CTRL
  #define SCU_BDRV_IRQ_CTRL (0x0u)
#endif

/*SCU_DMAIEN1: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)*/
#ifndef SCU_DMAIEN1
  #define SCU_DMAIEN1 (0x0u)
#endif

/*SCU_DMAIEN2: (0<<1)|(0<<2)|(1<<3)|(1<<4)|(0<<5)*/
#ifndef SCU_DMAIEN2
  #define SCU_DMAIEN2 (0x18u)
#endif

/*SCU_EDCCON: 0|(0<<2)*/
#ifndef SCU_EDCCON
  #define SCU_EDCCON (0x0u)
#endif

/*SCU_EXICON0: 1|(0<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5)|(0<<6)|(0<<7)*/
#ifndef SCU_EXICON0
  #define SCU_EXICON0 (0x3Du)
#endif

/*SCU_GPT12IEN: 0|(0<<1)|(0<<2)|(0<<3)|(0<<5)|(0<<4)*/
#ifndef SCU_GPT12IEN
  #define SCU_GPT12IEN (0x0u)
#endif

/*SCU_MODIEN1: (0<<6)|(0<<7)|(0<<2)|(0<<1)|0*/
#ifndef SCU_MODIEN1
  #define SCU_MODIEN1 (0x0u)
#endif

/*SCU_MODIEN2: (0<<6)|(0<<7)|(1<<5)|(1<<2)|(0<<1)|0*/
#ifndef SCU_MODIEN2
  #define SCU_MODIEN2 (0x24u)
#endif

/*SCU_NMICON: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)*/
#ifndef SCU_NMICON
  #define SCU_NMICON (0x0u)
#endif

/*SCU_SYS_IRQ_CTRL: 0|(0<<1)|(0<<2)|(0<<17)|(0<<16)|(0<<19)|(0<<18)|(0<<21)|(0<\
<20)|(0<<13)|(0<<12)|(0<<14)|(0<<11)|(0<<10)|(0<<9)|(0<<8)|(0<<7)|(0<<6)*/
#ifndef SCU_SYS_IRQ_CTRL
  #define SCU_SYS_IRQ_CTRL (0x0u)
#endif

/*SCU_SYS_SUPPLY_IRQ_CTRL: (0<<5)|(0<<1)|(0<<4)|0|(0<<6)|(0<<2)|(0<<7)|(0<<3)*/
#ifndef SCU_SYS_SUPPLY_IRQ_CTRL
  #define SCU_SYS_SUPPLY_IRQ_CTRL (0x0u)
#endif


#endif
