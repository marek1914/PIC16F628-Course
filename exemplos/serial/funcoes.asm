;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;   
;   Biblioteca de funcoes gerais
;   @Author  :  Rafael Dias Menezes
;   @Data    :  Jul/2009
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    
#include <defs.inc>
#include <macros.inc>


    EXTERN	DIV_8
    EXTERN	MUL_8
    EXTERN	B_REG

    
    UDATA
TBL_PTR RES 2   ;  vari�vel para armazenamento de tabela que dever� ser lida da mem�ria de programa
W_TEMP	RES	1

    GLOBAL  TBL_PTR, TBL_Read, Int2BCD, BCD2Int
     
    CODE
   
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;     
;   TBL_Read
;   \brief  Realiza a leitura de um valor da tabela. Este valor � indexado por (TBL_PTR+WREG)
;           O numero m�ximo de bytes a serem lidos e considerados da tabela s�o 256
;   \return WREG
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    
TBL_Read:
    ; NOTA : usando a nota��o litte endian
    BANKSEL TBL_PTR
    ADDWF   TBL_PTR+1,F     ; desloca o ponteiro
    BTFSC   STATUS,C
    INCF    TBL_PTR,F
    
    MOVF    TBL_PTR,W
    ANDLW   0x1F
    MOVWF   PCLATH     
    MOVF    TBL_PTR+1,W
    MOVWF   PCL
    
    ; neste ponto o PC � alterado para (TBL_PTR+WREG) e l� deve ter um RETLW

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    

    
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;     
;   Int2BCD
;   \brief  Converte um n�mero inteiro em BCD
;   \param  WREG-> valor a converter. 0-99
;   \return WREG-> valor convertido
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    
Int2BCD:
    ; a conta a ser realizada deve ser algo da forma:
    ;   W_REG   =   W_REG/10
    ;   B_REG   =   W_REG mod 10   
    ;   RESULT  =   W_REG * 16 | B_REG
    ;
	BANKSEL	W_TEMP
	movwf	W_TEMP
	
	sublw   99          ; verifica se � um valor v�lido.
	btfss   STATUS,C
	retlw   -1
	
	BANKSEL	B_REG
	movlw	10
	movwf	B_REG
	
	BANKSEL	W_TEMP
	movf	W_TEMP,W
	CALL	DIV_8
	
	BANKSEL	W_TEMP
	movwf	W_TEMP
	RLNC	W_TEMP
	RLNC	W_TEMP
	RLNC	W_TEMP
	RLNC	W_TEMP
	movf	W_TEMP,W
	;bcf	STATUS,C	
	;rlf 	W_TEMP,F
	;bcf	STATUS,C	
	;rlf 	W_TEMP,F
	;bcf	STATUS,C	
	;rlf 	W_TEMP,F
	;bcf	STATUS,C	
	;rlf 	W_TEMP,W
	
	BANKSEL	B_REG
	IORWF	B_REG,W
	
	return;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;     
;   BCD2Int
;   \brief  Converte um n�mero BCD em inteiro
;	\param	WREG-> valor a converter. 0-99
;   \return WREG-> valor convertido
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;    
BCD2Int:
    BANKSEL W_TEMP
    movwf    W_TEMP
   
    BANKSEL B_REG
    movlw   10
    movwf   B_REG

    BANKSEL W_TEMP    
    swapf   W_TEMP,F
    movlw   0x0F
    andwf   W_TEMP,W
    swapf   W_TEMP,F
    
    CALL    MUL_8
    BANKSEL B_REG
    movwf   B_REG
    
    BANKSEL W_TEMP
    movlw   0x0F
    andwf   W_TEMP,W
    
    BANKSEL B_REG
    addwf   B_REG,W
       
    return;

    END