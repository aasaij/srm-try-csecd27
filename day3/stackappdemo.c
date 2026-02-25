//Program to implement stack using array
#include <stdio.h>
#include <stdlib.h>
typedef enum boolean {false, true} boolean;
//typedef enum boolean {true=1, false=0} boolean;
typedef struct Book{
	int id; // 4
	char title[30]; // 30
	double price; // 8
}book;
typedef struct Stack {
	int capacity;
	int size;
	book *books;
}stack;
stack *createStack(int max){
	stack *st = (stack*)malloc(sizeof(stack));
	st->capacity = max;
	st->size = -1;
	st->books =(book*) malloc(sizeof(book)*max);
	return st;
}
boolean isEmpty(stack* st){
//	if (st->size ==-1)
//		return true;
//	return false;
	return st->size == -1;
}
boolean isFull(stack *st){
	return st->size+1 == st->capacity;
}
boolean push(stack *st, book b){
	if (isFull(st))
		return false;
//	st->size++;
//	st->books[st->size] = b;
	st->books[++st->size] = b;
	return true;
}
book* pop(stack* st){
	if (!isEmpty(st))	
		return &st->books[(st->size)--];
	return NULL;
}
book* peek(stack* st){
	if (!isEmpty(st))	
		return &st->books[st->size];
	return NULL;
}
int stackSize(stack *st){
	return st->size+1;
}
void printMenu(){
	printf("\nStack Operation Demo\n");
	printf("********************\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Peek\n");
	printf("4. Stack size\n");
	printf("5. Exit\n");
	printf("Enter your choice : ");	
}
book getBook(){
	book b;
	printf("Book id    : ");
	scanf("%d", &b.id);
	printf("Book Title : ");
	scanf("%s", b.title);
	printf("Book Price : ");
	scanf("%lf", &b.price);
	return b;
}
void printBook(book b){
	printf("Book id    : %d\n", b.id);
	printf("Book Title : %s\n", b.title);
	printf("Book Price : %.2lf\n", b.price);
}
int main(){
	stack *myStack = NULL;
	int size;
	scanf("%d", &size);
	myStack = createStack(size);
	while(true){
		printMenu();
		int choice;
		scanf("%d", &choice);
		switch(choice){
			case 1:
				if (push(myStack, getBook()))
					printf("Pushed....\n");
				else
					printf("Stack overflow....\n");
				break;
			case 2:{
				book *b = pop(myStack);
				if (b)
					printBook(*b);
				else
					printf("Stack underflow....\n");
				break;
			}
			case 3:{
				book *b = peek(myStack);
				if (b)
					printBook(*b);
				else
					printf("Stack underflow....\n");
				break;
			}
			case 4:
					printf("Stack Size : %d\n", stackSize(myStack));
				break;
			default:
				printf("Thank you so much for being very very interactive in the class!");
				return 0;
		}
	}
	return 0;
}