/*
 * MiniProj3.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mohamed Ezzat
 */

#include "MiniProj3.h"
#include "lcd.h"
#include "dcmotor.h"
#include "adc.h"
#include "lm35_sensor.h"

int main() {
	uint8 speed = 0;
	uint8 temp;
	DcMotor_State state;
	uint8 fanState;
	ADC_ConfigType ADC_Config;
	ADC_Config.prescaler = Div8;
	ADC_Config.ref_volt = internalVolt;
	DcMotor_Init();
	LCD_init();
	ADC_init(&ADC_Config);
	while (1) {
		temp = LM35_getTemperature();
		state = CW; /* init state as CW and only change it if fan is off */
		fanState = 1;
		if (temp < 30) {
			state = Stop;
			speed = 0;
			fanState = 0;
		} else if (temp >= 120) {
			speed = 100;
		} else if (temp >= 90) {
			speed = 75;
		} else if (temp >= 60) {
			speed = 50;
		} else if (temp >= 30) {
			speed = 25;
		}
		DcMotor_Rotate(state, speed);
		fanState ? LCD_displayStringRowColumn(0, 4, "Fan Is ON ") : LCD_displayStringRowColumn(0, 4, "Fan Is OFF");
		LCD_displayStringRowColumn(1, 4, "Temp = ");
		LCD_moveCursor(1, 10);
		LCD_intgerToString(temp);
	}
}

