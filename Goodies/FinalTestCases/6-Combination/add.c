#include <stdio.h>

double add(double a, double b);

int main(){
	double a, b;
	double sum;
	
	a = 33;
	b = 72;
	
	sum = add(a, b);
	
	printf("%lf\n", sum);
	
	return 0;
}

double add(double a, double b){
	if(a == 0)
		return b;

	return add(a - 1, b) + 1;
}