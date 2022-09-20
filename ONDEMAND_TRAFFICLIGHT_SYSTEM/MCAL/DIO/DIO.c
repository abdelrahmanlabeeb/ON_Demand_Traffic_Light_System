/*
 * DIO.c
 *
 * Created: 8/30/2022 5:00:36 PM
 *  Author: Abdelrahman Hisham
 */ 
#include "DIO.h"

EN_DIO_Error DIO_init(uint8_t Portname, uint8_t Pinnumber,uint8_t direction )
{
	if (Pinnumber > 8)
	return DIO_PIN_INVALID;
	if (direction != IN && direction != OUT)
	return DIO_Direction_Invalid;
	switch (Portname)
	{
		case PORT_A:
		if (direction == OUT)
		DDRA |= (1<<Pinnumber);
		else if (direction == IN) 
		DDRA &= ~(1<<Pinnumber);
		break;
		
		case PORT_B:
		if (direction == OUT)
		DDRB |= (1<<Pinnumber);
		else if (direction == IN)
		DDRB &= ~(1<<Pinnumber);
		break;
		
		case PORT_C:
		if (direction == OUT)
		DDRC |= (1<<Pinnumber);
		else if (direction == OUT)
		DDRC &= ~(1<<Pinnumber);
		break;
		
		case PORT_D:
		if (direction == OUT)
		DDRD |= (1<<Pinnumber);
		else if (direction == IN)
		DDRD &= ~(1<<Pinnumber);
		break;
		
		default:
		return DIO_PORT_INVALID;
		break;
		
	}
	return OK_DIO;
}

EN_DIO_Error DIO_read(uint8_t Portname, uint8_t Pinnumber,uint8_t *value)
{
	if (Pinnumber > 8)
	return DIO_PIN_INVALID;
	
	switch (Portname)
	{
		case PORT_A:
		*value = (PINA & (1<<Pinnumber))>>Pinnumber;
		break;
		
		case PORT_B:
		*value = (PINB & (1<<Pinnumber))>>Pinnumber;
		break;
		
		case PORT_C:
		*value = (PINC & (1<<Pinnumber))>>Pinnumber;
		break;
		
		case PORT_D:
		*value = (PIND & (1<<Pinnumber))>>Pinnumber;
		break;
		
		default:
		return DIO_PORT_INVALID;
		break;
}
return OK_DIO;
}

EN_DIO_Error DIO_write(uint8_t Portname, uint8_t Pinnumber,uint8_t Logic_State )
{
	if (Pinnumber > 8)
	return DIO_PIN_INVALID;
	if (Logic_State != L_HIGH && Logic_State != L_LOW)
	return DIO_Direction_Invalid;
	switch(Portname)
	{
		case PORT_A:
		if (Logic_State == L_HIGH)
		PORTA |= (1<<Pinnumber);
		else if(Logic_State == L_LOW)
		PORTA &=~(1<<Pinnumber);
 		break;
		
		case PORT_B:
		if (Logic_State == L_HIGH)
		PORTB |= (1<<Pinnumber);
		else if(Logic_State == L_LOW)
		PORTB &=~(1<<Pinnumber);
		break;
		
		case PORT_C:
		if (Logic_State == L_HIGH)
		PORTC |= (1<<Pinnumber);
		else if(Logic_State == L_LOW)
		PORTC &=~(1<<Pinnumber);
		break;
		
		case PORT_D:
		if (Logic_State == L_HIGH)
		PORTD |= (1<<Pinnumber);
		else if(Logic_State == L_LOW)
		PORTD &=~(1<<Pinnumber);
		break;
		
		
		default:
		return DIO_PORT_INVALID;
		break;
	}
	return OK_DIO;
}


EN_DIO_Error DIO_toggle(uint8_t Portname, uint8_t Pinnumber)
{
	if (Pinnumber > 8)
	return DIO_PIN_INVALID;
	switch(Portname)
	{
	case PORT_A:
	PORTA ^=(1<<Pinnumber);
	break;
	
	case PORT_B:
	PORTB ^=(1<<Pinnumber);
	break;
	
	case PORT_C:
	PORTC ^=(1<<Pinnumber);
	break;
	
	case PORT_D:
	PORTD ^=(1<<Pinnumber);
	break;
	
	default:
	return DIO_PORT_INVALID;
	break;
	}
	return OK_DIO;
}