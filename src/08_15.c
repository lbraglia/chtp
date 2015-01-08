#include <stdio.h>
#include <string.h>

void printReversed(char string[]);

int main(void)
{
    char string[] = "String to be reversed";

    printReversed(string);

    return 0;
}

void printReversed(char string[])
{

    char *tokenPtr = strtok(string, " ");
    char *tokens[1000];
    int i = 0;

    while (tokenPtr != NULL) {
	tokens[i] = tokenPtr;
	tokenPtr = strtok(NULL, " ");
	i++;
    }

    for (--i; i >= 0; --i)
	printf("%s ", tokens[i]);
    printf("\n");

}
