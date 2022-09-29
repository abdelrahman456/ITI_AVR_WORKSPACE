/*
 * Timer.INTERFACE.h
 *
 *  Created on: Sep 24, 2022
 *      Author: abdo_
 */

#ifndef TIMER_TIMER_INTERFACE_H_
#define TIMER_TIMER_INTERFACE_H_

#define TIMER0	0
#define TIMER1	1

void TIMERS_vInit(void);
void TIMERS_vSetBusyWait_synch(/*TIMER ID*/u32 A_u32Ticks);

void TIMERS_vStartTimer(u8 A_u8TimerId);
void TIMERS_vStopTimer(u8 A_u8TimerId);
void TIMERS_vStetCallback(/*TIMER ID*/ void(*fptr)(void));

void TIMERS_vSetPreloadValue(u8 A_u8TimerId, u16 A_u16Preload);
void TIMERS_vSetCompareMatchValue(u8 A_u8TimerId , u16 A_u16OcrVal    );
void TIMERS_vSetICR1(u16 A_16IcrValue);

#endif /* TIMER_TIMER_INTERFACE_H_ */
