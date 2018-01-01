/* This code has been written for 4.5 Volts and current limited at 580mA, if Volts are changed speed will be affected and
 * and can be adjusted by adjusting d_time. MAX_STEPS will be adjusted when motor is finally placed in its actual
 * casing in radiator valve */

//Including Relevant libraries
#include <stdlib.h>
#include <stdio.h>
#include "em_device.h"
#include "em_chip.h"
#include "InitDevice.h"
#include "bsp.h"
#include "em_timer.h"
#include "em_gpio.h"
#include "em_system.h"
#include "em_emu.h"
#include "em_cmu.h"
#include "ustimer.h"

//Pins used to control motor
#define MOTOR_PORT gpioPortD
#define MOTOR_PIN1A 8
#define MOTOR_PIN1B 9
#define MOTOR_PIN2A 10
#define MOTOR_PIN2B 11

//Edit MAX_STEPS to control the maximum position of Radiator Valve
#define MAX_STEPS 700

//Delay time between each sequence, editing this will change the speed of motor
#define d_time  4000

//Starting Position of Valve, it is assumed the valve is completely closed at the start
int current_position = 0;

//Used during testing and debugging
int state = 1;

//To move motor outside/up
void cw(int steps)
{
	if (state == 1)
	{
		for(int i=0;i<steps;i++)
		{
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 0);
			USTIMER_Delay(d_time);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 0);
			USTIMER_Delay(d_time);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 1);
			USTIMER_Delay(d_time);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 1);
			USTIMER_Delay(d_time);
			//printf("%d \n",x);
			//x--;

		}
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 0);
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 0);
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 0);
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 0);
		state=0;
	}
}

//To move motor down
void ccw(int steps)
{
	if (state == 1)
	{
		for(int i=0;i<steps;i++)
		{
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 1);
			USTIMER_Delay(d_time);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 1);
			USTIMER_Delay(d_time);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 0);
			USTIMER_Delay(d_time);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 0);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 1);
			GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 0);
			USTIMER_Delay(d_time);
			//printf("%d \n",x);
			//x++;
		}
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1A, gpioModePushPull, 0);
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN1B, gpioModePushPull, 0);
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2A, gpioModePushPull, 0);
		GPIO_PinModeSet(MOTOR_PORT, MOTOR_PIN2B, gpioModePushPull, 0);
		state=0;

	}
}

//This function takes input from 0-100, which represents percent of Radiator Valve to be opened. Also updates
// and tracks the position of RV

int update_position(float x)
{
	int move_steps;
	float y;

	//Scale it to value of MAX_STEPS
	if(x<=100 && x>=0)
	{
		y = x/100.0;
		y = y * MAX_STEPS;
		//printf("\n Radiator will now be %f Percent opened",x);
	}
	else
	{
		//printf("\n Please enter values between 0-100 only !");
	}

	if(y>current_position)
	{
		move_steps = y - current_position;
		//printf("\n Opening Valve");
		state=1;
		cw(move_steps);
		current_position = current_position + move_steps;

	}
	else if(y<current_position)
	{
		move_steps = current_position - y;
		//printf("\n Closing Valve");
		state=1;
		ccw(move_steps);
		current_position = current_position - move_steps;
	}
	else
		{
		//printf("\n Already at the current position");
		}

	return current_position;
}






int main(void)

{
  /* Chip errata */
  CHIP_Init();
  BSP_Init( BSP_INIT_BCC );
  USTIMER_Init();

  //CMU_ClockEnable(cmuClock_TIMER1, true);
  /* Setup SysTick Timer for 1 msec interrupts  */
  //if (SysTick_Config(CMU_ClockFreqGet(cmuClock_CORE) / 1000)) while (1) ;


  /* Infinite loop */
  while (1) {

	  //ccw(200);

	  USTIMER_Delay(3000000);
	  update_position(60);
	  USTIMER_Delay(3000000);
	  update_position(80);
	  USTIMER_Delay(3000000);
	  update_position(40);
	  USTIMER_Delay(3000000);
	  update_position(20);
	  USTIMER_Delay(3000000);
	  update_position(100);
	  USTIMER_Delay(3000000);
	  update_position(0);
	  USTIMER_Delay(300000000);




	  //state=1;
	  //USTIMER_Delay(300000000);

  }
}
