;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;********************************************************************
    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemReadP32

; Word32 memReadP32  (Word32 *pX);
; #pragma interrupt  /* Can be used in a pragma interrupt ISR */
;
;    Register usage:
;       R2 - pX
;       A  - return value
;       X0 - temp
;
      ORG  P:



FmemReadP32:
       adda   #2,SP
       move.w X0,x:(SP)
       move.w A0,X0
      move.w P:(R2)+,X0
      move.w P:(R2)+,A
      move.w X0,A0
      suba   #2,SP
      rts

      ENDSEC
      END
