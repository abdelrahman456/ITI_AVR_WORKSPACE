/*
 * WD_PRIVATE.h
 *
 *  Created on: Oct 2, 2022
 *      Author: abdo_
 */

#ifndef WD_T_WD_PRIVATE_H_
#define WD_T_WD_PRIVATE_H_

#define WDTCR *((volatile u8*)(0x41))

#define WDE 	3 	//Bit 3 – WDE: Watchdog Enable
#define WDTOE   4	//Bit 4 – WDTOE: Watchdog Turn-off Enable
					//Bits 2..0 – WDP2, WDP1, WDP0: Watchdog Timer Prescaler 2, 1, and 0

#define WDT_PS_163ms	0b000 //16.3 ms
#define WDT_PS_325ms	0b001 //32.5 ms
#define WDT_PS_65ms		0b010 //65 	 ms
#define WDT_PS_13s		0b011 //0.13 s
#define WDT_PS_26s		0b100 //0.26 s
#define WDT_PS_52s		0b101 //0.52 s
#define WDT_PS_1s		0b110 //1 	 s
#define WDT_PS_21s		0b111 //2.1  s
#endif /* WD_T_WD_PRIVATE_H_ */
