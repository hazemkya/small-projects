#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
	int size;

	printf("Enter the number of integers to process:");
	scanf("%d", &size);

	int *arr = (int *)malloc(sizeof(int)* size);

	getInput(arr, size);
	calcAvg(arr, size);



	return 0;
}

void getInput(int *arr,int size){
	int first = 1, counter=1;

	do
	{
		int temp, i, valid=1;
		printf("Enter value # %d:", counter);
		scanf("%d", &temp);

		if (first){
			*arr = temp;
			first =0;
			counter ++;
			continue;	
		}

		for (i = 0; i < counter; i++){
			if (*(arr + i) == temp){
				valid = 0;
			}
		}

		if (valid)
		{
			*(arr + counter) = temp;
			counter ++;
			continue;	
		}
		
		printf("You have entered %d already\n", temp);

	} while(counter < size+1);

}

void calcAvg(int *arr,int size){
	int i, sum, avg;

	for (i = 0; i < size; i++)
	{
		printf("%d\n", *(arr + i));
		sum = sum +( *(arr + i));
	}

	avg= sum/size;

	printf("The average of array elements: %d\n", avg);

}