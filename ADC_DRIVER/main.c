/*
 * main.c
 *
 *  Created on: Sep 24, 2022
 *      Author: abdo_
 */


#include <avr/io.h>
#include <util/delay.h>
#include "LIB/bit_math.h"
#include "LIB/std_types.h"
#include "MCAL/DIO_INTERFACE.h"
#include "ADC/ADC_INTERFACE.h"
#include "ADC/ADC_CONFIG.h"
#include "LCD/LCD_INTERFACE.h"
#include "GIE/GIE_INTERFACE.h"
void A_LED(void){
	u16 T;
		DIO_vWritePortDirection(DIO_PORTC,0xff);
			DIO_vWritePortVALUE(DIO_PORTC,0x00);
	T=ADC_u16Read(0b00000);
			if(T>0 && T<127){
				DIO_vWritePortVALUE(DIO_PORTC,0x01);
			}else if(T<255 && T>127){


				DIO_vWritePortVALUE(DIO_PORTC,0x03);

			}else if(T<383 && T>255){

				DIO_vWritePortVALUE(DIO_PORTC,0x07);
			}else if(T<511 && T>383){

				DIO_vWritePortVALUE(DIO_PORTC,0x0f);
			}else if(T<639 && T>511){

				DIO_vWritePortVALUE(DIO_PORTC,0x1f);
			}else if(T<767 && T>639){

				DIO_vWritePortVALUE(DIO_PORTC,0x3f);

			}else if(T<895 && T>767){

				DIO_vWritePortVALUE(DIO_PORTC,0x7f);

			}else if(T<1023 && T>895){

				DIO_vWritePortVALUE(DIO_PORTC,0xff);

			}

}

int main(void){

	//LCD_INIT();
		DIO_vWritePortDirection(DIO_PORTC,0xff);
		DIO_vWritePortVALUE(DIO_PORTC,0x00);
		ADC_vInit();




		ADC_EnableInterrupt();

			GIE_vEnable();

			//ADC_vStartConversion(0b00000);
	//LCD_sendcommand(0b00000001);

			ADC_vSetCallback(A_LED);

	while(1){


		ADC_vStartConversion(0b00000);


		/*LCD_set_cursor(0,0);
		_delay_ms(50);
		LCD_send_number(T);
		LCD_set_cursor(5,0);
		LCD_sendChar('c');*/

	}





}
