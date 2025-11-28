#include<stdio.h>
int main(){
	float celsius ,fahrenheit;
	printf("enter temp  in fahrenheit:");
	scanf("%d",&fahrenheit);
	celsius=(fahrenheit-32)/1.8;
	printf("Temperaturein celsius:%2f",celsius);
	return 0;
	
}
