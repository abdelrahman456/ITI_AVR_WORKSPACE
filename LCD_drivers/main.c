/*
 * main.c
 *
 *  Created on: Sep 16, 2022
 *      Author: abdo_
 */


#include <avr/io.h>
#include <avr/delay.h>
#include"LIB/std_types.h"
#include"LIB/bit_math.h"
#include "LCD_INTERFACE.h"
#include "CUSTOM_CHARS.h"

#define REFRESH_RATE 250
#define steve 	0
#define kick 	1
#define punch	2
#define duck	3
#define dead1	4
#define dead2	5


const u8 custom_chars[][8] = {STICK_FIG,KICK,PUNCH,DUCK,DEAD1,DEAD2};

int main(void){

LCD_INIT();


//load all custom charahcters into CGRAM
	for(u8 i=0; i<6 ; i++)
	{
	LCD_save_shap(i, custom_chars[i]);
	}

	// frame 1
		LCD_sendcommand(0b00000001);
		LCD_set_cursor(0, 0);
		LCD_display_shap(steve);
		LCD_set_cursor(0,1);
		LCD_sendstring("This is Steve.",0);
		_delay_ms(REFRESH_RATE*2);
		// frame2~6
			LCD_set_cursor(0,0);
			LCD_sendChar(' ');
			for(u8 i=0; i<8;i++)
			{
				LCD_set_cursor(i,0);
				LCD_display_shap(steve);
				_delay_ms(REFRESH_RATE);
				LCD_set_cursor(i,0);
				LCD_sendChar(' ');
			}
			LCD_set_cursor(7,0);
			LCD_display_shap(steve);
			// end of frame2~6

			_delay_ms(REFRESH_RATE*4);

			// frame 7
			LCD_set_cursor(0,1);
			LCD_sendstring("Steve is Smart   ",0);
			// end of frame 7


			_delay_ms(REFRESH_RATE*8);

				// frame 8
				LCD_set_cursor(0,1);
				LCD_sendstring("He Plays KungFu ",0);
				// end of frame 8

				_delay_ms(REFRESH_RATE*8);

				//frame 9
				LCD_set_cursor(0,1);
				LCD_sendstring(">>>>Fight !!<<<<",250);
				// end of frame 9

				_delay_ms(REFRESH_RATE*4);

				// frame 10
				LCD_set_cursor(15,0);
				LCD_display_shap(steve);
				//end of frame 10

				_delay_ms(REFRESH_RATE*4);

				// frame 11~18
				for(u8 i=15; i != 8; i--)
				{
					LCD_set_cursor(i,0);
					LCD_display_shap(steve);
					_delay_ms(REFRESH_RATE);
					LCD_set_cursor(i,0);
					LCD_sendChar(' ');
				}
				LCD_set_cursor(8,0);
				LCD_display_shap(steve);
				// end of frame 11~18
				_delay_ms(REFRESH_RATE*4);

				//frame 19
				LCD_set_cursor(7,0);
				LCD_display_shap(kick);
				LCD_set_cursor(8,0);
				LCD_display_shap(punch);
				// end of frame 19
				_delay_ms(REFRESH_RATE*4);

				// frame 20
				LCD_set_cursor(7,0);
				LCD_display_shap(punch);
				LCD_set_cursor(8,0);
				LCD_display_shap(duck);
				// end of frame 20
				_delay_ms(REFRESH_RATE*4);

				// frame 21
				LCD_set_cursor(7,0);
				LCD_display_shap(duck);
				LCD_set_cursor(8,0);
				LCD_display_shap(kick);
				// end of frame 21
				_delay_ms(REFRESH_RATE*4);

				// frame 22
				LCD_set_cursor(7,0);
				LCD_display_shap(punch);
				LCD_set_cursor(8,0);
				LCD_display_shap(kick);
				// end of frame 22
				_delay_ms(REFRESH_RATE*4);

				// frame 23
				LCD_set_cursor(7,0);
				LCD_display_shap(duck);
				LCD_set_cursor(8,0);
				LCD_display_shap(punch);
				// end of frame 23
				_delay_ms(REFRESH_RATE*4);

				// frame 24
				LCD_set_cursor(7,0);
				LCD_display_shap(kick);
				LCD_set_cursor(8,0);
				LCD_display_shap(duck);
				// end of frame 24
				_delay_ms(REFRESH_RATE*4);

				// frame 25
				LCD_set_cursor(7,0);
				LCD_display_shap(steve);
				LCD_set_cursor(8,0);
				LCD_display_shap(dead1);
				LCD_display_shap(dead2);
				// end of frame 25
				_delay_ms(REFRESH_RATE*4);

				// frame 26
				LCD_set_cursor(0,1);
				LCD_sendstring("   >>>>KO<<<<   ", 0);
				_delay_ms(REFRESH_RATE);
				LCD_set_cursor(0,1);
				LCD_sendstring("                ", 0);
				_delay_ms(REFRESH_RATE);
				LCD_set_cursor(0,1);
				LCD_sendstring("   >>>>KO<<<<   ", 0);
				_delay_ms(REFRESH_RATE*4);
				LCD_set_cursor(0,1);
				LCD_sendstring("***Steve WON****", 0);

				// end of frame 26



while(1){


}
}
