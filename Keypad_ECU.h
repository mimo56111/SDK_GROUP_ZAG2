/*
 * Keypad_ECU.h
 *
 * Created: 7/19/2020 7:35:40 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef KEYPAD_ECU_H_
#define KEYPAD_ECU_H_
#include "GPIO.h"
#include "Data_Type.h"

#define NOTPRESSED 0xff

void Keypad_vInit(u_int8 port);

u_int8 Keypad_u8check_press(u_int8 port);



#endif /* KEYPAD_ECU_H_ */