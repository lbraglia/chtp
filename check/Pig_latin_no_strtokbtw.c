/* 
 * File:   main.c
 * Author: Riki Lord of Shadows
 *
 * Created on February 22, 2016, 2:00 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void initialize(char english[], char piglatin[]);
void readinput(char english[]);
int countwords(char english[]);
void convert(int words, char english[], char piglatin[]);
void writeoutput(char piglatin[]);

int main(){
    char english[80], piglatin[80];
    int words;
    printf("\nPig Latin Translator in C\n\n");
    printf( "Type \ 'END\' when finished\n\n");

    do
    {
        initialize(english, piglatin);
        readinput(english);

        if (toupper(english[0]) == 'E' && toupper(english[1]) == 'N' && toupper(english[2]) == 'D')
            break;

        words = countwords(english);

        convert(words, english, piglatin);
        writeoutput(piglatin);
    }
    while (words >= 0);
    printf("\naveHa aa icena ayda (Have a nice day)\n");
}


void initialize(char english[], char piglatin[])
{
    int count;
    for (count = 0; count < 80; ++count)
        english[count] = piglatin[count] = ' ';
}


void readinput(char english[])
{
    int count = 0;
    char c;
    while (( c = getchar()) != '\n')
    {
        english[count] = c;
        ++count;
    }
}


int countwords(char english[])
{
    int count, words = 1;
    for (count = 0; count < 79; ++count)
    if (english[count] == ' ' && english[count + 1] != ' ')
        ++words;
    return words;
}


void convert(int words, char english[], char piglatin[])
{
    int n, count;
    int m1 = 0; 
    int m2; 

    for (n = 1; n <= words; ++n)
    {
        count = m1 ;
        while (english[count] != ' ')
            m2 = count++;

        for (count = m1 ; count < m2; ++count)
            piglatin[count + (n - 1)] = english[count + 1];
        piglatin[m2 + (n - 1)] = english[m1];
        piglatin[m2 + n] = 'a'; /* adding 'a' at the end */

        m1 = m2 + 2;
    }
}


void writeoutput(char piglatin[]){
    int count = 0;
    for (count = 0; count < 80; ++count)
        putchar(piglatin[count]);
    printf("\n");
}