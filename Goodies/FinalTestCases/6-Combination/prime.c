#include <stdio.h>

int main(){
	double max;
	double num;
	double counter;
	double i;

	counter = 0;
	num = 2;
	max = 10;
	
	while(counter != max){
		double found;
		
		found = 0;
		
		for(i = 2; i <= num - 1; i++){
			double q;
			double r;
			
			q = 0;
			r = 0;
			
			while(q * i < num)
				q = q + 1;
			
			if(num == q * i){
				i = num;
				found = 1;
			}
		}
		
		if(found == 0){
			printf("%lf\n", num);
			counter = counter + 1;
		}
		
		num = num + 1;
	}

	return 0;
}