/*
 * WD_PROGRAM.c
 *
 *  Created on: Oct 2, 2022
 *      Author: abdo_
 */

#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "WD_INTERFACE.h"
#include "WD_PRIVATE.h"

void WD_vENABLE(void){

	WDTCR &=~(0b111)|(WDT_PS);	//Watchdog Timer SET Prescaler
	SET_Bit(WDTCR,WDE);  //WDE WATCH DOG ENABLE

}
void WD_vDISABLE(void){

WDTCR=0b00011000;
WDTCR=0;
CLR_Bit(WDTCR,WDE);

}
