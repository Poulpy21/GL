#define pi 3.14159265358979323846
#include <stdio.h>

//Epsilon machine atteint à 24 cycles.

struct vect{
	float cos;
	float sin;
};
	
	//n est le nombre d'itérations. Pratique pour les tests de performance.
	//Eventuellement get dans le main.
struct vect coordic(float beta, int n){
	struct vect v;
	float v2; //Copie temporaire de v.cos
	if((beta < -pi/2) || (beta > pi/2)){
		if(beta<0){
			v = coordic(beta+pi,n);
		} else {
			v = coordic(beta-pi,n);
		}
		v.cos = - v.cos;
		v.sin = - v.sin;
		return v;
	}
	
	float angles[28] = { 0.78539816339745 ,  0.46364760900081 ,  
	0.24497866312686 ,  0.12435499454676 ,
	0.06241880999596 ,  0.03123983343027 , 0.01562372862048 ,  0.00781234106010,
	0.00390623013197 ,  0.00195312251648 ,  0.00097656218956,   0.00048828121119,
	0.00024414062015 ,  0.00012207031189 , 0.00006103515617 ,  0.00003051757812,
	0.00001525878906 ,  0.00000762939453  , 0.00000381469727 ,  0.00000190734863,
	0.00000095367432 ,  0.00000047683716  , 0.00000023841858 ,  0.00000011920929,
	0.00000005960464 ,  0.00000002980232   ,0.00000001490116 ,  0.00000000745058};

	float Kvalues[24] = {0.70710678118655,   0.63245553203368,
	0.61357199107790 ,  0.60883391251775,
	0.60764825625617 ,  0.60735177014130 ,  0.60727764409353   ,0.60725911229889,
	0.60725447933256 ,  0.60725332108988 ,  0.60725303152913  , 0.60725295913894,
	0.60725294104140 ,  0.60725293651701 ,  0.60725293538591  , 0.60725293510314,
	0.60725293503245 ,  0.60725293501477 ,  0.60725293501035  , 0.60725293500925,
	0.60725293500897 ,  0.60725293500890 ,  0.60725293500889  , 0.60725293500888};
	
	float Kn;
	if (n<24){
		Kn = Kvalues[n-1];
	} else {
		Kn = Kvalues[23];
	}
	v.cos = 1;
	v.sin = 0;
	float poweroftwo = 1;
	float angle = angles[0];
	float sigma;
	float factor;
	
	for (int j = 0; j<n; j++){
		printf("Debug:%lf\n",beta);
		if (beta<0){
			sigma = -1;
		} else {
			sigma = 1;
		}
		factor = sigma * poweroftwo;
		
		//R = [1, -factor; factor, 1];
		//v = R * v; 
		v2 = v.cos - factor*v.sin;
		v.sin = factor*v.cos + v.sin;
		v.cos = v2;
		
		beta -= sigma*angle;
		poweroftwo/=2;
		
		if(j+1 > 27){
			angle/=2;
		} else {
			angle = angles[j+1];
		}
	}
		
	v.cos*=Kn;
	v.sin*=Kn;
	return v;
		
}

int main(){
	float angle;
	scanf("%f", &angle);
	struct vect v = coordic(angle,23);
	printf("cos(%lf) = %lf \nsin(%lf) = %lf\n\n", angle, v.cos, angle, v.sin);
	return 0;
	
}