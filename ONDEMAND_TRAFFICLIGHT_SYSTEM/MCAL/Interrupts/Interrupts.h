/*
 * Interrupts.h
 *
 * Created: 9/4/2022 7:47:50 AM
 *  Author: Abdelrahman
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_
#include "../DIO/DIO.h"
#include "../../Utilities/Common_macros.h"

#define INT0 0
#define INT1 1
#define INT2 2

#define EXT_INT_0 __vector_1
#define ISR(INT_VECT) void INT_VECT(void)__attribute__((signal,used));\
void INT_VECT(void)

#define EXT_INT_1 __vector_2
#define ISR(INT_VECT) void INT_VECT(void)__attribute__((signal,used));\
void INT_VECT(void)

#define EXT_INT_2 __vector_3
#define ISR(INT_VECT) void INT_VECT(void)__attribute__((signal,used));\
void INT_VECT(void)

typedef enum 
{
	LOW,CHANGE,FALLING,RISE
}EXT_INT_sense;
typedef enum
{
	INT_0,INT_1,INT_2
	}EXT_INT_num;
typedef enum
{
	OK_I, INT_num_invalid,INT_sense_invalid
	}EN_EXT_INT_Error;
typedef	struct{
	EXT_INT_num ext_int_num;
	EXT_INT_sense ext_int_sense;
	}EXT_INT_Config;

EN_EXT_INT_Error Ext_INT_init(EXT_INT_Config *intconfigptr);

void set_INT0_callbackptr(void (*INT_0_callback)(void));
void set_INT1_callbackptr(void (*INT_1_callback)(void));
void set_INT2_callbackptr(void (*INT_2_callback)(void));




#endif /* INTERRUPTS_H_ */