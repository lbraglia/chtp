#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM 5
#define WI_DIM 4
#define WS_DIM 6
#define NOFSENTENCES 20
#define BUFFERLEN 80

int dice(int faces);


int main(void)
{
    int sents_cnt;		/* sentence counter */
    int wrd_cntr;		/* word counter inside sentence */

    char *article[DIM] = { "the", "a", "one", "some", "any" };
    char *noun[DIM] = { "boy", "girl", "dog", "town", "car" };
    char *verb[DIM] = { "drove", "jumped", "ran", "walked", "skipped" };
    char *preposition[DIM] = { "to", "from", "over", "under", "on" };
    char buffer[BUFFERLEN] = { '\0' };
    /* to have a sentence we use in sequence article, noun, verb,
       preposition, article and noun: under here you find that
       sequence in terms of words_index indexes */
    int word_sequence[WS_DIM] = { 0, 1, 2, 3, 0, 1 };
    char **words_index[WI_DIM];

    words_index[0] = article;
    words_index[1] = noun;
    words_index[2] = verb;
    words_index[3] = preposition;

    srand(time(NULL));

    /* sentence counter */
    for (sents_cnt = 1; sents_cnt <= NOFSENTENCES; ++sents_cnt) {

	/* sentence composition */
	for (wrd_cntr = 0; wrd_cntr < WS_DIM; ++wrd_cntr) {

	    /* put the random string in the buffer */
	    strcat(buffer,
		   *(words_index[word_sequence[wrd_cntr]] + dice(DIM) - 1)
		);

	    /* add the white space or the period */
	    if (wrd_cntr < WS_DIM - 1)
		strcat(buffer, " ");
	    else if (wrd_cntr == WS_DIM - 1)
		strcat(buffer, ".\n");
	    /* and uppercase the first letter */
	    buffer[0] = toupper(buffer[0]);
	}

	/* print and clean */
	printf("%s", buffer);
	buffer[0] = '\0';
    }

    return 0;
}


int dice(int faces)
{
    return (1 + rand() % faces);
}
