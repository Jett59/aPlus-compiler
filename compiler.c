#include <stdio.h>
#include <stdlib.h>
#include "regexp.h"

int main(int argc, char* argv[])
{
string* regexpTest = regexp("int(string\");\")\n", "*(*)\n");
if(regexpTest == NULL)
{
    fprintf(stderr, "regexpError while computing regexp\n");
    exit(-1);
}
printf("%s\n", *regexpTest);
regexpTest++;
printf("%s\n", *regexpTest);
free(*regexpTest);
regexpTest--;
free(*regexpTest);
free(regexpTest);
}