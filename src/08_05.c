#include <stdio.h>
#include <ctype.h>


int main(void)
{

    char c;

    while (scanf("%c", &c) != EOF) {

	if (c == '\n')
	    continue;

	printf("isalnum(%c): \t%c\n"
	       "isalpha(%c): \t%c\n"
	       "iscntrl(%c): \t%c\n"
	       "isdigit(%c): \t%c\n"
	       "isgraph(%c): \t%c\n"
	       "isprint(%c): \t%c\n"
	       "ispunct(%c): \t%c\n"
	       "isspace(%c): \t%c\n"
	       "isxdigit(%c): \t%c\n"
	       "isupper(%c): \t%c\n"
	       "islower(%c): \t%c\n"
	       "tolower(%c): \t%c\n"
	       "toupper(%c): \t%c\n\n",
	       c, isalnum(c) ? 'T' : 'F',
	       c, isalpha(c) ? 'T' : 'F',
	       c, iscntrl(c) ? 'T' : 'F',
	       c, isdigit(c) ? 'T' : 'F',
	       c, isgraph(c) ? 'T' : 'F',
	       c, isprint(c) ? 'T' : 'F',
	       c, ispunct(c) ? 'T' : 'F',
	       c, isspace(c) ? 'T' : 'F',
	       c, isxdigit(c) ? 'T' : 'F',
	       c, isupper(c) ? 'T' : 'F',
	       c, islower(c) ? 'T' : 'F', c, tolower(c), c, toupper(c)
	    );
    }

    return 0;
}
