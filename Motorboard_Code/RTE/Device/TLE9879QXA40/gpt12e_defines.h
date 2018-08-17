/*sha256=0E0666C0763598998857F03758E8745339707E7D4A87968AC0244C121730D68F*/
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
created on:Sat Aug 11 13:42:25 2018
------------------------------------------------------------------------------*/

#ifndef _GPT12E_DEFINES_H
#define _GPT12E_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef GPT12E_XML_VERSION
  #define GPT12E_XML_VERSION 10300
#endif

/*GPT12E_CAPREL: 65535*/
#ifndef GPT12E_CAPREL
  #define GPT12E_CAPREL (0xFFFFu)
#endif

/*GPT12E_CAPREL_TICK: 1*/
#ifndef GPT12E_CAPREL_TICK
  #define GPT12E_CAPREL_TICK (0x1u)
#endif

#ifndef GPT12E_CAPREL_TIME
  #define GPT12E_CAPREL_TIME 0
#endif

/*GPT12E_PISEL: (1<<1)|0|(1<<4)|(3<<2)|(0<<8)|(1<<6)|(1<<11)|(1<<10)|(2<<14)|(0\
<<13)|(0<<12)*/
#ifndef GPT12E_PISEL
  #define GPT12E_PISEL (0x8C5Eu)
#endif

/*GPT12E_T2: 65535*/
#ifndef GPT12E_T2
  #define GPT12E_T2 (0xFFFFu)
#endif

/*GPT12E_T2CON: 0|(0<<9)|(0<<7)|(0<<3)|(0<<8)*/
#ifndef GPT12E_T2CON
  #define GPT12E_T2CON (0x0u)
#endif

#ifndef GPT12E_T2CON_T2I_CAPTURE
  #define GPT12E_T2CON_T2I_CAPTURE 0
#endif

#ifndef GPT12E_T2CON_T2I_COUNTER
  #define GPT12E_T2CON_T2I_COUNTER 0
#endif

#ifndef GPT12E_T2CON_T2I_GATED_TIMER_HIGH
  #define GPT12E_T2CON_T2I_GATED_TIMER_HIGH 0
#endif

#ifndef GPT12E_T2CON_T2I_GATED_TIMER_LOW
  #define GPT12E_T2CON_T2I_GATED_TIMER_LOW 0
#endif

#ifndef GPT12E_T2CON_T2I_INC_EDGE
  #define GPT12E_T2CON_T2I_INC_EDGE 0
#endif

#ifndef GPT12E_T2CON_T2I_INC_ROT
  #define GPT12E_T2CON_T2I_INC_ROT 0
#endif

#ifndef GPT12E_T2CON_T2I_RELOAD
  #define GPT12E_T2CON_T2I_RELOAD 0
#endif

#ifndef GPT12E_T2CON_T2I_TIMER
  #define GPT12E_T2CON_T2I_TIMER 0
#endif

/*GPT12E_T2_TICK: 1*/
#ifndef GPT12E_T2_TICK
  #define GPT12E_T2_TICK (0x1u)
#endif

#ifndef GPT12E_T2_TIME
  #define GPT12E_T2_TIME 0
#endif

/*GPT12E_T3: 65535*/
#ifndef GPT12E_T3
  #define GPT12E_T3 (0xFFFFu)
#endif

/*GPT12E_T3CON: (1<<11)|6|(0<<7)|(0<<10)|(0<<9)|(0<<3)|(0<<8)*/
#ifndef GPT12E_T3CON
  #define GPT12E_T3CON (0x806u)
#endif

#ifndef GPT12E_T3CON_T3I_COUNTER
  #define GPT12E_T3CON_T3I_COUNTER 0
#endif

#ifndef GPT12E_T3CON_T3I_GATED_TIMER_HIGH
  #define GPT12E_T3CON_T3I_GATED_TIMER_HIGH 0
#endif

#ifndef GPT12E_T3CON_T3I_GATED_TIMER_LOW
  #define GPT12E_T3CON_T3I_GATED_TIMER_LOW 0
#endif

#ifndef GPT12E_T3CON_T3I_INC_EDGE
  #define GPT12E_T3CON_T3I_INC_EDGE 0
#endif

#ifndef GPT12E_T3CON_T3I_INC_ROT
  #define GPT12E_T3CON_T3I_INC_ROT 0
#endif

#ifndef GPT12E_T3CON_T3I_TIMER
  #define GPT12E_T3CON_T3I_TIMER 6
#endif

/*GPT12E_T3_TICK: 1*/
#ifndef GPT12E_T3_TICK
  #define GPT12E_T3_TICK (0x1u)
#endif

#ifndef GPT12E_T3_TIME
  #define GPT12E_T3_TIME 0
#endif

/*GPT12E_T4: 65535*/
#ifndef GPT12E_T4
  #define GPT12E_T4 (0xFFFFu)
#endif

/*GPT12E_T4CON: 0|(0<<9)|(0<<10)|(0<<11)|(0<<7)|(0<<3)|(0<<8)*/
#ifndef GPT12E_T4CON
  #define GPT12E_T4CON (0x0u)
#endif

#ifndef GPT12E_T4CON_T4I_CAPTURE
  #define GPT12E_T4CON_T4I_CAPTURE 0
#endif

#ifndef GPT12E_T4CON_T4I_COUNTER
  #define GPT12E_T4CON_T4I_COUNTER 0
#endif

#ifndef GPT12E_T4CON_T4I_GATED_TIMER_HIGH
  #define GPT12E_T4CON_T4I_GATED_TIMER_HIGH 0
#endif

#ifndef GPT12E_T4CON_T4I_GATED_TIMER_LOW
  #define GPT12E_T4CON_T4I_GATED_TIMER_LOW 0
#endif

#ifndef GPT12E_T4CON_T4I_INC_EDGE
  #define GPT12E_T4CON_T4I_INC_EDGE 0
#endif

#ifndef GPT12E_T4CON_T4I_INC_ROT
  #define GPT12E_T4CON_T4I_INC_ROT 0
#endif

#ifndef GPT12E_T4CON_T4I_RELOAD
  #define GPT12E_T4CON_T4I_RELOAD 0
#endif

#ifndef GPT12E_T4CON_T4I_TIMER
  #define GPT12E_T4CON_T4I_TIMER 0
#endif

/*GPT12E_T4_TICK: 1*/
#ifndef GPT12E_T4_TICK
  #define GPT12E_T4_TICK (0x1u)
#endif

#ifndef GPT12E_T4_TIME
  #define GPT12E_T4_TIME 0
#endif

/*GPT12E_T5: 65535*/
#ifndef GPT12E_T5
  #define GPT12E_T5 (0xFFFFu)
#endif

/*GPT12E_T5CON: 0|(0<<15)|(0<<10)|(0<<14)|(0<<9)|(0<<7)|(0<<3)|(0<<8)*/
#ifndef GPT12E_T5CON
  #define GPT12E_T5CON (0x0u)
#endif

#ifndef GPT12E_T5CON_T5I_COUNTER
  #define GPT12E_T5CON_T5I_COUNTER 0
#endif

#ifndef GPT12E_T5CON_T5I_GATED_TIMER_HIGH
  #define GPT12E_T5CON_T5I_GATED_TIMER_HIGH 0
#endif

#ifndef GPT12E_T5CON_T5I_GATED_TIMER_LOW
  #define GPT12E_T5CON_T5I_GATED_TIMER_LOW 0
#endif

#ifndef GPT12E_T5CON_T5I_TIMER
  #define GPT12E_T5CON_T5I_TIMER 0
#endif

/*GPT12E_T5_TICK: 1*/
#ifndef GPT12E_T5_TICK
  #define GPT12E_T5_TICK (0x1u)
#endif

#ifndef GPT12E_T5_TIME
  #define GPT12E_T5_TIME 0
#endif

/*GPT12E_T6: 65535*/
#ifndef GPT12E_T6
  #define GPT12E_T6 (0xFFFFu)
#endif

/*GPT12E_T6CON: (1<<11)|0|(0<<14)|(0<<15)|(0<<7)|(0<<10)|(0<<9)|(0<<3)|(0<<8)*/
#ifndef GPT12E_T6CON
  #define GPT12E_T6CON (0x800u)
#endif

#ifndef GPT12E_T6CON_T6I_COUNTER
  #define GPT12E_T6CON_T6I_COUNTER 0
#endif

#ifndef GPT12E_T6CON_T6I_GATED_TIMER_HIGH
  #define GPT12E_T6CON_T6I_GATED_TIMER_HIGH 0
#endif

#ifndef GPT12E_T6CON_T6I_GATED_TIMER_LOW
  #define GPT12E_T6CON_T6I_GATED_TIMER_LOW 0
#endif

#ifndef GPT12E_T6CON_T6I_TIMER
  #define GPT12E_T6CON_T6I_TIMER 0
#endif

/*GPT12E_T6_TICK: 1*/
#ifndef GPT12E_T6_TICK
  #define GPT12E_T6_TICK (0x1u)
#endif

#ifndef GPT12E_T6_TIME
  #define GPT12E_T6_TIME 0
#endif

#ifndef GPT12E_TEMP_CAPREL_SEL
  #define GPT12E_TEMP_CAPREL_SEL 0
#endif

#ifndef GPT12E_TEMP_T2_PISEL
  #define GPT12E_TEMP_T2_PISEL 0
#endif

#ifndef GPT12E_TEMP_T2_SEL
  #define GPT12E_TEMP_T2_SEL 0
#endif

#ifndef GPT12E_TEMP_T3OUT
  #define GPT12E_TEMP_T3OUT 0
#endif

#ifndef GPT12E_TEMP_T3_PISEL
  #define GPT12E_TEMP_T3_PISEL 0
#endif

#ifndef GPT12E_TEMP_T3_SEL
  #define GPT12E_TEMP_T3_SEL 0
#endif

#ifndef GPT12E_TEMP_T4_PISEL
  #define GPT12E_TEMP_T4_PISEL 0
#endif

#ifndef GPT12E_TEMP_T4_SEL
  #define GPT12E_TEMP_T4_SEL 0
#endif

#ifndef GPT12E_TEMP_T5_SEL
  #define GPT12E_TEMP_T5_SEL 0
#endif

#ifndef GPT12E_TEMP_T6OUT
  #define GPT12E_TEMP_T6OUT 0
#endif

#ifndef GPT12E_TEMP_T6_PISEL
  #define GPT12E_TEMP_T6_PISEL 0
#endif

#ifndef GPT12E_TEMP_T6_SEL
  #define GPT12E_TEMP_T6_SEL 0
#endif

#ifndef GPT1_BASE_CLK
  #define GPT1_BASE_CLK 6
#endif

#ifndef GPT1_T2_CLK
  #define GPT1_T2_CLK 6
#endif

#ifndef GPT1_T3_CLK
  #define GPT1_T3_CLK 0.09375
#endif

#ifndef GPT1_T4_CLK
  #define GPT1_T4_CLK 6
#endif

#ifndef GPT2_BASE_CLK
  #define GPT2_BASE_CLK 12
#endif

#ifndef GPT2_T5_CLK
  #define GPT2_T5_CLK 12
#endif

#ifndef GPT2_T6_CLK
  #define GPT2_T6_CLK 12
#endif


#endif
