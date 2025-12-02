#include<stdio.h>
void greet(){ printf("Hello!\n");}
int main(){
	void (*funcPtr)() = greet;
	funcPtr();
	return 0 ;
}

