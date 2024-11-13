#include <stdio.h>
void enqueue();
void dequeue();
void display();
int cqueue[50],front=-1,rear=-1,count=0,item,max_size;
void main()
{ 
	int choice=0;
	printf("Enter the size of circular queue: ");
	scanf("%d",&max_size);
	while (choice!=4) {
		printf("\nEnter Operation to perform on Queue: 1. Enqueue 2. Dequeue 3. Display 4. Exit - ");
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
				printf("Successfully exited from the program");
				break;
			default:
				printf("Invalid Input!");
		}
	}
}

void enqueue() {
	if (front == (rear+1)%max_size) {
		printf("Circular Queue Overflow Error \n");
	}
	else {
		printf("Enter the element to enqueue: ");
		scanf("%d",&item);
		if (front == -1 && rear == -1) {
			rear=0;
			front=0;
		}
		else {
			rear=(rear+1)%max_size;
		}
		cqueue[rear]=item;
		count++;
	}
}

void dequeue() {
	if (front == -1 && rear == -1) {
		printf("Circular Queue Underflow Error \n");
	}
	else {
		printf("Deleted element is %d",cqueue[front]);
		count--;
		if (front == rear) {
			front=-1;
			rear=-1;
		}
		else {
			front=(front+1)%max_size;
		}
	}
}

void display() {
	if (front == -1 && rear == -1) {
		printf("Circular Queue Empty \n");
	}
	else {
		printf("\nGiven circular queue is: \n");
		int i=front;
		for (int j=0; j<count; j++) {
			printf("%d \t",cqueue[i]);
			i=(i+1)%max_size;
		}
	}
}
