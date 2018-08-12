;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;
;********************************************************************
;
; File Name:    memcopyptox.asm
;
; Description:  Contains code for copying P memory to X memory.
;
; Modules
;    Included:  FmemCopyPtoP
;
;********************************************************************

    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemCopyPtoX

;********************************************************************
;
; void * memCopyPtoX ( void *dest, const void *src, size_t count );
; #pragma interrupt   /* Can be used in a pragma interrupt ISR */
;
;    Register usage:
;       R2 - dest
;       R3 - src
;       Y0 - count/temp
;
;********************************************************************

      ORG  P:
FmemCopyPtoX:

      brset   #1,R2,OddBytes    ; Optimize move for words
      nop
      nop
      brset   #1,R3,OddBytes
      nop
      nop
      brset   #1,Y0,OddBytes
      nop

;
; Move words between word addresses
;
      lsra    R2            ; convert to word address
      lsr.w   Y0            ; convert to word count
      lsra    R3            ; convert to word address

      if CODEWARRIOR_WORKAROUND==1
      do      Y0,>>EndDoEven ; move all words
      else
      do      Y0,EndDoEven  ; move all words
      endif

      move.w    P:(R3)+,Y0
      move.w    Y0,X:(R2)+
      nop
      nop
EndDoEven:
      asla    R2            ; convert to byte address
      ; R2 - Contains *dest return value
      rts

;
; Move bytes or words between possible non-word addresses
;
OddBytes:
      adda    #2,SP
      move.l  R4,x:(SP)+
      move.w  X0,x:(SP)    ; push X0

      move.l  #1,R4        ; R4 = constant 1

      move.w  R3,X0
      lsra    R3
      andc    #$0001,X0

      if CODEWARRIOR_WORKAROUND==1
      do      Y0,>>EndDo
      else
      do      Y0,EndDo
      endif

      move.w  P:(R3)+,Y0
      tst.w   X0
      beq     SkipShift
      adda    R4,R3
      lsrr.w  #8,Y0
SkipShift:
      suba    R4,R3
      eorc    #1,X0
      move.bp Y0,X:(R2)+
      nop
EndDo:
      move.l  x:(SP)-,R4
      move.w  x:(SP),X0
      suba    #2,SP

      ; R2 - Contains *dest return value
      rts

      ENDSEC
      END
