/*
 * ADC_CONFIG.h
 *
 *  Created on: Sep 23, 2022
 *      Author: abdo_
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#define ENABLE 1
#define DISABLE 0


/*ADC VOLTAGE REF
 * VREF_VCC  	     //AVCC with external capacitor at AREF pin
 * VREF_AREF    	//AREF, Internal Vref turned off
 * VREF_Reserved   //Reserved
 * VREF_Internal  //Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
#define ADC_VREF VREF_VCC


/*ADC PRESCALER
 * PR_128
 * PR_64
 * PR_32
 * PR_16
 * PR_8
 * PR_4
 * PR_2*/
#define ADC_PR   PR_64


/*2- select data adjustment
 * RIGHT ADJUSTMENT
 * LEFT ADJUSTMENT*/
#define RIGHT_ADJUST ENABLE
#define LEFT_ADJUST	 DISABLE
#define DATA_ADJUST	RIGHT_ADJUST

/*ADC ANALOG CHANNEL*/
#define A_u8Channel A_CHANNAE_0

#define INTERRUPT_MODE  DISABLE
#define POLLING_MODE    ENABLE
#define MODE POLLING_MODE

/*ADC AUTO TRIGGER*/
#define AUTO_TRIGGER_MODE DISABLE

/*Auto Trigger Source
 * Free_Running
 * Analog_Comparator
 * EXTI0_Request
 * Timer0_COMP
 * Timer0_OVF
 * Timer_COMP_B
 * Timer1_OVF
 * Timer1_CE
  * */
#define AUTO_TRIGGER_SOURCE Free_Running

/*ADIE: ADC Interrupt Enable/Disable	*/
#define ADC_INTERRUPT_MODE DISABLE
#endif /* ADC_CONFIG_H_ */
