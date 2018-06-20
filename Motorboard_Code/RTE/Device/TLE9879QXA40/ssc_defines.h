/*sha256=DE2DDA397AE5B5F099673913AF60FB943650CCABF6F62F17E95B3C7FA4BF1800*/
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
created on:Wed Jun 20 22:15:00 2018
------------------------------------------------------------------------------*/

#ifndef _SSC_DEFINES_H
#define _SSC_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef SSC_XML_VERSION
  #define SSC_XML_VERSION 10300
#endif

#ifndef SSC1_AUTO_BAUDRATE
  #define SSC1_AUTO_BAUDRATE 3
#endif

#ifndef SSC1_AUTO_BAUD_SEL
  #define SSC1_AUTO_BAUD_SEL 0
#endif

/*SSC1_BR: 11*/
#ifndef SSC1_BR
  #define SSC1_BR (0xBu)
#endif

/*SSC1_CON: (1<<15)|(0<<14)|15|(1<<4)|(0<<5)|(0<<6)|(0<<7)|(0<<8)|(0<<9)|(0<<10\
)|(0<<11)|(0<<12)*/
#ifndef SSC1_CON
  #define SSC1_CON (0x801Fu)
#endif

#ifndef SSC1_MAN_BAUDRATE
  #define SSC1_MAN_BAUDRATE 1000
#endif

#ifndef SSC1_PISEL
  #define SSC1_PISEL 0
#endif

#ifndef SSC1_TEMP_BR
  #define SSC1_TEMP_BR 1000
#endif

#ifndef SSC1_TEMP_BRG
  #define SSC1_TEMP_BRG 0
#endif

#ifndef SSC1_TEMP_CIS
  #define SSC1_TEMP_CIS 0
#endif

#ifndef SSC1_TEMP_CLK
  #define SSC1_TEMP_CLK 24
#endif

#ifndef SSC1_TEMP_COS
  #define SSC1_TEMP_COS 0
#endif

#ifndef SSC1_TEMP_MIS
  #define SSC1_TEMP_MIS 4
#endif

#ifndef SSC1_TEMP_MOS
  #define SSC1_TEMP_MOS 0
#endif

#ifndef SSC1_TEMP_MS
  #define SSC1_TEMP_MS 0
#endif

#ifndef SSC1_TEMP_SIS
  #define SSC1_TEMP_SIS 0
#endif

#ifndef SSC1_TEMP_SOS
  #define SSC1_TEMP_SOS 1
#endif

#ifndef SSC2_AUTO_BAUDRATE
  #define SSC2_AUTO_BAUDRATE 3
#endif

#ifndef SSC2_AUTO_BAUD_SEL
  #define SSC2_AUTO_BAUD_SEL 0
#endif

/*SSC2_BR: 11*/
#ifndef SSC2_BR
  #define SSC2_BR (0xBu)
#endif

/*SSC2_CON: (0<<15)|(0<<14)|1|(0<<4)|(0<<5)|(0<<6)|(0<<7)|(0<<8)|(0<<9)|(0<<10)\
|(0<<11)|(0<<12)*/
#ifndef SSC2_CON
  #define SSC2_CON (0x1u)
#endif

#ifndef SSC2_MAN_BAUDRATE
  #define SSC2_MAN_BAUDRATE 1000
#endif

#ifndef SSC2_PISEL
  #define SSC2_PISEL 0
#endif

#ifndef SSC2_TEMP_BR
  #define SSC2_TEMP_BR 1000
#endif

#ifndef SSC2_TEMP_BRG
  #define SSC2_TEMP_BRG 0
#endif

#ifndef SSC2_TEMP_CIS
  #define SSC2_TEMP_CIS 2
#endif

#ifndef SSC2_TEMP_CLK
  #define SSC2_TEMP_CLK 24
#endif

#ifndef SSC2_TEMP_COS
  #define SSC2_TEMP_COS 0
#endif

#ifndef SSC2_TEMP_MIS
  #define SSC2_TEMP_MIS 4
#endif

#ifndef SSC2_TEMP_MOS
  #define SSC2_TEMP_MOS 0
#endif

#ifndef SSC2_TEMP_MS
  #define SSC2_TEMP_MS 0
#endif

#ifndef SSC2_TEMP_SIS
  #define SSC2_TEMP_SIS 2
#endif

#ifndef SSC2_TEMP_SOS
  #define SSC2_TEMP_SOS 0
#endif


#endif
