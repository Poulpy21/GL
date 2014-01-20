#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "random.h"
#include "utils.h"

#define FILE_PER_PASS 1

#define MIN_VARS 0
#define MAX_VARS 5
#define MIN_FUNCS 0
#define MAX_FUNCS 5
#define MIN_ARGS 0
#define MAX_ARGS 1
#define MAX_CONTROL_STRUCT 1
#define MIN_CONTROL_STRUCT 1
#define MIN_INSTRUCTIONS_PER_BLOCK 1
#define MAX_INSTRUCTIONS_PER_BLOCK 1
#define MIN_DEPTH 1
#define MAX_DEPTH 1

char *newProgramm();

char *newVarDeclBlock();
char *newVarInitialized();
char *newVarNotInitialized();
char *newDoubleVarInitialized();
char *newDoubleVarNotInitialized();

char *newInstructionsBlock();
char *newControlStruct();
char *newInstruction();
char *newFuncCall();

char *newParenthesis(char *inside);
char *newAccolades(char *inside);
char *ne

char *newBlock(char *programm);

void verify_consts();

int main( int argc, const char* argv[] )
{

	verify_consts();
	rand_init();

	const char *types[] = { "void", "boolean", "Object", "int", "float"};
	const char *values[] = { "true", "false", "null", "0.0e1", "0x1.0p1", "0"};
	const char *funcs[] = { "return", "print", "println", "printx", "printlnx", "main"};
	const char *control_struct[] = { "if", "else if", "else", "while"};
	const char *special[] = { ";", ",", "(", ")", "{", "}"};

	unsigned int i;
	liste_string *types_list ;
	liste_string *values_list ;
	liste_string *func_list ;
	liste_string *control_struct_list ;
	liste_string *special_list ;

	do {
		types_list = create_liste_string(types, 5, 5, RAND_CHAR_STRING);
		values_list = create_liste_string(values, 6, 6, RAND_ALL);
		func_list = create_liste_string(funcs, 6, 6, RAND_CHAR_STRING);
		control_struct_list = create_liste_string(control_struct, 4, 4, RAND_CHAR_STRING);
		special_list = create_liste_string(special, 6, 0, RAND_NONE);

		liste_string *listes_string[] = {types_list, values_list, func_list, control_struct_list, special_list };

		for (i = 0; i < values_list->size; i++) {
			printf(values_list->liste[i]);
			printf("\n");
		}

		for (i = 0; i <5; i++) {
			free(listes_string[i]);
		}

	} while (false);
}

void verify_consts() {
	assert(MIN_VARS >= 0);
	assert(MIN_FUNCS >= 0);
	assert(MIN_ARGS >= 0);
	assert(MIN_CONTROL_STRUCT >= 0);
	assert(MIN_INSTRUCTIONS_PER_BLOCK >= 0);
	assert(MIN_DEPTH >= 0);
	assert(MAX_VARS - MIN_VARS >= 0);
	assert(MAX_FUNCS - MIN_FUNCS >= 0);
	assert(MAX_ARGS - MIN_ARGS >= 0);
	assert(MAX_CONTROL_STRUCT - MIN_CONTROL_STRUCT >= 0);
	assert(MAX_INSTRUCTIONS_PER_BLOCK - MIN_INSTRUCTIONS_PER_BLOCK >= 0);
	assert(MAX_DEPTH - MIN_DEPTH >= 0);
}
