/*
 * Timer_MCAL.h
 *
 * Created: 7/26/2020 7:42:10 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef TIMER_MCAL_H_
#define TIMER_MCAL_H_
#include "Data_Type.h"
#include "Register.h"
#include "std_macros.h"
#include<avr/interrupt.h>

/************************************************Timer0************************************/
/******Modes****************/
#define NORMAL_MODE      0
#define CTC_MODE         1
#define OCM_NON_PWM_MODE 2
#define FAST_PWM_MODE    3
#define PHASE_CORRECT_PWM 4
/*****************************/
/*******T0 OV interrupt*********/
#define  TOIE0_ENABLE   0
#define  TOIE0_DISABLE  1
/*******************************/
/*******T0 CTC interrupt*********/
#define  OCIE0_ENABLE   0
#define  OCIE0_DISABLE  1
/*******************************/
/*******Prescalar****************/
#define NO_CLK_SRC   0
#define NO_PRESCALLING  1
#define PRESCALING_CLK8 2
#define PRESCALING_CLK64 3
#define PRESCALING_CLK256 4
#define PRESCALING_CLK1024 5
#define EXT_CLK_FALLING    6
#define EXT_CLK_RISING     7
/*****************************/

/*struct*/
typedef struct{
	u_int8 mode;
	u_int8 TMR0_OVF_Interrupt;
	u_int8 TMR0_CTC_Interrupt;
	u_int8 Prescalar;
	}TMR0_config;
/*********************************/

void TMR0_Get_config(TMR0_config *ptr, u_int8 Mode, u_int8 OVF_Interrupt, u_int8 CTC_Interrupt, u_int8 prescalar);

void TMR0_VInit();

u_int8 TMR0_Read_count(void);

void TMR0_set_compare_value(u_int8 val);

void TMR0_set_counter_value(u_int8 val);

void TMR0_Fast_PWM_Gen(u_int8 duty_cycle);

#endif /* TIMER_MCAL_H_ */