#include <stdio.h>
#include <string.h>
#define SIZE 100
int main()
{
	int n;
	char s1[SIZE], s2[SIZE];
	printf("Enter two strings:\n");
	gets(s1);
	gets(s2);
	printf("Enter number of characters to be compared: ");
	scanf("%d",&n);
	if (strncmp(s1, s2, n) < 0)
		printf("%s is greater than %s \n",s1, s2);
	else if(strcmp(s1, s2) == 0)
		printf("%s is equal than %s \n",s1, s2);
	else
		printf("%s is less than %s \n",s1, s2);
	return 0; 
}
