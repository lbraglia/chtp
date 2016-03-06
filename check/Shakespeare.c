/* 
 * File:   main.c
 * Author: Riki Lord of Shadows
 *
 * Created on March 1, 2016, 10:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXDIM 1000
#define MAXLEN 1000

void parse(char ar[][MAXLEN], int words);

void print(char ar[][MAXLEN], int c){
    int max;
    int value=0,j;
    
    max=strlen(ar[0]);
    for(int i=1; i<c; i++){
        if(max<strlen(ar[i])){
            max=strlen(ar[i]);
        }
    }
    
    printf("\n***********WORD LENGTH READER***********\n");
    printf("| LENGTHS || VALUES | \n");
    for(j=1; j<=max; j++){
        for(int i=0; i<c; i++){
            if(strlen(ar[i])==j){
                value++;
            }
        }
        printf("|    %d    ||   %d    | \n",j,value);
        value=0; 
    }
    printf("\n****************************************\n");
}

int main(int argc, char** argv) {
    
    char txt[MAXLEN];
    char *token;
    char mat[MAXDIM][MAXLEN];
    int i=0,wordcnt=0;
    
    do{
        printf(">>>Write and press enter (EXIT for end of program)<<< : ",49);
        gets(txt);
        if(strcmp(txt,"EXIT")!=0){
            token=strtok(txt," ");
            strcpy(mat[i],token);
            i++;
            while(token!=NULL){
                token=strtok(NULL, " ");
                if(token!=NULL){
                    strcpy(mat[i],token);
                    i++;
                }
            }
        }
    }while(strcmp(txt,"EXIT")!=0);
    
    parse(mat,i);
    
    print(mat,i);
    
    return (EXIT_SUCCESS);
}

void parse(char ar[][MAXLEN], int words){
    for(int i=0; i<words; i++){
        for(int j=0; j<strlen(ar[i]); j++){
            if((ar[i][j]<65 && ar[i][j]!=39) || (ar[i][j]>90 && ar[i][j]<97)|| ar[i][j]>122){
                for(int g=j; g<strlen(ar[i]); g++){
                    ar[i][g]=ar[i][g+1];
                }
            }
        }
    }
}