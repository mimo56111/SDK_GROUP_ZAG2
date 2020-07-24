/*
 * SDK_Zag_Group2.c
 *
 * Created: 6/27/2020 12:12:32 PM
 *  Author: Mahmoud Ayman
 */ 


#include "LED_ECU_driver.h"
#include "Switch_ECU_driver.h"
#include "Data_Type.h"
#include "Register.h"
#include "Internal_EEPROM_MCAL.h"
#include "LCD_ECU.h"
#include "Keypad_ECU.h"
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void){
	OBJ x;
	LCD_Get_config(&x,EIGHT_BIT,HIGH_NIBBLE,'A','B',0,'B',1,'B',2);
	LCD_vInit();
	Keypad_vInit('C');
    u_int8 y;
	while(1){
		y = Keypad_u8check_press('C');
		while(y != NOTPRESSED){
			LCD_vsend_char(y);
			_delay_ms(500);
			y=NOTPRESSED;
		}   
		
    }
}
