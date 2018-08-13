/*sha256=8558E14B4345C83F8ABA53DCFB3014A4EE4A0A33A916F9F1CC34982C5E7CD0F0*/
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
created on:So Jul 9 21:20:52 2017
------------------------------------------------------------------------------*/

#ifndef _PMU_DEFINES_H
#define _PMU_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.3.0 */
#ifndef PMU_XML_VERSION
  #define PMU_XML_VERSION 10300
#endif

/*PMU_CNF_CYC_SAMPLE_DEL: 0*/
#ifndef PMU_CNF_CYC_SAMPLE_DEL
  #define PMU_CNF_CYC_SAMPLE_DEL (0x0u)
#endif

/*PMU_CNF_CYC_SENSE: (0<<4)|0*/
#ifndef PMU_CNF_CYC_SENSE
  #define PMU_CNF_CYC_SENSE (0x0u)
#endif

/*PMU_CNF_CYC_WAKE: (0<<4)|0*/
#ifndef PMU_CNF_CYC_WAKE
  #define PMU_CNF_CYC_WAKE (0x0u)
#endif

/*PMU_CNF_PMU_SETTING: (0<<7)|(0<<2)|(0<<3)|(1<<1)|0*/
#ifndef PMU_CNF_PMU_SETTING
  #define PMU_CNF_PMU_SETTING (0x2u)
#endif

/*PMU_CNF_RST_TFB: 3*/
#ifndef PMU_CNF_RST_TFB
  #define PMU_CNF_RST_TFB (0x3u)
#endif

/*PMU_CNF_WAKE_FILTER: 0|(0<<1)|(2<<2)*/
#ifndef PMU_CNF_WAKE_FILTER
  #define PMU_CNF_WAKE_FILTER (0x8u)
#endif

#ifndef PMU_CYC_SENSE_ACT_TIME
  #define PMU_CYC_SENSE_ACT_TIME 10
#endif

#ifndef PMU_CYC_SENSE_EFF_SLP_TIME
  #define PMU_CYC_SENSE_EFF_SLP_TIME 2
#endif

#ifndef PMU_CYC_SENSE_SLP_TIME
  #define PMU_CYC_SENSE_SLP_TIME 2
#endif

#ifndef PMU_CYC_WAKE_EFF_TIME
  #define PMU_CYC_WAKE_EFF_TIME 2
#endif

#ifndef PMU_CYC_WAKE_TIME
  #define PMU_CYC_WAKE_TIME 2
#endif

/*PMU_LIN_WAKE_EN: (0<<7)*/
#ifndef PMU_LIN_WAKE_EN
  #define PMU_LIN_WAKE_EN (0x0u)
#endif

#ifndef PMU_MON_WAKE
  #define PMU_MON_WAKE 1
#endif

#ifndef PMU_MON_WAKE_FALL
  #define PMU_MON_WAKE_FALL 1
#endif

#ifndef PMU_MON_WAKE_RISE
  #define PMU_MON_WAKE_RISE 1
#endif

/*PMU_PMU_SUPPLY_STS: (0<<2)|(0<<6)*/
#ifndef PMU_PMU_SUPPLY_STS
  #define PMU_PMU_SUPPLY_STS (0x0u)
#endif

#ifndef PMU_PORT0_WAKE
  #define PMU_PORT0_WAKE 0
#endif

#ifndef PMU_PORT1_WAKE
  #define PMU_PORT1_WAKE 0
#endif

#ifndef PMU_SENSE_EFF_SLP_TIME
  #define PMU_SENSE_EFF_SLP_TIME 10
#endif

#ifndef PMU_SLEEP_MODE
  #define PMU_SLEEP_MODE 0
#endif

#ifndef PMU_STOP_MODE
  #define PMU_STOP_MODE 0
#endif

/*PMU_VDDEXT_CTRL: 0|(0<<1)|(0<<2)*/
#ifndef PMU_VDDEXT_CTRL
  #define PMU_VDDEXT_CTRL (0x0u)
#endif

/*PMU_WAKE_CONF_GPIO0_CYC: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)*/
#ifndef PMU_WAKE_CONF_GPIO0_CYC
  #define PMU_WAKE_CONF_GPIO0_CYC (0x0u)
#endif

/*PMU_WAKE_CONF_GPIO0_FALL: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)*/
#ifndef PMU_WAKE_CONF_GPIO0_FALL
  #define PMU_WAKE_CONF_GPIO0_FALL (0x0u)
#endif

/*PMU_WAKE_CONF_GPIO0_RISE: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)*/
#ifndef PMU_WAKE_CONF_GPIO0_RISE
  #define PMU_WAKE_CONF_GPIO0_RISE (0x0u)
#endif

/*PMU_WAKE_CONF_GPIO1_CYC: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)*/
#ifndef PMU_WAKE_CONF_GPIO1_CYC
  #define PMU_WAKE_CONF_GPIO1_CYC (0x0u)
#endif

/*PMU_WAKE_CONF_GPIO1_FALL: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)*/
#ifndef PMU_WAKE_CONF_GPIO1_FALL
  #define PMU_WAKE_CONF_GPIO1_FALL (0x0u)
#endif

/*PMU_WAKE_CONF_GPIO1_RISE: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)*/
#ifndef PMU_WAKE_CONF_GPIO1_RISE
  #define PMU_WAKE_CONF_GPIO1_RISE (0x0u)
#endif


#endif
