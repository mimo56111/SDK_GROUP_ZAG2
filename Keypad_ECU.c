/*
 * Keypad_ECU.c
 *
 * Created: 7/19/2020 7:35:54 PM
 *  Author: Mahmoud Ayman
 */ 
#include "Keypad_ECU.h"
void Keypad_vInit(u_int8 port){
	GPIO_vSETPORT_DDR(port,0x0f); 
	GPIO_vInternal_pullupON(port,4);
	GPIO_vInternal_pullupON(port,5);
	GPIO_vInternal_pullupON(port,6);
	GPIO_vInternal_pullupON(port,7);
}

u_int8 Keypad_u8check_press(u_int8 port){
	//u_int8 arr[4][4]={{'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}}; //real keypad
	u_int8 arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}}; //proteus Keypad
	u_int8 row , coloumn, x;
	u_int8 return_val= NOTPRESSED;
	for(row = 0; row < 4; row++){
		GPIO_vWritePIN(port,0,1);
		GPIO_vWritePIN(port,1,1);
		GPIO_vWritePIN(port,2,1);
		GPIO_vWritePIN(port,3,1);
		GPIO_vWritePIN(port,row,0);
		for(coloumn = 0; coloumn < 4; coloumn++){
			x=GPIO_u8ReadPIN(port,(coloumn + 4));
			if(0 == x){
				return_val=arr[row][coloumn];
				break;
			}
		}
		if(0==x){
			break;
		}
	}
	return return_val;
}