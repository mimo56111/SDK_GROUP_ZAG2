/*
 * SDK_Zag_Group2.c
 *
 * Created: 6/27/2020 12:12:32 PM
 *  Author: Mahmoud Ayman
 */ 


#include "LED_ECU_driver.h"
#include "Switch_ECU_driver.h"
#include "Data_Type.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void){
	LED_vInit('A',6);
	Switch_vInit('D',1);
    while(1){
        if (Switch_u8Read('D',1)==0){
			LED_von('A',6);
			_delay_ms(300);
			LED_voff('A',6);
        }else{
			LED_voff('A',6);
		}
    }
}