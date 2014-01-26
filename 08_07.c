#include <stdio.h>
#define MAXLEN 20

int main(void)
{
   char a[MAXLEN], b[MAXLEN], c[MAXLEN], d[MAXLEN];
   

   gets(a);
   gets(b);
   gets(c);
   gets(d);

   printf("Sum is %d.\n", 
          atoi(a) + atoi(b) + atoi(c) + atoi(d) 
      );

   return 0;
}

