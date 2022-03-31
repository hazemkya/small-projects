#include <stdio.h>

int main(int argc, char const *argv[])
{
	char CC[]="+966"; char city[]="11"; char a='p';


	printf("1) %6d, %4d\n", 86, 1040);	

	printf("2) %12.5e\n",30.253);

	printf("3) %d\t%c\n", (int)30.253, (char)83.162);

	printf("4) %s-%s-%d\n", CC, city, 4334567);

	printf("5) %d:%d:%d %cM (%d/%d/%d)", 9, 3, 7, a, 12, 7, 16);

	return 0;
}