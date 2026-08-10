#include<stdio.h>
int main(){
	float b,h,area;
	printf("enter base and height (in cm)");
	scanf("%f %f",&b,&h);
	area = (0.5 *b *h);
	printf("area of triangle is %2f",area);
	return 0;
}

