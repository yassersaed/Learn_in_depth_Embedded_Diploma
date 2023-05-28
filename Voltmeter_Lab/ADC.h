
#ifndef ADC_H_
#define ADC_H_

void ADC_Init(void);
int ADC_Read(unsigned char channel);
void ADC_Start_Conversion(void);

#endif /* ADC_H_ */