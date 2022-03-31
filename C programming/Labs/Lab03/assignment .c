#include <stdio.h>


int main()
{
	char str[1024];
	int a=0, e=0, i=0, o=0, u=0;
	int j;

	printf("Enter a string\n");
	gets(str);

	printf("%d\n", i);
	for (j = 0; str[j] != '\0'; j++)
	{

		if (str[j]=='a'|| str[j] == 'A') 
			a++;
		
		if (str[j]=='e'|| str[j] == 'E') 
			e++;
		
		if (str[j]=='i'|| str[j] == 'I') 
			i++;
		
		if (str[j]=='o'|| str[j] == 'O') 
			o++;
		
		if (str[j]=='u'|| str[j] == 'U') 
			u++;
	}

	printf("A/a:%d E/e:%d I/i:%d O/o:%d U/u:%d\n",a,e,i,o,u );
	return 0;
}
