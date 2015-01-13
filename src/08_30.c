/* 
   08.30
 */

#include <stdio.h>

int mystrcmp(const char *s1, const char *s2);
int mystrncmp(const char *s1, const char *s2, size_t n);

int main (void)
{

   char *s1 = "Happy New Year";
   char *s2 = "Happy Holidays";
   char *s3 = "Happy";
   
   printf("%d\n", mystrcmp(s1,s1));
   printf("%d\n", mystrcmp(s1,s2));
   printf("%d\n", mystrcmp(s2,s1));
   printf("%d\n", mystrcmp(s1,s3));
   printf("%d\n", mystrcmp(s3,s1));

   printf("\n");
   
   printf("%d\n", mystrncmp(s1,s2,6));
   printf("%d\n", mystrncmp(s1,s2,7));
   printf("%d\n", mystrncmp(s2,s1,7));
   
   return 0;

}

int mystrcmp(const char *s1, const char *s2){

   /* go on until at least one is finished */
   while( (*s1 != '\0') && (*s2 != '\0') ){
      if (*s1 > *s2)
	 return 1;
      else if (*s1 < *s2)
	 return -1;
      else {/*go to the next if equal*/
	 s1++;
	 s2++;
      }
   }

   /* hereat least now if both are '\0', we can compare the string anyway
   because '\0' is less than anything, see printf("%d", (int) '\0') */
   if (*s1 == *s2)
      return 0;
   else if (*s1 > *s2)
      return 1;
   else if  (*s1 < *s2)
      return -1;
   
}


int mystrncmp(const char *s1, const char *s2, size_t n){

   size_t cntr = 1;
   
   /* go on until at least one is finished or we reached n-1 (-1 because we
      do the last comparison in the following if*/
   while( (*s1 != '\0') && (*s2 != '\0') && (cntr < n) ){
      if (*s1 > *s2)
	 return 1;
      else if (*s1 < *s2)
	 return -1;
      else {/*go to the next if equal*/
	 s1++;
	 s2++;
	 cntr++;
      }
   }

   /* the handling is the same */
   if (*s1 == *s2)
      return 0;
   else if (*s1 > *s2)
      return 1;
   else if  (*s1 < *s2)
      return -1;


}
