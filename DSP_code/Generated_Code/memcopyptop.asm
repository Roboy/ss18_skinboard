;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;
;********************************************************************
;
; File Name:    memcopyptop.asm
;
; Description:  Contains code for copying P memory to P memory.
;
; Modules
;    Included:  FmemCopyPtoP
;
;********************************************************************

    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemCopyPtoP

;********************************************************************
;
; void * memCopyPtoP ( void *dest, const void *src, size_t count );
; #pragma interrupt  /* Can be used in a pragma interrupt ISR */
;
;    Register usage:
;       R2 - dest
;       R3 - src
;       Y0 - count/temp
;
; Note:  The current implementation only supports setting P memory
;        on word boundaries.
;
;********************************************************************

      ORG  P:
FmemCopyPtoP:

  if ASSERT_ON_INVALID_PARAMETER==1

      brset   #$0001,R2,ByteAlignment
      brset   #$0001,R3,ByteAlignment
                        brclr   #$0001,Y0,ParamsOK
ByteAlignment:
      debughlt    ;  Current implementation does not support byte alignment
ParamsOK:

  endif

      asra    R2
      asra    R3
      asr     Y0

      tst.w   Y0
      beq     EndDo

      if CODEWARRIOR_WORKAROUND==1
      do      Y0,>>EndDo
      else
      do      Y0,EndDo
      endif

      move.w  P:(R3)+,Y0
      move.w  Y0,P:(R2)+
EndDo:
      asla    R2
      ; R2 - Contains *dest return value
      rts

      ENDSEC
      END
