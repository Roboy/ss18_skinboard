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
 * see bootrom.c
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#ifndef _BOOTROM_H
#define _BOOTROM_H

#include <Types.h>
#include <RTE_Components.h>

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/
#define FlashPageSize 		          (128U)
#define FlashSectorSize		          (4096U)

/*******************************************************************************
** Entry points into the BootROM                                              **
*******************************************************************************/
#define addr_USER_CFLASH_WR_PROT_EN   (0x3925u);
#define addr_USER_CFLASH_WR_PROT_DIS  (0x391Du);
#define addr_USER_CFLASH_RD_PROT_EN   (0x3915u);
#define addr_USER_CFLASH_RD_PROT_DIS  (0x390Du);
#define addr_USER_DFLASH_WR_PROT_EN   (0x3905u);
#define addr_USER_DFLASH_WR_PROT_DIS  (0x38FDu);
#define addr_USER_DFLASH_RD_PROT_EN   (0x38F5u);
#define addr_USER_DFLASH_RD_PROT_DIS  (0x38EDu);
#define addr_USER_OPENAB              (0x38E5u);
#define addr_USER_PROG                (0x38DDu);
#define addr_USER_ERASEPG             (0x38D5u);
#define addr_USER_ABORTPROG           (0x38CDu);
#define addr_USER_NVMRDY              (0x38C5u);
#define addr_USER_READ_CAL            (0x38BDu);
#define addr_USER_NVM_CONFIG          (0x38B5u);
#define addr_USER_NVM_ECC2ADDR        (0x38ADu);
#define addr_USER_MAPRAM_INIT         (0x389Du);
#define addr_USER_READ_100TP          (0x3875u);
#define addr_USER_100TP_PROG          (0x386Du);
#define addr_USER_ERASE_SECTOR        (0x3865u);
#define addr_USER_RAM_MBIST_START     (0x384Du);
#define addr_USER_NVM_ECC_CHECK       (0x3845u);
#define addr_USER_ECC_CHECK           (0x383Du);
/* BF-Step BootROM API extension */                                      
#ifdef RTE_DEVICE_BF_STEP
  #define addr_USER_ERASEPG_VERIFY      (0x3885u);
  #define addr_USER_ERASE_SECTOR_VERIFY (0x388Du);
  #define addr_USER_VERIFY_PAGE         (0x3895u);
#endif /* RTE_DEVICE_BF_STEP */

/*******************************************************************************
** Customer ID struct                                                         **
*******************************************************************************/
typedef union
{
  uint32 reg;
  struct
  {
    uint32           :8;   /*!< [0..7]   rfu                                  */
    uint32 Step      :8;   /*!< [15..8]  design step major/minor number [HEX] */
    uint32 Clock     :2;   /*!< [17..16] clock frequency                      */
    uint32 Package   :2;   /*!< [19..18] package code                         */
    uint32 SalesCode :4;   /*!< [23..20] device sales code [DEC]              */
    uint32 Family    :8;   /*!< [31..24] family code                          */
  } bit;                   /*!< [32] BitSize                                  */
} TCustomerID;

/*******************************************************************************
** Function USER_PROG: type definition of the parameter PROG_FLAG             **
*******************************************************************************/
typedef enum
{
  RAM_Branch,
  CorrAct,
} TProgFlag;

/*******************************************************************************
** Function USER_PROG: return value decoding                                  **
*******************************************************************************/
typedef union {
	uint8   reg;	
	struct {
		uint8 GlobFail   :  1;
		uint8            :  3;
		uint8 VerifyFail :  1;
		uint8 EmergExit  :  1;
		uint8 SparePgFail:  1;
		uint8 ExecFail   :  1;
	} bit;                           
} TUser_Prog;

/*******************************************************************************
** Function USER_OpenAB: return value decoding                                **
*******************************************************************************/
typedef union {
	uint8   reg;	
	struct {
		uint8 ABFail   :  1;
		uint8          :  6;
		uint8 ExecFail :  1;
	} bit;                           
} TUser_OpenAB;

/*******************************************************************************
** Function USER_MAPRAM_INIT: return value decoding                           **
*******************************************************************************/
typedef union {
	uint8   reg;	
	struct {
		uint8 GlobFail      :  1;
		uint8               :  4;
		uint8 DoubleMapping :  1;
		uint8 FaultyPage    :  1;
		uint8 ExecFail      :  1;
	} bit;                           
} TUser_MAPRAM_Init;

#ifdef RTE_DEVICE_BF_STEP
/*******************************************************************************
** Function USER_ERASE_SECTOR_VERIFY: return value decoding                   **
*******************************************************************************/
typedef union {
	uint8   reg;	
	struct {
		uint8 GlobFail      :  1;
		uint8 VerifyFail    :  1;
		uint8               :  4;
		uint8 MapRAMFail    :  1;
		uint8 ExecFail      :  1;
	} bit;                           
} TUser_ERASE_SECTOR_VERIFY;

/*******************************************************************************
** Function USER_ERASEPG_VERIFY: return value decoding                        **
*******************************************************************************/
typedef union {
	uint8   reg;	
	struct {
		uint8 GlobFail      :  1;
		uint8 VerifyFail    :  1;
		uint8               :  4;
		uint8 MapRAMFail    :  1;
		uint8 ExecFail      :  1;
	} bit;                           
} TUser_ERASEPG_VERIFY;

/*******************************************************************************
** Function USER_VERIFY_PAGE: return value decoding                           **
*******************************************************************************/
typedef union {
	uint8   reg;	
	struct {
		uint8 GlobFail       :  1;
		uint8 VerifyEraseFail:  1;
		uint8 VerifyProgFail :  1;
		uint8                :  4;
		uint8 ExecFail       :  1;
	} bit;                           
} TUser_VERIFY_PAGE;
#endif

/********************************************************************************
**                      Global Function Definitions                            **
********************************************************************************/
extern int (*const USER_CFLASH_WR_PROT_EN) (uint16 cflash_pw);
extern int (*const USER_CFLASH_WR_PROT_DIS) (uint16 cflash_pw);
extern int (*const USER_CFLASH_RD_PROT_EN) (uint16 cflash_pw);
extern int (*const USER_CFLASH_RD_PROT_DIS) (uint16 cflash_pw);
extern int (*const USER_DFLASH_WR_PROT_EN) (uint16 dflash_pw);
extern int (*const USER_DFLASH_WR_PROT_DIS) (uint16 dflash_pw);
extern int (*const USER_DFLASH_RD_PROT_EN) (uint16 dflash_pw);
extern int (*const USER_DFLASH_RD_PROT_DIS) (uint16 dflash_pw);
extern int (*const USER_OPENAB) (const uint32 * NVMPAGEAddr);
extern int (*const USER_PROG) (const uint8 PROG_FLAG);
extern int (*const USER_ERASEPG)
  (const uint32 * NVMPageAddr, const uint8 XRAM_RTNE_BRNCHNG);
extern int (*const USER_ABORTPROG) (void);
extern int (*const USER_NVMRDY) (void);
extern int (*const USER_READ_CAL)
  (const uint8 NumOfBytes, const uint8 CSAddr, const uint16 RAMAddr);
extern int (*const USER_NVM_CONFIG)
  (const uint8 * NVMSize, const uint8 * MapRAMSize);
extern int (*const USER_NVM_ECC2ADDR) (const uint16 * ECC2Addr);
extern uint8 (*const USER_MAPRAM_INIT) (void);
extern int (*const USER_READ_100TP)
  (const uint8 OTP_Page_Sel,
  const uint8 DataOffset, const uint32 * HundredTPData);
extern int (*const USER_100TP_PROG) (const uint8 OTP_Page_Sel);
extern int (*const USER_ERASE_SECTOR) (const uint32 NVMSectorAddr);
extern uint8(*const USER_RAM_MBIST_START)
  (const uint16 RAM_MBIST_Stop_Addr, const uint16 RAM_MBIST_Start_addr);
extern uint8(*const USER_NVM_ECC_CHECK) (void);
extern uint8(*const USER_ECC_CHECK) (const uint32* ECC2Addr);
/* BF-Step BootROM API extension */
#ifdef RTE_DEVICE_BF_STEP
extern uint8 (*const USER_ERASE_SECTOR_VERIFY) (const uint32 sector_addr);
extern uint8 (*const USER_ERASEPG_VERIFY) (const uint32 page_addr);
extern uint8 (*const USER_VERIFY_PAGE) (const uint32 page_addr);
#endif /* RTE_DEVICE_BF_STEP */

int ProgramPage(uint32 addr,
   const uint8 * buf, uint8 Branch, uint8 Correct, uint8 FailPageErase);
int GetCustomerID(uint32 * CustID);


#endif
