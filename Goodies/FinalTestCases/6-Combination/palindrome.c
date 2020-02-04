#include <stdio.h>

double getPalindrome(double num);
double getUnit(double num);
double len(double num);

int main(){
	double num;
	
	num = 123456789;
	
	num = getPalindrome(num);
	
	printf("%lf\n", num);
	
	return 0;
}

double getPalindrome(double num){
	double pal;
	pal = 0;
	
	while(num >= 1){
		double units = getUnit(num);
		pal = pal * 10 + units;
		num = (num - units) / 10;
	}
	
	return pal;
}

double getUnit(double num){
	double q;
	double r;
	
	q = 0;
	r = 0;
	
	while(q * 10 < num)
		q = q + 1;
	
	if(num == q * 10)
		return 0;
	
	q = q - 1;
	
	return num - q * 10;
}