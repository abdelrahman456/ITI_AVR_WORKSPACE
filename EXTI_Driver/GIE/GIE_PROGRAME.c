/*
 * GIE_PROGRAME.c
 *
 *  Created on: Sep 23, 2022
 *      Author: abdo_
 */

#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL/DIO_INTERFACE.h"
#include "GIE_INTERFACE.h"
#include "GIE_PRIV.h"
void GIE_vEnable(void){

	SET_Bit(SREG,I_BIT);


}
