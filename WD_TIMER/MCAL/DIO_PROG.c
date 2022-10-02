/*
 * DIO_PROG.c
 *
 *  Created on: Sep 16, 2022
 *      Author: abdo_
 */

#include"../LIB/std_types.h"
#include"../LIB/bit_math.h"
#include "DIO_INTERFACE.h"
#include "DIO_PRIV.h"
#include "DIO_CONFIG.h"


void DIO_vWritePortDirection(u8 A_uPortId, u8 A_uPortDirection){





	switch(A_uPortId){

	 case DIO_PORTA: DDRA=A_uPortDirection; break;
	 case DIO_PORTB: DDRB=A_uPortDirection; break;
	 case DIO_PORTC: DDRC=A_uPortDirection; break;
	 case DIO_PORTD: DDRD=A_uPortDirection; break;



	}





}

void DIO_vWritePortVALUE(u8 A_uPortId, u8 A_uPortValue){


	switch(A_uPortId){

		 case DIO_PORTA: PORTA=A_uPortValue; break;
		 case DIO_PORTB: PORTB=A_uPortValue; break;
		 case DIO_PORTC: PORTC=A_uPortValue; break;
		 case DIO_PORTD: PORTD=A_uPortValue; break;



		}


}
u8 DIO_vReadPortVALUE(u8 A_uPortId){


u8 returnportv =0;
	switch(A_uPortId){

			 case DIO_PORTA: returnportv =  PINA; break;
			 case DIO_PORTB: returnportv =  PINB; break;
			 case DIO_PORTC: returnportv =  PINC; break;
			 case DIO_PORTD: returnportv =  PIND; break;



			}

return returnportv;
}

void DIO_vWritePinDirection(u8 A_uPortId, u8 A_uPinNo, u8 A_uPinDirection)
{

	if(A_uPinDirection==OUTPUT){


		switch(A_uPortId){

		 case DIO_PORTA: SET_Bit(DDRA, A_uPinNo); break;
		 case DIO_PORTB: SET_Bit(DDRB, A_uPinNo); break;
		 case DIO_PORTC: SET_Bit(DDRC, A_uPinNo); break;
		 case DIO_PORTD: SET_Bit(DDRD, A_uPinNo); break;

         }


	}else if (A_uPinDirection==INPUT){

		switch(A_uPortId){

			 case DIO_PORTA: CLR_Bit(DDRA, A_uPinNo); break;
			 case DIO_PORTB: CLR_Bit(DDRB, A_uPinNo); break;
			 case DIO_PORTC: CLR_Bit(DDRC, A_uPinNo); break;
			 case DIO_PORTD: CLR_Bit(DDRD, A_uPinNo); break;

		}

	         }


}

void DIO_vWritePinVALUE(u8 A_uPortId, u8 A_uPinNo, u8 A_uPinValue){


	if(A_uPinValue==HIGH){


			switch(A_uPortId){

			 case DIO_PORTA: SET_Bit(PORTA , A_uPinNo); break;
			 case DIO_PORTB: SET_Bit(PORTB, A_uPinNo); break;
			 case DIO_PORTC: SET_Bit(PORTC, A_uPinNo); break;
			 case DIO_PORTD: SET_Bit(PORTD, A_uPinNo); break;

	         }


		}else if (A_uPinValue==LOW){

			switch(A_uPortId){

				 case DIO_PORTA: CLR_Bit(PORTA, A_uPinNo); break;
				 case DIO_PORTB: CLR_Bit(PORTB, A_uPinNo); break;
				 case DIO_PORTC: CLR_Bit(PORTC, A_uPinNo); break;
				 case DIO_PORTD: CLR_Bit(PORTD, A_uPinNo); break;

			}

		         }

}

u8 DIO_vReadPinVALUE(u8 A_uPortId, u8 A_uPinNo){

   u8 returnpinv= 0;
	switch(A_uPortId){

				 case DIO_PORTA: returnpinv= GET_Bit(PINA , A_uPinNo); break;
				 case DIO_PORTB: returnpinv= GET_Bit(PINB, A_uPinNo); break;
				 case DIO_PORTC: returnpinv= GET_Bit(PINC, A_uPinNo); break;
				 case DIO_PORTD: returnpinv= GET_Bit(PIND, A_uPinNo); break;

		         }



return returnpinv;








}




void DIO_vTogglePin(u8 A_uPortId, u8 A_uPinNo)
{


	switch(A_uPortId){

				 case DIO_PORTA: TOG_Bit(PORTA, A_uPinNo); break;
				 case DIO_PORTB: TOG_Bit(PORTB, A_uPinNo); break;
				 case DIO_PORTC: TOG_Bit(PORTC, A_uPinNo); break;
				 case DIO_PORTD: TOG_Bit(PORTD, A_uPinNo); break;

		         }





}










