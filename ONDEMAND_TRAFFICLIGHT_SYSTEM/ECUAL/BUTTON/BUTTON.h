/*
 * BUTTON.h
 *
 * Created: 9/3/2022 9:37:03 AM
 *  Author: Abdelrahman
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO/DIO.h"
typedef enum
{
	OK_PB,DIO_Error
}EN_Push_Button_Error;
EN_Push_Button_Error BUTTON_init(uint8_t portname,uint8_t pinnumber);
EN_Push_Button_Error BUTTON_read(uint8_t portname, uint8_t pinnumber,uint8_t* value);





#endif /* BUTTON_H_ */