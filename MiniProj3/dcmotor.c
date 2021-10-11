/*
 * dcmotor.c
 *
 *  Created on: Oct 11, 2021
 *      Author: Mohamed Ezzat
 */

#include "dcmotor.h"
#include "gpio.h"
#include "pwm.h"



void DcMotor_Init(void) {
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN1, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN2, PIN_OUTPUT);
	GPIO_setupPinDirection(DCMOTOR_PORT_ID, DCMOTOR_PIN_E, PIN_OUTPUT);

	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN1, 0);
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN2, 0);
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_E, 0);
}

void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN1, (state & 0x01)); /* take LSB and put it on IN1 pin */
	GPIO_writePin(DCMOTOR_PORT_ID, DCMOTOR_PIN_IN2, (state & 0x02)); /* take 2nd LSB and put it on IN2 pin */
	PWM_Timer0_Init(speed);
}
