//Program to demonstrate singly linked list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node{
    int rollno;
    char name[30]; // 30
    struct Node *next; // 8
}node;

int main(){    
    node *x, *y, *z;
    x =(node *)calloc(1, sizeof(node));
    x->rollno = 120;
    strcpy(x->name, "Ram");
    
    y =(node *)calloc(1,sizeof(node));
    y->rollno = 165;
    strcpy(y->name,"Guna");
    
    z =(node *)calloc(1,sizeof(node));    
    z->rollno = 140;
    strcpy(z->name,"Harshith");
    x->next = y;
    x->next->next = z;
    return 0;
}

// void* malloc(size_t numBytes;
//	malloc( 2 *1024 * 1024 * 1024)