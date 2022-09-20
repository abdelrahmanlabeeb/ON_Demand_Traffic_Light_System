/*
 * ONDEMAND_TRAFFICLIGHT_SYSTEM.c
 *
 * Created: 9/3/2022 8:15:49 AM
 * Author : Abdelrahman
 */ 

//#include <avr/io.h>
#include "Application/Application.h"
void timer_test(void);
void ext_int_test(void);
int main(void)
{
	app_init();
	app_start();
	//LED_Toggle(Pedestrian, Yellow);
	/*Timer0_init_normal();
	LED_init('B',1);
	while(1)
	{
	for (int i = 0 ; i<31; i++)
	{
		flag0 = 0;
		Timer0_set_(0x04);
		Timer0_start_(1024);
		while (flag0 == 0)
		Timer0_checkflag(flag0ptr);
		Timer0_stop();
	}
	LED_Toggle('B',1);
	}*/
	/*Timer_test();*/
	/*sei;
	LED_init(CAR,Red);
	BUTTON_init('D',3);

	EXT_INT_Config int_config;
	int_config.ext_int_num = INT_1;
	int_config.ext_int_sense = RISE;
	Ext_INT_init(&int_config);
	set_INT1_callbackptr(ext_int_test);
	while(1);*/

}

	void Timer_test()
	{
	LED_init(CAR,Red);
	while(1)
	{
		LED_ON(CAR,Red);
		Delay_s(5);
		LED_OFF(CAR,Red);
		Delay_s(5);
	}
}
void ext_int_test()
{
	LED_Toggle(CAR,Red);
}