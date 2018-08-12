/** ###################################################################
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
**
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/

/* File: port.h */

#include "PE_Types.h"

#ifndef __PORT_H
#define __PORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "PE_Types.h"
#include "IO_Map.h"

/*******************************************************
* Target designation
*******************************************************/

/* MetroWerks defines __m56800E__ */


/*******************************************************
* C Constructs
*******************************************************/

#define EXPORT extern
#define ITU_INTRINSICS


/*******************************************************
* Basic Types
*******************************************************/

typedef struct {
   Frac16     real;
   Frac16     imag;
} CFrac16;

typedef struct {
   Frac32     real;
   Frac32     imag;
} CFrac32;

/* Useful definitions */

/* Convert int/float to Frac16; constant x generates compile time constant */
#define FRAC16(x) ((Frac16)((x) < 1 ? ((x) >= -1 ? ((Frac16)((x)*0x8000)) : ((Frac16)0x8000)) : ((Frac16)0x7FFF)))
/* Convert int/float to Frac32; constant x generates compile time constant */
#define FRAC32(x) ((Frac32)((x) < 1 ? ((x) >= -1 ? ((Frac32)((x)*0x80000000)) : ((Frac32)0x80000000)) : ((Frac32)0x7FFFFFFF)))

/* Miscellaneous types */
typedef int            Flag;

typedef int            Result;



/*******************************************************
* Conditional assembly
*******************************************************/

/*
  PORT_ASSERT_ON_INVALID_PARAMETER conditionally compiles
  code to check the validity of function parameters
*/
#define PORT_ASSERT_ON_INVALID_PARAMETER

/*
   These defines permit the same C source code to be
   used for Large and Small Memory Models
*/
/*lint -save  -esym(960,19.6) Disable MISRA rule (19.6) checking. Constant existence switches between ASM and C implementation. */
#undef PORT_LARGE_MEMORY_MODEL
/*lint -restore  +esym(960,19.6) Enable MISRA rule (19.6) checking. */


/*******************************************************
* Constants
*******************************************************/

/* Function Result Values */
#define PASS           0
#define FAIL           -1

#ifndef COMPILER_HAS_BOOL
#define true           1
#define false          0
#endif


/*******************************************************
* Implementation Limits
*******************************************************/

#define PORT_MAX_VECTOR_LEN  65535

#include "types.h"
#include "arch.h"

#ifdef __cplusplus
}
#endif

#endif

