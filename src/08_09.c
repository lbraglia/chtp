#include <stdio.h>
#include <string.h>

#define MAXLEN 80

int main(void)
{

    char a[MAXLEN], b[MAXLEN];
    int results;
    char *results_word;
    gets(a);
    gets(b);
    results = strcmp(a, b);
    results_word =
	results > 0 ? "greater than" :
	results == 0 ? "equal to" : "less than";

    printf("\"%s\" is %s \"%s\" \n", a, results_word, b);

    return 0;
}
