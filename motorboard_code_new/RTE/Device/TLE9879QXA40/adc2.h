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

#ifndef ADC2_H
#define ADC2_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "adc2_defines.h"

/*******************************************************************************
**                        Global Macro Declarations                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define ADC2_VREF (1.211)

#define ADC2_RESULT_VBAT       ((uint16)0)         /* Channel 0 - VBAT */
#define ADC2_RESULT_VS         ((uint16)1)         /* Channel 1 - VS */
#define ADC2_RESULT_VSD        ((uint16)2)         /* Channel 2 - VSD */
#define ADC2_RESULT_VCP        ((uint16)3)         /* Channel 3 - VCP */
#define ADC2_RESULT_MON        ((uint16)4)         /* Channel 4 - MON */
#define ADC2_RESULT_VDDP       ((uint16)5)         /* Channel 5 - VDDP */
#define ADC2_RESULT_VAREF      ((uint16)6)         /* Channel 6 - VAREF */
#define ADC2_RESULT_VBG        ((uint16)7)         /* Channel 7 - VBG */
#define ADC2_RESULT_VDDC       ((uint16)8)         /* Channel 8 - VDDC */
#define ADC2_RESULT_TEMP       ((uint16)9)         /* Channel 9 - TEMP */

#if (UC_SERIES == TLE986)
#define ADC2_VBat_Attenuator_Range_3_28V (1u)
#define ADC2_VBat_Attenuator_Range_3_22V (0u)

#define ADC2_VBat_Attenuator_Range_3_28V_Set() (ADC2->CTRL_STS.reg |= (uint32)1u << 16u)
#define ADC2_VBat_Attenuator_Range_3_22V_Set() (ADC2->CTRL_STS.reg &= (uint32)~(1u << 16u))
#define ADC2_VBat_Attenuator_Range_Get()       ((ADC2->CTRL_STS.reg >> 16u) & 1u)
#endif

#define ADC2_VS_Attenuator_Range_3_28V (1u)
#define ADC2_VS_Attenuator_Range_3_22V (0u)

#define ADC2_VS_Attenuator_Range_3_28V_Set() (ADC2->CTRL_STS.reg |= (uint32)1u << 17u)
#define ADC2_VS_Attenuator_Range_3_22V_Set() (ADC2->CTRL_STS.reg &= (uint32)~(1u << 17u))
#define ADC2_VS_Attenuator_Range_Get()       ((ADC2->CTRL_STS.reg >> 17u) & 1u)


/* ADC2 Interrupt Clear Macros */
#define ADC2_VS_OV_Int_Clr()         (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 5u)
#define ADC2_VS_UV_Int_Clr()         (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 1u)
#define ADC2_VDDP_OV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 6u)
#define ADC2_VDDP_UV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 2u)
#define ADC2_VDDC_OV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 7u)
#define ADC2_VDDC_UV_Int_Clr()       (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 3u)
#define ADC2_VSD_OV_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 20u)
#define ADC2_VSD_UV_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 19u)
#define ADC2_VCP_OV_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 18u)
#define ADC2_VCP_UV_Int_Clr()        (SCUPM->BDRV_ISCLR.reg = (uint32)1u << 17u)
#if (UC_SERIES == TLE986)               
  #define ADC2_VBAT_OV_Int_Clr()     (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 4u)
  #define ADC2_VBAT_UV_Int_Clr()     (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 0u)
#endif                                  
#if (UC_SERIES == TLE987)               
  #define ADC2_MON_OV_Int_Clr()      (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 4u)
  #define ADC2_MON_UV_Int_Clr()      (SCUPM->SYS_SUPPLY_IRQ_CLR.reg = (uint32)1u << 0u)
#endif                                  
#define ADC2_VBG_OV_Int_Clr()        (SCUPM->SYS_ISCLR.reg = (uint32)1u << 11u)
#define ADC2_VBG_UV_Int_Clr()        (SCUPM->SYS_ISCLR.reg = (uint32)1u << 10u)
#if ((ADC2_CTRL2 & (1u << 2u)) == 0u)
  /* System Temperature Sensor */
  #define ADC2_TEMP_OT_Int_Clr()     (SCUPM->SYS_ISCLR.reg = (uint32)1u << 9u)
  #define ADC2_TEMP_WARN_Int_Clr()   (SCUPM->SYS_ISCLR.reg = (uint32)1u << 8u)
#else
  /* PMU Temperature Sensor */
  #define ADC2_TEMP_OT_Int_Clr()     (SCUPM->SYS_ISCLR.reg = (uint32)1u << 7u)
  #define ADC2_TEMP_WARN_Int_Clr()   (SCUPM->SYS_ISCLR.reg = (uint32)1u << 6u)
#endif

/* ADC2 Interrupt Enable/Disable Macros */
#define ADC2_VS_OV_Int_En()         (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_OV_IE = 1u)
#define ADC2_VS_OV_Int_Dis()        (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_OV_IE = 0u)
#define ADC2_VS_UV_Int_En()         (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_UV_IE = 1u)
#define ADC2_VS_UV_Int_Dis()        (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_UV_IE = 0u)
#define ADC2_VDDP_OV_Int_En()       (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_OV_IE = 1u)
#define ADC2_VDDP_OV_Int_Dis()      (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_OV_IE = 0u)
#define ADC2_VDDP_UV_Int_En()       (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_UV_IE = 1u)
#define ADC2_VDDP_UV_Int_Dis()      (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_UV_IE = 0u)
#define ADC2_VDDC_OV_Int_En()       (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_OV_IE = 1u)
#define ADC2_VDDC_OV_Int_Dis()      (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_OV_IE = 0u)
#define ADC2_VDDC_UV_Int_En()       (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_UV_IE = 1u)
#define ADC2_VDDC_UV_Int_Dis()      (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_UV_IE = 0u)
#define ADC2_VSD_OV_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.VSD_UPTH_IE = 1u)
#define ADC2_VSD_OV_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.VSD_UPTH_IE = 0u)
#define ADC2_VSD_UV_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.VSD_LOWTH_IE = 1u)
#define ADC2_VSD_UV_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.VSD_LOWTH_IE = 0u)
#define ADC2_VCP_OV_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.VCP_UPTH_IE = 1u)
#define ADC2_VCP_OV_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.VCP_UPTH_IE = 0u)
#define ADC2_VCP_UV_Int_En()        (SCUPM->BDRV_IRQ_CTRL.bit.VCP_LOWTH1_IE = 1u)
#define ADC2_VCP_UV_Int_Dis()       (SCUPM->BDRV_IRQ_CTRL.bit.VCP_LOWTH1_IE = 0u)
#if (UC_SERIES == TLE986)               
  #define ADC2_VBAT_OV_Int_En()     (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_OV_IE = 1u)
  #define ADC2_VBAT_OV_Int_Dis()    (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_OV_IE = 0u)
  #define ADC2_VBAT_UV_Int_En()     (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_UV_IE = 1u)
  #define ADC2_VBAT_UV_Int_Dis()    (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_UV_IE = 0u)
#endif                                  
#if (UC_SERIES == TLE987)               
  #define ADC2_MON_OV_Int_En()      (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.MON_OV_IE = 1u)
  #define ADC2_MON_OV_Int_Dis()     (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.MON_OV_IE = 0u)
  #define ADC2_MON_UV_Int_En()      (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.MON_UV_IE = 1u)
  #define ADC2_MON_UV_Int_Dis()     (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.MON_UV_IE = 0u)
#endif                                  
#define ADC2_VBG_OV_Int_En()        (SCUPM->SYS_IRQ_CTRL.bit.REFBG_UPTHWARN_IE = 1u)
#define ADC2_VBG_OV_Int_Dis()       (SCUPM->SYS_IRQ_CTRL.bit.REFBG_UPTHWARN_IE = 0u)
#define ADC2_VBG_UV_Int_En()        (SCUPM->SYS_IRQ_CTRL.bit.REFBG_LOTHWARN_IE = 1u)
#define ADC2_VBG_UV_Int_Dis()       (SCUPM->SYS_IRQ_CTRL.bit.REFBG_LOTHWARN_IE = 0u)
#if (ADC2_CTRL2 & (1u << 2u) == 0u)
  /* System Temperature Sensor */
  #define ADC2_TEMP_OT_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.SYS_OT_IE = 1u)
  #define ADC2_TEMP_OT_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.SYS_OT_IE = 0u)
  #define ADC2_TEMP_WARN_Int_En()   (SCUPM->SYS_IRQ_CTRL.bit.SYS_OTWARN_IE = 1u)
  #define ADC2_TEMP_WARN_Int_Dis()  (SCUPM->SYS_IRQ_CTRL.bit.SYS_OTWARN_IE = 0u)
#else
  /* PMU Temperature Sensor */
  #define ADC2_TEMP_OT_Int_En()     (SCUPM->SYS_IRQ_CTRL.bit.PMU_OT_IE = 1u)
  #define ADC2_TEMP_OT_Int_Dis()    (SCUPM->SYS_IRQ_CTRL.bit.PMU_OT_IE = 0u)
  #define ADC2_TEMP_WARN_Int_En()   (SCUPM->SYS_IRQ_CTRL.bit.PMU_OTWARN_IE = 1u)
  #define ADC2_TEMP_WARN_Int_Dis()  (SCUPM->SYS_IRQ_CTRL.bit.PMU_OTWARN_IE = 0u)
#endif

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/

void ADC2_Init(void);
__STATIC_INLINE uint16 ADC2_GetChResult(uint8 channel);
#if (UC_SERIES == TLE986)
__STATIC_INLINE uint16 ADC2_VBat_Result_mV(void);
#endif
__STATIC_INLINE uint16 ADC2_VS_Result_mV(void);
__STATIC_INLINE uint16 ADC2_VSD_Result_mV(void);
__STATIC_INLINE uint16 ADC2_VCP_Result_mV(void);
__STATIC_INLINE uint16 ADC2_MON_Result_mV(void);
__STATIC_INLINE uint16 ADC2_VAREF_Result_mV(void);
__STATIC_INLINE uint16 ADC2_VDDP_Result_mV(void);
__STATIC_INLINE uint16 ADC2_VBG_Result_mV(void);
__STATIC_INLINE uint16 ADC2_VDDC_Result_mV(void);
__STATIC_INLINE sint16 ADC2_Temp_Result_C(void);

/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/
/** \brief Get ADC2 Channel result value.
 *
 * \param[in] channel-channel number(defined in adc2.h)
 * \param[out] n/a
 * \return native ADC2 result value
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_GetChResult(uint8 channel)
{
  volatile uint32 *pBaseAddr;
  volatile uint16 Var;

  pBaseAddr = (uint32*)(&(ADC2->FILT_OUT0.reg) + (uint32) (channel));
  Var = ((*pBaseAddr) & 0x000003FF);
  return (Var);
} /* End of ADC2_GetChResult */

#if (UC_SERIES == TLE986)
/** \brief Get ADC2 Channel 0 (VBAT_Sense) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VBat value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VBat_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VBAT);
  if (ADC2_VS_Attenuator_Range_Get() == ADC2_VS_Attenuator_Range_3_28V)
  {
    /* attenuator 0.039 (39/1000) */
    value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 1000) / 39);
  }
  else
  {
    /* attenuator 0.055 (11/200) */
    value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 200) / 11);
  }
  return(value);
}
#endif

/** \brief Get ADC2 Channel 1 (VS) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VS value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VS_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VS);
  if (ADC2_VS_Attenuator_Range_Get() == ADC2_VS_Attenuator_Range_3_28V)
  {
    /* attenuator 0.039 (39/1000) */
    value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 1000) / 39);
  }
  else
  {
    /* attenuator 0.055 (11/200) */
    value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 200) / 11);
  }
  return(value);
}

/** \brief Get ADC2 Channel 2 (VSD) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VSD value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VSD_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VSD);
  /* attenuator 0.039 (39/1000) */
  value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 1000) / 39);
  return(value);
}

/** \brief Get ADC2 Channel 3 (VCP) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VCP value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VCP_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VCP);
  /* attenuator 0.023 (23/1000) */
  value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 1000) / 23);
  return(value);
}

/** \brief Get ADC2 Channel 4 (MON) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return MON value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_MON_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_MON);
  /* attenuator 0.039 (39/1000) */
  value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 1000) / 39);
  return(value);
}

/** \brief Get ADC2 Channel 5 (VDDP) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VDDP value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VDDP_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VDDP);
  /* attenuator 0.164 (41/250) */
  value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 250) / 41);
  return(value);
}

/** \brief Get ADC2 Channel 6 (VAREF) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VAREF value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VAREF_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VAREF);
  /* attenuator 0.219 (219/1000) */
  value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 1000) / 219);
  return(value);
}

/** \brief Get ADC2 Channel 7 (VBG) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VBG value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VBG_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VBG);
  /* attenuator 0.75 (3/4) */
  value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 4) / 3);
  return(value);
}

/** \brief Get ADC2 Channel 8 (VDDC) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return VDDC value in mV
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE uint16 ADC2_VDDC_Result_mV(void)
{
  uint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_VDDC);
  /* attenuator 0.75 (3/4) */
  value = (uint16)(((value * (uint16)(ADC2_VREF * 1000) / 1023) * 4) / 3);
  return(value);
}

/** \brief Get ADC2 Channel 9 (Temp) result value.
 *
 * \param[in] none
 * \param[out] n/a
 * \return Temp. value in °C
 *
 * \ingroup adc2_api
 */
__STATIC_INLINE sint16 ADC2_Temp_Result_C(void)
{
  sint16 value;
  value = ADC2_GetChResult(ADC2_RESULT_TEMP);
  /* attenuator 0.75 (3/4) */
  value = (sint16)((((value * (uint16)(ADC2_VREF * 1000) / 1023) - 666) * 100) / 231);
  return(value);
}

#endif
