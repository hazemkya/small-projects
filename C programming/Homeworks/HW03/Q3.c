#include <stdio.h>


int part1(){
printf("Part 1:\n");
int count=0;

int a = 10;
do {
	count++;
   if( a == 15)
    	a = a + 1;
    printf("value of a: %d\n", a++);
  } while( a < 20 );

printf("\nPart 1 count: %d\n",count);
printf("----------------------------------\n");

return 0;
}

int part2(){
printf("Part 2:\n");
int count=0;

int i;
 for(i=900;-5 ;i/=3){
 	count++;
	printf("%d ",i);
    if(i<=34)
    	break; 
 }


printf("\nPart 2 count: %d\n",count);
printf("----------------------------------\n");

return 0;
}

int part3(){
printf("Part 3:\n");
int count=0;

int i,j,k;
for(i=0,k=0;i<=5,k<=3;i++,k+=2){
	count++;
	printf("%d ",i+k); 
}


printf("\nPart 3 count: %d\n",count);
printf("----------------------------------\n");

return 0;
}

int part4(){
printf("Part 4:\n");
int count=0;

int n = 100; 
while (--n){
	count++;   
	printf("%d\n", n*2);
}

printf("\nPart 4 count: %d\n",count);
printf("----------------------------------\n");

return 0;
}

int part5(){
printf("Part 5:\n");
int count=0;

unsigned char c; 
for(c=255; c; c>>=1){ 
	count++;  
	printf("%d ",c); }


printf("\nPart 5 count: %d\n",count);
printf("----------------------------------\n");

return 0;
}

int part6(){
printf("Part 6:\n");
int count=0;


unsigned char c; 
for(c=128; c; c>>=1){  
	count++; 
	printf("%d ",c); 
}

printf("\nPart 6 count: %d\n",count);
printf("----------------------------------\n");

return 0;
}

int part7(){
printf("Part 7:\n");
int count=0;

unsigned char c; 
for(c=1; c; c<<=1){  
	count++; 
	printf("%d ",c); 
}

printf("\nPart 7 count: %d\n",count);
printf("----------------------------------\n");

return 0;
}


int main(){
 
part1(); part2(); part3(); part4(); part5(); part6(); part7();

	return 0; 
}
