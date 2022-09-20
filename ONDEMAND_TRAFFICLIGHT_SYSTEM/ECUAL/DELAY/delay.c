/*
* delay.c
*
* Created: 9/5/2022 1:50:06 PM
*  Author: Abdelrahman
*/
#include "delay.h"



EN_Delay_Error Delay_s(double sec)
{
volatile unsigned long F_CPU = 1000000;
volatile double clock_cycle = 1.0/F_CPU;
volatile double tick_time;
TIFR |= (1<<2);
Timer_config_type timer_1_config;
timer_1_config.timer_num = Timer_1; /*use timer 1 to get wide range of delays without number of overflows*/
timer_1_config.OCR_init = 0;
timer_1_config.timer_mode = Overflow;
if (sec > 16.777216)
{
timer_1_config.timer_prescaler = CPU_1024;
tick_time = clock_cycle*1024;
timer_1_config.TCNT_init = ceil(pow(2,16)-(sec/tick_time));
}
else if (sec > 4.194304 && sec<16.777216)
{
	timer_1_config.timer_prescaler = CPU_256;
	tick_time = clock_cycle*256;
	timer_1_config.TCNT_init = ceil(pow(2,16)-(sec/tick_time));
}
else if (sec > 0.524288 && sec<4.194304)
{
		timer_1_config.timer_prescaler = CPU_64;
		tick_time = clock_cycle*64;
		timer_1_config.TCNT_init = ceil(pow(2,16)-(sec/tick_time));
}
else if (sec > 0.065536 && sec<0.524288)
{
	timer_1_config.timer_prescaler = CPU_8;
	tick_time = clock_cycle*8;
	timer_1_config.TCNT_init = ceil(pow(2,16)-(sec/tick_time));
}
else if (sec <= 0.065536)
{
	timer_1_config.timer_prescaler = CPU_clock;
	tick_time = clock_cycle;
	timer_1_config.TCNT_init = ceil(pow(2,16)-(sec/tick_time));
}
		uint8_t flag = 0;
		if (Timer_init(&timer_1_config) == OK_T)
	{	
		while(flag == 0)
		Timer1_checkflag(&flag);
		Timer_Deinit(Timer_1);
		return OK_D;
		}
		else
		return DELAY_ERROR;
}