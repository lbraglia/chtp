#include <stdio.h>

int main(void)
{
    char asd[] = "ajeje";
    printf("\n");
    printArray(asd, 6);
    printf("\n");

    return 0;
}

void printArray(char string[], int strlength)
{
    if (strlength == 1)
	return;
    else {
	printf("%c", string[strlength - 1 - 1]);
	printArray(string, strlength - 1);
    }

}
