/*sha256=1D88A526CDE37978EBF01840FACD74EE7DDBD73B407823BF22D74C63E25CBC26*/
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

#ifndef _LIN_DEFINES_H
#define _LIN_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.6
#endif

/* XML Version 1.3.0 */
#ifndef LIN_XML_VERSION
  #define LIN_XML_VERSION 10300
#endif

#ifndef LIN_AUTOBAUD_EN
  #define LIN_AUTOBAUD_EN 0
#endif

/*LIN_CTRL_STS: (3<<1)|(0<<11)|(0<<21)*/
#ifndef LIN_CTRL_STS
  #define LIN_CTRL_STS (0x6u)
#endif

#ifndef LIN_Configuration_En
  #define LIN_Configuration_En 0
#endif

#ifndef LIN_MASTER_BAUDRATE
  #define LIN_MASTER_BAUDRATE 19200
#endif

/*LIN_SYNC: 0|(0<<1)*/
#ifndef LIN_SYNC
  #define LIN_SYNC (0x0u)
#endif

/*SCU_LINST: (3<<1)|(0<<6)*/
#ifndef SCU_LINST
  #define SCU_LINST (0x6u)
#endif


#endif
