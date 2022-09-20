/*
 * LED.c
 *
 * Created: 9/3/2022 9:32:45 AM
 *  Author: Abdelrahman
 */ 
#include "LED.h"

EN_LED_Error LED_init(uint8_t portname, uint8_t pinnumber)
{
	if(DIO_init(portname,pinnumber,OUT) == OK_DIO) //initializes Pin as output	
	return OK_L;
	else 
	return DIO_L_Error;
}
EN_LED_Error LED_ON (uint8_t portname, uint8_t pinnumber)
{
	if (DIO_write(portname,pinnumber,L_HIGH) == OK_DIO) // Turns on LED by writing Logic high 
	return OK_L;
	else
	return DIO_L_Error;
}
EN_LED_Error LED_OFF(uint8_t portname, uint8_t pinnumber)
{
	if(DIO_write(portname,pinnumber,L_LOW) == OK_DIO) // turns off LED by writing logic low 
	return OK_L;
	else
	return DIO_L_Error;
}

EN_LED_Error LED_Toggle(uint8_t portname, uint8_t pinnumber)
{
	if(DIO_toggle(portname,pinnumber) == OK_DIO) // Led toggles 
	return OK_L;
	else
	return DIO_L_Error;
}
EN_LED_Error LED_read(uint8_t portname,uint8_t pinnumber, uint8_t *stateptr)
{
	if(DIO_read(portname,pinnumber,stateptr) == OK_DIO)  // reads the port state (high/low)
	return OK_L;
	else
	return DIO_L_Error;
}