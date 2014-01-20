#include "codegen.h"
#include "consts.h"
#include "utils.h"
#include "random.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

unsigned int ptr;
unsigned int indent_level;
char *programm;

const char *types[] = { "void", "boolean", "Object", "int", "float"};
const char *var_names[] = {"a","b","x","y"};
const char *values[] = { "true", "false", "null", "0.0e1", "0x1.0p1", "0"};
const char *funcs[] = { "return", "print", "println", "printx", "printlnx"};
const char *control_struct[] = { "if", "else if", "else", "while"};
const char *special[] = { ";", ",", "(", ")", "{", "}"};

liste_string *types_list ;
liste_string *var_names_list ;
liste_string *values_list ;
liste_string *func_list ;
liste_string *control_struct_list ;
liste_string *special_list ;

char *newProgramm() {

	/*initialization*/
	types_list = create_liste_string(types, 5, 5, RAND_CHAR_STRING);
	var_names_list = create_liste_string(var_names, 4, 4, RAND_CHAR_STRING);
	values_list = create_liste_string(var_names_list, values, 6, 6, RAND_ALL);
	func_list = create_liste_string(funcs, 5, 5, RAND_CHAR_STRING);
	control_struct_list = create_liste_string(control_struct, 4, 4, RAND_CHAR_STRING);
	special_list = create_liste_string(special, 6, 0, RAND_NONE);

	liste_string *listes_string[] = {types_list, values_list, var_names_list, func_list, control_struct_list, special_list };


	unsigned i,j;

	/*create programm*/
	programm = (char*) calloc(MAX_PROGRAMM_SIZE, sizeof(char));
	ptr = 0;
	indent_level = 0;

	beginBlock();

	newDeclVarBlock();

	endBlock();

	/*free memory*/
	for (i = 0; i <6; i++) {
		/*for (j = 0; j < listes_string[i]->size; j++) {*/
		/*free((listes_string[i]->liste)[j]);*/
		/*}*/
		free(listes_string[i]);
	}

	return programm;
}

void newDeclVarBlock() {

	int nbVars = rand_int(MIN_VARS, MAX_VARS);
	float p, q;

	while(nbVars > 0) {
		p = rand_float();
		q = rand_float();

		if(nbVars >= 2 && p <= P_DOUBLE_VAR_DEF) {
			if (q <= P_INITIALIZE_VAR)
				newDoubleVarInitialized();
			else
				newDoubleVarNotInitialized();

			nbVars -= 2;
		}
		else {
			if (q <= P_INITIALIZE_VAR)
				newVarInitialized();
			else
				newVarNotInitialized();

			nbVars --;
		}
	}

}

void newVarInitialized() {
	newType();
	write(" ");
	newVar();
	write(" = ");
	newVal();
	write(";");
	end_line();
}

void newVarNotInitialized() {
	newType();
	write(" ");
	newVar();
	write(";");
	end_line();
}
void newDoubleVarInitialized() {
	newType();
	write(" ");
	newVar();
	write(" = ");
	newVal();
	write(", ");
	newVar();
	write(" = ");
	newVal();
	write(";");
	end_line();
}
void newDoubleVarNotInitialized() {
	newType();
	write(" ");
	newVar();
	write(", ");
	newVar();
	write(";");
	end_line();
}

void newType() {
	write(pick_random(types_list));
}

void newVar() {
	write(pick_random(var_names_list));
}
void newVal() {
	write(pick_random(values_list));
}

void end_line() {
	write("\n");
}

void beginBlock() {
	indent_level++;
	write("{\n");
}

void endBlock(){
	indent_level--;
	write("\n}");
}


void write(char *string) {
	char *src = string;

	while(*src) {
		programm[ptr++] = *src; 

		if (*src++ == '\n') {
			for (unsigned int i = 0; i < indent_level; i++) {
				programm[ptr++] = '\t';
			}
		}
	}
}

char* pick_random(liste_string *liste) {

	float p = rand_float();
	unsigned int index = liste->size;
	
	/*Au cas ou p = 1.0f*/
	while (index == liste->size)
		index = (int) (liste->size * p);
	
	return liste->liste[index];
}
