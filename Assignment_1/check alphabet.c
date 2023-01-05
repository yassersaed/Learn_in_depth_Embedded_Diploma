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
	char c;
	printf("Enter the char:\n");
	fflush(stdout);
	scanf("%c",&c);
	if((c>='a'&& c<='z')||(c>='A'&& c<='Z'))
		printf("%c is an alphabet\n",c);
	else
		printf("%c is not an alphabet\n",c);
	return 0;
}