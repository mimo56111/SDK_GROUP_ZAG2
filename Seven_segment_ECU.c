/*
 * Seven_segment_ECU.c
 *
 * Created: 7/6/2020 12:21:27 PM
 *  Author: Mahmoud Ayman
 */ 
#include "Seven_segment_ECU.h"
#define  Low_Nibble 0
#define  High_Nibble 1
#define  OUTPUT 1
#define INPUT 0 
u_int8 mode;
u_int8 nibble;
u_int8 port;
void Seven_segment_Init(u_int8 Mode,u_int8 portnum,u_int8 Nibble){
	if (Mode== EIGHT_BIT){
		GPIO_vSETPORT_DDR(portnum,0xff);
		mode = Mode;
		nibble = Nibble;
		port =portnum;
	}else if(Mode == FOUR_BIT){
		if(Nibble==Low_Nibble){
			GPIO_vLow_Nibble_set_DDR(portnum,OUTPUT);
			/*GPIO_vSETPIN_DDR(portnum,0,1);
			GPIO_vSETPIN_DDR(portnum,1,1);
			GPIO_vSETPIN_DDR(portnum,2,1);
			GPIO_vSETPIN_DDR(portnum,3,1);*/
		}else if(Nibble == High_Nibble){
			/*GPIO_vSETPIN_DDR(portnum,4,1);
			GPIO_vSETPIN_DDR(portnum,5,1);
			GPIO_vSETPIN_DDR(portnum,6,1);
			GPIO_vSETPIN_DDR(portnum,7,1);*/
			GPIO_vHigh_Nibble_set_DDR(portnum,OUTPUT);
		}			
		
	}
}
void Seven_segment_Display(u_int8 Val){
	if (mode == FOUR_BIT){
		if (nibble == Low_Nibble){
			GPIO_vLow_Nibble_write(port,Val);
		}else if(nibble == High_Nibble){
			GPIO_vHigh_Nibble_write(port,Val);
		}
	}else if(mode == EIGHT_BIT){
		if(Val >=0 && Val <= 9){
			u_int8 seven_segment_arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
			GPIO_vWritePORT(port,seven_segment_arr[Val]);
		}else{
			#define A 0
			#define B 1
			#define C 2
			#define D 3
			#define E 4
			#define F 5
			u_int8 arr[6]={0x77,0x1f,0x39,0x5E,0x79,0x71};
			GPIO_vWritePORT(port,arr[Val]);
		}
	}
}	