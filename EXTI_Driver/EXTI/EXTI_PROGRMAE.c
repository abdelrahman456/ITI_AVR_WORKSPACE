/*
 * EXTI_PROGRMAE.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Abdelrhaman Raafat
 */

#include "../LIB/bit_math.h"
#include "../LIB/std_types.h"
#include "../MCAL/DIO_INTERFACE.h"
#include "EXTI_INTERFACE.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_CONFIG.h"


static void (*G_EXTI0_Callback)(void);
static void (*G_EXTI1_Callback)(void);
static void (*G_EXTI2_Callback)(void);


void EXTI_vInit(void){



#if EXTI_Init_0 == ENABLE

			/* 1- make pins input*/
			DIO_vWritePinDirection(EXTI0_PORT,EXTI0_pin,INPUT);
			DIO_vWritePinVALUE(EXTI0_PORT,EXTI0_pin,HIGH);

			/* 2-sense control*/
			MCUCR &= ~(0b11);
			MCUCR |=(EXTI0_SC & 0x03);

			/*3- enable Interrupt*/
			SET_Bit(GICR,EXTI0_E);
#endif
#if  EXTI_Init_1	== ENABLE

			    /* 1- make pins input*/
				DIO_vWritePinDirection(EXTI0_PORT,EXTI0_pin,INPUT);
				DIO_vWritePinVALUE(EXTI0_PORT,EXTI0_pin,HIGH);

				/* 2-sense control*/
				MCUCR &= ~(0b11<<2);
				MCUCR |=(EXTI1_SC & 0x30);
				//SET_Bit(MCUCR,1);
				//CLR_Bit(MCUCR,0);


				/*3- enable Interrupt*/
				SET_Bit(GICR,EXTI1_E);
#endif

#if  EXTI_Init_2 == ENABLE


				/* 1- make pins input*/
				DIO_vWritePinDirection(EXTI0_PORT,EXTI0_pin,INPUT);
				DIO_vWritePinVALUE(EXTI0_PORT,EXTI0_pin,HIGH);

					/* 2-sense control*/
					MCUCSR &= ~(0b1<<6);
					MCUCSR |=(EXTI2_SC);
					//SET_Bit(MCUCSR,1);
					//CLR_Bit(MCUCSR,0);

					/*3- enable Interrupt*/
					SET_Bit(GICR,EXTI3_E);
#endif
#if EXTI_Init_2==DISABLE && EXTI_Init_2==DISABLE && EXTI_Init_2==DISABLE
#warning "EXTI_vInit(): NO Interrupt pins selected!!"
#endif
}

void EXTI_vSetSenseCtr( u8 A_u8ExtiPin, u8 A_u8SenseCtrl){

		/* 1- make pins input*/


		DIO_vWritePinDirection(EXTI_PORT,A_u8ExtiPin,INPUT);
		DIO_vWritePinVALUE(EXTI_PORT,A_u8ExtiPin,HIGH);
switch(A_u8ExtiPin)
{

	case EXTI_0:


					/* 2-sense control
					 * EXTI0_low_level	0
					 * EXTI0_Any_logical_change 1
					 * EXTI0_falling_edge	2
					 * EXTI0_rising_edgel	3
					 * */
		switch(A_u8SenseCtrl)
		{

			case low_level:
						MCUCR &= ~(0b11);
						MCUCR |=(EXTI0_low_level & 0x03);
						//SET_Bit(MCUCR,1);
						//CLR_Bit(MCUCR,0);
											break;
			case Any_logical_change:
						MCUCR &= ~(0b11);
						MCUCR |=(EXTI0_Any_logical_change & 0x03);
						//SET_Bit(MCUCR,1);
						//CLR_Bit(MCUCR,0);
											break;
			case falling_edge:
						MCUCR &= ~(0b11);
						MCUCR |=(EXTI0_falling_edge & 0x03);
						//SET_Bit(MCUCR,1);
						//CLR_Bit(MCUCR,0);
											break;
			case rising_edgel:
						MCUCR &= ~(0b11);
						MCUCR |=(EXTI0_rising_edgel & 0x03);
						//SET_Bit(MCUCR,1);
						//CLR_Bit(MCUCR,0);
												break;
			default :							break;

		}
		/*3- enable Interrupt*/
		SET_Bit(GICR,EXTI0_E);	break;

	case EXTI_1:

							/* 2-sense control
							 * EXTI1_low_level	0
							 * EXTI1_Any_logical_change 1
							 * EXTI1_falling_edge	2
							 * EXTI1_rising_edgel	3
							 * */
			switch(A_u8SenseCtrl)
			{

					case low_level:
								MCUCR &= ~(0b11<<2);
								MCUCR |=(EXTI1_low_level & 0x03);
								//SET_Bit(MCUCR,1);
								//CLR_Bit(MCUCR,0);
													break;
					case Any_logical_change:
								MCUCR &= ~(0b11<<2);
								MCUCR |=(EXTI1_Any_logical_change & 0x03);
								//SET_Bit(MCUCR,1);
								//CLR_Bit(MCUCR,0);
													break;
					case falling_edge:
								MCUCR &= ~(0b11<<2);
								MCUCR |=(EXTI1_falling_edge & 0x03);
								//SET_Bit(MCUCR,1);
								//CLR_Bit(MCUCR,0);
													break;
					case rising_edgel:
								MCUCR &= ~(0b11<<2);
								MCUCR |=(EXTI1_rising_edgel & 0x03);
								//SET_Bit(MCUCR,1);
								//CLR_Bit(MCUCR,0);
														break;
					default :							break;

				}

					/*3- enable Interrupt*/
					SET_Bit(GICR,EXTI1_E); 	break;

	case EXTI_2:

						/* 2-sense control
						 * EXTI2_falling_edge	2
						 * EXTI2_rising_edgel	3
						 * */
					switch(A_u8SenseCtrl)
					{
							case falling_edge:
										MCUCR &= ~(0b1<<6);
										MCUCR |=(EXTI2_falling_edge );
										//SET_Bit(MCUCR,1);
										//CLR_Bit(MCUCR,0);
															break;
							case rising_edgel:
										MCUCR &= ~(0b1<<6);
										MCUCR |=(EXTI2_rising_edgel );
										//SET_Bit(MCUCR,1);
										//CLR_Bit(MCUCR,0);
																break;
							default :							break;

						}

					MCUCSR &= ~(0b1<<6);
					MCUCSR |=(EXTI2_SC);
					//SET_Bit(MCUCSR,1);
					//CLR_Bit(MCUCSR,0);
					/*3- enable Interrupt*/
					SET_Bit(GICR,EXTI2_E);	break;

	default :								break;

}

}
void EXTI_vEnableInterrupt(u8 A_u8ExtiPin){

			/* 1- make pins input*/




switch(A_u8ExtiPin)
{
	case EXTI_0:

					DIO_vWritePinDirection(EXTI_PORT,EXTI0_pin,INPUT);
					DIO_vWritePinVALUE(EXTI_PORT,EXTI0_pin,HIGH);

					/*3- enable Interrupt 0*/
					SET_Bit(GICR,EXTI0_E);	break;

	case EXTI_1:
					DIO_vWritePinDirection(EXTI_PORT,EXTI1_pin,INPUT);
					DIO_vWritePinVALUE(EXTI_PORT,EXTI1_pin,HIGH);
					/*3- enable Interrupt 1*/
					SET_Bit(GICR,EXTI1_E);	break;
	case EXTI_2:
					DIO_vWritePinDirection(EXTI2_PORT,EXTI2_pin,INPUT);
					DIO_vWritePinVALUE(EXTI2_PORT,EXTI2_pin,HIGH);
					/*3- enable Interrupt 2*/
					SET_Bit(GICR,EXTI2_E);	break;

}

}
void EXTI_vDisableInterrupt(u8 A_u8ExtiPin){

	switch(A_u8ExtiPin)
	{
		case EXTI_0:	/*3- Disable Interrupt*/
			 	 	 	 CLR_Bit(GICR,EXTI0_E); 	//clear EXTI_0_E
			 	 	 	 	 	 	 	 	 	 break;

		case EXTI_1:	/*3- Disable Interrupt*/
	 	 	 	 	 	 CLR_Bit(GICR,EXTI1_E); 	//clear EXTI_1_E
	 	 	 	 	 	 	 	 	 break;
		case EXTI_2:	/*3- Disable Interrupt*/
	 	 	 	 	 	 CLR_Bit(GICR,EXTI2_E); 	//clear EXTI_2_E
	 	 	 	 	 	 	 	 	 break;

	}




}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if(G_EXTI0_Callback!=NULL){

		G_EXTI0_Callback();

	}

}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if(G_EXTI1_Callback!=NULL){

		G_EXTI1_Callback();

	}

}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{

	if(G_EXTI2_Callback!=NULL){

		G_EXTI2_Callback();

	}

}
void EXTI_vRegisterCallback(u8 A_u8ExtiPin, void(*fptr)(void)){


	switch(A_u8ExtiPin)
	{
		case EXTI_0:	G_EXTI0_Callback=fptr;	break;

		case EXTI_1:	G_EXTI1_Callback=fptr;	break;

		case EXTI_2:	G_EXTI2_Callback=fptr;	break;

		default:								break;



	}



}

