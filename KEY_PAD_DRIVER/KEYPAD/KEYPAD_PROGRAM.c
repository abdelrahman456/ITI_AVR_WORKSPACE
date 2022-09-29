/*
 * KEYPAD_PROGRAM.c
 *
 *  Created on: Sep 22, 2022
 *      Author: abdo_
 */

#include <avr/io.h>
#include <util/delay.h>

#include "../LIB/std_types.h"

#include "../LIB/bit_math.h"

#include "../MCAL/DIO_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"

void KEYPAD_vInit(void){

	DIO_vWritePortDirection(KEYPAD_PORT,0xF0);
	DIO_vWritePortVALUE(KEYPAD_PORT,HIGH); // activate pull up resistors




}
u8 KEYPAD_vGETPress(void){

	u8 Pressed_Key=0;
	u8 row = 0, col =0;

	for(col=0; col<COLUMNS; col++)
	{

		DIO_vWritePinVALUE(KEYPAD_PORT, col+4, LOW);

		for(row=0; row<ROWS; row++)
		{
			if(DIO_vReadPinVALUE(KEYPAD_PORT,row)==0){

				Pressed_Key=(row+(col*COLUMNS)+1);



			}while(DIO_vReadPinVALUE(KEYPAD_PORT,row)==0){}

		    _delay_ms(DEBOUNCE_DELAY);



		}



		DIO_vWritePinVALUE(KEYPAD_PORT, col+4, HIGH);




}





return Pressed_Key;


}
