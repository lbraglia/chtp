#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5
#define WI_DIM 4
#define WS_DIM 6
#define NOFSENTENCES 20
#define BUFFERLEN 80


int main(void)
{
    int lil_cntr;		/* a counter */
    int sents_cnt;

    char *article[DIM] = { "the", "a", "one", "some", "any" };
    char *noun[DIM] = { "boy", "girl", "dog", "town", "car" };
    char *verb[DIM] = { "drove", "jumped", "ran", "walked", "skipped" };
    char *preposition[DIM] = { "to", "from", "over", "under", "on" };

    char **words_index[WI_DIM] = { article, noun, verb, preposition };

    char *sentences[NOFSENTENCES];	/* our final product */
    char buffer[BUFFERLEN];

    /* to have a sentence we use in sequence article, noun, verb,
       preposition, article and noun: under here you find that
       sequence in terms of words_index indexes */
    int word_sequence[WS_DIM] = { 0, 1, 2, 3, 0, 1 };


    for (sents_cnt = 1; sents_cnt <= NOFSENTENCES; ++sents_cnt) {



	/* sentence composition */
	for (lil_cntr = 0; lil_cntr < WS_DIM; ++lil_cntr) {

	    /* put the random string in the buffer */
	    strcat(buffer,
		   *(words_index[word_sequence[lil_cntr]] + dice(DIM) - 1)
		);

	    /* add the white space or the period */
	    if (lil_cntr < WS_DIM - 1)
		strcat(buffer, " ");
	    else if (lil_cntr == WS_DIM - 1)
		strcat(buffer, ".");
	    /* and uppercase the first letter */


	}

	/* copy the buffer in sentences and clear the buffer */
	strcpy(sentences[sents_cnt - 1], buffer);
	buffer[0] = '\0';


    }

    return 0;
}


int dice(int faces)
{
    static i = 1;
    if (i) {
	srand(time(NULL));
	i--;
    }

    return (1 + rand() % faces);
}
