//Program to add two numbers
//
//Input 1
//	10 20
//output 1
//	30
//Input 2:
//	10.5 20.5
//
//Output 2
//	31
//Input 3:
//	10.5 20
//	
//Output 2
//	30.50
#include <stdio.h>

int main(){
	double x, y, sum;
	scanf("%lf %lf", &x,&y);
	sum = x + y;
//	printf("%g", sum);
	if ( sum == (long long int) sum)
		printf("%lld", (long long int)sum);
	else
		printf("%.2lf", sum);
	return 00;	
}