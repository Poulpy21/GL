#pragma once
#include <stddef.h>

#define RAND_NONE 0x00
#define RAND_INT_VAL 0x01
#define RAND_FLOAT_VAL 0x02
#define RAND_FLOAT_HEX_VAL 0x04
#define RAND_CHAR_STRING 0x08
#define RAND_CHAR_INT 0x10
#define RAND_FLOAT_ALL (RAND_FLOAT_VAL + RAND_FLOAT_HEX_VAL)
#define RAND_VAL_ALL (RAND_FLOAT_ALL + RAND_INT_VAL)
#define RAND_CHAR_ALL (RAND_CHAR_STRING + RAND_CHAR_INT)
#define RAND_ALL (RAND_VAL_ALL + RAND_CHAR_ALL)


typedef struct liste_string_s {
	char **liste;
	size_t size;
} liste_string;

typedef struct random_type_s {
	unsigned int int_val : 1;
	unsigned int float_val : 1;
	unsigned int float_hex_val : 1;
	unsigned int char_string : 1;
	unsigned int char_int_string : 1;
	unsigned int : 3 ;
} random_type;

char *concat(char *debut, char *milieu, char *fin);

random_type int_to_random_type(unsigned int val);

unsigned int sum_bits(random_type bitfield);	

char *generate_random(random_type bitfield);

liste_string* create_liste_string(const char *initial_liste[], const size_t size, const size_t complete, unsigned int rand_type);
liste_string* create_liste_string(liste_string *include_list, const char *initial_liste[], const size_t size, const size_t complete, unsigned int rand_type);

int cp(const char *to, const char *from);
