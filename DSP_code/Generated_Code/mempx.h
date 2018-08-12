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

/* File: mempx.h */

#ifndef __MEMPX_H
#define __MEMPX_H

#include "port.h"
#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************
* Types of Memory
*******************************************************/

typedef enum
{
  XData,
  PData
} mem_eMemoryType;


/*******************************************************
* Routines for P <-> X Memory Access
*
* - All routines can be used in pragma interrupt ISRs
*
*******************************************************/

#define memset   memMemset
#define memSetP  memMemsetP
#define memcpy   memMemcpy

UWord16 memReadP16 (UWord16 *pSrc);
UWord32 memReadP32 (UWord32 *pSrc);

void   memWriteP16 (UWord16 Data, Word16 *pDest);
void   memWriteP32 (UWord32 Data, Word32 *pDest);

void * memCopyXtoP (void *pDest, const void *pSrc, ssize_t Count);
void * memCopyPtoX (void *pDest, const void *pSrc, ssize_t Count);
void * memCopyPtoP (void *pDest, const void *pSrc, ssize_t Count);

void * memMemset   (void *dest, int c, ssize_t count);
void * memMemcpy   (void *dest, const void *src, ssize_t count);

void * memMemsetP  (void *dest, int c, ssize_t count);

/*******************************************************/
#ifdef __cplusplus
}
#endif

#endif
