#include <stdio.h>
#include <string.h> /*for testing purposes*/

size_t myStrlenPtr(const char *s);
size_t myStrlenArr(const char *s);

int main(void)
{

   printf("%u\n", (unsigned int) strlen("qwerty"));
   printf("%u\n", (unsigned int) myStrlenPtr("qwerty"));
   printf("%u\n", (unsigned int) myStrlenArr("qwerty"));
   printf("%u\n", (unsigned int) strlen(""));
   printf("%u\n", (unsigned int) myStrlenPtr(""));
   printf("%u\n", (unsigned int) myStrlenArr(""));

   return 0;
}

size_t myStrlenPtr(const char *s)
{

   size_t len = 0;
   while( *(s + len) != '\0') len++;
   return len;

}

size_t myStrlenArr(const char *s)
{
   size_t len = 0;
   while( s[len] != '\0') len++;
   return len;

}
