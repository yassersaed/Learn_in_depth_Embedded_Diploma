/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 31 August 2020                                                    */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "HLEDMAT_interface.h"
#include "HLEDMAT_private.h"
#include "LEDMAT_config.h"



void HLEDMAX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMAX_ROW0_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_ROW1_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_ROW2_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_ROW3_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_ROW4_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_ROW5_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_ROW6_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_ROW7_PIN,0b0010);
	
	MGPIO_voidSetPinDirection(LEDMAX_COL0_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_COL1_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_COL2_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_COL3_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_COL4_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_COL5_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_COL6_PIN,0b0010);
	MGPIO_voidSetPinDirection(LEDMAX_COL7_PIN,0b0010);
}




void HLEDMAX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
		
	/* column0 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[0]);
	MGPIO_voidSetPinValue(LEDMAX_COL0_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec
	
	/* column1 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[1]);
	MGPIO_voidSetPinValue(LEDMAX_COL1_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec
	
	/* column2 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[2]);
	MGPIO_voidSetPinValue(LEDMAX_COL2_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec
	
	/* column3 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[3]);
	MGPIO_voidSetPinValue(LEDMAX_COL3_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec
	
	/* column4 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[4]);
	MGPIO_voidSetPinValue(LEDMAX_COL4_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec
	
	/* column5 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[5]);
	MGPIO_voidSetPinValue(LEDMAX_COL5_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec

    /* column6 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[6]);
	MGPIO_voidSetPinValue(LEDMAX_COL6_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec
	
    /* column7 */
	DisableAllColumns();
	SetRowValues(Copy_u8Data[7]);
	MGPIO_voidSetPinValue(LEDMAX_COL7_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500); //2.5msec
		
    }
	
}




void DisableAllColumns(void)
{
	MGPIO_voidSetPinValue(LEDMAX_COL0_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMAX_COL1_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMAX_COL2_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMAX_COL3_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMAX_COL4_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMAX_COL5_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMAX_COL6_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LEDMAX_COL7_PIN,GPIO_HIGH);
	
}




void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit;
	
	
	Local_u8Bit = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinDirection(LEDMAX_ROW0_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinDirection(LEDMAX_ROW1_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinDirection(LEDMAX_ROW2_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinDirection(LEDMAX_ROW3_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinDirection(LEDMAX_ROW4_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinDirection(LEDMAX_ROW5_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinDirection(LEDMAX_ROW6_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinDirection(LEDMAX_ROW7_PIN,Local_u8Bit);
	
	
}






