#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int not_guessed(int real_number, int player_guess);


int main(void)
{/************/

    int number, guess;
    char play_again = 'y';

    srand(time(NULL));

    while (play_again == 'y') {

	number = 1 + rand() % 1000;

	/* This printf should be cancelled once bug is fixed  */

	printf("%d\n", number);

	printf("I have a number beetween 1 and 1000\n"
	       "Can you guess my number?\n"
	       "Please type your first guess: ");

	scanf("%d", &guess);

	while (guessed(number, guess) == 0)
	    scanf("%d", &guess);

	printf("Would you like to play again? (y o n)");


	/* This printf should be cancelled once bug is fixed  */
	printf("\n%c\n", play_again);

/* This second scanf could fall in the classic problem of newline left
 * sitting in the buffer after (first) scanf(). Please take a
 * look at:
 */

/* + http://cboard.cprogramming.com/showthread.php?s=c85a7ea9a4048feb99ddadb1c380a734&t=95886 */
/* + http://www.phanderson.com/C/scanf.html */

	scanf("\n%c", &play_again);

	/* Notice \n before %c */

    }

    return 0;
}

int guessed(int real_number, int player_guess)
{/*******************************************/

    if (player_guess < real_number)
	printf("Too low. Try again: ");
    else if (player_guess > real_number)
	printf("Too high. Try again: ");
    else
	printf("Excellent! You guessed the number\n");

    return real_number == player_guess;

}
