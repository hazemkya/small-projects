#include <stdio.h>
#include <stdlib.h>

struct Student{
	int ID;
	char* name[50];
	float GPA;
};

struct Student* fillData(struct Student* Students, int count);
struct Student* printData(struct Student* Students, int count);

int main(int argc, char const *argv[])
{
	int count =0;

	printf("Enter the number of students:");
	scanf("%d", &count);

	if (count < 1){
		printf("Count must be a postive number");
		return 1;
	}

	struct Student* Students;
	Students = calloc(count+1, sizeof(int) + (sizeof(char)*50) + sizeof(float));
	
	Students = fillData(Students, count);
	Students = printData(Students, count);

	return 0;
}

struct Student* fillData(struct Student* Students, int count){
	int i;
	for (i = 0; i < count; i++)
	{
		
		printf("Enter ID of student %d:", i+1);
		scanf("%d", &((Students + i) -> ID));

		printf("Enter name of student %d:", i+1);
		scanf("%s", ((Students + i) -> name));

		printf("Enter GPA of student %d:", i+1);
		scanf("%f", &((Students + i) -> GPA));
	}
	return Students;
}

struct Student* printData(struct Student* Students, int count){
	int i, index=0;
	float highest= (Students + 0) -> GPA;

	for (i = 0; i < count; i++)
	{
		if (((Students + i) -> GPA) > highest){
			highest = (Students + i) -> GPA ;
			index = i;
		}
	}

	printf("%s\n", (Students + index) -> name );

	for (i = 0; i < count; i++)
	{
		if (i == index) continue;
		printf("%s\n", (Students + i) -> name);
	}

	return Students;

}