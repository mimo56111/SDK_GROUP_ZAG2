/*
 * Switch_ECU_driver.h
 *
 * Created: 7/3/2020 2:32:40 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef SWITCH_ECU_DRIVER_H_
#define SWITCH_ECU_DRIVER_H_

#include "GPIO.h"
#include "Data_Type.h"

void Switch_vInit(u_int8 portnum,u_int8 pinnum);
u_int8 Switch_u8Read(u_int8 portnum,u_int8 pinnum);


#endif /* SWITCH_ECU_DRIVER_H_ */