/* Deitel & Deitel - "C How To Program"
   Exercise 6.23 - Turtle graphics 
   Solution provided by Matteo Galvani, with some fix by me (avoid round
   and other misc stuff). 
*/
#include <stdio.h>

#define FLOOR_DIM 50
#define INIT_XPOS 25		/* Initial X */
#define INIT_YPOS 25		/* Initial Y */
#define PI 3.14159265358979323846264338327

int Floor[FLOOR_DIM][FLOOR_DIM] = { {0} };

int xpos = INIT_XPOS;
int ypos = INIT_YPOS;
enum Pen { DOWN, UP };

void walk(const int dir, const int pen);
void print_matrix(void);
int get_input(void);
int normalize_dir(int dir);

int main()
{

    int input;
    int pen = DOWN;
    int dir = 0;		/* turtle direction in degree: eg 0 right, 90 up, 
				   180 left, 270 below */
    while (1) {
	input = get_input();
	switch (input) {
	case 1:
	    pen = DOWN;
	    break;
	case 2:
	    pen = UP;
	    break;
	case 3:
	    dir -= 90;
	    dir = normalize_dir(dir);
	    printf("Direction in degree: %d\n", dir);
	    break;
	case 4:
	    dir += 90;
	    dir = normalize_dir(dir);
	    printf("Direction in degree: %d\n", dir);
	    break;
	case 5:
	    walk(dir, pen);
	    break;
	case 6:
	    print_matrix();
	    break;
	case 9:
	    print_matrix();
	    return 0;
	default:
	    printf("Wrong input, try again\n");
	}			/* end switch */
    }				/* end while */
}

int normalize_dir(int dir)
{
    int res;

    if (dir < 0)
	res = 360 + dir;
    else if (dir >= 360)
	res = dir - 360;
    else
	res = dir;

    return res;

}

void walk(const int dir, const int pen)
{

    int step;
    int i;
    int xposmodifier;
    int yposmodifier;

    if (dir == 0) {
	xposmodifier = 1;
	yposmodifier = 0;
    } else if (dir == 90) {
	xposmodifier = 0;
	yposmodifier = -1;	/* -1 because we're going up in the matrix */
    } else if (dir == 180) {
	xposmodifier = -1;
	yposmodifier = 0;
    } else if (dir == 270) {
	xposmodifier = 0;
	yposmodifier = 1;	/* 1 because we're going down in the matrix */
    }

    printf("How many steps? ");
    scanf("%d", &step);

    for (i = 0; i < step; i++) {

	xpos += xposmodifier;
	if (xpos < 0) {
	    xpos = 0;
	} else if (xpos > FLOOR_DIM) {
	    xpos = FLOOR_DIM;
	}

	ypos += yposmodifier;
	if (ypos < 0) {
	    ypos = 0;
	} else if (ypos > FLOOR_DIM) {
	    ypos = FLOOR_DIM;
	}

	if (pen == UP) {
	    Floor[ypos][xpos] = 1;
	}
    }


}

int get_input(void)
{
    int input;
    printf("\n"
	   "1) Pen UP\n"
	   "2) Pen DOWN\n"
	   "3) Turn right\n"
	   "4) Turn left\n"
	   "5) Walk x steps\n"
	   "6) Print matrix\n" "9) End\n\n" "Insert command: ");
    scanf("%d", &input);
    return input;
}

void print_matrix(void)
{
    int i, j;

    for (i = 0; i < FLOOR_DIM; i++) {
	for (j = 0; j < FLOOR_DIM; j++)
	    /* . is definely better than ' ' */
	    printf(Floor[i][j] ? "#" : ".");
	printf("\n");
    }
    printf("\n");
}
