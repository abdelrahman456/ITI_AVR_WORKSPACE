/*
 * EXTI_INTERFACE.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Abdelrhaman Raafat
 */

#ifndef EXTI_EXTI_INTERFACE_H_
#define EXTI_EXTI_INTERFACE_H_

#define EXTI_0	0
#define EXTI_1	1
#define EXTI_2	2

#define low_level	0
#define Any_logical_change 1
#define falling_edge	2
#define rising_edgel	3


void EXTI_vInit(void);
void EXTI_vSetSenseCtr( u8 A_u8ExtiPin, u8 A_u8SenseCtrl);
void EXTI_vEnableInterrupt(u8 A_u8ExtiPin);
void EXTI_vDisableInterrupt(u8 A_u8ExtiPin);
void EXTI_vRegisterCallback(u8 A_u8ExtiPin, void(*fptr)(void));
#endif /* EXTI_EXTI_INTERFACE_H_ */
