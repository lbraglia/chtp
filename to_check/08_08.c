#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int main()
{
	double i1, i2, i3, i4;
	char s1[SIZE], s2[SIZE], s3[SIZE], s4[SIZE];
	printf("Enter four strings represent floating-point values:\n");
	gets(s1);
	gets(s2);
	gets(s3);
	gets(s4);
	i1=atof(s1);
	i2=atof(s2);
	i3=atof(s3);
	i4=atof(s4);
	printf("The sum of the four floating-point values are:%f\n",i1+i2+i3+i4);
	return 0; 
}
