
#pragma once

/*
FICHIER RANDOM.H
Librairie de génération de chaines de caractères aléatoiree
*/


/*Initialise la seed*/
void rand_init(void);


int rand_int(int a, int b);
float rand_float();
float rand_float(float a, float b);

/*Renvoie une string de int alétoire*/
char *random_int(unsigned int longueur);
		
/*Renvoie une string de float alétoire*/
char *random_float(unsigned int longueur);

/*Renvoie une string de float hexadécimal alétoire*/
char *random_float_hex(unsigned int longueur);

/*Renvoie une chaine de caractère aléatoire*/
char *random_char(unsigned int longueur);

/*Renvoie une chaine de caractère avec chiffre aléatoire*/
char *random_char_int(unsigned int longueur);
