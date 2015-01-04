#include <stdio.h>
#include <ctype.h>

void tolow_toup(const char *ptr, int (*function) (int));

int main(void)
{

    char s[100];
    printf("\nOriginal:\t");
    gets(s);
    tolow_toup(s, tolower);
    tolow_toup(s, toupper);

    return 0;
}


void tolow_toup(const char *ptr, int (*function) (int))
{
    if (function == tolower)
	printf("Lower case:\t");
    else if (function == toupper)
	printf("Upper case:\t");
    else
	return;			/* error case */

    while (*ptr) {
	printf("%c", (*function) (*ptr));
	ptr++;
    }
    printf("\n");
}
