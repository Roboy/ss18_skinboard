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

/******************************************************************************/
/** BLDC: Motor Drive with block commutation and Hall sensor                 **/
/******************************************************************************/
/** use the Poti to start/stop and speedup motor                             **/
/** Motor connection, QBL4208:                                               **/
/** Phase 1             : black                                              **/
/** Phase 2             : yellow                                             **/
/** Phase 3             : red                                                **/
/** Hall A - P0.3       : blue                                               **/
/** Hall B - P0.4       : green                                              **/
/** Hall C - P1.2       : white                                              **/
/** Hall Supply - VDDEXT: red                                                **/
/** Hall Gnd - GND      : black                                              **/
/******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "tle_device.h"
#include "Main.h"
#include "Emo.h"

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void Main_lStartMotor(void);
static void Main_lStopMotor(void);
void Poti_Handler(void);

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Constant Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/** \brief Executes main code.
 *
 * \param None
 * \return None
 *
 */
int main(void)
{
  /*****************************************************************************
  ** initialization of the hardware modules based on the configuration done   **
  ** by using the IFXConfigWizard                                             **
  *****************************************************************************/
  TLE_Init();
	
  /* Initialize E-Motor application */
  Emo_Init();
	Emo_SetRefSpeed(1000);
	Main_lStartMotor();
	
  while (1)
  { 
    /* Service watch-dog */
    WDT1_Service();
  }
} /* End of main() */

void Main_HandleSysTick(void)
{
  /* Callback function executed every ms for speed control */
  Emo_CtrlSpeed();
} /* End of Main_HandleSysTick */

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
static void Main_lStartMotor(void)
{
  uint32 Error;
  
  Error = EMO_ERROR_NONE;
  if(Error == EMO_ERROR_NONE)
  {
    /* Start motor with desired positive or negative speed in [rpm] */
    Error = Emo_StartMotor();
  }
  if(Error == EMO_ERROR_NONE)
  {
  }  
  else /* Error */     
  {
    
  }  
} /* End of Main_lStartMotor */


static void Main_lStopMotor(void)
{
  uint32 Error;
  
  Error = Emo_StopMotor(); 

  if(Error != EMO_ERROR_NONE)
  {
    
  }  
} /* End of Main_lStopMotor */

void Poti_Handler(void)
{
	uint16 mV;
	
	/* read the value at Ch4 (Poti) in mV     *
	 * values between 0 and 5000 are possible */
	if (ADC1_GetChResult_mV(&mV, ADC1_CH4) == true)
	{
    
		Emo_SetRefSpeed(500);
    if (200 > 100)
    {
      Main_lStartMotor();
    }
    else
    {
      Main_lStopMotor();
    }
	}
}
