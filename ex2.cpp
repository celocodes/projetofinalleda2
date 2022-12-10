#include <iostream>

struct Node {
    int number;
    Node * next;
};

struct Queue {
    Node * head;
	Node * tail;
    
    int max_items;

    int qty;
};

int countElem(struct Queue * & queue) {
	int count = 0;
  	if(queue->head == NULL){
		printf("\nQueue empty");
	} else{
			struct Node * aux = queue->head;
			while(aux != NULL){
				count++;
				aux = aux->next;
			}
	}

	return count;
}

void isFull(struct Queue * & queue) {
	if(queue->max_items > countElem(queue)) printf("\nQueue is available");
	else printf("\nQueue is full");
}

void isEmpty(struct Queue * & queue) {
	if(queue->head == NULL) printf("\nQueue is empty");
	else printf("\nQueue is not empty");
}

int findElem(struct Queue * & queue, int searched) {
	int flag = 0;
  	if(queue->head == NULL){
		printf("\nQueue empty");
	} else{
			struct Node * aux = queue->head;
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

void checkQueue(struct Queue * & queue) {
  	if(queue->head == NULL){
		printf("\nQueue empty");
	} else{
		printf("\nShowing queue: ");
			struct Node * aux = queue->head;
			while(aux != NULL){
				printf("%d ", aux->number);
				aux = aux->next;
			}
	}
}

void enqueue(struct Queue * & queue, int num) {
	if(queue && (queue->max_items > countElem(queue))){
		Node * newNode = (Node *)calloc(1, sizeof(Node));
	
		newNode->number = num;
		newNode->next = NULL;
		
		if(queue->head == NULL) {
			queue->head = newNode;
			queue->tail = newNode;
	  	} else {
			queue->tail->next = newNode;
			queue->tail = newNode;
	  	}

		printf("\nNumber enqueued.");
		queue->qty++;
		
	} else printf("\nUnable to enqueue");
}

int dequeue(struct Queue * & queue){
  if(queue){
		Node * next = queue->head->next;
	
		if(next){
			int val = next->number;
			queue->head->next = next->next;
			queue->head->number = next->number;
			free(next);
			printf("\nNumber dequeued.");
			return val;

			queue->qty--;
		}
	}
	return -1;
}

int main() {
	struct Queue * myQueue = (struct Queue *) calloc(1, sizeof(struct Queue));
  	myQueue->max_items = 7;
	myQueue->qty = 0;

	isEmpty(myQueue);
	printf("\n");
	
  	enqueue(myQueue, 10);
  	enqueue(myQueue, 20);
  	enqueue(myQueue, 30);
  	enqueue(myQueue, 40);
	enqueue(myQueue, 50);
	enqueue(myQueue, 60);
	enqueue(myQueue, 70);

	printf("\n");
	
  	checkQueue(myQueue);

	isEmpty(myQueue);
	isFull(myQueue);

	printf("\n");
	
	enqueue(myQueue, 70);

	printf("\n");
	
	dequeue(myQueue);
	dequeue(myQueue);

	printf("\n");
	
	checkQueue(myQueue);
	findElem(myQueue, 10);

	printf("\n");
	
	enqueue(myQueue, 10);
	checkQueue(myQueue);
	findElem(myQueue, 10);
}