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
#include <port.h>
#include <eval_board.h>
#include <stdio.h>



volatile uint16_t DMA_send_reg[ 12 ];
volatile uint16_t DMA_receive_reg[ 12 ];
volatile uint16_t received;
int count = 0;
volatile int SS = 0;

//Ptrs to the position of send data
volatile uint16_t *velocity;
volatile uint16_t *current;
volatile uint16_t *tendon_stretch;
volatile uint16_t *sensor1;
volatile uint16_t *sensor2;
volatile uint16_t *position;
volatile uint16_t *error_flag;


// Pointers to the positions of received data
volatile uint16_t *message_type;
volatile uint16_t *duty_cycle;
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
static void Main_lStartMotor(void);
static void Main_lStopMotor(void);
void Poti_Handler(void);
void process_data ( void );
void SS_High ( void );
void SS_Low( void );
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
	uint32_t pin_read = 0x00000000; 
	int i;
  /*****************************************************************************
  ** initialization of the hardware modules based on the configuration done   **
  ** by using the IFXConfigWizard                                             **
  *****************************************************************************/
  TLE_Init();
	
  Emo_Init(); //Initialize E-Motor application
	DMA_Init(); // Initialise the DMA
	DMA_Master_En(); // Starts the DMA
	PORT_Init(); //Initialises the ports
	
	for( i = 0; i < DMA_CH2_NoOfTrans; i++ ) {
		DMA_send_reg[ i ] = ( uint16_t ) ( 0x0000 );
		DMA_receive_reg[ i ] = (uint16_t)( 0x0000 );
	}
	
	position = &DMA_send_reg[4];
	velocity = &DMA_send_reg[6];
	current = &DMA_send_reg[7];
	tendon_stretch = &DMA_send_reg[8];
	sensor1 = &DMA_send_reg[9];
	sensor2 = &DMA_send_reg[10];
	error_flag = &DMA_send_reg[11];
	
	message_type = &DMA_receive_reg[0];
	duty_cycle = &DMA_receive_reg[1];
	
	//According to examples the first word needs to be send manually. 
	//This begins the SPI device triggering it's interrupt to ask for more bytes.
	Emo_SetRefSpeed(2000);
	Main_lStartMotor();
	DMA_Reset_Channel( DMA_CH2, ( DMA_CH3_NoOfTrans - 1 ));
	DMA_Reset_Channel( DMA_CH3, DMA_CH2_NoOfTrans );
  DMA_receive_reg[0] = SSC1_SendWord(0x0000); 
	
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

//Function to be called once the DMA transfers all 12 bytes. 
void transmit_data ( void ) {
	int j;
	
	process_data();
	for ( j = 0; j < DMA_CH2_NoOfTrans; j++) {
		if (DMA_receive_reg[j] == 0x8000) {
				DMA_Reset_Channel(DMA_CH2, DMA_CH2_NoOfTrans - j);
				DMA_Reset_Channel(DMA_CH3, DMA_CH3_NoOfTrans - j);
		}
	}
}

//Basically want to use this one to keep my DMA in sync with  the frame. 
void receive_data ( void ) {
	
	int j = 0;
}

/* Set all output values and process received data */
void process_data ( void ) {
	
	*position = 0xCAFE;
	*velocity = Emo_GetAbsSpeed();
	*current = 0xFADE;
	*tendon_stretch = 0xFEED;
	*sensor1 = 0x1001;
	*sensor2 = 0x1002;
	*error_flag = 0x1005;
	
	
}

/*	Called on the falling edge of the CS Pin. Used to set
		the MISO pin to be an output*/
void SS_Low( void ) {
	
  volatile uint8 *pSfr;
  uint32 PinMask;
	uint32 PortPin = 0x04U;

  //Pin mask = 1 shifted left by pin
  PinMask = 1U << (PortPin & 0x7U);

  //DATA pointer = address of P0_DATA + port * 8 
  pSfr = (&(PORT->P0_DATA.reg)) + ((PortPin >> 4U) << 3U);

  //Change DATA register according to Action 
  __disable_irq();
  
	pSfr = (&(PORT->P0_DIR.reg)) + ((PortPin >> 4U) << 3U);
  *pSfr |= PinMask;
  
	__enable_irq();
	
	SS = 0;
}

/*	Called on the rising edge of the CS Pin. Used to set
		the MISO pin to be an input
*/
void SS_High ( void ) {
	
  volatile uint8 *pSfr;
  uint32 PinMask;

	uint32 PortPin = 0x04U;
  pSfr = (&(PORT->P0_DATA.reg)) + ((PortPin >> 4U) << 3U);

  // Change DATA register according to Action 
  __disable_irq();
	
  pSfr = (&(PORT->P0_DIR.reg)) + ((PortPin >> 4U) << 3U);
  *pSfr &= (~PinMask);

  __enable_irq();                         
	//End of PORT_ChangePinAlt 
	
	SS = 1;
	
} 



