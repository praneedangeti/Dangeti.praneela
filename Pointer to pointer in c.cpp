#include<stdio.h>
void greet(){ printf("Hello!\n");}
int main(){
	int x = 5;
	int *p = &x;
	int **pp = &p;
	printf("%d\n", **pp); // 5
	return 0;
	
}
