/*
 * ADC_PRIV.h
 *
 *  Created on: Sep 23, 2022
 *      Author: abdo_
 */

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/*Bit 7 – ADEN: ADC Enable*/
#define ADEN 7

/*Bit 5 – ADATE: ADC Auto Trigger Enable/disable*/
#define ADATE 5

/*Bit 7:5 – ADTS2:0: ADC Auto Trigger Source SFIOR*/

#define Free_Running 		(0b000<<4)
#define Analog_Comparator   (0b001<<4)
#define EXTI0_Request 		(0b010<<4)
#define Timer0_COMP		    (0b011<<4)
#define Timer0_OVF 			(0b100<<4)
#define Timer_COMP_B 		(0b101<<4)
#define Timer1_OVF  		(0b110<<4)
#define Timer1_CE 			(0b111<<4)



/*Bit 3 – ADIE: ADC Interrupt Enable*/
#define ADIE	3

/*Bit 7:6 – REFS1:0: Voltage Reference Selection Bits*/
#define VREF_VCC  	  0b01   //AVCC with external capacitor at AREF pin
#define VREF_AREF 	  0b00	//AREF, Internal Vref turned off
#define VREF_Reserved 0b10  //Reserved
#define VREF_Internal 0b11	//Internal 2.56V Voltage Reference with external capacitor at AREF pin

/*Bits 2:0 – ADPS2:0: ADC Prescaler Select Bits*/
#define PR_128 0b111
#define PR_64  0b110
#define PR_32  0b101
#define PR_16  0b100
#define PR_8   0b011
#define PR_4   0b010
#define PR_2   0b000

/*Bits 4:0 – MUX4:0: Analog Channel and Gain Selection Bits*/
#define A_CHANNAE_0 0b00000 //ADC0
#define A_CHANNAE_1 0b00001	//ADC1
#define A_CHANNAE_2 0b00010	//ADC2
#define A_CHANNAE_3 0b00011 //ADC3
#define A_CHANNAE_4 0b00100	//ADC4
#define A_CHANNAE_5 0b00101	//ADC5
#define A_CHANNAE_6 0b00110	//ADC6
#define A_CHANNAE_7 0b00111	//ADC7

#define ADSC 6 //start conversion

#define ADIF 4 //ADC Interrupt flag

#define  ADMUX   *((volatile u8*)(0x27))
#define  ADCSRA  *((volatile u8*)(0x26))

#define  ADCH  	 *((volatile u8*)(0x25))
#define  ADCL    *((volatile u8*)(0x24))
#define  SFIOR   *((volatile u8*)(0x50))

#define ADC_DATA *((volatile u16*)0x24)

#endif /* ADC_PRIV_H_ */
