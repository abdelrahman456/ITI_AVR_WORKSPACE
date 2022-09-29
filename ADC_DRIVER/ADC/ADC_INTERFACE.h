/*
 * ADC_INTERFACE.h
 *
 *  Created on: Sep 23, 2022
 *      Author: abdo_
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

void ADC_vInit(void);
u16 ADC_u16Read(u8 ADC_u8Channel);
void ADC_vSetCallback(void (*fptr)(void));
void ADC_EnableInterrupt(void);
void ADC_DisableInterrupt(void);
void ADC_vSelectChannel(u8 ADC_u8Channel);
void ADC_vStartConversion(u8 ADC_u8Channel);
u16 ADC_u16GetValue(u8 ADC_u8Channel);
#endif /* ADC_INTERFACE_H_ */
