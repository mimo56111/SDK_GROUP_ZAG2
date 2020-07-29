/*
 * GPIO.h
 *
 * Created: 6/27/2020 12:31:42 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef GPIO_H_
#define GPIO_H_
#include "Data_Type.h"
#include "Register.h"
#include "std_macros.h"
void GPIO_vSETPIN_DDR(u_int8 portnum , u_int8 pinnum , u_int8 dir);
void GPIO_vSETPORT_DDR(u_int8 portnum, u_int8 dir);
void GPIO_vWritePIN(u_int8 portnum , u_int8 pinnum , u_int8 val);
void GPIO_vWritePORT(u_int8 portnum , u_int8 val);

u_int8 GPIO_u8ReadPIN(u_int8 portnum , u_int8 pinnum);
u_int8 GPIO_u8ReadPORT(u_int8 portnum);
 
void GPIO_vInternal_pullupON(u_int8 portnum , u_int8 pinnum);
void GPIO_vInternal_pullupOFF(u_int8 portnum , u_int8 pinnum);
void GPIO_vLow_Nibble_set_DDR(u_int8 portnum, u_int8 dir);
void GPIO_vLow_Nibble_write(u_int8 portnum, u_int8 val);
void GPIO_vHigh_Nibble_set_DDR(u_int8 portnum, u_int8 dir);
void GPIO_vHigh_Nibble_write(u_int8 portnum, u_int8 val);
#endif /* GPIO_H_ */