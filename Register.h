/*
 * Register.h
 *
 * Created: 6/27/2020 12:14:57 PM
 *  Author: Mahmoud Ayman
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_
#include "Data_Type.h" 
/*PORTA*/
#define XPORTA *((volatile u_int8 * const)0x3B)
#define XDDRA  *((volatile u_int8 * const)0x3A)
#define XPINA  *((volatile u_int8 * const)0x39)
/*****************/
/*PORTB*/
#define XPORTB *((volatile u_int8 * const)0x38)
#define XDDRB  *((volatile u_int8 * const)0x37)
#define XPINB  *((volatile u_int8 * const)0x36)
/*****************/
/*PORTC*/  
#define XPORTC *((volatile u_int8 * const)0x35)
#define XDDRC  *((volatile u_int8 * const)0x34)
#define XPINC  *((volatile u_int8 * const)0x33)
/*****************/
/*PORTD*/
#define XPORTD *((volatile u_int8 * const)0x32)
#define XDDRD  *((volatile u_int8 * const)0x31)
#define XPIND  *((volatile u_int8 * const)0x30)
/*****************/
/******External Interrupt*******************/
#define XGICR  *((volatile u_int8 * const)0x5B)
#define  INT1 7
#define  INT0 6
#define  INT0 5
#define XMCUCR *((volatile u_int8 * const)0x55)
#define	 ISC00 0
#define	 ISC01 1
#define  ISC10 2
#define  ISC11 3
#define XMCUCSR  *((volatile u_int8 * const)0x54)
#define  ISC2 6
#define XGIFR  *((volatile u_int8 * const)0x5A)
#define  INTF1 7
#define  INTF0 6
#define  INTF2 5
#define XSREG  *((volatile u_int8 * const)0x5F)
/*****************************************************/
/***********Internal EEPROM************************/
#define XEEARH *((volatile u_int8 * const)0x3f)
#define XEEARL *((volatile u_int8 * const)0x3E)
#define XEEDR  *((volatile u_int8 * const)0x3D)
#define XEECR  *((volatile u_int8 * const)0x3C)
#define  EERE 0
#define  EEWE 1
#define  EEMWE 2
#define  EERIE 3
/****************************************************/
/***************ADC Registers************************/
#define XADMUX *((volatile u_int8 * const)0x27)
#define  MUX0 0
#define  MUX1 1
#define  MUX2 2
#define  MUX3 3
#define  MUX4 4
#define  ADLAR 5
#define  REFS0 6
#define  REFS1 7
#define XADCSRA *((volatile u_int8 * const)0x26)
#define  ADPS0 0
#define  ADPS1 1
#define  ADPS2 2
#define  ADIE 3
#define  ADIF 4
#define  ADATE 5
#define  ADSC 6
#define  ADEN 7
#define XADCH *((volatile u_int8 * const)0x25)
#define XADCL *((volatile u_int8 * const)0x24)
#define XSFIOR *((volatile u_int8 * const)0x50)
#define  PUD 2
#define  ADTS0 5
#define  ADTS1 6
#define  ADTS2 7
/**************************************************/
#endif /* REGISTER_H_ */