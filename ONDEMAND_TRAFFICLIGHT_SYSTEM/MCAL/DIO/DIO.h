/*
 * DIO.h
 *
 * Created: 8/30/2022 4:59:59 PM
 *  Author: Abdelrahman Hisham
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "../../Utilities/Registers.h"
typedef enum
{
	OK_DIO,DIO_PORT_INVALID,DIO_PIN_INVALID,DIO_Direction_Invalid
}EN_DIO_Error;
// defining port names
 #define PORT_A 'A'
 #define PORT_B 'B'
 #define PORT_C 'C'
 #define PORT_D 'D'
#define IN 0
#define OUT 1 
#define L_HIGH 1
#define L_LOW 0

EN_DIO_Error DIO_init(uint8_t Portname, uint8_t Pinnumber,uint8_t direction ); // initialize pin (input/output)
EN_DIO_Error DIO_read(uint8_t Portname, uint8_t Pinnumber,uint8_t *value); // read pin (high/low)and return in value
EN_DIO_Error DIO_write(uint8_t Portname, uint8_t Pinnumber,uint8_t value ); // set pin (high/low)
EN_DIO_Error DIO_toggle(uint8_t Portname, uint8_t Pinnumber); // toggle pin

#endif /* DIO_H_ */