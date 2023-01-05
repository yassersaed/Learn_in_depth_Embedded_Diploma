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
	printf("Enter an alphabet:\n");
	fflush(stdout);
	scanf("%c",&c);
	if(c=='a'||c=='A'||c=='e'||c=='E'||c=='i'||c=='I'||c=='o'||c=='O'||c=='u'||c=='U')
		{
		printf("%c is a Vowel\n",c);
		}
	else
		{
		printf("%c is a consonant\n",c);
		}

	return 0;
}
