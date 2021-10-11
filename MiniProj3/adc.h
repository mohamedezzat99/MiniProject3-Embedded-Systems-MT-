/*
 * adc.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Mohamed Ezzat
 */

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


typedef enum
{
AREF, AVCC, internalVolt=3
} ADC_ReferenceVolatge;


typedef enum
{
	Div2_1, Div2_2, Div4, Div8, Div16, Div32, Div64, Div128
} ADC_Prescaler ;

typedef struct {
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;


uint16 ADC_readChannel(uint8);
void ADC_init(const ADC_ConfigType * Config_Ptr);

#endif /* ADC_H_ */
