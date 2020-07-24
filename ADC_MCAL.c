/*
 * ADC_MCAL.c
 *
 * Created: 7/24/2020 8:13:02 PM
 *  Author: Mahmoud Ayman
 */ 
#include "ADC_MCAL.h"

void ADC_vInit(){
	/*Configuration Vref (VCC on AVCC with external capacitor at AVREF pin*/
	SEt_BIT(XADMUX,REFS0);
	SEt_BIT(XADMUX,REFS1);
	/*Enable ADC*/
	SEt_BIT(XADCSRA,ADEN);
	/*Adjust ADC Clock make the division factor 64 (8M/64 =125KHz)*/
	SEt_BIT(XADCSRA,ADPS2);
	SEt_BIT(XADCSRA,ADPS1);
	CLR_BIT(XADCSRA,ADPS0);
}


u_int16 ADC_u16Read(u_int8 Channel){
	u_int16 read_value;
	
	Channel &=0x07;  
	
	XADMUX &=0xE0;
	
	XADMUX|=Channel;
	
	SEt_BIT(XADCSRA,ADSC);
	
	while(IS_BIT_CLR(XADCSRA,ADIF));
	
	SEt_BIT(XADCSRA,ADIF);
	
	read_value=XADCL;
	read_value|=(XADCH<<8); 
	
	return read_value;
}