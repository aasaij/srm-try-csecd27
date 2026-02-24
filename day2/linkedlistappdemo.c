//Program to demonstrate singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    char name[30]; // 30
    struct Node *next; // 8
}node;
node* createNode(char str[]){
	node* temp = (node*)malloc(sizeof(node));
	strcpy(temp->name, str);
	temp->next = NULL;	
	return temp;
}
node* addFirst(node* list, char str[]){
	node* newNode = createNode(str);
	newNode->next = list;
	list = newNode;
	return list;
}
node* addLast(node* list, char str[]){
	node* newNode = createNode(str);
	if (list){//list is not empty
		node* temp;
		for (temp = list;temp->next!=NULL;temp=temp->next);
		temp->next = newNode;
	}
	else
		list = newNode;
	return list;
}
node* addAt(node* list, char str[], int pos){
	if (pos ==0 || pos == 1)
		return addFirst(list, str);
	if (pos > 1){
		
	}
}
node* deleteFirst(node* head){
	if (head){
		if (!head->next){
			free(head);
			return NULL;
		}
		node* temp = head;		
		head = temp->next;
		free(temp);
	}
	return head;
}
node* deleteLast(node* head){
	if (head){
		//list is not empty
		if (!head->next){
			//list contains only one node
			free(head);
			return NULL;
		}
		//list contains more than one element
		node *temp;
		for (temp = head; temp->next->next;temp=temp->next);
		free(temp->next);
		temp->next = NULL;
	}
	return head;
}
node* deleteElement(node* head, char str[]){
	if (head){
		if (!strcmp(head->name, str)){
			return deleteFirst(head);
		}		
		node* temp;
		for (temp = head; temp->next &&strcmp(temp->next->name, str)!=0; temp = temp->next);			
		if (temp->next){
			//element found
			//deleting that node
			node* t1 = temp->next;
			temp->next = t1->next;
			free(t1);
		}		
	}
	return head;
}	

void printList(node *list){
	if (list){ // list is not empty
		printf("\n[");		
		node* temp;
		for (temp = list; temp->next;temp=temp->next)
			printf("\"%s\",", temp->name);
		printf("\"%s\"]", temp->name);
	}
	else // list is empty
		printf("\n[]");
}
int main(){    
	node* root = NULL;
	root = addFirst(root, "Ram");
	root = addFirst(root, "Harshith");
	root = addFirst(root, "Guna");
	printList(root);
	root = addLast(root, "Nihal");
	root = addFirst(root, "Sarvesh");
	printList(root);
//	root = deleteFirst(root);
//	printList(root);
//	root = deleteLast(root);
//	printList(root);
	root = deleteElement(root,"Harsh" );
	printList(root);
    return 0;
}

// void* malloc(size_t numBytes;
//	malloc( 2 *1024 * 1024 * 1024)