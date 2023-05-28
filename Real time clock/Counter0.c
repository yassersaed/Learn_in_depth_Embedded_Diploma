#include <avr/io.h>
#include "Counter0.h"



/*********************************************************************
* Function    : void Counter0_Init(void);
*
* DESCRIPTION : This function used to Initialize Counter.
*
* PARAMETERS  : NON
*                                      
* Return Value: NON
*
* Note        : PINB0 input for external clock source
*               
***********************************************************************/
void Counter0_Init(void)
{
	DDRB &= ~(1<<PB0);
	TCCR0 |= (1<<CS02)|(1<<CS01)|(1<<CS00);
}




/*********************************************************************
* Function    : void DisplySec(unsigned char sec);
*
* DESCRIPTION : This function used to edit seconds to display on 7seg.
*
* PARAMETERS  : number of seconds.
*
* Return Value: NON
*
* Note        : we want to sec. on two 7seg so we used table if the value >= 10
*               so we add 6 to the sec value 
***********************************************************************/

void DisplySec(unsigned char sec)
{
	if (sec >= 10 & sec <= 19)
	PORTD += 6;// fixed the high bits and increment low bits by one  00010000
	if (sec >= 20 & sec <= 29)
	PORTD += 12;// fixed the high bits and increment low bits by one 00100000
	if (sec >= 30 & sec <= 39)
	PORTD += 18;// fixed the high bits and increment low bits by one 00110000
	if (sec >= 40 & sec <= 49)
	PORTD += 24;// fixed the high bits and increment low bits by one 01000000
	if (sec >= 50 & sec <= 59)
	PORTD += 30;// fixed the high bits and increment low bits by one 01010000
}

void DisplyMin(unsigned char min)
{
	if (min >= 10 & min <= 19)
	PORTC += 6;// fixed the high bits and increment low bits by one  00010000
	if (min >= 20 & min <= 29)
	PORTC += 12;// fixed the high bits and increment low bits by one 00100000
	if (min >= 30 & min <= 39)
	PORTC += 18;// fixed the high bits and increment low bits by one 00110000
	if (min >= 40 & min <= 49)
	PORTC += 24;// fixed the high bits and increment low bits by one 01000000
	if (min >= 50 & min <= 59)
	PORTC += 30;// fixed the high bits and increment low bits by one 01010000
}
