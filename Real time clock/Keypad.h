#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000
#include <avr/io.h>
#include <util/delay.h>

#define KEYPAD_DDR DDRA
#define KEYPAD_PRT PORTA
#define KEYPAD_PIN PINA
#define NUM_C 4
#define NUM_R 4
unsigned char keyPressed(void);

#endif 