#include "myscpi_defines.h"
#include "myscpi.h"

#include "common.h"		
#include "led.h"  	
#include "motor.h"  
#include "eeprom.h"
#include "eebackup.h"
#include "io.h"
#include "adc.h"
#include "nfv2.h"

extern uint16_t 	serialNumber;
extern SERVO_St		Servo; 
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
		_PRINT_RESPONSE("%s\r\n", MODULE_NAME)
		
	else
	_IF_MEMBER_THEN(":SRN1!")
		EEPROM_Write(EEADDR_SRV0MIN, (u16) Servo.min[0]);
	else
	_IF_MEMBER_THEN(":SRN2!")
		EEPROM_Write(EEADDR_SRV1MIN, (u16) Servo.min[1]);
	else
	_IF_MEMBER_THEN(":SRN3!")
		EEPROM_Write(EEADDR_SRV2MIN, (u16) Servo.min[2]);
	else
	_IF_MEMBER_THEN(":SRN4!")
		EEPROM_Write(EEADDR_SRV3MIN, (u16) Servo.min[3]);
	else
	_IF_MEMBER_THEN(":SRN5!")
		EEPROM_Write(EEADDR_SRV4MIN, (u16) Servo.min[4]);
	else
	_IF_MEMBER_THEN(":SRN6!")
		EEPROM_Write(EEADDR_SRV5MIN, (u16) Servo.min[5]);
	else
	_IF_MEMBER_THEN(":SRN7!")
		EEPROM_Write(EEADDR_SRV6MIN, (u16) Servo.min[6]);
	else
	_IF_MEMBER_THEN(":SRN8!")
		EEPROM_Write(EEADDR_SRV7MIN, (u16) Servo.min[7]);
		
	else
	_IF_MEMBER_THEN(":SRM1!")
		EEPROM_Write(EEADDR_SRV0MAX, (u16) Servo.max[0]);
	else
	_IF_MEMBER_THEN(":SRM2!")
		EEPROM_Write(EEADDR_SRV1MAX, (u16) Servo.max[1]);
	else
	_IF_MEMBER_THEN(":SRM3!")
		EEPROM_Write(EEADDR_SRV2MAX, (u16) Servo.max[2]);
	else
	_IF_MEMBER_THEN(":SRM4!")
		EEPROM_Write(EEADDR_SRV3MAX, (u16) Servo.max[3]);
	else
	_IF_MEMBER_THEN(":SRM5!")
		EEPROM_Write(EEADDR_SRV4MAX, (u16) Servo.max[4]);
	else
	_IF_MEMBER_THEN(":SRM6!")
		EEPROM_Write(EEADDR_SRV5MAX, (u16) Servo.max[5]);
	else
	_IF_MEMBER_THEN(":SRM7!")
		EEPROM_Write(EEADDR_SRV6MAX, (u16) Servo.max[6]);
	else
	_IF_MEMBER_THEN(":SRM8!")
		EEPROM_Write(EEADDR_SRV7MAX, (u16) Servo.max[7]);
		
	else
	_IF_MEMBER_THEN(":CNF1!")
		EEPROM_Write(EEADDR_SRV0ADJ, (u16) Servo.adj[0]);
	else
	_IF_MEMBER_THEN(":CNF2!")
		EEPROM_Write(EEADDR_SRV1ADJ, (u16) Servo.adj[1]);
	else
	_IF_MEMBER_THEN(":CNF3!")
		EEPROM_Write(EEADDR_SRV2ADJ, (u16) Servo.adj[2]);
	else
	_IF_MEMBER_THEN(":CNF4!")
		EEPROM_Write(EEADDR_SRV3ADJ, (u16) Servo.adj[3]);
	else
	_IF_MEMBER_THEN(":CNF5!")
		EEPROM_Write(EEADDR_SRV4ADJ, (u16) Servo.adj[4]);
	else
	_IF_MEMBER_THEN(":CNF6!")
		EEPROM_Write(EEADDR_SRV5ADJ, (u16) Servo.adj[5]);
	else
	_IF_MEMBER_THEN(":CNF7!")
		EEPROM_Write(EEADDR_SRV6ADJ, (u16) Servo.adj[6]);
	else
	_IF_MEMBER_THEN(":CNF8!")
		EEPROM_Write(EEADDR_SRV7ADJ, (u16) Servo.adj[7]);

	else
	_GET_SET_MEMBER(Servo.target[0], ":SRV1")
	else
	_GET_SET_MEMBER(Servo.target[1], ":SRV2")
	else
	_GET_SET_MEMBER(Servo.target[2], ":SRV3")
	else
	_GET_SET_MEMBER(Servo.target[3], ":SRV4")
	else
	_GET_SET_MEMBER(Servo.target[4], ":SRV5")
	else
	_GET_SET_MEMBER(Servo.target[4], ":SRV6") // SRV5 i SRV6 nastawiane razem
	else
	_GET_SET_MEMBER(Servo.target[6], ":SRV7")
	else							
	_GET_SET_MEMBER(Servo.target[6], ":SRV8") // SRV7 i SRV8 nastawiane razem
	
	else
	_GET_SET_MEMBER(Servo.min[0], ":SRN1")
	else
	_GET_SET_MEMBER(Servo.min[1], ":SRN2")
	else
	_GET_SET_MEMBER(Servo.min[2], ":SRN3")
	else
	_GET_SET_MEMBER(Servo.min[3], ":SRN4")
	else
	_GET_SET_MEMBER(Servo.min[4], ":SRN5")
	else
	_GET_SET_MEMBER(Servo.min[5], ":SRN6")
	else
	_GET_SET_MEMBER(Servo.min[6], ":SRN7")
	else							
	_GET_SET_MEMBER(Servo.min[7], ":SRN8")
	
	else
	_GET_SET_MEMBER(Servo.max[0], ":SRM1")
	else
	_GET_SET_MEMBER(Servo.max[1], ":SRM2")
	else
	_GET_SET_MEMBER(Servo.max[2], ":SRM3")
	else
	_GET_SET_MEMBER(Servo.max[3], ":SRM4")
	else
	_GET_SET_MEMBER(Servo.max[4], ":SRM5")
	else
	_GET_SET_MEMBER(Servo.max[5], ":SRM6")
	else
	_GET_SET_MEMBER(Servo.max[6], ":SRM7")
	else							
	_GET_SET_MEMBER(Servo.max[7], ":SRM8")
	
	else
	_GET_SET_MEMBER(Servo.adj[0], ":CNF1")
	else
	_GET_SET_MEMBER(Servo.adj[1], ":CNF2")
	else
	_GET_SET_MEMBER(Servo.adj[2], ":CNF3")
	else
	_GET_SET_MEMBER(Servo.adj[3], ":CNF4")
	else
	_GET_SET_MEMBER(Servo.adj[4], ":CNF5")
	else
	_GET_SET_MEMBER(Servo.adj[5], ":CNF6")
	else
	_GET_SET_MEMBER(Servo.adj[6], ":CNF7")
	else
	_GET_SET_MEMBER(Servo.adj[7], ":CNF8") 
	
	else
	_IF_MEMBER_THEN(":DOUT"){
		OUT_Set((rxBuf[6]=='1')<<7
				| (rxBuf[7]=='1')<<6
				| (rxBuf[8]=='1')<<5
				| (rxBuf[9]=='1')<<4
				| (rxBuf[10]=='1')<<3
				| (rxBuf[11]=='1')<<2
				| (rxBuf[12]=='1')<<1
				| (rxBuf[13]=='1')<<0);
	}
	
	else
	_IF_MEMBER_THEN(":DIN?")
		_PRINT_RESPONSE("%s\r\n", u8_to_binary(NFComBuf.ReadDigitalInputs.data[0], 7))
		
	else
	_IF_MEMBER_THEN(":AIN0?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[0])
	else
	_IF_MEMBER_THEN(":AIN1?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[1])
	else
	_IF_MEMBER_THEN(":AIN2?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[2])
	else
	_IF_MEMBER_THEN(":AIN3?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[3])
	else
	_IF_MEMBER_THEN(":AIN4?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[4])
	else
	_IF_MEMBER_THEN(":AIN5?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[5])
	else
	_IF_MEMBER_THEN(":AIN6?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[6])
	else
	_IF_MEMBER_THEN(":AIN7?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[7])
	else
	_IF_MEMBER_THEN(":AIN8?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[8])
	else
	_IF_MEMBER_THEN(":AIN9?")
		_PRINT_RESPONSE("%d\r\n", NFComBuf.ReadAnalogInputs.data[9])

	else
	_GROUP(":MOT1") 
		_GET_SET_MEMBER(NFComBuf.SetDrivesSpeed.data[0], "")
		MOTOR1_SetInput(NFComBuf.SetDrivesSpeed.data[0]);
	_ENDGROUP

	else
	_GROUP(":MOT2") 
		_GET_SET_MEMBER(NFComBuf.SetDrivesSpeed.data[1], "")
		MOTOR2_SetInput(NFComBuf.SetDrivesSpeed.data[1]);
	_ENDGROUP
	
	else
	_IF_MEMBER_THEN(":ENC1?")
		_PRINT_RESPONSE("%d\r\n", ENC1_ReadIncrement())		

	else
	_IF_MEMBER_THEN(":ENC2?")
		_PRINT_RESPONSE("%d\r\n", ENC2_ReadIncrement())		
										 
	else
	_IF_MEMBER_THEN(":SER!")
		EEPROM_Write(EEADDR_SERIAL, (u16) serialNumber);
	else							
	_GET_SET_MEMBER(serialNumber, ":SER")

	else
	_GROUP(":MEM") 
		_IF_MEMBER_THEN(":DEF")
			eebackup_SaveInitialValues();
		else
		_IF_MEMBER_THEN(":STO")
			eebackup_SaveAll();
		else
		_IF_MEMBER_THEN(":REC")
			eebackup_Recover();
	_ENDGROUP

	else
	_GROUP(":LED") 
		_IF_MEMBER_THEN(":SET")
			switch(rxBuf[9]){
				case '0':
					LED_Set(1<<0, 1<<0, 0);
					break;
				case '1':
					LED_Set(1<<1, 1<<1, 0);
					break;
				case '2':
					LED_Set(1<<2, 1<<2, 0);
					break;
			}
		else  
		_IF_MEMBER_THEN(":RES")
			switch(rxBuf[9]){
				case '0':
					LED_Set(1<<0, 0, 0);
					break;
				case '1':
					LED_Set(1<<1, 0, 0);
					break;
				case '2':
					LED_Set(1<<2, 0, 0);
					break;
			}
	_ENDGROUP

	else
	_GROUP(":DYNA") 
		_IF_MEMBER_THEN(":LED ON"){
		}
		else  
		_IF_MEMBER_THEN(":LED OFF"){
		}
	_ENDGROUP
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

