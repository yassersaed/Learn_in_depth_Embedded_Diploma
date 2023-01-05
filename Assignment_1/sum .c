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
	int num ,sum=0 , i;
	printf("Enter an integer:\n");
	fflush(stdout);
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		sum+=i;
	}
	printf("sum = %d",sum);
	return 0;
}