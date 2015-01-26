/* 
   12_08: stats about 25 ordered integers in a list
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NINTS 25
#define WRAP 10

struct Int {
    int data;
    struct Int *next;
};

typedef struct Int intNode;
typedef intNode *intNodePtr;

/* intNodePtr initializeList(const int * string); */
void printList(intNodePtr head);
int dice(void);
int doSum(intNodePtr head);
void insert(intNodePtr * head, int x);

int main(void)
{

    int integers[NINTS] = { 0 };
    intNodePtr list1 = NULL;
    int i, sum = 0;

    srand(time(NULL));

    printf("Unsorted data:\n");
    /* initializing the array */
    for (i = 0; i < NINTS; i++) {
	printf("%3d%s", integers[i] =
	       dice(), (i + 1) % WRAP == 0 ? "\n" : " ");
    }
    printf("\n");

    /* initialize the list */
    for (i = 0; i < NINTS; i++) {
	insert(&list1, integers[i]);
    }
    printList(list1);

    /* stats */
    sum = doSum(list1);
    printf("Sum = %d\nMean = %.2f\n", sum, ((float) sum) / NINTS);

    return 0;
}



void insert(intNodePtr * s, int x)
{

    intNodePtr new;
    intNodePtr previous;
    intNodePtr current;

    new = malloc(sizeof(intNodePtr));
    if (new != NULL) {

	new->data = x;
	new->next = NULL;
	previous = NULL;
	current = *s;

	/* find the right position */
	while (current != NULL && x > current->data) {
	    previous = current;
	    current = current->next;
	}

	if (previous == NULL) {
	    /* insert new element at the beginning  */
	    new->next = *s;	/* *s is NULL */
	    *s = new;		/* set head to point to new */
	} else {
	    /* insert element between previous and current */
	    previous->next = new;
	    new->next = current;
	}

    } else {
	printf("%d not inserted. No memory available.\n", x);
    }

}

int doSum(intNodePtr head)
{
    intNodePtr current = head;
    int sum = 0;

    while (current->next != NULL) {
	sum += current->data;
	current = current->next;
    }
    /* add the last element */
    sum += current->data;

    return sum;
}

void printList(intNodePtr head)
{

    intNodePtr current = head;
    int i = 1;
    printf("Number list:\n");
    while (current != NULL) {
	printf("%3d%s", current->data, i % WRAP == 0 ? "\n" : " ");
	current = current->next;
	i++;
    }
    printf("\n");

}

int dice(void)
{

    return (rand() % 101);

}
