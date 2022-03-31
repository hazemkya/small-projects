#include <stdio.h>


int part1(){
printf("Part 1:\n");
int n =5, i;
if (n > 0)   
	for (i = 0; i < n; i++)     
		if (i % 7 > 0) {
		    printf("...");
		    return i;
		   } 
		else
		    printf("error, n is negative\n"); 


printf("----------------------------------\n");

return 0;
}

int part2(){
printf("\nPart 2:\n");
int c, i, j;
char s[9] = "STRESSED";
  for (i = 0, j = 7; i < j; i++, j--) {
     c = s[i];
     s[i] = s[j];
     s[j] = c;
    }         
 printf("%s\n", s);

printf("----------------------------------\n");

return 0;
}

int part3(){
printf("Part 3:\n");
int a = 10; 
do {
  if( a == 15) {
       a = a + 1;
            continue;   
          }   
          printf("value of a: %d\n", a);   
          a++; 
        } while( a < 20 ); 

printf("----------------------------------\n");

return 0;
}

int part4(){
printf("Part 4:\n");
int x = 5, y = -3; 
if (x = y)    
	printf("%d\t%d\n", x, y); 
else if (x > y)     
	printf("%d > %d\n", x, y);   
else     
	printf("%d < %d\n", x, y);

printf("----------------------------------\n");

return 0;
}

int main(){
 
part1(); part2(); part3(); part4();

	return 0; 
}
