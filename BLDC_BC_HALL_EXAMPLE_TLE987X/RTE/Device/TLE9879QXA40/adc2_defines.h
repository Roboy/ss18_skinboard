/*sha256=AAF49DFF8C642D8EC502E49EF61EC9A9FCE607DC7E82B96A7F0D7D525EE1BD6E*/
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
created on:Mon Aug 13 21:42:20 2018
------------------------------------------------------------------------------*/

#ifndef _ADC2_DEFINES_H
#define _ADC2_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef ADC2_XML_VERSION
  #define ADC2_XML_VERSION 10300
#endif

#ifndef ADC2_CH1_LOTH_VOLT
  #define ADC2_CH1_LOTH_VOLT 5.78
#endif

#ifndef ADC2_CH1_UPTH_VOLT
  #define ADC2_CH1_UPTH_VOLT 28
#endif

#ifndef ADC2_CH2_LOTH_VOLT
  #define ADC2_CH2_LOTH_VOLT 5.78
#endif

#ifndef ADC2_CH2_UPTH_VOLT
  #define ADC2_CH2_UPTH_VOLT 28
#endif

#ifndef ADC2_CH3_LOTH_VOLT
  #define ADC2_CH3_LOTH_VOLT 6
#endif

#ifndef ADC2_CH3_UPTH_VOLT
  #define ADC2_CH3_UPTH_VOLT 42
#endif

#ifndef ADC2_CH4_LOTH_VOLT
  #define ADC2_CH4_LOTH_VOLT 5.078
#endif

#ifndef ADC2_CH4_UPTH_VOLT
  #define ADC2_CH4_UPTH_VOLT 24.5
#endif

#ifndef ADC2_CH5_LOTH_VOLT
  #define ADC2_CH5_LOTH_VOLT 4.5
#endif

#ifndef ADC2_CH5_UPTH_VOLT
  #define ADC2_CH5_UPTH_VOLT 5.5
#endif

#ifndef ADC2_CH6_LOTH_VOLT
  #define ADC2_CH6_LOTH_VOLT 4.5
#endif

#ifndef ADC2_CH6_UPTH_VOLT
  #define ADC2_CH6_UPTH_VOLT 5.5
#endif

#ifndef ADC2_CH7_LOTH_VOLT
  #define ADC2_CH7_LOTH_VOLT 1.1
#endif

#ifndef ADC2_CH7_UPTH_VOLT
  #define ADC2_CH7_UPTH_VOLT 1.3
#endif

#ifndef ADC2_CH8_LOTH_VOLT
  #define ADC2_CH8_LOTH_VOLT 1.35
#endif

#ifndef ADC2_CH8_UPTH_VOLT
  #define ADC2_CH8_UPTH_VOLT 1.6
#endif

#ifndef ADC2_CH9_LOTH_DEG
  #define ADC2_CH9_LOTH_DEG 150
#endif

#ifndef ADC2_CH9_UPTH_DEG
  #define ADC2_CH9_UPTH_DEG 200
#endif

#ifndef ADC2_CLK
  #define ADC2_CLK 24
#endif

/*ADC2_CNT0_3_LOWER: (0<<11)|(0<<8)|(0<<19)|(0<<16)|(0<<27)|(0<<24)*/
#ifndef ADC2_CNT0_3_LOWER
  #define ADC2_CNT0_3_LOWER (0x0u)
#endif

/*ADC2_CNT0_3_UPPER: (0<<11)|(0<<8)|(0<<19)|(0<<16)|(0<<27)|(0<<24)*/
#ifndef ADC2_CNT0_3_UPPER
  #define ADC2_CNT0_3_UPPER (0x0u)
#endif

/*ADC2_CNT4_5_LOWER: (0<<3)|0|(0<<11)|(0<<8)*/
#ifndef ADC2_CNT4_5_LOWER
  #define ADC2_CNT4_5_LOWER (0x0u)
#endif

/*ADC2_CNT4_5_UPPER: (0<<3)|0|(0<<11)|(0<<8)*/
#ifndef ADC2_CNT4_5_UPPER
  #define ADC2_CNT4_5_UPPER (0x0u)
#endif

#ifndef ADC2_CONV_TIME
  #define ADC2_CONV_TIME 1.16667
#endif

/*ADC2_CTRL1: (0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)*/
#ifndef ADC2_CTRL1
  #define ADC2_CTRL1 (0x0u)
#endif

/*ADC2_CTRL2: 1|(7<<8)|(0<<2)*/
#ifndef ADC2_CTRL2
  #define ADC2_CTRL2 (0x701u)
#endif

/*ADC2_CTRL4: (0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)|(0<<8)|(0<<9)|(0<<10)|(0<<11)*/
#ifndef ADC2_CTRL4
  #define ADC2_CTRL4 (0x0u)
#endif

/*ADC2_CTRL_STS: (1<<17)*/
#ifndef ADC2_CTRL_STS
  #define ADC2_CTRL_STS (0x20000u)
#endif

/*ADC2_FILTCOEFF0_5: (0<<2)|(0<<4)|(0<<6)|(0<<8)|(0<<10)*/
#ifndef ADC2_FILTCOEFF0_5
  #define ADC2_FILTCOEFF0_5 (0x0u)
#endif

/*ADC2_FILT_LO_CTRL: (0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)*/
#ifndef ADC2_FILT_LO_CTRL
  #define ADC2_FILT_LO_CTRL (0x0u)
#endif

/*ADC2_FILT_UP_CTRL: (0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)*/
#ifndef ADC2_FILT_UP_CTRL
  #define ADC2_FILT_UP_CTRL (0x0u)
#endif

/*ADC2_MMODE0_5: (0<<2)|(0<<4)|(0<<6)|(0<<8)|(0<<10)*/
#ifndef ADC2_MMODE0_5
  #define ADC2_MMODE0_5 (0x0u)
#endif

/*ADC2_TH0_3_LOWER: (46<<8)|(46<<16)|(28<<24)*/
#ifndef ADC2_TH0_3_LOWER
  #define ADC2_TH0_3_LOWER (0x1C2E2E00u)
#endif

/*ADC2_TH0_3_UPPER: (226<<8)|(226<<16)|(200<<24)*/
#ifndef ADC2_TH0_3_UPPER
  #define ADC2_TH0_3_UPPER (0xC8E2E200u)
#endif

/*ADC2_TH4_5_LOWER: 41|(153<<8)*/
#ifndef ADC2_TH4_5_LOWER
  #define ADC2_TH4_5_LOWER (0x9929u)
#endif

/*ADC2_TH4_5_UPPER: 198|(187<<8)*/
#ifndef ADC2_TH4_5_UPPER
  #define ADC2_TH4_5_UPPER (0xBBC6u)
#endif

/*ADC2_TH6_9_LOWER: 204|(171<<8)|(210<<16)|(197<<24)*/
#ifndef ADC2_TH6_9_LOWER
  #define ADC2_TH6_9_LOWER (0xC5D2ABCCu)
#endif

/*ADC2_TH6_9_UPPER: 250|(202<<8)|(249<<16)|(209<<24)*/
#ifndef ADC2_TH6_9_UPPER
  #define ADC2_TH6_9_UPPER (0xD1F9CAFAu)
#endif


#endif
