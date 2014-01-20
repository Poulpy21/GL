#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "random.h"
#include "utils.h"
#include "consts.h"
#include "codegen.h"


void verify_consts();

int main( int argc, const char* argv[] )
{

	verify_consts();
	rand_init();



	/*for (i = 0; i < values_list->size; i++) {*/
	/*printf("%s\n", values_list->liste[i]);*/
	/*}*/

	char *programm = newProgramm();

	printf("DEBUT\n%s\nFIN", programm);


}

