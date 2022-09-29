/*
 * LCD_PROGRAM.c
 *
 *  Created on: Sep 16, 2022
 *      Author: abdo_
 */

#include <avr/io.h>
#include <avr/delay.h>
#include"../LIB/std_types.h"
#include"../LIB/bit_math.h"
#include "LCD_INTERFACE.h"
#include "LCD_PRIV.h"
#include "LCD_CONFIG.h"

void LCD_sendcommand(char cmd){

	//Select RS -> 0
	CLR_Bit(LCD_CONTROL_PORT, LCD_RS_PIN);
	//SElect RW -> 0
	CLR_Bit(LCD_CONTROL_PORT, LCD_RW_PIN);
	//Select E -> 1
	LCD_DATA_PORT = cmd;
	SET_Bit(LCD_CONTROL_PORT, LCD_E_PIN);
	_delay_ms(1);
	CLR_Bit(LCD_CONTROL_PORT, LCD_E_PIN);
	_delay_ms(1);



}

void LCD_INIT(void){
	LCD_DATA_DDR= 0xff;

	SET_Bit(LCD_CONTROL_DDR, LCD_RS_PIN);
	SET_Bit(LCD_CONTROL_DDR, LCD_RW_PIN);
	SET_Bit(LCD_CONTROL_DDR, LCD_E_PIN);

	_delay_ms(50);
	LCD_sendcommand(0b00111000);
	_delay_ms(1);
	LCD_sendcommand(0b00001100);
		_delay_ms(1);
	LCD_sendcommand(0b00000001);
		_delay_ms(2);
	LCD_sendcommand(0b00000110);
		_delay_ms(1);





}


void LCD_sendChar(u8 character){
//Select RS -> 1
SET_Bit(LCD_CONTROL_PORT, LCD_RS_PIN);
//SElect RW -> 0
CLR_Bit(LCD_CONTROL_PORT, LCD_RW_PIN);
//Select E -> 1
PORTD = character;
SET_Bit(LCD_CONTROL_PORT, LCD_E_PIN);
_delay_ms(1);
CLR_Bit(LCD_CONTROL_PORT, LCD_E_PIN);
_delay_ms(1);
}

void LCD_sendstring(char* str, u32 delay){
while((*str)!='\0'){

	LCD_sendChar(*str);
	str++;
	if(delay != 0)
			{
				_delay_ms(delay);
			}

}
}




void LCD_send_number(int num){
	int rev=0;
	int flag = 0;
	char cr='0';
	while(num%10==0){

	  flag ++ ;
      num/=10;

	}

	while(num>0){


		rev=rev*10+num%10;
		num= num/10;

	}

	while(rev>0){


			num=rev%10;
            cr=num+'0';
            LCD_sendChar(cr);
			rev= rev/10;
	}
	while(flag!= 0) {


		 LCD_sendChar('0');
		rev*=10;
		flag--;

	}
}

void LCD_display_shap(char charid){

	LCD_sendChar(charid);





}



void LCD_save_shap(u8 charid, const u8 arr[]){

	LCD_sendcommand(0b01000000+(8*charid));

	for(int i =0; i<8;i++){


		LCD_sendChar(arr[i]);




	}


	LCD_sendcommand(0b10000000);





}
void LCD_set_cursor(u8 linepos, u8 line){

	if((line%2)==0){
	LCD_sendcommand(0x80+linepos);
	}else{


		LCD_sendcommand(0x80+linepos+64);
	}


}





