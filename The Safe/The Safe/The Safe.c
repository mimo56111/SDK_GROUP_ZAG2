/*
 * The_Safe.c
 *
 * Created: 7/24/2020 5:02:22 PM
 *  Author: Mahmoud Ayman
 */ 


#include "LCD_ECU.h"
#include "LED_ECU_driver.h"
#include "Keypad_ECU.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/*************EEPROM Password Address****************************/
#define EEPROM_PASSWORD_LOCATION1  0x11
#define EEPROM_PASSWORD_LOCATION2  0x12
#define EEPROM_PASSWORD_LOCATION3  0x13
#define EEPROM_PASSWORD_LOCATION4  0x14
#define STATUS  0x06
/****************************************************************/
#define TRIES 3

u_int8 arr_password[4];
int main(void){
	u_int8 val=NOTPRESSED;
	u_int8 tries = TRIES;
	u_int8 hash_password=200;
	OBJ x;
	u_int8 a,s,d,f;
	u_int8 flag =0;
	Keypad_vInit('C');
	LCD_Get_config(&x,EIGHT_BIT,LOW_NIBBLE,'A','B',0,'B',1,'B',2);
	LCD_vInit();
	LED_vInit('D',5);
	if (EEPROM_u8Read(STATUS)==0xff){
		LCD_vsend_string("Set Password:");
		LCD_vMove_Cursor(2,1);
		do{
			val=Keypad_u8check_press('C');
		}while(val==NOTPRESSED);
		LCD_vsend_char(val);
		_delay_ms(500);
		LCD_vMove_Cursor(2,1);
		LCD_vsend_char('*'); 
		_delay_ms(500);
		val=hash_password^val;
		EEPROM_vWrite(EEPROM_PASSWORD_LOCATION1,val);
		val=NOTPRESSED;
		do{
			val=Keypad_u8check_press('C');
		}while(val==NOTPRESSED);
		LCD_vsend_char(val);
		_delay_ms(500);
		LCD_vMove_Cursor(2,2);
		LCD_vsend_char('*');
		_delay_ms(500);
		val=hash_password^val;
		EEPROM_vWrite(EEPROM_PASSWORD_LOCATION2,val);
		val=NOTPRESSED;
		do{
			val=Keypad_u8check_press('C');
		}while(val==NOTPRESSED);
		LCD_vsend_char(val);
		_delay_ms(500);
		LCD_vMove_Cursor(2,3);
		LCD_vsend_char('*');
		_delay_ms(500);
		val=hash_password^val;
		EEPROM_vWrite(EEPROM_PASSWORD_LOCATION3,val);
		val=NOTPRESSED;
		do{
			val=Keypad_u8check_press('C');
		}while(val==NOTPRESSED);
		LCD_vsend_char(val);
		_delay_ms(500);
		LCD_vMove_Cursor(2,4);
		LCD_vsend_char('*');
		_delay_ms(500);
		val=hash_password^val;
		EEPROM_vWrite(EEPROM_PASSWORD_LOCATION4,val);
		val=NOTPRESSED;
		EEPROM_vWrite(STATUS,0x00);
	}
	while(flag==0){
		arr_password[0]=arr_password[1]=arr_password[2]=arr_password[3]=NOTPRESSED;
		LCD_vclear_screen();
		LCD_vsend_string("Enter Password:");
		LCD_vMove_Cursor(2,1);
		do{
			arr_password[0]=Keypad_u8check_press('C');
		}while(arr_password[0]==NOTPRESSED);
		LCD_vsend_char(arr_password[0]);
		_delay_ms(500);
		LCD_vMove_Cursor(2,1);
		LCD_vsend_char('*');
		_delay_ms(500);
		do{
			arr_password[1]=Keypad_u8check_press('C');
		}while(arr_password[1]==NOTPRESSED);
		LCD_vsend_char(arr_password[1]);
		_delay_ms(500);
		LCD_vMove_Cursor(2,2);
		LCD_vsend_char('*');
		_delay_ms(500);
		do{
			arr_password[2]=Keypad_u8check_press('C');
		}while(arr_password[2]==NOTPRESSED);
		LCD_vsend_char(arr_password[2]);
		_delay_ms(500);
		LCD_vMove_Cursor(2,3);
		LCD_vsend_char('*');
		_delay_ms(500);
		do{
			arr_password[3]=Keypad_u8check_press('C');
		}while(arr_password[3]==NOTPRESSED);
		LCD_vsend_char(arr_password[3]);
		_delay_ms(500);
		LCD_vMove_Cursor(2,4);
		LCD_vsend_char('*');
		_delay_ms(500);
		a=EEPROM_u8Read(EEPROM_PASSWORD_LOCATION1);
		a^=hash_password;
		s=EEPROM_u8Read(EEPROM_PASSWORD_LOCATION2);
		s^=hash_password;
		d=EEPROM_u8Read(EEPROM_PASSWORD_LOCATION3);
		d^=hash_password;
		f=EEPROM_u8Read(EEPROM_PASSWORD_LOCATION4);
		f^=hash_password;
		if(a==arr_password[0]&&s==arr_password[1]&&d==arr_password[2]&&f==arr_password[3]){
			LCD_vclear_screen();
			LCD_vsend_string("Right Password");
			LCD_vMove_Cursor(2,1);
			LCD_vsend_string("Safe is Open");
			LED_von('D',5);
			flag=1;
		}else{
			tries-=1;
			if(tries>0){
				LCD_vclear_screen();
				LCD_vsend_string("Wrong Password");
				LCD_vMove_Cursor(2,1);
				LCD_vsend_string("Tries left=");
				LCD_vsend_number(tries);
				_delay_ms(1000);
			}else{
				LCD_vclear_screen();
				LCD_vsend_string("Wrong Password");
				LCD_vMove_Cursor(2,1);
				LCD_vsend_string("Tries left=");
				LCD_vsend_number(tries);
				_delay_ms(1000);
				LCD_vclear_screen();
				LCD_vsend_string("Safe is Closed");
				_delay_ms(1000);
				break;
			}
		}
	}
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}