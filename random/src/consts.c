
#include "consts.h"

void verify_consts() {
	assert(MIN_STRING_LENGTH >= 0);
	assert(MIN_INT_LENGTH >= 0);
	assert(MIN_FLOAT_LENGTH >= 7);

	assert(MAX_STRING_LENGTH - MIN_STRING_LENGTH >= 0);
	assert(MAX_INT_LENGTH - MIN_INT_LENGTH >= 0);
	assert(MAX_FLOAT_LENGTH - MIN_FLOAT_LENGTH >= 0);
	
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
