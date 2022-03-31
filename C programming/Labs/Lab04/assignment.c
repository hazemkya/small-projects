#include <stdio.h>

#define True 1
#define False 0

int findLowest(int* arr,int size){
    int i,lowest=arr[0];
    for(i=0;i<size;i++){   
        if(arr[i]<lowest)
	    lowest=arr[i];
}
    printf("Droped value: %d\n",lowest);
    return lowest;
}

int avg(int* arr,int size){
    int i,sum=0;
    float avg;
    int foundLowest = False;
    int lowest = findLowest(arr, size);
    /*calculate avg*/
    for(i=0;i<size;i++){
       if(lowest == arr[i] && !foundLowest) {
          foundLowest =True;
	  continue;
       }
       sum+= arr[i];
    }
    avg = sum/size-1;
    printf("average of best 3 scores: %.2f \n",avg);

    return avg;
}

int main(){
   int i,size = 4;
   int arr[size];
   for(i=0;i<size;i++){
   printf("Enter digit %d:",i+1);
   scanf("%d",&arr[i]);
  }

   avg(arr,size);
   return 0;
}
