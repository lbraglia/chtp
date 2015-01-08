/* Ex. 7.25 - Maze Traverse */
#include <stdio.h>

#define MAZE_DIM 12

void printMaze(char maze[MAZE_DIM][MAZE_DIM]);
void mazeTraverse(char maze[MAZE_DIM][MAZE_DIM], int x, int y, int dir);
int feasible(char maze[MAZE_DIM][MAZE_DIM], int x, int y);

int main(void)
{


    char maze[MAZE_DIM][MAZE_DIM] = {
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
	{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
	{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
	{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
	{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
	{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };


    mazeTraverse(maze, 2, 0, 0);

    return 0;
}

void mazeTraverse(char maze[MAZE_DIM][MAZE_DIM], int x, int y, int dir)
{

    /* x is the row */
    /* y is the column */
    /* dir is the direction in degree that we are considering (can be 0, 90,
       180, 270 */

    /* flag the square */
    maze[x][y] = 'x';
    /* print the matrix */
    printMaze(maze);

    /* check if we have found the exit */
    if ((x == MAZE_DIM - 1) || (y == MAZE_DIM - 1)) {
	printf("Exit found!\n ");
	return;
    }
    /* otherwise go for the next step */
    if (dir == 0) {

	if (feasible(maze, x + 1, y))
	    mazeTraverse(maze, x + 1, y, 270);
	else if (feasible(maze, x, y + 1))
	    mazeTraverse(maze, x, y + 1, 0);
	else if (feasible(maze, x - 1, y))
	    mazeTraverse(maze, x - 1, y, 90);
	else if (feasible(maze, x, y - 1))
	    mazeTraverse(maze, x, y - 1, 180);

    } else if (dir == 90) {

	if (feasible(maze, x, y + 1))
	    mazeTraverse(maze, x, y + 1, 0);
	else if (feasible(maze, x - 1, y))
	    mazeTraverse(maze, x - 1, y, 90);
	else if (feasible(maze, x, y - 1))
	    mazeTraverse(maze, x, y - 1, 180);
	else if (feasible(maze, x + 1, y))
	    mazeTraverse(maze, x + 1, y, 270);

    } else if (dir == 180) {

	if (feasible(maze, x - 1, y))
	    mazeTraverse(maze, x - 1, y, 90);
	else if (feasible(maze, x, y - 1))
	    mazeTraverse(maze, x, y - 1, 180);
	else if (feasible(maze, x + 1, y))
	    mazeTraverse(maze, x + 1, y, 270);
	else if (feasible(maze, x, y + 1))
	    mazeTraverse(maze, x, y + 1, 0);

    } else if (dir == 270) {

	if (feasible(maze, x, y - 1))
	    mazeTraverse(maze, x, y - 1, 180);
	else if (feasible(maze, x + 1, y))
	    mazeTraverse(maze, x + 1, y, 270);
	else if (feasible(maze, x, y + 1))
	    mazeTraverse(maze, x, y + 1, 0);
	else if (feasible(maze, x - 1, y))
	    mazeTraverse(maze, x - 1, y, 90);

    }

}

int feasible(char maze[MAZE_DIM][MAZE_DIM], int x, int y)
{

    return (maze[x][y] != '#');

}

void printMaze(char maze[MAZE_DIM][MAZE_DIM])
{

    int i, j;

    printf("\n");
    for (i = 0; i < MAZE_DIM; i++) {
	printf("  ");
	for (j = 0; j < MAZE_DIM; j++)
	    printf("%c ", maze[i][j]);
	printf("\n");
    }
    printf("\n");
}
