#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Car {
	char plate_num[8];
	char* owner_name;
	int owner_tel;
}* PCar;

int match(char* s1, char* s2);
char* get_owner_name(PCar* carr, int size, char* key);
void fill_car(PCar car);

int main()
{

	int count=0, i;
	char key[8];

	printf("Enter number of cars:");
	scanf("%d", &count);


	PCar cars[count];

	for ( i = 0; i < count; i++){
		printf("Card number %d:\n", i+1);
		cars[i] = (PCar)calloc(1, sizeof(PCar));
		fill_car(cars[i]);
	}
	printf("Enter search key:");
	scanf("%s", key);

	char * result = get_owner_name(cars, count, key);
	if (result)
	{
		printf("Owner of %s plate is: %s\n",key, &result);
	}
	else{
		printf("No owner found for %s\n", key);
	}

	return 0;
}

int match(char* s1, char* s2){
	int i;

	if (strlen(s1) != strlen(s2))
		return 0;

	for (i = 0; s1[i] != '\0'; i++){
		if (s1[i] != s2[i])
			return 0;
	}
	return 1;
}

void fill_car(PCar car){

	printf("Enter plate number:");
	scanf("%s", &(car -> plate_num));

	printf("Enter car owner name:");
	scanf("%s", &(car -> owner_name));

	printf("Enter car owner telephone:");
	scanf("%d", &(car -> owner_tel));
}

char* get_owner_name(PCar* carr, int size, char* key){
	int i;
	for (i = 0; i < size; i++)
	{
		if(match((carr[i])->plate_num, key)){
			return (carr[i]) -> owner_name;
		}
	}
	return NULL;
}