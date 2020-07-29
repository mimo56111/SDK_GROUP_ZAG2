/*
 * GPIO.c
 *
 * Created: 6/27/2020 12:32:11 PM
 *  Author: Mahmoud Ayman
 */ 
#include "GPIO.h"
#define OUTPUT 1
#define INPUT  0
#define HIGH   1
#define LOW    0
void GPIO_vSETPIN_DDR(u_int8 portnum , u_int8 pinnum , u_int8 dir){
	switch(portnum){
		case 'A':
		case 'a':
			if (dir==OUTPUT){
				SEt_BIT(XDDRA,pinnum);
			}else{
				CLR_BIT(XDDRA,pinnum);
			}
			break;
		case 'B':
		case 'b':
			if (dir==OUTPUT){
				SEt_BIT(XDDRB,pinnum);
			}else{
				CLR_BIT(XDDRB,pinnum);
			}
			break;
		case 'C':
		case 'c':
			if (dir==OUTPUT){
				SEt_BIT(XDDRC,pinnum);
			}else{
				CLR_BIT(XDDRC,pinnum);
			}
			break;
		case 'D':
		case 'd':
			if (dir==OUTPUT){
				SEt_BIT(XDDRD,pinnum);
			}else{
				CLR_BIT(XDDRD,pinnum);
			}
			break;
	}
}
void GPIO_vSETPORT_DDR(u_int8 portnum, u_int8 dir){
	switch(portnum){
		case 'A':
		case 'a':
			XDDRA=dir;
			break;
		case 'B':
		case 'b':
			XDDRB=dir;
			break;
		case 'C':
		case 'c':
			XDDRC=dir;
			break;
		case 'D':
		case 'd':
			XDDRD=dir;
			break;
	}
}

void GPIO_vWritePIN(u_int8 portnum , u_int8 pinnum , u_int8 val){
	switch(portnum){
		case 'A':
		case 'a':
			if (val==HIGH){
				SEt_BIT(XPORTA,pinnum);
			}else{
				CLR_BIT(XPORTA,pinnum);
			}
			break;
		case 'B':
		case 'b':
			if (val==HIGH){
				SEt_BIT(XPORTB,pinnum);
			}else{
				CLR_BIT(XPORTB,pinnum);
			}
			break;
		case 'C':
		case 'c':
			if (val==HIGH){
				SEt_BIT(XPORTC,pinnum);
			}else{
				CLR_BIT(XPORTC,pinnum);
			}
			break;
		case 'D':
		case 'd':
			if (val==HIGH){
				SEt_BIT(XPORTD,pinnum);
			}else{
				CLR_BIT(XPORTD,pinnum);
			}
			break;
	}
}
void GPIO_vWritePORT(u_int8 portnum , u_int8 val){
	switch(portnum){
		case 'A':
		case 'a':
			XPORTA=val;
			break;
		case 'B':
		case 'b':
			XPORTB=val;
			break;
		case 'C':
		case 'c':
			XPORTC=val;
			break;
		case 'D':
		case 'd':
			XPORTD=val;
			break;
	}
}
u_int8 GPIO_u8ReadPIN(u_int8 portnum , u_int8 pinnum){
	u_int8 ret;
	switch(portnum){
		case 'A':
		case 'a':
			ret=Read_Bit(XPINA,pinnum);
			break;
		case 'B':
		case 'b':
			ret=Read_Bit(XPINB,pinnum);
			break;
		case 'C':
		case 'c':
			ret=Read_Bit(XPINC,pinnum);
			break;
		case 'D':
		case 'd':
			ret=Read_Bit(XPIND,pinnum);
			break;
	}	
	return ret;
}
u_int8 GPIO_u8ReadPORT(u_int8 portnum){
	u_int8 ret;
	switch(portnum){
		case 'A':
		case 'a':
			ret=XPINA;
			break;
		case 'B':
		case 'b':
			ret=XPINB;
			break;
		case 'C':
		case 'c':
			ret=XPINC;
			break;
		case 'D':
		case 'd':
			ret=XPIND;
			break;
	}
return ret;
}
void GPIO_vInternal_pullupON(u_int8 portnum , u_int8 pinnum){
	GPIO_vWritePIN(portnum,pinnum,1);
}
void GPIO_vInternal_pullupOFF(u_int8 portnum , u_int8 pinnum){
	GPIO_vWritePIN(portnum,pinnum,0);
}
void GPIO_vLow_Nibble_set_DDR(u_int8 portnum, u_int8 dir){
	if (dir == OUTPUT){
		GPIO_vSETPIN_DDR(portnum,0,OUTPUT);
		GPIO_vSETPIN_DDR(portnum,1,OUTPUT);
		GPIO_vSETPIN_DDR(portnum,2,OUTPUT);
		GPIO_vSETPIN_DDR(portnum,3,OUTPUT);
	}else{
		GPIO_vSETPIN_DDR(portnum,0,INPUT);
		GPIO_vSETPIN_DDR(portnum,1,INPUT);
		GPIO_vSETPIN_DDR(portnum,2,INPUT);
		GPIO_vSETPIN_DDR(portnum,3,INPUT);
	}
}
void GPIO_vLow_Nibble_write(u_int8 portnum, u_int8 val){
	val &= 0x0f;   
	switch(portnum){
		case 'A':
		case 'a':
			XPORTA &= 0xf0;   
			XPORTA |=val;
			break;	
		case 'B':
		case 'b':
			XPORTB &= 0xf0;
			XPORTB |=val;
			break;
		case 'C':
		case 'c':
			XPORTC &= 0xf0;
			XPORTC |=val;
			break;
		case 'D':
		case 'd':
			XPORTD &= 0xf0;
			XPORTD |=val;
			break;
	}
}
void GPIO_vHigh_Nibble_set_DDR(u_int8 portnum, u_int8 dir){
	if (dir == OUTPUT){
		GPIO_vSETPIN_DDR(portnum,4,OUTPUT);
		GPIO_vSETPIN_DDR(portnum,5,OUTPUT);
		GPIO_vSETPIN_DDR(portnum,6,OUTPUT);
		GPIO_vSETPIN_DDR(portnum,7,OUTPUT);
	}else{
		GPIO_vSETPIN_DDR(portnum,4,INPUT);
		GPIO_vSETPIN_DDR(portnum,5,INPUT);
		GPIO_vSETPIN_DDR(portnum,6,INPUT);
		GPIO_vSETPIN_DDR(portnum,7,INPUT);
	}
}
void GPIO_vHigh_Nibble_write(u_int8 portnum, u_int8 val){
	val &=0xf0;
	switch(portnum){
		case 'A':
		case 'a':
			XPORTA &= 0x0f;
			XPORTA |=val;
			break;
		case 'B':
		case 'b':
			XPORTB &= 0x0f;
			XPORTB |=val;
			break;
		case 'C':
		case 'c':
			XPORTC &= 0x0f;
			XPORTC |=val;
			break;
		case 'D':
		case 'd':
			XPORTD &= 0x0f;
			XPORTD |=val;
			break;
	}
}