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
	int num;
	printf("Enter an integer number you want to check:\n");
	fflush(stdout);
	scanf("%d",&num);
	if(num%2==0)
	{
		printf("%d is even number\n",num);
	}
	else {
		printf("%d is odd number\n",num);

	}
	return 0;
}