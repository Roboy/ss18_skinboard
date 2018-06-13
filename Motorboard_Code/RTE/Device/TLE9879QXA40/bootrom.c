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
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* 
 * V0.2.1: 2016-04-14, DM:   BF-Step BootROM API extension added 
 * V0.2.0: 2015-07-22, DM:   typedef unions added for various return values
 * V0.1.9: 2015-07-03, DM:   BE-Step compatible, USER_MAPRAM_INIT function added
 * V0.1.8: 2015-06-03, DM:   BootROM entry point defines moved into bootrom.h
 * V0.1.7: 2014-09-22, DM:   USER_ECC_CHECK modified, parameter added
 *                           ProgramPage: interrupts disabled over the entire
 *                           NVM programming flow, to prevent from nested
 *                           NVM operations during assembly buffer filling
 * V0.1.6: 2014-06-27, TA:   Changed to type definitions from Types.h
 * V0.1.5: 2014-05-18, DM:   provide a union/struct for the encoding of the
 *                           Customer ID
 * V0.1.4: 2014-05-14, DM:   add NVM protect/unprotect functions (BB-step)
 * V0.1.3: 2013-11-20, DM:   handle WDT1 and Interrupts in ProgramPage()
 *                           function,
 *                           GetCustomerID() function added 
 * V0.1.2: 2012-12-03, DM:   Defining the function pointers to be const
 *                           to save unnecessary RAM usage, 
 *                           BootROM_Init() function removed
 * V0.1.1: 2012-11-30, DM:   Implementation of all BOOTROM functions
 *                           described in the TLE986x AA-Step BootROM UM V0.9
 * V0.1.0: 2012-08-31, DM:   Initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

#include <tle_device.h>

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
** BootROM User Function declaration                                          **
*******************************************************************************/

/*lint -e19 Supressing MISRA 2012 Error 19: Useless Declaration */
/*lint -e970 Supressing MISRA 2012 MISRA 2012 Directive 4.6 */
int (*const USER_CFLASH_WR_PROT_EN)
  (const uint16 cflash_pw) = (int (*)(const uint16)) addr_USER_CFLASH_WR_PROT_EN;

int (*const USER_CFLASH_WR_PROT_DIS)
  (const uint16 cflash_pw) =
  (int (*)(const uint16)) addr_USER_CFLASH_WR_PROT_DIS;

int (*const USER_CFLASH_RD_PROT_EN)
  (const uint16 cflash_pw) = (int (*)(const uint16)) addr_USER_CFLASH_RD_PROT_EN;

int (*const USER_CFLASH_RD_PROT_DIS)
  (const uint16 cflash_pw) =
  (int (*)(const uint16)) addr_USER_CFLASH_RD_PROT_DIS;

int (*const USER_DFLASH_WR_PROT_EN)
  (const uint16 dflash_pw) = (int (*)(const uint16)) addr_USER_DFLASH_WR_PROT_EN;

int (*const USER_DFLASH_WR_PROT_DIS)
  (const uint16 dflash_pw) =
  (int (*)(const uint16)) addr_USER_DFLASH_WR_PROT_DIS;

int (*const USER_DFLASH_RD_PROT_EN)
  (const uint16 dflash_pw) = (int (*)(const uint16)) addr_USER_DFLASH_RD_PROT_EN;

int (*const USER_DFLASH_RD_PROT_DIS)
  (const uint16 dflash_pw) =
  (int (*)(const uint16)) addr_USER_DFLASH_RD_PROT_DIS;

int (*const USER_OPENAB)
  (const uint32 * address) = (int (*)(const uint32 *)) addr_USER_OPENAB;

int (*const USER_PROG)
  (const uint8 PROG_FLAG) = (int (*)(const uint8)) addr_USER_PROG;

int (*const USER_ERASEPG)
  (const uint32 * NVMPageAddr, const uint8 XRAM_RTNE_BRNCHNG) =
  (int (*)(const uint32 *, const uint8)) addr_USER_ERASEPG;

int (*const USER_ABORTPROG) (void) = (int (*)(void)) addr_USER_ABORTPROG;

int (*const USER_NVMRDY) (void) = (int (*)(void)) addr_USER_NVMRDY;

int (*const USER_READ_CAL)
  (const uint8 NumOfBytes, const uint8 CSAddr, const uint16 RAMAddr) =
  (int (*)(const uint8, const uint8, const uint16)) addr_USER_READ_CAL;

int (*const USER_NVM_CONFIG)
  (const uint8 * NVMSize, const uint8 * MapRAMSize) =
  (int (*)(const uint8 *, const uint8 *)) addr_USER_NVM_CONFIG;

int (*const USER_NVM_ECC2ADDR)
  (const uint16 * ECC2Addr) = (int (*)(const uint16 *)) addr_USER_NVM_ECC2ADDR;

uint8 (*const USER_MAPRAM_INIT) (void) = (uint8 (*)(void)) addr_USER_MAPRAM_INIT;

int (*const USER_READ_100TP)
  (const uint8 OTP_Page_Sel,
  const uint8 DataOffset,
  const uint32 * HundredTPData) =
  (int (*)(const uint8, const uint8, const uint32 *)) addr_USER_READ_100TP;

int (*const USER_100TP_PROG)
  (const uint8 OTP_Page_Sel) = (int (*)(const uint8)) addr_USER_100TP_PROG;

int (*const USER_ERASE_SECTOR)
  (const uint32 NVMSectorAddr) = (int (*)(const uint32)) addr_USER_ERASE_SECTOR;

uint8(*const USER_RAM_MBIST_START)
  (const uint16 RAM_MBIST_Stop_Addr,
  const uint16 RAM_MBIST_Start_addr) =
  (uint8(*)(const uint16, const uint16)) addr_USER_RAM_MBIST_START;

uint8(*const USER_NVM_ECC_CHECK)
  (void) = (uint8(*)(void)) addr_USER_NVM_ECC_CHECK;

uint8(*const USER_ECC_CHECK) (const uint32* ECC2Addr) = 
  (uint8(*)(const uint32*)) addr_USER_ECC_CHECK;
  
/* BF-Step BootROM API extension */
#ifdef RTE_DEVICE_BF_STEP
uint8 (*const USER_ERASE_SECTOR_VERIFY) (const uint32 sector_addr) = 
  (uint8 (*)(const uint32)) addr_USER_ERASE_SECTOR_VERIFY;
  
uint8 (*const USER_ERASEPG_VERIFY) (const uint32 page_addr) = 
  (uint8 (*)(const uint32)) addr_USER_ERASEPG_VERIFY;
  
uint8 (*const USER_VERIFY_PAGE) (const uint32 page_addr) = 
  (uint8 (*)(const uint32)) addr_USER_VERIFY_PAGE;
#endif /* RTE_DEVICE_BF_STEP */

/*lin +e19 */
/*lin +e970 */

/******************************************************************************
** Initialization function to make BootROM functions to be called from C     **
******************************************************************************/

/** \brief Programms a page to NVM
 *
 * \param uint32 addr   - Address of the page to be programmed
 *        uint8 *buf    - data buffer containing the date to be programmed
 *        uint8 Branch  - 0 = no RAM branch, 1 = RAM branch
 *        uint8 Correct - 0 = no corrective actions on fail, 
 *                        1 = corrective actions enabled
 *        uint8 FailPageErase - 0 = enabled, old data kept 
 *                              1 = disable, old data erased
 * \return 0 = pass, 1 = fail
 *
 * \ingroup bootrom_api
 */
int ProgramPage(uint32 addr,
  const uint8 * buf, uint8 Branch, uint8 Correct, uint8 FailPageErase)
{
  uint8 i;
  uint8 *pc = (uint8 *) addr;
  int res;

  /* suspend and remember all enabled interrupts */
  __disable_irq();	
  /* trigger WDT1 Short-Open-Window */
  WDT1_SOW_Service((uint8)1);
  /* open NVM assembly buffer */
  res = USER_OPENAB((uint32 *) addr);
  /* trigger regular WDT1, close SOW */
/*lint -e534 Supressing MISRA 2012 MISRA 2012 Directive 4.7 */
  WDT1_Service();
/*lint +e534 */
  /* check if OpenAB function returned a PASS (== 0) */
  if (res == 0)
  {
    /* fill up the assembly buffer with new data */
    for (i = 0u; i < (uint8)FlashPageSize; i++)
    {
/*lint -e9029 Supressing MISRA 2012 Rule 10.4 */
      pc[i] = buf[i];
/*lint +e9029 */
    }
    /* trigger WDT1 Short-Open-Window */
    WDT1_SOW_Service((uint8)1);
    /* execute NVM programming function */
    res = USER_PROG((uint8)(((FailPageErase & (uint8)1) << 2u) | 
		                ((Correct & (uint8)1) << 1u) | (Branch & (uint8)1)));
    /* trigger regular WDT1, close SOW */
/*lint -e534 Supressing MISRA 2012 MISRA 2012 Directive 4.7 */
    WDT1_Service();
/*lint +e534 */
    /* reenable suspended interrupts */
    __enable_irq();
  }
  return (res);
}

/** \brief Reads the Customer ID out of the 100TP NVM
 *
 * \param uint32 *CustID - pointer to the variable where the Customer ID
 *        shall be stored
 * \return 0 = pass, 1 = fail
 *
 * \ingroup bootrom_api
 */
int GetCustomerID(uint32 * CustID)
{
  int res;
  uint32 buf[128 / 4];

/*lint -e9029 Supressing MISRA 2012 Rule 10.4 */
  buf[0] = 0u;
/*lint +e9029 */
	
  /* suspend and remember all enabled interrupts */
  __disable_irq();
  /* trigger Short-Open-Window */
  WDT1_SOW_Service((uint8)1);
  /* read customer ID out of 100TP page 1, offset 0 */
/*lint -e9029 Supressing MISRA 2012 Rule 10.4 */
  res = USER_READ_100TP((uint8)0x11, (uint8)0, &buf[0]);
/*lint +e9029 */
  /* trigger regular WDT1, close SOW */
/*lint -e534 Supressing MISRA 2012 MISRA 2012 Directive 4.7 */
  WDT1_Service();
/*lint +e534 */
  /* reenable suspended interrupts */
  __enable_irq();
  /* check if Read_100TP returned a PASS (== 0) */
  if (res == 0)
  {
    /* return customer ID to caller */
/*lint -e9029 Supressing MISRA 2012 Rule 10.4 */
    *CustID = buf[0];
/*lint +e9029 */
  }
  return (res);
}
