;**********************************************************************
;   This file is a basic code template for object module code         *
;   generation on the PICmicro PIC16C924. This file contains the      *
;   basic code building blocks to build upon.  As a project minimum   *
;   the 16c923.lkr file will also be required for this file to        *
;   correctly build. The .lkr files are located in the MPLAB          *  
;   directory.                                                        *
;                                                                     *
;   If interrupts are not used all code presented between the         *
;   code section "INT_VECTOR and code section "MAIN" can be removed.  *
;   In addition the variable assignments for 'w_temp' and             *
;   'status_temp' can be removed.                                     *                                                       *                         
;                                                                     *
;   Refer to the MPASM User's Guide for additional information on     *
;   features of the assembler and linker (Document DS33014F).         *
;                                                                     *
;   Refer to the respective PICmicro data sheet for additional        *
;   information on the instruction set.                               *
;                                                                     *
;   Template file built using MPLAB V3.99.18 with MPASM V2.15.18 and  *
;   MPLINK 1.10.11 as the language tools.                             *
;                                                                     *
;**********************************************************************
;                                                                     *
;    Filename:	    xxx.asm                                           *
;    Date:                                                            *
;    File Version:                                                    *
;                                                                     *
;    Author:                                                          *
;    Company:                                                         *
;                                                                     * 
;                                                                     *
;**********************************************************************
;                                                                     *
;    Files required:                                                  *
;                                                                     *
;                                                                     *
;                                                                     *
;**********************************************************************
;                                                                     *
;    Notes:                                                           *
;                                                                     *
;                                                                     *
;                                                                     *
;                                                                     *
;**********************************************************************


	list      p=16c924            ; list directive to define processor
	#include <p16c924.inc>        ; processor specific variable definitions
	
	__CONFIG   _CP_OFF & _WDT_ON & _PWRTE_ON & _RC_OSC

; '__CONFIG' directive is used to embed configuration data within .asm file.
; The labels following the directive are located in the respective .inc file.
; See respective data sheet for additional information on configuration word.






;***** VARIABLE DEFINITIONS (examples)

; example of using Shared Uninitialized Data Section
INT_VAR       UDATA_SHR   
w_temp        RES     1           ; variable used for context saving 
status_temp   RES     1           ; variable used for context saving


; example of using Uninitialized Data Section
TEMP_VAR      UDATA      0x20     ; explicit address specified is not required
temp_count    RES     1           ; temporary variable (example)


; example of using Overlayed Uninitialized Data Section
; in this example both variables are assigned the same GPR location by linker
G_DATA        UDATA_OVR           ; explicit address can be specified
flag          RES     2           ; temporary variable (shared locations - G_DATA)

G_DATA        UDATA_OVR   
count         RES     2           ; temporary variable (shared locations - G_DATA)






;**********************************************************************
RESET_VECTOR  CODE    0x000       ; processor reset vector
        movlw  high  start        ; load upper byte of 'start' label
        movwf  PCLATH             ; initialize PCLATH
        goto   start              ; go to beginning of program


INT_VECTOR   CODE    0x004        ; interrupt vector location
		movwf   w_temp            ; save off current W register contents
		movf	STATUS,w          ; move status register into W register
		movwf	status_temp       ; save off contents of STATUS register


; isr code can go here or be located as a call subroutine elsewhere


		movf    status_temp,w     ; retrieve copy of STATUS register
		movwf	STATUS            ; restore pre-isr STATUS register contents
		swapf   w_temp,f
		swapf   w_temp,w          ; restore pre-isr W register contents
		retfie                    ; return from interrupt


MAIN    CODE
start

        nop                       ; code starts here (example)
        banksel  flag             ; example
        clrf   flag               ; example

; remaining code goes here





		END                       ; directive 'end of program'

