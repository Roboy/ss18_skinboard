/*sha256=2F2E1C7E2ACB0DB75E615380E5F9259E3FE9364201BCAC19CB5AF98EBF6226C2*/
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
created on:Wed Aug 15 20:23:07 2018
------------------------------------------------------------------------------*/

#ifndef _TIMER2X_DEFINES_H
#define _TIMER2X_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef TIMER2X_XML_VERSION
  #define TIMER2X_XML_VERSION 10300
#endif

#ifndef TIMER21_CLK
  #define TIMER21_CLK 2
#endif

#ifndef TIMER21_Configuration_En
  #define TIMER21_Configuration_En 0
#endif

#ifndef TIMER21_EXF21_PINSEL
  #define TIMER21_EXF21_PINSEL 0
#endif

#ifndef TIMER21_MAX_PERIOD
  #define TIMER21_MAX_PERIOD 32767.5
#endif

#ifndef TIMER21_RC2
  #define TIMER21_RC2 65535
#endif

#ifndef TIMER21_RC2H
  #define TIMER21_RC2H 255
#endif

#ifndef TIMER21_RC2L
  #define TIMER21_RC2L 255
#endif

#ifndef TIMER21_T2
  #define TIMER21_T2 65535
#endif

#ifndef TIMER21_T21IN_EN
  #define TIMER21_T21IN_EN 0
#endif

/*TIMER21_T2CON: (0<<3)|(0<<1)|0*/
#ifndef TIMER21_T2CON
  #define TIMER21_T2CON (0x0u)
#endif

/*TIMER21_T2CON1: 0|(0<<1)*/
#ifndef TIMER21_T2CON1
  #define TIMER21_T2CON1 (0x0u)
#endif

#ifndef TIMER21_T2H
  #define TIMER21_T2H 255
#endif

#ifndef TIMER21_T2L
  #define TIMER21_T2L 255
#endif

/*TIMER21_T2MOD: (0<<4)|(0<<1)|0|(0<<5)|(0<<6)|(0<<7)*/
#ifndef TIMER21_T2MOD
  #define TIMER21_T2MOD (0x0u)
#endif

#ifndef TIMER21_TEMP_TIMER2_SEL
  #define TIMER21_TEMP_TIMER2_SEL 0
#endif

/*TIMER21_TEMP_TIMER2_TICK: 1*/
#ifndef TIMER21_TEMP_TIMER2_TICK
  #define TIMER21_TEMP_TIMER2_TICK (0x1u)
#endif

#ifndef TIMER21_TEMP_TIMER2_TIME
  #define TIMER21_TEMP_TIMER2_TIME 1
#endif

#ifndef TIMER21_TEMP_TIMER2_TIME_SEL
  #define TIMER21_TEMP_TIMER2_TIME_SEL 0
#endif

/*TIMER21_TEMP_TIME_TICK: 1*/
#ifndef TIMER21_TEMP_TIME_TICK
  #define TIMER21_TEMP_TIME_TICK (0x1u)
#endif

#ifndef TIMER21_TEMP_TIME_TIME
  #define TIMER21_TEMP_TIME_TIME 1
#endif

#ifndef TIMER2_CLK
  #define TIMER2_CLK 2
#endif

#ifndef TIMER2_Configuration_En
  #define TIMER2_Configuration_En 0
#endif

#ifndef TIMER2_EXF2_PINSEL
  #define TIMER2_EXF2_PINSEL 0
#endif

#ifndef TIMER2_MAX_PERIOD
  #define TIMER2_MAX_PERIOD 32767.5
#endif

#ifndef TIMER2_RC2
  #define TIMER2_RC2 65535
#endif

#ifndef TIMER2_RC2H
  #define TIMER2_RC2H 255
#endif

#ifndef TIMER2_RC2L
  #define TIMER2_RC2L 255
#endif

#ifndef TIMER2_T2
  #define TIMER2_T2 65535
#endif

/*TIMER2_T2CON: (0<<3)|(0<<1)|0*/
#ifndef TIMER2_T2CON
  #define TIMER2_T2CON (0x0u)
#endif

/*TIMER2_T2CON1: 0|(0<<1)*/
#ifndef TIMER2_T2CON1
  #define TIMER2_T2CON1 (0x0u)
#endif

#ifndef TIMER2_T2H
  #define TIMER2_T2H 255
#endif

#ifndef TIMER2_T2L
  #define TIMER2_T2L 255
#endif

/*TIMER2_T2MOD: (0<<4)|(0<<1)|0|(0<<5)|(0<<6)|(0<<7)*/
#ifndef TIMER2_T2MOD
  #define TIMER2_T2MOD (0x0u)
#endif

#ifndef TIMER2_TEMP_TIMER2_SEL
  #define TIMER2_TEMP_TIMER2_SEL 0
#endif

/*TIMER2_TEMP_TIMER2_TICK: 1*/
#ifndef TIMER2_TEMP_TIMER2_TICK
  #define TIMER2_TEMP_TIMER2_TICK (0x1u)
#endif

#ifndef TIMER2_TEMP_TIMER2_TIME
  #define TIMER2_TEMP_TIMER2_TIME 1
#endif

#ifndef TIMER2_TEMP_TIMER2_TIME_SEL
  #define TIMER2_TEMP_TIMER2_TIME_SEL 0
#endif

/*TIMER2_TEMP_TIME_TICK: 1*/
#ifndef TIMER2_TEMP_TIME_TICK
  #define TIMER2_TEMP_TIME_TICK (0x1u)
#endif

#ifndef TIMER2_TEMP_TIME_TIME
  #define TIMER2_TEMP_TIME_TIME 1
#endif


#endif
