//Program to demonstrate doubly linked list 
#include <stdio.h>
#include <stdlib.h>
//definition of node 
typedef struct Node{
	struct Node *prev;
	char element;
	struct Node *next;
}node;

node* createNode(char data){
//	node* temp =(node*) malloc(sizeof(node));
	node* temp = (node*)calloc(1, sizeof(node));
	temp->element = data;
//	temp->prev = NULL;
//	temp->next = NULL;
	return temp;
}
node* addFirst(node* head, char data){
	node* newNode = createNode(data);
	if (head){
		//list contains node
		newNode->next = head;
		head->prev = newNode;
	}
	head=newNode;
	return head;
}
node* deleteLast(node* head){
	if (head){ // list is not empty
		if (!head->next){ // list contains only one element
			free(head);
			return NULL;
		}
		//list contains more than one element
		node* temp;
		//traversing the pointer to the last but second element
		for (temp = head; temp->next->next; temp= temp->next);
		//deleting the last element
		free(temp->next);
		temp->next = NULL;		
	}
	return head;
}
void printList(node* head){
	if (head){
		printf("\nForward Traversal : [");
		node* temp;
		for (temp=head; temp->next; temp=temp->next)
			printf("'%c',", temp->element);
		printf("'%c']", temp->element);					
		printf("\nBackward Traversal : [");
		for (;temp->prev;temp=temp->prev)
			printf("'%c',", temp->element);
		printf("'%c']", temp->element);								
	}
	else
		printf("\n[]");
}
int main(){
	node* root = NULL;
	root = addFirst(root, 'B');
	root = addFirst(root, 'A');
	root = addFirst(root, 'C');
	printList(root);
	root = deleteLast(root);
	printList(root);
	return 0;
}