#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORMAT "%s. %s %c. %s"

typedef struct fullname
{
	char gender[4];
	char firstName[50];
	char midInital;
	char familyName[50];

}fullname ;

char* format_name(char* firstName, char* midInital, char* familyName, char gender){
	fullname* formated = malloc(sizeof(fullname) + 2);
	char* result = (char*)malloc(sizeof(fullname) + 2);

	if (gender == 'm')
	{
		memcpy(formated->gender, "Mr", 4);
	}
	else{
		memcpy(formated->gender, "Mrs", 4);
	}

	memcpy(formated->firstName, firstName, 50);
	formated->midInital = midInital[0];
	memcpy(formated->familyName, familyName, 50);

	snprintf(result,sizeof(fullname), FORMAT ,formated->gender, formated->firstName, formated->midInital, formated->familyName);

	return result;
}

void split_name(char* name, char* fname, char* sname, char* gender){
	fullname* formated = malloc(sizeof(fullname) + 2);

	sscanf(name, "%[a-zA-Z]. %[a-zA-Z] %c. %[a-zA-Z]" ,formated->gender, formated->firstName, &formated->midInital, formated->familyName);

	if (strcmp(formated->gender, "Mr") == 0)
	{
		*gender = 'm';
	}
	else{
		*gender = 'f';
	}

	memcpy(fname, formated->firstName, 50);
	memcpy(sname ,formated->familyName, 50);
}


int main(int argc, char const *argv[])
{
	char * name = format_name("Hazem", "Khaled", "Assiri", 'm');
	printf("%s\n",name);

	char fn[50];
	char sn[50];
	char gender;

	split_name("Mr. Hazem K. Assiri", fn, sn, &gender);

	printf("%s %s %c\n", fn,sn, gender);
	return 0;
}