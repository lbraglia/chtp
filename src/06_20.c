/* Fig. 5.10: fig05_10.c
   Craps */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
enum Status { CONTINUE, WON, LOST };
int roll(void);
int craps(int win[], int lose[]);
int main(void)
{/*************/
    srand(time(NULL));
    long repetitions;
    for (repetitions = 100; repetitions <= 100000; repetitions *= 10) {
	int i;
	int time_a, time_b;
	int winning_freq[21] = { 0 };
	int losing_freq[21] = { 0 };
	int wons = 0;

	/* execution & timing */
	time_a = time(NULL);	/* start time */
	for (i = 1; i <= repetitions; i++)
	    craps(winning_freq, losing_freq);
	time_b = time(NULL);	/* stop time */
	for (i = 0; i <= 20; i++)	/* counting for winning game */
	    wons += winning_freq[i];

	/*printing results */
	printf("Number of repetitions: %ld\n", repetitions);
	printf("Time elapsed: %d sec.\n", time_b - time_a);

	/* win & lost vectors */
	printf("try\twon\tlost \n");
	for (i = 0; i <= 19; i++)

	    /* fixme, I'm badly formatted */
	    printf("%3d\t%6d\t%6d \n", i + 1, winning_freq[i],
		   losing_freq[i]);
	printf("21+\t%6d\t%6d \n ", winning_freq[20], losing_freq[20]);

	/* winning probability */
	printf("Won games: %.2f%\n", ((float) wons) / repetitions * 100);
	printf("\n\n");
    } return 0;
}

int craps(int win[], int lose[])
{/************/
    int sum = 0;
    int myPoint = 0;
    enum Status status;
    int try = 1;		/* number of execution before win
				   (or lost) */
    sum = roll();
    switch (sum) {
    case 7:
    case 11:
	status = WON;
	break;
    case 2:
    case 3:
    case 12:
	status = LOST;
	break;
    default:
	status = CONTINUE;
	myPoint = sum;

	/* printf( "Point is %d\n", myPoint ); */
	break;
    }
    for (; status == CONTINUE; try++) {
	sum = roll();
	if (sum == myPoint)
	    status = WON;

	else if (sum == 7)
	    status = LOST;
    }

    /* I control for # of try: they're going to be inserted in a
       21 scalar vector */
    if (try > 20)
	try = 21;

    /* ending  */
    if (status == WON) {

	/* printf( "Player wins\n" ); */
	++win[try - 1];
    }

    else {

	/* printf( "Player loses\n" ); */
	++lose[try - 1];
    }
}

int roll(void)
{/*************/
    int dice_1 = 1 + (rand() % 6);
    int dice_2 = 1 + (rand() % 6);
    int sum = dice_1 + dice_2;

    /* printf( "Player rolled %d + %d = %d\n", dice_1, dice_2, sum ); */
    return sum;
}
