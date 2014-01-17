#include <stdio.h>
#include <stdlib.h>
//Calcul de l'arcsinus grâce à son développement limité.
//Nécessite plus de cycles le plus on s'éloigne de 0. Reste quand même plutôt rapide et précis.
float arcsin(float x, int n){
	if(x<-11 || x>1){
		printf("\nValeur incorrecte donnée à arcsin (<1 ou >1)! Aborting.\n");
		exit(EXIT_FAILURE);
	}
	float res = x;
	float sol = 0;
	sol += res;
	for(int j = 3; j<2*n+3; j+=2){
		res*=(j-2)*(j-2)*x*x;
		res/=(j*2*((j-1)/2));
		sol += res;
	}
	return sol;
}

int main(){
	float angle;
	int iter;
	scanf("%f", &angle);
	scanf("%d", &iter);
	printf("asin(%f) = %f \n",angle,arcsin(angle, iter));
	return 0;
}