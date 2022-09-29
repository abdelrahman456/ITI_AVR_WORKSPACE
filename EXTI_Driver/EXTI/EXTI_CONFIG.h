/*
 * EXTI_CONFIG.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Abdelrhaman Raafat
 */

#ifndef EXTI_EXTI_CONFIG_H_
#define EXTI_EXTI_CONFIG_H_


#define ENABLE 1
#define DISABLE 0

/* number of EXTI*/
#define EXTI_0	0
#define EXTI_1 	1
#define EXTI_2	2

/* number of EXTI*/
#define EXTI_Init_0	ENABLE
#define EXTI_Init_1	DISABLE
#define EXTI_Init_2	DISABLE
/*External Interrupt_ PIN
 * PORTD */
#define EXTI_PIN EXTI0_pin
#define EXTI_PORT EXTI0_PORT

#define EXTI2_PORT 2
/*External Interrupt_0 Sense Control 0*/
#define EXTI0_SC	EXTI0_falling_edge
#define SC_0 1
/*External Interrupt_1 Sense Control */
#define EXTI1_SC	EXTI1_falling_edge
#define SC_1 0

/*External Interrupt_1 Sense Control */
#define EXTI2_SC	EXTI2_falling_edge
#endif /* EXTI_EXTI_CONFIG_H_ */
