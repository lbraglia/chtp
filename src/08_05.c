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
	       c, isalnum(c) ? 'V' : 'F',
	       c, isalpha(c) ? 'V' : 'F',
	       c, iscntrl(c) ? 'V' : 'F',
	       c, isdigit(c) ? 'V' : 'F',
	       c, isgraph(c) ? 'V' : 'F',
	       c, isprint(c) ? 'V' : 'F',
	       c, ispunct(c) ? 'V' : 'F',
	       c, isspace(c) ? 'V' : 'F',
	       c, isxdigit(c) ? 'V' : 'F',
	       c, isupper(c) ? 'V' : 'F',
	       c, islower(c) ? 'V' : 'F', c, tolower(c), c, toupper(c)
	    );
    }

    return 0;
}
