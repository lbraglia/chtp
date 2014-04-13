/* 
   03_35.c: palindromes

 */
#include <stdio.h>

int main (void) {
   
   int number = 0;
   int first_digit = 0;
   int second_digit = 0;
   int third_digit = 0;
   int fourth_digit = 0;
   int fifth_digit = 0;

   printf("Insert a number: ");
   scanf("%d", &number);

   first_digit = number / 10000;
   second_digit = (number % 10000)/1000 ;
   third_digit = (number % 1000)/100 ;
   fourth_digit = (number % 100)/10 ;
   fifth_digit = (number % 10) ;

   printf("1st digit = %d\n", first_digit);
   printf("2nd digit = %d\n", second_digit);
   printf("3nd digit = %d\n", third_digit);
   printf("4nd digit = %d\n", fourth_digit);
   printf("5nd digit = %d\n", fifth_digit);

   ((first_digit == fifth_digit) * (second_digit ==  fourth_digit)) ?
      printf("Number %d is palindrome\n", number) :
      printf("Number %d is NOT palindrome\n", number) ;
      

   return 0;

}
