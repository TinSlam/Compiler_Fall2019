#include <stdio.h>

int main(){
	double num;
	double a, b, c, d;
	
	num = 3;
	a = 1;
	b = 2;
	c = 3;
	d = 4;
	
	num = -num * num - (1 / a + 1 / b + 1 / c) * d;
	
	printf("%lf\n", num);
	
	return 0;
}