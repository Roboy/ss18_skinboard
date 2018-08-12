;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;********************************************************************
    SECTION rtlib

    include "portasm.h"


    ORG  P:

;/*****************************************************************************/
; asm bool archGetSetSaturationMode (bool saturationMode)
    global  FarchGetSetSaturationMode

FarchGetSetSaturationMode:

    clr.w  X0
    brclr  #$10,OMR,SClear
    move.w #1,X0
SClear:

  cmp.w  #0,Y0
  beq    SatOff
  bfset  #$10,OMR
  move.w X0,Y0
  nop
  rts
SatOff:
  bfclr  #$10,OMR
  move.w X0,Y0
  nop
  rts

  ENDSEC
  END
