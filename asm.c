#include <stdio.h>
#include "regexp.h"

typedef char* string;

void compileAsmScript(string input, FILE* output)
{
    string* asmRegexp = regexp(input, "asm*;");
    if(asmRegexp == NULL)
    {
        return;
    }
    fprintf(output, *asmRegexp);
}