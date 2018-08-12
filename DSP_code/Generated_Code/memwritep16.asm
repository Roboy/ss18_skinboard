;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;********************************************************************
    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemWriteP16

; void memWriteP16  (Word16 x, Word16 *pX);
; #pragma interrupt  /* Can be used in a pragma interrupt ISR */
;
;    Register usage:
;       R2 - pX
;       Y0 - x
;
      ORG  P:
FmemWriteP16:

                        move.w Y0,P:(R2)+
      rts

      ENDSEC
      END
