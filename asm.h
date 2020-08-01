#ifndef include_asm_header
#define include_asm_header  1
#include <stdio.h>
#ifndef typedef_string
#define typedef_string  1
typedef char* string;
#endif

void compileAsmScript(string input, FILE* output);
#endif