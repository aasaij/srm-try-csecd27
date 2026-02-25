#include<stdio.h>

int x; // global variable --> data or BSS segment
int total = 100; // data segment
int main(){
    int ab;
    register int data; // cpu memory
    scanf("%d", &data);
	auto int y; // stack segment
	static int s; // BSS segment
	static int testing = 100; // data segment
	printf("%d %d", x, y);
	
	return 0;
}