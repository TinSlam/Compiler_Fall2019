#include <stdio.h>

int f_1(double a, double b);
int f_2(double a, double b, double c);
int f_3();

int main(){
	double n;
	
	n = f_1(f_2(1, 2, 3), 4);
	
	n = f_3();
	
	printf("%lf\n", n);
	
	return 0;
}

int f_1(double a, double b){
	printf("%lf\n", a);
	printf("%lf\n", b);

	return 0;
}

int f_2(double a, double b, double c){
	printf("%lf\n", c);
	
	return 0;
}

int f_3(){
	printf("%lf\n", 2.3);
	
	return 0;
}