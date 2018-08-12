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

/* File: arch.h */

#ifndef __ARCH_H
#define __ARCH_H

#include "port.h"

#ifdef __cplusplus
extern "C" {
#endif

/*******************************************************
* Architecture Dependent Routines
*******************************************************/
/* Get limit bit */
EXPORT Flag archGetLimitBit (void);

/* void archResetLimitBit (void); */
#define archResetLimitBit() asm(bfclr  #0x40,SR)

/* void archSetNoSat (void); */
#define archSetNoSat() asm(bfclr #0x10,OMR)

/* void archSetSat32 (void); */
#define archSetSat32() asm(bfset #0x10,OMR)

/* Get, then set saturation mode */
EXPORT bool archGetSetSaturationMode (bool bSatMode);

/* void archSet2CompRound (void); */
#define archSet2CompRound() asm(bfset #0x20,OMR)

/* void archSetConvRound (void); */
#define archSetConvRound() asm(bfclr #0x20,OMR)

/* void archStop (void); */
#define archStop() asm(stop)

/* void archTrap (void); */
#define archTrap() asm(swi)

/* void archWait (void); */
#define archWait() asm(wait)

/* void archEnableInt (void); */
#define archEnableInt() asm(bfclr #0x0300,SR)

/* void archDisableInt (void); */
#define archDisableInt() asm(bfset #0x0300,SR)


#define archMemRead(Local, Remote, Bytes) *(Local) = *(Remote)
#define archMemWrite(Remote, Local, Bytes) *(Remote) = *(Local)

#define archCoreRegisterBitSet(Mask, Reg)     asm(bfset   Mask,Reg)
#define archCoreRegisterBitClear(Mask, Reg)    asm(bfclr   Mask,Reg)
#define archCoreRegisterBitChange(Mask, Reg)   asm(bfchg   Mask,Reg)
#define archCoreRegisterBitTestHigh(Mask, Reg) asm(bftsth  Mask,Reg)
#define archCoreRegisterBitTestLow(Mask, Reg)  asm(bftstl  Mask,Reg)

#define archMemBitSet(Mask, Addr)          asm(bfset   Mask,Addr)
#define archMemBitClear(Mask, Addr)         asm(bfclr   Mask,Addr)
#define archMemBitChange(Mask, Addr)        asm(bfchg   Mask,Addr)
#define archMemBitTestHigh(Mask, Addr)       asm(bftsth  Mask,Addr)
#define archMemBitTestLow(Mask, Addr)        asm(bftstl  Mask,Addr)

#ifdef __cplusplus
}
#endif

#endif
