//!
//! Modulo para controle e configura��o da porta serial
//! Autor : Rafael Dias Menezes
//! Data  : Ago/2009
//!

#ifndef __SERIAL__
#define __SERIAL__

#include "defs.h"

/**
 *  \brief define alguns tipos utilizados na configura��o da paridade
 */
enum COM_Parity{
    PR_NONE = 0,
    PR_ODD, 
    PR_EVEN 
};

/**
 *  \brief define os baudrates poss�ves
 */
enum COM_BaudRate{
    BR_300 = 0,
    BR_1200,
    BR_2400,
    BR_4800,
    BR_9600,
    BR_19200,
    BR_38400,
    BR_57600,
    BR_115200
};

/**
 *  \brief define os stopbits poss�veis.
 */
enum COM_StopBits{
    ST_1 = 0, 
    ST_2
};	

//!
//! pointer function to a ISR routine.
//!
typedef void SERIALCOMFUNC(void);

/** 
 *  \brief  Inicializa a porta 
 *          Pr� condi��o: verificar a configura��o dos ports de entrada/sa�da e 
 *          controle no arquivo rs485.c
 *  \param  port UART que dever� ser utilizada para interface serial
 *  \param  baudRate    baudRate a ser utilizado
 *  \param  stopBits    stop bits utilizados para a interface serial
 *  \param  par         paridade
 *  \param  isrFunc     Ponteiro para fun��o que realizar� o tratamento dos dados recebidos pela serial.
 */
void InitSerial( BYTE port, BYTE baudRate, BYTE stopBits, BYTE par, SERIALCOMFUNC*  func );

/**
 *  \brief Retorna o baudrate da interface rs485
 *  \return Baudrate atual
 */
BYTE GetSerialBaudRate( void );

/**
 *  \brief retorna o numero de stop bits da interface rs485
 *  \return stopbits atual
 */
BYTE GetSerialStopBits( void );

/**
 *  \brief retorna a paridade configurada para a inteface rs485
 *  \return paridade atual
 */
BYTE GetSerialParidade( void );

/**
 *  \brief realiza a leitura do �ltimo caracter recebido pela interface serial
 *  \return ultimo caracter recebido.
 */
BYTE SerialGetchar( void );

/**
 *  \brief envia um caracter pela intercafe serial
 *  \param c dado a ser enviado
 */
void SerialPutc( BYTE c );

/**
 *  \brief desliga a recep��o de dados pela interface serial
 */
void ReceiveOff( void );


/**
 * \brief habilita a recep��o de dados pela interface serial, com a limpeza do buffer de recep��o
 */
void ReceiveOn( void );

/**
 *  \brief converte do tipo enum COM_BaudRate para DWORD
 *  \param c baudrate a ser convertido
 *  \return DWORD representativo do baudrate passado como parametro
 *  se o baurdare for invalido, retorna 9600
 */
DWORD Baud2Int( enum COM_BaudRate c );

/**
 *  \brief  converte de DWORD para o tipo enum COM_BaudRate
 *  \param  baud baudrate a ser convertido
 *  \return baud convertido para o tipo enum COM_BaudRate. Se o baudrate passado for invalido, retorna BR_9600
 */
enum COM_BaudRate Int2Baud( DWORD baud );

#endif  //~ __SERIAL__
