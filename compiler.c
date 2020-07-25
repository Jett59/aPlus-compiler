#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main(int argc, char* argv[])
{
string compiledFunction = compileFunction("printf();");
if(compiledFunction == NULL)
{
    fprintf(stderr, "error while compiling function\n");
    exit(-1);
}
printf("%s\n", compiledFunction);
}