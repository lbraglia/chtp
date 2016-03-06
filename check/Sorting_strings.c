/* 
 * File:   main.c
 * Author: Riki Lord of Shadows
 *
 * Created on February 27, 2016, 1:06 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
#define MAXDIM 15

void sort(char a[][MAXLEN], int c);
void printsort(char s[][MAXLEN],int c);

int main(int argc, char** argv) {
    char s[MAXDIM][MAXLEN];
    int i=0;
    
    while(i<10){
        printf("City %d of 10 is: ",i+1);
        gets(s[i]);
        i++;
    }
            
    sort(s,i);
    printf("\n************SORTED LIST************\n");
    printsort(s,i);
    printf("\n***********************************\n");
    return (EXIT_SUCCESS);
}

void sort(char a[][MAXLEN], int c){
    char temp[MAXLEN];
    
    for(int i=0; i<c; i++){
        for(int j=0; j<c-1; j++){
            if(strcmp(a[j],a[j+1])>0){
                strcpy(temp,a[j]);
                strcpy(a[j],a[j+1]);
                strcpy(a[j+1],temp);
            }
        }
    }
}

void printsort(char s[][MAXLEN],int c){
    
    for(int i=0; i<c; i++){
        puts(s[i]);
    }
}