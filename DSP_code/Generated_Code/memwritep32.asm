;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;********************************************************************
    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemWriteP32

; void memWriteP32  (Word32 x, Word32 *pX);
; #pragma interrupt  /* Can be used in a pragma interrupt ISR */
; NB: R2 willl be change
;    Register usage:
;       R2   - pX
;       A10  - x
;       X0   - temp
;
      ORG  P:

FmemWriteP32:
      adda   #2,SP
      move.w X0,x:(SP)
      move.w A0,X0
      move.w X0,P:(R2)+
      move.w A1,P:(R2)+
      move.w x:(SP),X0
      suba   #2,SP
      rts

      ENDSEC
      END
