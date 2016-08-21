/*Solution provided by dilippuri*/
#include<stdio.h>

int main(void){
  int i;
  printf("Decimal\tOctal\tHexadecimal\n");

  for(i=1;i<=256;i++){
    printf("%d\t%o\t%x\n", i,i,i);
  }

 return 0;
}
