/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/
#ifndef NVIC_PRAIVATE_H
#define  NVIC_PRAIVATE_H


#define NVIC_ISER0          *((volatile u32*)0xE000E100)    // Enable External interrupts from 0  to 31
#define NVIC_ISER1          *((volatile u32*)0xE000E104)

#define NVIC_ICER0          *((volatile u32*)0xE000E180)
#define NVIC_ICER1          *((volatile u32*)0xE000E184)

#define NVIC_ISPR0          *((volatile u32*)0xE000E200)
#define NVIC_ISPR1          *((volatile u32*)0xE000E204)

#define NVIC_ICPR0          *((volatile u32*)0xE000E280)
#define NVIC_ICPR1          *((volatile u32*)0xE000E284)

#define NVIC_IABR0          *((volatile u32*)0xE000E300)
#define NVIC_IABR1          *((volatile u32*)0xE000E304)

#define NVIC_IPR            ((volatile u8*)0xE000E400)

#define SCB_AIRCR           *((volatile u32*)0xE000ED0C)


#endif
