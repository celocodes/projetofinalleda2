#include <iostream>

struct Node {
    int number;
    Node * next;
};

struct Stack {
    Node * top;
    
    int max_items;

    int qty;
};

int countElem(struct Stack * & stack) {
	int count = 0;
  	if(stack->top == NULL){
		printf("\nStack empty");
	} else{
			struct Node * aux = stack->top;
			while(aux != NULL){
				count++;
				aux = aux->next;
			}
	}

	return count;
}

void isFull(struct Stack * & stack) {
	if(stack->max_items > countElem(stack)) printf("\nStack is available");
	else printf("\nStack is full");
}

void isEmpty(struct Stack * & stack) {
	if(stack->top == NULL) printf("\nStack is empty");
	else printf("\nStack is not empty");
}

int findElem(struct Stack * & stack, int searched) {
	int flag = 0;
  	if(stack->top == NULL){
		printf("\nStack empty");
	} else{
			struct Node * aux = stack->top;
			while(aux != NULL){
				if(aux->number == searched) { 
					printf("\nElement found");
					flag = 1;
				}
				aux = aux->next;
			}
		if(flag == 0) printf("\nElement not found");
	}

	return flag;
}

void checkStack(struct Stack * & stack) {
  	if(stack->top == NULL){
		printf("\nStack empty");
	} else{
		printf("\nShowing stack: ");
			struct Node * aux = stack->top;
			while(aux != NULL){
				printf("%d ", aux->number);
				aux = aux->next;
			}
	}
}

void push(struct Stack * & stack, int num){
  	if(stack && (stack->max_items > countElem(stack))){
        struct Node * newNode = (struct Node *) calloc(1, sizeof(struct Node));
        newNode->number = num;
        newNode->next = stack->top;
        stack->top = newNode;

		printf("\nNumber inserted.");
		stack->qty++;
		
	} else printf("\nUnable to push");
}

int pop(struct Stack * & stack){
  if(stack){
		Node * next = stack->top->next;
	
		if(next){
			int val = next->number;
			stack->top->next = next->next;
			stack->top->number = next->number;
			free(next);
			printf("\nNumber popped.");
			return val;

			stack->qty--;
		}
	}
	return -1;
}

int main() {
	struct Stack * myStack = (struct Stack *) calloc(1, sizeof(struct Stack));
  	myStack->max_items = 7;
	myStack->qty = 0;

	isEmpty(myStack);
	printf("\n");
	
  	push(myStack, 10);
  	push(myStack, 20);
  	push(myStack, 30);
  	push(myStack, 40);
	push(myStack, 50);
	push(myStack, 60);
	push(myStack, 70);

	printf("\n");
	
  	checkStack(myStack);

	isEmpty(myStack);
	isFull(myStack);

	printf("\n");
	
	push(myStack, 70);

	printf("\n");
	
	pop(myStack);
	pop(myStack);

	printf("\n");
	
	checkStack(myStack);
	findElem(myStack, 60);

	printf("\n");
	
	push(myStack, 60);
	findElem(myStack, 60);
}