/*
 * Ultra_sonic.c
 *
 *  Created on: Jun 16, 2023
 *      Author: dabou
 */
#include <avr/io.h>
#include "Ultra_sonic.h"
#include "icu.h"
#include "gpio.h"
#include <util/delay.h>

uint8 g_edgeCount = 0;
uint16 g_timeHigh = 0;
uint16 g_timePeriod = 0;
uint16 g_timePeriodPlusHigh = 0;

void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		ICU_setEdgeDetectionType(RAISING);
	}
	else if(g_edgeCount == 3)
	{
		g_timePeriod = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 4)
	{
		g_timePeriodPlusHigh = ICU_getInputCaptureValue();

		g_timeHigh = (g_timePeriodPlusHigh - g_timePeriod);

		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(RAISING);
		g_edgeCount = 0;
	}


}
void Ultrasonic_init(void)
{

	SREG |= (1<<7);
	ICU_ConfigType conf = {F_CPU_8,RAISING};
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	ICU_init(&conf);
}

void Ultrasonic_Trigger()
{

	GPIO_writePin(PORTB_ID, PIN5_ID, 1);
	_delay_us(10);
	GPIO_writePin(PORTB_ID, PIN5_ID, 0);

}

uint16 Ultrasonic_readDistance(void)
{

	uint8 distance_measured = 0;
	Ultrasonic_Trigger();
	distance_measured = ceil( g_timeHigh/58.8);
	return distance_measured;


}
