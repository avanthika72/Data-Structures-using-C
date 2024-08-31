#include<stdio.h>
void enqueue();
void dequeue();
void display();
int queue[50],front=-1,rear=-1,item,max_size;
void main()
{ 
	int choice=0;
	printf("Enter the size of queue: ");
	scanf("%d",&max_size);
	while (choice!=4) {
		printf("\nEnter Operation to perform on Queue: 1. Enqueue 2. Dequeue 3. Display 4. Exit \n");
		scanf("%d",&choice);
		switch (choice) {
			case 1: 
				enqueue();
				break;
			case 2: 
				dequeue();
				break;
			case 3: 
				display();
				break;
			case 4: 
				printf("\nSuccessfully exited from the program");
				break;
			default:
				printf("\nInvalid Input!");
		}
	}
}
void enqueue() {
	if (rear == max_size-1) 
		printf("\nQueue Overflow Error!");
	else {     
		printf("\nEnter the element to enqueue: ");
		scanf("%d",&item);
		if (front == -1 && rear == -1) {
			rear=0;
			front=0;
		}
		else 
			rear++;
		queue[rear]=item;
	}
}
void dequeue() {
	if (front == -1 && rear == -1)                  
		printf("\nQueue Underflow Error!");
	else {
		printf("\nDeleted element is %d",queue[front]);
		if (front == rear) {
			front=-1;
			rear=-1;
		}
		else 
			front++;
	}
}
void display() {
	if (front == -1 && rear == -1) 
		printf("\nQueue Empty!");
	else {
		printf("\nGiven queue is: \n");
		for (int i=front; i<=rear; i++) 
			printf("%d \t",queue[i]);
	}
}
