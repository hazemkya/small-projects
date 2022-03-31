#include <stdio.h>

int main(){
  int a = 1, b=2,c=3;  

  printf("::::: Powers Table :::::\n");

  printf("Number\t Square\t Cube\t 4th power\n");

  printf("%d\t %d\t %d\t %d\n", a, a*a, a*a*a, a*a*a*a);
 
  printf("%d\t %d\t %d\t %d\n", b, b*b, b*b*b, b*b*b*b);

  printf("%d\t %d\t %d\t %d\n", c, c*c, c*c*c, c*c*c*c);
  return 0;
}
