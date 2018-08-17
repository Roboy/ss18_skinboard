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
/* See scu.c */

#ifndef SCU_H
#define SCU_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include <bootrom.h>
#include "scu_defines.h"
#include "pmu_defines.h"
#if (PMU_SLEEP_MODE == 1)
#include <lin.h>
#endif

/******************************************************************************
**                      Global Macro Definitions                             **
*******************************************************************************/
/* PASSWD Phrases */
#define PASSWD_Open (0x98U)
#define PASSWD_Close (0xA8U)

/* NVM Protection indices */
#define NVM_DATA_WRITE (0U)
#define NVM_CODE_WRITE (1U)
#define NVM_DATA_READ  (2U)
#define NVM_CODE_READ  (3U)

/* NVM Protection actions */
#define PROTECTION_CLEAR  (1U)
#define PROTECTION_SET    (0U)

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/** \brief SCU configuration
 */

typedef enum
{
  Mod_ADC1 = 0x00,
  Mod_SSC1 = 0x01,
  Mod_CCU6 = 0x02,
  Mod_Timer2 = 0x03,
  Mod_GPT12 = 0x04,
  Mod_SSC2 = 0x11,
  Mod_Timer21 = 0x13,
  MOd_Timer3 = 0x15
} TScu_Mod;

/*******************************************************************************
**                      Global Variable Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void SCU_ClkInit(void);
void SCU_Init(void);
#if (PMU_SLEEP_MODE == 1)
void SCU_EnterSleepMode(void);
#endif
#if (PMU_STOP_MODE == 1)
void SCU_EnterStopMode(void);
#endif
void SCU_EnterSlowMode(void);
void SCU_ExitSlowMode(void);

__STATIC_INLINE void SCU_WDT_Start(void);
__STATIC_INLINE void SCU_WDT_Stop(void);
__STATIC_INLINE void SCU_WDT_Service(void);
__STATIC_INLINE void SCU_ChangeNVMProtection(uint8 Protection, uint8 Action);
__STATIC_INLINE void SCU_Disable_Module(TScu_Mod Module);
__STATIC_INLINE void SCU_Enable_Module(TScu_Mod Module);
__STATIC_INLINE void SCU_OpenPASSWD(void);
__STATIC_INLINE void SCU_ClosePASSWD(void);

/*******************************************************************************
**                      Global INLINE Function Definitions                    **
*******************************************************************************/
/** \brief starts the internal Watchdog
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_WDT_Start(void)
{
  SCU->WDTCON.bit.WDTEN = 1;
}

/** \brief stops the internal Watchdog
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_WDT_Stop(void)
{
  SCU->WDTCON.bit.WDTEN = 0;
}

/** \brief Services the internal Watchdog
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_WDT_Service(void)
{
  SCU->WDTCON.bit.WDTRS = 1;
}

/** \brief Sets the Write/Read Protection for the Code/Data Flash
 *
 * \param[in] Protection: CODE/DATA, READ/WRITE
 * \param[in] Action: CLEAR/SET
 * \return nothing
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_ChangeNVMProtection(uint8 Protection, uint8 Action)
{
  if (Action == PROTECTION_CLEAR)
  {
    if (Protection == NVM_DATA_WRITE)
    {
      USER_DFLASH_WR_PROT_DIS((uint16) SCU_DFLASH_WPROT_PW);
    }
    else if (Protection == NVM_CODE_WRITE)
    {
      USER_CFLASH_WR_PROT_DIS((uint16) SCU_CFLASH_WPROT_PW);
    }
    else if (Protection == NVM_DATA_READ)
    {
      USER_DFLASH_RD_PROT_DIS((uint16) SCU_DFLASH_WPROT_PW);
    }
    else if (Protection == NVM_CODE_READ)
    {
      USER_CFLASH_RD_PROT_DIS((uint16) SCU_CFLASH_WPROT_PW);
    }
  }
  else
  {
    if (Protection == NVM_DATA_WRITE)
    {
      USER_DFLASH_WR_PROT_EN((uint16) SCU_DFLASH_WPROT_PW);
    }
    else if (Protection == NVM_CODE_WRITE)
    {
      USER_CFLASH_WR_PROT_EN((uint16) SCU_CFLASH_WPROT_PW);
    }
    else if (Protection == NVM_DATA_READ)
    {
      USER_DFLASH_RD_PROT_EN((uint16) SCU_DFLASH_WPROT_PW);
    }
    else if (Protection == NVM_CODE_READ)
    {
      USER_CFLASH_RD_PROT_EN((uint16) SCU_CFLASH_WPROT_PW);
    }
  }
}

/** \brief Disables a given peripheral module
 *
 * \param[in] TScu_Mod Module, Bit[4] = PMCON1 or PMCON2, Bit[3:0] slects the bit
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_Disable_Module(TScu_Mod Module)
{
  volatile uint8 *pSfr;

  /* pSfr will be assigned to PMCON1 or PMCON2 depending on *
   * bit4 in the parameter Module                           */
  pSfr = (uint8 *) (&SCU->PMCON1.reg) + ((Module & 0x10) >> 2);

  /* sets the corresponding bit given by the lower nibble in*
   * the parameter Module                                   */
  *pSfr |= (uint8) (1 << (Module & 0x07));
}

/** \brief Enables a given peripheral module
 *
 * \param[in] TScu_Mod Module, Bit[4] = PMCON1 or PMCON2, Bit[3:0] slects the bit
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_Enable_Module(TScu_Mod Module)
{
  volatile uint8 *pSfr;

  /* pSfr will be assigned to PMCON1 or PMCON2 depending on *
   * bit4 in the parameter Module                           */
  pSfr = (uint8 *) (&SCU->PMCON1.reg) + ((Module & 0x10) >> 2);

  /* sets the corresponding bit given by the lower nibble in*
   * the parameter Module                                   */
  *pSfr &= (uint8) ~ (1 << (Module & 0x07));
}

/** \brief Opens the PASSWD Register protection scheme for 32 tCLK
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_OpenPASSWD(void)
{
  SCU->PASSWD.reg = (uint8) PASSWD_Open;
}

/** \brief Closes the PASSWD Register protection scheme
 *
 * \param[in] none
 * \param[in] none
 * \return None
 *
 * \ingroup scu_api
 */
__STATIC_INLINE void SCU_ClosePASSWD(void)
{
  SCU->PASSWD.reg = (uint8) PASSWD_Close;
}

#endif
