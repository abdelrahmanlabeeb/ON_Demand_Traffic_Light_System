/*
 * Application.h
 *
 * Created: 9/4/2022 5:19:12 AM
 *  Author: Abdelrahman
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_
#include "../ECUAL/BUTTON/BUTTON.h"
#include "../ECUAL/LED/LED.h"
#include "../MCAL/Interrupts/Interrupts.h"
#include "../ECUAL/DELAY/delay.h"
/*
APP_init Skeleton:
*Enable global interrupts pin I
*Enable External interrupt INT0
*set CAR and Pedestrian LEDs as output
*set INT0 pin as input
*sets the red light on as a starting condition
*/
void app_init(void);
/*
APP_start Skeleton:
*run the normal mode
*Red on for 5 seconds 
*Yellow blinking for 5 seconds 
*Green on for 5 seconds  
*/
void app_start(void);
/*
Pedestrian_mode Skeleton:
*checks the current traffic light state 
*if current state is Red 
  -CAR Red and Pedestrian Green will be on for 5 seconds 
  - Back to the normal mode 
  -normal starts with Yellow on (next after red)
*if current state is Green 
  1-Pedestrian Red and CAR Green will be on for 5 seconds 
  2-Pedestrian Red/Yellow will be on and CAR Green/Yellow will be on for 5 seconds 
  3-Pedestrian Green and CAR Red will be on for 5 seconds 
  4-Pedestrian Green/Yellow and CAR Yellow will be on for 5 seconds 
  5-Pedestrian Red and CAR Green will be on for 5 seconds 
  6-Back to the normal mode 
  -normal mode starts from Yellow
  *if current state is Yellow
   1-Pedestrian Red and CAR Yellow will be on for 5 seconds
   2-Pedestrian Red/Yellow will be on and CAR Yellow will be on for 5 seconds
   3-Pedestrian Green and CAR Red will be on for 5 seconds
   4-Pedestrian Green/Yellow and CAR Yellow will be on for 5 seconds
   5-Pedestrian Red and CAR Green will be on for 5 seconds
   6-Back to the normal mode
   -normal mode starts from Yellow*/
void Pedestrian_mode();
/*delay with toggling the car yellow LED*/
void delay_toggle_Car(double sec);
/*delay with toggling the car and pedestrian yellow LEDs*/
void delay_toggle_pedstrain(double sec);
/* Read_Car Skeleton
* reads which light is on in car traffic lights 
* sends the open light to the address pointed to by LEDptrr
*/
void Read_Car (uint8_t *LED);
#endif /* APPLICATION_H_ */