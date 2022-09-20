/*
 * Registers.h
 *
 * Created: 8/30/2022 5:43:58 PM
 *  Author: Abdelrahman Hisham
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
//Dio Registers
//1- PORTA
#define PORTA *(volatile uint8_t*)0X3B
#define DDRA *(volatile uint8_t*)0X3A
#define PINA *(volatile uint8_t*)0X39
//2- PORTB
#define PORTB *(volatile uint8_t*)0X38
#define DDRB *(volatile uint8_t*)0X37
#define PINB *(volatile uint8_t*)0X36
//3- PORTC
#define PORTC *(volatile uint8_t*)0X35
#define DDRC *(volatile uint8_t*)0X34
#define PINC *(volatile uint8_t*)0X33
//1- PORTD
#define PORTD *(volatile uint8_t*)0X32
#define DDRD *(volatile uint8_t*)0X31
#define PIND *(volatile uint8_t*)0X30
/***************************************************************************************
*										Timers REGISTERS							   *
****************************************************************************************/							
//Timer1 registers
#define TCCR1A *(uint8_t*)0x4F
#define TCCR1B *(uint8_t*)0x4E
#define TCNT1H *(uint8_t*)0x4D
#define TCNT1L *(uint8_t*)0x4C
#define TIFR *(uint8_t*) 0x58
//Timer0 registers 
#define TCCR0 *(uint8_t*)0x53
#define TCNT0 *(uint8_t*)0x52
//Timer2 registers
#define TCCR2 *(uint8_t*)0x45
#define TCNT2 *(uint8_t*)0x44

// Status register 
#define SREG *(uint8_t*)0x5F

//Interrupts registers 
// Global interrupt 
#define sei SREG |= (1<<7) // enabling global interrupt by setting the i bit in SREG register 
#define cli SREG &= ~(1<<7) // disabling global interrupt by clearing the i bit in SREG register 
//EXTERNAL interrupt registers 
#define MCUCR *(volatile uint8_t*)0x55 // MCU control register 
#define MCUCSR *(uint8_t*)0x54 // MCU control and status register 
#define GICR *(uint8_t*)0x5B // General interrupt control register 
#define GIFR *(volatile uint8_t*)0x5A // General interrupt flag register 

#endif /* REGISTERS_H_ */