/*
 * LED.h
 *
 * Created: 9/3/2022 9:27:41 AM
 *  Author: Abdelrahman
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/Common_macros.h"
typedef enum
{
	OK_L,DIO_L_Error
}EN_LED_Error;
EN_LED_Error LED_init(uint8_t portname, uint8_t pinnumber);
EN_LED_Error LED_ON (uint8_t portname, uint8_t pinnumber);
EN_LED_Error LED_OFF(uint8_t portname, uint8_t pinnumber);
EN_LED_Error LED_read (uint8_t portname,uint8_t pinnumber, uint8_t *state);
EN_LED_Error LED_Toggle(uint8_t portname, uint8_t pinnumber);
#endif /* LED_H_ */