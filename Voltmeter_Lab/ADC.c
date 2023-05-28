#include <avr/io.h>
#include "ADC.h"


void ADC_Init(void)
{
	ADMUX |= (1<<REFS0)|(1<<MUX0);
	ADCSRA |= (1 << ADEN);     //enable ADC
	ADCSRA |= (1 << ADIE);     //enable interrupt
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1);    //8_pre
}

int ADC_Read(uint8_t Channel)
{
	Channel &=0x07;//reassignation for the input argument
	ADMUX |=Channel;
	return ADC;
}

void ADC_Start_Conversion(void)
{
	ADCSRA |=(1<<ADSC);  //start conversion
}