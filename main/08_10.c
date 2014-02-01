
#include <stdio.h>
#include <string.h>

#define MAXLEN 80

int main(void)
{

   char a[MAXLEN], b[MAXLEN];
   int results;
   int len;
   char * results_word;

   printf("Enter the first string: ");
   gets(a);
   printf("Enter the second string: ");
   gets(b);
   printf("Enter the comparation length: ");
   scanf("%d", &len);

   results = strncmp(a,b,len);
   results_word = 
      results>0 ? "greater than" : 
      results == 0? "equal to" : "less than"
      ;

   printf("\"%s\" is %s \"%s\" \n",
          a, results_word,  b );

   return 0;
}
