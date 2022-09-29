/*
 * EXTI_PRIVATE.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Abdelrhaman Raafat
 */

#ifndef EXTI_EXTI_PRIVATE_H_
#define EXTI_EXTI_PRIVATE_H_

/*External Interrupt_0 PIN2
 * PORTD */
#define EXTI0_pin	2
#define EXTI0_PORT 3

/*External Interrupt_1 PIN3
 * PORTD */
#define EXTI1_pin	3
#define EXTI1_PORT 3

/*External Interrupt_1 PIN3
 * PORTD */
#define EXTI2_pin	2
#define EXTI2_PORT 2

/*Bit 1, 0 – ISC01, ISC00: Interrupt Sense Control 0 Bit 1 and Bit 0*/
#define EXTI0_low_level 		 0b00
#define EXTI0_Any_logical_change 0b01
#define EXTI0_falling_edge		 0b10
#define EXTI0_rising_edgel 		 0b11

/*Bit 3, 2 – ISC11, ISC10: Interrupt Sense Control 1*/
#define EXTI1_low_level 		 (0b00<<2)
#define EXTI1_Any_logical_change (0b01<<2)
#define EXTI1_falling_edge		 (0b10<<2)
#define EXTI1_rising_edgel 		 (0b11<<2)

/*Bit 6 – ISC2: Interrupt Sense Control 2*/
#define EXTI2_falling_edge 		 (0b0<<6)
#define EXTI2_rising_edgel 		 (0b1<<6)

/*Bit 7 – INT1: External Interrupt Request 1 Enable*/
#define EXTI1_E 7

/*Bit 6 – INT0: External Interrupt Request 0 Enable*/
#define EXTI0_E 6

/*Bit 5 – INT2: External Interrupt Request 2 Enable*/
#define EXTI2_E 5

#define MCUCR	*((volatile u8 *)(0x55))
#define MCUCSR	*((volatile u8 *)(0x54))
#define GICR	*((volatile u8 *)(0x5B))
#define GIFR	*((volatile u8 *)(0x5A))

#endif /* EXTI_EXTI_PRIVATE_H_ */
