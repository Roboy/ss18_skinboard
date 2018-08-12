;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;
;********************************************************************
;
; File Name:    memsetp.asm
;
; Description:  Contains code writing to P memory.
;
; Modules
;    Included:  FmemMemsetP
;
;********************************************************************

    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemMemsetP

;********************************************************************
;
; void  * memMemsetP (void *dest, int c, size_t count);
; #pragma interrupt  /* Can be used in a pragma interrupt ISR */
;
;    Register usage:
;       R2 - dest
;       Y0 - c
;       Y1 - count
;
; Note:  The current implementation only supports setting P memory
;        on word boundaries.
;
;********************************************************************

      ORG  P:
FmemMemsetP:

  if ASSERT_ON_INVALID_PARAMETER==1

      brset   #$0001,R2,ByteAlignment
      brclr   #$0001,Y1,ParamsOK
ByteAlignment:
      debughlt    ;  Current implementation does not support byte alignment
ParamsOK:

  endif

      asra    R2
      lsr.w   Y1
      tst.w   Y1
      beq     EndMemsetP

      if CODEWARRIOR_WORKAROUND==1
      do      Y1,>>EndMemsetP
      else
      do      Y1,EndMemsetP
      endif

      move.w  Y0,P:(R2)+
EndMemsetP:
      asla    R2
      ; R2 - Contains *dest return value
      rts

      ENDSEC
      END
