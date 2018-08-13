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
/* See port.c */

#ifndef PORT_H
#define PORT_H

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include <tle_device.h>
#include <Types.h>
#include "port_defines.h"

/*******************************************************************************
**                      Global Type Definitions                               **
*******************************************************************************/
/* Port indices */
#define PORT_P0 (0U)
#define PORT_P1 (1U)
#define PORT_P2 (2U)

/* Port actions */
#define PORT_ACTION_CLEAR  (0U)
#define PORT_ACTION_SET    (1U)
#define PORT_ACTION_TOGGLE (2U)
#define PORT_ACTION_INPUT  (3U)
#define PORT_ACTION_OUTPUT (4U)

/*******************************************************************************
**                      Global Macro Definitions                              **
********************************************************************************/
/* Port0 Macros */
/* Port0 Input/Output Set */
#define PORT_P00_Output_Set()      (PORT->P0_DIR.reg |= (uint8) (1u << 0u))
#define PORT_P00_Input_Set()       (PORT->P0_DIR.reg &= (uint8)~(1u << 0u))
#define PORT_P01_Output_Set()      (PORT->P0_DIR.reg |= (uint8) (1u << 1u))
#define PORT_P01_Input_Set()       (PORT->P0_DIR.reg &= (uint8)~(1u << 1u))
#define PORT_P02_Output_Set()      (PORT->P0_DIR.reg |= (uint8) (1u << 2u))
#define PORT_P02_Input_Set()       (PORT->P0_DIR.reg &= (uint8)~(1u << 2u))
#define PORT_P03_Output_Set()      (PORT->P0_DIR.reg |= (uint8) (1u << 3u))
#define PORT_P03_Input_Set()       (PORT->P0_DIR.reg &= (uint8)~(1u << 3u))
#define PORT_P04_Output_Set()      (PORT->P0_DIR.reg |= (uint8) (1u << 4u))
#define PORT_P04_Input_Set()       (PORT->P0_DIR.reg &= (uint8)~(1u << 4u))

/* Port0 Output Set/Reset */
#define PORT_P00_Output_High_Set()    (PORT->P0_DATA.reg |= (uint8) (1u << 0u))
#define PORT_P00_Output_Low_Set()     (PORT->P0_DATA.reg &= (uint8)~(1u << 0u))
#define PORT_P00_Output_Toggle_Set()  (PORT->P0_DATA.reg ^= (uint8) (1u << 0u))
#define PORT_P01_Output_High_Set()    (PORT->P0_DATA.reg |= (uint8) (1u << 1u))
#define PORT_P01_Output_Low_Set()     (PORT->P0_DATA.reg &= (uint8)~(1u << 1u))
#define PORT_P01_Output_Toggle_Set()  (PORT->P0_DATA.reg ^= (uint8) (1u << 1u))
#define PORT_P02_Output_High_Set()    (PORT->P0_DATA.reg |= (uint8) (1u << 2u))
#define PORT_P02_Output_Low_Set()     (PORT->P0_DATA.reg &= (uint8)~(1u << 2u))
#define PORT_P02_Output_Toggle_Set()  (PORT->P0_DATA.reg ^= (uint8) (1u << 2u))
#define PORT_P03_Output_High_Set()    (PORT->P0_DATA.reg |= (uint8) (1u << 3u))
#define PORT_P03_Output_Low_Set()     (PORT->P0_DATA.reg &= (uint8)~(1u << 3u))
#define PORT_P03_Output_Toggle_Set()  (PORT->P0_DATA.reg ^= (uint8) (1u << 3u))
#define PORT_P04_Output_High_Set()    (PORT->P0_DATA.reg |= (uint8) (1u << 4u))
#define PORT_P04_Output_Low_Set()     (PORT->P0_DATA.reg &= (uint8)~(1u << 4u))
#define PORT_P04_Output_Toggle_Set()  (PORT->P0_DATA.reg ^= (uint8) (1u << 4u))

/* Port0 Input */
#define PORT_P00_Get()             ((PORT->P0_DATA.reg >> 0u) & 1u)
#define PORT_P01_Get()             ((PORT->P0_DATA.reg >> 1u) & 1u)
#define PORT_P02_Get()             ((PORT->P0_DATA.reg >> 2u) & 1u)
#define PORT_P03_Get()             ((PORT->P0_DATA.reg >> 3u) & 1u)
#define PORT_P04_Get()             ((PORT->P0_DATA.reg >> 4u) & 1u)

/* Port0 OpenDrain Enable/Disable */
#define PORT_P00_OpenDrain_En()    (PORT->P0_OD.reg |= (uint8) (1u << 0u))
#define PORT_P00_OpenDrain_Dis()   (PORT->P0_OD.reg &= (uint8)~(1u << 0u))
#define PORT_P01_OpenDrain_En()    (PORT->P0_OD.reg |= (uint8) (1u << 1u))
#define PORT_P01_OpenDrain_Dis()   (PORT->P0_OD.reg &= (uint8)~(1u << 1u))
#define PORT_P02_OpenDrain_En()    (PORT->P0_OD.reg |= (uint8) (1u << 2u))
#define PORT_P02_OpenDrain_Dis()   (PORT->P0_OD.reg &= (uint8)~(1u << 2u))
#define PORT_P03_OpenDrain_En()    (PORT->P0_OD.reg |= (uint8) (1u << 3u))
#define PORT_P03_OpenDrain_Dis()   (PORT->P0_OD.reg &= (uint8)~(1u << 3u))
#define PORT_P04_OpenDrain_En()    (PORT->P0_OD.reg |= (uint8) (1u << 4u))
#define PORT_P04_OpenDrain_Dis()   (PORT->P0_OD.reg &= (uint8)~(1u << 4u))

/* Port0 PullUpDown Enable/Disable */
#define PORT_P00_PullUpDown_En()   (PORT->P0_PUDEN.reg |= (uint8) (1u << 0u))
#define PORT_P00_PullUpDown_Dis()  (PORT->P0_PUDEN.reg &= (uint8)~(1u << 0u))
#define PORT_P01_PullUpDown_En()   (PORT->P0_PUDEN.reg |= (uint8) (1u << 1u))
#define PORT_P01_PullUpDown_Dis()  (PORT->P0_PUDEN.reg &= (uint8)~(1u << 1u))
#define PORT_P02_PullUpDown_En()   (PORT->P0_PUDEN.reg |= (uint8) (1u << 2u))
#define PORT_P02_PullUpDown_Dis()  (PORT->P0_PUDEN.reg &= (uint8)~(1u << 2u))
#define PORT_P03_PullUpDown_En()   (PORT->P0_PUDEN.reg |= (uint8) (1u << 3u))
#define PORT_P03_PullUpDown_Dis()  (PORT->P0_PUDEN.reg &= (uint8)~(1u << 3u))
#define PORT_P04_PullUpDown_En()   (PORT->P0_PUDEN.reg |= (uint8) (1u << 4u))
#define PORT_P04_PullUpDown_Dis()  (PORT->P0_PUDEN.reg &= (uint8)~(1u << 4u))

/* Port0 PullUp/Down Set */
#define PORT_P00_PullUp_Set()      (PORT->P0_PUDSEL.reg |= (uint8) (1u << 0u))
#define PORT_P00_PullDown_Set()    (PORT->P0_PUDSEL.reg &= (uint8)~(1u << 0u))
#define PORT_P01_PullUp_Set()      (PORT->P0_PUDSEL.reg |= (uint8) (1u << 1u))
#define PORT_P01_PullDown_Set()    (PORT->P0_PUDSEL.reg &= (uint8)~(1u << 1u))
#define PORT_P02_PullUp_Set()      (PORT->P0_PUDSEL.reg |= (uint8) (1u << 2u))
#define PORT_P02_PullDown_Set()    (PORT->P0_PUDSEL.reg &= (uint8)~(1u << 2u))
#define PORT_P03_PullUp_Set()      (PORT->P0_PUDSEL.reg |= (uint8) (1u << 3u))
#define PORT_P03_PullDown_Set()    (PORT->P0_PUDSEL.reg &= (uint8)~(1u << 3u))
#define PORT_P04_PullUp_Set()      (PORT->P0_PUDSEL.reg |= (uint8) (1u << 4u))
#define PORT_P04_PullDown_Set()    (PORT->P0_PUDSEL.reg &= (uint8)~(1u << 4u))

/* Port1 Macros */
/* Port1 Input/Output Set */
#define PORT_P10_Output_Set()      (PORT->P1_DIR.reg |= (uint8) (1u << 0u))
#define PORT_P10_Input_Set()       (PORT->P1_DIR.reg &= (uint8)~(1u << 0u))
#define PORT_P11_Output_Set()      (PORT->P1_DIR.reg |= (uint8) (1u << 1u))
#define PORT_P11_Input_Set()       (PORT->P1_DIR.reg &= (uint8)~(1u << 1u))
#define PORT_P12_Output_Set()      (PORT->P1_DIR.reg |= (uint8) (1u << 2u))
#define PORT_P12_Input_Set()       (PORT->P1_DIR.reg &= (uint8)~(1u << 2u))
#define PORT_P13_Output_Set()      (PORT->P1_DIR.reg |= (uint8) (1u << 3u))
#define PORT_P13_Input_Set()       (PORT->P1_DIR.reg &= (uint8)~(1u << 3u))
#define PORT_P14_Output_Set()      (PORT->P1_DIR.reg |= (uint8) (1u << 4u))
#define PORT_P14_Input_Set()       (PORT->P1_DIR.reg &= (uint8)~(1u << 4u))

/* Port1 Output Set/Reset */
#define PORT_P10_Output_High_Set()    (PORT->P1_DATA.reg |= (uint8) (1u << 0u))
#define PORT_P10_Output_Low_Set()     (PORT->P1_DATA.reg &= (uint8)~(1u << 0u))
#define PORT_P10_Output_Toggle_Set()  (PORT->P1_DATA.reg ^= (uint8) (1u << 0u))
#define PORT_P11_Output_High_Set()    (PORT->P1_DATA.reg |= (uint8) (1u << 1u))
#define PORT_P11_Output_Low_Set()     (PORT->P1_DATA.reg &= (uint8)~(1u << 1u))
#define PORT_P11_Output_Toggle_Set()  (PORT->P1_DATA.reg ^= (uint8) (1u << 1u))
#define PORT_P12_Output_High_Set()    (PORT->P1_DATA.reg |= (uint8) (1u << 2u))
#define PORT_P12_Output_Low_Set()     (PORT->P1_DATA.reg &= (uint8)~(1u << 2u))
#define PORT_P12_Output_Toggle_Set()  (PORT->P1_DATA.reg ^= (uint8) (1u << 2u))
#define PORT_P13_Output_High_Set()    (PORT->P1_DATA.reg |= (uint8) (1u << 3u))
#define PORT_P13_Output_Low_Set()     (PORT->P1_DATA.reg &= (uint8)~(1u << 3u))
#define PORT_P13_Output_Toggle_Set()  (PORT->P1_DATA.reg ^= (uint8) (1u << 3u))
#define PORT_P14_Output_High_Set()    (PORT->P1_DATA.reg |= (uint8) (1u << 4u))
#define PORT_P14_Output_Low_Set()     (PORT->P1_DATA.reg &= (uint8)~(1u << 4u))
#define PORT_P14_Output_Toggle_Set()  (PORT->P1_DATA.reg ^= (uint8) (1u << 4u))

/* Port1 Input */
#define PORT_P10_Get()             ((PORT->P1_DATA.reg >> 0u) & 1u)
#define PORT_P11_Get()             ((PORT->P1_DATA.reg >> 1u) & 1u)
#define PORT_P12_Get()             ((PORT->P1_DATA.reg >> 2u) & 1u)
#define PORT_P13_Get()             ((PORT->P1_DATA.reg >> 3u) & 1u)
#define PORT_P14_Get()             ((PORT->P1_DATA.reg >> 4u) & 1u)

/* Port1 OpenDrain Enable/Disable */
#define PORT_P10_OpenDrain_En()    (PORT->P1_OD.reg |= (uint8) (1u << 1u))
#define PORT_P10_OpenDrain_Dis()   (PORT->P1_OD.reg &= (uint8)~(1u << 1u))
#define PORT_P11_OpenDrain_En()    (PORT->P1_OD.reg |= (uint8) (1u << 2u))
#define PORT_P11_OpenDrain_Dis()   (PORT->P1_OD.reg &= (uint8)~(1u << 2u))
#define PORT_P12_OpenDrain_En()    (PORT->P1_OD.reg |= (uint8) (1u << 3u))
#define PORT_P12_OpenDrain_Dis()   (PORT->P1_OD.reg &= (uint8)~(1u << 3u))
#define PORT_P13_OpenDrain_En()    (PORT->P1_OD.reg |= (uint8) (1u << 3u))
#define PORT_P13_OpenDrain_Dis()   (PORT->P1_OD.reg &= (uint8)~(1u << 3u))
#define PORT_P14_OpenDrain_En()    (PORT->P1_OD.reg |= (uint8) (1u << 4u))
#define PORT_P14_OpenDrain_Dis()   (PORT->P1_OD.reg &= (uint8)~(1u << 4u))

/* Port1 PullUpDown Enable/Disable */
#define PORT_P10_PullUpDown_En()   (PORT->P1_PUDEN.reg |= (uint8) (1u << 0u))
#define PORT_P10_PullUpDown_Dis()  (PORT->P1_PUDEN.reg &= (uint8)~(1u << 0u))
#define PORT_P11_PullUpDown_En()   (PORT->P1_PUDEN.reg |= (uint8) (1u << 1u))
#define PORT_P11_PullUpDown_Dis()  (PORT->P1_PUDEN.reg &= (uint8)~(1u << 1u))
#define PORT_P12_PullUpDown_En()   (PORT->P1_PUDEN.reg |= (uint8) (1u << 2u))
#define PORT_P12_PullUpDown_Dis()  (PORT->P1_PUDEN.reg &= (uint8)~(1u << 2u))
#define PORT_P13_PullUpDown_En()   (PORT->P1_PUDEN.reg |= (uint8) (1u << 3u))
#define PORT_P13_PullUpDown_Dis()  (PORT->P1_PUDEN.reg &= (uint8)~(1u << 3u))
#define PORT_P14_PullUpDown_En()   (PORT->P1_PUDEN.reg |= (uint8) (1u << 4u))
#define PORT_P14_PullUpDown_Dis()  (PORT->P1_PUDEN.reg &= (uint8)~(1u << 4u))

/* Port1 PullUp/Down Set */
#define PORT_P10_PullUp_Set()      (PORT->P1_PUDSEL.reg |= (uint8) (1u << 0u))
#define PORT_P10_PullDown_Set()    (PORT->P1_PUDSEL.reg &= (uint8)~(1u << 0u))
#define PORT_P11_PullUp_Set()      (PORT->P1_PUDSEL.reg |= (uint8) (1u << 1u))
#define PORT_P11_PullDown_Set()    (PORT->P1_PUDSEL.reg &= (uint8)~(1u << 1u))
#define PORT_P12_PullUp_Set()      (PORT->P1_PUDSEL.reg |= (uint8) (1u << 2u))
#define PORT_P12_PullDown_Set()    (PORT->P1_PUDSEL.reg &= (uint8)~(1u << 2u))
#define PORT_P13_PullUp_Set()      (PORT->P1_PUDSEL.reg |= (uint8) (1u << 3u))
#define PORT_P13_PullDown_Set()    (PORT->P1_PUDSEL.reg &= (uint8)~(1u << 3u))
#define PORT_P14_PullUp_Set()      (PORT->P1_PUDSEL.reg |= (uint8) (1u << 4u))
#define PORT_P14_PullDown_Set()    (PORT->P1_PUDSEL.reg &= (uint8)~(1u << 4u))

/* Port2 Macros */
/* Port2 Input/Disable Set */
#define PORT_P20_Dis()             (PORT->P2_DIR.reg |= (uint8) (1u << 0u))
#define PORT_P20_Input_Set()       (PORT->P2_DIR.reg &= (uint8)~(1u << 0u))
#define PORT_P22_Dis()             (PORT->P2_DIR.reg |= (uint8) (1u << 2u))
#define PORT_P22_Input_Set()       (PORT->P2_DIR.reg &= (uint8)~(1u << 2u))
#define PORT_P23_Dis()             (PORT->P2_DIR.reg |= (uint8) (1u << 3u))
#define PORT_P23_Input_Set()       (PORT->P2_DIR.reg &= (uint8)~(1u << 3u))
#define PORT_P24_Dis()             (PORT->P2_DIR.reg |= (uint8) (1u << 4u))
#define PORT_P24_Input_Set()       (PORT->P2_DIR.reg &= (uint8)~(1u << 4u))
#define PORT_P25_Dis()             (PORT->P2_DIR.reg |= (uint8) (1u << 5u))
#define PORT_P25_Input_Set()       (PORT->P2_DIR.reg &= (uint8)~(1u << 5u))

/* Port2 Input */
#define PORT_P20_Get()             ((PORT->P2_DATA.reg >> 0u) & 1u)
#define PORT_P22_Get()             ((PORT->P2_DATA.reg >> 2u) & 1u)
#define PORT_P23_Get()             ((PORT->P2_DATA.reg >> 3u) & 1u)
#define PORT_P24_Get()             ((PORT->P2_DATA.reg >> 4u) & 1u)
#define PORT_P25_Get()             ((PORT->P2_DATA.reg >> 5u) & 1u)

/* Port2 PullUpDown Enable/Disable */
#define PORT_P20_PullUpDown_En()   (PORT->P2_PUDEN.reg |= (uint8) (1u << 0u))
#define PORT_P20_PullUpDown_Dis()  (PORT->P2_PUDEN.reg &= (uint8)~(1u << 0u))
#define PORT_P22_PullUpDown_En()   (PORT->P2_PUDEN.reg |= (uint8) (1u << 2u))
#define PORT_P22_PullUpDown_Dis()  (PORT->P2_PUDEN.reg &= (uint8)~(1u << 2u))
#define PORT_P23_PullUpDown_En()   (PORT->P2_PUDEN.reg |= (uint8) (1u << 3u))
#define PORT_P23_PullUpDown_Dis()  (PORT->P2_PUDEN.reg &= (uint8)~(1u << 3u))
#define PORT_P24_PullUpDown_En()   (PORT->P2_PUDEN.reg |= (uint8) (1u << 4u))
#define PORT_P24_PullUpDown_Dis()  (PORT->P2_PUDEN.reg &= (uint8)~(1u << 4u))
#define PORT_P25_PullUpDown_En()   (PORT->P2_PUDEN.reg |= (uint8) (1u << 5u))
#define PORT_P25_PullUpDown_Dis()  (PORT->P2_PUDEN.reg &= (uint8)~(1u << 5u))

/* Port2 PullUp/Down Set */
#define PORT_P20_PullUp_Set()      (PORT->P2_PUDSEL.reg |= (uint8) (1u << 0u))
#define PORT_P20_PullDown_Set()    (PORT->P2_PUDSEL.reg &= (uint8)~(1u << 0u))
#define PORT_P22_PullUp_Set()      (PORT->P2_PUDSEL.reg |= (uint8) (1u << 2u))
#define PORT_P22_PullDown_Set()    (PORT->P2_PUDSEL.reg &= (uint8)~(1u << 2u))
#define PORT_P23_PullUp_Set()      (PORT->P2_PUDSEL.reg |= (uint8) (1u << 3u))
#define PORT_P23_PullDown_Set()    (PORT->P2_PUDSEL.reg &= (uint8)~(1u << 3u))
#define PORT_P24_PullUp_Set()      (PORT->P2_PUDSEL.reg |= (uint8) (1u << 4u))
#define PORT_P24_PullDown_Set()    (PORT->P2_PUDSEL.reg &= (uint8)~(1u << 4u))
#define PORT_P25_PullUp_Set()      (PORT->P2_PUDSEL.reg |= (uint8) (1u << 5u))
#define PORT_P25_PullDown_Set()    (PORT->P2_PUDSEL.reg &= (uint8)~(1u << 5u))


/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Declarations                          **
*******************************************************************************/
void PORT_Init(void);

/* Inline functions ***********************************************************/
__STATIC_INLINE void PORT_ChangePin(uint32 PortPin, uint32 Action);
__STATIC_INLINE uint32 PORT_ReadPin(uint32 PortPin);
__STATIC_INLINE uint32 PORT_ReadPort(uint32 Port);
__STATIC_INLINE void PORT_ChangePinAlt(uint32 PortPin, uint8 AltSel);

/*******************************************************************************
**                      Global Inline Function Definitions                    **
*******************************************************************************/
/** \brief Sets/clears/toggles a port pin in a safe way, i.e. with interrupt disable.
 *
 * \param[in] PortPin Port and pin to change, e.g 0x12U for P1.2
 * \param[in] Action PORT_ACTION_SET, PORT_ACTION_CLEAR or PORT_ACTION_TOGGLE
 * \return None
 *
 * \ingroup PORT_api
 */
__STATIC_INLINE void PORT_ChangePin(uint32 PortPin, uint32 Action)
{
  volatile uint8 *pSfr;
  uint32 PinMask;

  /* Pin mask = 1 shifted left by pin */
  PinMask = 1U << (PortPin & 0x7U);

  /* DATA pointer = address of P0_DATA + port * 8 */
  pSfr = (&(PORT->P0_DATA.reg)) + ((PortPin >> 4U) << 3U);

  /* Change DATA register according to Action */
  __disable_irq();
  if (Action == PORT_ACTION_CLEAR)
  {
    *pSfr &= (~PinMask);
  }
  else if (Action == PORT_ACTION_SET)
  {
    *pSfr |= PinMask;
  }
  else if (Action == PORT_ACTION_TOGGLE)
  {
    *pSfr ^= PinMask;
  }
  else if (Action == PORT_ACTION_INPUT)
  {
    pSfr = (&(PORT->P0_DIR.reg)) + ((PortPin >> 4U) << 3U);
    *pSfr &= (~PinMask);
  }
  else                          /* (Action == PORT_ACTION_OUTPUT) */
  {
    pSfr = (&(PORT->P0_DIR.reg)) + ((PortPin >> 4U) << 3U);
    *pSfr |= PinMask;
  }
  __enable_irq();
}                               /* End of PORT_ChangePin */


/** \brief Reads a port pin.
 *
 * \param[in] PortPin Port and pin to read, e.g 0x12U for P1.2
 * \return Port pin level (0U or 1U)
 *
 * \ingroup PORT_api
 */
__STATIC_INLINE uint32 PORT_ReadPin(uint32 PortPin)
{
  volatile uint8 *pSfr;

  /* DATA pointer = address of P0_DATA + port * 8 */
  pSfr = (&(PORT->P0_DATA.reg)) + ((PortPin >> 4U) << 3U);

  /* Read DATA register, shift right by pin and extract bit 0 */
  return (*pSfr >> (PortPin & 0x7U)) & 1U;
}                               /* End of PORT_ReadPin */


/** \brief Reads a port.
 *
 * \param[in] Port Port to read, e.g. 2U for Port 2
 * \return Port data (combination of 0Us and 1Us)
 *
 * \ingroup PORT_api
 */
__STATIC_INLINE uint32 PORT_ReadPort(uint32 Port)
{
  volatile uint8 *pSfr;

  /* DATA pointer = address of P0_DATA + port * 8 */
  pSfr = (&(PORT->P0_DATA.reg)) + (Port << 3U);

  /* Read DATA register */
  return *pSfr;
}                               /* End of PORT_ReadPort */

/** \brief Change Alternative Settings.
 *
 * \param[in] Port to change AltSel, e.g. 1U for Port 1
 * \return AltSel data (combination of 0Us and 1Us)
 *
 * \ingroup PORT_api
 */
__STATIC_INLINE void PORT_ChangePinAlt(uint32 PortPin, uint8 AltSel)
{
  volatile uint8 *pSfr0, *pSfr1;
  uint32 PinMask;

  /* Pin mask = 1 shifted left by pin */
  PinMask = 1U << (PortPin & 0x7U);
  PortPin &= 0x1F;              /* only Port0 and Port1 are allowed */

  /* DATA pointer = address of P0_DATA + port * 8 */
  pSfr0 = (&(PORT->P0_ALTSEL0.reg)) + ((PortPin >> 4U) << 3U);
  pSfr1 = (&(PORT->P0_ALTSEL1.reg)) + ((PortPin >> 4U) << 3U);

  /* Change DATA register according to Action */
  __disable_irq();

  *pSfr0 &= (~PinMask);
  *pSfr1 &= (~PinMask);

  if ((AltSel & 1) != 0)
  {
    *pSfr0 |= PinMask;
  }
  if ((AltSel & 2) != 0)
  {
    *pSfr1 |= PinMask;
  }

  __enable_irq();
}                               /* End of PORT_ChangePinAlt */

#endif /* PORT_H */
