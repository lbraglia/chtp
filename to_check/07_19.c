/* Deitel & Deitel - "C How To Program"
Exercise 7.19 - Simpletron 
Solution provided by Matteo Galvani */

#include <stdio.h>
#define SIZE 100

// declarations
void getInstructions(int instArr[]);
void dump(int arr[], int acc, int iC, int iR, int oC, int o);
void splitIR(int instructionRegister, int *oC, int *o);

int main(void)
{
    // array holding simpletrons' instructions
    int memory[SIZE] = { 0 };


    int accumulator = +0000;
    int instructionCounter = 00;
    int instructionRegister = +0000;
    int operationCode = 00;
    int operand = 00;

    printf("\n\n\t*** Welcome to Simpretron! ***\n"
	   "\t*** Please enter your program one instruction ***\n"
	   "\t*** (or data word) at a time. I will type the ***\n"
	   "\t*** location number and a queston mark (?).   ***\n"
	   "\t*** You then type the word for that location. ***\n"
	   "\t*** Type the sentinel -99999 to stop entering ***\n"
	   "\t*** Your program. ***\n\n");

    getInstructions(memory);

    while (operationCode != 43) {
	instructionRegister = memory[instructionCounter];

	splitIR(instructionRegister, &operationCode, &operand);

	/*
	   printf( "\nAcc = %i\n", accumulator);
	   printf( "C = %i\n", instructionCounter);
	   printf( "IR = %i\n", instructionRegister);
	   printf( "oC = %i\n", operationCode);
	   printf( "o = %i\n", operand);
	 */
	switch (operationCode) {

	case 10:
	    printf("Input: ");
	    scanf("%i", &memory[operand]);
	    instructionCounter++;
	    break;

	case 11:
	    printf("Output: %i\n", memory[operand]);
	    instructionCounter++;
	    break;

	case 20:
	    accumulator = memory[operand];
	    instructionCounter++;
	    break;

	case 21:
	    memory[operand] = accumulator;
	    instructionCounter++;
	    break;

	case 30:
	    accumulator += memory[operand];
	    instructionCounter++;
	    break;

	case 31:
	    accumulator -= memory[operand];
	    instructionCounter++;

	    break;

	case 32:
	    if (accumulator == 0) {
		printf(" *** Attempt to divide by zero *** \n"
		       " *** Simpletron exetution abnormally terminated *** \n");
		return -1;
	    } else {
		accumulator = memory[operand] / accumulator;
		instructionCounter++;
		break;
	    }

	case 33:
	    accumulator *= memory[operand];
	    instructionCounter++;
	    break;

	case 40:
	    instructionCounter = operand;
	    break;

	case 41:
	    if (accumulator < 0) {
		instructionCounter = operand;
	    } else {
		instructionCounter++;
	    }
	    break;

	case 42:
	    if (accumulator == 0) {
		instructionCounter = operand;
	    } else {
		instructionCounter++;
	    }
	    break;

	}
    }

    dump(memory, accumulator, instructionCounter, instructionRegister,
	 operationCode, operand);

    return 0;

}

void getInstructions(int instArr[])
{

    int instNumber;
    int instCode;

    printf("Input instructions code: range -9999; +9999\n\n");

    for (instNumber = 0; instNumber < SIZE; instNumber += 1) {
	// check for instructions in allowed range
	do {
	    printf("%02i ? ", instNumber);
	    scanf("%i", &instCode);
	} while (((instCode < -9999) || (instCode > 9999))
		 && (instCode != -99999));

	if (instCode != -99999) {
	    instArr[instNumber] = instCode;
	} else {
	    break;
	}
    }

    printf("*** Program loading completed ***\n");

}				// end getInstructions

void dump(int arr[], int acc, int iC, int iR, int oC, int o)
{
    int i;

    printf("********************");
    printf("\n\nMemory dump\n\n");
    printf("accumulator = %i\n", acc);
    printf("instructionCounter = %i\n", iC);
    printf("instructionRegister = %i\n", iR);
    printf("operationCode = %i\n", oC);
    printf("operand = %i\n\n", o);

    printf("   ");
    for (i = 0; i < 10; i += 1) {
	printf("%4i ", i);
    }
    printf("\n");
    for (i = 0; i < SIZE; i += 1) {
	if (i % 10 == 0) {
	    printf("%02i %04i ", i, arr[i]);
	} else if ((i + 1) % 10 == 0) {
	    printf("%04i\n", arr[i]);
	} else {
	    printf("%04i ", arr[i]);
	}
    }

}				// end dump

void splitIR(int instructionRegister, int *oC, int *o)
{
    *oC = instructionRegister / 100;
    *o = instructionRegister % 100;

}				// end splitIR (instructionregister)
