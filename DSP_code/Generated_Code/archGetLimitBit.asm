;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;********************************************************************
  SECTION rtlib

  include "portasm.h"

  ORG P:


;/*****************************************************************************/
; asm Flag archGetLimitBit()
  global  FarchGetLimitBit

FarchGetLimitBit:
   clr.w Y0
   brclr #$40,SR,LClear
   nop
   move.w  #1,Y0
LClear:
   rts

  ENDSEC
  END
