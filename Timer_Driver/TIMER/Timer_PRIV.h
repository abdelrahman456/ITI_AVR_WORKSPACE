/*
 * Timer_PRIV.h
 *
 *  Created on: Sep 24, 2022
 *      Author: abdo_
 */

#ifndef TIMER_TIMER_PRIV_H_
#define TIMER_TIMER_PRIV_H_

#define WGM00	6
#define WGM01	3
#define COM00	4
#define COM01	5
#define TOV0	0
#define OCIE0	1


#define PS_NOCLK	0b000
#define PS_1		0b001
#define PS_8		0b010
#define PS_64 		0b011
#define PS_256 		0b100
#define PS_1024     0b101

#define TCNT0 	*((volatile u8*)(0x52))
#define TCCR0 	*((volatile u8*)(0x53))
#define OCR0 	*((volatile u8*)(0x5C))
#define TIMSK 	*((volatile u8*)(0x59))
#define TIFR    *((volatile u8*)(0x58))



#define WGM13	4
#define WGM12	3
#define WGM11	1
#define WGM10	0

#define COM1A1	7
#define COM1A0	6

#define TCCR1A 	*((volatile u8*)(0x4F))
#define TCCR1B	*((volatile u8*)(0x4E))
#define TCNT1 	*((volatile u16*)(0x4C))
#define OCR1A 	*((volatile u16*)(0x4A))
#define OCR1B 	*((volatile u16*)(0x48))
#define ICR1 	*((volatile u16*)(0x46))


#endif /* TIMER_TIMER_PRIV_H_ */
