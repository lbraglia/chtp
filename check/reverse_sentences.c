/* 
 * File:   main.c
 * Author: Riki Lord of Shadows
 *
 * Created on February 25, 2016, 2:22 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlen 100
#define dimension 100

 //When you press ENTER in input segment of the program, you actually input '\n'...
    //...and that is why the first word is separated from the others

int main(int argc, char** argv) {
    
    char s[maxlen];
    char *token;
    char ar[dimension][maxlen];
    int i=1;
    
    printf("Input pls: ");
    fgets(s,maxlen,stdin);
    
    token=strtok(s," ");
    strcat(ar[0],token);
    while(token!=NULL){
        token=strtok(NULL," ");
        if(token!=NULL){
            strcat(ar[i],token);
            i++;
        }
    }
    printf("*********REVERSE SENTENCE************\n");
    for(i; i>=0; --i){
        printf("%s ",ar[i]);
    }
    printf("\n");
    printf("*************************************");
   
    return (EXIT_SUCCESS);
}

