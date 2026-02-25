#include<stdio.h>
extern char *name;
extern int isAlpha(char);
int main(){
    printf("%s", name);
    printf("\n%s", isAlpha('A')?"Yes":"No");
	return 0;
}


data file

char *name = "Aasaithambi Jay";

int isAlpha(char ch){
    return ch >='A' && ch <='Z' || ch >='a' && ch <='z';
}