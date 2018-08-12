;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;********************************************************************
                SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemMemset

; void  * memMemset (void *dest, int c, size_t count);
; #pragma interrupt  /* Can be called from a pragma interrupt ISR */
;
;    Register usage:
;       R2 - dest, byte address pointer
;       Y0 - c
;       Y1 - count
;
      ORG  P:
FmemMemset:

      adda    #2,SP
      move.w  X0,x:(SP)   ; Save X0 to restore later

      tst.w   Y1          ; Q: count > 0 ?
      beq     EndMemset
      nop
      nop

      brclr   #$0001,R2,AddrEven
      nop
      nop
      move.bp Y0,x:(R2)+  ; move one byte
      dec.w   Y1
AddrEven:
      asra    R2          ; create word address
      move.w  Y0,X0       ; create 16-bit data value
      asll.w  #8,X0
      andc    #$00FF,Y0
      or.w    X0,Y0
      move.w  Y1,X0       ; create word count
      lsr.w   X0
      rep     X0          ; move words
      move.w  Y0,X:(R2)+

      asla    R2,R2       ; restore byte address

      brclr   #$0001,Y1,EndMemset  ; Q: Odd byte?
      move.bp Y0,x:(R2)+  ;
EndMemset:
      ; R2 - Contains *dest return value
      move.w  x:(SP),X0  ; Restore X0 register
      suba    #2,SP
      rts

      ENDSEC
      END

