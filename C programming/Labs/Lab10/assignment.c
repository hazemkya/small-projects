#include <stdlib.h>
#include <stdio.h>

struct node{
	char data;
    struct node* next;
};

struct linkedList{
	struct node* top;
} stack={0};

int isEmpty() {
   return stack.top == NULL;
}

void push(char info){
	struct node* new = (struct node*) calloc(sizeof(struct node),1);

	new->data = info;
	new->next = stack.top;
	stack.top = new;
}

char pop(){
	if(isEmpty()) return 0;
	
	char result = stack.top->data;
	
	stack.top = stack.top -> next;
	
	return result;
}



int main(){
	stack.top = NULL;

	char str[50];
	printf("Type a word:");
	gets(str);
	int i;

	for(i=0; str[i]!= '\0';i++){
		push(str[i]);
	}

	while(!isEmpty())
		printf("%c", pop());

	printf("\n");

	return 1;
}
