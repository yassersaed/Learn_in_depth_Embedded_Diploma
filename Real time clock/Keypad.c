#include "Keypad.h"


/*********************************************************************
* Function    : unsigned char keyPress(void);
*
* DESCRIPTION : This function used to get pressed key.
*
* PARAMETERS  : Non.
*
* Return Value: Pressed key or if there is no pressed key it return 1.
*
* Note        : we connected the col to output pins and rows to input pins of the microcontroller. 
*               
***********************************************************************/

unsigned char keyPressed(void)
{
	unsigned char col,row;
	while(1)
	{
		KEYPAD_DDR = (0xF0);//higher bits for col and lower bits for rows
		for(col=0;col<NUM_C;col++) //loop for columns
		{
			KEYPAD_PRT |= 0xFF; //set all rows to high 
			KEYPAD_PRT &= (~(0b00010000<<col)); // check col by col
			for(row=0;row<NUM_R;row++) //loop for rows
			{
				if((KEYPAD_PIN & (1<<row)) == 0) //check if the switch is press in this row
				{
					_delay_ms(30);
					if((KEYPAD_PIN & (1<<row)) == 0) //check if the switch is press in this row
					{
						#if (NUM_C == 3)
						unsigned char keypad_4x3[NUM_R][NUM_C] = {'1','2','3',
							'4','5','6',
							'7','8','9',
						    '*','0','#'};
						while((KEYPAD_PIN & (1<<row)) == 0);
						return keypad_4x3[row][col];
						#else
						unsigned char keypad_4x4[NUM_R][NUM_C] = {'7','8','9','/',
							'4','5','6','*',
							'1','2','3','-',
						    'C','0','=','+'};
						while((KEYPAD_PIN & (1<<row)) == 0);
						return keypad_4x4[row][col];
						#endif
					}
				}
			}
		}
		return 1;
	}
}
