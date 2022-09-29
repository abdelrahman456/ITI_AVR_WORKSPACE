/*
 * DIO_INTERFACE.h
 *
 *  Created on: Sep 16, 2022
 *      Author: abdo_
 */

#ifndef DIO_ITERFACE_H_
#define DIO_ITERFACE_H_

#define HIGH 1
#define LOW 0

#define OUTPUT 1
#define INPUT 0




#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PINA 0
#define DIO_PINB 1
#define DIO_PINC 2
#define DIO_PIND 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7



void DIO_vWritePinDirection (u8 A_uPortId, u8 A_uPinNo, u8 A_uPinDirection);

void DIO_vWritePinVALUE (u8 A_uPortId, u8 A_uPinNo, u8 A_uPinValue);
u8 DIO_vReadPinVALUE (u8 A_uPortId, u8 A_uPinNo);
void DIO_vTogglePin (u8 A_uPortId, u8 A_uPinNo);

void DIO_vWritePortDirection (u8 A_uPortId, u8 A_uPortDirection);

void DIO_vWritePortVALUE (u8 A_uPortId, u8 A_uPortValue);
u8 DIO_vReadPortVALUE (u8 A_uPortId);











#endif /* DIO_PRIV_H_ */
