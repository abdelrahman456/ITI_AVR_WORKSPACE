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
#include "02-7seg/7seg.h"






void count_99(_7seg* ss1, _7seg* ss2 ) {

	for(u8 i=0 ; i<100; i++)
	{
		_7SEG_VidDisplayNum( ss1, (i/10));
		_7SEG_VidDisplayNum( ss2, (i%10));
		_delay_ms(100);


	}


}
int main(void)
{


	_7seg_pin ss1_pins[]={
			{DIO_PORTA,0},
			{DIO_PORTA,1},
			{DIO_PORTA,2},
			{DIO_PORTA,3},
			{DIO_PORTA,4},
			{DIO_PORTA,5},
			{DIO_PORTA,6},
			{DIO_PORTA,7},
	};

	_7seg_pin ss2_pins[]={
			{DIO_PORTC,0},
			{DIO_PORTC,1},
			{DIO_PORTC,2},
			{DIO_PORTC,3},
			{DIO_PORTC,4},
			{DIO_PORTC,5},
			{DIO_PORTC,6},
			{DIO_PORTC,7},
	};



	_7seg  ss1;

	_7seg  ss2;

	ss1.pins=ss1_pins;
	ss1.type = COM_ANODE;

	ss2.pins=ss2_pins;
	ss2.type = COM_ANODE;


	_7SEG_VidInit(&ss1);
	_7SEG_VidInit(&ss2);

count_99(&ss1, &ss2);
	while(1)
	{

	}
}





