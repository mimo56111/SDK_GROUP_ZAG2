/*
 * Internal_EEPROM_MCAL.c
 *
 * Created: 7/12/2020 12:31:04 PM
 *  Author: Mahmoud Ayman
 */ 
#include "Internal_EEPROM_MCAL.h"
void EEPROM_vWrite(u_int16 address, u_int8 val){
	XEEARL=(u_int8)address;   
	XEEARH=(u_int8)(address>>8);
	XEEDR=val;
	SEt_BIT(XEECR,EEMWE);
	SEt_BIT(XEECR,EEWE);
	while(Read_Bit(XEECR,EEWE)==1);
}

u_int8 EEPROM_u8Read(u_int16 address){
	XEEARL=(u_int8)address;
	XEEARH=(u_int8)(address>>8);
	SEt_BIT(XEECR,EERE);
	return XEEDR;
}