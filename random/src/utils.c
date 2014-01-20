#include "utils.h"
#include "random.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MIN_LENGTH 3
#define MAX_LENGTH 10
#define MIN_INT_LENGTH 1
#define MAX_INT_LENGTH 8
#define MIN_FLOAT_LENGTH 6 //min 6
#define MAX_FLOAT_LENGTH 20

char *concat(char *debut, char *milieu, char *fin) {
	char *buffer = (char*) malloc(100*sizeof(char));
	strcat(buffer, debut);
	strcat(buffer, milieu);
	strcat(buffer, fin);

	return buffer;
}

random_type int_to_random_type(unsigned int val) {
	random_type bitfield;

	bitfield.int_val = val && RAND_INT_VAL;
	bitfield.float_val = val && RAND_FLOAT_VAL;
	bitfield.float_hex_val = val && RAND_FLOAT_HEX_VAL;
	bitfield.char_string = val && RAND_CHAR_STRING;
	bitfield.char_int_string = val && RAND_CHAR_INT;
	
	return bitfield;
}

unsigned int sum_bits(random_type bitfield) {	
	return bitfield.int_val + bitfield.float_val + bitfield.float_hex_val
		+ bitfield.char_string + bitfield.char_int_string;
}

char *generate_random(random_type bitfield) {
	float uniform = 1.0f / sum_bits(bitfield);
	float p = rand_float();
	unsigned int i = 1;	

	char *buffer;
	
	if(bitfield.int_val && p <= (i++)*uniform) {
		buffer = random_int(rand_int(MIN_INT_LENGTH, MAX_INT_LENGTH));
	}
	else if(bitfield.float_val && p <= (i++)*uniform) {
		buffer = random_float(rand_int(MIN_FLOAT_LENGTH, MAX_FLOAT_LENGTH));
	}
	else if(bitfield.float_hex_val && p <= (i++)*uniform) {
		buffer = random_float_hex(rand_int(MIN_FLOAT_LENGTH, MAX_FLOAT_LENGTH));
	}
	else if(bitfield.char_string && p <= (i++)*uniform) {
		buffer = random_char(rand_int(MIN_LENGTH, MAX_LENGTH));
	}
	else if(bitfield.char_int_string && p <= (i++)*uniform) {
		buffer = random_char_int(rand_int(MIN_LENGTH, MAX_LENGTH));
	}
	else {
		assert(false);
	}

	return buffer;
}

liste_string* create_liste_string(const char *initial_list[], const size_t size, const size_t complete, unsigned int rand_type) {

	random_type bitfield = int_to_random_type(rand_type);
	
	char **liste = (char**) malloc(sizeof(char*)*(size+complete));
	unsigned int i;

	for (i = 0; i < size; i++) {
		liste[i] = (char *) initial_list[i];
	}

	for (; i < size + complete; i++) {
		liste[i] = generate_random(bitfield);
	}

	liste_string *list = (liste_string*) malloc(sizeof(liste_string));
	list->liste = liste;
	list->size = size + complete;

	return list;
}
