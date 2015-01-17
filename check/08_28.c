/* 8.28: pointers way only */
#include <stdio.h>
#include <string.h>		/* for comparison/check purposes */

char *mystrcpy(char *s1, const char *s2);
char *mystrncpy(char *s1, const char *s2, size_t n);
char *mystrcat(char *s1, const char *s2);
char *mystrncat(char *s1, const char *s2, size_t n);

int main (void)
{
   /* strcpy */
   char string[20] = "Hello";

   printf("%s\n", mystrcpy(string, "World"));
   strcpy(string, "Hello");  /* restoring old value */

   /* strncpy */
   printf("%s\n", mystrncpy(string, "Qwerty", 3));
   strcpy(string, "Hello");  /* restoring old value */

   /* strcat */
   printf("%s\n", mystrcat(string, "World"));
   strcpy(string, "Hello");  /* restoring old value */

   /* strncat is buggy somehow ...*/
   printf("%s\n", mystrncat(string, "World", 3));
   
   return 0;
}

char * mystrcpy(char *s1, const char *s2){
   char * res = s1;

   while(( *s1++ = *s2++ ) != '\0');
   return res;
}

char * mystrncpy(char *s1, const char *s2, size_t n){
   
   size_t i = 1;
   char * res = s1;

   while( (i <= n) && (( *s1++ = *s2++ ) != '\0') )
      i++;

   /* should add '\0' if n > length of copied string here to be perfectly
      compiant  */
   
   return res;
}

char *mystrcat(char *s1, const char *s2){

   char * res = s1;
   
   /* go to the end of the first string */
   while(*s1 != '\0') s1++;
   /* then copy s2 */
   mystrcpy(s1, s2);
   
   return res;

}

char *mystrncat(char *s1, const char *s2, size_t n){

   char * res = s1;
   
   /* go to the end of the first string */
   while(*s1 != '\0') s1++;
   /* then copy */
   mystrncpy(s1, s2, n);
   
   return res;

}
