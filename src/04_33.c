/*Solution provided by dilippuri*/
#include <stdio.h>

int main(void){
  int num;
  printf("Enter the num: ");
  scanf("%d", &num);
  //----------------
      while (num>100) {
        printf("C");
        num = num - 100;
      }
      if (num==100) {
        printf("C\n");
        return 0;
      }
      if (num==99) {
        printf("IC\n");
        return 0;
      }
  //----------------
      while (num>50) {
        printf("L");
        num = num - 50;
      }
      if (num==50) {
        printf("L\n");
        return 0;
      }
      if (num==49) {
        printf("IL\n");
        return 0;
      }
    //----------------
      while (num>10) {
        printf("X");
        num = num - 10;
      }
      if (num==10) {
        printf("L\n");
        return 0;
      }
      if (num==9) {
        printf("IX\n");
        return 0;
      }
    //----------------
      while (num>5) {
        printf("V");
        num = num - 5;
      }
      if (num==5) {
        printf("V\n");
        return 0;
      }
      if (num==4) {
        printf("IV\n");
        return 0;
      }
    //----------------
    while (num>1) {
      printf("I");
      num = num - 1;
    }
    if (num==1) {
      printf("I\n");
      return 0;
    }
  return 0;
}
