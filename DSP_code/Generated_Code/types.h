/*****************************************************************************
*
* (c) Freescale Semiconductor
* 2004 All Rights Reserved
*
*
******************************************************************************
*
* File Name:         types.h
*
* Description:       Header file for defining common typedefs used by
*                    the SDK
*
* Modules Included:
*
*
*****************************************************************************/

#ifndef __TYPES_H
#define __TYPES_H

#include "port.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int clockid_t;
typedef unsigned int timer_t;
typedef unsigned int handle_t;
#ifndef _MSL_TIME_T_DEFINED
  typedef long             time_t;
  #define _MSL_TIME_T_DEFINED         /* avoid multiple def's of time_t */
#endif

typedef void (*types_tCallback)(void *param);
typedef void (*types_tErrorCallback)(UWord16 param);

typedef int types_tHandle;

#ifdef __cplusplus
}
#endif

#endif
