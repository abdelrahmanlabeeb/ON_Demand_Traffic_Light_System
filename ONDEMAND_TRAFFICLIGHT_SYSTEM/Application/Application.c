/*
* Application.c
*
* Created: 9/4/2022 5:20:04 AM
*  Author: Abdelrahman
*/
#include "Application.h"

void app_init(void)
{
	/*initializing traffic lights as output*/
	LED_init(CAR, Green);
	LED_init(CAR, Yellow);
	LED_init(CAR, Red);
	// initializing Pedestrian lights as output
	LED_init(Pedestrian,Green);
	LED_init(Pedestrian,Yellow);
	LED_init(Pedestrian,Red);
	// initializing Pedestrian button as input
	BUTTON_init('D',button);
	// initially the red light is on
	LED_ON(CAR,Red);
	/*set the ISR to call Pedestrian_mode when interrupt triggered */
	set_INT0_callbackptr(Pedestrian_mode);
	/*initialize external interrupt
	*Enable global interrupt
	*Enable INT0 external interrupt
	*set the sense as rising edge*/
	sei;
	EXT_INT_Config int_config;
	int_config.ext_int_num = INT_0;
	int_config.ext_int_sense = RISE;
	Ext_INT_init(&int_config);

}
void app_start(void)
{

	while (1)
	{
		
		//Stage 1 RED OFF, YELLOW ON
		Delay_s(5);
		LED_OFF(CAR,Red);
		LED_ON(CAR,Yellow);
		// STAGE 2 YELLOW OFF, GREEN ON
		delay_toggle_Car(5);
		LED_OFF(CAR,Yellow);
		LED_ON(CAR,Green);
		
		//STAGE 3 GREEN OFF, YELLOW ON
		Delay_s(5);
		LED_OFF(CAR,Green);
		LED_ON(CAR,Yellow);
		
		//STAGE 4 YELLOW OFF, RED ON
		delay_toggle_Car(5);
		LED_OFF(CAR,Yellow);
		LED_ON(CAR,Red);
		
	}
	
}

void Pedestrian_mode(void)
{
	uint8_t state = 0;
	Read_Car(&state); // read traffic light state (which light is on at the moment)
	switch(state)
	{
		case Red: // in case of red light is on
		LED_ON(Pedestrian,Green); // turn pedestrian green light on
		Delay_s(5);
		LED_OFF(Pedestrian,Green); // turn pedestrian lights off and back to normal mode
		break;
		
		case Green: // in case of green light is on
		// STAGE 1 Car yellow and green on, Pedestrian yellow and red on
		LED_ON(CAR,Yellow);
		LED_ON(Pedestrian,Red);
		LED_ON(Pedestrian,Yellow);
		delay_toggle_pedstrain(5);
		
		//STAGE 2  Car red on , Pedestrian green on
		LED_OFF(CAR,Green);
		LED_ON(CAR,Red);
		LED_OFF(CAR,Yellow);
		LED_OFF(Pedestrian,Red);
		LED_ON(Pedestrian,Green);
		LED_OFF(Pedestrian,Yellow);
		Delay_s(5);
		
		// STAGE 3 Car  Yellow on , Pedestrian yellow on
		LED_OFF(CAR,Red);
		LED_ON(CAR,Yellow);
		LED_ON(Pedestrian,Yellow);
		delay_toggle_pedstrain(5);
		
		// STAGE 4 Car green on , Pedestrian red on
		LED_OFF(Pedestrian,Green);
		LED_ON(Pedestrian,Red);
		LED_OFF(Pedestrian,Yellow);
		LED_ON(CAR,Green);
		LED_OFF(CAR,Yellow);
		Delay_s(5);
		
		// Pedestrian lights off, back to normal mode
		LED_OFF(Pedestrian,Red);
		break;
		
		case Yellow: // in case of yellow light is on
		// STAGE 1 Car yellow on, Pedestrian yellow and red on
		LED_ON(CAR,Yellow);
		LED_ON(Pedestrian,Red);
		LED_ON(Pedestrian,Yellow);
		delay_toggle_pedstrain(5);
		
		//STAGE 2  Car red on , Pedestrian green on
		LED_ON(CAR,Red);
		LED_OFF(CAR,Yellow);
		LED_OFF(Pedestrian,Red);
		LED_ON(Pedestrian,Green);
		LED_OFF(Pedestrian,Yellow);
		Delay_s(5);
		
		// STAGE 3 Car  Yellow on , Pedestrian yellow on
		LED_OFF(CAR,Red);
		LED_ON(CAR,Yellow);
		LED_ON(Pedestrian,Yellow);
		delay_toggle_pedstrain(5);
		
		// STAGE 4 Car green on , Pedestrian red on
		LED_OFF(Pedestrian,Green);
		LED_ON(Pedestrian,Red);
		LED_OFF(Pedestrian,Yellow);
		LED_ON(CAR,Green);
		LED_OFF(CAR,Yellow);
		Delay_s(5);
		
		// Pedestrian lights off, back to normal mode
		LED_OFF(Pedestrian,Red);
		LED_OFF(CAR,Green);
		break;
		
		default:
		break;

	}
}
void delay_toggle_Car(double sec)
{
	while (sec > 0.5)
	{
		Delay_s(0.5);
		LED_Toggle(CAR,Yellow);
		sec -=0.5;
	}
	Delay_s(sec);
}
void delay_toggle_pedstrain(double sec)
{
	while (sec > 0.5)
	{
		Delay_s(0.5);
		LED_Toggle(CAR,Yellow);
		LED_Toggle(Pedestrian,Yellow);
		sec -=0.5;
	}
	Delay_s(sec);
}


void Read_Car(uint8_t *LEDptr)
{
	/*
	* reads which light is on in car traffic lights 
	* sends the open light to the address pointed to by LEDptrr
	*/
	LED_read(CAR,Green,LEDptr); // Reads the pin connected to Green light 
	if(*LEDptr == L_HIGH)// if its on
	*LEDptr = Green;// returns Green 
	else
	{
		LED_read(CAR,Yellow,LEDptr); // Reads the pin connected to yellow light 
		if(*LEDptr == L_HIGH) // if its on
		*LEDptr = Yellow; // returns Yellow 
		else
		{
			LED_read(CAR,Red,LEDptr);  // Reads the pin connected to Red light
			if(*LEDptr == L_HIGH) // if its on
			*LEDptr = Red; // returns Red 
		}
	
	if(*LEDptr == L_LOW) // in case all lights are off 
	*LEDptr = Yellow; // then the Yellow is blinking state so we set LED as yellow 
	}
}