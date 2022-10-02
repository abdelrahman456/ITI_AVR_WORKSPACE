/*
 * main.c
 *
 *  Created on: Sep 17, 2022
 *      Author: abdo_
 */




#include <avr/io.h>
#include <avr/delay.h>
#include"LIB/std_types.h"
#include"LIB/bit_math.h"

#include "MCAL/DIO_INTERFACE.h"
#include "WD_T/WD_INTERFACE.h"








int main(void)
{


		DIO_vWritePinDirection(DIO_PORTA, DIO_PIN0, OUTPUT);
	    WD_vENABLE();
	    DIO_vWritePinVALUE(DIO_PORTA, DIO_PIN0, HIGH);
		_delay_ms(500);
		DIO_vWritePinVALUE(DIO_PORTA, DIO_PIN0, LOW);
		WD_vDISABLE();

	while(1)
	{

	}
}





