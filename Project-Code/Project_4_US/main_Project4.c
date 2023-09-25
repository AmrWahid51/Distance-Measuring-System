/*
 * main_Project4.c
 *
 *  Created on: Jun 16, 2023
 *      Author: dabour
 */

#include "Ultra_sonic.h"
#include "lcd.h"
#include "std_types.h"
#include "std_types.h"

int main(void)
{
	LCD_init();
	Ultrasonic_init();
	uint8 distance = 0;
	LCD_displayString("Distance = ");

	while(1)
	{

		distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 12);
		LCD_intgerToString(distance);
		LCD_displayString("cm");

	}
}
