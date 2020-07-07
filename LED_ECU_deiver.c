/*
 * LED_ECU_deiver.c
 *
 * Created: 7/3/2020 2:13:15 PM
 *  Author: Mahmoud Ayman
 */ 
#include "LED_ECU_driver.h"
void LED_vInit(u_int8 portnum,u_int8 pinnum){
	GPIO_vSETPIN_DDR(portnum,pinnum,1);
}
void LED_von(u_int8 portnum,u_int8 pinnum){
	GPIO_vWritePIN(portnum,pinnum,1);
}
void LED_voff(u_int8 portnum,u_int8 pinnum){
	GPIO_vWritePIN(portnum,pinnum,0);
}
void LED_vtoggle(u_int8 portnum,u_int8 pinnum){
	u_int8 x=2;
	x=GPIO_u8ReadPIN(portnum,pinnum);
	if(x==1){
		LED_voff(portnum,pinnum);
	}else{
		LED_von(portnum,pinnum);
	}
}