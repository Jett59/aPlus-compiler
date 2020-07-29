#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "string.h"
#include "function.h"

int main(int argc, char* argv[])
{
    string code = readFile(argv[1]);
    void* codeAnkor = (void*)code;
string compiledFunction = compileFunction(code);
if(compiledFunction == NULL)
{
    fprintf(stderr, "error while compiling function\n");
    exit(-1);
}
printf("%s\n", compiledFunction);
free(compiledFunction);
seekTo(';', &code);
code++;
compiledFunction = compileFunction(code);
if(compiledFunction == NULL)
{
    fprintf(stderr, "error while compiling function\n");
    exit(-1);
}
printf("%s\n", compiledFunction);
free(compiledFunction);
code = (string)codeAnkor;
free(code);
}