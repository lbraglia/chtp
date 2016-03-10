/* Deitel & Deitel - "C How To Program"
   Exercise 6.23 - Turtle graphics 
   Solution provided by rafael Bluhm
*/
#include <stdio.h> 

#define SIZE 50

/* * Prototypes: * */

void displayMenu(void);

/*	Sets all matrix slots to '.' and Center with 'T' where
	turtle initiality stands. Initial turtlue position can 
	ben altered at main() begining. */
void startMatrix(char [][SIZE], int []);

/* Display atual state of Logo matrix */
void displayMatrix(char [][SIZE]);

/* DOWN == 0, RIGHT == 1, UP == 2, LEFT == 3 
	Needs 5 in parameter list: the matix, atual position, average, 
   direction and pen state. */
void moveTurtle(char [][SIZE], int [], int, int, int);

int rotateCounter(int);

int rotateClock(int);

void clearStdin(void);

/* Just to clear stdin input for scanf's inside while loop*/
void clearStdin(void);

/* * 

	MAIN 

* */
int main(void)
{	
	/* Defines the matrix to be inputed in any function 
		who will write or display the turtle matrix. */
	char matrix[SIZE][SIZE];

	/* Initial position can be changed here */
	int pos[2] = {SIZE/2, SIZE/2};

	/* loop varible control */
	int sentinel = 1;
	
	/* Start with tutle moving DOWN by default */	
	int direction = 0;

	int pen = 1; /* 1 - DOWN, 0 - UP */

	startMatrix(matrix, pos);

	displayMenu();

	while(sentinel){

		int option[2];

		if(1 == scanf("%1d", &option[0])){

			switch(option[0]){
		
				case 1:
					printf("Pen top\n");	
					pen = 0;
					break;		

				case 2:
					printf("Pen down\n");
					pen = 1;
					break;

				case 3:
					direction = rotateClock(direction);
					break;

				case 4:
					direction = rotateCounter(direction);
					break;

				case 5:
					if(1 == scanf(",%2d", &option[1])){
						moveTurtle(matrix, pos, option[1], direction, pen);
						clearStdin(); 
					}
					else{
						printf("Failed to read second integer.\n"); 
                  clearStdin();
               }  
					break;
			
				case 6:
					displayMatrix(matrix);
					printf("Atual Position:x = %d, y = %d\n", pos[0] + 1, pos[1] + 1);  
					break;

				case 9:
					sentinel = 0;
					break;

				default:
					puts("Invalid option, try again.");
					break;
			}/* end switch */	
			
		}/* end scanf if */	
		else{		
			puts("Failed to read integer.");
			clearStdin();
      }
	}/* end while */

	return 0;
}/* end main */

/* Functions Implementations 
	(keep same down order from prototypes) */

void displayMenu(void){

	printf("\n"
	"Pen UP       - 1\n"
	"Pen DOWN     - 2\n"
	"Turn right   - 3\n"
	"Turn left    - 4\n"
	"Walk,steps   - 5,x\n"
	"Print matrix - 6\n" 
	"End          - 9\n\n" 
	"Insert command: ");
}

void startMatrix(char matrix[][SIZE], int pos[]){

	 int i, j;

    for( i = 0; i < SIZE; i++)
        for( j = 0; j < SIZE; j++)
            matrix[i][j] = '.';

	matrix[pos[0]][pos[1]] = 'T';
}

void displayMatrix(char matrix[][SIZE]){

	int i, j;

	for(i = 0; i < SIZE; i++){

		for(j = 0; j < SIZE; j++){

			printf("%c ", matrix[i][j]);  
		}
		printf("\n");
	}
}

void moveTurtle(char matrix[][SIZE], int pos[], int pass, int dir, int pen){

	int i; /*Counter loop variable */
	int final_pos;
	
/* Direction: DOWN == 0 */
	if(dir == 0){
	/* internal if to check arrays bounds and not pass */
		final_pos = pos[1] + pass;	

		if(0 <= final_pos && final_pos < SIZE){
			
			if(pen == 1){
				
				for(i = pos[1]; i < pos[1] + pass; i++)
					matrix[i][pos[0]] = '*';	

			}else {
				
				(matrix[pos[1]][pos[0]] == '*' || matrix[pos[1]][pos[0]] == 'T')?
				(matrix[pos[1]][pos[0]] = '*') : (matrix[pos[1]][pos[0]] = '.');
			}
				
				pos[1] = final_pos;

				matrix[pos[1]][pos[0]] = 'T';	

		}else			
			puts("Invalid position. Try again:");
	}

/* Direction: RIGHT == 1 */
	else if(dir == 1){

		final_pos = pos[0] + pass;

		if(0 <= final_pos && final_pos < SIZE){

			if(pen == 1){
	
				for(i = pos[0]; i < pos[0] + pass; i++)
					matrix[pos[1]][i] = '*';
			
			}else {
				
				(matrix[pos[1]][pos[0]] == '*' || matrix[pos[1]][pos[0]] == 'T')?
				(matrix[pos[1]][pos[0]] = '*') : (matrix[pos[1]][pos[0]] = '.');
			}
			
			pos[0] = final_pos;

			matrix[pos[1]][pos[0]] = 'T';	

		}else
			puts("Invalid position. Try again:");	
	}

/* Direction: UP == 2 */
	else if(dir == 2){

		final_pos = pos[1] - pass;

		if(0 <= final_pos && final_pos < SIZE){

			if(pen == 1){ 

				for(i = pos[1]; i > pos[1] - pass; i--)
					matrix[i][pos[0]] = '*';
				
			}else{

				(matrix[pos[1]][pos[0]] == '*' || matrix[pos[1]][pos[0]] == 'T')?
				(matrix[pos[1]][pos[0]] = '*') : (matrix[pos[1]][pos[0]] = '.');		
			}

			pos[1] = final_pos;

			matrix[pos[1]][pos[0]] = 'T';	

		}else
			puts("Invalid position. Try Again.");
	}

/* Direction: LEFT == 3 */
	else if(dir == 3){

		final_pos = pos[0] - pass;

		if(0 <= final_pos && final_pos < SIZE){

			if(pen == 1){

				for(i = pos[0]; i > pos[0] - pass; i--)
					matrix[pos[1]][i] = '*';

			}else{

				(matrix[pos[1]][pos[0]] == '*' || matrix[pos[1]][pos[0]] == 'T')?
				(matrix[pos[1]][pos[0]] = '*') : (matrix[pos[1]][pos[0]] = '.');
			}

			pos[0] = final_pos;

			matrix[pos[1]][pos[0]] = 'T';

		}else
			puts("Invalid position. Try again.");
	}
}

int rotateCounter(int value){

	value++;

	return value % 4;
}

int rotateClock(int value){

	if(value == 0)		
		value = 3;

	else{

		value--;
	}
	return value % 4;
}

void clearStdin(void){	

	char c;
	
	while(( c = getchar() ) != '\n');
}
