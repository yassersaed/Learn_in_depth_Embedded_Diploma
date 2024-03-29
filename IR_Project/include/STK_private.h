/*********************************************************************************/
/* Author    : Yasser Saeed                                                      */
/* Version   : V01                                                               */
/* Date      : 25 August 2020                                                    */
/*********************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct 
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL ;
}MSTK_T;


#define     MSTK     ((MSTK_T *)0xE000E010)



#define    CLOCK_SRC_AHB     0
#define    CLOCK_SRC_AHB_8   1


#define   MSTK_SINGLE_INTERVAL        0
#define   MSTK_PERIODIC_INTERVAL      1






#endif
