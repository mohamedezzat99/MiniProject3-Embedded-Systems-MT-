/*
 * dcmotor.h
 *
 *  Created on: Oct 11, 2021
 *      Author: Mohamed Ezzat
 */

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"

typedef enum {
	Stop, CW, ACW
} DcMotor_State;

void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State, uint8);

#define DCMOTOR_PORT_ID 1
#define DCMOTOR_PIN_IN1 0
#define DCMOTOR_PIN_IN2 1
#define DCMOTOR_PIN_E	3
#endif /* DCMOTOR_H_ */
