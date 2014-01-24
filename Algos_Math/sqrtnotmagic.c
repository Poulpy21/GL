#include <stdio.h>

double sqrt9( const double x)
{ 
	double n = x / 2.0;
	double a = 0.0; 
	while(n != a)  
	{ 
		a = n;
		n = (n + x/n) / 2.0; 
	}
	return n;
 } 
 
 int main(){
	float num;
	scanf("%f", &num);
	printf("sqrt(%f) = %f \n",num, sqrt9(num));
	/*for (float j = 0; j<100000; j++){
		sqrt9(j);
	}*/
	return 0;
}