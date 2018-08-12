/* ###################################################################
**     Filename    : Events.h
**     Project     : try2_codewarrior
**     Processor   : MC56F8006_48_LQFP
**     Component   : Events
**     Version     : Driver 01.03
**     Compiler    : CodeWarrior DSP C Compiler
**     Date/Time   : 2018-08-12, 15:17, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.03
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "SS1.h"
#include "MEM1.h"


void SS1_OnRxChar(void);
/*
** ===================================================================
**     Event       :  SS1_OnRxChar (module Events)
**
**     Component   :  SS1 [SynchroSlave]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**         [ Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and the
**         receiver is configured to use DMA controller then this event
**         is disabled. Only OnFullRxBuf method can be used in DMA mode.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SS1_OnTxChar(void);
/*
** ===================================================================
**     Event       :  SS1_OnTxChar (module Events)
**
**     Component   :  SS1 [SynchroSlave]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SS1_OnTxEmptyChar(void);
/*
** ===================================================================
**     Event       :  SS1_OnTxEmptyChar (module Events)
**
**     Component   :  SS1 [SynchroSlave]
**     Description :
**         The event is called when an Empty character is sent
**         automaticaly if no user data is in buffer (see <Empty
**         character> property for details about empty character).
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**         [ Version specific information for Freescale 56800
**         derivatives ] 
**         DMA mode:
**         If DMA controller is available on the selected CPU and the
**         transmitter is configured to use DMA controller then this
**         event is not available.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SS1_OnError(void);
/*
** ===================================================================
**     Event       :  SS1_OnError (module Events)
**
**     Component   :  SS1 [SynchroSlave]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

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
