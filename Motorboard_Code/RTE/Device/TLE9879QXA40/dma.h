#ifndef _DMA_H
#define _DMA_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <Types.h>
#include <dma_defines.h>
#include <tle_device.h>
#include <scu_defines.h>

/*******************************************************************************
**                      Private Macro Definitions 						                **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
typedef union {
  uint32  reg;
  struct {
    uint32 Cycle_Ctrl: 3;           /* Bit[2..0] */
    uint32 Next_UseBurst: 1;        /* Bit[3] */
    uint32 N_Minus_1: 10;           /* Bit[13..4] */
    uint32 R_Power: 4;              /* Bit[17..14] */
    uint32 Src_Prot_Ctrl: 3;        /* Bit[20..18] */
    uint32 Dst_Prot_Ctrl: 3;        /* Bit[23..21] */
    uint32 Src_Size: 2;             /* Bit[25..24] */
    uint32 Src_Inc: 2;              /* Bit[27..26] */
    uint32 Dst_Size: 2;             /* Bit[29..28] */
    uint32 Dst_Inc: 2;              /* Bit[31..30] */
  } bit;
} TControl;

typedef struct
{
  uint32 Src_End_Ptr;
  uint32 Dst_End_Ptr;
  TControl Control;
  uint32 reserved;
} TDMA_Entry;

/* DMA Channels */
#define DMA_CH0                       (0u)
#define DMA_CH1                       (1u)
#define DMA_CH2                       (2u)
#define DMA_CH3                       (3u)
#define DMA_CH4                       (4u)
#define DMA_CH5                       (5u)
#define DMA_CH6                       (6u)
#define DMA_CH7                       (7u)
#define DMA_CH8                       (8u)
#define DMA_CH9                       (9u)
#define DMA_CH10                      (10u)
#define DMA_CH11                      (11u)
#define DMA_CH12                      (12u)

/* DMA Channel Mask */
#define DMA_MASK_CH0                  (1u << 0u)
#define DMA_MASK_CH1                  (1u << 1u)
#define DMA_MASK_CH2                  (1u << 2u)
#define DMA_MASK_CH3                  (1u << 3u)
#define DMA_MASK_CH4                  (1u << 4u)
#define DMA_MASK_CH5                  (1u << 5u)
#define DMA_MASK_CH6                  (1u << 6u)
#define DMA_MASK_CH7                  (1u << 7u)
#define DMA_MASK_CH8                  (1u << 8u)
#define DMA_MASK_CH9                  (1u << 9u)
#define DMA_MASK_CH10                 (1u << 10u)
#define DMA_MASK_CH11                 (1u << 11u)
#define DMA_MASK_CH12                 (1u << 12u)

/* DMA Transfer Codes */
#define DMA_8Bit_Transfer             (0u)
#define DMA_16Bit_Transfer            (1u)
#define DMA_32Bit_Transfer            (2u)

/* DMA Increments */
#define DMA_Inc_8bit                  (0u)
#define DMA_Inc_16bit                 (1u)
#define DMA_Inc_32bit                 (2u)

/* DMA Increment Codes*/
#define DMA_No_Inc                    (0u)
#define DMA_Src_Inc                   (1u)
#define DMA_Dst_Inc                   (2u)
#define DMA_Src_Dst_Inc               (3u)

/* DMA Cycle Types */
#define DMA_Cycle_Type_Invalid	      (0u)
#define DMA_Cycle_Type_Basic	      (1u)
#define DMA_Cycle_Type_Auto	          (2u)
#define DMA_Cycle_Type_PingPong	      (3u)
#define DMA_Cycle_Type_MemSctGthPrim  (4u)
#define DMA_Cycle_Type_MemSctGthAlt	  (5u)
#define DMA_Cycle_Type_PerSctGthPrim  (6u)
#define DMA_Cycle_Type_PerSctGthAlt   (7u)

/* DMA Interrupt Clear Macros */
#define DMA_CH0_Int_Clr()             (SCU->DMAIRC2CLR.reg = (uint8)1u << 1u)
#define DMA_CH1_Int_Clr()             (SCU->DMAIRC2CLR.reg = (uint8)1u << 2u)
#define DMA_CH2_Int_Clr()             (SCU->DMAIRC2CLR.reg = (uint8)1u << 3u)
#define DMA_CH3_Int_Clr()             (SCU->DMAIRC2CLR.reg = (uint8)1u << 4u)
#define DMA_CH4_Int_Clr()             (SCU->DMAIRC1CLR.reg = (uint8)1u << 0u)
#define DMA_CH5_Int_Clr()             (SCU->DMAIRC1CLR.reg = (uint8)1u << 1u)
#define DMA_CH6_Int_Clr()             (SCU->DMAIRC1CLR.reg = (uint8)1u << 2u)
#define DMA_CH7_Int_Clr()             (SCU->DMAIRC1CLR.reg = (uint8)1u << 3u)
#define DMA_CH8_Int_Clr()             (SCU->DMAIRC1CLR.reg = (uint8)1u << 4u)
#define DMA_CH9_Int_Clr()             (SCU->DMAIRC1CLR.reg = (uint8)1u << 5u)
#define DMA_CH10_Int_Clr()            (SCU->DMAIRC1CLR.reg = (uint8)1u << 6u)
#define DMA_CH11_Int_Clr()            (SCU->DMAIRC1CLR.reg = (uint8)1u << 7u)
#define DMA_CH12_Int_Clr()            (SCU->DMAIRC2CLR.reg = (uint8)1u << 5u)

/* DMA Interrupt Enable/Disable Macros */
#define DMA_CH0_Int_En()            (SCU->DMAIEN2.bit.TRSEQ1RDYIE = 1u)
#define DMA_CH0_Int_Dis()           (SCU->DMAIEN2.bit.TRSEQ1RDYIE = 0u)
#define DMA_CH1_Int_En()            (SCU->DMAIEN2.bit.TRSEQ2RDYIE = 1u)
#define DMA_CH1_Int_Dis()           (SCU->DMAIEN2.bit.TRSEQ2RDYIE = 0u)
#define DMA_CH2_Int_En()            (SCU->DMAIEN2.bit.SSCTXIE = 1u)
#define DMA_CH2_Int_Dis()           (SCU->DMAIEN2.bit.SSCTXIE = 0u)
#define DMA_CH3_Int_En()            (SCU->DMAIEN2.bit.SSCRXIE = 1u)
#define DMA_CH3_Int_Dis()           (SCU->DMAIEN2.bit.SSCRXIE = 0u)
#define DMA_CH4_Int_En()            (SCU->DMAIEN1.bit.CH1IE = 1u)
#define DMA_CH4_Int_Dis()           (SCU->DMAIEN1.bit.CH1IE = 0u)
#define DMA_CH5_Int_En()            (SCU->DMAIEN1.bit.CH2IE = 1u)
#define DMA_CH5_Int_Dis()           (SCU->DMAIEN1.bit.CH2IE = 0u)
#define DMA_CH6_Int_En()            (SCU->DMAIEN1.bit.CH3IE = 1u)
#define DMA_CH6_Int_Dis()           (SCU->DMAIEN1.bit.CH3IE = 0u)
#define DMA_CH7_Int_En()            (SCU->DMAIEN1.bit.CH4IE = 1u)
#define DMA_CH7_Int_Dis()           (SCU->DMAIEN1.bit.CH4IE = 0u)
#define DMA_CH8_Int_En()            (SCU->DMAIEN1.bit.CH5IE = 1u)
#define DMA_CH8_Int_Dis()           (SCU->DMAIEN1.bit.CH5IE = 0u)
#define DMA_CH9_Int_En()            (SCU->DMAIEN1.bit.CH6IE = 1u)
#define DMA_CH9_Int_Dis()           (SCU->DMAIEN1.bit.CH6IE = 0u)
#define DMA_CH10_Int_En()           (SCU->DMAIEN1.bit.CH7IE = 1u)
#define DMA_CH10_Int_Dis()          (SCU->DMAIEN1.bit.CH7IE = 0u)
#define DMA_CH11_Int_En()           (SCU->DMAIEN1.bit.CH8IE = 1u)
#define DMA_CH11_Int_Dis()          (SCU->DMAIEN1.bit.CH8IE = 0u)
#define DMA_CH12_Int_En()           (SCU->DMAIEN2.bit.GPT12IE = 1u)
#define DMA_CH12_Int_Dis()          (SCU->DMAIEN2.bit.GPT12IE = 0u)

#define DMA_Primary_Struct_Set(a)   (DMA->CTRL_BASE_PTR.reg = (uint32)a)

#define DMA_Channel_Enable_Set(mask_ch)		    (DMA->CHNL_ENABLE_SET.reg = (uint32)(mask_ch & 0x1FFF))
#define DMA_Software_Request_Set(mask_ch)	    (DMA->CHNL_SW_REQUEST.reg = (uint32)(mask_ch & 0x1FFF))
#define DMA_Primary_Struct_Usage_Set(mask_ch)   (DMA->CHNL_PRI_ALT_CLR.reg = (uint32)(mask_ch & 0x1FFF))
#define DMA_Alternate_Struct_Usage_Set(mask_ch) (DMA->CHNL_PRI_ALT_SET.reg = (uint32)(mask_ch & 0x1FFF))

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
#if (DMA_XML_VERSION >= 10200)
void DMA_Init(void);
void DMA_Setup_Channel(uint32 DMA_ChIdx, uint32 addr_src, uint32 addr_dst, 
                       uint32 trans_cnt, uint32 datawidth, uint32 increment);
void DMA_Reset_Channel(uint32 DMA_ChIdx, uint32 trans_cnt);
void DMA_Channel_MemSctGth_Set(uint32 DMA_ChIdx, TDMA_Entry* Task_List, uint32 NoOfTasks);
void DMA_Channel_PerSctGth_Set(uint32 DMA_ChIdx, TDMA_Entry* Task_List, uint32 NoOfTasks);
TDMA_Entry* DMA_Task_SctGth_Set(TDMA_Entry* entry, uint8 DMA_Ch, TDMA_Entry* Task_List, uint32 NoOfTask);

TDMA_Entry* DMA_Task_Set(TDMA_Entry* entry, uint8 cycle_type, uint8 arb_rate, uint32 addr_src, uint32 addr_dst, 
                         uint32 trans_cnt, uint32 datawidth, uint32 increment);

__STATIC_INLINE void DMA_Master_En(void);

/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/
__STATIC_INLINE void DMA_Master_En(void)
{
  /* arm the DMA */
  DMA->CFG.bit.MASTER_ENABLE = 1u;
}
#else
	#error "use IFXConfigWizard XML Version V1.2.0 or greater"
#endif

#endif
