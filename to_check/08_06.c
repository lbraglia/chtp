#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int main()
{
	int i;
	char s[SIZE];
	printf("Enter a line of text:\n");
	gets(s);
	printf("The line printed in uppercase letters:\n");
	for(i=0; s[i] != '\0'; i++)
		printf("%c",toupper(s[i]));
	printf("\nThe line printed in lowercase letters:\n");
	for(i=0; s[i] != '\0' ; i++)
		printf("%c",tolower(s[i]));
	printf("\n");
	return 0; 
}
