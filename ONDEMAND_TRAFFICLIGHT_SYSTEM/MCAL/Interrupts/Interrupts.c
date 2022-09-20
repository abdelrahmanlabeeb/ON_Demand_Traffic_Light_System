/*
* Interrupts.c
*
* Created: 9/4/2022 7:47:33 AM
*  Author: Abdelrahman
*/
#include "Interrupts.h"
static volatile void (*g_I_0_callbackptr)(void) = NULL_PTR;
static volatile void (*g_I_1_callbackptr)(void) = NULL_PTR;
static volatile void (*g_I_2_callbackptr)(void) = NULL_PTR;

EN_EXT_INT_Error Ext_INT_init(EXT_INT_Config *intconfigptr)
{
	/*switch case 1 for the interrupt number*/
	switch(intconfigptr->ext_int_num)
	{
		case INT_0:
		/*switch case 1.1 for the interrupt sense*/ 
		switch (intconfigptr->ext_int_sense)
		{
			case LOW:
			MCUCR &= ~(1<<0); /*clear ISC00*/
			MCUCR &= ~(1<<1); /*clear ISC01*/
			break;
			case CHANGE:
			MCUCR |= (1<<0); /*set ISC00*/
			MCUCR &= ~(1<<1); /*clear ISC01*/
			break;
			case FALLING:
			MCUCR &= ~(1<<0); /*clear ISC00*/
			MCUCR |= (1<<1); /*set ISC01*/
			break;
			case RISE:
			MCUCR |= (1<<0); /*set ISC00*/
			MCUCR |= (1<<1); /*set ISC01*/
			break;
			default:
			return INT_sense_invalid;
			break;
		}
		GICR |=(1<<6); /*set INT0 to enable external interrupt for pinD2*/
		break;
		case INT_1:
		/*switch case 1.2 for the interrupt sense*/
		switch (intconfigptr->ext_int_sense)
		{
			case LOW:
			MCUCR &= ~(1<<2); /*clear ISC00*/
			MCUCR &= ~(1<<3); /*clear ISC01*/
			break;
			case CHANGE:
			MCUCR |= (1<<2); /*set ISC00*/
			MCUCR &= ~(1<<3); /*clear ISC01*/
			break;
			case FALLING:
			MCUCR &= ~(1<<2); /*clear ISC00*/
			MCUCR |= (1<<3); /*set ISC01*/
			break;
			case RISE:
			MCUCR |= (1<<2); /*set ISC00*/
			MCUCR |= (1<<3); /*set ISC01*/
			break;
			default:
			return INT_sense_invalid;
			break;
		}
		GICR |=(1<<7); /*set INT0 to enable external interrupt for pinD2*/
		break;
		case INT_2:
		MCUCSR |= (1<<6); /*Enable ISC2 for rising edge sense in INT2*/
		GICR |=(1<<5);
		break;
		default:
		return INT_num_invalid;
		break;
	}
	return OK_I;
}

void set_INT0_callbackptr(void (*INT_0_callback)(void))
{
	g_I_0_callbackptr = INT_0_callback;
}
void set_INT1_callbackptr(void (*INT_1_callback)(void))
{
	g_I_1_callbackptr = INT_1_callback;
}
void set_INT2_callbackptr(void (*INT_2_callback)(void))
{
	g_I_2_callbackptr = INT_2_callback;
}

ISR(EXT_INT_0)
{
	if (g_I_0_callbackptr !=NULL_PTR)
	(*g_I_0_callbackptr)();
	
}

ISR(EXT_INT_1)
{
	if (g_I_1_callbackptr !=NULL_PTR)
	(*g_I_1_callbackptr)(); 
	
}

ISR(EXT_INT_2)
{
	if (g_I_2_callbackptr !=NULL_PTR)
	(*g_I_2_callbackptr)(); 
	
}
