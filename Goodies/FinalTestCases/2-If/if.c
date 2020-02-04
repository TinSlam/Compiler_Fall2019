#include <stdio.h>

int main(){
	double n;
	
	n = 24;
	
	if(n >= 24 && (0 || 1)){
		if(n == 32){
			n = 3;
		}else if(n == 44){
			n = 4;
		}else if(n == 60){
			n = 5;
		}else n = 6;
	}else{
		n = 0;
	}
	
	printf("%lf\n", n);
	
	return 0;
}