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
	float a,b,c;
	printf("Enter the numbers:\n");
	fflush(stdout);
	scanf("%f%f%f",&a,&b,&c);
	if(a>=b && a>=c)
		printf("%f is the largest number\n",a);
	else if(b>=a && b>=c)
		printf("%f is the largest number\n",b);
	else
		printf("%f is the largest number\n",c);
	return 0;
}