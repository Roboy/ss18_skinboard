/*sha256=F9FF1247482268F045AC92229BB6D38698E7C82292687C44AA415A5153B856A3*/
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

#ifndef _DMA_DEFINES_H
#define _DMA_DEFINES_H

#ifndef IFXConfigWizard_Version
  #define IFXConfigWizard_Version 1.8.7
#endif

/* XML Version 1.3.0 */
#ifndef DMA_XML_VERSION
  #define DMA_XML_VERSION 10300
#endif

/*DMA_BASE_ADDR: 402654208*/
#ifndef DMA_BASE_ADDR
  #define DMA_BASE_ADDR (0x18000400u)
#endif

/*DMA_CFG: 0*/
#ifndef DMA_CFG
  #define DMA_CFG (0x0u)
#endif

#ifndef DMA_CH0_DST
#define DMA_CH0_DST enter destination location
#endif

#ifndef DMA_CH0_DST_EXT
  #define DMA_CH0_DST_EXT 0
#endif

#ifndef DMA_CH0_DST_PTR_OFFS
  #define DMA_CH0_DST_PTR_OFFS 0
#endif

/*DMA_CH0_INC: 0|(0<<1)*/
#ifndef DMA_CH0_INC
  #define DMA_CH0_INC (0x0u)
#endif

#ifndef DMA_CH0_NoOfTrans
  #define DMA_CH0_NoOfTrans 1
#endif

#ifndef DMA_CH0_SIZE
  #define DMA_CH0_SIZE 1
#endif

#ifndef DMA_CH0_SRC
#define DMA_CH0_SRC ADC1->RES_OUT0.reg
#endif

#ifndef DMA_CH0_SRC_ADC1
  #define DMA_CH0_SRC_ADC1 0
#endif

#ifndef DMA_CH0_SRC_EXT
  #define DMA_CH0_SRC_EXT 0
#endif

#ifndef DMA_CH0_SRC_PTR_OFFS
  #define DMA_CH0_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH0_SRC_SEL
  #define DMA_CH0_SRC_SEL 0
#endif

#ifndef DMA_CH0_TASK_NoOfTasks
  #define DMA_CH0_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH0_TASK_SRC
#define DMA_CH0_TASK_SRC enter source reference
#endif

#ifndef DMA_CH0_TRANS_MODE
  #define DMA_CH0_TRANS_MODE 0
#endif

#ifndef DMA_CH10_DST
#define DMA_CH10_DST enter destination reference
#endif

#ifndef DMA_CH10_DST_EXT
  #define DMA_CH10_DST_EXT 0
#endif

#ifndef DMA_CH10_DST_PTR_OFFS
  #define DMA_CH10_DST_PTR_OFFS 0
#endif

/*DMA_CH10_INC: 0|(0<<1)*/
#ifndef DMA_CH10_INC
  #define DMA_CH10_INC (0x0u)
#endif

#ifndef DMA_CH10_NoOfTrans
  #define DMA_CH10_NoOfTrans 1
#endif

#ifndef DMA_CH10_SIZE
  #define DMA_CH10_SIZE 1
#endif

#ifndef DMA_CH10_SRC
#define DMA_CH10_SRC ADC1->RES_OUT6.reg
#endif

#ifndef DMA_CH10_SRC_EXT
  #define DMA_CH10_SRC_EXT 0
#endif

#ifndef DMA_CH10_SRC_PTR_OFFS
  #define DMA_CH10_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH10_SRC_SEL
  #define DMA_CH10_SRC_SEL 0
#endif

#ifndef DMA_CH10_TASK_NoOfTasks
  #define DMA_CH10_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH10_TASK_SRC
#define DMA_CH10_TASK_SRC enter source reference
#endif

#ifndef DMA_CH10_TRANS_MODE
  #define DMA_CH10_TRANS_MODE 0
#endif

#ifndef DMA_CH11_DST
#define DMA_CH11_DST enter destination reference
#endif

#ifndef DMA_CH11_DST_EXT
  #define DMA_CH11_DST_EXT 0
#endif

#ifndef DMA_CH11_DST_PTR_OFFS
  #define DMA_CH11_DST_PTR_OFFS 0
#endif

/*DMA_CH11_INC: 0|(0<<1)*/
#ifndef DMA_CH11_INC
  #define DMA_CH11_INC (0x0u)
#endif

#ifndef DMA_CH11_NoOfTrans
  #define DMA_CH11_NoOfTrans 1
#endif

#ifndef DMA_CH11_SIZE
  #define DMA_CH11_SIZE 1
#endif

#ifndef DMA_CH11_SRC
#define DMA_CH11_SRC enter source reference
#endif

#ifndef DMA_CH11_SRC_EXT
  #define DMA_CH11_SRC_EXT 0
#endif

#ifndef DMA_CH11_SRC_PTR_OFFS
  #define DMA_CH11_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH11_TASK_NoOfTasks
  #define DMA_CH11_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH11_TASK_SRC
#define DMA_CH11_TASK_SRC enter source reference
#endif

#ifndef DMA_CH11_TRANS_MODE
  #define DMA_CH11_TRANS_MODE 0
#endif

#ifndef DMA_CH12_DST
#define DMA_CH12_DST enter destination reference
#endif

#ifndef DMA_CH12_DST_EXT
  #define DMA_CH12_DST_EXT 0
#endif

#ifndef DMA_CH12_DST_PTR_OFFS
  #define DMA_CH12_DST_PTR_OFFS 0
#endif

/*DMA_CH12_INC: 0|(0<<1)*/
#ifndef DMA_CH12_INC
  #define DMA_CH12_INC (0x0u)
#endif

#ifndef DMA_CH12_NoOfTrans
  #define DMA_CH12_NoOfTrans 1
#endif

#ifndef DMA_CH12_SIZE
  #define DMA_CH12_SIZE 1
#endif

#ifndef DMA_CH12_SRC
#define DMA_CH12_SRC enter source reference
#endif

#ifndef DMA_CH12_SRC_EXT
  #define DMA_CH12_SRC_EXT 0
#endif

#ifndef DMA_CH12_SRC_PTR_OFFS
  #define DMA_CH12_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH12_TASK_NoOfTasks
  #define DMA_CH12_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH12_TASK_SRC
#define DMA_CH12_TASK_SRC enter source reference
#endif

#ifndef DMA_CH12_TRANS_MODE
  #define DMA_CH12_TRANS_MODE 0
#endif

#ifndef DMA_CH1_DST
#define DMA_CH1_DST enter destination reference
#endif

#ifndef DMA_CH1_DST_EXT
  #define DMA_CH1_DST_EXT 0
#endif

#ifndef DMA_CH1_DST_PTR_OFFS
  #define DMA_CH1_DST_PTR_OFFS 0
#endif

/*DMA_CH1_INC: 0|(0<<1)*/
#ifndef DMA_CH1_INC
  #define DMA_CH1_INC (0x0u)
#endif

#ifndef DMA_CH1_NoOfTrans
  #define DMA_CH1_NoOfTrans 1
#endif

#ifndef DMA_CH1_SIZE
  #define DMA_CH1_SIZE 1
#endif

#ifndef DMA_CH1_SRC
#define DMA_CH1_SRC ADC1->RES_OUT0.reg
#endif

#ifndef DMA_CH1_SRC_ADC1
  #define DMA_CH1_SRC_ADC1 0
#endif

#ifndef DMA_CH1_SRC_EXT
  #define DMA_CH1_SRC_EXT 0
#endif

#ifndef DMA_CH1_SRC_PTR_OFFS
  #define DMA_CH1_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH1_SRC_SEL
  #define DMA_CH1_SRC_SEL 0
#endif

#ifndef DMA_CH1_TASK_NoOfTasks
  #define DMA_CH1_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH1_TASK_SRC
#define DMA_CH1_TASK_SRC enter source reference
#endif

#ifndef DMA_CH1_TRANS_MODE
  #define DMA_CH1_TRANS_MODE 0
#endif

#ifndef DMA_CH2_DST
#define DMA_CH2_DST SSC1->TB.reg
#endif

#ifndef DMA_CH2_DST_EXT
  #define DMA_CH2_DST_EXT 0
#endif

#ifndef DMA_CH2_DST_PTR_OFFS
  #define DMA_CH2_DST_PTR_OFFS 0
#endif

#ifndef DMA_CH2_DST_SEL
  #define DMA_CH2_DST_SEL 0
#endif

/*DMA_CH2_INC: 0|(0<<1)*/
#ifndef DMA_CH2_INC
  #define DMA_CH2_INC (0x0u)
#endif

#ifndef DMA_CH2_NoOfTrans
  #define DMA_CH2_NoOfTrans 1
#endif

#ifndef DMA_CH2_SIZE
  #define DMA_CH2_SIZE 1
#endif

#ifndef DMA_CH2_SRC
#define DMA_CH2_SRC enter source reference
#endif

#ifndef DMA_CH2_SRC_EXT
  #define DMA_CH2_SRC_EXT 0
#endif

#ifndef DMA_CH2_SRC_PTR_OFFS
  #define DMA_CH2_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH2_TASK_NoOfTasks
  #define DMA_CH2_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH2_TASK_SRC
#define DMA_CH2_TASK_SRC enter source reference
#endif

#ifndef DMA_CH2_TRANS_MODE
  #define DMA_CH2_TRANS_MODE 0
#endif

#ifndef DMA_CH3_DST
#define DMA_CH3_DST enter destination reference
#endif

#ifndef DMA_CH3_DST_EXT
  #define DMA_CH3_DST_EXT 0
#endif

#ifndef DMA_CH3_DST_PTR_OFFS
  #define DMA_CH3_DST_PTR_OFFS 0
#endif

/*DMA_CH3_INC: 0|(0<<1)*/
#ifndef DMA_CH3_INC
  #define DMA_CH3_INC (0x0u)
#endif

#ifndef DMA_CH3_NoOfTrans
  #define DMA_CH3_NoOfTrans 1
#endif

#ifndef DMA_CH3_SIZE
  #define DMA_CH3_SIZE 1
#endif

#ifndef DMA_CH3_SRC
#define DMA_CH3_SRC SSC1->RB.reg
#endif

#ifndef DMA_CH3_SRC_EXT
  #define DMA_CH3_SRC_EXT 0
#endif

#ifndef DMA_CH3_SRC_PTR_OFFS
  #define DMA_CH3_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH3_SRC_SEL
  #define DMA_CH3_SRC_SEL 0
#endif

#ifndef DMA_CH3_TASK_NoOfTasks
  #define DMA_CH3_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH3_TASK_SRC
#define DMA_CH3_TASK_SRC enter source reference
#endif

#ifndef DMA_CH3_TRANS_MODE
  #define DMA_CH3_TRANS_MODE 0
#endif

#ifndef DMA_CH4_DST
#define DMA_CH4_DST enter destination reference
#endif

#ifndef DMA_CH4_DST_EXT
  #define DMA_CH4_DST_EXT 0
#endif

#ifndef DMA_CH4_DST_PTR_OFFS
  #define DMA_CH4_DST_PTR_OFFS 0
#endif

/*DMA_CH4_INC: 0|(0<<1)*/
#ifndef DMA_CH4_INC
  #define DMA_CH4_INC (0x0u)
#endif

#ifndef DMA_CH4_NoOfTrans
  #define DMA_CH4_NoOfTrans 1
#endif

#ifndef DMA_CH4_SIZE
  #define DMA_CH4_SIZE 1
#endif

#ifndef DMA_CH4_SRC
#define DMA_CH4_SRC ADC1->RES_OUT0.reg
#endif

#ifndef DMA_CH4_SRC_EXT
  #define DMA_CH4_SRC_EXT 0
#endif

#ifndef DMA_CH4_SRC_PTR_OFFS
  #define DMA_CH4_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH4_SRC_SEL
  #define DMA_CH4_SRC_SEL 0
#endif

#ifndef DMA_CH4_TASK_NoOfTasks
  #define DMA_CH4_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH4_TASK_SRC
#define DMA_CH4_TASK_SRC enter source reference
#endif

#ifndef DMA_CH4_TRANS_MODE
  #define DMA_CH4_TRANS_MODE 0
#endif

#ifndef DMA_CH5_DST
#define DMA_CH5_DST enter destination reference
#endif

#ifndef DMA_CH5_DST_EXT
  #define DMA_CH5_DST_EXT 0
#endif

#ifndef DMA_CH5_DST_PTR_OFFS
  #define DMA_CH5_DST_PTR_OFFS 0
#endif

/*DMA_CH5_INC: 0|(0<<1)*/
#ifndef DMA_CH5_INC
  #define DMA_CH5_INC (0x0u)
#endif

#ifndef DMA_CH5_NoOfTrans
  #define DMA_CH5_NoOfTrans 1
#endif

#ifndef DMA_CH5_SIZE
  #define DMA_CH5_SIZE 1
#endif

#ifndef DMA_CH5_SRC
#define DMA_CH5_SRC ADC1->RES_OUT1.reg
#endif

#ifndef DMA_CH5_SRC_EXT
  #define DMA_CH5_SRC_EXT 0
#endif

#ifndef DMA_CH5_SRC_PTR_OFFS
  #define DMA_CH5_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH5_SRC_SEL
  #define DMA_CH5_SRC_SEL 0
#endif

#ifndef DMA_CH5_TASK_NoOfTasks
  #define DMA_CH5_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH5_TASK_SRC
#define DMA_CH5_TASK_SRC enter source reference
#endif

#ifndef DMA_CH5_TRANS_MODE
  #define DMA_CH5_TRANS_MODE 0
#endif

#ifndef DMA_CH6_DST
#define DMA_CH6_DST enter destination reference
#endif

#ifndef DMA_CH6_DST_EXT
  #define DMA_CH6_DST_EXT 0
#endif

#ifndef DMA_CH6_DST_PTR_OFFS
  #define DMA_CH6_DST_PTR_OFFS 0
#endif

/*DMA_CH6_INC: 0|(0<<1)*/
#ifndef DMA_CH6_INC
  #define DMA_CH6_INC (0x0u)
#endif

#ifndef DMA_CH6_NoOfTrans
  #define DMA_CH6_NoOfTrans 1
#endif

#ifndef DMA_CH6_SIZE
  #define DMA_CH6_SIZE 1
#endif

#ifndef DMA_CH6_SRC
#define DMA_CH6_SRC ADC1->RES_OUT2.reg
#endif

#ifndef DMA_CH6_SRC_EXT
  #define DMA_CH6_SRC_EXT 0
#endif

#ifndef DMA_CH6_SRC_PTR_OFFS
  #define DMA_CH6_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH6_SRC_SEL
  #define DMA_CH6_SRC_SEL 0
#endif

#ifndef DMA_CH6_TASK_NoOfTasks
  #define DMA_CH6_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH6_TASK_SRC
#define DMA_CH6_TASK_SRC enter source reference
#endif

#ifndef DMA_CH6_TRANS_MODE
  #define DMA_CH6_TRANS_MODE 0
#endif

#ifndef DMA_CH7_DST
#define DMA_CH7_DST enter destination reference
#endif

#ifndef DMA_CH7_DST_EXT
  #define DMA_CH7_DST_EXT 0
#endif

#ifndef DMA_CH7_DST_PTR_OFFS
  #define DMA_CH7_DST_PTR_OFFS 0
#endif

/*DMA_CH7_INC: 0|(0<<1)*/
#ifndef DMA_CH7_INC
  #define DMA_CH7_INC (0x0u)
#endif

#ifndef DMA_CH7_NoOfTrans
  #define DMA_CH7_NoOfTrans 1
#endif

#ifndef DMA_CH7_SIZE
  #define DMA_CH7_SIZE 1
#endif

#ifndef DMA_CH7_SRC
#define DMA_CH7_SRC ADC1->RES_OUT3.reg
#endif

#ifndef DMA_CH7_SRC_EXT
  #define DMA_CH7_SRC_EXT 0
#endif

#ifndef DMA_CH7_SRC_PTR_OFFS
  #define DMA_CH7_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH7_SRC_SEL
  #define DMA_CH7_SRC_SEL 0
#endif

#ifndef DMA_CH7_TASK_NoOfTasks
  #define DMA_CH7_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH7_TASK_SRC
#define DMA_CH7_TASK_SRC enter source reference
#endif

#ifndef DMA_CH7_TRANS_MODE
  #define DMA_CH7_TRANS_MODE 0
#endif

#ifndef DMA_CH8_DST
#define DMA_CH8_DST enter destination reference
#endif

#ifndef DMA_CH8_DST_EXT
  #define DMA_CH8_DST_EXT 0
#endif

#ifndef DMA_CH8_DST_PTR_OFFS
  #define DMA_CH8_DST_PTR_OFFS 0
#endif

/*DMA_CH8_INC: 0|(0<<1)*/
#ifndef DMA_CH8_INC
  #define DMA_CH8_INC (0x0u)
#endif

#ifndef DMA_CH8_NoOfTrans
  #define DMA_CH8_NoOfTrans 1
#endif

#ifndef DMA_CH8_SIZE
  #define DMA_CH8_SIZE 1
#endif

#ifndef DMA_CH8_SRC
#define DMA_CH8_SRC ADC1->RES_OUT4.reg
#endif

#ifndef DMA_CH8_SRC_EXT
  #define DMA_CH8_SRC_EXT 0
#endif

#ifndef DMA_CH8_SRC_PTR_OFFS
  #define DMA_CH8_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH8_SRC_SEL
  #define DMA_CH8_SRC_SEL 0
#endif

#ifndef DMA_CH8_TASK_NoOfTasks
  #define DMA_CH8_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH8_TASK_SRC
#define DMA_CH8_TASK_SRC enter source reference
#endif

#ifndef DMA_CH8_TRANS_MODE
  #define DMA_CH8_TRANS_MODE 0
#endif

#ifndef DMA_CH9_DST
#define DMA_CH9_DST enter destination reference
#endif

#ifndef DMA_CH9_DST_EXT
  #define DMA_CH9_DST_EXT 0
#endif

#ifndef DMA_CH9_DST_PTR_OFFS
  #define DMA_CH9_DST_PTR_OFFS 0
#endif

/*DMA_CH9_INC: 0|(0<<1)*/
#ifndef DMA_CH9_INC
  #define DMA_CH9_INC (0x0u)
#endif

#ifndef DMA_CH9_NoOfTrans
  #define DMA_CH9_NoOfTrans 1
#endif

#ifndef DMA_CH9_SIZE
  #define DMA_CH9_SIZE 1
#endif

#ifndef DMA_CH9_SRC
#define DMA_CH9_SRC ADC1->RES_OUT5.reg
#endif

#ifndef DMA_CH9_SRC_EXT
  #define DMA_CH9_SRC_EXT 0
#endif

#ifndef DMA_CH9_SRC_PTR_OFFS
  #define DMA_CH9_SRC_PTR_OFFS 0
#endif

#ifndef DMA_CH9_SRC_SEL
  #define DMA_CH9_SRC_SEL 0
#endif

#ifndef DMA_CH9_TASK_NoOfTasks
  #define DMA_CH9_TASK_NoOfTasks 0
#endif

#ifndef DMA_CH9_TASK_SRC
#define DMA_CH9_TASK_SRC enter source reference
#endif

#ifndef DMA_CH9_TRANS_MODE
  #define DMA_CH9_TRANS_MODE 0
#endif

/*DMA_EN: 0|(0<<1)|(0<<2)|(0<<3)|(0<<4)|(0<<5)|(0<<6)|(0<<7)|(0<<8)|(0<<9)|(0<<\
10)|(0<<11)|(0<<12)*/
#ifndef DMA_EN
  #define DMA_EN (0x0u)
#endif


#endif
