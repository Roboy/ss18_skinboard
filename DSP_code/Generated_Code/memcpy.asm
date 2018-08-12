;********************************************************************
;
; (c) Freescale Semiconductor
; 2004 All Rights Reserved
;
;
;********************************************************************
;
; File Name:    memcpy.asm
;
; Description:  Contains code for copying X memory to X memory.
;
; Modules
;    Included:  FmemMemcpy
;
;********************************************************************

    SECTION rtlib

    include "portasm.h"

    GLOBAL  FmemMemcpy

;********************************************************************
;
; void *memcpy( void *dest, const void *src, size_t count );
; #pragma interrupt /* Can be called from a pragma interrupt ISR */
;
;    Register usage:
;       R2 - dest
;       R3 - src
;       Y0 - count/temp
;
;********************************************************************

      ORG  P:
FmemMemcpy:
                        tst.w   Y0
      beq     EndDo
      nop
      nop
      if CODEWARRIOR_WORKAROUND==1
      do      Y0,>>EndDo
      else
      do      Y0,EndDo
      endif

      move.bp X:(R3)+,Y0
      move.bp Y0,X:(R2)+
EndDo:
      ; R2 - Contains *dest return value
      rts

      ENDSEC
      END
