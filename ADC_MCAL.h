/*
 * ADC_MCAL.h
 *
 * Created: 7/24/2020 8:12:51 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef ADC_MCAL_H_
#define ADC_MCAL_H_
#include "Register.h"
#include "Data_Type.h"
#include "std_macros.h"

#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7

void ADC_vInit();


u_int16 ADC_u16Read(u_int8 Channel);




#endif /* ADC_MCAL_H_ */