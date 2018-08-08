/*sha256=5EC37B09FF213A320B64DA355A31E05C9C9A90E2FD378483586CA111FA17B834*/
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
created on:Wed Aug 8 14:22:11 2018
------------------------------------------------------------------------------*/

#ifndef _SCU_DEFINES_H
#define _SCU_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef SCU_XML_VERSION
  #define SCU_XML_VERSION 10300
#endif

#ifndef SCUPM_WDT1_PERIOD
  #define SCUPM_WDT1_PERIOD 1008
#endif

#ifndef SCUPM_WDT1_PERIOD_EDIT
  #define SCUPM_WDT1_PERIOD_EDIT 1008
#endif

/*SCUPM_WDT1_TRIG: 63*/
#ifndef SCUPM_WDT1_TRIG
  #define SCUPM_WDT1_TRIG (0x3Fu)
#endif

#ifndef SCUPM_WDT1_TRIGGER
  #define SCUPM_WDT1_TRIGGER 699
#endif

/*SCU_APCLK1: 0*/
#ifndef SCU_APCLK1
  #define SCU_APCLK1 (0x0u)
#endif

/*SCU_APCLK2: 11*/
#ifndef SCU_APCLK2
  #define SCU_APCLK2 (0xBu)
#endif

/*SCU_APCLK_CTRL1: (1<<2)|(0<<7)|(0<<6)*/
#ifndef SCU_APCLK_CTRL1
  #define SCU_APCLK_CTRL1 (0x4u)
#endif

/*SCU_APCLK_CTRL2: (0<<2)*/
#ifndef SCU_APCLK_CTRL2
  #define SCU_APCLK_CTRL2 (0x0u)
#endif

#ifndef SCU_APCLK_FILT_CLK
  #define SCU_APCLK_FILT_CLK 2
#endif

#ifndef SCU_APCLK_MI_CLK
  #define SCU_APCLK_MI_CLK 24
#endif

/*SCU_AUTO_FSYS: 24000000*/
#ifndef SCU_AUTO_FSYS
  #define SCU_AUTO_FSYS (0x16E3600u)
#endif

#ifndef SCU_AUTO_FSYS_SEL
  #define SCU_AUTO_FSYS_SEL 0
#endif

/*SCU_BCON1: (0<<1)|0*/
#ifndef SCU_BCON1
  #define SCU_BCON1 (0x0u)
#endif

/*SCU_BCON2: (0<<1)|0*/
#ifndef SCU_BCON2
  #define SCU_BCON2 (0x0u)
#endif

#ifndef SCU_CFLASH_WPROT
  #define SCU_CFLASH_WPROT 0
#endif

#ifndef SCU_CFLASH_WPROT_PW
  #define SCU_CFLASH_WPROT_PW 0
#endif

#ifndef SCU_CKOUT_FREQ
  #define SCU_CKOUT_FREQ 24
#endif

/*SCU_CMCON1: (3<<4)|(1<<7)*/
#ifndef SCU_CMCON1
  #define SCU_CMCON1 (0xB0u)
#endif

/*SCU_COCON: (0<<7)|0|(0<<5)|(0<<6)|(0<<4)*/
#ifndef SCU_COCON
  #define SCU_COCON (0x0u)
#endif

#ifndef SCU_DFLASH_WPROT
  #define SCU_DFLASH_WPROT 0
#endif

#ifndef SCU_DFLASH_WPROT_PW
  #define SCU_DFLASH_WPROT_PW 0
#endif

/*SCU_DMASRCSEL: (0<<2)|(0<<3)*/
#ifndef SCU_DMASRCSEL
  #define SCU_DMASRCSEL (0x0u)
#endif

/*SCU_DMASRCSEL2: 0*/
#ifndef SCU_DMASRCSEL2
  #define SCU_DMASRCSEL2 (0x0u)
#endif

#ifndef SCU_EXINT1_FALLING_INT_EN
  #define SCU_EXINT1_FALLING_INT_EN 0
#endif

#ifndef SCU_EXINT1_RISING_INT_EN
  #define SCU_EXINT1_RISING_INT_EN 1
#endif

#ifndef SCU_EXINT2_FALLING_INT_EN
  #define SCU_EXINT2_FALLING_INT_EN 1
#endif

#ifndef SCU_EXINT2_RISING_INT_EN
  #define SCU_EXINT2_RISING_INT_EN 1
#endif

#ifndef SCU_FSYS
  #define SCU_FSYS 2.4e+07
#endif

/*SCU_GPT12PISEL: 0*/
#ifndef SCU_GPT12PISEL
  #define SCU_GPT12PISEL (0x0u)
#endif

/*SCU_IEN0: (1<<7)*/
#ifndef SCU_IEN0
  #define SCU_IEN0 (0x80u)
#endif

#ifndef SCU_INT_OSC
  #define SCU_INT_OSC 5
#endif

#ifndef SCU_INT_OSC_OVERRIDE_EN
  #define SCU_INT_OSC_OVERRIDE_EN 0
#endif

/*SCU_MODIEN3: (0<<4)|0*/
#ifndef SCU_MODIEN3
  #define SCU_MODIEN3 (0x0u)
#endif

/*SCU_MODIEN4: 1*/
#ifndef SCU_MODIEN4
  #define SCU_MODIEN4 (0x1u)
#endif

/*SCU_MODPISEL: (0<<7)|(0<<6)|3|(3<<2)|(1<<4)*/
#ifndef SCU_MODPISEL
  #define SCU_MODPISEL (0x1Fu)
#endif

/*SCU_MODPISEL1: (0<<6)|(0<<7)|0*/
#ifndef SCU_MODPISEL1
  #define SCU_MODPISEL1 (0x0u)
#endif

/*SCU_MODPISEL2: 1|(0<<4)|(0<<2)|(2<<6)*/
#ifndef SCU_MODPISEL2
  #define SCU_MODPISEL2 (0x81u)
#endif

/*SCU_MODPISEL3: (0<<6)*/
#ifndef SCU_MODPISEL3
  #define SCU_MODPISEL3 (0x0u)
#endif

/*SCU_OSC_CON: 144*/
#ifndef SCU_OSC_CON
  #define SCU_OSC_CON (0x90u)
#endif

#ifndef SCU_PINSEL
  #define SCU_PINSEL 0
#endif

/*SCU_PLL_CON: (11<<4)*/
#ifndef SCU_PLL_CON
  #define SCU_PLL_CON (0xB0u)
#endif

#ifndef SCU_PLL_fPLL
  #define SCU_PLL_fPLL 24
#endif

/*SCU_WDTCON: (0<<2)|0|(0<<5)*/
#ifndef SCU_WDTCON
  #define SCU_WDTCON (0x0u)
#endif

/*SCU_WDTRL: 1*/
#ifndef SCU_WDTRL
  #define SCU_WDTRL (0x1u)
#endif

#ifndef SCU_WDTWINB
  #define SCU_WDTWINB 128
#endif

#ifndef SCU_WDT_TIME_SEL
  #define SCU_WDT_TIME_SEL 0
#endif

/*SCU_WDT_TIME_TICK: 1*/
#ifndef SCU_WDT_TIME_TICK
  #define SCU_WDT_TIME_TICK (0x1u)
#endif

#ifndef SCU_WDT_TIME_TIME
  #define SCU_WDT_TIME_TIME 1
#endif

#ifndef SCU_XTAL_EN
  #define SCU_XTAL_EN 0
#endif

#ifndef SCU_XTAL_FREQ
  #define SCU_XTAL_FREQ 5
#endif


#endif
