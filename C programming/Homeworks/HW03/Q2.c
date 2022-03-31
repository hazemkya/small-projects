#include <stdio.h>

int main(){
	char ch = getchar();
	if (ch >= 65 && ch <= 90)		 /* test if ch is a capital letter */     
		printf("%c is a capital letter\n", ch);
   		else if (ch >= 97 && ch <= 122)	 /* test if ch is a small letter */       
   			printf("%c is a small letter\n", ch);
        	else if (ch >= 48 && ch <= 57)	 /* test if ch is a digit */         
       			printf("%c is a digit\n", ch);
               	else if (ch == 43 || ch == 45 || ch == 42 || ch == 47 || ch == 37) /* test if ch is an arithmetic operator */           
        			printf("%c is an arithmetic operator\n", ch);
                 	else  
                 		printf("Unrecognized character");   
	return 0; 
}
