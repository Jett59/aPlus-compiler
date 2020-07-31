#include <stdlib.h>
#include <string.h>
#include "regexp.h"

void compileFunction(string input, FILE* output)
{
    string* functionRegexp = regexp(input, "*(*);");
    if(functionRegexp == NULL)
    {
        return;
    }
    printf("%s\n", *functionRegexp);
    functionRegexp++;
    printf("%s\n", *functionRegexp);
    fflush(stdout);
    fprintf(output, "\n\t mov ");
    void* paramsAnkor = (void*)*functionRegexp;
    while(**functionRegexp != 0)
    {
        if(**functionRegexp == ',')
        {
            fprintf(output, "\n\t mov ");
        }
        else
        {
                if(**functionRegexp == '-')
                {
                    putc(',', output);
                }
                else
                {
                    putc(**functionRegexp, output);
                }
            }
        (*functionRegexp)++;
    }
    *functionRegexp = (string)paramsAnkor;
    free(*functionRegexp);
    functionRegexp--;
    fprintf(output, "\n\t call %s\n", *functionRegexp);
    free(*functionRegexp);
    free(functionRegexp);
}