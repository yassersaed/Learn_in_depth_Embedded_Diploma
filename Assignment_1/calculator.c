/*
 ============================================================================
 Name        : basic.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char operator;
	float num1 , num2;
	printf("enter type of operator (+,-,*,/) :\n");
	fflush(stdout);
	scanf("%c",&operator);
	printf("enter your numbers :\n");
	fflush(stdout);
	scanf("%f%f",&num1,&num2);
	switch(operator){
	case '+':printf("%f + %f = %f",num1,num2,num1+num2);break;
	case '-':printf("%f - %f = %f",num1,num2,num1-num2);break;
	case '*':printf("%f * %f = %f",num1,num2,num1*num2);break;
	case '/':
		if(num2==0){printf("divided by zero \n");}
		else {printf("%f / %f = %f",num1,num2,num1/num2);}
		break;
	default :printf("wrong operator\n");
	}
	return 0;
}
