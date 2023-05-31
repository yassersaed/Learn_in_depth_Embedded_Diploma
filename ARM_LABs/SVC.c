/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


#include "stm32f103x6.h"
#include "stm32f103_GPIO_driver.h"
#include "stm32f103_EXTI_driver.h"

uint8_t TaskA_flag, TaskB_flag, IRQ_Flag = 0;

#define TaskA_Stack_Size     100
#define TaskB_Stack_Size     100


#define OS_SET_PSP(add)             __asm volatile("mov r0, %0 \n\t msr psp, r0 " : : "r" (add));
#define OS_SWITCH_SP_TO_PSP         __asm volatile("mrs r0, CONTROL \n\t mov r1, #0x02 \n\t orr r0,r0,r1 \n\t msr CONTROL, r0");
#define OS_SWITCH_SP_TO_MSP         __asm volatile("mrs r0, CONTROL \n\t mov r1, #0x05 \n\t and r0,r0,r1 \n\t msr CONTROL, r0");

#define OS_Generate_Exsaption       __asm("SVC #0x3");


extern int _estack;

//main stack
unsigned int  _S_MSP = &_estack;
unsigned int  _E_MSP;


//proces stack
unsigned int _S_PSP_TA;
unsigned int _E_PSP_TA;


unsigned int _S_PSP_TB;
unsigned int _E_PSP_TB;

enum CPUAcessLevel {privileged , none_privileged };


void SVC_Handker()
{
	Switch_CPU_Access_Level(privileged);
}




void Switch_CPU_Access_Level(enum CPUAcessLevel  level)
{
	switch(level){

	case none_privileged:
		__asm ("mrs r3, CONTROL \n\t"
				"orr r3,r3, #0x1 \n\t"
				"msr CONTROL , r3");
		break;
	case privileged:
		__asm("mrs r3, CONTROL \n\t"
				"lsr r3,r3,#0x1\n\t"
				"lsl r3,r3,#0x1\n\t"
				"msr CONTROL , r3");
		break;
	}
}


void EXTI9_CALLBACK(void)
{
	//IRQ_Flag = 1;
	if(IRQ_Flag == 0)
	{
		TaskA_flag == 1;
		IRQ_Flag = 1;
	}else if(IRQ_Flag == 1)
	{
		TaskB_flag == 1;
		IRQ_Flag = 0;
	}
}


int TaskA (int a, int b, int c)
{
	return a+b+c;
}

int TaskB (int a, int b, int c, int d)
{
	return a+b+c+d;
}


void MainOS()
{
	//main stack
	_E_MSP = _S_MSP - 512;

	//task A
	_S_PSP_TA = _E_MSP - 8;
	_E_PSP_TA = _S_PSP_TA - TaskA_Stack_Size;

	//task B
	_S_PSP_TB = _E_PSP_TA -8;
	_E_PSP_TB = _S_PSP_TB - TaskB_Stack_Size;

	while(1)
	{
		__asm("NOP");
		if(TaskA_flag == 1)
		{
			// Set PSP register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TA);
			// SP -> PSP
			OS_SWITCH_SP_TO_PSP;
			// switch from privileged to unprivileged
			Switch_CPU_Access_Level(none_privileged);

			TaskA_flag = TaskA(1,2,3);

			//switch to privileged
			OS_Generate_Exsaption;
			// Sp -> MSP
			OS_SWITCH_SP_TO_MSP;

		}else if (TaskB_flag == 1)
		{
			// Set PSP register = _S_PSP_TA
			OS_SET_PSP(_S_PSP_TB)
   	  											// SP -> PSP
   	  											OS_SWITCH_SP_TO_PSP;
			// switch from privileged to unprivileged
			Switch_CPU_Access_Level(none_privileged);


			TaskB_flag = TaskB(1,2,3,4);

			//switch to privileged
			OS_Generate_Exsaption;
			// Sp -> MSP
			OS_SWITCH_SP_TO_MSP;

		}
	}


}
void OS_SVC(int *stack_frame)
{
	unsigned char SVC_number;
	unsigned int val1,val2;

	val1 = stack_frame[0];
	val2 = stack_frame[1];

	SVC_number = *((unsigned char*)(((unsigned char*)stack_frame[6])-2));

	switch(SVC_number)
	{
	case 0:
		stack_frame[0] = val1 + val2;
		break;
	case 1:
		stack_frame[0] = val1 - val2;
		break;
	case 2:
		stack_frame[0] = val1 * val2;
		break;
	}
}
__attribute ((naked)) void SVC_Handler()
{
	__asm("Tst lr, #4 \n\t"
			"ITE EQ \n\t"
			"mrseq r0,MSP \n\t"
			"mrsne r0,PSP \n\t"
			"B OS_SVC");
}

int OS_SVC_Set(int a, int b, int SVC_ID)
{
	int return_val;
	switch(SVC_ID)
	{
	case 0: //add
		__asm("svc #0x00");
		break;
	case 1://sub
		__asm("svc #0x01");
		break;
	case 2://mul
		__asm("svc #0x02");
		break;
	}

	//r0 will have the return_val
	__asm("mov %0, r0": "=r"(return_val));
	return return_val;
}

int main(void)
{
	//RCC_GPIOB_CLK_EN();
	//RCC_AFIO_CLK_EN();

	//Set EXTI Configuration
	//EXTI_PinConfig_t EXTIConfig;
	//EXTIConfig.EXTI_PIN = EXTI9PB9;
	//EXTIConfig.Trigger_Case = EXTI_Trigger_RISING;
	//EXTIConfig.P_IRQ_CallBack = EXTI9_CALLBACK;
	//EXTIConfig.IRQ_EN = EXTI_IRQ_Enable;
	//MCAL_EXTI_GPIO_Init(&EXTIConfig);
	//Switch_CPU_Access_Level(none_privileged);
	//Switch_CPU_Access_Level(privileged);

	//MainOS();
	//IRQ_Flag = 1;

	int result ;
	result = OS_SVC_Set(3,2,0);
	result = OS_SVC_Set(3,2,1);
	result = OS_SVC_Set(3,2,2);



	while (1)
	{

		if(IRQ_Flag)
		{
			IRQ_Flag = 0;
		}
		else { /* Misra */ }
	}


}
