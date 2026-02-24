#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; 
    struct Node *next; 
}node;

node* createNode(int element){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = element;
	temp->next = NULL;	
	return temp;
}
node* addFirst(node* tail, int element){
	node* newNode = createNode(element);
	if (tail){
		newNode->next = tail->next;
		tail->next = newNode;
	}
	else{
		newNode->next = newNode;
		tail=newNode;
	}
	return tail;
}
node* addLast(node* tail, int data){
	node* newNode = createNode(data);
	if (!tail){
		newNode->next = newNode;
		return newNode;
	}
	newNode->next = tail->next;
	tail->next = newNode;
	tail = newNode;
	return tail;		
}
node* deleteFirst(node* tail){
	if (tail){
		if (tail->next == tail){
			free(tail);
			return NULL;
		}
		node* temp = tail->next;
		tail->next = temp->next;
		free(temp);
	}
	return tail;
}
void printList(node* tail){
	if (tail){
		printf("\n[");
		for (node* temp = tail->next; temp!=tail; temp = temp->next)
			printf("%d,", temp->data);
		printf("%d]", tail->data);
	}
	else
		printf("\n[]");
}
int main(){
	node *root = NULL;
	root = addFirst(root, 10);
	root = addFirst(root, 110);
	root = addFirst(root, 1110);
	printList(root);
	root = addLast(root, 1);
	printList(root);
	root = deleteFirst(root);
	printList(root);
	return 0;
}
