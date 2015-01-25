/* 
   11.17: Bare bone simple Simpletron able to source program from external
          files 
 */

#include <stdio.h>

#define READ 10
#define WRITE 11

#define LOAD 20
#define STORE 21

#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33

#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

#define MEMLIMITS 100
#define PATHLEN 1024

void runProgram(int memory[], int * accumulator);
void welcomeMessage(void);

int main(void){

   int memory[MEMLIMITS] = {0};
   int accumulator = 0;
   unsigned int i = 0; 		/* instructionCounter */
   int res = 0;
   int operation = 0;
   int operand = 0;

   FILE * srcFile = NULL;
   char filePath[PATHLEN] = {0};
   
   printf("*** Welcome to Simpletron!          ***\n"
          "*** Please enter the path to your   ***\n"
	  "*** your SML source file.           ***\n\n");
   
   /* Set the source file */
   printf("Path: ");
   fscanf(stdin, "%s", filePath);
   if ((srcFile = fopen(filePath, "r")) != NULL){
      
      /* Fill the memory, ignoring simple invalid option and avoiding buffer
	 overflows  */
      while(!feof(srcFile) && (i < MEMLIMITS)){
	 fscanf(srcFile, "%d", &res );
	 if ((res < -9999) | (res > 9999)) {/* ignore wrong input */
	    continue; 
	 } else { /*save input*/
	    memory[i++] = res;
	 }
      }
      fclose(srcFile);

      /* Run the program */
      printf("*** Program execution begins ***\n");
      for(i = 0; i < MEMLIMITS; i++){
      
	 operation = memory[i] / 100;
	 operand = memory[i] % 100;
      
	 if (HALT == operation) {
	    printf("*** Simpletron execution terminated ***\n");
	 } else {
	    switch(operation){
	    case READ:
	       scanf("%d", &memory[operand]);
	       break;
	    case WRITE:
	       printf("%d\n", memory[operand]);
	       break;
	    case LOAD:
	       accumulator = memory[operand];
	       break;
	    case STORE:
	       memory[operand] = accumulator; 
	       break;
	    case ADD:
	       accumulator +=  memory[operand];
	       break;
	    case SUBTRACT:
	       accumulator -=  memory[operand];
	       break;
	    case DIVIDE:
	       accumulator /=  memory[operand];
	       break;
	    case MULTIPLY:
	       accumulator *=  memory[operand];
	       break;
	    case BRANCH:
	       i = operand - 1;	/* -1 because of for i++ */
	       break;
	    case BRANCHNEG:
	       if (accumulator < 0)
		  i = operand - 1;   
	       break;
	    case BRANCHZERO:
	       if (accumulator == 0)
		  i = operand - 1;	       
	       break;
	    default:
	       break;
	    }	/* switch */
	 } /* if */
      }	/* for */

   } else { /* filePath not readable */
      printf("Unable to read %s\n", filePath);
   }

   return 0;
}
