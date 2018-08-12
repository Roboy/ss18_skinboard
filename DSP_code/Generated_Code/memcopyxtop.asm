;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;
;********************************************************************
;
; File Name:    memcopyxtop.asm
;
; Description:  Contains code for copying Xmemory to P memory.
;
; Modules
;    Included:  FmemCopyXtoP
;
;********************************************************************

    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemCopyXtoP

;********************************************************************
;
; void * memCopyXtoP   ( void *dest, const void *src, size_t count );
; #pragma interrupt  /* Can be used in a pragma interrupt ISR */
;
;    Register usage:
;       R2 - dest
;       R3 - src
;       Y0 - count/temp
;
;********************************************************************

      ORG  P:
FmemCopyXtoP:

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

      move.w  X:(R3)+,Y0
      move.w  Y0,P:(R2)+
      nop
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
      adda    #2,SP         ; save registers
      move.l  R4,x:(SP)+    ; push R4
      move.w  X0,x:(SP-1)   ; push X0
      move.w  Y1,x:(SP)     ; push Y1

      move.l  #1,R4         ; R4 = constant 1
      move.w  R2,X0
      lsra    R2
      andc    #$0001,X0

      if CODEWARRIOR_WORKAROUND==1
      do      Y0,>>EndDo
      else
      do      Y0,EndDo
      endif

      move.bp X:(R3)+,Y1

      move.w  P:(R2)+,Y0
      tst.w   X0
      beq     SkipShift
      asll.w  #8,Y1
      andc    #$FF,Y0
      suba    R4,R2
      or.w    Y1,Y0
      move.w  Y0,P:(R2)+
      bra     SwitchBytes
SkipShift:
      andc    #$FF00,Y0
      andc    #$FF,Y1
      suba    R4,R2
      or.w    Y1,Y0
      move.w  Y0,P:(R2)+

      ; These three NOPs are required on VIPER
      ; but not necessary in Wedge
      nop
      nop
      nop

      suba    R4,R2
SwitchBytes:
      eorc    #1,X0

EndDo:
      move.w  X0,R3
      adda.l  R2,R3
      tfra    R3,R2

      move.w  x:(SP-1),X0  ; restore saved registers
      move.w  X:(SP),Y1
      suba    #2,SP
      move.l  x:(SP)-,R4

      ; R2 - Contains *dest return value
      rts

      ENDSEC
      END
