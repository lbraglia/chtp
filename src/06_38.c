#include <stdio.h>

void stringReverse(char string[], int strlength);

int main(void)
{
    char asd[] = "ajeje";
    stringReverse(asd, 6);
    printf("\n");

    return 0;
}

void stringReverse(char string[], int strlength)
{
    if (strlength == 1)
	return;
    else {
	printf("%c", string[strlength - 1 - 1]);
	stringReverse(string, strlength - 1);
    }

}
