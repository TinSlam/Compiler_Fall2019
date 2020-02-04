#include <stdio.h>

int main(){
	double num1, num2, num3, num4, num5;
	double average;
	double variance;
	double error1, error2, error3, error4, error5;
	
	num1 = 1;
	num2 = 2;
	num3 = 3;
	num4 = 4;
	num5 = 5;
	
	average = (num1 + num2 + num3 + num4 + num5) / 5;
	
	error1 = num1 - average;
	error2 = num2 - average;
	error3 = num3 - average;
	error4 = num4 - average;
	error5 = num5 - average;
	
	variance = (error1 * error1 + error2 * error2 + error3 * error3 + error4 * error4 + error5 * error5) / 5;
	
	printf("%lf\n", variance);
	
	return 0;
}