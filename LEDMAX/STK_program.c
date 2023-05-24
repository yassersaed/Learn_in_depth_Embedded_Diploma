/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 25 August 2020                                                    */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"


static void(*MSTK_CallBack)(void); 

static u8 MSTK_u8ModeOfInterval;


void MSTK_voidInit(void)
{
	#if       MSTK_CLOCK_SRC == CLOCK_SRC_AHB
	 /* Disable STK ,Disable STK Interrupt , Set clock source AHB */
	             MSTK -> CTRL = 0x00000004;
	 
	#else     MSTK_CLOCK_SRC == CLOCK_SRC_AHB/8
	/* Disable STK ,Disable STK Interrupt , Set clock source AHB/8 */
	
	            MSTK -> CTRL = 0x00000000;
	 #endif
	 
}



void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	MSTK -> LOAD = Copy_u32Ticks;                         // load the value
	
	SET_BIT(MSTK -> CTRL , 0);                           // enable counter
	
	while(GET_BIT(MSTK -> CTRL , 16) == 1);             // wait untill the flag be high
	
    SET_BIT(MSTK -> CTRL , 0);                         // disable timer
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
	
}



void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*ptr) (void))
{
	MSTK -> LOAD = Copy_u32Ticks;
	
	SET_BIT(MSTK -> CTRL , 0);
	SET_BIT(MSTK -> CTRL , 1);
	
	MSTK_CallBack = ptr;
	
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
		
}



void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*ptr) (void))
{
	MSTK -> LOAD = Copy_u32Ticks;
	
	SET_BIT(MSTK -> CTRL , 0);      // enable counter
	SET_BIT(MSTK -> CTRL , 1);      // enable interrupt
	
	MSTK_CallBack = ptr;
	
	MSTK_u8ModeOfInterval = MSTK_PERIODIC_INTERVAL;
	
}



void MSTK_voidStopInterval(void)
{
	CLR_BIT(MSTK -> CTRL , 1);              // disable interrupt
	
    SET_BIT(MSTK->CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
	 
}



u8   MSTK_u8GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime = 0;
	
	Local_u32ElapsedTime = MSTK -> LOAD - MSTK -> VAL ;
	
	return Local_u32ElapsedTime;
	
}



u8   MSTK_u8GetRemainingTime(void)
{
	u32 Local_u32RemainingTime = 0;
	
	Local_u32RemainingTime = MSTK -> VAL ;
	
	return Local_u32RemainingTime;
	
}



void SysTick_Handler(void)
{
	u8 Local_u8Variable;
	
	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
	
		CLR_BIT(MSTK->CTRL, 1);          // disable interrupt
	
		
		SET_BIT(MSTK->CTRL, 0);         //  Stop Timer 
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}
	
	
	MSTK_CallBack();
	
	/* Clear interrupt flag  clear by read*/
	Local_u8Variable = GET_BIT(MSTK->CTRL,16);       
}


































