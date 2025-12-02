#include<stdio.h>
#include<stdlib.h>
int main(){
	int *ptr = (int*)malloc(sizeof(int));
	*ptr = 42;
	free(ptr); // memory freed
	//printf("%d",*ptr); // ? dangling pointer
	ptr = NULL; // ? safe practice
	return 0;
}
