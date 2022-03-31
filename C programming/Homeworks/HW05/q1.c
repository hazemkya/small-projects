#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x[4] = {12,20,39,43}, *y; y=x;
	
	printf("%d\n",*y+1 );
	printf("%d\n", *(y+1));
	printf("%d\n", y+=2,*y);
	printf("%d\n", *y =38);
	printf("%d\n", *y -1);
	printf("%d\n", *y++);
	printf("%d\n", *y);
	printf("%d\n", y[0]);
	printf("%d\n", x[2]> y[0]);
	printf("%d\n", y-x);



	return 0;
}