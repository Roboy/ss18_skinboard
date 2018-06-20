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
	
  /* Initialize E-Motor application */
  Emo_Init();
	DMA_Init(); // Initialise the DMA
	DMA_Master_En(); // Apparently starts the DMA running. 
	PORT_Init();
	
	for( i = 0; i < DMA_CH2_NoOfTrans; i++ ) {
		DMA_send_reg[ i ] = ( uint16_t ) ( 0x0000 );
		DMA_receive_reg[ i ] = (uint16_t)( 0x0000 );
	}
	
	position = &DMA_send_reg[6];
	velocity = &DMA_send_reg[7];
	current = &DMA_send_reg[8];
	tendon_stretch = &DMA_send_reg[9];
	sensor1 = &DMA_send_reg[10];
	sensor2 = &DMA_send_reg[11];
	//error_flag = &DMA_send_reg[12];
	
	message_type = &DMA_receive_reg[0];
	duty_cycle = &DMA_receive_reg[1];
	
	//According to examples the first word needs to be send manually. 
	//This begins the SPI device triggering it's interrupt to ask for more bytes.
	Emo_SetRefSpeed(2000);
	Main_lStartMotor();
	DMA_Reset_Channel( DMA_CH2, ( DMA_CH3_NoOfTrans - 1 ));
	DMA_Reset_Channel( DMA_CH3, DMA_CH2_NoOfTrans );
  DMA_receive_reg[0] = SSC1_SendWord(0xA0AA); 
	
  while (1)
  { 
    /* Service watch-dog */
    WDT1_Service();
  }
} /* End of main() */

void Main_HandleSysTick(void)
{
  /* Callback function executed every ms for speed control */
  //Emo_CtrlSpeed();
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
	
	/* read the value at Ch4 (Poti) in mV     */
	// values between 0 and 5000 are possible 
	/*
	if (ADC1_GetChResult_mV(&mV, ADC1_CH4) == true)
	{
    Emo_SetRefSpeed(mV / 2); 
    if (mV > 100)
    {
      Main_lStartMotor();
    }
    else
    {
      Main_lStopMotor();
    }
	} */
}

//Function to be called once the DMA transfers all 12 bytes. 
void transmit_data ( void ) {
	int j;
	//process_data();
	//try to change the data to be sent. 
	/*for( i = 0; i < 12; i++ ) {
		DMA_send_reg[ i ] = DMA_receive_reg[ i ]; 
	}*/
	//DMA_send_reg[0] = 0x8000;
	
	
	//PORT_ChangePin( 0x04U, PORT_ACTION_INPUT );

	//SSC1_SendWord( 0xF00D );
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
	//printf( "SPI Read: %x\n", DMA_receive_reg[count]);
	/*DMA_receive_reg[ count ] = received;
	if ( DMA_receive_reg[ 0 ] == 0x8000 ) {
		count = 0;
	}
	if ( count == 12 ) {
		DMA_Reset_Channel(DMA_CH2, DMA_CH2_NoOfTrans);
		//DMA_Reset_Channel(DMA_CH3, DMA_CH3_NoOfTrans);
	} else {
		count++;
	} */
	//DMA_Reset_Channel(DMA_CH2, DMA_CH2_NoOfTrans - j);
	//DMA_Reset_Channel(DMA_CH3, DMA_CH3_NoOfTrans - j);
	
	
}


void process_data ( void ) {
	*position = 0xCAFE;
	//*velocity = 0xFACE;
	*current = 0xFADE;
	*tendon_stretch = 0xFEED;
	*sensor1 = 0x1001;
	*sensor2 = 0x1002;
	//error_flag = &DMA_send_reg[12];
	
	//*message_type;
	//*duty_cycle;
	
}

void SS_Low( void ) {
	//PORT_ChangePin( 0x04U, PORT_ACTION_OUTPUT );

	
	//uint32 Action = PORT_ACTION_OUTPUT;
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
	
	//PORT_ChangePin( 0x04U, PORT_ACTION_OUTPUT );
	
	//Work out which pin is 
	*velocity = Emo_GetAbsSpeed();
	
	//DMA_Reset_Channel(DMA_CH3, DMA_CH3_NoOfTrans);
	//DMA_Reset_Channel(DMA_CH2, DMA_CH2_NoOfTrans);
	
	SS = 0;
}


void SS_High ( void ) {
	

	//PORT_ChangePin( 0x04U, PORT_ACTION_INPUT );
  volatile uint8 *pSfr;
  uint32 PinMask;

  //Pin mask = 1 shifted left by pin 
	uint32 PortPin = 0x04U;
	//uint32 Action = PORT_ACTION_INPUT;
  // DATA pointer = address of P0_DATA + port * 8 
  pSfr = (&(PORT->P0_DATA.reg)) + ((PortPin >> 4U) << 3U);

  // Change DATA register according to Action 
  //__disable_irq();
	
  pSfr = (&(PORT->P0_DIR.reg)) + ((PortPin >> 4U) << 3U);
  *pSfr &= (~PinMask);

  //__enable_irq();                          //End of PORT_ChangePinAlt 
	
	SS = 1;
	
} 

/* Notes to Self:
This command can set high low as well as input output
void PORT_ChangePin(uint32 PortPin, uint32 Action

I need to change the SSC channel to use 2 instead of 1.
As this is required for the pin assignment chosen.
 
*/

