
#include<stdint.h>

void  Reset_Handler();
extern int main(void);
void Default_Handler()
{
	Reset_Handler();
}
void  NMI_Handler()__attribute__((weak,alias("Default_Handler")));;
void  H_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void  MM_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;
void  Bus_Handler()__attribute__((weak,alias("Default_Handler")));;
void  Usage_Fault_Handler()__attribute__((weak,alias("Default_Handler")));;

extern unsigned int stack_top ;
uint32_t vectors[] __attribute__((section(".vectors")))= {
	
(uint32_t) 	&stack_top,
(uint32_t)	&Reset_Handler,
(uint32_t)	&NMI_Handler,
(uint32_t)	&H_Fault_Handler,
(uint32_t)	&MM_Fault_Handler,
(uint32_t)	&Bus_Handler,
(uint32_t)	&Usage_Fault_Handler

};
extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;
void Reset_Handler(void)
{
	int i;
	
	// copy .data from flash(ROM) into sram(RAM)
	unsigned char data_size = (unsigned char*)&_E_DATA  - (unsigned char*)&_S_DATA ;
	unsigned char* p_src = (unsigned char*)&_E_text ;    //source
	unsigned char* p_dst = (unsigned char*)&_S_DATA ;     //destination
	for(i = 0; i < data_size; i++)
	{
		*((unsigned char*)p_dst++) = *((unsigned char*)p_src++);
	}
	// init .bss with zero in sram
	unsigned char bss_size = (unsigned char*)&_E_bss  - (unsigned char*)&_S_bss ;	
	p_dst = (unsigned char*)&_S_bss ;
	for(i = 0; i < bss_size; i++)
	{
		*((unsigned char*)p_dst++) = (unsigned char)0 ;
	}
	// jump to main function
	main();
}