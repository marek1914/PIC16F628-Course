;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   
;   Biblioteca de macros
;   @Author  :  Rafael Dias Menezes
;   @Data    :  Jul/2009
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    #include <defs.inc>
	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	MACRO CJNE
;	\brief 	Compara e salta se o registro for diferente ao valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CFJNE	MACRO	REG, REG2, ENDER
        BANKSEL REG
        movf    REG,W
        BANKSEL REG2
        xorwf   REG2,W
		btfss	STATUS,Z
		goto	ENDER	
		ENDM	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	MACRO CJEQ
;	\brief 	Compara e salta se o registro for igual ao valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CFJEQ   MACRO	REG, REG2, ENDER
        BANKSEL REG
        movf    REG,W
        BANKSEL REG2
        xorwf   REG2,W
		btfsc	STATUS,Z
		goto	ENDER	
		ENDM	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	MACRO CJGT
;	\brief 	Compara e salta se o registro for maior do que o valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CFJGT	MACRO	REG, REG2, ENDER
        BANKSEL REG
        movf    REG,W
        BANKSEL REG2
        xorwf   REG2,W
		btfsc	STATUS,C
		goto	ENDER	
		ENDM	
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO CJLT
;	\brief 	Compara e salta se o registro for menor do que o valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CFJLT	MACRO	REG, REG2, ENDER
        BANKSEL REG
        movf    REG,W
        BANKSEL REG2
        xorwf   REG2,W
		btfss	STATUS,C
		goto    ENDER	
		ENDM
		
				
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	MACRO CJNE
;	\brief 	Compara e salta se o registro for diferente ao valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CJNE	MACRO	REG, VAL, ENDER
		movlw	VAL
		BANKSEL REG
		xorwf	REG,W
		btfsc	STATUS,Z
		goto	ENDER	
		ENDM	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	MACRO CJEQ
;	\brief 	Compara e salta se o registro for igual ao valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CJEQ    MACRO	REG, VAL, ENDER
		movlw	VAL
		BANKSEL REG
		xorwf	REG,W
		btfss	STATUS,Z
		goto	ENDER	
		ENDM	

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;	MACRO CJGT
;	\brief 	Compara e salta se o registro for maior do que o valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CJGT	MACRO	REG, VAL, ENDER
		movlw	VAL
		BANKSEL REG
		subwf	REG,W
		btfsc	STATUS,C
		goto	ENDER	
		ENDM	
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO CJLT
;	\brief 	Compara e salta se o registro for menor do que o valor 
;	\param	REG	registro a ser comparado
;	\param	VAL	valor a ser comparado	
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
CJLT	MACRO	REG, VAL, ENDER
		movlw		VAL
		BANKSEL REG
		subwf		REG,W
		btfss		STATUS,C
		goto		ENDER	
		ENDM	
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO JPWZ
;	\brief 	Salta se o acumulador for zero
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
JPWZ	MACRO   ENDER
		iorlw   0
		btfsc   STATUS,Z
		goto    ENDER
		ENDM
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO JPWNZ
;	\brief 	Salta se o acumulador for diferente de zero
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
JPWNZ	MACRO  ENDER
		iorlw		0
		btfss		STATUS,Z
		goto		ENDER
		ENDM
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;		
; MACRO JPWNZ
;	\brief 	Salta se o acumulador for igual ao valor
;	\param	VAL 	valor comparado
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
JPWEQ	MACRO	VAL, ENDER	
		xorlw		VAL
		btfsc		STATUS,Z
		goto		ENDER
		ENDM
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO INCW
;	\brief 	incrementa acumulador
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
INCW	MACRO	
		addlw	1
		ENDM
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO DECW
;	\brief 	decrementa acumulador
;	\param	ENDER endereco de salto
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
DECW	MACRO
		addlw	-1
		ENDM
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO RRNC
;	\brief 	rotaciona registro sem o carry
;	\param	REG regostro a ser rotacionado
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RRNC	MACRO REG
		bcf			STATUS, C
		rrf			REG, F
		ENDM

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO RLNC
;	\brief 	rotaciona registro sem o carry
;	\param	REG regostro a ser rotacionado
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
RLNC	MACRO REG
		bcf			STATUS, C
		rlf			REG, F
		ENDM
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO COMW
;	\brief 	complementa acumulador
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
COMW	MACRO 
		xorlw			0xFF
		ENDM
		
		
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO BCW
;	\brief 	apaga um bit do acumulador
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BCW	MACRO BIT
		IF (BIT==0) 
			andlw	b'11111110'
		ENDIF
		IF (BIT==1)
			andlw	b'11111101'
		ENDIF
		IF (BIT==2)
			andlw	b'11111011'
		ENDIF
		IF (BIT==3)
			andlw	b'11110111'
		ENDIF
		IF (BIT==4)
			andlw	b'11101111'
		ENDIF
		IF (BIT==5)
			andlw	b'11011111'
		ENDIF
		IF (BIT==6)
			andlw	b'10111111'
		ENDIF
		IF (BIT==7)
			andlw	b'01111111'
		ENDIF
		ENDM


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; MACRO BSW
;	\brief 	liga um bit do acumulador
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
BSW	MACRO BIT
		IF (BIT==0) 
			iorlw	1
		ENDIF
		IF (BIT==1)
			iorlw 2
		ENDIF
		IF (BIT==2)
			iorlw	4
		ENDIF
		IF (BIT==3)
			iorlw	8
		ENDIF
		IF (BIT==4)
			iorlw	16
		ENDIF
		IF (BIT==5)
			iorlw	32
		ENDIF
		IF (BIT==6)
			iorlw	64
		ENDIF
		IF (BIT==7)
			iorlw	128
		ENDIF
	ENDM

