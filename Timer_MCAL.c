/*
 * Timer_MCAL.c
 *
 * Created: 7/26/2020 7:42:31 PM
 *  Author: Mahmoud Ayman
 */ 

#include "Timer_MCAL.h"

TMR0_config *ptr_struct;

void TMR0_Get_config(TMR0_config *ptr, u_int8 Mode, u_int8 OVF_Interrupt, u_int8 CTC_Interrupt, u_int8 prescalar){
	ptr_struct=ptr;
	ptr_struct->mode=Mode;
	ptr_struct->TMR0_OVF_Interrupt=OVF_Interrupt;
	ptr_struct->TMR0_CTC_Interrupt=CTC_Interrupt;
	ptr_struct->Prescalar=prescalar;
}

void TMR0_VInit(){
	/*Adjust Mode*/
	if(ptr_struct->mode==NORMAL_MODE){
		CLR_BIT(XTCCR0,WGM00);
		CLR_BIT(XTCCR0,WGM01);
	}else if(ptr_struct->mode==CTC_MODE){
		CLR_BIT(XTCCR0,WGM00);
		SEt_BIT(XTCCR0,WGM01);
	}else if(ptr_struct->mode==OCM_NON_PWM_MODE){
		CLR_BIT(XTCCR0,WGM00);
		SEt_BIT(XTCCR0,WGM01);
	}else if(ptr_struct->mode==FAST_PWM_MODE){
		SEt_BIT(XTCCR0,WGM00);
		SEt_BIT(XTCCR0,WGM01);
	}else if(ptr_struct->mode==PHASE_CORRECT_PWM){
		SEt_BIT(XTCCR0,WGM00);
		CLR_BIT(XTCCR0,WGM01);
	}
	/*****************************************/
	/*Adjust Prescalar*/
	XTCCR0&=0xF8;
	XTCCR0|=ptr_struct->Prescalar;  
	/********************************/
	/*OVF Interrupt*/
	if(ptr_struct->TMR0_OVF_Interrupt==TOIE0_ENABLE){
		SEt_BIT(XTIMASK,TOIE0);
	}else if(ptr_struct->TMR0_OVF_Interrupt==TOIE0_DISABLE){
		CLR_BIT(XTIMASK,TOIE0);
	}
	/*****************************/
	/*CTC Interrupt*/
	if(ptr_struct->TMR0_OVF_Interrupt==OCIE0_ENABLE){
		SEt_BIT(XTIMASK,OCIE0);
	}else if(ptr_struct->TMR0_OVF_Interrupt==OCIE0_DISABLE){
		CLR_BIT(XTIMASK,OCIE0);
	}
	/*****************************/
}


u_int8 TMR0_Read_count(void){
	return XTCNT0;
}

void TMR0_set_compare_value(u_int8 val){
	XOCR0= val;
}

void TMR0_set_counter_value(u_int8 val){
	XTCNT0=val;
}


void TMR0_Fast_PWM_Gen(u_int8 duty_cycle){
	/*adjust mode as Fast PWM*/
	SEt_BIT(XTCCR0,WGM00);
	SEt_BIT(XTCCR0,WGM01);
	/****************************/
	u_int8 val;
	SEt_BIT(XDDRB,3);
	val=(duty_cycle * 256)/100; 
	XOCR0=val; 
	CLR_BIT(XTCCR0,COM00);
	SEt_BIT(XTCCR0,COM01);
}