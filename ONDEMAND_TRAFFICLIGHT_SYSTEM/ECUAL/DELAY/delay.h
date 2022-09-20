/*
 * delay.h
 *
 * Created: 9/5/2022 1:50:19 PM
 *  Author: Abdelrahman
 */ 


#ifndef DELAY_H_
#define DELAY_H_
#include "../../MCAL/TIMER/Timer.h"
#include "../../Utilities/Common_macros.h"
#include <math.h>

typedef enum {
	OK_D,DELAY_ERROR
}EN_Delay_Error;
/*Deleay_s Skeleton:
*takes the required delay in seconds
*sets Timer1 , Overflow mode
*resets the Timer flag
*sets the Prescaler according to the required delay
*calculates the tick time according to the Prescaler
*calculates the Timer initial value
*waits for the Timer Overflow flag to be set
*stops the Timer */
EN_Delay_Error Delay_s(double sec);


#endif /* DELAY_H_ */