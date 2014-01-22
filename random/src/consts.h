#pragma once

#include <assert.h>

#define MAX_THREADS 8
#define PROGRAMM_PER_THREAD 10000

#define MAX_PROGRAMM_SIZE 10000
#define FILE_PER_PASS 1

#define MIN_STRING_LENGTH 3
#define MAX_STRING_LENGTH 10
#define MIN_INT_LENGTH 1
#define MAX_INT_LENGTH 8
#define MIN_FLOAT_LENGTH 7 //min 7
#define MAX_FLOAT_LENGTH 20

#define MIN_VARS 4
#define MAX_VARS 10
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

#define P_DOUBLE_VAR_DEF 0.3
#define P_INITIALIZE_VAR 0.5

void verify_consts();
