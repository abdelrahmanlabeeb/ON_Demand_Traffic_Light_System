/*
* TIMER.c
*
* Created: 9/3/2022 12:00:54 PM
*  Author: Abdelrahman
*/


#include "Timer.h"

void Timer1_checkflag(uint8_t *flag)
{
	if (TIFR & (1<<2)) // checking TOV1 FLAG
	*flag = (uint8_t)1;
	else
	*flag = (uint8_t)0;
}



void Timer0_checkflag(uint8_t *flag)
{
	if(TIFR & (1<<0))
	*flag = (uint8_t)1;
	else
	*flag = (uint8_t)0;
}

void Timer2_checkflag(uint8_t *flag)
{
	if(TIFR & (1<<6))
	*flag = (uint8_t)1;
	else
	*flag = (uint8_t)0;
}
EN_Timer_Error Timer_init(Timer_config_type* configptr)
{
	/*switch_1 case timer number*/
	switch (configptr->timer_num)
	{
		//case 1 for Timer 0
		case Timer_0:
		//switch_1.1 case for the Timer mode
		switch (configptr->timer_mode)
		{
			case Overflow:
			TCCR0 &= ~(1<<6); /*clear WGM00*/
			TCCR0 &= ~(1<<3); /*clear WGM01*/
			break;
			case Compare:
			TCCR0 &= ~(1<<6); /*clear WGM00*/
			TCCR0 |= (1<<3); /*set WGM01*/
			break;
			case FPWM:
			TCCR0 |= (1<<6); /*set WGM00*/
			TCCR0 &= ~(1<<3); /*clear WGM01*/
			break;
			case PCPWM:
			TCCR0 |= (1<<6); /*set WGM00*/
			TCCR0 |= (1<<3); /*set WGM01*/
			break;
			/*in case the user entered another mode that is not available */
			default:
			return Timer_mode_invalid;
			break;
		}
		//set the initial value for overflow counter in timer 0
		TCNT0 = (uint8_t)configptr->TCNT_init;
		//switch case 1.2 to set the Prescaler value
		switch (configptr->timer_prescaler)
		{
			case NO_clock:
			TCCR0 &= ~(1<<0); /*clear CS00*/
			TCCR0 &= ~(1<<1); /*clear CS01*/
			TCCR0 &= ~(1<<2); /*clear CS02*/
			break;
			case CPU_clock:
			TCCR0 |= (1<<0); /*set CS00*/
			TCCR0 &= ~(1<<1); /*clear CS01*/
			TCCR0 &= ~(1<<2); /*clear CS02*/
			break;
			case CPU_8:
			TCCR0 &= ~(1<<0); /*clear CS00*/
			TCCR0 |= (1<<1); /*set CS01*/
			TCCR0 &= ~(1<<2); /*clear CS02*/
			break;
			case CPU_64:
			TCCR0 |= (1<<0); /*set CS00*/
			TCCR0 |= (1<<1); /*set CS01*/
			TCCR0 &= ~(1<<2); /*clear CS02*/
			break;
			case CPU_256:
			TCCR0 &= ~(1<<0); /*clear CS00*/
			TCCR0 &= ~(1<<1); /*clear CS01*/
			TCCR0 |= (1<<2); /*set CS02*/
			break;
			case CPU_1024:
			TCCR0 |= (1<<0); /*set CS00*/
			TCCR0 &= ~(1<<1); /*clear CS01*/
			TCCR0 |= (1<<2); /*set CS02*/
			break;
			
			default:
			return Timer_clock_invalid;
			break;
		}
		break;
		case Timer_1:
		//switch_2.1 case for the Timer mode
		switch (configptr->timer_mode)
		{
			case Overflow:
			TCCR1A &= ~(1<<0); /*clear WGM10*/
			TCCR1A &= ~(1<<1); /*clear WGM11*/
			TCCR1B &= ~(1<<3); /*clear WGM12*/
			break ;
			case Compare:
			TCCR1A &= ~(1<<0); /*clear WGM10*/
			TCCR1A &= ~(1<<1) ;/*clear WGM11*/
			TCCR1B |= (1<<3); /*SET WGM12*/
			break;
			case FPWM:
			TCCR1A |= (1<<0); /*SET WGM10*/
			TCCR1A &= ~(1<<1); /*clear WGM11*/
			TCCR1B |= (1<<3); /*SET WGM12*/
			break;
			case PCPWM:
			TCCR1A |= (1<<0) ;/*SET WGM10*/
			TCCR1A &= ~(1<<1) ;/*clear WGM11*/
			TCCR1B &= ~(1<<3); /*clear WGM12*/
			break;
			/*in case the user entered another mode that is not available */
			default:
			return Timer_mode_invalid;
			break;
		}
		//set the initial value for overflow counter in timer 0
		TCNT1H = (uint8_t)(configptr->TCNT_init >> 8);
		TCNT1L = (uint8_t)(configptr->TCNT_init);
		//switch case 2.2 to set the Prescaler value
		switch (configptr->timer_prescaler)
		{
			case NO_clock:
			TCCR1B &= ~(1<<0); /*clear CS10*/
			TCCR1B &= ~(1<<1); /*clear CS11*/
			TCCR1B &= ~(1<<2); /*clear CS12*/
			break;
			case CPU_clock:
			TCCR1B |= (1<<0); /*set CS10*/
			TCCR1B &= ~(1<<1); /*clear CS11*/
			TCCR1B &= ~(1<<2); /*clear CS12*/
			break;
			case CPU_8:
			TCCR1B &= ~(1<<0); /*clear CS10*/
			TCCR1B |= (1<<1); /*set CS11*/
			TCCR1B &= ~(1<<2); /*clear CS12*/
			break;
			case CPU_64:
			TCCR1B |= (1<<0); /*set CS10*/
			TCCR1B |= (1<<1); /*set CS11*/
			TCCR1B &= ~(1<<2); /*clear CS12*/
			break;
			case CPU_256:
			TCCR1B &= ~(1<<0); /*clear CS10*/
			TCCR1B &= ~(1<<1); /*clear CS11*/
			TCCR1B |= (1<<2); /*set CS12*/
			break;
			case CPU_1024:
			TCCR1B |= (1<<0); /*set CS10*/
			TCCR1B &= ~(1<<1); /*clear CS11*/
			TCCR1B |= (1<<2); /*set CS12*/
			break;
			
			default:
			return Timer_clock_invalid;
			break;
		}
		break;
		case Timer_2:
		//switch_1.3 case for the Timer mode
		switch (configptr->timer_mode)
		{
			case Overflow:
			TCCR2 &= ~(1<<6); /*clear WGM20*/
			TCCR2 &= ~(1<<3); /*clear WGM21*/
			break;
			case Compare:
			TCCR2 &= ~(1<<6); /*clear WGM20*/
			TCCR2 |= (1<<3); /*set WGM21*/
			break;
			case FPWM:
			TCCR2 |= (1<<6); /*set WGM20*/	
			TCCR2 &= ~(1<<3); /*clear WGM21*/
			break;
			case PCPWM:
			TCCR2 |= (1<<6); /*set WGM20*/
			TCCR2 |= (1<<3); /*set WGM21*/
			break;
			/*in case the user entered another mode that is not available */
			default:
			return Timer_mode_invalid;
			break;
		}
		//set the initial value for overflow counter in timer 2
		TCNT2 = (uint8_t)configptr->TCNT_init;
		//switch case 1.3 to set the Prescaler value
		switch (configptr->timer_prescaler)
		{
			case NO_clock:
			TCCR2 &= ~(1<<0); /*clear CS20*/
			TCCR2 &= ~(1<<1); /*clear CS21*/
			TCCR2 &= ~(1<<2); /*clear CS22*/
			break;
			case CPU_clock:
			TCCR2 |= (1<<0); /*set CS20*/
			TCCR2 &= ~(1<<1); /*clear CS21*/
			TCCR2 &= ~(1<<2); /*clear CS22*/
			break;
			case CPU_8:
			TCCR2 &= ~(1<<0); /*clear CS20*/
			TCCR2 |= (1<<1); /*set CS21*/
			TCCR2 &= ~(1<<2); /*clear CS22*/
			break;
			case CPU_32:
			TCCR2 |= (1<<0); /*set CS20*/
			TCCR2 |= (1<<1); /*set CS21*/
			TCCR2 &= ~(1<<2); /*clear CS22*/
			break;
			case CPU_64:
			TCCR2 &= ~(1<<0); /*clear CS20*/
			TCCR2 &= ~(1<<1); /*clear CS21*/
			TCCR2 |= (1<<2); /*set CS22*/
			break;
			case CPU_128:
			TCCR2 |= (1<<0); /*set CS20*/
			TCCR2 &= ~(1<<1); /*clear CS21*/
			TCCR2 |= (1<<2); /*set CS22*/
			break;
			case CPU_256:
			TCCR2 &= ~(1<<0); /*clear CS20*/
			TCCR2 |= (1<<1); /*set CS21*/
			TCCR2 |= (1<<2); /*set CS02*/
			break;
			case CPU_1024:
			TCCR2 |= (1<<0); /*set CS20*/
			TCCR2 |= (1<<1); /*set CS21*/
			TCCR2 |= (1<<2); /*set CS22*/
			default:
			return Timer_clock_invalid;
			break;
		}
		break;
	}
	return OK_T;
}
void Timer_Deinit(Timer_num timer_NUM)
{
	if (timer_NUM == Timer_0)
	TCCR0 = 0;
	else if (timer_NUM== Timer_1)
	{
		TCCR1A = 0;
		TCCR1B = 0;
	}
	else if (timer_NUM == Timer_2)
	TCCR2 = 0;
}