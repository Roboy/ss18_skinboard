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
**                      Author(s) Identity                                    **
********************************************************************************
**                                                                            **
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** TA           Thomas Albersinger                                            **
**                                                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.2.0: 2017-04-04, DM:   NMI ISR: ECC enable defines added
 * V0.1.9: 2017-02-24, DM:   UART2 callbacks fixed
 * V0.1.8: 2016-10-07, DM:   all ISRs: interrupt enable checked at runtime
 * V0.1.7: 2016-08-04, DM:   ADC2.MON interrupt handling added (TLE987x)
 * V0.1.6: 2016-07-06, DM:   EXTINTx and MON corrected
 * V0.1.5: 2015-09-10, DM:   BEMF interrupt status flags naming corrected
 * V0.1.4: 2015-07-15, DM:   #define DEVICE replaced by #define UC_SERIES
 *                           BEMF callbacks added
 * V0.1.3: 2015-02-10, DM:   individual header file added
 * V0.1.2: 2014-10-31, DM:   EXINTx decoding corrected
 * V0.1.1: 2014-07-24, DM:   DMA ISRs, interrupt flags now cleared after
 *                           call of Callback function
 * V0.1.0: 2014-07-01, DM:   Initial version
 */

/*******************************************************************************
**                      MISRA                                                 **
*******************************************************************************/
/*lint -e9032 Supressing MISRA 2012 Rule 10.7 */
/*lint -e9053 Supressing MISRA 2012 Rule 12.2 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>

#ifdef RTE_DEVICE_SDK_WDT1
  #include <wdt1.h>
#endif
#ifdef RTE_DEVICE_SDK_SCU
  #include <scu.h>
#endif
#ifdef RTE_DEVICE_SDK_PMU
  #include <pmu.h>
#endif
#ifdef RTE_DEVICE_SDK_ADC1
  #include <adc1.h>
#endif
#ifdef RTE_DEVICE_SDK_ADC2
  #include <adc2.h>
#endif
#ifdef RTE_DEVICE_SDK_BDRV
  #include <bdrv.h>
#endif
#ifdef RTE_DEVICE_SDK_CCU6
  #include <ccu6.h>
#endif
#ifdef RTE_DEVICE_SDK_CSA
  #include <csa.h>
#endif
#ifdef RTE_DEVICE_SDK_GPT12E
  #include <gpt12e.h>
#endif
#ifdef RTE_DEVICE_SDK_INT
  #include <int.h>
#endif
#ifdef RTE_DEVICE_SDK_ISR
  #include <isr.h>
#endif
#ifdef RTE_DEVICE_SDK_LIN
  #include <lin.h>
#endif
#ifdef RTE_DEVICE_SDK_MON
  #include <mon.h>
#endif
#ifdef RTE_DEVICE_SDK_PORT
  #include <port.h>
#endif
#ifdef RTE_DEVICE_SDK_SSC
  #include <ssc.h>
#endif
#ifdef RTE_DEVICE_SDK_TIMER2X
  #include <timer2x.h>
#endif
#ifdef RTE_DEVICE_SDK_TIMER3
  #include <timer3.h>
#endif
#ifdef RTE_DEVICE_SDK_UART
  #include <uart.h>
#endif
#ifdef RTE_DEVICE_SDK_DMA
  #include <dma.h>
#endif

/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/
/* GPT1u Call Backs */
#if (GPT12E_T2_INT_EN == 1u)
  extern void GPT1_T2_CALLBACK(void);
#endif /*(GPT12E_T2_INT_EN == 1u)*/
#if (GPT12E_T3_INT_EN == 1u)
  extern void GPT1_T3_CALLBACK(void);
#endif /*(GPT12E_T3_INT_EN == 1u)*/
#if (GPT12E_T4_INT_EN == 1u)
  extern void GPT1_T4_CALLBACK(void);
#endif /*(GPT12E_T4_INT_EN == 1u)*/

/* GPT2 Call Backs */
#if (GPT12E_T5_INT_EN == 1u)  
  extern void GPT2_T5_CALLBACK(void);
#endif /*(GPT12E_T5_INT_EN == 1u)*/
#if (GPT12E_T6_INT_EN == 1u)
  extern void GPT2_T6_CALLBACK(void);
#endif /*(GPT12E_T6_INT_EN == 1u)*/
#if (GPT12E_CAP_INT_EN == 1u)
  extern void GPT2_CAPREL_CALLBACK(void);
#endif /*(GPT12E_CAPREL_INT_EN == 1u)*/

/* ADC1u Call Backs */
#if (ADC1_CH0_INT_EN == 1u)
  extern void ADC1_CH0_CALLBACK(void);
#endif /*(ADC1_CH0_INT_EN == 1u)*/
#if (ADC1_CH1_INT_EN == 1u)
  extern void ADC1_CH1_CALLBACK(void);
#endif /*(ADC1_CH1_INT_EN == 1u)*/
#if (ADC1_CH2_INT_EN == 1u)
  extern void ADC1_CH2_CALLBACK(void);
#endif /*(ADC1_CH2_INT_EN == 1u)*/
#if (ADC1_CH3_INT_EN == 1u)
  extern void ADC1_CH3_CALLBACK(void);
#endif /*(ADC1_CH3_INT_EN == 1u)*/
#if (ADC1_CH4_INT_EN == 1u)
  extern void ADC1_CH4_CALLBACK(void);
#endif /*(ADC1_CH4_INT_EN == 1u)*/
#if (ADC1_CH5_INT_EN == 1u)
  extern void ADC1_CH5_CALLBACK(void);
#endif /*(ADC1_CH5_INT_EN == 1u)*/
#if (ADC1_CH6_INT_EN == 1u)
  extern void ADC1_CH6_CALLBACK(void);
#endif /*(ADC1_CH6_INT_EN == 1u)*/
#if (ADC1_CH7_INT_EN == 1u)
  extern void ADC1_CH7_CALLBACK(void);
#endif /*(ADC1_CH7_INT_EN == 1u)*/
#if (ADC1_EIM_INT_EN == 1u)
  extern void ADC1_EIM_CALLBACK(void);
#endif /*(ADC1_EIM_INT_EN == 1u)*/
#if (ADC1_ESM_INT_EN == 1u)
  extern void ADC1_ESM_CALLBACK(void);
#endif /*(ADC1_ESM_INT_EN == 1u)*/

/* ADC2/Timer3/BEMF Call Backs */
#if (ADC2_VBAT_UP_INT_EN == 1u)
  extern void ADC2_VBAT_UP_CALLBACK(void);
#endif
#if (ADC2_VBAT_LO_INT_EN == 1u)
  extern void ADC2_VBAT_LO_CALLBACK(void);
#endif
#if (ADC2_VS_UP_INT_EN == 1u)
  extern void ADC2_VS_UP_CALLBACK(void);
#endif
#if (ADC2_VS_LO_INT_EN == 1u)
  extern void ADC2_VS_LO_CALLBACK(void);
#endif
#if (ADC2_VSD_UP_INT_EN == 1u)
  extern void ADC2_VSD_UP_CALLBACK(void);
#endif
#if (ADC2_VSD_LO_INT_EN == 1u)
  extern void ADC2_VSD_LO_CALLBACK(void);
#endif
#if (ADC2_VCP_UP_INT_EN == 1u)
  extern void ADC2_VCP_UP_CALLBACK(void);
#endif
#if (ADC2_VCP_LO_INT_EN == 1u)
  extern void ADC2_VCP_LO_CALLBACK(void);
#endif
#if (ADC2_MON_UP_INT_EN == 1u)
  extern void ADC2_MON_UP_CALLBACK(void);
#endif
#if (ADC2_MON_LO_INT_EN == 1u)
  extern void ADC2_MON_LO_CALLBACK(void);
#endif
#if (ADC2_VDDP_UP_INT_EN == 1u)
  extern void ADC2_VDDP_UP_CALLBACK(void);
#endif
#if (ADC2_VDDP_LO_INT_EN == 1u)
  extern void ADC2_VDDP_LO_CALLBACK(void);
#endif
#if (ADC2_VAREF_UP_INT_EN == 1u)
  extern void ADC2_VAREF_UP_CALLBACK(void);
#endif
#if (ADC2_VAREF_LO_INT_EN == 1u)
  extern void ADC2_VAREF_LO_CALLBACK(void);
#endif
#if (ADC2_VAREF_OL_INT_EN == 1u)
  extern void ADC2_VAREF_OL_CALLBACK(void);
#endif
#if (ADC2_VBG_UP_INT_EN == 1u)
  extern void ADC2_VBG_UP_CALLBACK(void);
#endif
#if (ADC2_VBG_LO_INT_EN == 1u)
  extern void ADC2_VBG_LO_CALLBACK(void);
#endif
#if (ADC2_VDDC_UP_INT_EN == 1u)
  extern void ADC2_VDDC_UP_CALLBACK(void);
#endif
#if (ADC2_VDDC_LO_INT_EN == 1u)
  extern void ADC2_VDDC_LO_CALLBACK(void);
#endif
#if (ADC2_SYS_TEMP_UP_INT_EN == 1u)
  extern void ADC2_SYS_TEMP_UP_CALLBACK(void);
#endif
#if (ADC2_SYS_TEMP_LO_INT_EN == 1u)
  extern void ADC2_SYS_TEMP_LO_CALLBACK(void);
#endif
#if (ADC2_PMU_TEMP_UP_INT_EN == 1u)
  extern void ADC2_PMU_TEMP_UP_CALLBACK(void);
#endif
#if (ADC2_PMU_TEMP_LO_INT_EN == 1u)
  extern void ADC2_PMU_TEMP_LO_CALLBACK(void);
#endif
#if (TIMER3_HB_INT_EN == 1u)
  extern void TIMER3_HBOF_CALLBACK(void);
#endif
#if (TIMER3_LB_INT_EN == 1u)
  extern void TIMER3_LBOF_CALLBACK(void);
#endif
#if (UC_SERIES == TLE987)
  #if (BEMF_U_HI_INT_EN == 1u)
    extern void BEMF_U_HI_CALLBACK(void);
  #endif
  #if (BEMF_V_HI_INT_EN == 1u)
    extern void BEMF_V_HI_CALLBACK(void);
  #endif
  #if (BEMF_W_HI_INT_EN == 1u)
    extern void BEMF_W_HI_CALLBACK(void);
  #endif
  #if (BEMF_U_LO_INT_EN == 1u)
    extern void BEMF_U_LO_CALLBACK(void);
  #endif
  #if (BEMF_V_LO_INT_EN == 1u)
    extern void BEMF_V_LO_CALLBACK(void);
  #endif
  #if (BEMF_W_LO_INT_EN == 1u)
    extern void BEMF_W_LO_CALLBACK(void);
  #endif
#endif /*(UC_DEVICE == TLE987) */

/* CCU6 Call Backs*/
#if (CCU6_CH0_CM_R_INT_EN == 1u)
  extern void CCU6_CH0_CM_R_CALLBACK(void);
#endif
#if (CCU6_CH0_CM_F_INT_EN == 1u)
  extern void CCU6_CH0_CM_F_CALLBACK(void);
#endif
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  extern void CCU6_CH1_CM_R_CALLBACK(void);
#endif
#if (CCU6_CH1_CM_F_INT_EN == 1u)
  extern void CCU6_CH1_CM_F_CALLBACK(void);
#endif
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  extern void CCU6_CH2_CM_R_CALLBACK(void);
#endif
#if (CCU6_CH2_CM_F_INT_EN == 1u)
  extern void CCU6_CH2_CM_F_CALLBACK(void);
#endif
#if (CCU6_T12_OM_INT_EN == 1u)
  extern void CCU6_T12_OM_CALLBACK(void);
#endif
#if (CCU6_T12_PM_INT_EN == 1u)
  extern void CCU6_T12_PM_CALLBACK(void);
#endif
#if (CCU6_T13_CM_INT_EN == 1u)
  extern void CCU6_T13_CM_CALLBACK(void);
#endif
#if (CCU6_T13_PM_INT_EN == 1u)
  extern void CCU6_T13_PM_CALLBACK(void);
#endif
#if (CCU6_TRAP_INT_EN == 1u)
  extern void CCU6_TRAP_CALLBACK(void);
#endif
#if (CCU6_CHE_INT_EN == 1u)
  extern void CCU6_CORRECT_HALL_CALLBACK(void);
#endif
#if (CCU6_WHE_INT_EN == 1u)
  extern void CCU6_WRONG_HALL_CALLBACK(void);
#endif
#if (CCU6_MCM_STR_INT_EN == 1u)
  extern void CCU6_MCM_STR_CALLBACK(void);
#endif

/* SSC1 Call Backs*/
#if (SSC1_RX_INT_EN == 1u)
  extern void SSC1_RX_CALLBACK(void);
#endif
#if (SSC1_TX_INT_EN == 1u)
  extern void SSC1_TX_CALLBACK(void);
#endif
#if (SSC1_ERR_INT_EN == 1u)
  extern void SSC1_ERR_CALLBACK(void);
#endif

/* SSC2 Call Backs*/
#if (SSC2_RX_INT_EN == 1u)
  extern void SSC2_RX_CALLBACK(void);
#endif
#if (SSC2_TX_INT_EN == 1u)
  extern void SSC2_TX_CALLBACK(void);
#endif
#if (SSC2_ERR_INT_EN == 1u)
  extern void SSC2_ERR_CALLBACK(void);
#endif

/* UART1/TIMER2/LIN Call Backs*/
#if (UART1_RX_INT_EN == 1u)
  extern void UART1_RX_CALLBACK(void);
#endif
#if (UART1_TX_INT_EN == 1u)
  extern void UART1_TX_CALLBACK(void);
#endif
#if (TIMER2_TF2_INT_EN == 1u)
  extern void TIMER2_TF2_CALLBACK(void);
#endif
#if (TIMER2_EXF2_INT_EN == 1u)
  extern void TIMER2_EXF2_CALLBACK(void);
#endif
#if (LIN_OC_INT_EN == 1u)
  extern void LIN_OC_CALLBACK(void);
#endif
#if (LIN_OT_INT_EN == 1u)
  extern void LIN_OT_CALLBACK(void);
#endif
#if (LIN_TMOUT_INT_EN == 1u)
  extern void LIN_TMOUT_CALLBACK(void);
#endif
#if (LIN_EOF_INT_EN == 1u)
  extern void LIN_EOF_CALLBACK(void);
#endif
#if (LIN_ERR_INT_EN == 1u)
  extern void LIN_ERR_CALLBACK(void);
#endif

/* UART2/TIMER21/EXINT2 Call Backs*/
#if (UART2_RX_INT_EN == 1u)
  extern void UART2_RX_CALLBACK(void);
#endif
#if (UART2_TX_INT_EN == 1u)
  extern void UART2_TX_CALLBACK(void);
#endif
#if (TIMER21_TF2_INT_EN == 1u)
  extern void TIMER21_TF2_CALLBACK(void);
#endif
#if (TIMER21_EXF2_INT_EN == 1u)
  extern void TIMER21_EXF2_CALLBACK(void);
#endif
#if (SCU_EXINT2_RISING_INT_EN == 1u)
  extern void EXINT2_RISING_CALLBACK(void);
#endif
#if (SCU_EXINT2_FALLING_INT_EN == 1u)
  extern void EXINT2_FALLING_CALLBACK(void);
#endif

/* EXINT0u Call Backs*/
#if (SCU_EXINT0_RISING_INT_EN == 1u)
  extern void EXINT0_RISING_CALLBACK(void);
#endif
#if (SCU_EXINT0_FALLING_INT_EN == 1u)
  extern void EXINT0_FALLING_CALLBACK(void);
#endif

/* MON/EXINT1u Call Backs*/
#if (MON_RISING_INT_EN == 1u)
  extern void MON_RISING_CALLBACK(void);
#endif
#if (MON_FALLING_INT_EN == 1u)
  extern void MON_FALLING_CALLBACK(void);
#endif
#if (SCU_EXINT1_RISING_INT_EN == 1u)
  extern void EXINT1_RISING_CALLBACK(void);
#endif
#if (SCU_EXINT1_FALLING_INT_EN == 1u)
  extern void EXINT1_FALLING_CALLBACK(void);
#endif

/* BDRV Call Backs*/
#if (BDRV_HS1_OC_INT_EN == 1u)
  extern void BDRV_HS1_OC_CALLBACK(void);
#endif
#if (BDRV_LS1_OC_INT_EN == 1u)
  extern void BDRV_LS1_OC_CALLBACK(void);
#endif
#if (BDRV_HS2_OC_INT_EN == 1u)
  extern void BDRV_HS2_OC_CALLBACK(void);
#endif
#if (BDRV_LS2_OC_INT_EN == 1u)
  extern void BDRV_LS2_OC_CALLBACK(void);
#endif
#if (UC_SERIES == TLE987)
  #if (BDRV_HS3_OC_INT_EN == 1u)
    extern void BDRV_HS3_OC_CALLBACK(void);
  #endif
  #if (BDRV_LS3_OC_INT_EN == 1u)
    extern void BDRV_LS3_OC_CALLBACK(void);
  #endif
#endif /*(UC_DEVICE == TLE987) */
#if (BDRV_HS1_DS_INT_EN == 1u)
  extern void BDRV_HS1_DS_CALLBACK(void);
#endif
#if (BDRV_LS1_DS_INT_EN == 1u)
  extern void BDRV_LS1_DS_CALLBACK(void);
#endif
#if (BDRV_HS2_DS_INT_EN == 1u)
  extern void BDRV_HS2_DS_CALLBACK(void);
#endif
#if (BDRV_LS2_DS_INT_EN == 1u)
  extern void BDRV_LS2_DS_CALLBACK(void);
#endif
#if (UC_SERIES == TLE987)
  #if (BDRV_HS3_DS_INT_EN == 1u)
    extern void BDRV_HS3_DS_CALLBACK(void);
  #endif
  #if (BDRV_LS3_DS_INT_EN == 1u)
    extern void BDRV_LS3_DS_CALLBACK(void);
  #endif
#endif /*(UC_SERIES == TLE987) */
extern void BDRV_VCP_LO_CALLBACK(void);

/* DMA Call Backs */
#if (DMA_SQ1_RDY_INT_EN == 1u)
  extern void DMA_SQ1_RDY_CALLBACK(void);
#endif
#if (DMA_SQ2_RDY_INT_EN == 1u)
  extern void DMA_SQ2_RDY_CALLBACK(void);
#endif
#if (DMA_SSC_TX_INT_EN == 1u)
  extern void DMA_SSC_TX_CALLBACK(void);
#endif
#if (DMA_SSC_RX_INT_EN == 1u)
  extern void DMA_SSC_RX_CALLBACK(void);
#endif
#if (DMA_CH1_INT_EN == 1u)
  extern void DMA_CH1_CALLBACK(void);
#endif
#if (DMA_CH2_INT_EN == 1u)
  extern void DMA_CH2_CALLBACK(void);
#endif
#if (DMA_CH3_INT_EN == 1u)
  extern void DMA_CH3_CALLBACK(void);
#endif
#if (DMA_CH4_INT_EN == 1u)
  extern void DMA_CH4_CALLBACK(void);
#endif
#if (DMA_CH5_INT_EN == 1u)
  extern void DMA_CH5_CALLBACK(void);
#endif
#if (DMA_CH6_INT_EN == 1u)
  extern void DMA_CH6_CALLBACK(void);
#endif
#if (DMA_CH7_INT_EN == 1u)
  extern void DMA_CH7_CALLBACK(void);
#endif
#if (DMA_CH8_INT_EN == 1u)
  extern void DMA_CH8_CALLBACK(void);
#endif
#if (DMA_GPT12E_INT_EN == 1u)
  extern void DMA_GPT12E_CALLBACK(void);
#endif

/* NMI Call Backs */
#if (SCU_NMI_WDT_INT_EN == 1u)
  extern void SCU_NMI_WDT_CALLBACK(void);
#endif
#if (SCU_NMI_PLL_INT_EN == 1u)
  extern void SCU_NMI_PLL_CALLBACK(void);
#endif
#if (SCU_NMI_NVM_INT_EN == 1u)
  extern void SCU_NMI_NVM_CALLBACK(void);
#endif
#if (SCU_NMI_OWD_INT_EN == 1u)
  extern void SCU_NMI_OWD_CALLBACK(void);
#endif
#if (SCU_NMI_MAP_INT_EN == 1u)
  extern void SCU_NMI_MAP_CALLBACK(void);
#endif

/* NMI ECC Error Call Backs*/
#if (SCU_ECC_RAM_DB_INT_EN == 1u)
  extern void SCU_ECC_RAM_DB_CALLBACK(void);
#endif
#if (SCU_ECC_NVM_DB_INT_EN == 1u)
  extern void SCU_ECC_NVM_DB_CALLBACK(void);
#endif

/* NMI Supply Error Call Backs*/
#if (PMU_VDDC_OV_INT_EN == 1u)
  extern void PMU_VDDC_OV_CALLBACK(void);
#endif /*(PMU_VDDC_OV_INT_EN == 1u)*/
#if (PMU_VDDC_OL_INT_EN == 1u)
  extern void PMU_VDDC_OL_CALLBACK(void);
#endif /*(PMU_VDDC_OL_INT_EN == 1u)*/
#if (PMU_VDDP_OV_INT_EN == 1u)
  extern void PMU_VDDP_OV_CALLBACK(void);
#endif /*(PMU_VDDP_OV_INT_EN == 1u)*/
#if (PMU_VDDP_OL_INT_EN == 1u)
  extern void PMU_VDDP_OL_CALLBACK(void);
#endif /*(PMU_VDDP_OL_INT_EN == 1u)*/
#if (PMU_VDDEXT_OV_INT_EN == 1u)
  extern void PMU_VDDEXT_OV_CALLBACK(void);
#endif /*(PMU_VDDEXT_OV_INT_EN == 1u)*/
#if (PMU_VDDEXT_OL_INT_EN == 1u)
  extern void PMU_VDDEXT_OL_CALLBACK(void);
#endif /*(PMU_VDDEXT_OL_INT_EN == 1u)*/
#if (PMU_VDDEXT_SHORT_INT_EN == 1u)
  extern void PMU_VDDEXT_SHORT_CALLBACK(void);
#endif /*(PMU_VDDEXT_SHORT_INT_EN == 1u)*/

/* Core Exceptions */
#if (CPU_HARDFAULT_EN == 1)
  extern void CPU_HARDFAULT_CALLBACK(void);
#endif
#if (CPU_MEMMANAGE_EN == 1)
  extern void CPU_MEMMANAGE_CALLBACK(void);
#endif
#if (CPU_BUSFAULT_EN == 1)
  extern void CPU_BUSFAULT_CALLBACK(void);
#endif
#if (CPU_USAGEFAULT_EN == 1)
  extern void CPU_USAGEFAULT_CALLBACK(void);
#endif
#if (CPU_SYSTICK_EN == 1)
  extern void CPU_SYSTICK_CALLBACK(void);
#endif

#define CCU6_SR0 0u
#define CCU6_SR1 1u
#define CCU6_SR2 2u
#define CCU6_SR3 3u

void GPT1_IRQHandler(void);
void GPT2_IRQHandler(void);
void ADC2_IRQHandler(void);  	
void ADC1_IRQHandler(void);		
void CCU6SR0_IRQHandler(void);
void CCU6SR1_IRQHandler(void); 
void CCU6SR2_IRQHandler(void); 
void CCU6SR3_IRQHandler(void); 
void SSC1_IRQHandler(void); 	
void SSC2_IRQHandler(void); 	
void UART1_IRQHandler(void);   
void UART2_IRQHandler(void);	
void EXINT0_IRQHandler(void);  
void EXINT1_IRQHandler(void);  
void BDRV_IRQHandler(void);    
void DMA_IRQHandler(void);    
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SysTick_Handler(void);

#if (INT_XML_VERSION < 10300)
  #error "use IFXConfigWizard XML Version V1.3.0 or greater"
#else
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Peripheral Modules ISRs.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
/*******************************************************************************
**                      GPT1 ISR                                              **
*******************************************************************************/
#if ((GPT12E_T2_INT_EN == 1u) || \
     (GPT12E_T3_INT_EN == 1u) || \
     (GPT12E_T4_INT_EN == 1u))
void GPT1_IRQHandler(void)
{
#if (GPT12E_T2_INT_EN == 1u)
  /* GPT1u - T2 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T2IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.T2 == (uint8)1u)
    {
      GPT1_T2_CALLBACK();
      GPT12E_T2_Int_Clr();
    }
  }
#endif /*(GPT12E_T2_INT_EN == 1u)*/

#if (GPT12E_T3_INT_EN == 1u)
  /* GPT1u - T3 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T3IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.T3 == (uint8)1u)
    {
      GPT1_T3_CALLBACK();
      GPT12E_T3_Int_Clr();
    }
  }
#endif /*(GPT12E_T3_INT_EN == 1u)*/

#if (GPT12E_T4_INT_EN == 1u)
  /* GPT1u - T4 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T4IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.T4 == (uint8)1u)
    {
      GPT1_T4_CALLBACK();
      GPT12E_T4_Int_Clr();
    }
  }
#endif /*(GPT12E_T4_INT_EN == 1u)*/
}
#endif

/*******************************************************************************
**                      GPT2 ISR                                              **
*******************************************************************************/
#if ((GPT12E_T5_INT_EN == 1u) || \
     (GPT12E_T6_INT_EN == 1u) || \
     (GPT12E_CAP_INT_EN == 1u))
void GPT2_IRQHandler(void)
{
#if (GPT12E_T5_INT_EN == 1u)
  /* GPT2 - T5 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T5IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.T5 == (uint8)1u)
    {
      GPT2_T5_CALLBACK();
      GPT12E_T5_Int_Clr();
    }
  }
#endif /*(GPT12E_T5_INT_EN == 1u)*/

#if (GPT12E_T6_INT_EN == 1u)
  /* GPT2 - T6 Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.T6IE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.T6 == (uint8)1u)
    {
      GPT2_T6_CALLBACK();
      GPT12E_T6_Int_Clr();
    }
  }
#endif /*(GPT12E_T6_INT_EN == 1u)*/

#if (GPT12E_CAP_INT_EN == 1u)
  /* GPT2 - CAPREL Interrupt */
  if ((uint8)SCU->GPT12IEN.bit.CRIE == (uint8)1u)
  {
    if ((uint8)SCU->GPT12IRC.bit.CR == (uint8)1u)
    {
      GPT2_CAPREL_CALLBACK();
      GPT12E_CapRel_Int_Clr();
    }
  }
#endif /*(GPT12E_CAPREL_INT_EN == 1u)*/
}
#endif

/*******************************************************************************
**                      ADC2 ISR                                              **
*******************************************************************************/
#if ((TIMER3_HB_INT_EN == 1u) || \
     (TIMER3_LB_INT_EN == 1u) || \
     (ADC2_VBG_UP_INT_EN == 1u) || \
     (ADC2_VBG_LO_INT_EN == 1u) || \
     (BEMF_U_HI_INT_EN == 1u) || \
     (BEMF_U_LO_INT_EN == 1u) || \
     (BEMF_V_HI_INT_EN == 1u) || \
     (BEMF_V_LO_INT_EN == 1u) || \
     (BEMF_W_HI_INT_EN == 1u) || \
     (BEMF_W_LO_INT_EN == 1u))
void ADC2_IRQHandler(void)
{
#if (TIMER3_HB_INT_EN == 1u)
  /* Timer3 High Byte Interrtupt */
  if (TIMER3->CTRL.bit.T3H_OVF_IE == 1u)
  {
    if (TIMER3->CTRL.bit.T3H_OVF_STS == 1u)
    {
      TIMER3_HBOF_CALLBACK();
      TIMER3_HB_OF_Int_Clr();
    }
  }
#endif /*(TIMER3_HB_INT_EN == 1u) */
  
#if (TIMER3_LB_INT_EN == 1u)
  /* Timer3 Low Byte Interrtupt */
  if (TIMER3->CTRL.bit.T3L_OVF_IE == 1u)
  {
    if (TIMER3->CTRL.bit.T3L_OVF_STS == 1u)
    {
      TIMER3_LBOF_CALLBACK();
      TIMER3_LB_OF_Int_Clr();
    }
  }
#endif /*(TIMER3_LB_INT_EN == 1u) */
  
  if (ADC2->CHx_ESM.bit.STS == 1u)
  {
    /* place your ISR code here
       ...
     */
  }
#if (ADC2_VBG_UP_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.REFBG_UPTHWARN_IE == 1u)
  {
    if (MF->REF1_STS.bit.REFBG_UPTHWARN_STS == 1u)
    {
      ADC2_VBG_UP_CALLBACK();
      ADC2_VBG_OV_Int_Clr();
    }
  }
#endif /*(ADC2_VBG_UP_INT_EN == 1u)*/
	
#if (ADC2_VBG_LO_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.REFBG_LOTHWARN_IE == 1u)
  {
    if (MF->REF1_STS.bit.REFBG_LOTHWARN_STS == 1u)
    {
      ADC2_VBG_LO_CALLBACK();
      ADC2_VBG_UV_Int_Clr();
    }
  }
#endif /*(ADC2_VBG_LO_INT_EN == 1u)*/

#if (BEMF_U_HI_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.PHU_ZCHI_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.PHU_ZCHI_IS == 1u)
    {
      BEMF_U_HI_CALLBACK();
      BEMF_Phase_U_Hi_Int_Clr();
    }
  }
#endif /*(BEMF_U_HI_INT_EN == 1u)*/

#if (BEMF_U_LO_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.PHU_ZCLOW_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.PHU_ZCLOW_IS == 1u)
    {
      BEMF_U_LO_CALLBACK();
      BEMF_Phase_U_Lo_Int_Clr();
    }
  }
#endif /*(BEMF_U_LO_INT_EN == 1u)*/

#if (BEMF_V_HI_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.PHV_ZCHI_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.PHV_ZCHI_IS == 1u)
    {
      BEMF_V_HI_CALLBACK();
      BEMF_Phase_V_Hi_Int_Clr();
    }
  }
#endif /*(BEMF_V_HI_INT_EN == 1u)*/

#if (BEMF_V_LO_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.PHV_ZCLOW_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.PHV_ZCLOW_IS == 1u)
    {
      BEMF_V_LO_CALLBACK();
      BEMF_Phase_V_Lo_Int_Clr();
    }
  }
#endif /*(BEMF_V_LO_INT_EN == 1u)*/

#if (BEMF_W_HI_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.PHW_ZCHI_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.PHW_ZCHI_IS == 1u)
    {
      BEMF_W_HI_CALLBACK();
      BEMF_Phase_W_Hi_Int_Clr();
    }
  }
#endif /*(BEMF_W_HI_INT_EN == 1u)*/

#if (BEMF_W_LO_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.PHW_ZCLOW_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.PHW_ZCLOW_IS == 1u)
    {
      BEMF_W_LO_CALLBACK();
      BEMF_Phase_W_Lo_Int_Clr();
    }
  }
#endif /*(BEMF_W_LO_INT_EN == 1u)*/
}
#endif

/*******************************************************************************
**                      ADC1 ISR                                              **
*******************************************************************************/
#if ((ADC1_CH0_INT_EN == 1u) || \
     (ADC1_CH1_INT_EN == 1U) || \
     (ADC1_CH2_INT_EN == 1U) || \
     (ADC1_CH3_INT_EN == 1U) || \
     (ADC1_CH4_INT_EN == 1U) || \
     (ADC1_CH5_INT_EN == 1U) || \
     (ADC1_CH6_INT_EN == 1U) || \
     (ADC1_CH7_INT_EN == 1U) || \
     (ADC1_EIM_INT_EN == 1U) || \
     (ADC1_ESM_INT_EN == 1U) || \
     (ADC2_VAREF_UP_INT_EN == 1U) || \
     (ADC2_VAREF_LO_INT_EN == 1U) || \
     (ADC2_VAREF_OL_INT_EN == 1U))
void ADC1_IRQHandler(void)
{
#if (ADC1_CH0_INT_EN == 1u)
  /* ADC1 - Ch0 Interrupt */
  if (ADC1->IE.bit.CH0_IE == 1u)
  {
    if (ADC1->IS.bit.CH0_STS == 1u)
    {
      ADC1_CH0_CALLBACK();
      ADC1_Ch0_Int_Clr();
    }
  }
#endif /*(ADC1_CH0_INT_EN == 1u) */

#if (ADC1_CH1_INT_EN == 1u)
  /* ADC1 - Ch1 Interrupt */
  if (ADC1->IE.bit.CH1_IE == 1u)
  {
    if (ADC1->IS.bit.CH1_STS == 1u)
    {
      ADC1_CH1_CALLBACK();
      ADC1_Ch1_Int_Clr();
    }
  }
#endif /*(ADC1_CH1_INT_EN == 1u) */
  
#if (ADC1_CH2_INT_EN == 1u)
  /* ADC1 - Ch2 Interrupt */
  if (ADC1->IE.bit.CH2_IE == 1u)
  {
    if (ADC1->IS.bit.CH2_STS == 1u)
    {
      ADC1_CH2_CALLBACK();
      ADC1_Ch2_Int_Clr();
    }
  }
#endif /*(ADC1_CH2_INT_EN == 1u) */
  
#if (ADC1_CH3_INT_EN == 1u)
  /* ADC1 - Ch3 Interrupt */
  if (ADC1->IE.bit.CH3_IE == 1u)
  {
    if (ADC1->IS.bit.CH3_STS == 1u)
    {
      ADC1_CH3_CALLBACK();
      ADC1_Ch3_Int_Clr();
    }
  }
#endif /*(ADC1_CH3_INT_EN == 1u) */

#if (ADC1_CH4_INT_EN == 1u)
  /* ADC1 - Ch4 Interrupt */
  if (ADC1->IE.bit.CH4_IE == 1u)
  {
    if (ADC1->IS.bit.CH4_STS == 1u)
    {
      ADC1_CH4_CALLBACK();
      ADC1_Ch4_Int_Clr();
    }
  }
#endif /*(ADC1_CH4_INT_EN == 1u) */

#if (ADC1_CH5_INT_EN == 1u)
  /* ADC1 - Ch5 Interrupt */
  if (ADC1->IE.bit.CH5_IE == 1u)
  {
    if (ADC1->IS.bit.CH5_STS == 1u)
    {
      ADC1_CH5_CALLBACK();
      ADC1_Ch5_Int_Clr();
    }
  }
#endif /*(ADC1_CH5_INT_EN == 1u) */

#if (ADC1_CH6_INT_EN == 1u)
  /* ADC1 - Ch6 Interrupt */
  if (ADC1->IE.bit.CH6_IE == 1u)
  {
    if (ADC1->IS.bit.CH6_STS == 1u)
    {
      ADC1_CH6_CALLBACK();
      ADC1_Ch6_Int_Clr();
    }
  }
#endif /*(ADC1_CH6_INT_EN == 1u) */

#if (ADC1_CH7_INT_EN == 1u)
  /* ADC1 - Ch7 Interrupt */
  if (ADC1->IE.bit.CH7_IE == 1u)
  {
    if (ADC1->IS.bit.CH7_STS == 1u)
    {
      ADC1_CH7_CALLBACK();
      ADC1_Ch7_Int_Clr();
    }
  }
#endif /*(ADC1_CH7_INT_EN == 1u) */

#if (ADC1_EIM_INT_EN == 1u)
  /* ADC1 - EIM Interrupt */
  if (ADC1->IE.bit.EIM_IE == 1u)
  {
    if (ADC1->IS.bit.EIM_STS == 1u)
    {
      ADC1_EIM_CALLBACK();
      ADC1_EIM_Int_Clr();
    }
  }
#endif /*(ADC1_EIM_INT_EN == 1u) */
  
#if (ADC1_ESM_INT_EN == 1u)
  /* ADC1 - ESM Interrupt */
  if (ADC1->IE.bit.ESM_IE == 1u)
  {
    if (ADC1->IS.bit.ESM_STS == 1u)
    {
      ADC1_ESM_CALLBACK();
      ADC1_ESM_Int_Clr();
    }
  }
#endif /*(ADC1_ESM_INT_EN == 1u) */
	
#if (ADC2_VAREF_UP_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.VREF5V_UPTH_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.VREF5V_UPTH_IS == 1u)
    {
      ADC2_VAREF_UP_CALLBACK();
      SCUPM->SYS_ISCLR.bit.VREF5V_UPTH_ICLR = 1u;
    }
  }
#endif /*(ADC2_VAREF_UP_INT_EN == 1u)*/
	
#if (ADC2_VAREF_LO_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.VREF5V_LOWTH_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.VREF5V_LOWTH_IS	== 1u)
    {
      ADC2_VAREF_LO_CALLBACK();
      SCUPM->SYS_ISCLR.bit.VREF5V_LOWTH_ICLR = 1u;
    }
  }
#endif /*(ADC2_VAREF_LO_INT_EN == 1u)*/

#if (ADC2_VAREF_OL_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.VREF5V_OVL_IE == 1u)
  {
    if (SCUPM->SYS_IS.bit.VREF5V_OVL_IS	== 1u)
    {
      ADC2_VAREF_OL_CALLBACK();
      SCUPM->SYS_ISCLR.bit.VREF5V_OVL_ICLR = 1u;
    }
  }
#endif /*(ADC2_VAREF_OL_INT_EN == 1u)*/
}
#endif

/*******************************************************************************
**                      CCU6 SR0 ISR                                          **
*******************************************************************************/
/*lint -e572 Supressing MISRA 2012 Excessive shift value */
#if ((CPU_NVIC_ISER0 & (1u << 4u)) != 0u)
void CCU6SR0_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR0)

#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR0)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR0)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR0)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR0)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR0)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR0) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR0)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR0) */

  SCU->IRCON3CLR.bit.CCU6SR0C = 1;
}
#endif

/*******************************************************************************
**                      CCU6 SR1 ISR                                          **
*******************************************************************************/
#if ((CPU_NVIC_ISER0 & (1u << 5u)) != 0u)
void CCU6SR1_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR1)

#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR1)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR1)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR1)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR1)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR1)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR1) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR1)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR1) */

  SCU->IRCON3CLR.bit.CCU6SR1C = 1;
}
#endif

/*******************************************************************************
**                      CCU6 SR2 ISR                                          **
*******************************************************************************/
#if ((CPU_NVIC_ISER0 & (1u << 6u)) != 0u)
void CCU6SR2_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR2)

#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR2)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR2)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR2)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR2)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR2)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR2) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR2)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR2) */

  SCU->IRCON4CLR.bit.CCU6SR2C = 1;
}
#endif

/*******************************************************************************
**                      CCU6 SR3 ISR                                          **
*******************************************************************************/
#if ((CPU_NVIC_ISER0 & (1u << 7u)) != 0u)
void CCU6SR3_IRQHandler(void)
{
#if (((CCU6_INP >> 0u) & 3u) == CCU6_SR3)

#if (CCU6_CH0_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60R == (uint16)1u)
    {
      CCU6_CH0_CM_R_CALLBACK();
      CCU6_CH0_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_R_INT_EN == 1u) */

#if (CCU6_CH0_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC60F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC60F == (uint16)1u)
    {
      CCU6_CH0_CM_F_CALLBACK();
      CCU6_CH0_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH0_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 0u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 2u) & 3u) == CCU6_SR3)
#if (CCU6_CH1_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61R == (uint16)1u)
    {
      CCU6_CH1_CM_R_CALLBACK();
      CCU6_CH1_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_R_INT_EN == 1u) */

#if (CCU6_CH1_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC61F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC61F == (uint16)1u)
    {
      CCU6_CH1_CM_F_CALLBACK();
      CCU6_CH1_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH1_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 2u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 4u) & 3u) == CCU6_SR3)
#if (CCU6_CH2_CM_R_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62R == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62R == (uint16)1u)
    {
      CCU6_CH2_CM_R_CALLBACK();
      CCU6_CH2_CM_R_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_R_INT_EN == 1u) */

#if (CCU6_CH2_CM_F_INT_EN == 1u)
  if (CCU6->IEN.bit.ENCC62F == 1u)
  {
    if ((uint16)CCU6->IS.bit.ICC62F == (uint16)1u)
    {
      CCU6_CH2_CM_F_CALLBACK();
      CCU6_CH2_CM_F_Int_Clr();
    }
  }
#endif /*(CCU6_CH2_CM_F_INT_EN == 1u) */
#endif /*((CCU6_INP >> 4u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 10u) & 3u) == CCU6_SR3)
#if (CCU6_T12_OM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12OM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12OM == (uint16)1u)
    {
      CCU6_T12_OM_CALLBACK();
      CCU6_T12_OM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */

#if (CCU6_T12_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT12PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T12PM == (uint16)1u)
    {
      CCU6_T12_PM_CALLBACK();
      CCU6_T12_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T12_OM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 10u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 12u) & 3u) == CCU6_SR3)
#if (CCU6_T13_CM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13CM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13CM == (uint16)1u)
    {
      CCU6_T13_CM_CALLBACK();
      CCU6_T13_CM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_CM_INT_EN == 1u) */

#if (CCU6_T13_PM_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENT13PM == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.T13PM == (uint16)1u)
    {
      CCU6_T13_PM_CALLBACK();
      CCU6_T13_PM_Int_Clr();
    }
  }
#endif /*(CCU6_T13_PM_INT_EN == 1u) */
#endif /*((CCU6_INP >> 12u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 8u) & 3u) == CCU6_SR3)
#if (CCU6_TRAP_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENTRPF == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.TRPF == (uint16)1u)
    {
      CCU6_TRAP_CALLBACK();
      CCU6_TRAP_Int_Clr();
    }
  }
#endif /*(CCU6_TRAP_INT_EN == 1u) */

#if (CCU6_WHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENWHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.WHE == (uint16)1u)
    {
      CCU6_WRONG_HALL_CALLBACK();
      CCU6_WHE_Int_Clr();
    }
  }
#endif /*(CCU6_WHE_INT_EN == 1u) */
#endif /*((CCU6_INP >> 8u) & 3u) == CCU6_SR3) */

#if (((CCU6_INP >> 6u) & 3u) == CCU6_SR3)
#if (CCU6_CHE_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENCHE == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.CHE == (uint16)1u)
    {
      CCU6_CORRECT_HALL_CALLBACK();
      CCU6_CHE_Int_Clr();
    }
  }
#endif /*(CCU6_CHE_INT_EN == 1u) */

#if (CCU6_MCM_STR_INT_EN == 1u)
  if ((uint16)CCU6->IEN.bit.ENSTR == (uint16)1u)
  {
    if ((uint16)CCU6->IS.bit.STR == (uint16)1u)
    {
      CCU6_MCM_STR_CALLBACK();
      CCU6_STR_Int_Clr();
    }
  }
#endif /*(CCU6_MCM_STR_INT_EN == 1u) */
#endif /*((CCU6_INP >> 6u) & 3u) == CCU6_SR3) */

  SCU->IRCON4CLR.bit.CCU6SR3C = 1;
}
#endif
/*lint +e572 */

/*******************************************************************************
**                      SSC1 ISR                                              **
*******************************************************************************/
#if ((SSC1_RX_INT_EN == 1u) || \
     (SSC1_TX_INT_EN == 1u) || \
     (SSC1_ERR_INT_EN == 1u))
void SSC1_IRQHandler(void)
{
#if (SSC1_RX_INT_EN == 1u)
  /* check for receive interrupt */
  if (SCU->MODIEN1.bit.RIREN1 == 1u)
  {
    if ((uint8)SCU->IRCON1.bit.RIR == (uint8)1u)
    {
      SSC1_RX_CALLBACK();
      SSC1_RX_Int_Clr();
    }
  }
#endif /*(SSC1_RX_INT_EN == 1u) */

#if (SSC1_TX_INT_EN == 1u)
  /* check for transmit interrupt */
  if (SCU->MODIEN1.bit.TIREN1 == 1u)
  {
    if ((uint8)SCU->IRCON1.bit.TIR == (uint8)1u)
    {
      SSC1_TX_CALLBACK();
      SSC1_TX_Int_Clr();
    }
  }
#endif /*(SSC1_TX_INT_EN == 1u) */

#if (SSC1_ERR_INT_EN == 1u)
  /* check for error interrupt */
  if (SCU->MODIEN1.bit.EIREN1 == 1u)
  {
    if ((uint8)SCU->IRCON1.bit.EIR == (uint8)1u)
    {
      SSC1_ERR_CALLBACK();
      SSC1_Err_Int_Clr();
    }
  }
#endif /*(SSC1_ERR_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      SSC2 ISR                                              **
*******************************************************************************/
#if ((SSC2_RX_INT_EN == 1u) || \
     (SSC2_TX_INT_EN == 1u) || \
     (SSC2_ERR_INT_EN == 1u))
void SSC2_IRQHandler(void)
{
#if (SSC2_RX_INT_EN == 1u)
  /* check for receive interrupt */
  if (SCU->MODIEN2.bit.RIREN2 == 1u)
  {
    if ((uint8)SCU->IRCON2.bit.RIR == (uint8)1u)
    {
      SSC2_RX_CALLBACK();
      SSC2_RX_Int_Clr();
    }
  }
#endif /*(SSC2_RX_INT_EN == 1u) */

#if (SSC2_TX_INT_EN == 1u)
  /* check for transmit interrupt */
  if (SCU->MODIEN2.bit.TIREN2 == 1u)
  {
    if ((uint8)SCU->IRCON2.bit.TIR == (uint8)1u)
    {
      SSC2_TX_CALLBACK();
      SSC2_TX_Int_Clr();
    }
  }
#endif /*(SSC2_TX_INT_EN == 1u) */

#if (SSC2_ERR_INT_EN == 1u)
  /* check for error interrupt */
  if (SCU->MODIEN2.bit.EIREN2 == 1u)
  {
    if ((uint8)SCU->IRCON2.bit.EIR == (uint8)1u)
    {
      SSC2_ERR_CALLBACK();
      SSC2_Err_Int_Clr();
    }
  }
#endif /*(SSC2_ERR_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      UART1 ISR                                             **
*******************************************************************************/
#if ((UART1_RX_INT_EN == 1u) || \
     (UART1_TX_INT_EN == 1u) || \
     (TIMER2_EXF2_INT_EN == 1u) || \
     (TIMER2_TF2_INT_EN == 1u) || \
     (LIN_EOF_INT_EN == 1u) || \
     (LIN_ERR_INT_EN == 1u) || \
     (LIN_OC_INT_EN == 1u) || \
     (LIN_OT_INT_EN == 1u) || \
     (LIN_TMOUT_INT_EN == 1u))
void UART1_IRQHandler(void)
{
#if (UART1_RX_INT_EN == 1u)
  if (SCU->MODIEN1.bit.RIEN1 == 1u)
  {
    /* check for receive interrupt */
    if ((uint8)UART1->SCON.bit.RI == (uint8)1u)
    {
      UART1_RX_CALLBACK();
      UART1_RX_Int_Clr();
    }
  }
#endif /*(UART1_RX_INT_EN == 1u) */

#if (UART1_TX_INT_EN == 1u)
  if (SCU->MODIEN1.bit.TIEN1 == 1u)
  {
    /* check for transmit interrupt */
    if ((uint8)UART1->SCON.bit.TI == (uint8)1u)
    {
      UART1_TX_CALLBACK();
      UART1_TX_Int_Clr();
    }
  }
#endif /*(UART1_TX_INT_EN == 1u) */

#if (TIMER2_TF2_INT_EN == 1u)
  if (TIMER2->T2CON1.bit.TF2EN == 1u)
  {
    if ((uint8)TIMER2->T2CON.bit.TF2 == (uint8)1u)
    {
      TIMER2_TF2_CALLBACK();
      TIMER2_Overflow_Int_Clr();
    }
  }
#endif /*(TIMER2_TF2_INT_EN == 1u) */

#if (TIMER2_EXF2_INT_EN == 1u)
  if (TIMER2->T2CON1.bit.EXF2EN == 1u)
  {
    if ((uint8)TIMER2->T2CON.bit.EXF2 == (uint8)1u)
    {
      TIMER2_EXF2_CALLBACK();
      TIMER2_External_Int_Clr();
    }
  }
#endif /*(TIMER2_EXF2_INT_EN == 1u) */

#if (LIN_OC_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.LIN_OC_IE == 1u)
  {
    /* LIN Over Current Interrupt */
    if ((uint8)LIN->CTRL_STS.bit.OC_STS == (uint8)1u)
    {
      LIN_OC_CALLBACK();
      LIN_Over_Curr_Int_Clr();
    }
  }
#endif /*((SCU_SYS_IRQ_CTRL & (1u << 0u)) != 0u) */
#if (LIN_OT_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.LIN_OT_IE == 1u)
  {
    /* LIN Over Temperature Interrupt */
    if ((uint8)LIN->CTRL_STS.bit.OT_STS == (uint8)1u)
    {
      LIN_OT_CALLBACK();
      LIN_Over_Temp_Int_Clr();
    }
  }
#endif /*((SCU_SYS_IRQ_CTRL & (1u << 0u)) != 0u) */
  
#if (LIN_TMOUT_INT_EN == 1u)
  if (SCUPM->SYS_IRQ_CTRL.bit.LIN_TMOUT_IE == 1u)
  {
    /* LIN TxD Timerout Interrupt */
    if ((uint8)LIN->CTRL_STS.bit.TXD_TMOUT_STS == (uint8)1u)
    {
      LIN_TMOUT_CALLBACK();
      LIN_Time_Out_Int_Clr();
    }
  }
#endif /*((SCU_SYS_IRQ_CTRL & (1u << 0u)) != 0u) */
  
#if ((LIN_EOF_INT_EN == 1u) || \
     (LIN_ERR_INT_EN == 1u) )
  if (SCU->LINST.bit.SYNEN == 1u)
  {
#if (LIN_EOF_INT_EN == 1u)
    if ((uint8)SCU->LINST.bit.EOFSYN == (uint8)1u)
    {
      LIN_EOF_CALLBACK();
      LIN_End_Of_Sync_Int_Clr();
    }
#endif /* ((LIN_EOF_INT_EN == 1u) */
#if (LIN_ERR_INT_EN == 1u)
    if ((uint8)SCU->LINST.bit.ERRSYN == (uint8)1u)
    {
      LIN_ERR_CALLBACK();
      LIN_Err_In_Sync_Int_Clr();
    }
#endif /* ((LIN_ERR_INT_EN == 1u) */
  }
#endif
}
#endif

/*******************************************************************************
**                      UART2 ISR                                             **
*******************************************************************************/
#if ((UART2_RX_INT_EN == 1u) || \
     (UART2_TX_INT_EN == 1u) || \
     (TIMER21_EXF2_INT_EN == 1u) || \
     (TIMER21_TF2_INT_EN == 1u) || \
     (SCU_EXINT2_RISING_INT_EN == 1u) || \
     (SCU_EXINT2_FALLING_INT_EN == 1u) )
void UART2_IRQHandler(void)
{
#if (UART2_RX_INT_EN == 1u)
  if (SCU->MODIEN2.bit.RIEN2 == 1u)
  {
    /* check for receive interrupt */
    if ((uint8)UART2->SCON.bit.RI == (uint8)1u)
    {
      UART2_RX_CALLBACK();
      UART2_RX_Int_Clr();
    }
  }
#endif /*(UART2_RX_INT_EN == 1u) */

#if (UART2_TX_INT_EN == 1u)
  if (SCU->MODIEN2.bit.TIEN2 == 1u)
  {
    /* check for transmit interrupt */
    if ((uint8)UART2->SCON.bit.TI == (uint8)1u)
    {
      UART2_TX_CALLBACK();
      UART2_TX_Int_Clr();
    }
  }
#endif /*(UART2_TX_INT_EN == 1u) */

#if (TIMER21_TF2_INT_EN == 1u)
  if (TIMER21->T2CON1.bit.TF2EN == 1u)
  {
    if ((uint8)TIMER21->T2CON.bit.TF2 == (uint8)1u)
    {
      TIMER21_TF2_CALLBACK();
      TIMER21_Overflow_Int_Clr();
    }
  }
#endif /*(TIMER21_TF2_INT_EN == 1u) */

#if (TIMER21_EXF2_INT_EN == 1u)
  if (TIMER21->T2CON1.bit.EXF2EN == 1u)
  {
    if ((uint8)TIMER21->T2CON.bit.EXF2 == (uint8)1u)
    {
      TIMER21_EXF2_CALLBACK();
      TIMER21_External_Int_Clr();
    }
  }
#endif /*(TIMER21_TF2_INT_EN == 1u) */

#if ((SCU_MODIEN2 & (1u << 5u)) != 0u)
#if (SCU_EXINT2_FALLING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 5u)) != 0u)
  {
    /* External Interrupt 2 - Falling Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT2F == (uint8)1u)
    {
      EXINT2_FALLING_CALLBACK();
      EXINT2_Falling_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT2_FALLING_INT_EN == 1u) */
  
#if (SCU_EXINT2_RISING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 4u)) != 0u)
  {
    /* External Interrupt 2 - Rising Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT2R == (uint8)1u)
    {
      EXINT2_RISING_CALLBACK();
      EXINT2_Rising_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT2_RISING_INT_EN == 1u) */
#endif /*((SCU_MODIEN3 & (1u << 5u)) != 0u) */
}
#endif

/*******************************************************************************
**                      EXTINT0 ISR                                           **
*******************************************************************************/
#if ((SCU_EXINT0_RISING_INT_EN == 1u) || \
     (SCU_EXINT0_FALLING_INT_EN == 1u) || \
     (MON_RISING_INT_EN == 1u) || \
     (MON_FALLING_INT_EN == 1u) )
void EXINT0_IRQHandler(void)
{
#if ((SCU_MODIEN3 & (1u << 0u)) != 0u)
#if (SCU_EXINT0_FALLING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 1u)) != 0u)
  {
    /* External Interrupt 0 - Falling Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT0F == (uint8)1u)
    {
      EXINT0_FALLING_CALLBACK();
      EXINT0_Falling_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT0_FALLING_INT_EN == 1u) */
  
#if (SCU_EXINT0_RISING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 0u)) != 0u)
  {
    /* External Interrupt 0 - Rising Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT0R == (uint8)1u)
    {
      EXINT0_RISING_CALLBACK();
      EXINT0_Rising_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT0_RISING_INT_EN == 1u) */
#endif /* ((SCU_MODIEN3 & (1u << 0u)) != 0u) */

#if ((SCU_MODIEN3 & (1u << 4u)) != 0u)
#if (MON_FALLING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 7u)) != 0u)
  {
    /* MON Pin Interrupt - Falling Edge */
    if ((uint8)SCU->IRCON0.bit.MONF == (uint8)1u)
    {
      MON_FALLING_CALLBACK();
      MON_Falling_Edge_Int_Clr();
    }
  }
#endif /* (MON_FALLING_INT_EN == 1u) */
  
#if (MON_RISING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 6u)) != 0u)
  {
    /* MON Pin Interrupt - Rising Edge */
    if ((uint8)SCU->IRCON0.bit.MONR == (uint8)1u)
    {
      MON_RISING_CALLBACK();
      MON_Rising_Edge_Int_Clr();
    }
  }
#endif /* (MON_RISING_INT_EN == 1u) */
#endif /*((SCU_MODIEN3 & (1u << 4u)) != 0u) */
}
#endif

/*******************************************************************************
**                      EXTINT1 ISR                                           **
*******************************************************************************/
#if ((SCU_EXINT1_RISING_INT_EN == 1u) || \
     (SCU_EXINT1_FALLING_INT_EN == 1u))
void EXINT1_IRQHandler(void)
{
#if ((SCU_MODIEN4 & (1u << 0u)) != 0u)
#if (SCU_EXINT1_FALLING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 3u)) != 0u)
  {
    /* External Interrupt 1 - Falling Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT1F == (uint8)1u)
    {
      EXINT1_FALLING_CALLBACK();
      EXINT1_Falling_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT1_FALLING_INT_EN == 1u) */
#if (SCU_EXINT1_RISING_INT_EN == 1u)
  if ((SCU->EXICON0.reg & (1u << 2u)) != 0u)
  {
    /* External Interrupt 1 - Rising Edge */
    if ((uint8)SCU->IRCON0.bit.EXINT1R == (uint8)1u)
    {
      EXINT1_RISING_CALLBACK();
      EXINT1_Rising_Edge_Int_Clr();
    }
  }
#endif /* (SCU_EXINT1_RISING_INT_EN == 1u) */
#endif /*((SCU_MODIEN4 & (1u << 0u)) != 0u) */
}
#endif

/*******************************************************************************
**                      BDRV ISR                                              **
*******************************************************************************/
#if ((BDRV_HS1_OC_INT_EN == 1u) || \
     (BDRV_LS1_OC_INT_EN == 1u) || \
     (BDRV_HS2_OC_INT_EN == 1u) || \
     (BDRV_LS2_OC_INT_EN == 1u) || \
     (BDRV_HS3_OC_INT_EN == 1u) || \
     (BDRV_LS3_OC_INT_EN == 1u) || \
     (BDRV_HS1_DS_INT_EN == 1u) || \
     (BDRV_LS1_DS_INT_EN == 1u) || \
     (BDRV_HS2_DS_INT_EN == 1u) || \
     (BDRV_LS2_DS_INT_EN == 1u) || \
     (BDRV_HS3_DS_INT_EN == 1u) || \
     (BDRV_LS3_DS_INT_EN == 1u) || \
     (ADC2_VSD_UP_INT_EN == 1u) || \
     (ADC2_VSD_LO_INT_EN == 1u) || \
     (BDRV_VCP_LO2_INT_EN == 1u) || \
     (ADC2_VCP_UP_INT_EN == 1u) || \
     (ADC2_VCP_LO_INT_EN == 1u) )
void BDRV_IRQHandler(void)
{
#if (BDRV_HS1_OC_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.HS1_OC_IE == 1u)
  {
    /* HS1 Over Current Interrupt */
    if (SCUPM->BDRV_IS.bit.HS1_OC_IS == 1u)
    {
      BDRV_HS1_OC_CALLBACK();
      BDRV_HS1_OC_Int_Clr();
    }
  }
#endif /*(BDRV_HS1_OC_INT_EN == 1u) */

#if (BDRV_LS1_OC_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.LS1_OC_IE == 1u)
  {
    /* LS1 Over Current Interrupt */
    if (SCUPM->BDRV_IS.bit.LS1_OC_IS == 1u)
    {
      BDRV_LS1_OC_CALLBACK();
      BDRV_LS1_OC_Int_Clr();
    }
  }
#endif /*(BDRV_LS1_OC_INT_EN == 1u) */

#if (BDRV_HS2_OC_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.HS2_OC_IE == 1u)
  {
    /* HS2 Over Current Interrupt */
    if (SCUPM->BDRV_IS.bit.HS2_OC_IS == 1u)
    {
      BDRV_HS2_OC_CALLBACK();
      BDRV_HS2_OC_Int_Clr();
    }
  }
#endif /*(BDRV_HS2_OC_INT_EN == 1u) */

#if (BDRV_LS2_OC_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.LS2_OC_IE == 1u)
  {
    /* LS2 Over Current Interrupt */
    if (SCUPM->BDRV_IS.bit.LS2_OC_IS == 1u)
    {
      BDRV_LS2_OC_CALLBACK();
      BDRV_LS2_OC_Int_Clr();
    }
  }
#endif /*(BDRV_LS2_OC_INT_EN == 1u) */

#if (UC_SERIES == TLE987)
#if (BDRV_HS3_OC_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.HS3_OC_IE == 1u)
  {
    /* HS3 Over Current Interrupt */
    if (SCUPM->BDRV_IS.bit.HS3_OC_IS == 1u)
    {
      BDRV_HS3_OC_CALLBACK();
      BDRV_HS3_OC_Int_Clr();
    }
  }
#endif /*(BDRV_HS3_OC_INT_EN == 1u) */

#if (BDRV_LS3_OC_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.LS3_OC_IE == 1u)
  {
    /* LS3 Over Current Interrupt */
    if (SCUPM->BDRV_IS.bit.LS3_OC_IS == 1u)
    {
      BDRV_LS3_OC_CALLBACK();
      BDRV_LS3_OC_Int_Clr();
    }
  }
#endif /*(BDRV_LS3_OC_INT_EN == 1u) */
#endif /*(UC_SERIES == TLE987) */

#if (BDRV_HS1_DS_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.HS1_DS_IE == 1u)
  {
    /* HS1 Drain Source Monitoring Interrupt */
    if (SCUPM->BDRV_IS.bit.HS1_DS_IS == 1u)
    {
      BDRV_HS1_DS_CALLBACK();
      BDRV_HS1_DS_Int_Clr();
    }
  }
#endif /*(BDRV_HS1_DS_INT_EN == 1u) */

#if (BDRV_LS1_DS_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.LS1_DS_IE == 1u)
  {
    /* LS1 Drain Source Monitoring Interrupt */
    if (SCUPM->BDRV_IS.bit.LS1_DS_IS == 1u)
    {
      BDRV_LS1_DS_CALLBACK();
      BDRV_LS1_DS_Int_Clr();
    }
  }
#endif /*(BDRV_LS1_DS_INT_EN == 1u) */

#if (BDRV_HS2_DS_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.HS2_DS_IE == 1u)
  {
    /* HS2 Drain Source Monitoring Interrupt */
    if (SCUPM->BDRV_IS.bit.HS2_DS_IS == 1u)
    {
      BDRV_HS2_DS_CALLBACK();
      BDRV_HS2_DS_Int_Clr();
    }
  }
#endif /*(BDRV_HS2_DS_INT_EN == 1u) */

#if (BDRV_LS2_DS_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.LS2_DS_IE == 1u)
  {
    /* LS2 Drain Source Monitoring Interrupt */
    if (SCUPM->BDRV_IS.bit.LS2_DS_IS == 1u)
    {
      BDRV_LS2_DS_CALLBACK();
      BDRV_LS2_DS_Int_Clr();
    }
  }
#endif /*(BDRV_LS2_DS_INT_EN == 1u) */

#if (UC_SERIES == TLE987)
#if (BDRV_HS3_DS_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.HS3_DS_IE == 1u)
  {
    /* HS3 Drain Source Monitoring Interrupt */
    if (SCUPM->BDRV_IS.bit.HS3_DS_IS == 1u)
    {
      BDRV_HS3_DS_CALLBACK();
      BDRV_HS3_DS_Int_Clr();
    }
  }
#endif /*(BDRV_HS3_DS_INT_EN == 1u) */

#if (BDRV_LS3_DS_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.LS3_DS_IE == 1u)
  {
    /* LS3 Drain Source Monitoring Interrupt */
    if (SCUPM->BDRV_IS.bit.LS3_DS_IS == 1u)
    {
      BDRV_LS3_DS_CALLBACK();
      BDRV_LS3_DS_Int_Clr();
    }
  }
#endif /*(BDRV_LS3_DS_INT_EN == 1u) */
#endif /*(UC_DEVICE == TLE987) */

#if (ADC2_VCP_LO_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.VCP_LOWTH1_IE == 1u)
  {
    /* Charge Pump output voltage low threshold measured by ADC2-Ch3 */
    if (SCUPM->BDRV_IS.bit.VCP_LOWTH1_IS == 1u)
    {
      ADC2_VCP_LO_CALLBACK();
      ADC2_VCP_UV_Int_Clr();
    }
  }
#endif /*(ADC2_VCP_LO_INT_EN == 1u) */

#if (BDRV_VCP_LO2_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.VCP_LOWTH2_IE == 1u)
  {
    /* Charge Pump output voltage low threshold comparator in BDRV module */
    if (SCUPM->BDRV_IS.bit.VCP_LOWTH2_IS == 1u)
    {
      BDRV_VCP_LO_CALLBACK();
      BDRV_VCP_LO_Int_Clr();
    }
  }
#endif /*(ADC2_VCP_LO2_INT_EN == 1u) */

#if (ADC2_VCP_UP_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.VCP_UPTH_IE == 1u)
  {
    /* Charge Pump output voltage upper threshold measured by ADC2-Ch3 */
    if (SCUPM->BDRV_IS.bit.VCP_UPTH_IS == 1u)
    {
      ADC2_VCP_UP_CALLBACK();
      ADC2_VCP_OV_Int_Clr();
    }
  }
#endif /*(ADC2_VCP_UP_INT_EN == 1u) */

#if (ADC2_VSD_LO_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.VSD_LOWTH_IE == 1u)
  {
    /* Charge Pump input voltage low threshold measured by ADC2-Ch2 */
    if (SCUPM->BDRV_IS.bit.VSD_LOWTH_IS == 1u)
    {
      ADC2_VSD_LO_CALLBACK();
      ADC2_VCP_UV_Int_Clr();
    }
  }
#endif /*(ADC2_VSD_LO_INT_EN == 1u) */

#if (ADC2_VSD_UP_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.VSD_UPTH_IE == 1u)
  {
    /* Charge Pump input voltage upper threshold measured by ADC2-Ch2 */
    if (SCUPM->BDRV_IS.bit.VSD_UPTH_IS == 1u)
    {
      ADC2_VSD_UP_CALLBACK();
      ADC2_VSD_OV_Int_Clr();
    }
  }
#endif /*(ADC2_VSD_UP_INT_EN == 1u) */

#if (ADC2_VSD_LO_INT_EN == 1u)
  if (SCUPM->BDRV_IRQ_CTRL.bit.VSD_LOWTH_IE == 1u)
  {
    /* Charge Pump input voltage lower threshold measured by ADC2-Ch2 */
    if (SCUPM->BDRV_IS.bit.VSD_LOWTH_IS == 1u)
    {
      ADC2_VSD_LO_CALLBACK();
      ADC2_VSD_UV_Int_Clr();
    }
  }
#endif /*(ADC2_VSD_LO_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      DMA ISR                                               **
*******************************************************************************/
#if ((DMA_SQ1_RDY_INT_EN == 1u) || \
     (DMA_SQ2_RDY_INT_EN) || \
     (DMA_SSC_TX_INT_EN) || \
     (DMA_SSC_RX_INT_EN) || \
     (DMA_CH1_INT_EN) || \
     (DMA_CH2_INT_EN) || \
     (DMA_CH3_INT_EN) || \
     (DMA_CH4_INT_EN) || \
     (DMA_CH5_INT_EN) || \
     (DMA_CH6_INT_EN) || \
     (DMA_CH7_INT_EN) || \
     (DMA_CH8_INT_EN) || \
     (DMA_GPT12E_INT_EN) )
void DMA_IRQHandler(void)
{
#if (DMA_CH1_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH1IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH1 == (uint8)1u)
    {
      DMA_CH1_CALLBACK();
      /* DMA Ch4 => ADC1.Ch0 */
      /* but DMA starts counting with '1', therefore Ch1 */
      DMA_CH4_Int_Clr();
    }
  }
#endif /*(DMA_CH1_INT_EN == 1u) */

#if (DMA_CH2_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH2IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH2 == (uint8)1u)
    {
      DMA_CH2_CALLBACK();
      /* DMA Ch5 => ADC1.Ch1 */
      /* but DMA starts counting with '1', therefore Ch2 */
      DMA_CH5_Int_Clr();
    }
  }
#endif /*(DMA_CH2_INT_EN == 1u) */

#if (DMA_CH3_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH3IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH3 == (uint8)1u)
    {
      DMA_CH3_CALLBACK();
      /* DMA Ch6 => ADC1.Ch2 */
      /* but DMA starts counting with '1', therefore Ch3 */
      DMA_CH6_Int_Clr();
    }
  }
#endif /*(DMA_CH3_INT_EN == 1u) */

#if (DMA_CH4_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH4IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH4 == (uint8)1u)
    {
      DMA_CH4_CALLBACK();
      /* DMA Ch7 => ADC1.Ch3 */
      /* but DMA starts counting with '1', therefore Ch4 */
      DMA_CH7_Int_Clr();
    }
  }
#endif /*(DMA_CH4_INT_EN == 1u) */

#if (DMA_CH5_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH5IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH5 == (uint8)1u)
    {
      DMA_CH5_CALLBACK();
      /* DMA Ch8 => ADC1.Ch4 */
      /* but DMA starts counting with '1', therefore Ch5 */
      DMA_CH8_Int_Clr();
    }
  }
#endif /*(DMA_CH5_INT_EN == 1u) */

#if (DMA_CH6_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH6IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH6 == (uint8)1u)
    {
      DMA_CH6_CALLBACK();
      /* DMA Ch9 => ADC1.Ch5 */
      /* but DMA starts counting with '1', therefore Ch6 */
      DMA_CH9_Int_Clr();
    }
  }
#endif /*(DMA_CH6_INT_EN == 1u) */

#if (DMA_CH7_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH7IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH7 == (uint8)1u)
    {
      DMA_CH7_CALLBACK();
      /* DMA Ch10 => ADC1.Ch6 */
      /* but DMA starts counting with '1', therefore Ch7 */
      DMA_CH10_Int_Clr();
    }
  }
#endif /*(DMA_CH7_INT_EN == 1u) */

#if (DMA_CH8_INT_EN == 1u)
  if (SCU->DMAIEN1.bit.CH8IE == 1u)
  {
    if ((uint8)SCU->DMAIRC1.bit.CH8 == (uint8)1u)
    {
      DMA_CH8_CALLBACK();
      /* DMA Ch11 => ADC1.Ch7 */
      /* but DMA starts counting with '1', therefore Ch8 */
      DMA_CH11_Int_Clr();
    }
  }
#endif /*(DMA_CH8_INT_EN == 1u) */

#if (DMA_SQ1_RDY_INT_EN == 1u)
  if (SCU->DMAIEN2.bit.TRSEQ1RDYIE == 1u)
  {
    if ((uint8)SCU->DMAIRC2.bit.TRSEQ1DY == (uint8)1u)
    {
      DMA_SQ1_RDY_CALLBACK();
      DMA_CH0_Int_Clr();
    }
  }
#endif /*(DMA_SQ1_RDY_INT_EN == 1u) */

#if (DMA_SQ2_RDY_INT_EN == 1u)
  if (SCU->DMAIEN2.bit.TRSEQ2RDYIE == 1u)
  {
    if ((uint8)SCU->DMAIRC2.bit.TRSEQ2DY == (uint8)1u)
    {
      DMA_SQ2_RDY_CALLBACK();
      DMA_CH1_Int_Clr();
    }
  }
#endif /*(DMA_SQ2_RDY_INT_EN == 1u) */

#if (DMA_SSC_TX_INT_EN == 1u)
  if (SCU->DMAIEN2.bit.SSCTXIE == 1u)
  {
    if ((uint8)SCU->DMAIRC2.bit.SSC1RDY == 1u)
    {
      DMA_SSC_TX_CALLBACK();
      DMA_CH2_Int_Clr();
    }
  }
#endif /*(DMA_SSC_TX_INT_EN == 1u) */

#if (DMA_SSC_RX_INT_EN == 1u)
  if (SCU->DMAIEN2.bit.SSCRXIE == 1u)
  {
    if ((uint8)SCU->DMAIRC2.bit.SSC2RDY == 1u)
    {
      DMA_SSC_RX_CALLBACK();
      DMA_CH3_Int_Clr();
    }
  }
#endif /*(DMA_SSC_RX_INT_EN == 1u) */

#if (DMA_GPT12E_INT_EN == 1u)
  if (SCU->DMAIEN2.bit.GPT12IE == 1u)
  {
    if ((uint8)SCU->DMAIRC2.bit.GPT12 == (uint8)1u)
    {
      DMA_GPT12E_CALLBACK();
      DMA_CH12_Int_Clr();
    }
  }
#endif /*(DMA_GPT12E_INT_EN == 1u) */
}
#endif

/*******************************************************************************
**                      NMI ISR                                               **
*******************************************************************************/
#if ((SCU_NMI_WDT_INT_EN == 1u) || \
     (SCU_NMI_PLL_INT_EN == 1u) || \
     (SCU_NMI_NVM_INT_EN == 1u) || \
     (SCU_NMI_OWD_INT_EN == 1u) || \
     (SCU_NMI_MAP_INT_EN == 1u) || \
	 (SCU_ECC_RAM_DB_INT_EN == 1u) || \
	 (SCU_ECC_NVM_DB_INT_EN == 1u)  || \
     (ADC2_SYS_TEMP_UP_INT_EN == 1u) || \
     (ADC2_SYS_TEMP_LO_INT_EN == 1u) || \
     (ADC2_PMU_TEMP_UP_INT_EN == 1u) || \
     (ADC2_PMU_TEMP_LO_INT_EN == 1u) || \
     (ADC2_VS_UP_INT_EN == 1u) || \
     (ADC2_VS_LO_INT_EN == 1u) || \
     (ADC2_VBAT_UP_INT_EN == 1u) || \
     (ADC2_VBAT_LO_INT_EN == 1u) || \
     (ADC2_VDDC_UP_INT_EN == 1u) || \
     (ADC2_VDDC_LO_INT_EN == 1u) || \
     (ADC2_VDDP_UP_INT_EN == 1u) || \
     (ADC2_VDDP_LO_INT_EN == 1u) || \
     (ADC2_MON_UP_INT_EN == 1u) || \
     (ADC2_MON_LO_INT_EN == 1u) || \
     (PMU_VDDEXT_SHORT_INT_EN == 1u) || \
     (PMU_VDDEXT_OV_INT_EN == 1u) || \
     (PMU_VDDEXT_OL_INT_EN == 1u) || \
     (PMU_VDDC_OV_INT_EN == 1u) || \
     (PMU_VDDC_OL_INT_EN == 1u) || \
     (PMU_VDDP_OV_INT_EN == 1u) || \
     (PMU_VDDP_OL_INT_EN == 1u))
void NMI_Handler(void)
{
#if (SCU_NMI_WDT_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIWDT == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIWDT == (uint8)1u)
    {
      SCU_NMI_WDT_CALLBACK();
      NMI_WDT_Int_Clr();
    }
  }
#endif /*((SCU_NMICON & (1u << 0u)) != 0u) */

#if (SCU_NMI_PLL_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIPLL == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIPLL == (uint8)1u)
    {
      SCU_NMI_PLL_CALLBACK();
      NMI_PLL_Int_Clr();
    }
  }
#endif /*((SCU_NMICON & (1u << 1u)) != 0u) */

#if (SCU_NMI_NVM_INT_EN == 1u)
  if (SCU->NMICON.bit.NMINVM == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMINVM == (uint8)1u)
    {
      SCU_NMI_NVM_CALLBACK();
      NMI_NVM_Int_Clr();
    }
  }
#endif /*((SCU_NMICON & (1u << 2u)) != 0u) */

#if ((ADC2_SYS_TEMP_UP_INT_EN == 1u) || \
     (ADC2_SYS_TEMP_LO_INT_EN == 1u) || \
     (ADC2_PMU_TEMP_UP_INT_EN == 1u) || \
     (ADC2_PMU_TEMP_LO_INT_EN == 1u) )
  if ((uint8)SCU->NMISR.bit.FNMIOT == (uint8)1u)
  {
    NMI_OT_Int_Clr();

#if (ADC2_SYS_TEMP_LO_INT_EN == 1u)
    if (SCUPM->SYS_IRQ_CTRL.bit.SYS_OTWARN_IE == 1u)
    {
      if (SCUPM->SYS_IS.bit.SYS_OTWARN_IS == 1u)
      {
        ADC2_SYS_TEMP_LO_CALLBACK();
        ADC2_TEMP_WARN_Int_Clr();
      }
    }
#endif /*((SCU_SYS_IRQ_CTRL & (1u << 8u)) != 0u) */

#if (ADC2_SYS_TEMP_UP_INT_EN == 1u)
    if (SCUPM->SYS_IRQ_CTRL.bit.SYS_OT_IE == 1u)
    {
      if (SCUPM->SYS_IS.bit.SYS_OT_IS == 1u)
      {
        ADC2_SYS_TEMP_UP_CALLBACK();
        ADC2_TEMP_OT_Int_Clr();
      }
    }
#endif /*((SCU_SYS_IRQ_CTRL & (1u << 9u)) != 0u) */

#if (ADC2_PMU_TEMP_LO_INT_EN == 1u)
    if (SCUPM->SYS_IRQ_CTRL.bit.PMU_OTWARN_IE == 1u)
    {
      if (SCUPM->SYS_IS.bit.PMU_OTWARN_IS == 1u)
      {
        ADC2_PMU_TEMP_LO_CALLBACK();
        ADC2_TEMP_WARN_Int_Clr();
      }
    }
#endif /*((SCU_SYS_IRQ_CTRL & (1u << 6u)) != 0u) */

#if (ADC2_PMU_TEMP_UP_INT_EN == 1u)
    if (SCUPM->SYS_IRQ_CTRL.bit.PMU_OT_IE == 1u)
    {
      if (SCUPM->SYS_IS.bit.PMU_OT_IS == 1u)
      {
        ADC2_PMU_TEMP_UP_CALLBACK();
        ADC2_TEMP_OT_Int_Clr();
      }
    }
#endif /*((SCU_SYS_IRQ_CTRL & (1u << 7u)) != 0u) */
  }
#endif /*((SCU_NMICON & (1u << 3u)) != 0u) */


#if (SCU_NMI_OWD_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIOWD == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIOWD == (uint8)1u)
    {
      SCU_NMI_OWD_CALLBACK();
      NMI_OWD_Int_Clr();
    }
  }
#endif /*((SCU_NMICON & (1u << 4u)) != 0u) */

#if (SCU_NMI_MAP_INT_EN == 1u)
  if (SCU->NMICON.bit.NMIMAP == 1u)
  {
    if ((uint8)SCU->NMISR.bit.FNMIMAP == (uint8)1u)
    {
      SCU_NMI_MAP_CALLBACK();
      NMI_MAP_Int_Clr();
    }
  }
#endif /*((SCU_NMICON & (1u << 5u)) != 0u) */

#if ((SCU_ECC_RAM_DB_INT_EN == 1u) || \
     (SCU_ECC_NVM_DB_INT_EN == 1u))
  if ((uint8)SCU->NMISR.bit.FNMIECC == (uint8)1u)
  {
    NMI_ECC_Int_Clr();

#if (SCU_ECC_RAM_DB_INT_EN == 1u)
    if (SCU->EDCCON.bit.RIE == 1u)
    {
      if ((uint8)SCU->EDCSTAT.bit.RDBE == (uint8)1u)
      {
        SCU_ECC_RAM_DB_CALLBACK();
        ECC_RAM_DoubleBit_Int_Clr();
      }
    }
#endif /*((SCU_EDCCON & (1u << 0u)) != 0u) */

#if (SCU_ECC_NVM_DB_INT_EN == 1u)
    if (SCU->EDCCON.bit.NVMIE == 1u)
    {
      if ((uint8)SCU->EDCSTAT.bit.NVMDBE == (uint8)1u)
      {
        SCU_ECC_NVM_DB_CALLBACK();
        ECC_NVM_DoubleBit_Int_Clr();
      }
    }
#endif /*((SCU_EDCCON & (1u << 2u)) != 0u) */
  }
#endif /*((SCU_NMICON & (1u << 6u)) != 0u) */

#if ((ADC2_VS_UP_INT_EN == 1u) || \
     (ADC2_VS_LO_INT_EN == 1u) || \
     (ADC2_VBAT_UP_INT_EN == 1u) || \
     (ADC2_VBAT_LO_INT_EN == 1u) || \
     (ADC2_VDDC_UP_INT_EN == 1u) || \
     (ADC2_VDDC_LO_INT_EN == 1u) || \
     (ADC2_VDDP_UP_INT_EN == 1u) || \
     (ADC2_VDDP_LO_INT_EN == 1u) || \
     (ADC2_MON_UP_INT_EN == 1u) || \
     (ADC2_MON_LO_INT_EN == 1u) || \
     (PMU_VDDEXT_SHORT_INT_EN == 1u) || \
     (PMU_VDDEXT_OV_INT_EN == 1u) || \
     (PMU_VDDEXT_OL_INT_EN == 1u) || \
     (PMU_VDDC_OV_INT_EN == 1u) || \
     (PMU_VDDC_OL_INT_EN == 1u) || \
     (PMU_VDDP_OV_INT_EN == 1u) || \
     (PMU_VDDP_OL_INT_EN == 1u))
  if ((uint8)SCU->NMISR.bit.FNMISUP == (uint8)1u)
  {
    NMI_SUP_Int_Clr();

#if (ADC2_VDDC_UP_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_OV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD1V5_OV_IS == 1u)
      {
        ADC2_VDDC_UP_CALLBACK();
        ADC2_VDDC_OV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 7u)) != 0u) */

#if (ADC2_VDDC_LO_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD1V5_UV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD1V5_UV_IS == 1u)
      {
        ADC2_VDDC_LO_CALLBACK();
        ADC2_VDDC_UV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 3u)) != 0u) */

#if (ADC2_VDDP_UP_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_OV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD5V_OV_IS == 1u)
      {
        ADC2_VDDP_UP_CALLBACK();
        ADC2_VDDP_OV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 6u)) != 0u) */

#if (ADC2_VDDP_LO_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VDD5V_UV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VDD5V_UV_IS == 1u)
      {
        ADC2_VDDP_LO_CALLBACK();
        ADC2_VDDP_UV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 2u)) != 0u) */

#if (ADC2_VS_UP_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_OV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VS_OV_IS == 1u)
      {
        ADC2_VS_UP_CALLBACK();
        ADC2_VS_OV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 5u)) != 0u) */

#if (ADC2_VS_LO_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VS_UV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VS_UV_IS == 1u)
      {
        ADC2_VS_LO_CALLBACK();
        ADC2_VS_UV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 1u)) != 0u) */
    
#if (UC_SERIES == TLE986)
#if (ADC2_VBAT_UP_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_OV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_OV_IE == 1u)
      {
        ADC2_VBAT_UP_CALLBACK();
        ADC2_VBAT_OV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 4u)) != 0u) */

#if (ADC2_VBAT_LO_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.VBAT_UV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.VBAT_UV_IS == 1u)
      {
        ADC2_VBAT_LO_CALLBACK();
        ADC2_VBAT_UV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 0u)) != 0u) */
#endif /* UC_DEVICE == TLE986 */

#if (UC_SERIES == TLE987)
#if (ADC2_MON_UP_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.MON_OV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.MON_OV_IS == 1u)
      {
        ADC2_MON_UP_CALLBACK();
        ADC2_MON_OV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 4u)) != 0u) */

#if (ADC2_MON_LO_INT_EN == 1u)
    if (SCUPM->SYS_SUPPLY_IRQ_CTRL.bit.MON_UV_IE == 1u)
    {
      if (SCUPM->SYS_SUPPLY_IRQ_STS.bit.MON_UV_IS == 1u)
      {
        ADC2_MON_LO_CALLBACK();
        ADC2_MON_UV_Int_Clr();
      }
    }
#endif /*((SCU_SYS_SUPPLY_IRQ_CTRL & (1u << 0u)) != 0u) */
#endif /* UC_DEVICE == TLE987 */

#if ((PMU_VDDC_OV_INT_EN == 1u) || \
     (PMU_VDDC_OL_INT_EN == 1u))
    if (PMU->PMU_SUPPLY_STS.bit.PMU_1V5_FAIL_EN == 1u)
    {
    #if (PMU_VDDC_OV_INT_EN == 1u)
      if ((uint8)PMU->PMU_SUPPLY_STS.bit.PMU_1V5_OVERVOLT == (uint8)1u)
      {
        PMU_VDDC_OV_CALLBACK();
      }
    #endif
    #if (PMU_VDDC_OL_INT_EN == 1u)
      if ((uint8)PMU->PMU_SUPPLY_STS.bit.PMU_1V5_OVERLOAD == (uint8)1u)
      {
        PMU_VDDC_OL_CALLBACK();
      }
    #endif
    }
#endif /*((PMU_PMU_SUPPLY_STS & (1u << 0u)) != 0u) */

#if ((PMU_VDDP_OV_INT_EN == 1u) || \
     (PMU_VDDP_OL_INT_EN == 1u))
    if (PMU->PMU_SUPPLY_STS.bit.PMU_5V_FAIL_EN == 1u)
    {
    #if (PMU_VDDP_OV_INT_EN == 1u)
      if ((uint8)PMU->PMU_SUPPLY_STS.bit.PMU_5V_OVERVOLT == (uint8)1u)
      {
        PMU_VDDP_OV_CALLBACK();
      }
    #endif
    #if (PMU_VDDP_OL_INT_EN == 1u)
      if ((uint8)PMU->PMU_SUPPLY_STS.bit.PMU_5V_OVERLOAD == (uint8)1u)
      {
        PMU_VDDP_OL_CALLBACK();
      }
    #endif
    }
#endif /*((PMU_PMU_SUPPLY_STS & (1u << 6u)) != 0u) */

#if ((PMU_VDDEXT_SHORT_INT_EN == 1u) || \
     (PMU_VDDEXT_OV_INT_EN == 1u) || \
     (PMU_VDDEXT_OL_INT_EN == 1u) )
    if (PMU->VDDEXT_CTRL.bit.FAIL_EN == 1u)
    {
      #if ((PMU_VDDEXT_FAIL & (1u << 1u)) != 0u)
        if ((uint8)PMU->VDDEXT_CTRL.bit.OVERVOLT == (uint8)1u)
        {
          PMU_VDDEXT_OV_CALLBACK();
        }
      #endif
      #if ((PMU_VDDEXT_FAIL & (1u << 2u)) != 0u)
        if ((uint8)PMU->VDDEXT_CTRL.bit.OVERLOAD == (uint8)1u)
        {
          PMU_VDDEXT_OL_CALLBACK();
        }
      #endif
      #if ((PMU_VDDEXT_FAIL & (1u << 0u)) != 0u)
        if ((uint8)PMU->VDDEXT_CTRL.bit.SHORT == (uint8)1u)
        {
          PMU_VDDEXT_SHORT_CALLBACK();
        }
      #endif
    }
#endif /*(PMU_VDDEXT_IE == 1u) */
  }
#endif /*((SCU_NMICON & (1u << 7u)) != 0u) */
}
#endif

/*lint +e9032 */
/*lint +e9053 */

/*******************************************************************************
**                      HardFault ISR                                         **
*******************************************************************************/
void HardFault_Handler(void)
{
#if (CPU_HARDFAULT_EN == 1)
    CPU_HARDFAULT_CALLBACK();
#endif /*(CPU_HARDFAULT_EN == u)*/
}

/*******************************************************************************
**                      MemManage ISR                                         **
*******************************************************************************/
void MemManage_Handler(void)
{
#if (CPU_MEMMANAGE_EN == 1)
    CPU_MEMMANAGE_CALLBACK();
#endif /*(CPU_MEMMANAGE_EN == 1)*/
}

/*******************************************************************************
**                      BusFault ISR                                          **
*******************************************************************************/
void BusFault_Handler(void)
{
#if (CPU_BUSFAULT_EN == 1)
    CPU_BUSFAULT_CALLBACK();
#endif /*(CPU_BUSFAULT_EN == 1)*/
}

/*******************************************************************************
**                      UsageFault ISR                                        **
*******************************************************************************/
void UsageFault_Handler(void)
{
#if (CPU_USAGEFAULT_EN == 1)
    CPU_USAGEFAULT_CALLBACK();
#endif /*(CPU_USAGEFAULT_EN == 1)*/
}

/*******************************************************************************
**                      SysTick ISR                                           **
*******************************************************************************/
void SysTick_Handler(void)
{
#if (CPU_SYSTICK_EN == 1)
    CPU_SYSTICK_CALLBACK();
#endif /*(CPU_SYSTICK_EN == 1)*/

  WDT1_Window_Count();
}
#endif /* INT_XML_VERSION < 0x10300 */

