/*
 * std_macros.h
 *
 * Created: 6/27/2020 12:36:17 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SEt_BIT(reg,Bit) reg|=(1<<Bit)
#define CLR_BIT(reg,Bit) reg&=(~(1<<Bit))
#define Toggle_Bit(reg,Bit) reg^=(1<<Bit)
#define Read_Bit(reg,Bit)  ((reg&(1<<Bit))>>Bit)
#define IS_BIT_CLR(reg,Bit) !((reg&(1<<Bit))>>Bit)

#endif /* STD_MACROS_H_ */