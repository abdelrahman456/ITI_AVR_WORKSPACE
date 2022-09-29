/*
 * main.c
 *
 *  Created on: Sep 27, 2022
 *      Author: abdo_
 */
#include <util/delay.h>
#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#include "TIMER/Timer_INTERFACE.h"
#include "MCAL/DIO_INTERFACE.h"
#include "GIE/GIE_INTERFACE.h"

#if 0
void LedToggle(void)
{
	static u32 counter =0 ;
	counter++;
	if(counter == 4000)
	{
		counter =0 ;
		DIO_vTogglePin(DIO_PORTA, DIO_PIN0);
	}
}
#endif
int main(void){

	//DIO_vWritePinDirection(DIO_PORTB,DIO_PIN3,OUTPUT);
	DIO_vWritePinDirection(DIO_PORTD, DIO_PIN5, OUTPUT);
	TIMERS_vInit();
	//TIMERS_vStetCallback(LedToggle);

		//GIE_vEnable();
	    TIMERS_vSetICR1(624);
		TIMERS_vStartTimer(TIMER1);
u16 counter =0;
	while(1){

#if 0
		for(int i=0;i<=255;i++){
			counter++;
			if(counter==40000){
				counter=0;
			 TIMERS_vSetCompareMatchValue(TIMER1,i);

			}

				}
		for(int i=255;i>=0;--i){
					counter++;
					if(counter==40000){
						counter=0;
					 TIMERS_vSetCompareMatchValue(TIMER1,i);

					}

						}

#endif
		for(int i=32;i<64;i++){

						counter=0;
					 TIMERS_vSetCompareMatchValue(TIMER1,i);

					 _delay_ms(2);

						}
				for(int i=64;i>32;--i){

							 TIMERS_vSetCompareMatchValue(TIMER1,i);

							 _delay_ms(2);

								}
}}
