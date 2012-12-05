#ifndef _MYSCPI_H
#define _MYSCPI_H

#include <inttypes.h> 
#include <stdlib.h>
#include <stdio.h>		
#include <string.h>

#include "myscpi_defines.h"

uint8_t MYSCPI_Interpreter(volatile uint8_t *rxBuf, volatile uint8_t *rxPt, volatile uint8_t *txBuf, volatile uint8_t *txCnt);
int my_itoa(int value, char* result, int base);

#endif //_MYSCPI_H

