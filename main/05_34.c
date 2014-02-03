#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rng(void);
int check_answer(int alpha, int beta);
void print_stat(int questn, int wrongn, int rightn, int answern);
void right_answer(void);
void wrong_answer(void);
int bad_stats(int answern, int rightn);
void extra_help(void);

int interruptme = 0;


int main(void)
{/***********/
    srand(time(NULL));
    int nofquestions, nofanswers = 0, wrongs = 0, rights = 0;

    for (nofquestions = 1;; nofquestions++) {

	int a = rng(), b = rng();
	for (;; nofanswers++) {

	    print_stat(nofquestions, wrongs, rights, nofanswers);

	    if ((nofanswers % 10 == 0) && (bad_stats(nofanswers, rights)))
	    {
		interruptme = 1;
		extra_help();
		break;
	    }



	    if (check_answer(a, b)) {	/* if it's right ... */
		right_answer();
		rights++;
		nofanswers++;	/* I add this because break
				   make nofanswer not to
				   increment when answer is
				   not true */

		break;		/* start a new question */
	    }

	    else {
		wrong_answer();
		wrongs++;
	    }

	}

	if (interruptme)
	    break;
    }

    return 0;
}


int rng(void)
{/**********/
    return 1 + rand() % 9;
}


int check_answer(int alpha, int beta)
{/**********************************/
    int answer;

    printf("How much is %d times %d: ", alpha, beta);
    scanf("%d", &answer);
    return answer == alpha * beta;	/* 0 if wrong, 1 if right */

}

void print_stat(int questn, int wrongn, int rightn, int answern)
{/************************************************/

    printf("\n=================\n");
    printf("| Question: %3d |\n", questn);
    printf("=================\n");
    printf("|  Answers: %3d |\n", answern);
    printf("|   Wrongs: %3d |\n", wrongn);
    printf("|   Rights: %3d |\n", rightn);
    printf("=================\n\n");

}


int bad_stats(int answern, int rightn)
{/***********************************/
    return ((float) rightn / answern) <= 0.75;
}

void extra_help(void)
{/******************/
    printf("\n\t*********************************************\n");
    printf("\t* Please ask your instructor for extra help *\n");
    printf("\t*********************************************\n\n");
}

void right_answer(void)
{/********************/
    int rn = rand() % 4;
    switch (rn) {
    case 0:
	printf("Very good!\n");
	break;
    case 1:
	printf("Excellent!\n");
	break;
    case 2:
	printf("Nice work!\n");
	break;
    case 3:
	printf("Keep up the good work!\n");
	break;
    }
}


void wrong_answer(void)
{/********************/
    int rn = rand() % 4;
    switch (rn) {
    case 0:
	printf("No. Please try again.\n");
	break;
    case 1:
	printf("Wrong.\n");
	break;
    case 2:
	printf("Don't give up.\n");
	break;
    case 3:
	printf("No. Keep trying.\n");
	break;
    }
}
