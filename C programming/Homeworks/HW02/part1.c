#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x=1, y=7, z=0; double i=1.5, j=-0.7; char a='m';

	double n1 = x * y - z /i;
	printf("1) %.2f \n",n1);

	double n2 = 3 *(2 * x + 1 )/x;
	printf("2) %.2f \n",n2);

	double n3 = x && y | z;
	printf("3) %.2f \n",n3);

	double n4 = (double)x / i * y;
	printf("4) %.2f \n",n4);

	double n5 = a / y +  (int) i / x;
	printf("5) %.2f \n",n5);

	double n6 = i > j & j > x || !z;
	printf("6) %.2f \n",n6);

	double n7 = x+y--+z++;
	printf("7) %.2f \n",n7);

	double n8 = --x > z++ ? y-- : i*j;
	printf("8) %.2f \n",n8);

	double n9 = a ? y - x : x - y ;
	printf("9) %.2f \n",n9);

	double n10 = x = 5 ? (y=z) : (z = y );
	printf("10) %.2f \n",n10);

	return 0;
}