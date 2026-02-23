#include<stdio.h>

int main(){
	int x=10;
	float f  = 0.5;
	char c = 'A';
	void *ptr;
	ptr = &x;
	printf("%d\n", *(int*)ptr);
	ptr = &f;
	printf("%.2f\n", *(float*)ptr);
	ptr = &c;
	printf("%c\n", *(char*)ptr);	
	return 0;
}