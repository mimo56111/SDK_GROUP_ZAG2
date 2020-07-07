/*
 * Switch_ECU_driver.c
 *
 * Created: 7/3/2020 2:33:07 PM
 *  Author: Mahmoud Ayman
 */ 

#include "Switch_ECU_driver.h"
void Switch_vInit(u_int8 portnum,u_int8 pinnum){
	GPIO_vSETPIN_DDR(portnum, pinnum, 0);
	GPIO_vInternal_pullupON(portnum,pinnum);
}
u_int8 Switch_u8Read(u_int8 portnum,u_int8 pinnum){
	u_int8 x;
	x=GPIO_u8ReadPIN(portnum,pinnum);
	return x;
}