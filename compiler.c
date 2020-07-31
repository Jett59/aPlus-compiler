#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "string.h"
#include "function.h"

int main(int argc, char* argv[])
{
    FILE* output = fopen("output.asm\0", "w+");
    if(output == NULL)
    {
        printf("error while openning output.asm\n");
        exit(0);
    }
    string code = readFile(argv[1]);
    void* codeAnkor = (void*)code;
    printf("started compilation\n");
    while(*code != 0)
    {
        while(*code == '\n')
        {
            printf("skipping \\n char\n");
            code++;
        }
        printf("compiling function!\n");
        compileFunction(code, output);
        printf("compiled function!\n");
        seekTo(';', &code);
        code++;
    }
    fclose(output);
}