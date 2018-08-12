;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;********************************************************************
    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemReadP16

; Word16 memReadP16  (Word16 *pX);
; #pragma interrupt  /* Can be used in a pragma interrupt ISR */
;
;    Register usage:
;       R2 - pX
;       Y0 - return value
;
      ORG  P:
FmemReadP16:

      move.w P:(R2)+,Y0
      rts

      ENDSEC
      END
