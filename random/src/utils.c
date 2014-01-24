#include "utils.h"
#include "random.h"
#include "utils.h"
#include "consts.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

char *concat(char *debut, char *milieu, char *fin) {
	char *buffer = (char*) malloc(100*sizeof(char));
	strcat(buffer, debut);
	strcat(buffer, milieu);
	strcat(buffer, fin);

	return buffer;
}

random_type int_to_random_type(unsigned int val) {
	random_type bitfield;

	bitfield.int_val = val & RAND_INT_VAL ? 1 : 0;
	bitfield.float_val = val & RAND_FLOAT_VAL ? 1 : 0;
	bitfield.float_hex_val = val & RAND_FLOAT_HEX_VAL ? 1 : 0;
	bitfield.char_string = val & RAND_CHAR_STRING ? 1 : 0;
	bitfield.char_int_string = val & RAND_CHAR_INT ? 1 : 0;

	/*printf("\nVAL : %u \t\tBITFIELD : %u\t%u\t%u\t%u\t%u", val, bitfield.int_val, bitfield.float_val, bitfield.float_hex_val, bitfield.char_string, bitfield.char_int_string);*/

	return bitfield;
}

unsigned int sum_bits(random_type bitfield) {	
	return bitfield.int_val + bitfield.float_val + bitfield.float_hex_val + bitfield.char_string + bitfield.char_int_string;
}

char *generate_random(random_type bitfield) {

	int sumBits = sum_bits(bitfield);

	assert(sumBits != 0);

	float uniform = 1.0f / sumBits;
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
		buffer = random_char(rand_int(MIN_STRING_LENGTH, MAX_STRING_LENGTH));
	}
	else if(bitfield.char_int_string && p <= (i++)*uniform) {
		buffer = random_char_int(rand_int(MIN_STRING_LENGTH, MAX_STRING_LENGTH));
	}
	else {
		assert(false);
	}

	return buffer;
}

liste_string* create_liste_string(const char *initial_list[], const size_t size, const size_t complete, unsigned int rand_type) {

	assert((rand_type != 0) ^ (complete == 0));
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

liste_string* create_liste_string(liste_string *include_list, const char *initial_list[], const size_t size, const size_t complete, unsigned int rand_type) {

	assert((rand_type != 0) ^ (complete == 0));
	random_type bitfield = int_to_random_type(rand_type);

	char **liste = (char**) malloc(sizeof(char*)*(include_list->size + size + complete));
	unsigned int i;

	for (i = 0; i < include_list->size; i++) {
		liste[i] = (char *) include_list->liste[i];
	}

	for (; i < include_list->size + size; i++) {
		liste[i] = (char *) initial_list[i-include_list->size];
	}

	for (; i < include_list->size + size + complete; i++) {
		liste[i] = generate_random(bitfield);
	}

	liste_string *list = (liste_string*) malloc(sizeof(liste_string));
	list->liste = liste;
	list->size = include_list->size + size + complete;

	return list;
}

/*old good 70s cp style*/
int cp(const char *to, const char *from)
{
	int fd_to, fd_from;
	char buf[4096];
	ssize_t nread;
	int saved_errno;

	fd_from = open(from, O_RDONLY);
	if (fd_from < 0)
		return -1;

	fd_to = open(to, O_WRONLY | O_CREAT | O_EXCL, 0666);
	if (fd_to < 0)
		goto out_error;

	while (nread = read(fd_from, buf, sizeof buf), nread > 0)
	{
		char *out_ptr = buf;
		ssize_t nwritten;

		do {
			nwritten = write(fd_to, out_ptr, nread);

			if (nwritten >= 0)
			{
				nread -= nwritten;
				out_ptr += nwritten;
			}
			else if (errno != EINTR)
			{
				goto out_error;
			}
		} while (nread > 0);
	}

	if (nread == 0)
	{
		if (close(fd_to) < 0)
		{
			fd_to = -1;
			goto out_error;
		}
		close(fd_from);

		/* Success! */
		return 0;
	}

out_error:
	saved_errno = errno;

	close(fd_from);
	if (fd_to >= 0)
		close(fd_to);

	errno = saved_errno;
	return -1;
}
