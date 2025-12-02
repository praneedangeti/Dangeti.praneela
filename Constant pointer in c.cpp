#include<stdio.h>
#include<stdlib.h>
int main(){
int x = 10, y = 20;
int *const ptr = &x; // constant pointer
*ptr = 15; //
// ptr = &y; // not allowed
return 0;
}
