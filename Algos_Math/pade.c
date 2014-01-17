#include <stdio.h>
//Fonction compatible java! =)

float PI_4 = 0.78539816339744830675;
float PI_2 = 1.5707963267948966135;
 
float sq2p1 = 2.414213562373095048802;
float sq2m1  = 0.414213562373095048802;
 
float p4  = 16.1536412982230228262;
float p3  = 268.42548195503973794141;
float p2  = 1153.0293515404850115428136;
float p1  = 1780.40631643319697105464587;
float p0  = 896.78597403663861959987488;
 
float q4  = 58.95697050844462222791;
float q3  = 536.265374031215315104235;
float q2  = 1666.7838148816337184521798;
float q1  = 2079.33497444540981287275926;
float q0  = 896.78597403663861962481162;
 
// atan near 0
float atan_near0(float x) {
	float x2,result;
	x2 = x*x;
	float P = ( ( ( (p4*x2 + p3)*x2 + p2) *x2 + p1) *x2 + p0);
	float Q = ( ( ( ( (x2 + q4)*x2 + q3) *x2 + q2)*x2 + q1) *x2 + q0);
	result = x*(P/Q);
	return result;
}
 
// atan in range [0,+inf]
float atan_positive(float x) {
	if(x < sq2m1)
		return atan_near0(x);
	else if(x > sq2p1)
		return PI_2 - atan_near0(1/x);
	else
		return PI_4 + atan_near0((x-1)/(x+1));
}
 
//  atan in range [-inf,+inf]
float arctansmabouboule(float x) {
	if (x<0)
		return -atan_positive(-x);
	else
		return atan_positive(x);
}

int main(){
	float angle;
	scanf("%f", &angle);
	printf("atan(%f) = %f \n",angle,arctansmabouboule(angle));
/*
	//Pour le calcul de performances. 10.000 artan en 14 ms.
	for (float j=-5000; j<5000; j++){
		arctansmabouboule(j/100);
	}*/
	return 0;
	
}