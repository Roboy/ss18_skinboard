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
 * V0.3.6: 2017-02-16, DM:   Bdrv prefix changed to capital letter
 * V0.3.5: 2016-09-23, DM:   OpenLoad detection current set to 1
 * V0.3.4: 2016-07-28, DM:   OpenLoad detection for 3-phase motors added
 * V0.3.3: 2015-11-12, DM:   disable interrupts before writing TRIM_DRVx
 * V0.3.2: 2015-07-15, DM:   BEMF register init added
 * V0.3.1: 2015-02-10, DM:   individual header file added
 * V0.3.0: 2014-04-25, TA:   Bdrv_Init(): use #defines from "IFX Config Wizard"
 * V0.2.0: 2013-09-20, DM:   function and settings adapted to B-Step device
 * V0.1.1: 2013-05-24, DM:   Bdrv_Diag functions removed
 *                           Bdrv_Clr_Sts changed, to be robust agains
 *                           unintened flag clearing
 *                           Open-Load detection function added
 * V0.1.0: 2013-02-10, DM:   Initial version
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <bdrv.h>
#include <scu.h>
#include <wdt1.h>
/*******************************************************************************
**                      External CallBacks                                    **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Initializes the BDRV module.
 *
 * \param None
 * \return None
 *
 * \ingroup drv_api
 */
void BDRV_Init(void)
{
  /* Set charge pump clock */
  BDRV->CP_CLK_CTRL.reg = (uint32) BDRV_CP_CLK_CTRL;

  /* Set charge pump control, clear status bits */
  BDRV->CP_CTRL_STS.reg = (uint32) BDRV_CP_CTRL_STS;

  /* Set trimming register */
  __disable_irq();
  SCU_OpenPASSWD();
  BDRV->TRIM_DRVx.reg = (uint32) BDRV_TRIM_DRVx;
  SCU_ClosePASSWD();
  __enable_irq();

  /* Set bridge driver control 3 */
  BDRV->CTRL3.reg = (uint32) BDRV_CTRL3;
  BDRV->CTRL1.reg = 0u;
  BDRV->CTRL2.reg = 0u;

  BDRV->OFF_SEQ_CTRL.reg = (uint32) BDRV_OFF_SEQ;
  BDRV->ON_SEQ_CTRL.reg = (uint32) BDRV_ON_SEQ;
  
#if (UC_SERIES == TLE987)
  MF->BEMFC_CTRL_STS.reg = (uint32) MF_BEMFC_CTRL_STS;
  MF->TRIM_BEMFx.reg = (uint32) MF_TRIM_BEMFx;
#endif  
} /* End of BDRV_Init */


/** \brief sets the bridge in the desired state
 *
 * \param Channel Configuration for each MOSFET
 * \return None
 *
 * \ingroup drv_api
 */
#if (UC_SERIES == TLE987)
void BDRV_Set_Bridge(TBdrv_Ch_Cfg LS1_Cfg, TBdrv_Ch_Cfg HS1_Cfg,
  TBdrv_Ch_Cfg LS2_Cfg, TBdrv_Ch_Cfg HS2_Cfg, TBdrv_Ch_Cfg LS3_Cfg,
  TBdrv_Ch_Cfg HS3_Cfg)
{
  uint32 ctrl;

  ctrl = ((uint32)HS2_Cfg << 24u) | ((uint32)HS1_Cfg << 16u) | ((uint32)LS2_Cfg << 8u) | (uint32)LS1_Cfg;
  BDRV->CTRL1.reg = ctrl;
  ctrl = ((uint32)HS3_Cfg << 8u) | (uint32)LS3_Cfg;
  BDRV->CTRL2.reg = ctrl;
}
#else
void BDRV_Set_Bridge(TBdrv_Ch_Cfg LS1_Cfg, TBdrv_Ch_Cfg HS1_Cfg,
  TBdrv_Ch_Cfg LS2_Cfg, TBdrv_Ch_Cfg HS2_Cfg)
{
  uint32 ctrl;

  ctrl = ((uint32)HS2_Cfg << 24u) | ((uint32)HS1_Cfg << 16u) | ((uint32)LS2_Cfg << 8u) | (uint32)LS1_Cfg;
  BDRV->CTRL1.reg = ctrl;
}
#endif

/** \brief clears individual status flags
 *
 * \param status bit to be cleared
 * \return None
 *
 * \ingroup drv_api
 */
void BDRV_Clr_Sts(uint32 Sts_Bit)
{
  SCUPM->BDRV_ISCLR.reg = (uint32) Sts_Bit;
}

/** \brief sets the bridge in the desired state
 *
 * \param Channel Configuration for each MOSFET
 * \return None
 *
 * \ingroup drv_api
 */
void BDRV_Set_Channel(TBdrv_Ch BDRV_Ch, TBdrv_Ch_Cfg Ch_Cfg)
{
#if (UC_SERIES == TLE987)
  if (BDRV_Ch < LS3)
  {
#endif
    BDRV->CTRL1.reg = (BDRV->CTRL1.reg & ~(uint32) ((uint32)0x0F << ((uint32)BDRV_Ch << 3u)))
      | (uint32) ((uint32)Ch_Cfg << ((uint32)BDRV_Ch << 3u));
#if (UC_SERIES == TLE987)
  }
  else
  {
    BDRV->CTRL2.reg = (BDRV->CTRL2.reg & ~(uint32) ((uint32)0x0F << 
		(((uint32)BDRV_Ch - 4u) << 3u))) | (uint32) ((uint32)Ch_Cfg << 
		(((uint32)BDRV_Ch - 4u) << 3u));
  }
#endif
}

/** \brief sets Interrupt Enable for the individual MOSFETs
 *
 * \param Channel selection, Interrupt selection
 * \return None
 *
 * \ingroup drv_api
 */
void BDRV_Set_Int_Channel(TBdrv_Ch BDRV_Ch, TBdrv_Ch_Int Ch_Int)
{
  /* set DS_Int */
  SCUPM->BDRV_IRQ_CTRL.reg |= (uint32) (((uint32)Ch_Int & 1u) << (uint32)BDRV_Ch);

  /* set OC_Int */
  SCUPM->BDRV_IRQ_CTRL.reg |= (uint32) ((((uint32)Ch_Int >> 1u) & 1u) << ((uint32)BDRV_Ch + 10u));

  /* enable BDRV interrupt node */
  if ((SCUPM->BDRV_IRQ_CTRL.reg & (uint32)BDRV_IRQ_BITS) != 0u)
  {
    CPU->NVIC_ISER0.bit.Int_BDRV = 1u;
  }
}

/** \brief Open Load detection, detects whether a motor is connected
 *
 * \param none
 * \return true = no motor detected, false = motor connected
 *
 * \ingroup drv_api
 */
#if (UC_SERIES == TLE986)
bool BDRV_Diag_OpenLoad(void)
{
  /* HSx_OC/LSx_OC and HSx_DS/LSx/DS bits */
  uint8 iBDRV_Int_En;
  bool bOpenLoad;
  uint32 lCTRL3;

  bOpenLoad = false;

  /* save bridge driver interrupt enable */
  iBDRV_Int_En = CPU->NVIC_ISER0.bit.Int_BDRV;
  /* disable bridge driver interrupt */
  CPU->NVIC_ICER0.reg = (1u << 14);

  /* save CTRL3 register */
  lCTRL3 = BDRV->CTRL3.reg;

  /* set IDISCHARGE = 1, set DSMONVTH = 7 (2.25V) */
  BDRV->CTRL3.bit.DSMONVTH = 7;
  BDRV->CTRL3.bit.IDISCHARGEDIV2_N = 0;
  BDRV->CTRL3.bit.IDISCHARGE_TRIM = 1;

  /* check Phase 1 and 2 */
  BDRV_Set_Channel(LS1, Ch_En);
  BDRV_Set_Channel(LS2, Ch_En);
  BDRV_Set_Channel(HS1, Ch_En);
  BDRV_Set_Channel(HS2, Ch_En);

  /* enable HS1 DS-Current Source */
  BDRV_Set_Channel(HS1, Ch_DCS);

  /* Delay, give the DS-Current source some time to settle *
   * delay time depents on the attached motor              */
  Delay_us(800u);
	
  /* clear status flags */
  SCUPM->BDRV_ISCLR.reg = (uint32) BDRV_IRQ_BITS;

  /* check status flags */
  if ((SCUPM->BDRV_IS.reg & (uint32)BDRV_IRQ_BITS) != 0u)
  {
    bOpenLoad = true;
  }

  /* switch off all drivers */
  BDRV->CTRL1.reg = (uint32) 0;

  /* restore CTRL3 register */
  BDRV->CTRL3.reg = lCTRL3;

  /* restore interrupt */
  if (iBDRV_Int_En == 1u)
  {
    CPU->NVIC_ISER0.bit.Int_BDRV = 1u;
  }
  return (bOpenLoad);
}
#endif

#if (UC_SERIES == TLE987)
bool BDRV_Diag_OpenLoad(void)
{
  #define BDRV_ISCLR_DS 0x0000003F
  bool bBDRV_Int_En;
  bool bOpenLoad;
  uint32 lCTRL3;
  
  bOpenLoad = false;
  
  /* save bridge driver interrupt enable */
  bBDRV_Int_En = (bool)(CPU->NVIC_ISER0.bit.Int_BDRV == 1);
  /* disable bridge driver interrupt */
  CPU->NVIC_ICER0.reg = (uint32)(1u << BDRV_CP_Int);

  /* save CTRL3 register */
  lCTRL3 = BDRV->CTRL3.reg;
  
  /* set IDISCHARGE = 1, set DSMONVTH = 7 (2.00V) */
  BDRV->CTRL3.bit.DSMONVTH = 7;
  BDRV->CTRL3.bit.IDISCHARGEDIV2_N = 0;
  BDRV->CTRL3.bit.IDISCHARGE_TRIM = 1;
  
  /*****************/
  /* check Phase 1 */
  /*****************/
  BDRV_Set_Channel(LS1, Ch_En);
  BDRV_Set_Channel(LS2, Ch_En);
  BDRV_Set_Channel(LS3, Ch_En);

  BDRV_Set_Channel(HS1, Ch_En);

  /* enable HS2/3 DS-Current Source */
  BDRV_Set_Channel(HS2, Ch_DCS);
  BDRV_Set_Channel(HS3, Ch_DCS);
  
  /* Delay, give the DS-Current source some time to settle *
   * delay time depents on the attached motor              */
  Delay_us(800u);
  Delay_us(800u);
    
  /* clear status flags */
  SCUPM->BDRV_ISCLR.reg = BDRV_ISCLR_DS;
  
  /* check status flags */
  if (SCUPM->BDRV_IS.bit.HS1_DS_IS == 1u)
  {
      bOpenLoad = true;
  }

  /*****************/
  /* check Phase 2 */
  /*****************/
  BDRV_Set_Channel(LS1, Ch_En);
  BDRV_Set_Channel(LS2, Ch_En);
  BDRV_Set_Channel(LS3, Ch_En);

  BDRV_Set_Channel(HS2, Ch_En);

  /* enable HS1/3 DS-Current Source */
  BDRV_Set_Channel(HS1, Ch_DCS);
  BDRV_Set_Channel(HS3, Ch_DCS);
  
  /* Delay, give the DS-Current source some time to settle *
   * delay time depents on the attached motor              */
  Delay_us(800u);
  Delay_us(800u);
    
  /* clear status flags */
  SCUPM->BDRV_ISCLR.reg = BDRV_ISCLR_DS;

  if (SCUPM->BDRV_IS.bit.HS2_DS_IS == 1u)
  {
      bOpenLoad = true;
  }

  /*****************/
  /* check Phase 3 */
  /*****************/
  BDRV_Set_Channel(LS1, Ch_En);
  BDRV_Set_Channel(LS2, Ch_En);
  BDRV_Set_Channel(LS3, Ch_En);

  BDRV_Set_Channel(HS3, Ch_En);

  /* enable HS1/2 DS-Current Source */
  BDRV_Set_Channel(HS1, Ch_DCS);
  BDRV_Set_Channel(HS2, Ch_DCS);
  
  /* Delay, give the DS-Current source some time to settle *
   * delay time depents on the attached motor              */
  Delay_us(800u);
  Delay_us(800u);
    
  /* clear status flags */
  SCUPM->BDRV_ISCLR.reg = BDRV_ISCLR_DS;

  if (SCUPM->BDRV_IS.bit.HS3_DS_IS == 1u)
  {
      bOpenLoad = true;
  }
  
  /* switch off all drivers */
  BDRV->CTRL1.reg = (uint32)0;
  BDRV->CTRL2.reg = (uint32)0;
  
  /* restore CTRL3 register */
  BDRV->CTRL3.reg = lCTRL3;
  
  /* restore interrupt */
  if (bBDRV_Int_En == true)
  {
    CPU->NVIC_ISER0.bit.Int_BDRV = 1;
  }
  return(bOpenLoad);
}
#endif
