/*
 * main.c
 *
 *  Created on: Oct 1, 2020
 *      Author: Infotech
 */


#include "../../STP/include/BIT_MATH.h"
#include "../../STP/include/DIO_interface.h"
#include "../../STP/include/EXTI0_interface.h"
#include "../../STP/include/NVIC_interface.h"
#include "../../STP/include/RCC_interface.h"
#include "../../STP/include/STD_TYPES.h"
#include "../../STP/include/STK_interface.h"

volatile u8   u8StartFlag       = 0;
volatile u32  u32FrameData[50]  = {0};
volatile u8   u8EdgeCounter     = 0;
volatile u8   u8Data            = 0;

void voidPlay(void)
{
	switch(u8Data)
	{

	    case 17 : MGPIO_VidSetPinValue(GPIOA,1,HIGH); break;
	    case 18 : MGPIO_VidSetPinValue(GPIOA,2,HIGH);  break;

	}
}


void voidTakeAction(void)
{
	u8 i;
	u8Data = 0;

	if ( (u32FrameData[0] >= 10000) && (u32FrameData[0] <= 14000) )   // check start bit
	{
		for (i=0;i<8;i++)
		{
			if (  (u32FrameData[17+i] >= 2000) && (u32FrameData[17+i] <=2300) )
			{
				SET_BIT(u8Data,i);
			}

			else
			{
				CLR_BIT(u8Data,i);
			}
		}
		voidPlay();
	}

	else
	{
		/* Invalid Frame */
	}
    /* for next button */
	u8StartFlag     = 0;
	u32FrameData[0] = 0;
	u8EdgeCounter   = 0;
}

void voidGetFrame(void)
{
	if (u8StartFlag == 0)      // chack for falling edge
	{
		/* Start Timer */
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8StartFlag = 1;
	}

	else
	{
		u32FrameData[u8EdgeCounter] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
		u8EdgeCounter++;
	}
}


void main(void)
{
	/* RCC Initialize */
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); /* GPIOA Enable Clock */

	/* IO Pins Initialization */
	MGPIO_VidSetPinDirection(GPIOA,0,0b0100); /* A0 Input Floating        */
	MGPIO_VidSetPinDirection(GPIOA,1,0b0010); /* A1 Output PP "RED"       */
	MGPIO_VidSetPinDirection(GPIOA,2,0b0010); /* A1 Output PP "GREEN"     */
	MGPIO_VidSetPinDirection(GPIOA,3,0b0010); /* A1 Output PP "BLUE"      */


	/* EXTI Initializtion */
	MEXTI_voidSetCallBack(voidGetFrame);
	MEXTI_voidInit(); /* A0 EXTI0 Enabled / Falling Edge */

	/* Enable EXTI0 from NVIC */
	MNVIC_voidInit();
	MNVIC_voidEnableInterrupt(6); /* EXTI0 */

	/* SysTick Init */
	MSTK_voidInit(); /* Enable SysTick AHB/8 = 1MHZ */

	while(1)
	{

	}

}
