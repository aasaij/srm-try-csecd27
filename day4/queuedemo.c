//Program to implement circular queue using array
#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{
	int id;
	char name[30];
	double salary;	
}employee;

typedef struct Queue{
	int capacity;
	int front;
	int rear;
	employee *employees;
}queue;

typedef enum boolean {false, true}boolean;
boolean isFull(queue*);
boolean isEmpty(queue*);
queue *createQueue(int max){
	queue *temp = (queue*)malloc(sizeof(queue));
	temp->capacity = max;
	temp->front = -1;
	temp->rear = -1;
	temp->employees = (employee*)malloc(sizeof(employee) * max) ;
	return temp;
}
boolean enqueue(queue *q, employee e){
	if (isFull(q))	
		return false;
	if (q->front == -1) q->front = 0;
	q->rear = (q->rear + 1) % q->capacity;
	q->employees[q->rear] = e;
	return true;
}
employee* dequeue(queue *q){
	if (!isEmpty(q)){
		employee *emp = &q->employees[q->front];
		if (q->front==q->rear)
			q->front = q->rear = -1;
		else
			q->front = (q->front+1) % q->capacity;	
		return emp;		
	}
	return NULL;
}
employee* front(queue *q){
	if (isEmpty(q))
		return NULL;
	return &q->employees[q->front];
}
void printQueue(queue *q){
	if (!isEmpty(q)){
		printf("\n[");
		for (int i = q->front; i!=q->rear;){
			employee e = q->employees[i];
			printf("[%d, %s, %.2f],", e.id, e.name, e.salary);
			i = (i+1)% q->capacity;
		}
		employee e = q->employees[q->rear];
		printf("[%d, %s, %.2f]]", e.id, e.name, e.salary);
	}
	else
		printf("\n[]");
}
int queueSize(queue *q){
	int cnt;
	for (int i = q->front; i!=q->rear;){
		cnt++;
		i = (i+1)% q->capacity;
	}
	return cnt;
}
boolean isFull(queue *q){
	return q->rear+1 == q->capacity && q->front == 0 || (q->rear+1 == q->front);		
}

boolean isEmpty(queue *q){
	return q->front == -1 && q->rear == -1;	
}

void printMenu(){
	printf("\nQueue operations Demo\n");
	printf("*********************\n");
	printf("1. Enqueue\n");
	printf("2. Dequeue\n");
	printf("3. Display Front\n");
	printf("4. Display the queue\n");
	printf("5. Queue length\n");
	printf("6. Exit\n");
	printf("Enter your choice : ");
}

employee getEmployee(){
	employee emp;
	printf("Employee ID     : ");
	scanf("%d", &emp.id);
	printf("Employee Name   : ");
	scanf("\n%[^\n]s", emp.name);
	printf("Employee Salary : ");
	scanf("%lf", &emp.salary);
	return emp;	
}

void printEmployee(employee emp){
	printf("Employee ID     : %d\n", emp.id);
	printf("Employee Name   : %s\n", emp.name);
	printf("Employee Salary : %.2lf", emp.salary);
}

int main(){
	queue *myQueue = NULL;
	int size;
	scanf("%d", &size);
	myQueue = createQueue(size);
	while(true){
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
//				if (!isFull(myQueue)){
					if (!isFull(myQueue) && enqueue(myQueue, getEmployee()))
						printf("Enqueued...\n");
					else
						printf("Queue is full!\n");
//				}
//				else
//					printf("Queue is full!\n");
				break;
			case 2:{
				employee *e = dequeue(myQueue);
				if (e){
					printEmployee(*e);
				}
				else
					printf("Queue is empty..\n");				
				break;
			}
			case 3:{
				employee *e = front(myQueue);
				if (e){
					printEmployee(*e);
				}
				else
					printf("Queue is empty..\n");				
				
				break;
			}
			case 4:
				printQueue(myQueue);
				break;
			case 5:
				printf("Queue length :  %d\n", queueSize(myQueue));
				break;
			default:
				printf("Thank you so much for being very very silent in the class!");
				exit(0);				
		}
	}
	return 0;
}