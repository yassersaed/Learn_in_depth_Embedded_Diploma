#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "LCD.h"

void LCD_SendCommand( unsigned char cmnd )
{
	LCD_PORT = (LCD_PORT & 0x0F) | (cmnd & 0xF0); //sending Higher bits
	LCD_PORT &= ~ (1<<RS);		//command mode
	LCD_PORT |= (1<<EN);		// Enable Pulse
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);

	_delay_us(200);

	LCD_PORT = (LCD_PORT & 0x0F) | (cmnd << 4);  //sending Lower bits
	LCD_PORT |= (1<<EN);
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);
	_delay_ms(2);
}


void LCD_SendChar( unsigned char data )
{
	LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0); //sending Higher bits
	LCD_PORT |= (1<<RS);		// Data mode
	LCD_PORT|= (1<<EN);        //Enable pulse
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);

	_delay_us(200);

	LCD_PORT = (LCD_PORT & 0x0F) | (data << 4); //sending Lower bits
	LCD_PORT |= (1<<EN);
	_delay_us(1);
	LCD_PORT &= ~ (1<<EN);
	_delay_ms(2);
}

void LCD_Init (void)
{
	LCD_DIR = 0xFF;			 //LCD PORT ==> Output
	_delay_ms(20);
	
	LCD_SendCommand(0x02);		        // send for 4 bit initialize of LCD
	LCD_SendCommand(0x28);              // 2 line, 5*7 matrix in 4_bit mode
	LCD_SendCommand(0x0c);              // Display on cursor off
	LCD_SendCommand(0x06);              // Increment cursor
	LCD_SendCommand(0x01);              // Clear display
	_delay_ms(2);
}


void LCD_SendString (char *str)
{
	while((*str)!='\0')
	{
		LCD_SendChar(*str);
		str++;

	}
}


void LCD_Clear(void)
{
	LCD_SendCommand (0x01);		// Clear display
	_delay_ms(2);
	LCD_SendCommand (0x80);		// Cursor at home position
}

void LCD_GO_TO(unsigned char row,unsigned char col)
{
	unsigned char address;
	switch(row)
	{
		case 0:
		address=col+0x80;
		break;
		case 1:
		address=col+0xC0;
		break;
		case 2:
		address=col+0x90;
		break;
		case 3:
		address=col+0xD0;
		break;
	}
	LCD_SendCommand(address);
}