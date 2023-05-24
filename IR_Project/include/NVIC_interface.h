/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/
#ifndef NVIC_INTERFACE_H
#define  NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptID);
void MNVIC_voidDisnableInterrupt(u8 Copy_u8InterruptID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID);
void MNVIC_voidSetPriority(s8 Copy_u8PriorityID,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority,u32 Copy_u32Group);

#define   GROUP3        0x05FA0300    // 4 bits for group
#define   GROUP4        0x05FA0400    //3 bits for group and 1 for sub
#define   GROUP5        0x05FA0500   // 2 bits for group and 2 for sub
#define   GROUP6        0x05FA0600   // 1 bits for group and 3 for sub
#define   GROUP7        0x05FA0700   // 0 bits for group and 4 for sub


#endif
