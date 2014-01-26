#include <stdio.h>

void booking_procedure(int class);
int wrong_chair_insertion(int class, int chair);
void print_reservation(int chair, int class);
int ask_for_desired_class(void);
int not_full(int class);
void book_it(int chair);
void available_chairs(int class);

int airplane[10] = { 0 };


int main(void)
{/***********/

    int desired_class;
    int other_class;
    int desired_chair;
    int answer;

    while (1) {			/* 1 because we have to
				   comunicate the 11th, 12th,
				   13th and so on customer
				   that there are no more
				   chairs */

	desired_class = ask_for_desired_class();
	other_class = (desired_class == 1) ? 2 : 1;


	if (not_full(desired_class))
	    booking_procedure(desired_class);

	/* if desired class is full, check for other class availability */
	else if (not_full(other_class)) {

	    /* the desired class is full */
	    printf("%s class is full\n", (desired_class - 1) ?
		   "economic" : "first");

	    /* I propose for a booking in the other class */
	    printf("Would you like to book a ticket in %s class\n",
		   (desired_class - 1) ? "first" : "economic");
	    printf("Enter 1 (yes) or 0 (no): ");

	    /* get the answer */
	    scanf("%d", &answer);
	    while (answer != 0 && answer != 1) {
		printf("Enter 1 (yes) or 0 (no): ");
		scanf("%d", &answer);
	    }


	    /* If the answer is yes, book in the other class */
	    if (answer == 1) {
		booking_procedure(other_class);
	    }

	    /* otherwise give the next flight communication */
	    else if (answer == 0)
		printf("Next flight leaves in 3 hours\n");
	}


	/* If the flight is completely booked (no overbooking) ... */
	else {
	    printf("\n\nThis flights is completely booked\n");
	    printf("Next flight leaves in 3 hours\n");
	}



    }				/* end of the first while */

    return 0;
}



int ask_for_desired_class(void)
{/****************************/
    int desired_class;
    int first_full = 0;
    int economy_full = 0;

    if (not_full(1))
	printf("Please type 1 for \"first class\"\n");
    else {
	first_full = 1;
	printf("\n\nFirst class is full\n");
    }

    if (not_full(2))
	printf("Please type 2 for \"economy\"\n");
    else {
	economy_full = 1;
	printf("Economy class is full");
    }


    if (economy_full && first_full) {
	printf("\n\nThis flights is completely booked\n");
	printf("Next flight leaves in 3 hours\n");
    }



    scanf("%d", &desired_class);

    while ((desired_class != 2) && (desired_class != 1)) {
	printf("Please type 1 for \"first class\"\n");
	printf("Please type 2 for \"economy\"\n");
	scanf("%d", &desired_class);
    }

    return desired_class;

}


int not_full(int class)
{/********************/

    /* since airplane vector can't be ordered, a linear search is needed */

    int i, start, end;

    if (class == 1) {
	start = 0;
	end = 4;
    }

    else {
	start = 5;
	end = 9;
    }

    for (i = start; i <= end; i++)
	if (airplane[i] == 0)
	    return 1;

    /* otherwise */

    return 0;

}



void booking_procedure(int class)
{/******************************/

    int desired_chair;

    do {
	printf("Available chairs:\n");
	available_chairs(class);

	printf("Enter # of desired chair: ");
	scanf("%d", &desired_chair);
    }

    while (wrong_chair_insertion(class, desired_chair));

    book_it(desired_chair);
    print_reservation(desired_chair, class);


}



void available_chairs(int class)
{/******************************/
    int i, start, end;

    if (class == 1) {
	start = 0;
	end = 4;
    }

    else {
	start = 5;
	end = 9;
    }

//      printf("class: %s\n" class == 1 ? "first class" :  "economy class");
    for (i = start; i <= end; i++)
	if (airplane[i] == 0)
	    printf("%2d ", i + 1);
    printf("\n");

}


int wrong_chair_insertion(int class, int chair)
{/********************************************/

    if (class == 1)
	if ((chair <= 0) || (chair >= 6)) {
	    printf("Wrong immission\n");
	    return 1;
	}

    if (class == 2)
	if ((chair <= 5) || (chair >= 11)) {
	    printf("Wrong immission\n");
	    return 1;
	}

    if (airplane[chair - 1] == 1) {
	printf("This chair is already booked\n");
	return 1;
    }


    /* otherwise */
    return 0;
}


void print_reservation(int chair, int class)
{/******************************/

    printf("\n\n|==============|\n");
    printf("| Foo Airlines |\n");
    printf("|==============|\n");
    printf("  %s class\n", (class == 1) ? "first" : "economy");
    printf("  chair: %2d\n", chair);
    printf("|==============|\n");
    printf("\n\n");


}



void book_it(int chair)
{/********************/

    /* it books chair specified as argument; chair must be in
     * normal numeric notation (not vector one) */

    airplane[chair - 1] = 1;

}
