 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Mohamed Ezzat
 *
 *******************************************************************************/



#include "adc.h"
#include "common_macros.h"
#include "avr/io.h"

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX=0;
	SET_BIT(ADCSRA, ADEN);
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr ->ref_volt & 0x03) << 6 );
	ADCSRA = ( ADCSRA & 0xF8) | (Config_Ptr->prescaler & 0x07);


}

uint16 ADC_readChannel(uint8 a_channelNumber)
{
	ADMUX = (ADMUX & 0xE0) | (a_channelNumber & 0x1F);	/* insert channel number into MUX bits to select which pin to be ADC input */
	SET_BIT(ADCSRA, ADSC);								/* Start conversion */
	while(BIT_IS_CLEAR(ADCSRA, ADIF));					/* polling till checking that ADC conversion is done */
	SET_BIT(ADCSRA, ADIF);								/* clear ADIF flag */
	return ADC;
}


