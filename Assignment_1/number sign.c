
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

int main()
{
	float a;
	printf("Enter the number:\n");
	fflush(stdout);
	scanf("%f",&a);
	if(a>0)
		printf("%1f is positive number\n",a);
	else if(a<0)
		printf("%1f is nigative number\n",a);
	else
		printf("you entered zero\n");
	return 0;
}