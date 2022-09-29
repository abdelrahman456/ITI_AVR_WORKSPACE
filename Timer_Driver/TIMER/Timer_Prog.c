/*
 * Timer_Prog.c
 *
 *  Created on: Sep 24, 2022
 *      Author: abdo_
 */

#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"

#include "Timer_INTERFACE.h"
#include "Timer_PRIV.h"
#include "Timer_Config.h"

static void(*TIMER0_OVF_Callback)(void);
static void(*TIME0_COMP_Callback)(void);

void TIMERS_vInit(void){
#if TIMER0_ENABLE == ENABLE
	/*1- select wave generation mode	*/
	 SET_Bit(TCCR0, WGM00);
	 SET_Bit(TCCR0, WGM01);

	/*2- Output compare mode 	*/
	 CLR_Bit(TCCR0, COM00);
	 SET_Bit(TCCR0, COM01);
	/*3- preload */
	 TCNT0 =TIMER0_PRELOAD;
	/*4- Interrupt EN/DIS 	*/
	 CLR_Bit(TIMSK,TOV0);
	 CLR_Bit(TIMSK, OCIE0);
	 /* PWM: Disable Interrupts */

#endif
#if TIMER1_ENABLE == ENABLE

	 SET_Bit(TCCR1B,WGM13);
	 SET_Bit(TCCR1B,WGM12);
	 SET_Bit(TCCR1A,WGM11);
	 CLR_Bit(TCCR1A,WGM10);

	 SET_Bit(TCCR1A,COM1A1); // COM1A1	7
	 CLR_Bit(TCCR1A,COM1A0); 	// COM1A0	6
#endif
}
void TIMERS_vSetBusyWait_synch (/*TIMER ID*/ u32 A_u32Ticks)
{







}

void TIMERS_vStartTimer(u8 A_u8TimerId){

switch(A_u8TimerId){
	case TIMER0:
			TCCR0 =(TCCR0 & ~0b111) | (TIMER0_PRESCALER);	break;
	case TIMER1:
			TCCR1B =(TCCR1B & ~0b111) | (TIMER1_PRESCALER);	break;

	default:												break;

	}

}

void TIMERS_vStopTimer(u8 A_u8TimerId){

switch(A_u8TimerId){

	case TIMER0:
			TCCR0 =(TCCR0 & ~0b111) | (PS_NOCLK);	break;
	case TIMER1:
			TCCR1B =(TCCR1B & ~0b111) | (PS_NOCLK);	break;

	default:												break;



	}

}

void TIMERS_vSetPreloadValue(u8 A_u8TimerId, u16 A_u16Preload){

switch(A_u8TimerId){

		case TIMER0:
				TCNT0 =A_u16Preload;	break;
		case TIMER1:
				TCNT1 =A_u16Preload;	break;

		default:												break;



		}

}


void TIMERS_vSetCompareMatchValue(u8 A_u8TimerId, u16 A_u16OcrVal   ){

	switch(A_u8TimerId){

		case TIMER0:
				OCR0 = A_u16OcrVal;	break;
		case TIMER1:
				OCR1A = A_u16OcrVal;	break;

		default:												break;



		}

}

void TIMERS_vSetICR1(u16 A_16IcrValue)
{
	ICR1 = A_16IcrValue;
}


void TIMERS_vStetCallback(/*TIMER ID*/ void(*fptr)(void)){




	TIME0_COMP_Callback = fptr;





}


void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
if(TIMER0_OVF_Callback!=NULL){

	TIMER0_OVF_Callback();


}
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
if(TIME0_COMP_Callback!=NULL){

	TIME0_COMP_Callback();


}
}

