int main(int argc, char const *argv[])
{

/*1) A code that prints all characters of the string.*/
  
  char ch, *str1 = "Hello World";

  while((ch= *(str1++) ) != '\0')
    printf("%c", ch);

printf("\n");
printf("====================\n");

/*/2) A code that prints the elements at the even indices.*/
  int *p, arr[] = {10,33,15,22,14};
  for (p=arr; p<arr+5; (p+=2) )
    printf("%d ", *p);


printf("\n");
printf("====================\n");

/*3) A code that reverses a string:   */
char n=0, *s, *e, str[] = "siht hsinif ot ekil I";
	while (str[++n]);
	for(s=str, e=str+n-1; e>s ; e--){
		printf("%c\n", *e);
	    str[n] = *e;
	    *e = *s;

	    *s = str[n]; 
	} 
  	str[n] = '\0';
	

	return 0;
}