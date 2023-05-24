/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 25 August 2020                                                    */
/*********************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8preId);
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PreId);


/*Bus Types*/
#define RCC_AHB       0
#define RCC_APB1      1
#define RCC_APB2      2


/* Clock Types */
#define RCC_HSE_CRYSTAL      0
#define RCC_HSE_RC           1
#define RCC_HSI              2
#define RCC_PLL              3


/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2




#endif
