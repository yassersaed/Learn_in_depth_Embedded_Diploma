#define F_CPU 1000000
#include<avr/interrupt.h>
#include <util/delay.h>

#include "BIT_MATH.h"
#include "ADC.h"
#include "LCD.h"

int ADC_Value, Volt, str[5];
 
int main(void)
{
   
	
	DDRA = 0x00;
	DDRC = 0xff;
	PORTC = 0x00;
	
	LCD_Init();
	sei();
	ADC_Init();
	
	
	while(1)
	{
		ADC_Start_Conversion();
	}
}

ISR(ADC_vect)
{
	ADC_Value = ADC_Read(1);
	Volt = (ADC_Value * 5/ 1023);
	Volt = (Volt*1000);
	itoa(Volt, str, 10);
	LCD_SendString("The Volt is= ");
	LCD_GO_TO(1,0);
	LCD_SendString(str);
	LCD_SendString("mv");
	_delay_ms(1000);
	LCD_Clear();
	
}


