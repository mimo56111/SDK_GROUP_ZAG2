/*
 * LCD_ECU.h
 *
 * Created: 7/19/2020 4:57:11 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef LCD_ECU_H_
#define LCD_ECU_H_
#include "GPIO.h"
#include "Data_Type.h"
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define LCD_4Bit_2Lines  0x28
#define LCD_8Bit_2Lines  0x38

/*******************LCD Commands**********************/
#define LCD_MOVE_DISP_RIGHT        0x1C
#define LCD_MOVE_DISP_LEFT         0x18
#define LCD_MOVE_CURSOR_RIGHT      0x14
#define LCD_MOVE_CURSOR_LEFT       0x10
#define LCD_DISP_OFF_CURSOR_OFF    0x08
#define LCD_DISP_ON_CURSOR_ON      0x0E
#define LCD_DISP_ON_CURSOR_BLINK   0x0F
#define LCD_ENTRY_MODE             0x06
#define LCD_ENTRY_DEC              0x04
#define LCD_ENTRY_DEC_SHIFT        0x05
#define LCD_ENTRY_INC              0x06
#define LCD_ENTRY_INC_SHIFT        0x07
#define LCD_BEGIN_AT_FIRST_RAW     0x80
#define LCD_BEGIN_AT_SECOND_RAW    0xC0
#define LCD_CLEAR_SCREEN           0x01
#define LCD_RETURN_HOME            0x02
/**************************************************/
#define FOUR_BIT  0
#define EIGHT_BIT 1
#define HIGH_NIBBLE  1
#define LOW_NIBBLE   0

typedef struct{
	u_int8 Mode;
	u_int8 Nibble;
	u_int8 LCD_port;
	u_int8 RS_port;
	u_int8 RS_pin;
	u_int8 RW_port;
	u_int8 RW_pin;
	u_int8 EN_port;
	u_int8 EN_pin;
	}OBJ;

void LCD_Get_config(OBJ *ptr, u_int8 mode, u_int8 nibble, u_int8 port, u_int8 Rs_port, u_int8 rs_pin, u_int8 rw_port, u_int8 rw_pin, u_int8 en_port, u_int8 en_pin);

void LCD_vInit(void);

void LCD_vsend_cmd(u_int8 cmd);

static void LCD_send_falling_edge(void);

void LCD_vsend_char(u_int8 data);

void LCD_vsend_string(u_int8 *ptr); 

void LCD_vMove_Cursor(u_int8 raw, u_int8 position);

void LCD_vclear_screen();

void LCD_vsend_number(u_int32 Number);

void LCD_vsend_real_number(float64 Number);
#endif /* LCD_ECU_H_ */