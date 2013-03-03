#include "myscpi/myscpi.h"
#include "common.h"		
#include "led.h"  	
#include "io.h"
#include "adc.h"
#include "nf/nfv2.h"

extern uint16_t 	serialNumber;
extern NF_STRUCT_ComBuf 	NFComBuf;

uint8_t MYSCPI_Interpreter(volatile uint8_t *rxBuf, volatile uint8_t *rxPt, volatile uint8_t *txBuf, volatile uint8_t *txCnt)
{
	// Do not modify this section
	//	||	||	||	||	||	||	||
	//	\/	\/	\/	\/	\/	\/	\/
	uint8_t grNameLen = 0;
	uint8_t memNameLen = 0;
	uint8_t ret = 0;

	*txCnt = 0;
	
	// Wrong start byte
	if((*rxPt) == 0 && rxBuf[0]!=':' && rxBuf[0]!='*'){
		return 0;
	}
	// Start byte or data received
	else if(rxBuf[*rxPt]!='\r' && rxBuf[*rxPt]!='\n'){
		// Pointer increment, Buffer size overflow check
		if(++(*rxPt) >= RXBUFSZ){
			(*rxPt) = 0;
		}
		return 0;
	}
	// End byte '\r' or '\n' received.
	else{
		// Increment rxPt to avoid rxBuf modification during interpretation
		(*rxPt)++;
	}
	//	/\	/\	/\	/\	/\	/\	/\
	//	||	||	||	||	||	||	||
	// Do not modify this section

	
	
	// Here you build your own command parser
	//	||	||	||	||	||	||	||
	//	\/	\/	\/	\/	\/	\/	\/

	_IF_MEMBER_THEN("*IDN?")
	//	_PRINT_RESPONSE("%s, %s %s \r\n", MODULE_NAME, __DATE__, __TIME__);
		_PRINT_STR_RESPONSE(MODULE_NAME)
		
	//	/\	/\	/\	/\	/\	/\	/\
	//	||	||	||	||	||	||	||
	// Here you build your own command parser
	
	
	// Do not modify this section
	//	||	||	||	||	||	||	||
	//	\/	\/	\/	\/	\/	\/	\/
	ret = *rxPt;
	// Reset rxPt for next incoming command
	*rxPt = 0;
	// Return length of received command
	return ret;
}

