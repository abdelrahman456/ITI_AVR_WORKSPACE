/*
 * ADC_PROG.c
 *
 *  Created on: Sep 23, 2022
 *      Author: abdo_
 */
#include "../LIB/std_types.h"
#include "../LIB/bit_math.h"
#include "ADC_INTERFACE.h"
#include "ADC_PRIV.h"
#include "ADC_CONFIG.h"

static void (*G_ADC_Callback)(u16) = NULL;

void ADC_vInit(void){

	/*1- select reference bits */
	ADMUX &=~(0b11<<6);
	ADMUX |= (ADC_VREF<<6);
	/*2- select data adjustment*/
#if  DATA_ADJUST==RIGHT_ADJUST
	CLR_BIT(ADMUX,5);			//right adjustment
#elif  DATA_ADJUST == LEFT_ADJUST
	SET_BIT(ADMUX,5);			//left adjustment
#endif

	/*3- ADC Enable */
	SET_Bit(ADCSRA,ADEN); 	//set bit 7 in ADCSRA (ADEN)

	/*4- Auto trigger enable/disable
	 *  ADATE: ADC Auto Trigger Enable/disable */
#if AUTO_TRIGGER_MODE == DISABLE
	CLR_Bit(ADCSRA,ADATE);	//ADC Auto Trigger Disable Clear (ADATE)
#elif AUTO_TRIGGER_MODE == ENABLE
	SET_Bit(ADCSRA,ADATE);
	/*4-a select auto trigger source*/
	SFIOR &= ~(0b111<<4);
	SFIOR |=(AUTO_TRIGGER_SOURCE);
#endif

	/*5- ADIE: ADC Interrupt Enable/Disable	*/
#if	ADC_INTERRUPT_MODE == DISABLE
	CLR_Bit(ADCSRA,ADIE);	//ADC Interrupt Disable	Clear ADIE
#elif ADC_INTERRUPT_MODE == ENABLE
	SET_Bit(ADCSRA,ADIE);	//ADC Interrupt Enable	SET ADIE
#endif
	/*6- conv. clock Prescaler*/
	ADCSRA &= ~ (0b111);
	ADCSRA |= (ADC_PR);



}




u16 ADC_u16Read(u8 ADC_u8Channel){

	/*1- select channel	*/
	ADMUX &= ~(0b11111);
	ADMUX |=(ADC_u8Channel & 0x07); //select channel_0 and allow only number from 0 to 7

	/*2- start conversion*/
	SET_Bit(ADCSRA,ADSC); //set bit 6 in ADCSRA (ADSC)

	/*3- wait for conv. complete flag*/
	while(GET_Bit(ADCSRA,ADIF)==0)
	{/*wait for conversion to complete */}

	/*4- clear flag*/
#if AUTO_TRIGGER_MODE == DISABLE
	SET_Bit(ADCSRA,ADIF);	//ADC Interrupt flag
#endif

	/* 5- return ADC value*/
#if DATA_ADJUST == LEFT_ADJUST
	return ADCH;

#elif 	DATA_ADJUST == RIGHT_ADJUST
	return ADC_DATA;

#endif


}



void ADC_vSetCallback(void (*fptr)(u16)){

	if(fptr!=NULL){
		G_ADC_Callback=fptr;
}



}

void ADC_EnableInterrupt(void){

#if ADC_INTERRUPT_MODE == ENABLE
	/*5- ADIE: ADC Interrupt Enable/Disable	*/
		SET_Bit(ADCSRA,ADIE);	//ADC Interrupt Enable	Set ADIE

#endif

}

void ADC_DisableInterrupt(void){

#if ADC_INTERRUPT_MODE == ENABLE
	/*5- ADIE: ADC Interrupt Enable/Disable	*/
		CLR_Bit(ADCSRA,ADIE);	//ADC Interrupt Disable	Clear ADIE
#endif
}
void ADC_vSelectChannel(u8 ADC_u8Channel){

		/*1- select channel	*/
		ADMUX &= ~(0b11111);
		ADMUX |=(ADC_u8Channel & 0x07); //select channel_0 and allow only number from 0 to 7



}
#if ADC_INTERRUPT_MODE == ENABLE
void __vector_16(void) __attribute__((signal));
void __vector_16(void)
{

	if(G_ADC_Callback!=NULL){

		G_ADC_Callback(ADC_DATA);

	}

}
#endif

void ADC_vStartConversion(u8 ADC_u8Channel){

		/*1- select channel	*/
		ADMUX &= ~(0b11111);
		ADMUX |=(ADC_u8Channel & 0x07); //select channel_0 and allow only number from 0 to 7

		/*2- start conversion*/
		SET_Bit(ADCSRA,ADSC); //set bit 6 in ADCSRA (ADSC)






}
u16 ADC_u16GetValue(u8 ADC_u8Channel){

	        ADMUX &= ~(0b11111);
			ADMUX |=(ADC_u8Channel & 0x07);

#if DATA_ADJUST == LEFT_ADJUST
	return ADCH;

#elif 	DATA_ADJUST == RIGHT_ADJUST
	return ADC_DATA;

#endif


}
