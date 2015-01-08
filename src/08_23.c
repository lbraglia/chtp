#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

int main(void)
{

    char buffer[BUFSIZ] = { '\0' };

    /* get the buffer and analyze the first value (pointer way), if not EOF
       go on and check it against 'b' (vector way); if equal print the line */

    while ((*(gets(buffer)) != EOF)) {
	if (buffer[0] == 'b')
	    puts(buffer);
    }

    return 0;

}
