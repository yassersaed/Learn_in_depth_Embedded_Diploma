/*
 * main.c
 *
 *  Created on: Sep 15, 2020
 *      Author: Infotech
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"
#include "RCC_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "LEDMAT_config.h"

u8 DataArray[8] = {0, 124, 18, 18, 18, 124, 0, 0};
void main(void)
{
 	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);   //GPIOA
	RCC_voidEnableClock(RCC_APB2,3);

	MSTK_voidInit();

	HLEDMAX_voidInit();
	HLEDMAX_voidDisplay(DataArray);




}
