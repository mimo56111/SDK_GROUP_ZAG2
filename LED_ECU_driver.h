/*
 * LED_ECU_driver.h
 *
 * Created: 7/3/2020 2:12:51 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef LED_ECU_DRIVER_H_
#define LED_ECU_DRIVER_H_

#include "GPIO.h"
#include "Data_Type.h"
/*
	return: void
	argument: portnum as unsigned char and pinnum as unsigned char
	functionality: Set pin which led is connected as an output pin.
*/
void LED_vInit(u_int8 portnum,u_int8 pinnum);
void LED_von(u_int8 portnum,u_int8 pinnum);
void LED_voff(u_int8 portnum,u_int8 pinnum);
void LED_vtoggle(u_int8 portnum,u_int8 pinnum);


#endif /* LED_ECU_DRIVER_H_ */