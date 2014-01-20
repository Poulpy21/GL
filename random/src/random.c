#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>

void rand_init(void) {
	/*srand(time(NULL));*/
	struct timeval *tv = (struct timeval*) malloc(sizeof(struct timeval));
	gettimeofday(tv, NULL);
	srand(tv->tv_usec);
}

int rand_int(int a, int b) {
	return rand() % (b - a)  + a;		
}

float rand_float() {
	return (float)rand()/(float)RAND_MAX;		
}

float rand_float(float a, float b) {
	return (b-a)*rand_float() + a;
}

/*Renvoie une chaine de caractère aléatoire*/
char *random_int(unsigned int longueur)
{
	char *chaine = (char*) malloc((longueur + 1) * sizeof(char));
	for (unsigned int i = 0; i < longueur; i++) { 
		chaine[i] = (char) (rand() % 10 + '0');		
	}

	chaine[longueur] = '\0';

	return chaine;
}



/*Renvoie une string de float alétoire*/
char *random_float(unsigned int longueur) {
	char *chaine = (char*) malloc((longueur + 1) * sizeof(char));
	float p;
	
	for (unsigned int i = 0; i < longueur; i++) { 
		if (i == longueur - 3) {
			p =rand_float();
			if (p<0.5f)
				chaine[i] = 'e';
			else 
				chaine[i] = 'E';
		}
		else if (i == 1) {
			chaine[i] = '.';
		}
		else {
			chaine[i] = (char) (rand() % 10 + '0');		
		}
	}

	chaine[longueur] = '\0';

	return chaine;
}

/*Renvoie une string de float hexadecimal alétoire*/
char *random_float_hex(unsigned int longueur) {
	char *chaine = (char*) malloc((longueur + 1) * sizeof(char));
	float p;
	
	assert(longueur > 6);

	chaine[0] = '0';
	chaine[1] = 'x';
	chaine[2] = '1';
	chaine[3] = '.';

	for (unsigned int i = 4; i < longueur; i++) { 
		if (i == longueur - 3) {
			p = rand_float();
			if(p<0.5f) 
				chaine[i] = 'p';
			else
				chaine[i] = 'P';
		}
		else if(i < longueur - 3) {
			p = rand_float();
			
			if(p < 1.0f/3.0f) {
				chaine[i] = (char) (rand() % 6 + 'A');		
			}
			else if(p < 2.0f/3.0f) {
				chaine[i] = (char) (rand() % 6 + 'a');		
			}
			else {
				chaine[i] = (char) (rand() % 10 + '0');		
			}
		}
		else {
			chaine[i] = (char) (rand() % 9 + '0');		
		}
	}

	chaine[longueur] = '\0';

	return chaine;
}

/*Renvoie une string alétoire*/
char *random_char(unsigned int longueur)
{
	char *chaine = (char*) malloc((longueur + 1) * sizeof(char));
	float p;
	for (unsigned int i = 0; i < longueur; i++) { 
		p = rand_float();
		if (p < 5.0f/11.0f) {
			chaine[i] = (char) (rand() % 26 + 'a');		
		}
		else if (p < 10.0f/11.0f) {
			chaine[i] = (char) (rand() % 26 + 'A');		
		}
		else {
			chaine[i] = '_';
		}
	}

	chaine[longueur] = '\0';

	return chaine;
}



/*Renvoie une string contenant aussi des int alétoire*/
char *random_char_int(unsigned int longueur)
{
	char *chaine = (char*) malloc((longueur + 1) * sizeof(char));
	float p;
	for (unsigned int i = 0; i < longueur; i++) { 
		p = rand_float();
		if (p < 6.0f/20.0f) {
			chaine[i] = (char) (rand() % 26 + 'a');		
		}
		else if (p < 12.0f/20.0f) {
			chaine[i] = (char) (rand() % 26 + 'A');		
		}
		else if (p < 18.0f/20.0f) {
			chaine[i] = (char) (rand() % 10 + '0');		
		}
		else {
			chaine[i] = '_';
		}
	}

	chaine[longueur] = '\0';

	return chaine;
}


