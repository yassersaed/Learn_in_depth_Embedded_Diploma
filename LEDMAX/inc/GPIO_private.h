/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 25 August 2020                                                    */
/*********************************************************************************/
#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


#define   GPIOA_BASE_ADDRESS     0x40010800
#define   GPIOB_BASE_ADDRESS     0x40010C00
#define   GPIOC_BASE_ADDRESS     0x40011000


  /* Registers adress for port A */
#define   GPIOA_CRL              *((u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define   GPIOA_CRH              *((u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define   GPIOA_IDR              *((u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define   GPIOA_ODR              *((u32 *)(GPIOA_BASE_ADDRESS + 0x0C))
#define   GPIOA_BSRR             *((u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define   GPIOA_BRR              *((u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define   GPIOA_LCKR             *((u32 *)(GPIOA_BASE_ADDRESS + 0x18))
 
  /* Registers adress for port B*/
#define   GPIOB_CRL              *((u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define   GPIOB_CRH              *((u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define   GPIOB_IDR              *((u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define   GPIOB_ODR              *((u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define   GPIOB_BSRR             *((u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define   GPIOB_BRR              *((u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define   GPIOB_LCKR             *((u32 *)(GPIOB_BASE_ADDRESS + 0x18))

 /* Registers adress for port C */
#define   GPIOC_CRL              *((u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define   GPIOC_CRH              *((u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define   GPIOC_IDR              *((u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define   GPIOC_ODR              *((u32 *)(GPIOC_BASE_ADDRESS + 0x0C))
#define   GPIOC_BSRR             *((u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define   GPIOC_BRR              *((u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define   GPIOC_LCKR             *((u32 *)(GPIOC_BASE_ADDRESS + 0x18))

 /*GPIO modes*/
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101


#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110


#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111


#define INPUT_ANALOGUE            0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PU_PD               0b1000






#endif