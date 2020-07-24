/*
 * Internal_EEPROM_MCAL.h
 *
 * Created: 7/12/2020 12:30:52 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef INTERNAL_EEPROM_MCAL_H_
#define INTERNAL_EEPROM_MCAL_H_
#include "Data_Type.h"
#include "Register.h"
#include "std_macros.h"

void EEPROM_vWrite(u_int16 address, u_int8 val);

u_int8 EEPROM_u8Read(u_int16 address);


#endif /* INTERNAL_EEPROM_MCAL_H_ */