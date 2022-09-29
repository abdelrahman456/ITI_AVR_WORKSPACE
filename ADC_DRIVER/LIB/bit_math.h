/*
 * bit_math.h
 *
 *  Created on: Aug 19, 2021
 *      Author: abdo
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

#define SET_Bit(VAR,BITNO) (VAR)|= (1<<(BITNO))
#define CLR_Bit(VAR,BITNO) (VAR)&= ~(1<<(BITNO))
#define TOG_Bit(VAR,BITNO) (VAR)^= (1<<(BITNO))
#define GET_Bit(VAR,BITNO) (((VAR) >> (BITNO)) & 1)
#define IS_BIT_CLEAR(VAR,BITNO) !((VAR&(1<<BITNO))>>BITNO)

#endif /* LIB_BIT_MATH_H_ */
