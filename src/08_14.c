#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LEN 15

void message(void);
int valid_format(char string[]);

int main(void)
{

    char *tempmem;
    char *pref;
    char number[8] = { 0 };
    char *num1;
    char *num2;

    char string[LEN];

    message();
    fgets(string, LEN, stdin);
    while (!valid_format(string)) {
	message();
	fgets(string, LEN, stdin);
    }

    /* prefix */
    tempmem = strtok(string, "(");
    pref = strtok(tempmem, ")");

    /* xxx-... */
    tempmem = strtok(NULL, " ");
    num1 = strtok(tempmem, "-");
    /* ...-xxxx */
    num2 = strtok(NULL, "this is the end");
    /* number composition */
    strcat(number, num1);
    strcat(number, num2);


    /* print out  */
    printf("%s %d \n"
	   "%s %ld \n", "prefix: ", atoi(pref), "number: ", atol(number)
	);

    return 0;
}


int valid_format(char string[])
{
    int len = (int) strlen(string);

    if (len < (LEN - 1))
	return 0;		/* 0 == fail */
    if (string[0] != '(')
	return 0;
    if (string[4] != ')')
	return 0;
    if (string[5] != ' ')
	return 0;
    if (string[9] != '-')
	return 0;
    if (!isdigit(string[1]))
	return 0;
    if (!isdigit(string[2]))
	return 0;
    if (!isdigit(string[3]))
	return 0;
    if (!isdigit(string[6]))
	return 0;
    if (!isdigit(string[7]))
	return 0;
    if (!isdigit(string[8]))
	return 0;
    if (!isdigit(string[10]))
	return 0;
    if (!isdigit(string[11]))
	return 0;
    if (!isdigit(string[12]))
	return 0;
    if (!isdigit(string[13]))
	return 0;

    /* else return success */
    return 1;
}


void message(void)
{
    printf("Please enter a number in the \"(xxx) xxx-xxxx\" \n"
	   "format, where x is a number\n");
}
