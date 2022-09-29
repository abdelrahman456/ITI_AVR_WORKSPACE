/*
 * main.c
 *
 *  Created on: Sep 23, 2022
 *      Author: abdo_
 */


#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#include "MCAL/DIO_INTERFACE.h"
#include "GIE/GIE_INTERFACE.h"
#include "EXTI/EXTI_INTERFACE.h"
void TOggle(void){

	DIO_vTogglePin(DIO_PORTA,DIO_PIN0);


}

int main(void){

	EXTI_vRegisterCallback(EXTI_0,TOggle);
	DIO_vWritePinDirection(DIO_PORTA, DIO_PIN0, OUTPUT);
	EXTI_vInit();
	GIE_vEnable();

while(1){}






}
