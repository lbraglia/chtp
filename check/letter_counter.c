/* File:   main.c
 * Author: Riki Lord of Shadows
 *
 * Created on March 1, 2016, 3:20 PM */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDIM 50
#define MAXLEN 1000
#define LETTERNO 52
#define LETTERLEN 2

void table(int ar[][LETTERLEN]);
void comparator(char ar[][MAXLEN], int ASKI[][LETTERLEN], int lines);


int main(int argc, char** argv) {
    
    char txt[MAXLEN];
    char mat[MAXDIM][MAXLEN];
    int ASCII[LETTERNO][LETTERLEN];
    int i=0,compare=0;
    
    printf("***********TEXT ANALYSIS***********\n\nEnter EXIT for end!\n");
    puts(">>>Line<<< : ");
    gets(txt);
    compare=strcmp(txt,"EXIT");
    table(ASCII);
    comparator(txt,ASCII,i);
    printf("\n");
    printf("************TABLE OF LETTERS APPEARING IN FIRST SENTENCE************\n");
    for(int i=0; i<52; i++){ 
        for(int j=0; j<2; j++){
            if(j==0){
                printf("LETTER: %c\n",ASCII[i][j]);
            }
            if(j==1){
                printf("OCCURENCES: %d\n",ASCII[i][j]);
            }
        }
        printf("\n");
    }
    printf("********************************************************************\n");
    
    return (EXIT_SUCCESS);
}

void table(int ar[][LETTERLEN]){
    
    int cnt=0;
    
    for(int i=65; i<=122; i++){
        if(i>90 && i<97){
            continue;
        }
        ar[cnt][0]=i;
        ar[cnt][1]=0;
        cnt++;
    }
}

void comparator(char ar[][MAXLEN], int ASKI[][LETTERLEN], int lines){
    for(int i=0; i<lines; i++){
        for(int j=0; j<strlen(ar[i]); j++){
            for(int g=0; g<LETTERNO; g++){
                if(ar[i][j]==ASKI[g][0]){
                    ASKI[g][1]++;
                }
            }
        }
    }
}