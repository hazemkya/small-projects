#include <stdio.h>
int add(int first, int second){
  return first + second + 15;
}
int operation(int first, int second, int (*functocall)(int, int)){
   return (*functocall)(first, second);
}
int main(){
   int  a;
   int  (*plus)(int, int) = add;
   a = operation(15, 10, plus);
   printf("%d", a);
   return 0;
}
