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
	int fact =1 ,n ,counter;
	printf("Enter an integer number\n");
	fflush(stdout);
	scanf("%d",&n);
	if(n<0){
		printf("error nagative number");
	}
	else if(n==0){
		printf("factorial of zero = 1");
	}
	else {
		for(counter=1;counter<=n;counter++){
			fact*=counter;
		}
		printf("factorial of %d = %d \n",n,fact);
	}
	return 0;
}
