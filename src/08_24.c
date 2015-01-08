#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

int endsWithED(const char buffer[]);

int main(void)
{

    char buffer[BUFSIZ] = { '\0' };

    /* get the buffer and analyze the first value (pointer way), if not EOF
       go on and check it against 'b' (vector way); if equal print the line */

    while ((*(gets(buffer)) != EOF)) {
	if (endsWithED(buffer))
	    puts(buffer);
    }

    return 0;

}

int endsWithED(const char buffer[])
{

    return ((strcmp(buffer + (strlen(buffer) - 2), "ed")) == 0);

}
