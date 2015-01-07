/* Deitel ex 06-33 Palindromes
 */
#include <stdio.h>

int isPalindrome(char string[], int from, int to);
void tester(char string[], int from, int to);

int main(void)
{

    char string1[] = "abba";
    char string2[] = "mommy";
    char string3[] = "abba ";
    char string4[] = "mom!";

    tester(string1, 0, 5);
    tester(string2, 0, 6);
    tester(string3, 0, 6);
    tester(string4, 0, 5);

    return 0;

}


void tester(char string[], int from, int to)
{

    printf("'%s' %s palindrome\n", string,
	   (isPalindrome(string, from, to) ? "is" : "is not"));

}

int isPalindrome(char string[], int from, int to)
{

    char charFrom = string[from];
    char charTo = string[to];

    /* consider only lower case characters */
    while ((charFrom < 97) | (charFrom > 122)) {
	from++;
	charFrom = string[from];
    }
    while ((charTo < 97) | (charTo > 122)) {
	to--;
	charTo = string[to];
    }

    /* ending condition */
    if (from >= to)
	return 1;
    else {
	return (charFrom == charTo) * isPalindrome(string, from + 1,
						   to - 1);
    }

}
