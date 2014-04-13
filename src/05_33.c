#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int rng(void);
int check_answer(int alpha, int beta);
void right_answer(void);
void wrong_answer(void);


int main(void)
{/***********/
    srand(time(NULL));
    int nofquestions, nofanswers;

    for (nofquestions = 1;; nofquestions++) {

	int a = rng(), b = rng();
	for (nofanswers;; nofanswers++) {

	    if (check_answer(a, b)) {	/* if it's right ... */
		right_answer();
		break;
	    }

	    else
		wrong_answer();

	}
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
