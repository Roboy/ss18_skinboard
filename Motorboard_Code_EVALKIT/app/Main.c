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
void process_data( void );
void receive_data( void );

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/

//Ptrs to the position of send data
volatile int16_t *velocity;
volatile int16_t *current;
volatile int16_t *tendon_stretch;
volatile int16_t *sensor1;
volatile int16_t *sensor2;
volatile int16_t *position;
volatile int16_t *error_flag;

// Pointers to the positions of received data
volatile int16_t *message_type;
volatile int16_t *duty_cycle;

volatile int32_t enc_pos = 0;
volatile int16_t current_meas;

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
volatile int16_t DMA_send_reg[ 12 ];
volatile int16_t DMA_receive_reg[ 12 ];
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
  int i;
	/*****************************************************************************
  ** initialization of the hardware modules based on the configuration done   **
  ** by using the IFXConfigWizard                                             **
  *****************************************************************************/
	//SCU->DMASRCSEL.bit.SSCTXSRCSEL = 1;
	//SCU->DMASRCSEL.bit.SSCRXSRCSEL = 1;
	TLE_Init();
	SCU->DMASRCSEL.bit.SSCTXSRCSEL = 1;
	SCU->DMASRCSEL.bit.SSCRXSRCSEL = 1;
  Emo_Init(); //Initialize E-Motor application
	DMA_Init(); // Initialise the DMA
	DMA_Master_En(); // Starts the DMA
	//PORT_Init(); //Initialises the ports
	//SCU->DMASRCSEL.bit.SSCTXSRCSEL = 1;
	//SCU->DMASRCSEL.bit.SSCRXSRCSEL = 1;
  /* Initialize E-Motor application */
	for( i = 0; i < DMA_CH2_NoOfTrans; i++ ) {
		DMA_send_reg[ i ] = ( uint16_t ) ( 0 );
		DMA_receive_reg[ i ] = (uint16_t)( 0 );
	}
	DMA_Reset_Channel( DMA_CH2, ( DMA_CH3_NoOfTrans - 1 ));
	DMA_Reset_Channel( DMA_CH3, DMA_CH2_NoOfTrans );
	//SCU->DMASRCSEL.bit.SSCTXSRCSEL = 1;
	//SCU->DMASRCSEL.bit.SSCRXSRCSEL = 1;
	DMA_receive_reg[0] = SSC2_SendWord(0xFEED);
  
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
	process_data();
	Emo_SetRefSpeed((500));
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
    //Emo_SetRefSpeed(mV / 2);
    if (100>10)
    {
      Main_lStartMotor();
    }
    else
    {
      Main_lStopMotor();
    }
	}
}

void transmit_data ( void ) {

	DMA_Reset_Channel(DMA_CH2, DMA_CH2_NoOfTrans);
	
	Emo_SetRefSpeed(*duty_cycle);
	if (*duty_cycle > 50) {
		
		Main_lStartMotor();
  } else {
		
		Main_lStopMotor();
  }
	process_data();
}

void receive_data( void ){
	DMA_Reset_Channel(DMA_CH3, DMA_CH3_NoOfTrans);
	DMA_send_reg[1] = *duty_cycle;
	DMA_send_reg[0] = *message_type;
	
}
void process_data( void ) {
	uint16_t mV;
	
	*position = enc_pos;
	*velocity = Emo_GetAbsSpeed();
	*sensor1 = 0xFEED;
	*sensor2 = 0xFADE;
	*error_flag = 0xFACE;
	if ( ADC1_GetChResult_mV(&mV, ADC1_CH1) == true ) {
		//V = IR ( current (mA = V/R   R = 0.005 -> multiply by 200;
		current_meas = mV * 200;
	};
	*current = current_meas;
}

void rotary_encoder ( void ) {
	//Triggered on the rising Edge of Enc_B ( P2.4 ). 

	//Check status of Enc_A ( P2.0 )
	if ( PORT->P2_DATA.bit.P5 ) {
		
		//If Enc_A is already on, it means a turn in 1 direction:
		enc_pos++;
	
	} else {
		
		enc_pos--;
	}
}

void current_measure( void ) {
	uint16_t mV; 
	if ( ADC1_GetChResult_mV(&mV, ADC1_CH1) == true ) {
		//V = IR
		//current_meas = mV / 0.005;
	} ;
}

