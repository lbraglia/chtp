#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

void shuffle( unsigned int wDeck[][ FACES ] ) {
 size_t row;
 size_t column;
 size_t card;
    for ( card = 1; card <= CARDS; ++card ) {
        do {
            row = rand() % SUITS;
            column = rand() % FACES;
        } while( wDeck[ row ][ column ] != 0 );
        
        wDeck[ row ][ column ] = card;
    }
}

void deal( unsigned int wDeck[][ FACES ], const char *wFace[],const char *wSuit[], char hand[6][150] ){
    size_t row;
    size_t column;
    size_t card;
    for ( card = 0; card <= 5; ++card ) {
        for ( row = 0; row < SUITS; ++row ) {
            for ( column = 0; column < FACES; ++column ) {
                if ( wDeck[ row ][ column ] == card ) {
                    strcat(hand[card],wFace[column]);
                    strcat(hand[card]," ");
                    strcat(hand[card],wSuit[row]);
                }
            }
        }
    }
}

int converter(int point[],char **card_faces){
    for(int i=0; i<5; i++){
        if(strcmp("Ace",card_faces[i])==0){
            point[i]=1;
        }
        else if(strcmp("Deuce",card_faces[i])==0){
           point[i]=2;
        }
        else if(strcmp("Three",card_faces[i])==0){
            point[i]=3;
        }
        else if(strcmp("Four",card_faces[i])==0){
           point[i]=4;
        }
        else if(strcmp("Five",card_faces[i])==0){
           point[i]=5;
        }
        else if(strcmp("Six",card_faces[i])==0){
           point[i]=6;
        }
        else if(strcmp("Seven",card_faces[i])==0){
           point[i]=7;
        }
        else if(strcmp("Eight",card_faces[i])==0){
           point[i]=8;
        }
        else if(strcmp("Nine",card_faces[i])==0){
           point[i]=9;
        }
        else if(strcmp("Ten",card_faces[i])==0){
           point[i]=10;
        }
        else if(strcmp("Jack",card_faces[i])==0){
           point[i]=11;
        }
        else if(strcmp("Queen",card_faces[i])==0){
           point[i]=12;
        }
        else if(strcmp("King",card_faces[i])==0){
           point[i]=13;
        }
        else{
            printf("Error number 1 - Unhandled exception. Program will now close.");
            exit(1);
        }
    }
}

int pointconverter(int *handpts, char *card_face){
    if(strcmp("Ace",card_face)==0){
            *handpts=1;
        }
        else if(strcmp("Deuce",card_face)==0){
           *handpts=2;
        }
        else if(strcmp("Three",card_face)==0){
            *handpts=3;
        }
        else if(strcmp("Four",card_face)==0){
           *handpts=4;
        }
        else if(strcmp("Five",card_face)==0){
           *handpts=5;
        }
        else if(strcmp("Six",card_face)==0){
           *handpts=6;
        }
        else if(strcmp("Seven",card_face)==0){
           *handpts=7;
        }
        else if(strcmp("Eight",card_face)==0){
           *handpts=8;
        }
        else if(strcmp("Nine",card_face)==0){
           *handpts=9;
        }
        else if(strcmp("Ten",card_face)==0){
           *handpts=10;
        }
        else if(strcmp("Jack",card_face)==0){
           *handpts=11;
        }
        else if(strcmp("Queen",card_face)==0){
           *handpts=12;
        }
        else if(strcmp("King",card_face)==0){
           *handpts=13;
        }
        else{
            printf("Error number 2 - Converting error. Program will now close.");
            exit(2);
    }
}

void sort(int values[]){
    for(int i=0; i<5; i++){
      for(int j=0; j<5-1; j++) {
	if(values[j]>values[j+1]) {
	   int temp = values[j+1];
	      values[j+1] = values[j];
		values[j] = temp;
	}
       }
    }
}

int straight_catcher(int values[]){
    int straight=0;
    if(values[0]==values[1]-1 && values[0]==values[2]-2 && values[0]==values[3]-3 && values[0]==values[4]-4){
        straight++;
    }
    return straight;
}

void catcher(char **faces, int points[], int sigs[], int *handpts){
    int j=1;
    int g=1;
    int no=0;
    int pass;
    int token=0;
    char ** faceatm= malloc(5 * sizeof(char*));
    
    for(int i=0; i<5; i++){
        j=i+1;
        g=i;
        no=0;
        faceatm[i]=malloc(sizeof(faces[i]));
        strcpy(faceatm[i],faces[i]);
        
        if(g>0){                                    //THIS
            do{                                     //WHOLE
                pass=strcmp(faceatm[i],faceatm[g-1]);//PART RESOLVES
                g--;                                  //DUPLICATE
                if (pass==0){                         //APPEARANCE
                    break;                            //OF
                }                                     //MATCHES
            }while(g>0);                              //EXAMPLE
        }                                             //JACK
        if (pass==0){                                 //JACK JACK
            continue;                                 //TEN, QUEEN
        }                                             //SIGNALS THAT ARE EQUAL TO 1 ARE: TRIPPLE,PAIR. THIS PREVENTS IT.
        
        if(j<5){
          do{
             token=strcmp(faceatm[i],faces[j]);
              if(token==0){
                  no++;
               }
               j++;
           }while(j<5);
        }
        switch(no){
            case 1: printf("Pair of %ss\n",faceatm[i]); sigs[0]++;  break;
            case 2: printf("Three of %ss\n",faceatm[i]); sigs[1]++;  break;
            case 3: printf("Poker of %ss\n",faceatm[i]); sigs[2]++; break;
        }
    }
}

int flush_catcher(char **card_suits){
    char *suitatm=malloc(sizeof(card_suits[0]));
    int flush=0;
    int j=0;
    int token;
    int no=0;
    
    strcpy(suitatm,card_suits[0]);
    
    do{
      token=strcmp(suitatm,card_suits[j]);
      if(token==0){
        no++;
      }
      j++;
    }while(j<5);
    if(no==4){
        printf("FLUSH OF %s",suitatm);
        flush++;
    }
    return flush;
}

char* fixNshow (char hand[6][150]){
    char ** handFIXED = malloc(10 * sizeof(char*));
    for(int i=0; i<5; i++){
        handFIXED[i]=malloc(sizeof(hand[i+1]));
        handFIXED[i]=hand[i+1];
    }
    for(int i=0; i<5; i++){
        printf("%s\n",handFIXED[i]);
    }
    return handFIXED;
}
 
int* signal_catcher(char **handFIXED){
       char *token;
       char ** faces = malloc(5 * sizeof(char*));
       char ** suits = malloc(5 * sizeof(char*));
       int pts[5];
       int handpoints;
       
       int signals[5]={0,0,0,0,0}; //pair,t-o-k,f-o-k,straight,flush
       
       for(int i=0; i<5; i++){
        token=strtok(handFIXED[i]," ");
        faces[i]=malloc(sizeof(handFIXED[i]));
        suits[i]=malloc(sizeof(handFIXED[i]));
         if(token!=NULL){
           strcpy(faces[i],token);
           token=strtok(NULL," ");
           if(token!=NULL){
             strcpy(suits[i],token);
           }
         }
    }
    printf("\n");
    
    converter(pts,faces);
    sort(pts);
    catcher(faces,pts,signals,&handpoints);
    signals[3]=straight_catcher(pts);
    signals[4]=flush_catcher(suits);
    return signals;
}

/*
    int totalpoints=0;
    int highcard=0;
    //Pairs, tripples, pokers, two pairs
    
    //End of hand evaluation
    //Points
    highcard=hardness[4];
        if(pair==0 && three==0 && poker==0 && straight==0 && flush==0){totalpoints=highcard;}
        else if(pair==1 && three==0 && poker==0 && straight==0 && flush==0){totalpoints=14;}
        else if(pair==2 && three==0 && poker==0 && straight==0 && flush==0){totalpoints=15;}
        else if(pair==0 && three==1 && poker==0 && straight==0 && flush==0){totalpoints=16;}
        else if(pair==0 && three==0 && poker==0 && straight==1 && flush==0){totalpoints=17;}
        else if(pair==0 && three==0 && poker==0 && straight==0 && flush==1){totalpoints=18;}
        else if(pair==1 && three==1 && poker==0 && straight==0 && flush==0){totalpoints=19;}
        else if(pair==0 && three==0 && poker==1 && straight==0 && flush==0){totalpoints=20;}
        else if(pair==0 && three==0 && poker==0 && straight==1 && flush==1){ 
            if(hardness[0]==1 && hardness[1]==10 && hardness[2]==11 && hardness[3]==12 && hardness[4]==13){
                totalpoints=22;
            }
            else {
                totalpoints=21;
            }    
        }
    return totalpoints;
}*/



int main(void) {
    const char *suit[ SUITS ] ={ "Hearts", "Diamonds", "Clubs", "Spades" };
    const char *face[ FACES ] ={ "Ace", "Deuce", "Three", "Four",
                                 "Five", "Six", "Seven", "Eight",
                                 "Nine", "Ten", "Jack", "Queen", "King" };
    unsigned int deck[ SUITS ][ FACES ] = { 0 };
    char first[6][150]={""};
    char **hand;
    int handpoints;
    int *signals;
    
    srand( time( NULL ) );
    
    shuffle( deck );
    deal(deck,face,suit,first);
    hand=fixNshow(first);
    signals=signal_catcher(hand);
    
}
