#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main()
{
	int i1, i2, i3, i4;
	char s1[SIZE], s2[SIZE], s3[SIZE], s4[SIZE];
	printf("Enter four strings represent integers:\n");
	gets(s1);
	gets(s2);
	gets(s3);
	gets(s4);
	i1=atoi(s1);
	i2=atoi(s2);
	i3=atoi(s3);
	i4=atoi(s4);
	printf("The sum of the four integers are:%d\n",i1+i2+i3+i4);
	return 0; 
}
