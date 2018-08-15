/*sha256=CC6645840A10840D1E26E84CF56F90D0FDE27A0C7C47EDEC381563F23BA83761*/
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
created on:Wed Aug 15 13:15:20 2018
------------------------------------------------------------------------------*/

#ifndef _UART_DEFINES_H
#define _UART_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef UART_XML_VERSION
  #define UART_XML_VERSION 10300
#endif

#ifndef UART1_AUTO_BAUDRATE
  #define UART1_AUTO_BAUDRATE 1
#endif

#ifndef UART1_AUTO_BAUD_SEL
  #define UART1_AUTO_BAUD_SEL 0
#endif

#ifndef UART1_BAUDRATE
  #define UART1_BAUDRATE 19200
#endif

/*UART1_BRVAL: 78*/
#ifndef UART1_BRVAL
  #define UART1_BRVAL (0x4Eu)
#endif

#ifndef UART1_CLK
  #define UART1_CLK 24
#endif

#ifndef UART1_Configuration_En
  #define UART1_Configuration_En 0
#endif

/*UART1_FD: 4*/
#ifndef UART1_FD
  #define UART1_FD (0x4u)
#endif

#ifndef UART1_MAN_BAUDRATE
  #define UART1_MAN_BAUDRATE 19200
#endif

#ifndef UART1_RXD_PINSEL
  #define UART1_RXD_PINSEL 0
#endif

/*UART1_SCON: (1<<6)|(0<<5)|(0<<4)*/
#ifndef UART1_SCON
  #define UART1_SCON (0x40u)
#endif

#ifndef UART1_STD_EN
  #define UART1_STD_EN 0
#endif

#ifndef UART1_TXD_PINSEL
  #define UART1_TXD_PINSEL 0
#endif

#ifndef UART2_AUTO_BAUDRATE
  #define UART2_AUTO_BAUDRATE 1
#endif

#ifndef UART2_AUTO_BAUD_SEL
  #define UART2_AUTO_BAUD_SEL 0
#endif

#ifndef UART2_BAUDRATE
  #define UART2_BAUDRATE 19200
#endif

/*UART2_BRVAL: 78*/
#ifndef UART2_BRVAL
  #define UART2_BRVAL (0x4Eu)
#endif

#ifndef UART2_CLK
  #define UART2_CLK 24
#endif

#ifndef UART2_Configuration_En
  #define UART2_Configuration_En 0
#endif

/*UART2_FD: 4*/
#ifndef UART2_FD
  #define UART2_FD (0x4u)
#endif

#ifndef UART2_MAN_BAUDRATE
  #define UART2_MAN_BAUDRATE 19200
#endif

#ifndef UART2_PINSEL
  #define UART2_PINSEL 0
#endif

#ifndef UART2_PINSEL_EN
  #define UART2_PINSEL_EN 0
#endif

/*UART2_SCON: (1<<6)|(0<<5)|(0<<4)*/
#ifndef UART2_SCON
  #define UART2_SCON (0x40u)
#endif

#ifndef UART2_STD_EN
  #define UART2_STD_EN 0
#endif


#endif
