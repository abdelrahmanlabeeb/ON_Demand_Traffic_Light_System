/*
 * BUTTON.c
 *
 * Created: 9/3/2022 9:41:11 AM
 *  Author: Abdelrahman
 */ 
#include "BUTTON.h"

EN_Push_Button_Error BUTTON_init(uint8_t portname,uint8_t pinnumber)
{
	if (DIO_init(portname,pinnumber,IN) == OK_DIO) // initializes the pin as input
	return OK_PB;
	else 
	return DIO_Error;
}
EN_Push_Button_Error BUTTON_read(uint8_t portname, uint8_t pinnumber,uint8_t* value)
{
	if(DIO_read(portname,pinnumber,value) == OK_DIO) // reads the button state (Pressed/not pressed)
	return OK_PB ;
	else 
	return DIO_Error;
}