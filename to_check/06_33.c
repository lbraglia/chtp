/* 
   Deitel & Deitel - "C How To Program"
   Exercise 6.33 - Recursive test palindrome
   Solution provided by Matteo Galvani 

   TODO:
   - remove avoidable global variables
   - focus on palindrome function that has to manage non standard situation
     (not already cleaned string)

*/

#include <stdio.h>

int getString(void);
int rPalindrome(char string[50], int lenght, int pos);

char string[50];


int main(void){

   /* get string and return string length */
   int lenght = getString();	
   
   /* test if palindrome */   
   int test = rPalindrome(string, lenght, 0);	

    if (test == 1) {
	printf("It' a palindrome\n");
    } else {
	printf("Not a palindrome\n");
    }

    return 0;

}


/* test every element with the element in the same position starting from
   the end; when reach mid-string the test is over: for even lenght string
   the last test is redundant */
int rPalindrome(char string[], int lenght, int pos){

   if (pos == lenght / 2) {
	if (string[pos] == string[lenght - pos]) {
	    return 1;
	} else {
	    return 0;
	}
    } else if (string[pos] == string[lenght - pos]) {
	rPalindrome(string, lenght, pos + 1);
    } else {
	return 0;
    }

}

int getString(void){

    int i = 0;
    char c;
    printf("Insert lowe case string (end with: crtl-D)\n");

    /* get character until EOF */
    while ((c = getchar()) != EOF) {
	/* use character only if lower case letters */
	if (c > 96 && c < 123) {
	    string[i] = c;
	    i++;
	}
    }
    return i - 1;

}
