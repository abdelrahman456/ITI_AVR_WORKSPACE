/*
 * 7seg.c
 *
 *  Created on: Aug 16, 2021
 *      Author: abdo_
 */


#include <avr/io.h>
#include <avr/delay.h>
#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL/DIO_INTERFACE.h"
#include "7seg.h"

const u8 seven_seg_digits[16]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,A,b,c,d,E,F};

void _7SEG_VidInit(_7seg* me)
{
	for(u8 i=0 ; i<8; i++){
	DIO_vWritePinDirection(me->pins[i].port, me->pins[i].pin ,OUTPUT);

	}



}


void _7SEG_VidDisplayNum(_7seg* me, u8 num)
{

	u8 number =0;
	if(me->type==COM_CATHODE){

	number=seven_seg_digits[num%16];

	}else if (me->type==COM_ANODE)
	{
		number=~seven_seg_digits[num%16];



	}





	for(u8 i=0 ; i<8; i++){


	 DIO_vWritePinVALUE(me->pins[i].port, me->pins[i].pin, GET_Bit(number, i));

	}

}

void _7SEG_VidDisplayOff(_7seg * me)
{
	u8 number=0;
		if(me->type==COM_ANODE)
		{
			number = 0x00;
		}
		else if(me->type==COM_CATHODE)
		{
			number = 0xff;
		}

		for(u8 i=0; i<8; i++)
		{
			DIO_vWritePinVALUE(me->pins[i].port, me->pins[i].pin, (GET_Bit(number,i)));
		}




}

