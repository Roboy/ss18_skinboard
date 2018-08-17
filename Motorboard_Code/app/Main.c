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
void process_data( void );
void SS_High( void );
void SS_Low( void );
void current_measured( void );

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

volatile uint16_t DMA_send_reg[ 12 ];
volatile uint16_t DMA_receive_reg[ 12 ];
volatile int8_t ADC_Current;
volatile int8_t ADC_Ao;
volatile uint16_t received;
int count = 0;
volatile int SS = 0;
int motor_position = 0;
volatile uint8 *pSfr;
uint32 PinMask,input_mask;


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
	//uint32_t pin_read = 0x00000000; 
	int i;
  /*****************************************************************************
  ** initialization of the hardware modules based on the configuration done   **
  ** by using the IFXConfigWizard                                             **
  *****************************************************************************/
	TLE_Init();
  Emo_Init(); //Initialize E-Motor application
	DMA_Init(); // Initialise the DMA
	DMA_Master_En(); // Starts the DMA
	//PORT_Init(); //Initialises the ports
	
	
	SCU->DMASRCSEL.bit.SSCTXSRCSEL = 0;
	SCU->DMASRCSEL.bit.SSCRXSRCSEL = 0;
	
	//SS_High(); //Set MISO to be input. 
	//SS_Low();
	//Initiate send and receive registers.
	for( i = 0; i < DMA_CH2_NoOfTrans; i++ ) {
		DMA_send_reg[ i ] = ( uint16_t ) ( 0xAAAA );
		DMA_receive_reg[ i ] = (uint16_t)( 0xAAAA );
	}
	Emo_SetRefSpeed(2000);
	Main_lStartMotor();
	//process_data();
	
	//Direct appropriate data pointers to desired section of the frame.
	//Send Data:
	position = &DMA_send_reg[4];
	velocity = &DMA_send_reg[6];
	current = &DMA_send_reg[7];
	tendon_stretch = &DMA_send_reg[8];
	sensor1 = &DMA_send_reg[9];
	sensor2 = &DMA_send_reg[10];
	error_flag = &DMA_send_reg[11];
	
	//Receive Data
	message_type = &DMA_receive_reg[0];
	duty_cycle = &DMA_receive_reg[1];
	
	//First SPI word must be send manually, SSC module then triggeres DMA for more.
	DMA_Reset_Channel( DMA_CH2, ( DMA_CH3_NoOfTrans - 1 ));
	DMA_Reset_Channel( DMA_CH3, DMA_CH2_NoOfTrans );
  DMA_receive_reg[0] = SSC2_SendWord(0x40AA); 
	count++;
	
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
	//int j;
	DMA_Reset_Channel(DMA_CH2, DMA_CH2_NoOfTrans);
	
	process_data();
	/*for ( j = 0; j < DMA_CH2_NoOfTrans; j++) {
		if (DMA_receive_reg[j] == 0x8000) {
				DMA_Reset_Channel(DMA_CH2, DMA_CH2_NoOfTrans - j);
				DMA_Reset_Channel(DMA_CH3, DMA_CH3_NoOfTrans - j);
		}
	}*/
	
	//All Data transmitted for this frame. Now set MISO to be input. 
	SS_High();
}

//Basically want to use this one to keep my DMA in sync with  the frame. 
void receive_data ( void ) {
	
	//int j = 0;
	DMA_Reset_Channel(DMA_CH3, DMA_CH2_NoOfTrans);
}

/* Set all output values and process received data */
void process_data ( void ) {
	//Maybe change this so it is triggered by SS_High. I.e. frame ended and data received.
	//*position = 0xCAFE;
	//*velocity = Emo_GetAbsSpeed();
	
	//*current = 0xFADE;
	*tendon_stretch = 0xAAAA; //Still to do
	*sensor1 = 0xFEED;
	*sensor2 = 0xFADE;
	*error_flag = 0xFACE;

	

}

/*	Called on the falling edge of the CS Pin. Used to set
		the MISO pin to be an output*/
void SS_Low( void ) {
	
	//PORT_ChangePin(0x04U, PORT_ACTION_OUTPUT);
	//SSC1->CON.PRG_bit.EN = 1;
	
	//Sets P0.4 to be an output.
	//PORT->P0_DIR.bit.P4 = 1;
	SS = 1;
	
}

/*	Called on the rising edge of the CS Pin. Used to set
		the MISO pin to be an input
*/
void SS_High ( void ) {
	//SSC1->CON.PRG_bit.EN = 0;
  //PORT_ChangePin(0x04U, PORT_ACTION_INPUT);
	
	//Sets P0.4 to be input.
	//PORT->P0_DIR.bit.P4 = 0;
	SS = 0;
} 

/* 	Called through an interupt placed on pin P2.4. Triggered on the rissing edge.
		Checks if encoder B is already high. If it is, then turning one way, if it isn't: Turning the other way. 
		Directly updates the value stored in the send register.
*/
void rotary_encoder ( void ) {
	//Triggered on the rising Edge of Enc_B ( P2.4 ). 

	//Check status of Enc_A ( P2.0 )
	if ( PORT->P2_DATA.bit.P0 ) {
		
		//If Enc_A is already on, it means a turn in 1 direction:
		*position++;
	
	} else {
		
		*position--;
	}
}


/* 	Called through an interupt placed on pin P0.1. Triggered on the rissing edge.
		Checks if encoder B is already high. If it is, then turning one way, if it isn't: Turning the other way. 
		Directly updates the value stored in the send register.
*/
void displacement_encoder ( void ) {
	//Triggered on the rising Edge of Disp_A ( P0.1 ). 

	//Check status of Enc_B ( P0.3 )
	if ( PORT->P0_DATA.bit.P3 ) {
		
		//If Enc_B is already on, it means a turn in 1 direction:
		*tendon_stretch++;
	
	} else {
		
		*tendon_stretch--;
	}
}

/*	Activated by the DMA when ADC_Current has been loaded with a new value.
		Updates the value in the send register directly.
*/
void current_measured( void ) {
	
	//Used shunt resitor of value 0.005Ohm. Determine current through it.
	*current = ADC_Current / 0.005;
	
}


