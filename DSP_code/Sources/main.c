/* ###################################################################
**     Filename    : main.c
**     Project     : try2_codewarrior
**     Processor   : MC56F8006_48_LQFP
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2018-08-12, 15:17, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.16
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "SS1.h"
#include "MEM1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#include <stdio.h>
#include <stdlib.h>

void main(void)
{
  /* Write your local variable definition here */
	char spi_test_string[] = "Hello Roboy";
	signed char cnt = 0;
	unsigned char er_cnt = 0;
	word isTxBuffEmpty;
	
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	//this already init SPI 
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  for(;;) {
	  //Puts the char in the buffer
	  SS1_SendChar(spi_test_string[cnt]);
	  //Wait till the buffer is empty ... (if it takes too long it breaks);
	  for(er_cnt= 0;er_cnt<=100; er_cnt++){
		  isTxBuffEmpty = SS1_GetCharsInTxBuf();
		  if (isTxBuffEmpty == 0)
			  break;
	  }
	  //reset the string counter if end reached
	  if(sizeof(spi_test_string) >= cnt)
		  cnt = -1; 
	  
	  cnt++;
  }
}

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale 56800 series of microcontrollers.
**
** ###################################################################
*/
