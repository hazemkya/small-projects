#include <stdio.h>


int isprime (int n){
	int i, result=0, divisibles=0;
	printf("Number is : %d\n",n); 
	for (i=1; i <= n; i++){
		if( (n%i) ==-0) {
		printf("%d divisible by %d \n",n,i) ;
		divisibles ++;
			if (divisibles == 2)
				result =1;
		}
	}
	printf("Total divisibles: %d \n", divisibles );
	printf("Result is: %d\n", result);
	printf("=======================\n");
	return result;
}

int slen (char str[]){
	int i, count=0;
	printf("%s\n", str);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			count++;
		else if (str[i] >= 'a' && str[i] <= 'z')
			count++;
	}
	printf("count is: %d\n",count);
	return count;
}

int reverse(){
	int input;
	printf("Enter a number: ");
	scanf("%d", &input);
	if (input < 0)
		return 0;

	reverse();
	printf("%d ",input);

	return 0;
}

int sumdig(int dig){
	int i, sum=0, digCount=0,digIndex=1, temp =dig;

	do {
    temp /= 10;
    ++digCount;
  	} while (temp != 0);
  	printf("digit count is: %d\n",digCount);

  	for (i = 0; i < digCount; i++)
  	{
  		sum = sum +(dig/digIndex)%10;
  		digIndex*=10;
  	}
  	printf("Sum of digits is:%d\n", sum);

	return 2;
}

int main(){
	/*isPrime function*/
	int checkPrime=5;
	printf("isPrime function for: %d\n",checkPrime);
	isprime(checkPrime);
	
	/*sLen function */
	char str[1024] = "Whatever!";
	printf("slen function for: %s\n",str);
	printf("%d\n", slen(str));
	printf("=========================\n");

	/*reverse function*/
	printf("reverse function\n");
	reverse();
	printf("\n=========================\n");

	/*sumdig function*/
	int dig=2323795;
	printf("sumdig function for: %d\n",dig);
	sumdig(dig);
	printf("=========================\n");

	return 0;
}