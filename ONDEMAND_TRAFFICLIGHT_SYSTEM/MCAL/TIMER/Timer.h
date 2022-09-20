/*
* Timer.h
*
* Created: 9/3/2022 10:36:19 AM
*  Author: Abdelrahman
*/


#ifndef TIMER_H_
#define TIMER_H_
#include "../../Utilities/Registers.h"
/**************************************************************************************************
 *									Types Declaration											  *
 **************************************************************************************************/
typedef enum 
{
	OK_T, Timer_num_invalid, Timer_mode_invalid, Timer_clock_invalid
	}EN_Timer_Error;
typedef enum
{
	Timer_0 , Timer_1, Timer_2
}Timer_num;
typedef enum
{
	Overflow , Compare, FPWM ,PCPWM
}Timer_mode;
typedef enum 
{
	NO_clock,CPU_clock,CPU_8,CPU_32,CPU_64,CPU_128,CPU_256,CPU_1024
	}Prescaler;
typedef struct{
	Timer_num timer_num;
	Timer_mode timer_mode;
	Prescaler timer_prescaler;
	uint16_t TCNT_init; /*take the initial value form the user */
	uint16_t OCR_init; /*take the compare value from user, put 0 if using Overflow mode*/
	}Timer_config_type;
/**************************************************************************************************
 *									Function prototypes											  *
 **************************************************************************************************/
/*
* Description:
* Initialize the timer according to the configuration struct taken as argument 
* set the required timer 
* set the timer mode
* set the clock prescaler 
* set the initial value of the counter register 
*/
EN_Timer_Error Timer_init(Timer_config_type* configptr);

void Timer1_checkflag(uint8_t *flag); // returns HIGH if the flag is set else returns LOW

// timer 0 functions
void Timer0_checkflag(uint8_t *flag);
// timer 2 functions
void Timer2_checkflag(uint8_t *flag);

void Timer_Deinit(Timer_num timer_num);

#endif /* TIMER_H_ */