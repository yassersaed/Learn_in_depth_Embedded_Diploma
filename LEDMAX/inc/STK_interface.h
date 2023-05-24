/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 25 August 2020                                                    */
/*********************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks );
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*ptr) (void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*ptr) (void));
void MSTK_voidStopInterval(void);
u8   MSTK_u8GetElapsedTime(void);
u8   MSTK_u8GetRemainingTime(void);
void SysTick_Handler(void);



#endif