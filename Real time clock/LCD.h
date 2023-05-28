
#ifndef LCD_H_
#define LCD_H_

#define LCD_DIR  DDRB			//LCD data port direction
#define LCD_PORT PORTB			//LCD data port
#define RS PB1				   //Register Select pin
#define EN PB2 				   //Enable signal pin


void LCD_Init(void);
void LCD_SendCommand(unsigned char cmnd);
void LCD_SendChar(unsigned char data);
void LCD_SendString (char *str);
void LCD_GO_TO(unsigned char row,unsigned char col);
void LCD_Clear(void);


#endif /* LCD_H_ */