#include <avr/io.h>
#include "Counter0.h"
#include "Keypad.h"
#include "LCD.h"


unsigned char  key ,sec = 0, min = 0;

int main( void )
{
	DDRC  = 0xff;		
	DDRD  = 0xff;		
	PORTC = 0x00;			
	PORTD = 0x00;			
	
	Counter0_Init( );
	
	LCD_Init();
	
	LCD_SendString("'+'TO Adjust sec");
	LCD_GO_TO(1,0);
	LCD_SendString("'-'TO Adjust Min");
	LCD_GO_TO(2,0);
	LCD_SendString("'ON'To Reset Clk");
	LCD_GO_TO(3,0);
	LCD_SendString("'='TO Resume Clk");
	
	while (1)
	{
		key = keyPressed();
		if (key == 1)
		{
			if (TCNT0 >= 1)
			{
				TCNT0 = 0;
				sec++;//increment sec
				PORTD = sec;//display if num. of sec <10
				DisplySec(sec);//edit num. of sec >=10
				
				if (sec == 60)
				{
					min++;//increment min
					PORTC = min;
					sec = 0; 
					PORTD = sec;//display if num. of min <10
					DisplyMin(min);//edit num. of min >=10
					
					if (min == 60)
					{
						min = 0;
						PORTC = min;
						sec = 0;
						PORTD = sec;
					}
				}
			}
			
		}
		else if (key == '+')//Adjust sec
		{
			TCCR0 = 0;//stop the external clock source 
			sec++;//increment sec
			PORTD = sec;//if sec <10
			DisplySec(sec);//edit num. of sec >=10
			
		}
		else if (key == '-')//Adjust min
		{
			TCCR0 = 0;//stop the external clock source 
			min++;//increment min
			PORTC = min;//if min <10
			DisplyMin(min);//edit num. of min >=10
		}
		
		else if (key == 'C')
		{
			TCNT0 = 0;//clear control register
			sec = 0;
			min = 0;
			PORTD = sec;
			PORTC = min;
		}
		else if (key == '=')//Reset clock
		{
			DDRB &= ~(1<<PB0);
			TCCR0 |= (1<<CS02)|(1<<CS01)|(1<<CS00);
		}
		
		
	}
}