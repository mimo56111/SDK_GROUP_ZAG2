/*
 * LCD_ECU.c
 *
 * Created: 7/19/2020 4:57:29 PM
 *  Author: Mahmoud Ayman
 */ 
#include "LCD_ECU.h"

OBJ *ip;
void LCD_Get_config(OBJ *ptr, u_int8 mode, u_int8 nibble, u_int8 port, u_int8 Rs_port, u_int8 rs_pin, u_int8 rw_port, u_int8 rw_pin, u_int8 en_port, u_int8 en_pin){
	ip=ptr;
	ip->Mode=mode;
	ip->Nibble=nibble;
	ip->LCD_port=port;
	ip->RS_port=Rs_port;
	ip->RS_pin=rs_pin;
	ip->RW_port=rw_port;
	ip->RW_pin=rw_pin;
	ip->EN_port=en_port;
	ip->EN_pin=en_pin;
}
void LCD_vInit(void){
	if(ip!=0){
		_delay_ms(200);
		GPIO_vSETPIN_DDR(ip->RS_port,ip->RS_pin,1);
		GPIO_vSETPIN_DDR(ip->RW_port,ip->RW_pin,1);
		GPIO_vSETPIN_DDR(ip->EN_port,ip->EN_pin,1);
		if(ip->Mode==EIGHT_BIT){
			GPIO_vSETPORT_DDR(ip->LCD_port,0xff);
			GPIO_vWritePIN(ip->RW_port,ip->RW_pin,0);
			_delay_ms(15);
			LCD_vsend_cmd(LCD_8Bit_2Lines);
			_delay_ms(1);
			LCD_vsend_cmd(LCD_DISP_ON_CURSOR_ON);
			_delay_ms(1);
			LCD_vsend_cmd(LCD_CLEAR_SCREEN);
			_delay_ms(10);
			LCD_vsend_cmd(LCD_ENTRY_MODE);
			_delay_ms(1);
		}else{
			if(ip->Nibble==HIGH_NIBBLE){
				GPIO_vHigh_Nibble_set_DDR(ip->LCD_port,1);
				GPIO_vWritePIN(ip->RW_port,ip->RW_pin,0);
				_delay_ms(15);
				LCD_vsend_cmd(LCD_4Bit_2Lines);
				_delay_ms(1);
				LCD_vsend_cmd(LCD_DISP_ON_CURSOR_ON);
				_delay_ms(1);
				LCD_vsend_cmd(LCD_CLEAR_SCREEN);
				_delay_ms(10);
				LCD_vsend_cmd(LCD_ENTRY_MODE);
				_delay_ms(1);
			}else{
				GPIO_vLow_Nibble_set_DDR(ip->LCD_port,1);
				GPIO_vWritePIN(ip->RW_port,ip->RW_pin,0);
				_delay_ms(15);
				LCD_vsend_cmd(LCD_4Bit_2Lines);
				_delay_ms(1);
				LCD_vsend_cmd(LCD_DISP_ON_CURSOR_ON);
				_delay_ms(1);
				LCD_vsend_cmd(LCD_CLEAR_SCREEN);
				_delay_ms(10);
				LCD_vsend_cmd(LCD_ENTRY_MODE);
				_delay_ms(1);
			}
		}
	}
}

void LCD_vsend_cmd(u_int8 cmd){
	if(ip->Mode==EIGHT_BIT){
		GPIO_vWritePORT(ip->LCD_port,cmd);
		GPIO_vWritePIN(ip->RS_port,ip->RS_pin,0);
		LCD_send_falling_edge();
	}else{
		if(ip->Nibble==HIGH_NIBBLE){
			GPIO_vHigh_Nibble_write(ip->LCD_port,cmd>>4);  
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,0); 
			LCD_send_falling_edge();
			GPIO_vHigh_Nibble_write(ip->LCD_port,cmd);
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,0);
			LCD_send_falling_edge();
			_delay_ms(1);
		}else{
			GPIO_vLow_Nibble_write(ip->LCD_port,cmd>>4);
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,0);
			LCD_send_falling_edge();
			GPIO_vLow_Nibble_write(ip->LCD_port,cmd);
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,0);
			LCD_send_falling_edge();
			_delay_ms(1);
		}
	}
}

static void LCD_send_falling_edge(void){
	GPIO_vWritePIN(ip->EN_port,ip->EN_pin,1);
	_delay_ms(2);
	GPIO_vWritePIN(ip->EN_port,ip->EN_pin,0);
}
void LCD_vsend_char(u_int8 data){
	if(ip->Mode==EIGHT_BIT){
		GPIO_vWritePORT(ip->LCD_port,data);
		GPIO_vWritePIN(ip->RS_port,ip->RS_pin,1);
		LCD_send_falling_edge();
		_delay_ms(1);
	}else{
		if (ip->Nibble==HIGH_NIBBLE){
			GPIO_vHigh_Nibble_write(ip->LCD_port,data>>4);
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,1);
			LCD_send_falling_edge();
			GPIO_vHigh_Nibble_write(ip->LCD_port,data);
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,1);
			LCD_send_falling_edge();
			_delay_ms(1);
		}else{
			GPIO_vLow_Nibble_write(ip->LCD_port,data>>4);
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,1);
			LCD_send_falling_edge();
			GPIO_vLow_Nibble_write(ip->LCD_port,data);
			GPIO_vWritePIN(ip->RS_port,ip->RS_pin,1);
			LCD_send_falling_edge();
			_delay_ms(1);
		}
	}
}

void LCD_vsend_string(u_int8 *ptr){
	while((*ptr)!='\0'){
		LCD_vsend_char(*ptr);
		ptr++;
	}
}

void LCD_vMove_Cursor(u_int8 raw, u_int8 position){
	u_int8 data;
	if(raw > 3 || raw <1 || position > 16 ||position < 1){
		data= 0x80;
	}else if(1== raw){
		data = 0x80 + (position - 1);
	}else if(2 == raw){
		data = 0xC0 + (position - 1);
	} 
	LCD_vsend_cmd(data);
	_delay_ms(1);
}

void LCD_vclear_screen(){
	LCD_vsend_cmd(LCD_CLEAR_SCREEN);
	_delay_ms(10);
}

void LCD_vsend_number(u_int32 Number){
	u_int8 str[7];
	sprintf(str,"%d",Number);
	LCD_vsend_string(str);
}

void LCD_vsend_real_number(float64 Number){
	u_int8 str [16];
	u_int8 *tmpsign = (Number < 0)? "-" : "";
	float32 tmpval = (Number < 0)? -Number : Number;
	s_int32 tmpint1 = tmpval;
	float32 tmpfrac = tmpval - tmpint1;
	s_int32 tmpint2 = tmpfrac * 10000;
	sprintf(str,"%s%d.%04d",tmpsign,tmpint1,tmpint2);
	LCD_vsend_string(str);
}