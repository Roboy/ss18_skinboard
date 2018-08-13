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
**                                                                            **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.1.3: 2017-07-20, DM:   API macros added
 * V0.1.2: 2017-07-12, DM:   setup task for scatter-gather added
 * V0.1.1: 2017-07-09, DM:   interrupt macros added, scatter-gather support
 *                           added 
 * V0.1.0: 2015-11-25, DM:   inital version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include <dma.h>

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#if (DMA_XML_VERSION >= 10200)
#if ((DMA_EN & (1u << DMA_CH0)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_SEQ1  __attribute__((at(DMA_BASE_ADDR + DMA_CH0 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH0_TRANS_MODE == 0u)
	  #if ((DMA_CH0_SRC_SEL == 1u) && (DMA_CH0_SRC_EXT == 1u))
		extern void DMA_CH0_SRC;
	  #endif
	  #if (DMA_CH0_DST_EXT == 1u)
		extern void DMA_CH0_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_SEQ1_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH0 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH0_TASK_SRC;
  #endif /* (DMA_CH0_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH1)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_ESM   __attribute__((at(DMA_BASE_ADDR + DMA_CH1 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH1_TRANS_MODE == 0u)
	  #if ((DMA_CH1_SRC_SEL == 1u) && (DMA_CH1_SRC_EXT == 1u))
		extern void DMA_CH1_SRC;
	  #endif
	  #if (DMA_CH1_DST_EXT == 1u)
		extern void DMA_CH1_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_ESM_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH1 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH1_TASK_SRC;
  #endif /* (DMA_CH1_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH2)) != 0u)
  TDMA_Entry DMA_Entry_SSC1_Tx    __attribute__((at(DMA_BASE_ADDR + DMA_CH2 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH2_TRANS_MODE == 0u)
	  #if (DMA_CH2_SRC_EXT == 1u)
		extern void DMA_CH2_SRC;
	  #endif
	  #if ((DMA_CH2_DST_SEL == 1u) && (DMA_CH2_DST_EXT == 1u))
		extern void DMA_CH2_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_SSC1_Tx_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH2 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH2_TASK_SRC;
  #endif /* (DMA_CH2_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH3)) != 0u)
  TDMA_Entry DMA_Entry_SSC1_Rx    __attribute__((at(DMA_BASE_ADDR + DMA_CH3 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH3_TRANS_MODE == 0u)
	  #if ((DMA_CH3_SRC_SEL == 1u) && (DMA_CH3_SRC_EXT == 1u))
		extern void DMA_CH3_SRC;
	  #endif
	  #if (DMA_CH3_DST_EXT == 1u)
		extern void DMA_CH3_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_SSC1_Rx_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH3 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH3_TASK_SRC;
  #endif /* (DMA_CH3_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH4)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch0   __attribute__((at(DMA_BASE_ADDR + DMA_CH4 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH4_TRANS_MODE == 0u)
	  #if ((DMA_CH4_SRC_SEL == 1u) && (DMA_CH4_SRC_EXT == 1u))
		extern void DMA_CH4_SRC;
	  #endif
	  #if (DMA_CH4_DST_EXT == 1u)
		extern void DMA_CH4_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch0_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH4 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH4_TASK_SRC;
  #endif /* (DMA_CH4_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH5)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch1   __attribute__((at(DMA_BASE_ADDR + DMA_CH5 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH5_TRANS_MODE == 0u)
	  #if ((DMA_CH5_SRC_SEL == 1u) && (DMA_CH5_SRC_EXT == 1u))
		extern void DMA_CH5_SRC;
	  #endif
	  #if (DMA_CH5_DST_EXT == 1u)
		extern void DMA_CH5_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch1_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH5 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH5_TASK_SRC;
  #endif /* (DMA_CH5_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH6)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch2   __attribute__((at(DMA_BASE_ADDR + DMA_CH6 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH6_TRANS_MODE == 0u)
	  #if ((DMA_CH6_SRC_SEL == 1u) && (DMA_CH6_SRC_EXT == 1u))
		extern void DMA_CH6_SRC;
	  #endif
	  #if (DMA_CH6_DST_EXT == 1u)
		extern void DMA_CH6_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch2_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH6 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH6_TASK_SRC;
  #endif /* (DMA_CH6_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH7)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch3   __attribute__((at(DMA_BASE_ADDR + DMA_CH7 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH7_TRANS_MODE == 0u)
	  #if ((DMA_CH7_SRC_SEL == 1u) && (DMA_CH7_SRC_EXT == 1u))
		extern void DMA_CH7_SRC;
	  #endif
	  #if (DMA_CH7_DST_EXT == 1u)
		extern void DMA_CH7_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch3_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH7 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH7_TASK_SRC;
  #endif /* (DMA_CH7_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH8)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch4   __attribute__((at(DMA_BASE_ADDR + DMA_CH8 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH8_TRANS_MODE == 0u)
	  #if ((DMA_CH8_SRC_SEL == 1u) && (DMA_CH8_SRC_EXT == 1u))
		extern void DMA_CH8_SRC;
	  #endif
	  #if (DMA_CH8_DST_EXT == 1u)
		extern void DMA_CH8_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch4_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH8 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH8_TASK_SRC;
  #endif /* (DMA_CH8_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH9)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch5   __attribute__((at(DMA_BASE_ADDR + DMA_CH9 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH9_TRANS_MODE == 0u)
	  #if ((DMA_CH9_SRC_SEL == 1u) && (DMA_CH9_SRC_EXT == 1u))
		extern void DMA_CH9_SRC;
	  #endif
	  #if (DMA_CH9_DST_EXT == 1u)
		extern void DMA_CH9_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch5_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH9 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH9_TASK_SRC;
  #endif /* (DMA_CH9_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH10)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch6   __attribute__((at(DMA_BASE_ADDR + DMA_CH10 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH10_TRANS_MODE == 0u)
	  #if ((DMA_CH10_SRC_SEL == 1u) && (DMA_CH10_SRC_EXT == 1u))
		extern void DMA_CH10_SRC;
	  #endif
	  #if (DMA_CH10_DST_EXT == 1u)
		extern void DMA_CH10_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch6_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH10 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH10_TASK_SRC;
  #endif /* (DMA_CH10_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH11)) != 0u)
  TDMA_Entry DMA_Entry_ADC1_Ch7   __attribute__((at(DMA_BASE_ADDR + DMA_CH11 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH11_TRANS_MODE == 0u)
	  #if (DMA_CH11_SRC_EXT == 1u)
		extern void DMA_CH11_SRC;
	  #endif
	  #if (DMA_CH11_DST_EXT == 1u)
		extern void DMA_CH11_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_ADC1_Ch7_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH11 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH11_TASK_SRC;
  #endif /* (DMA_CH11_TRANS_MODE == 0u) */
#endif
#if ((DMA_EN & (1u << DMA_CH12)) != 0u)
  TDMA_Entry DMA_Entry_Timer3     __attribute__((at(DMA_BASE_ADDR + DMA_CH12 * sizeof(TDMA_Entry)),used));
  #if (DMA_CH12_TRANS_MODE == 0u)
	  #if (DMA_CH12_SRC_EXT == 1u)
		extern void DMA_CH12_SRC;
	  #endif
	  #if ((DMA_CH12_DST_SEL == 1u) && (DMA_CH12_DST_EXT == 1u))
		extern void DMA_CH12_DST;
	  #endif
  #else
	TDMA_Entry DMA_Entry_Timer3_Alt  __attribute__((at((DMA_BASE_ADDR + 0x100) + DMA_CH12 * sizeof(TDMA_Entry)),used));
	extern void DMA_CH12_TASK_SRC;
  #endif /* (DMA_CH12_TRANS_MODE == 0u) */
#endif

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief manually sets up a DMA channel, Basic Mode
 *
 * \param Channel Index, Source Address, Destination Address
 *        Count, Datawidth, Increment
 * \return None
 *
 * \ingroup drv_api
 */
void DMA_Setup_Channel(uint32 DMA_ChIdx, uint32 addr_src, uint32 addr_dst, 
                       uint32 trans_cnt, uint32 datawidth, uint32 increment)
{
  TDMA_Entry* entry = (TDMA_Entry*)(DMA_BASE_ADDR+DMA_ChIdx*sizeof(TDMA_Entry));
  
  entry->Src_End_Ptr = addr_src + trans_cnt * (1u << (datawidth - 1u));
  entry->Dst_End_Ptr = addr_dst + trans_cnt * (1u << (datawidth - 1u));
  /* Basic Transfere */
  entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
  /* */
  entry->Control.bit.Next_UseBurst = 0;
  /* number of transfers minus 1 */
  entry->Control.bit.N_Minus_1 = trans_cnt - 1;
  /* Arbitrates after each DMA Trans */
  entry->Control.bit.R_Power = 0;
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Src_Size = datawidth;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Dst_Size = datawidth;
  switch (increment)
  {
    case DMA_Src_Inc:
    {
      entry->Control.bit.Src_Inc = datawidth;
      entry->Control.bit.Dst_Inc = DMA_No_Inc;
    } break;
    case DMA_Dst_Inc:
    {
      entry->Control.bit.Src_Inc = DMA_No_Inc;
      entry->Control.bit.Dst_Inc = datawidth;
    } break;
    case DMA_Src_Dst_Inc:
    {
      entry->Control.bit.Src_Inc = datawidth;
      entry->Control.bit.Dst_Inc = datawidth;
    } break;
    default:
    {
      entry->Control.bit.Src_Inc = DMA_No_Inc;
      entry->Control.bit.Dst_Inc = DMA_No_Inc;
    } break;
  }
  /* set DMA structure base pointer */
  DMA->CTRL_BASE_PTR.reg = DMA_BASE_ADDR;

  /* enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1 << DMA_ChIdx);  
}

/** \brief set a DMA Channel for Memory Scatter-Gather Mode
 
 * \param Channel Index, Task List, Number of Tasks
 * \return None
 *
 * \ingroup drv_api
 */
void DMA_Channel_MemSctGth_Set(uint32 DMA_ChIdx, TDMA_Entry* Task_List, uint32 NoOfTasks)
{
  uint32 BASE_ADDR;
  TDMA_Entry* entry;
  
  /* get DMA structure base pointer */
  BASE_ADDR = DMA->CTRL_BASE_PTR.reg;
	
 entry = (TDMA_Entry*)(BASE_ADDR + DMA_ChIdx * sizeof(TDMA_Entry));
  
  /* Scatter-Gather Transfer */
  entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
  /* */
  entry->Control.bit.Next_UseBurst = 0;
  /* number of transfers  */
  entry->Control.bit.N_Minus_1 = (NoOfTasks * 4) - 1u;
  /* Arbitrates after one Task trans (4 DMA trans)*/
  entry->Control.bit.R_Power = 2;
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;

  entry->Control.bit.Src_Inc = DMA_32Bit_Transfer;
  entry->Control.bit.Dst_Inc = DMA_32Bit_Transfer;
  entry->Src_End_Ptr = (uint32)Task_List + ((NoOfTasks * 4u) - 1u) * (1u << DMA_32Bit_Transfer);
  entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_ChIdx * sizeof(TDMA_Entry)) + 12u;
}

/** \brief set a DMA Channel for Periphery Scatter-Gather Mode
 
 * \param Channel Index, Task List, Number of Tasks
 * \return None
 *
 * \ingroup drv_api
 */
void DMA_Channel_PerSctGth_Set(uint32 DMA_ChIdx, TDMA_Entry* Task_List, uint32 NoOfTasks)
{
  uint32 BASE_ADDR;
  TDMA_Entry* entry;
  
  /* get DMA structure base pointer */
  BASE_ADDR = DMA->CTRL_BASE_PTR.reg;
	
  entry = (TDMA_Entry*)(BASE_ADDR + DMA_ChIdx * sizeof(TDMA_Entry));
  
  /* Scatter-Gather Transfer */
  entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_PerSctGthPrim;
  /* */
  entry->Control.bit.Next_UseBurst = 0;
  /* number of transfers  */
  entry->Control.bit.N_Minus_1 = (NoOfTasks * 4) - 1u;
  /* Arbitrates after one Task trans (4 DMA trans)*/
  entry->Control.bit.R_Power = 2;
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;

  entry->Control.bit.Src_Inc = DMA_32Bit_Transfer;
  entry->Control.bit.Dst_Inc = DMA_32Bit_Transfer;
  entry->Src_End_Ptr = (uint32)Task_List + ((NoOfTasks * 4u) - 1u) * (1u << DMA_32Bit_Transfer);
  entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_ChIdx * sizeof(TDMA_Entry)) + 12u;
}

/** \brief manually sets up a DMA channel
 *
 * \param Channel Index, Source Address, Destination Address
 *        Count, Datawidth, Increment
 * \return None
 *
 * \ingroup drv_api
 */
TDMA_Entry* DMA_Task_Set(TDMA_Entry* entry, uint8 cycle_type, uint8 arb_rate, uint32 addr_src, uint32 addr_dst, 
                         uint32 trans_cnt, uint32 datawidth, uint32 increment)
{
  /* Scatter-Gather Transfer */
  entry->Control.bit.Cycle_Ctrl = cycle_type;
  /* */
  entry->Control.bit.Next_UseBurst = 0;
  /* number of transfers  */
  entry->Control.bit.N_Minus_1 = trans_cnt - 1;
  /* Arbitrates after each DMA Trans */
  entry->Control.bit.R_Power = arb_rate;
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Src_Size = datawidth;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Dst_Size = datawidth;
  switch (increment)
  {
    case DMA_Src_Inc:
    {
      entry->Control.bit.Src_Inc = datawidth;
      entry->Control.bit.Dst_Inc = DMA_No_Inc;
      entry->Src_End_Ptr = addr_src + (trans_cnt - 1) * (1u << datawidth);
      entry->Dst_End_Ptr = addr_dst;
    } break;
    case DMA_Dst_Inc:
    {
      entry->Control.bit.Src_Inc = DMA_No_Inc;
      entry->Control.bit.Dst_Inc = datawidth;
      entry->Src_End_Ptr = addr_src;
      entry->Dst_End_Ptr = addr_dst + (trans_cnt - 1) * (1u << datawidth);
    } break;
    case DMA_Src_Dst_Inc:
    {
      entry->Control.bit.Src_Inc = datawidth;
      entry->Control.bit.Dst_Inc = datawidth;
      entry->Src_End_Ptr = addr_src + (trans_cnt - 1) * (1u << datawidth);
      entry->Dst_End_Ptr = addr_dst + (trans_cnt - 1) * (1u << datawidth);
    } break;
    default:
    {
      entry->Control.bit.Src_Inc = DMA_No_Inc;
      entry->Control.bit.Dst_Inc = DMA_No_Inc;
      entry->Src_End_Ptr = addr_src;
      entry->Dst_End_Ptr = addr_dst;
    } break;
  }
	return (entry);
}

/** \brief manually sets up a DMA channel for Scatter Gather
 *
 * \param Channel Index, Source Address, Destination Address
 *        Count, Datawidth, Increment
 * \return None
 *
 * \ingroup drv_api
 */
TDMA_Entry* DMA_Task_SctGth_Set(TDMA_Entry* entry, uint8 DMA_Ch, TDMA_Entry* Task_List, uint32 NoOfTask)
{
  /* Scatter-Gather Transfer */
  entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
  /* */
  entry->Control.bit.Next_UseBurst = 0;
  /* number of transfers  */
  entry->Control.bit.N_Minus_1 = (NoOfTask * 4) - 1;
  /* Arbitrates after each DMA Trans */
  entry->Control.bit.R_Power = 2;
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
  /* datawidth of the data to be transferred */
  entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
  /* source increment */
  entry->Control.bit.Src_Inc = 2u;
  /* destination increment */
  entry->Control.bit.Dst_Inc = 2u;
  /* source end pointer, points to last task in task list */
  entry->Src_End_Ptr = (uint32)Task_List + ((NoOfTask * 4) - 1u) * (1u << DMA_32Bit_Transfer);
  /* destination pointer, points to channel index in alternate stucture */
  entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_Ch * sizeof(TDMA_Entry)) + 0xC;
	return (entry);
}

/** \brief manually resets up a DMA channel
 *
 * \param Channel Index, Source Address, Destination Address
 *        Count
 * \return None
 *
 * \ingroup drv_api
 */
void DMA_Reset_Channel(uint32 DMA_ChIdx, uint32 trans_cnt)
{
  uint32 BASE_ADDR;
  TDMA_Entry* entry;
  
  /* get DMA structure base pointer */
  BASE_ADDR = DMA->CTRL_BASE_PTR.reg;

  entry = (TDMA_Entry*)(BASE_ADDR + DMA_ChIdx * sizeof(TDMA_Entry));

  /* number of transfers minus 1 */
  entry->Control.bit.N_Minus_1 = trans_cnt - 1;
  /* Basic Transfere */
  entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
  /* enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1 << DMA_ChIdx);  
}

/** \brief Initializes the DMA module and data structure.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void DMA_Init(void)
{
#if (DMA_EN != 0u)
  TDMA_Entry* entry;
#endif
  /* set DMA structure base pointer */
  DMA->CTRL_BASE_PTR.reg = DMA_BASE_ADDR;

#if ((DMA_EN & (1u << DMA_CH0)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH0 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH0_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH0_SRC + DMA_CH0_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH0_DST + DMA_CH0_DST_PTR_OFFS;
    
    entry->Control.bit.Dst_Inc = DMA_CH0_INC & 2u ? DMA_CH0_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH0_INC & 1u ? DMA_CH0_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH0_SIZE;
    entry->Control.bit.Src_Size = DMA_CH0_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH0_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH0_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH0_TASK_SRC + ((DMA_CH0_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH0 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH0_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH1)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR+DMA_CH1 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH1_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH1_SRC + DMA_CH1_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH1_DST + DMA_CH1_DST_PTR_OFFS;
  
    entry->Control.bit.Dst_Inc = DMA_CH1_INC & 2u ? DMA_CH1_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH1_INC & 1u ? DMA_CH1_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH1_SIZE;
    entry->Control.bit.Src_Size = DMA_CH1_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH1_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH1_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH1_TASK_SRC + ((DMA_CH1_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH1 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH1_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH2)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH2 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH2_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH2_SRC + DMA_CH2_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH2_DST + DMA_CH2_DST_PTR_OFFS;
  
    entry->Control.bit.Dst_Inc = DMA_CH2_INC & 2u ? DMA_CH2_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH2_INC & 1u ? DMA_CH2_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH2_SIZE;
    entry->Control.bit.Src_Size = DMA_CH2_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH2_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH2_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH2_TASK_SRC + ((DMA_CH2_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH2 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH2_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH3)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH3 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH3_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH3_SRC + DMA_CH3_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH3_DST + DMA_CH3_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH3_INC & 2u ? DMA_CH3_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH3_INC & 1u ? DMA_CH3_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH3_SIZE;
    entry->Control.bit.Src_Size = DMA_CH3_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH3_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH3_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH3_TASK_SRC + ((DMA_CH3_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH3 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH3_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH4)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH4 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH4_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH4_SRC + DMA_CH4_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH4_DST + DMA_CH4_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH4_INC & 2u ? DMA_CH4_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH4_INC & 1u ? DMA_CH4_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH4_SIZE;
    entry->Control.bit.Src_Size = DMA_CH4_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH4_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH4_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH4_TASK_SRC + ((DMA_CH4_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH4 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH4_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH5)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH5 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH5_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH5_SRC + DMA_CH5_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH5_DST + DMA_CH5_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH5_INC & 2u ? DMA_CH5_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH5_INC & 1u ? DMA_CH5_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH5_SIZE;
    entry->Control.bit.Src_Size = DMA_CH5_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH5_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH5_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH5_TASK_SRC + ((DMA_CH5_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH5 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH5_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH6)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH6 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH6_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH6_SRC + DMA_CH6_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH6_DST + DMA_CH6_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH6_INC & 2u ? DMA_CH6_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH6_INC & 1u ? DMA_CH6_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH6_SIZE;
    entry->Control.bit.Src_Size = DMA_CH6_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH6_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH6_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH6_TASK_SRC + ((DMA_CH6_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH6 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH6_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH7)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH7 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH7_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH7_SRC + DMA_CH7_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH7_DST + DMA_CH7_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH7_INC & 2u ? DMA_CH7_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH7_INC & 1u ? DMA_CH7_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH7_SIZE;
    entry->Control.bit.Src_Size = DMA_CH7_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH7_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH7_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH7_TASK_SRC + ((DMA_CH7_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH7 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH7_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH8)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH8 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH8_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH8_SRC + DMA_CH8_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH8_DST + DMA_CH8_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH8_INC & 2u ? DMA_CH8_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH8_INC & 1u ? DMA_CH8_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH8_SIZE;
    entry->Control.bit.Src_Size = DMA_CH8_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH8_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH8_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH8_TASK_SRC + ((DMA_CH8_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH8 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH8_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH9)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH9 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH9_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH9_SRC + DMA_CH9_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH9_DST + DMA_CH9_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH9_INC & 2u ? DMA_CH9_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH9_INC & 1u ? DMA_CH9_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH9_SIZE;
    entry->Control.bit.Src_Size = DMA_CH9_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH9_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH9_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH9_TASK_SRC + ((DMA_CH9_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH9 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH9_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH10)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH10 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH10_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH10_SRC + DMA_CH10_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH10_DST + DMA_CH10_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH10_INC & 2u ? DMA_CH10_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH10_INC & 1u ? DMA_CH10_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH10_SIZE;
    entry->Control.bit.Src_Size = DMA_CH10_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH10_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH10_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH10_TASK_SRC + ((DMA_CH10_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH10 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH10_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH11)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH11 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH11_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH11_SRC + DMA_CH11_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH11_DST + DMA_CH11_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH11_INC & 2u ? DMA_CH11_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH11_INC & 1u ? DMA_CH11_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH11_SIZE;
    entry->Control.bit.Src_Size = DMA_CH11_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH11_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH11_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH11_TASK_SRC + ((DMA_CH11_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH11 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH11_TRANS_MODE == 0u) */
#endif

#if ((DMA_EN & (1u << DMA_CH12)) != 0u)
  entry = (TDMA_Entry*)(DMA_BASE_ADDR + DMA_CH12 * sizeof(TDMA_Entry));
  /* HPROT control */
  entry->Control.bit.Src_Prot_Ctrl = 7u;
  /* HPROT control */
  entry->Control.bit.Dst_Prot_Ctrl = 7u;
  #if (DMA_CH12_TRANS_MODE == 0u)
    /* Basic Transfere */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_Basic;
    /* */
    entry->Control.bit.Next_UseBurst = 0;
    /* load source pointer */
    entry->Src_End_Ptr = (uint32)&DMA_CH12_SRC + DMA_CH12_SRC_PTR_OFFS;
    /* load destination pointer */
    entry->Dst_End_Ptr = (uint32)&DMA_CH12_DST + DMA_CH12_DST_PTR_OFFS;
    entry->Control.bit.Dst_Inc = DMA_CH12_INC & 2u ? DMA_CH12_SIZE : 3u;
    entry->Control.bit.Src_Inc = DMA_CH12_INC & 1u ? DMA_CH12_SIZE : 3u;
    entry->Control.bit.Dst_Size = DMA_CH12_SIZE;
    entry->Control.bit.Src_Size = DMA_CH12_SIZE;
    /* number of transfers minus 1 */
    entry->Control.bit.N_Minus_1 = DMA_CH12_NoOfTrans - 1;
  #else
    /* Scatter-Gather Transfer */
    entry->Control.bit.Cycle_Ctrl = DMA_Cycle_Type_MemSctGthPrim;
    /* must be '0' for Scatter-Gather */
    entry->Control.bit.Next_UseBurst = 0;
    /* number of transfers  */
    entry->Control.bit.N_Minus_1 = (DMA_CH12_TASK_NoOfTasks * 4) - 1u;
    /* Arbitrates after one Task trans (4 DMA trans)*/
    entry->Control.bit.R_Power = 2;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Src_Size = DMA_32Bit_Transfer;
    /* datawidth of the data to be transferred */
    entry->Control.bit.Dst_Size = DMA_32Bit_Transfer;
    /* source increment */
    entry->Control.bit.Src_Inc = DMA_Inc_32bit;
    /* destination increment */
    entry->Control.bit.Dst_Inc = DMA_Inc_32bit;
    /* source end pointer, points to last task in task list */
    entry->Src_End_Ptr = (uint32)&DMA_CH12_TASK_SRC + ((DMA_CH12_TASK_NoOfTasks * 4) - 1u) * (1u << DMA_32Bit_Transfer);
    /* destination pointer, points to channel index in alternate stucture */
    entry->Dst_End_Ptr = (DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH12 * sizeof(TDMA_Entry)) + 0xC;
  #endif /* (DMA_CH12_TRANS_MODE == 0u) */
#endif
  /* enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg = (uint32)DMA_EN;  
}
#else
	#error "use IFXConfigWizard XML Version V1.2.0 or greater"
#endif
