/*
 * Seven_segment_ECU.h
 *
 * Created: 7/6/2020 12:21:05 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef SEVEN_SEGMENT_ECU_H_
#define SEVEN_SEGMENT_ECU_H_
#include "GPIO.h"
#include "Data_Type.h"

#define EIGHT_BIT 0
#define FOUR_BIT  1

void Seven_segment_Init(u_int8 Mode,u_int8 portnum,u_int8 Nibble); 

void Seven_segment_Display(u_int8 Val);


#endif /* SEVEN_SEGMENT_ECU_H_ */