/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


// u8 variable as we have only 240 interrupt to control

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID <=31)
	{
		NVIC_ISER0 = (1 << Copy_u8InterruptID);         // not use Set_Bit as zero has no effect
	}
	else if (Copy_u8InterruptID <=59)
	{
		Copy_u8InterruptID -= 32;                      // to return to bit 0
		NVIC_ISER1 = (1 << Copy_u8InterruptID);
	}
}



void MNVIC_voidDisnableInterrupt(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID <=31)
	{
		NVIC_ICER0 = (1 << Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <=59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ICER1 = (1 << Copy_u8InterruptID);
	}
}



void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID <=31)
	{
		NVIC_ISPR0 = (1 << Copy_u8InterruptID);
	}
	else if (Copy_u8InterruptID <=59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ISPR1 = (1 << Copy_u8InterruptID);
	}
}



void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID <=31)
	{
		NVIC_ICPR0 = (1 << Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <=59)
	{
		Copy_u8InterruptID -= 32;
		NVIC_ICPR1 = (1 << Copy_u8InterruptID);
	}
}



u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptID)
{
	u8 Local_u8Result;
	
	if (Copy_u8InterruptID <=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8InterruptID);
	}
	else if(Copy_u8InterruptID <=59)
	{
		Copy_u8InterruptID -= 32;
		Local_u8Result = GET_BIT( NVIC_IABR1 , Copy_u8InterruptID);
	}
	return Local_u8Result;
}


void MNVIC_voidSetPriority(s8 Copy_u8PriorityID,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority,u32 Copy_u32Group)
{
	u8 Local_u8Priority = Copy_u8GroupPriority | (Copy_u8GroupPriority << ((Copy_u32Group - 0x05FA0300)/0x100));
	
	
		/* core peripheral 			*/
	if(Copy_u8PriorityID < 0)
	{

	}
	/* external peripheral		*/ /*EXTI0 = 6*/
	else if (Copy_u8PriorityID >= 0)
	{
		NVIC_IPR[Copy_u8PriorityID] = Local_u8Priority <<4;   
	}
	
	SCB_AIRCR = Copy_u32Group;
}




