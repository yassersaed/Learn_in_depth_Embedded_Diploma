/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 25 August 2020                                                    */
/*********************************************************************************/
#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H



/* Clock opions 
             RCC_HSE_CRYSTAL      
             RCC_HSE_RC           
             RCC_HSI              
             RCC_PLL     */
			 
#define RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL 



/*PLL options
           RCC_PLL_IN_HSI_DIV_2
		   RCC_PLL_IN_HSE_DIV_2
		   RCC_PLL_IN_HSE           */
		   
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_INPUT  RCC_PLL_IN_HSE_DIV_2
#endif	   



/* PLL mul options : 2 to 16 */
#if RCC_CLOCK_TYPE == RCC_PLL
#define RCC_PLL_MUL_VAL   4
#endif



#endif