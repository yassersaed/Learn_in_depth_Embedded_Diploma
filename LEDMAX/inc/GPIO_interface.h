/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 25 August 2020                                                    */
/*********************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


void MGPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Mode);
void MGPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
u8 MGPIO_u8GetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin);


#define GPIOA   0
#define GPIOB   1
#define GPIOC   2


#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10   10
#define PIN11   11
#define PIN12   12
#define PIN13   13
#define PIN14   14
#define PIN15   15

#define GPIO_HIGH   1
#define GPIO_LOW    0
















#endif