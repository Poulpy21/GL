
#pragma once

#include "utils.h"

char *newProgramm();

void newDeclVarBlock();
void newVarInitialized();
void newVarNotInitialized();
void newDoubleVarInitialized();
void newDoubleVarNotInitialized();

void newType(); 
void newVar();
void newVal();

void newInstructionsBlock();
void newControlStruct();
void newInstruction();
void newFuncCall();

void end_line();
void beginBlock();
void endBlock();
void beginParenthesis();
void endParenthesis();

void write(char *string);
char* pick_random(liste_string *liste);
