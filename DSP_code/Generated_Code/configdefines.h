/*****************************************************************************
*
* (c) Freescale Semiconductor
* 2004 All Rights Reserved
*
*
******************************************************************************
*
* File Name: configdefines.h
*
* Description: This file is used to automatically define the configuration
* variables required by a specific SDK module. For example, the codec driver
* uses the SSI driver so when the user defines INCLUDE_CODEC in AppConfig.h,
* this file automatically defines INCLUDE_SSI. This simplifies the selection
* of the driver since the user does not need to know which additional modules
* to define.
*
*****************************************************************************/
#ifndef __CONFIGDEFINES_H
#define __CONFIGDEFINES_H

#ifdef __cplusplus
extern "C" {
#endif


/****************************************************************************
*
* Include user selected SDK components
*
****************************************************************************/
#include "AppConfig.h"

/****************************************************************************
*
* Resolve include dependencies automatically
*
****************************************************************************/

#ifdef INCLUDE_BSP
  #ifndef INCLUDE_PLL
    #define INCLUDE_PLL
  #endif
  #ifndef INCLUDE_SIM
    #define INCLUDE_SIM
  #endif
  #ifndef INCLUDE_CORE
    #define INCLUDE_CORE
  #endif
  #ifndef INCLUDE_ITCN
    #define INCLUDE_ITCN
  #endif
#endif

#ifdef INCLUDE_LED
  #ifndef INCLUDE_GPIO
    #define INCLUDE_GPIO
  #endif
#endif

#ifdef INCLUDE_CYCLECOUNT
  #ifndef INCLUDE_QUAD_TIMER
    #define INCLUDE_QUAD_TIMER
  #endif
#endif

#ifdef INCLUDE_BUTTON
  #ifndef INCLUDE_TIMER
    #define INCLUDE_TIMER
  #endif
#endif

#ifdef INCLUDE_FILEIO
  #ifndef INCLUDE_SCI
    #define INCLUDE_SCI
  #endif
#endif

#ifdef INCLUDE_TIME_OF_DAY
    #ifndef INCLUDE_TIMER
        #define INCLUDE_TIMER
    #endif
#endif

#ifdef INCLUDE_LCD
  #ifndef INCLUDE_PCS
    #define INCLUDE_PCS
  #endif
  #ifndef INCLUDE_QUAD_TIMER
    #define INCLUDE_QUAD_TIMER
  #endif
#endif

#ifdef INCLUDE_KEYPAD
  #ifndef INCLUDE_PCS
    #define INCLUDE_PCS
  #endif
  #ifndef INCLUDE_QUAD_TIMER
    #define INCLUDE_QUAD_TIMER
  #endif
#endif

#ifdef INCLUDE_TIMER
  #ifndef INCLUDE_QUAD_TIMER
    #define INCLUDE_QUAD_TIMER
  #endif
#endif

#ifdef INCLUDE_CODEC
  #ifndef INCLUDE_ESSI
    #define INCLUDE_ESSI
  #endif

  #ifndef INCLUDE_GPIO
      #define INCLUDE_GPIO
  #endif
#endif

#ifdef INCLUDE_CODECDMA
  #ifndef INCLUDE_ESSIDMA
    #define INCLUDE_ESSIDMA
  #endif

  #ifndef INCLUDE_GPIO
      #define INCLUDE_GPIO
  #endif
#endif

#ifdef INCLUDE_ESSIDMA
    #ifndef INCLUDE_DMA
        #define INCLUDE_DMA
    #endif
#endif

#ifdef INCLUDE_MULTICODEC
  #ifndef INCLUDE_GPIO
      #define INCLUDE_GPIO
  #endif
#endif

#ifdef INCLUDE_TDC1
  #ifndef INCLUDE_GPIO
      #define INCLUDE_GPIO
  #endif
#endif

#ifdef INCLUDE_IDC
  #ifndef INCLUDE_GPIO
      #define INCLUDE_GPIO
  #endif
  #ifndef INCLUDE_PCS
      #define INCLUDE_PCS
  #endif
#endif

#ifdef INCLUDE_SERIAL_DATAFLASH
    #ifndef INCLUDE_SPI
        #define INCLUDE_SPI
    #endif

    #ifndef INCLUDE_GPIO
        #define INCLUDE_GPIO
    #endif
#endif

#ifdef INCLUDE_IO

  #ifndef INCLUDE_IO_BUTTON
    #define INCLUDE_IO_BUTTON
  #endif

  #ifndef INCLUDE_IO_CODEC
    #define INCLUDE_IO_CODEC
  #endif

  #ifndef INCLUDE_IO_MULTICODEC
    #define INCLUDE_IO_MULTICODEC
  #endif

  #ifndef INCLUDE_IO_CODECDMA
    #define INCLUDE_IO_CODECDMA
  #endif

  #ifndef INCLUDE_IO_DMA
    #define INCLUDE_IO_DMA
  #endif

  #ifndef INCLUDE_IO_ESSI
    #define INCLUDE_IO_ESSI
  #endif

  #ifndef INCLUDE_IO_ESSIDMA
    #define INCLUDE_IO_ESSIDMA
  #endif

  #ifndef INCLUDE_IO_GPIO
    #define INCLUDE_IO_GPIO
  #endif

  #ifndef INCLUDE_IO_HI
    #define INCLUDE_IO_HI
  #endif

  #ifndef INCLUDE_IO_LED
    #define INCLUDE_IO_LED
  #endif

  #ifndef INCLUDE_IO_QUAD_TIMER
    #define INCLUDE_IO_QUAD_TIMER
  #endif

  #ifndef INCLUDE_IO_SCI
    #define INCLUDE_IO_SCI
  #endif

  #ifndef INCLUDE_IO_SERIAL_DATAFLASH
    #define INCLUDE_IO_SERIAL_DATAFLASH
  #endif

  #ifndef INCLUDE_IO_SPI
    #define INCLUDE_IO_SPI
  #endif

  #ifndef INCLUDE_IO_TDC1
    #define INCLUDE_IO_TDC1
  #endif

  #ifndef INCLUDE_IO_LCD
    #define INCLUDE_IO_LCD
  #endif

  #ifndef INCLUDE_IO_KEYPAD
    #define INCLUDE_IO_KEYPAD
  #endif

  #ifndef INCLUDE_IO_IDC
    #define INCLUDE_IO_IDC
  #endif
#endif

#if defined(INCLUDE_IO)               \
  || defined(INCLUDE_IO_BUTTON)     \
  || defined(INCLUDE_IO_CODEC)      \
  || defined(INCLUDE_IO_CODECDMA)      \
  || defined(INCLUDE_IO_MULTICODEC) \
  || defined(INCLUDE_IO_DMA)        \
  || defined(INCLUDE_IO_ESSI)       \
  || defined(INCLUDE_IO_ESSIDMA)       \
  || defined(INCLUDE_IO_GPIO)       \
  || defined(INCLUDE_IO_LED)        \
  || defined(INCLUDE_IO_QUAD_TIMER) \
  || defined(INCLUDE_IO_SCI)        \
  || defined(INCLUDE_IO_SERIAL_DATAFLASH)     \
  || defined(INCLUDE_IO_SPI)        \
  || defined(INCLUDE_IO_TDC1)       \
  || defined(INCLUDE_IO_LCD)        \
  || defined(INCLUDE_IO_KEYPAD)     \
  || defined(INCLUDE_IO_IDC)

    #ifndef INCLUDE_IO_IO
      #define INCLUDE_IO_IO
    #endif
#endif

#endif
