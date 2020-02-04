#include <stdio.h>

int main(){
	double first;
	double sec;
	double fibonacci;
	double num;
	int i;
	
	num = 7;
	
	if(num < 3)
		fibonacci = 1;
	else{
		first = 1;
		sec = 1;
		
		for(i = 1; i <= num - 2; i++){
			fibonacci = first + sec;
			
			first = sec;
			sec = fibonacci;
		}
	}
	
	printf("%lf\n", fibonacci);
	
	return 0;
}