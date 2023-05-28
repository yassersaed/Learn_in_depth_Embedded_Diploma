
#ifndef LCD_H_
#define LCD_H_

#define LCD_DIR  DDRC			//LCD data port direction
#define LCD_PORT PORTC			//LCD data port
#define RS PC0				//Register Select pin
#define EN PC1 				//Enable signal pin


void LCD_Init(void);
void LCD_SendCommand(unsigned char cmnd);
void LCD_SendChar(unsigned char data);
void LCD_SendString (char *str);
void LCD_GO_TO(unsigned char row,unsigned char col);
void LCD_Clear(void);


#endif /* LCD_H_ */