/*
 * KEYPAD_INTERFACE.h
 *
 *  Created on: Sep 22, 2022
 *      Author: abdo_
 */

#ifndef KEYPAD_KEYPAD_INTERFACE_H_
#define KEYPAD_KEYPAD_INTERFACE_H_

#define KEYPAD_PORT DIO_PORTC
#define ROWS 4
#define COLUMNS 4
#define DEBOUNCE_DELAY 5



void KEYPAD_vInit(void);
u8 KEYPAD_vGETPress(void);

#endif /* KEYPAD_KEYPAD_INTERFACE_H_ */
