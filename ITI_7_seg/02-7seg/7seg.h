/*
 * 7seg.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Abdelrhaman Raafat
 */

#ifndef _7SEG_H_
#define _7SEG_H_


#define _7SEG1_PORT PORTC
#define _7SEG2_PORT PORTD

typedef enum
{
	COM_CATHODE,
	COM_ANODE
}_7SEG_TYPE;


typedef struct
{

	u8 port;
	u8 pin;

}_7seg_pin;


typedef struct {

	_7seg_pin *pins;

	_7SEG_TYPE type;

}_7seg;


///  Connections
///  PORTx:  bit-7 bit-6 bit-5 bit-4 bit-3 bit-2 bit-1 bit-0
///  7-SEG:   dot     G     F     E     D     C     B     A



#define ZERO  	0b00111111
#define ONE   	0b00000110
#define TWO   	0b01011011
#define THREE 	0b01001111
#define FOUR  	0b01100110
#define FIVE  	0b01101101
#define SIX   	0b01111101
#define SEVEN 	0b00000111
#define EIGHT 	0b01111111
#define NINE  	0b01101111
//hex digits
#define A 		0b01110111
#define b 		0b01111100
#define c 		0b01011100
#define d 		0b01011110
#define E 		0b01111001
#define F 		0b01110001

#define DOT   	0b10000000

extern const u8 seven_seg_digits[];

void _7SEG_VidInit(_7seg *me);

void _7SEG_VidDisplayNum(_7seg *me,u8 num);
//void _7SEG_VidDisplayVal(_7Seg* me, u8 value);
void _7SEG_VidDisplayOff(_7seg* me);


#endif /* 7SEG_H_ */
