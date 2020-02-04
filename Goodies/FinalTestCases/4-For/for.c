#include <stdio.h>

int main(){
	double n;
	int i;
	int counter;
	
	n = 0;
	
	for(counter = 1; counter <= 3; counter++)
		for(i = 3 - 2; i <= 2 * 9; i += 2)
			n = n + i * 3;
		
	printf("%lf\n", n);
	
	return 0;
}