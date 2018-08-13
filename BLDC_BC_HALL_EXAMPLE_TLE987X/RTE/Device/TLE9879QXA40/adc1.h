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

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* See adc1.c */

#ifndef ADC1_H
#define ADC1_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "adc1_defines.h"

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
/* Mode Selection */
#define SW_MODE		0u
#define SEQ_MODE	1u

/* Sequencer Configuration */
#define SKIP		  0u
#define MEAS	    1u

/* Data Width Selection */
#define BIT10     0u
#define BIT8      1u

/* Interrupt Enable/Disable */
#define INTDIS    0u
#define INTEN     1u

/* Result Register WFR mode */
#define OVERWRITE 0u
#define WFR       1u

/* Result Register Channel */
#define ADC1_CH0	(0u)
#define ADC1_CH1	(1u)
#define ADC1_CH2	(2u)
#define ADC1_CH3	(3u)
#define ADC1_CH4	(4u)
#define ADC1_CH5	(5u)
#define ADC1_CH6	(6u)
#if defined (TLE9868QXB20)
  #define ADC1_CH7	(7u)
#endif
#define ADC1_EIM	(8u)

#define ADC1_P20  ADC1_CH0
#define ADC1_CSA  ADC1_CH1
#define ADC1_P22  ADC1_CH2
#define ADC1_P23  ADC1_CH3
#define ADC1_P24  ADC1_CH4
#define ADC1_P25  ADC1_CH5
#define ADC1_VDH  ADC1_CH6
#if defined (TLE9868QXB20)
  #define ADC1_P27  ADC1_CH7
#endif

/* ESM Channel */
#define ADC1_MASK_CH0 (1u << 0u)
#define ADC1_MASK_CH1 (1u << 1u)
#define ADC1_MASK_CH2 (1u << 2u)
#define ADC1_MASK_CH3 (1u << 3u)
#define ADC1_MASK_CH4 (1u << 4u)
#define ADC1_MASK_CH5 (1u << 5u)
#define ADC1_MASK_CH6 (1u << 6u)
#if defined (TLE9868QXB20)
#define ADC1_MASK_CH7 (1u << 7u)
#endif

#define ADC1_MASK_P20 (ADC1_MASK_CH0)
#define ADC1_MASK_CSA (ADC1_MASK_CH1)
#define ADC1_MASK_P22 (ADC1_MASK_CH2)
#define ADC1_MASK_P23 (ADC1_MASK_CH3)
#define ADC1_MASK_P24 (ADC1_MASK_CH4)
#define ADC1_MASK_P25 (ADC1_MASK_CH5)
#define ADC1_MASK_VDH (ADC1_MASK_CH6)
#if defined (TLE9868QXB20)
#define ADC1_MASK_P27 (ADC1_MASK_CH7)
#endif

/* ADC1 referenz voltage [V] */
#define ADC1_VREF 5.0

#define ADC1_MASK_EOC_STS          (0x08u)
#define ADC1_MASK_ANON_STS         (0x300u)
#define ADC1_MASK_CUR_CHN          (0x38)
#define ADC1_MASK_SAMPLE_STS       (0x02)
#define ADC1_MASK_BUSY_STS         (0x01)
#define ADC1_MASK_EIM_ACTIVE_STS   (0x200)
#define ADC1_MASK_ESM_ACTIVE_STS   (0x400)
#define ADC1_MASK_CURR_ACT_SEQ     (0x3800)
#define ADC1_MASK_CURR_ACT_CH      (0x70000)

/* ANON Enum */
#define ADC1_ANON_OFF         (0u)
#define ADC1_ANON_S_STANDBY   (1u)
#define ADC1_ANON_F_STANDBY   (2u)
#define ADC1_ANON_NORMAL      (3u)
/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef enum
{
  ADC1_Trigg_None      = 0,
  ADC1_Trigg_CCU6_Ch3  = 1,
  ADC1_Trigg_GPT12E_T6 = 2,
  ADC1_Trigg_GPT12E_T3 = 3,
  ADC1_Trigg_Timer2    = 4,
  ADC1_Trigg_Timer21   = 5,
  ADC1_Trigg_Timer3    = 6
} TADC1_TRIGG_SEL;

typedef enum
{
  ADC1_1_Meas   = 0,
  ADC1_2_Meas   = 1,
  ADC1_4_Meas   = 2,
  ADC1_8_Meas   = 3,
  ADC1_16_Meas  = 4,
  ADC1_32_Meas  = 5,
  ADC1_64_Meas  = 6,
  ADC1_128_Meas = 7
} TADC1_EIM_REP_CNT;

/*******************************************************************************
**                        Global Macro Declarations                           **
*******************************************************************************/
/* ADC1 global configuration flags */
#define ADC1_Power_On()           (ADC1->CTRL_STS.reg |= (uint32)1u << 0u)
#define ADC1_Power_Off()          (ADC1->CTRL_STS.reg &= (uint32)~(1u << 0u))
#define ADC1_SOC_Set()            (ADC1->CTRL_STS.reg |= (uint32)1u << 2u)
#define ADC1_SW_Ch_Sel(a)         (ADC1->CTRL_STS.bit.IN_MUX_SEL = (uint32)(a & 7u))
#define ADC1_DIVA_Set(a)          (ADC1->GLOBCTR.bit.DIVA = (uint32)(a & 0x3Fu))
#define ADC1_ANON_Set(a)          (ADC1->GLOBCTR.bit.ANON = (uint32)(a & 0x3u))
#define ADC1_Sequencer_Mode_Sel() (ADC1->SQ_FB.reg |= (uint32)1u << 8u)
#define ADC1_Software_Mode_Sel()  (ADC1->SQ_FB.reg &= (uint32)~(1u << 8u))

/* ADC1 status flags */
#define ADC1_EOC_Sts()          ((ADC1->CTRL_STS.reg & ADC1_MASK_EOC_STS) >> 3u)
#define ADC1_ANON_Sts()         ((ADC1->GLOBSTR.reg & ADC1_MASK_ANON_STS) >> 8u)
#define ADC1_Current_Ch_Sts()   ((ADC1->GLOBSTR.reg & ADC1_MASK_CUR_CHN) >> 3u)
#define ADC1_Sample_Sts()       ((ADC1->GLOBSTR.reg & ADC1_MASK_SAMPLE_STS) >> 1u)
#define ADC1_Busy_Sts()         ((ADC1->GLOBSTR.reg & ADC1_MASK_BUSY_STS) >> 0u)
#define ADC1_EIM_Active_Sts()   ((ADC1->SQ_FB.reg & ADC1_MASK_EIM_ACTIVE_STS) >> 9u)
#define ADC1_ESM_Active_Sts()   ((ADC1->SQ_FB.reg & ADC1_MASK_ESM_ACTIVE_STS) >> 10u)
#define ADC1_Current_Active_Sequence_Sts() \
                                ((ADC1->SQ_FB.reg & ADC1_MASK_CURR_ACT_SEQ) >> 11u)
#define ADC1_Current_Active_Channel_Sts() \
                                ((ADC1->SQ_FB.reg & ADC1_MASK_CURR_ACT_CH) >> 16u)

/* ADC1 Sequencer configuration */
#define ADC1_Sequence0_Set(mask_ch)    (ADC1->SQ1_4.bit.SQ1 = (uint32)(mask_ch & 0xFFu))
#define ADC1_Sequence1_Set(mask_ch)    (ADC1->SQ1_4.bit.SQ2 = (uint32)(mask_ch & 0xFFu))
#define ADC1_Sequence2_Set(mask_ch)    (ADC1->SQ1_4.bit.SQ3 = (uint32)(mask_ch & 0xFFu))
#define ADC1_Sequence3_Set(mask_ch)    (ADC1->SQ1_4.bit.SQ4 = (uint32)(mask_ch & 0xFFu))
#define ADC1_Sequence4_Set(mask_ch)    (ADC1->SQ5_8.bit.SQ5 = (uint32)(mask_ch & 0xFFu))
#define ADC1_Sequence5_Set(mask_ch)    (ADC1->SQ5_8.bit.SQ6 = (uint32)(mask_ch & 0xFFu))
#define ADC1_Sequence6_Set(mask_ch)    (ADC1->SQ5_8.bit.SQ7 = (uint32)(mask_ch & 0xFFu))
#define ADC1_Sequence7_Set(mask_ch)    (ADC1->SQ5_8.bit.SQ8 = (uint32)(mask_ch & 0xFFu))

/*ADC1 Get Sequencer Result */
#define ADC1_Ch0_Result_Get() ((uint16)((ADC1->RES_OUT0.reg  & 0xFFFu)>>2u))
#define ADC1_Ch1_Result_Get() ((uint16)((ADC1->RES_OUT1.reg  & 0xFFFu)>>2u))
#define ADC1_Ch2_Result_Get() ((uint16)((ADC1->RES_OUT2.reg  & 0xFFFu)>>2u))
#define ADC1_Ch3_Result_Get() ((uint16)((ADC1->RES_OUT3.reg  & 0xFFFu)>>2u))
#define ADC1_Ch4_Result_Get() ((uint16)((ADC1->RES_OUT4.reg  & 0xFFFu)>>2u))
#define ADC1_Ch5_Result_Get() ((uint16)((ADC1->RES_OUT5.reg  & 0xFFFu)>>2u))
#define ADC1_Ch6_Result_Get() ((uint16)((ADC1->RES_OUT6.reg  & 0xFFFu)>>2u))
#define ADC1_EIM_Result_Get() ((uint16)((ADC1->RES_OUT_EIM.reg  & 0xFFFu)>>2u))
#if defined (TLE9868QXB20)    
#define ADC1_Ch7_Result_Get() ((uint16)((ADC1->RES_OUT7.reg  & 0xFFFu)>>2u))
#endif

#define ADC1_P20_Result_Get() ADC1_Ch0_Result_Get()
#define ADC1_CSA_Result_Get() ADC1_Ch1_Result_Get()
#define ADC1_P22_Result_Get() ADC1_Ch2_Result_Get()
#define ADC1_P23_Result_Get() ADC1_Ch3_Result_Get()
#define ADC1_P24_Result_Get() ADC1_Ch4_Result_Get()
#define ADC1_P25_Result_Get() ADC1_Ch5_Result_Get()
#define ADC1_VDH_Result_Get() ADC1_Ch6_Result_Get()
#if defined (TLE9868QXB20)    
#define ADC1_P27_Result_Get() ADC1_Ch7_Result_Get()
#endif

/* ADC1 channel configuration flags */
/* Data Width */
#define ADC1_Ch0_DataWidth_8bit_Set()    (ADC1->DWSEL.reg |= (uint32)1u << 0u)
#define ADC1_Ch0_DataWidth_10bit_Set()   (ADC1->DWSEL.reg &= (uint32)~(1u << 0u))
#define ADC1_Ch1_DataWidth_8bit_Set()    (ADC1->DWSEL.reg |= (uint32)1u << 1u)
#define ADC1_Ch1_DataWidth_10bit_Set()   (ADC1->DWSEL.reg &= (uint32)~(1u << 1u))
#define ADC1_Ch2_DataWidth_8bit_Set()    (ADC1->DWSEL.reg |= (uint32)1u << 2u)
#define ADC1_Ch2_DataWidth_10bit_Set()   (ADC1->DWSEL.reg &= (uint32)~(1u << 2u))
#define ADC1_Ch3_DataWidth_8bit_Set()    (ADC1->DWSEL.reg |= (uint32)1u << 3u)
#define ADC1_Ch3_DataWidth_10bit_Set()   (ADC1->DWSEL.reg &= (uint32)~(1u << 3u))
#define ADC1_Ch4_DataWidth_8bit_Set()    (ADC1->DWSEL.reg |= (uint32)1u << 4u)
#define ADC1_Ch4_DataWidth_10bit_Set()   (ADC1->DWSEL.reg &= (uint32)~(1u << 4u))
#define ADC1_Ch5_DataWidth_8bit_Set()    (ADC1->DWSEL.reg |= (uint32)1u << 5u)
#define ADC1_Ch5_DataWidth_10bit_Set()   (ADC1->DWSEL.reg &= (uint32)~(1u << 5u))
#define ADC1_Ch6_DataWidth_8bit_Set()    (ADC1->DWSEL.reg |= (uint32)1u << 6u)
#define ADC1_Ch6_DataWidth_10bit_Set()   (ADC1->DWSEL.reg &= (uint32)~(1u << 6u))
#if defined (TLE9868QXB20)
  #define ADC1_Ch7_DataWidth_8bit_Set()  (ADC1->DWSEL.reg |= (uint32)1u << 7u)
  #define ADC1_Ch7_DataWidth_10bit_Set() (ADC1->DWSEL.reg &= (uint32)~(1u << 7u))
#endif

/* Sample Time */
#define ADC1_Ch0_Sample_Time_Set(a)    (ADC1->STC_0_3.bit.ch0 = (uint32)(a & 0xFFu))
#define ADC1_Ch1_Sample_Time_Set(a)    (ADC1->STC_0_3.bit.ch1 = (uint32)(a & 0xFFu))
#define ADC1_Ch2_Sample_Time_Set(a)    (ADC1->STC_0_3.bit.ch2 = (uint32)(a & 0xFFu))
#define ADC1_Ch3_Sample_Time_Set(a)    (ADC1->STC_0_3.bit.ch3 = (uint32)(a & 0xFFu))
#define ADC1_Ch4_Sample_Time_Set(a)    (ADC1->STC_4_7.bit.ch4 = (uint32)(a & 0xFFu))
#define ADC1_Ch5_Sample_Time_Set(a)    (ADC1->STC_4_7.bit.ch5 = (uint32)(a & 0xFFu))
#define ADC1_Ch6_Sample_Time_Set(a)    (ADC1->STC_4_7.bit.ch6 = (uint32)(a & 0xFFu))
#if defined (TLE9868QXB20)
  #define ADC1_Ch7_Sample_Time_Set(a)  (ADC1->STC_4_7.bit.ch7 = (uint32)(a & 0xFFu))
#endif

/* Result Mode */
#define ADC1_Ch0_WaitForRead_Set()     (ADC1->RES_OUT0.reg |= (uint32)1u << 16u)
#define ADC1_Ch0_Overwrite_Set()       (ADC1->RES_OUT0.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch1_WaitForRead_Set()     (ADC1->RES_OUT1.reg |= (uint32)1u << 16u)
#define ADC1_Ch1_Overwrite_Set()       (ADC1->RES_OUT1.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch2_WaitForRead_Set()     (ADC1->RES_OUT2.reg |= (uint32)1u << 16u)
#define ADC1_Ch2_Overwrite_Set()       (ADC1->RES_OUT2.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch3_WaitForRead_Set()     (ADC1->RES_OUT3.reg |= (uint32)1u << 16u)
#define ADC1_Ch3_Overwrite_Set()       (ADC1->RES_OUT3.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch4_WaitForRead_Set()     (ADC1->RES_OUT4.reg |= (uint32)1u << 16u)
#define ADC1_Ch4_Overwrite_Set()       (ADC1->RES_OUT4.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch5_WaitForRead_Set()     (ADC1->RES_OUT5.reg |= (uint32)1u << 16u)
#define ADC1_Ch5_Overwrite_Set()       (ADC1->RES_OUT5.reg &= (uint32)~(1u << 16u))
#define ADC1_Ch6_WaitForRead_Set()     (ADC1->RES_OUT6.reg |= (uint32)1u << 16u)
#define ADC1_Ch6_Overwrite_Set()       (ADC1->RES_OUT6.reg &= (uint32)~(1u << 16u))
#if defined (TLE9868QXB20)
  #define ADC1_Ch7_WaitForRead_Set()   (ADC1->RES_OUT7.reg |= (uint32)1u << 16u)
  #define ADC1_Ch7_Overwrite_Set()     (ADC1->RES_OUT7.reg &= (uint32)~(1u << 16u))
#endif

/*Exceptional Interrupt Measurement - EIM */
#define ADC1_EIM_Channel_Set(a)        (ADC1->CHx_EIM.bit.CHx = (uint32)(a & 0x7u))
#define ADC1_ESM_Channel_Set(a)        (ADC1->CHx_ESM.bit.ESM_0 = (uint32)(a & 0xFFu))

/* VDH (Channel6) Attenuator Settings */
#define ADC1_VDH_Attenuator_On()              (MF->VMON_SEN_CTRL.reg |= (uint32)1u << 0u)
#define ADC1_VDH_Attenuator_Off()             (MF->VMON_SEN_CTRL.reg &= (uint32)~(1u << 0u))
#define ADC1_VDH_Attenuator_Zhigh_Set()       (MF->VMON_SEN_CTRL.reg |= (uint32)1u << 4u)
#define ADC1_VDH_Attenuator_Zlow_Set()        (MF->VMON_SEN_CTRL.reg &= (uint32)~(1u << 4u))
#define ADC1_VDH_Attenuator_Range_0_28V_Set() (MF->VMON_SEN_CTRL.reg |= (uint32)1u << 5u)
#define ADC1_VDH_Attenuator_Range_0_18V_Set() (MF->VMON_SEN_CTRL.reg &= (uint32)~(1u << 5u))

/* ADC1 Interrupt Clear Macros */
#define ADC1_Ch0_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 0u)
#define ADC1_Ch1_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 1u)
#define ADC1_Ch2_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 2u)
#define ADC1_Ch3_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 3u)
#define ADC1_Ch4_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 4u)
#define ADC1_Ch5_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 5u)
#define ADC1_Ch6_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 6u)
#define ADC1_Ch7_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 7u)
#define ADC1_EIM_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 8u)
#define ADC1_ESM_Int_Clr()           (ADC1->ICLR.reg = (uint32)1u << 9u)

/* ADC1 Interrupt Enable/Disable Macros */
#define ADC1_Ch0_Int_En()           (ADC1->IE.bit.CH0_IE = 1u)
#define ADC1_Ch0_Int_Dis()          (ADC1->IE.bit.CH0_IE = 0u)
#define ADC1_Ch1_Int_En()           (ADC1->IE.bit.CH1_IE = 1u)
#define ADC1_Ch1_Int_Dis()          (ADC1->IE.bit.CH1_IE = 0u)
#define ADC1_Ch2_Int_En()           (ADC1->IE.bit.CH2_IE = 1u)
#define ADC1_Ch2_Int_Dis()          (ADC1->IE.bit.CH2_IE = 0u)
#define ADC1_Ch3_Int_En()           (ADC1->IE.bit.CH3_IE = 1u)
#define ADC1_Ch3_Int_Dis()          (ADC1->IE.bit.CH3_IE = 0u)
#define ADC1_Ch4_Int_En()           (ADC1->IE.bit.CH4_IE = 1u)
#define ADC1_Ch4_Int_Dis()          (ADC1->IE.bit.CH4_IE = 0u)
#define ADC1_Ch5_Int_En()           (ADC1->IE.bit.CH5_IE = 1u)
#define ADC1_Ch5_Int_Dis()          (ADC1->IE.bit.CH5_IE = 0u)
#define ADC1_Ch6_Int_En()           (ADC1->IE.bit.CH6_IE = 1u)
#define ADC1_Ch6_Int_Dis()          (ADC1->IE.bit.CH6_IE = 0u)
#define ADC1_Ch7_Int_En()           (ADC1->IE.bit.CH7_IE = 1u)
#define ADC1_Ch7_Int_Dis()          (ADC1->IE.bit.CH7_IE = 0u)
#define ADC1_EIM_Int_En()           (ADC1->IE.bit.EIM_IE = 1u)
#define ADC1_EIM_Int_Dis()          (ADC1->IE.bit.EIM_IE = 0u)
#define ADC1_ESM_Int_En()           (ADC1->IE.bit.ESM_IE = 1u)
#define ADC1_ESM_Int_Dis()          (ADC1->IE.bit.ESM_IE = 0u)

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void ADC1_Init(void);
bool VAREF_Enable(void);

/* Inline functions ***********************************************************/
__STATIC_INLINE bool ADC1_GetChResult(uint16 * pVar, uint8 channel);
__STATIC_INLINE bool ADC1_GetChResult_mV(uint16 * pVar_mV, uint8 channel);
__STATIC_INLINE bool ADC1_GetEIMResult(uint16 * pVar);
__STATIC_INLINE bool ADC1_GetEIMResult_mV(uint16 * pVar_mV);
__STATIC_INLINE void ADC1_SetEIMChannel(uint16 channel);
__STATIC_INLINE void ADC1_SetSwMode_Channel(uint16 channel);
__STATIC_INLINE void ADC1_SetMode(uint8 mode);
__STATIC_INLINE void ADC1_SetSocSwMode(uint8 Ch);
__STATIC_INLINE bool ADC1_GetEocSwMode(void);
__STATIC_INLINE bool ADC1_GetSwModeResult(uint16 * pVar);
__STATIC_INLINE bool ADC1_GetSwModeResult_mV(uint16 * pVar_mV);
__STATIC_INLINE bool ADC1_Busy(void);
__STATIC_INLINE void ADC1_EIM_Trigger_Select(TADC1_TRIGG_SEL trigsel);
__STATIC_INLINE void ADC1_EIM_Repeat_Counter_Set(TADC1_EIM_REP_CNT repcnt);
__STATIC_INLINE void ADC1_ESM_Trigger_Select(TADC1_TRIGG_SEL trigsel);
__STATIC_INLINE bool ADC1_isEndOfConversion(void);
__STATIC_INLINE bool ADC1_isEIMactive(void);
__STATIC_INLINE bool ADC1_isESMactive(void);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/** \brief Get ADC1 Channel result value.
 *
 * \param[in] pVar-application variable, channel-channel number(defined in adc1.h)
 * \param[out] *pVar = 10 bit ADC value (8bit left aligned in 10 bit return value)
 * \return true = *pVar valid
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_GetChResult(uint16 * pVar, uint8 channel)
{
  volatile uint32 *pBaseAddr;
  uint8 vf;
  bool res;

  res = false;
  pBaseAddr = (uint32 *)((uint32)&(ADC1->RES_OUT0.reg) - (uint32) (channel << 2));
  vf = ((*pBaseAddr) >> 17 & 0x1);

  /* update the value only if there is valid data in result register */
  if (vf)
  {
    *pVar = (((*pBaseAddr) & 0x00000FFF) >> 2);
    res = true;
  }
  return (res);
}                               /* End of ADC1_GetChResult */

/** \brief Get ADC1 Channel result in Milli Volt (mV).
 *
 * \param[in] pVar_mV-application variable, channel-channel number(defined in adc1.h)
 * \param[out] *pVar_mV = ADC value in mV
 * \return true = *pVar_mV valid
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_GetChResult_mV(uint16 * pVar_mV, uint8 channel)
{
  uint16 var;
  bool res;
  res = false;
  if (ADC1_GetChResult(&var, channel) == true)
  {
    *pVar_mV = var * (uint16) (ADC1_VREF * 1000u) / (uint16) 1023;
    /* calculate attenuator in case of VDH */
    if (channel == ADC1_CH6)
    {
      *pVar_mV = *pVar_mV / ((MF_VMON_SEN_CTRL & 0x20) == 0?0.224:0.166);
    }
    res = true;
  }
  return (res);
}

/** \brief Get ADC1 EIM result value.
 *
 * \param[in] pVar-application variable
 * \return true = *pVar valid
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_GetEIMResult(uint16 * pVar)
{
  volatile uint32 *pBaseAddr;
  uint8 vf;
  bool res;
  res = false;

  pBaseAddr = (uint32 *)&(ADC1->RES_OUT_EIM.reg);
  vf = ((*pBaseAddr) >> 17 & 0x1);

  if (vf)
  {
    *pVar = (((*pBaseAddr) & 0x00000FFF) >> 2);
    res = true;
  }
  return (res);
} /* End of ADC1_GetEIMResult */

/** \brief Get ADC1 EIM result value.
 *
 * \param[in] pVar-application variable
 * \param[out] *pVar_mV = ADC value in mV
 * \return true = *pVar valid
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_GetEIMResult_mV(uint16 * pVar_mV)
{
  uint16 var;
  bool res;
  res = false;
  if (ADC1_GetEIMResult(&var) == true)
  {
    *pVar_mV = var * (uint16) (ADC1_VREF * 1000u) / (uint16) 1023;
    /* calculate attenuator in case of VDH */
    if ((ADC1->CHx_EIM.reg & 0x7) == ADC1_CH6)
    {
      *pVar_mV = *pVar_mV / ((MF_VMON_SEN_CTRL & 0x20) == 0?0.224:0.166);
    }
    res = true;
  }
  return (res);
} /* End of ADC1_GetEIMResult */


/** \brief Set(Change) ADC1 EIM channel
 *
 * \param[in] channel-channel number
 * \return void
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE void ADC1_SetEIMChannel(uint16 channel)
{
  ADC1_EIM_Channel_Set(channel);
} /* End of ADC1_SetEIMChannel */


/** \brief Set(Change) ADC1 SW_MODE channel
 *
 * \param[in] channel-channel number
 * \return void
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE void ADC1_SetSwMode_Channel(uint16 channel)
{
  ADC1_SW_Ch_Sel(channel);
} /* End of ADC1_SetSwMode_Channel */


/** \brief Start ADC1 conversion mode selection
 *
 * \param[in] mode-Sequencer mode, SW mode
 * \return void
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE void ADC1_SetMode(uint8 mode)
{
  ADC1->SQ_FB.bit.SQ_RUN = mode;
} /* End of ADC1_SetMode */


/** \brief Start ADC1 SW_MODE conversion
 *
 * \param[in] void
 * \return void
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE void ADC1_SetSocSwMode(uint8 Ch)
{
  ADC1_SW_Ch_Sel(Ch);
  ADC1_SOC_Set();
} /* End of ADC1_SetSocSwMode */


/** \brief Get ADC1 SW_MODE EOC(end of conversion)
 *
 * \param[in] void
 * \return void
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_GetEocSwMode(void)
{
  return ((bool) (ADC1_EOC_Sts() == 1));
} /* End of ADC1_GetEocSwMode */


/** \brief Get ADC1 SW_MODE result
 *
 * \param[in] pVar - application variable to store the ADC result
 * \return void
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_GetSwModeResult(uint16 * pVar)
{
  uint8 channel;
  volatile uint32 *pBaseAddr;
  uint8 vf;
  bool res;
  res = false;

  channel = ADC1->CTRL_STS.bit.IN_MUX_SEL;

  /* Calculate the base address */
  pBaseAddr = (uint32 *)((uint32)&(ADC1->RES_OUT0.reg) - (uint32) (channel << 2));
  vf = ((*pBaseAddr) >> 17 & 0x1);

  if (vf)
  {
    *pVar = (((*pBaseAddr) & 0x00000FFF) >> 2);
    res = true;
  }
  return (res);
} /* End of ADC1_GetSwModeResult */

/** \brief Get ADC1 SW_MODE result
 *
 * \param[in] pVar - application variable to store the ADC result
 * \return void
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_GetSwModeResult_mV(uint16 * pVar_mV)
{
  uint16 var;
  bool res;
  res = false;
  if (ADC1_GetSwModeResult(&var) == true)
  {
    *pVar_mV = var * (uint16) (ADC1_VREF * 1000u) / (uint16) 1023;
    /* calculate attenuator in case of VDH */
    if (ADC1->CTRL_STS.bit.IN_MUX_SEL == ADC1_CH6)
    {
      *pVar_mV = *pVar_mV / ((MF_VMON_SEN_CTRL & 0x20) == 0?0.224:0.166);
    }
    res = true;
  }
  return (res);
} /* End of ADC1_GetSwModeResult */

/** \brief Get ADC1 Busy result
 *
 * \param[in] none
 * \return true = ADC1 busy
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_Busy(void)
{
  return ((bool)(ADC1_Busy_Sts() == 1u));
} /* End of ADC1_GetSwModeResult */

/** \brief Get ADC1 EIM Trigger Selection
 *
 * \param[in] Trigger select, TADC1_TRIGG_SEL
 * \return none
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE void ADC1_EIM_Trigger_Select(TADC1_TRIGG_SEL trigsel)
{
  ADC1->CHx_EIM.bit.TRIG_SEL = (uint32)trigsel;
}

/** \brief Get ADC1 EIM Repeat Counter
 *
 * \param[in] repeat counter, TADC1_EIM_REP_CNT
 * \return none
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE void ADC1_EIM_Repeat_Counter_Set(TADC1_EIM_REP_CNT repcnt)
{
  ADC1->CHx_EIM.bit.REP = (uint32)repcnt;
}

/** \brief Get ADC1 ESM Trigger Selection
 *
 * \param[in] Trigger select, TADC1_TRIGG_SEL
 * \return none
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE void ADC1_ESM_Trigger_Select(TADC1_TRIGG_SEL trigsel)
{
  ADC1->CHx_ESM.bit.TRIG_SEL = (uint32)trigsel;
}

/** \brief checks EndOfConversion ready (Software Mode)
 *
 * \param[in] none
 * \param[in] none
 * \return true if count ready, else false
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_isEndOfConversion(void)
{
	return((bool)(ADC1_EOC_Sts() == 1u));
}

/** \brief checks Exceptional Interrupt Mode active
 *
 * \param[in] none
 * \param[in] none
 * \return true if count ready, else false
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_isEIMactive(void)
{
	return((bool)(ADC1_EIM_Active_Sts() == 1u));
}

/** \brief checks Exceptional Sequencer Mode active
 *
 * \param[in] none
 * \param[in] none
 * \return true if count ready, else false
 *
 * \ingroup ADC1_api
 */
__STATIC_INLINE bool ADC1_isESMactive(void)
{
	return((bool)(ADC1_ESM_Active_Sts() == 1u));
}

#endif /* ADC1_H */
