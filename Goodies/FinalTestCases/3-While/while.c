#include <stdio.h>

int main(){
	double n, m;
	
	n = 5;
	
	while(n > 0){
		m = n;
		while(m > 0){
			printf("%lf\n", m);
			
			m = m - 1;
		}
		
		n = n - 1;
	}
	
	return 0;
}