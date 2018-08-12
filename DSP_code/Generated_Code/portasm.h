;/** ###################################################################
;**
;**     (c) Freescale Semiconductor, Inc.
;**     2004 All Rights Reserved
;**
;**
;**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
;**     All Rights Reserved.
;**     
;**     Redistribution and use in source and binary forms, with or without modification,
;**     are permitted provided that the following conditions are met:
;**     
;**     o Redistributions of source code must retain the above copyright notice, this list
;**       of conditions and the following disclaimer.
;**     
;**     o Redistributions in binary form must reproduce the above copyright notice, this
;**       list of conditions and the following disclaimer in the documentation and/or
;**       other materials provided with the distribution.
;**     
;**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
;**       contributors may be used to endorse or promote products derived from this
;**       software without specific prior written permission.
;**     
;**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
;**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
;**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
;**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
;**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
;**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
;**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
;**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
;**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;**     
;**     http: www.freescale.com
;**     mail: support@freescale.com
;** ###################################################################*/

; File: port.asm

;/*******************************************************
;* Conditional assembly
;*******************************************************/

;/* Change the following define to '0' to eliminate asserts */
  define  ASSERT_ON_INVALID_PARAMETER   '1'

;/* For V1 compatibility */
   define debug    'debughlt'

;/*
;   These defines permit the same ASM source code to be
;   used for Large and Small Memory Models
;*/
    define PORT_LARGE_MEMORY_MODEL '1'

    define CODEWARRIOR_WORKAROUND '0'

;   IF @DEF(F__CW_M56800E_LMM)
;   Small Memory Model defines

   define LoadRx   'moveu.w'
   define StoreRx  'move.w'
   define TestRx   'tst.w'

   define PTR_SIZE  '1'

;  endif

;/*******************************************************
;* Constants
;*******************************************************/

;/* Function Result Values */
PASS      equ     0
FAIL      equ     -1

true      equ     1
false     equ     0

;/*******************************************************
;* Implementation Limits
;*******************************************************/

PORT_MAX_VECTOR_LEN  equ 65535

