#include <avr/io.h>

void Timer0_Init(void)
{
	DDRB &= ~(1<<PB0);
	TCCR0 |= (1<<CS02)|(1<<CS01)|(1<<CS00);
}

