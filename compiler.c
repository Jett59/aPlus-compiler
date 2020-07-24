#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

string* regexp(string input, string pattern)
{
    void* patternAnkor = (void*)pattern;
    register unsigned int stringCount = 0;
while(*pattern != '\0')
{
if(*pattern == '*')
{
    stringCount++;
}
pattern++;
}
pattern = (string)patternAnkor;
string* strings = malloc(stringCount*sizeof(string));
void* stringsAnkor = (void*)strings;
void* inputAnkor = (void*)input;
string buffer = malloc(1024*sizeof(char));
void* bufferAnkor = (void*)buffer;
while(*pattern != '\0')
{
    char currentChar = *pattern;

if(currentChar == '*')
{
    pattern++;
    currentChar = *pattern;
    while(*input != currentChar)
    {
*buffer = *input;
input++;
buffer++;
    }
    input++;
    *buffer = '\0';
    buffer = (string)bufferAnkor;
    int length = strlen(buffer)+1;
    *strings = strcpy(malloc(length*sizeof(char)), buffer);
    strings++;
}
else
    {
        if(*input == *pattern)
        {
            input++;
        }
        else
        {
            fprintf(stderr, "input = %d while pattern = %d\n", *input, *pattern);
                input = (string)inputAnkor;
                pattern = (string)patternAnkor;
                free(buffer);
                return NULL;
        }
    }
    pattern++;
}
strings = (string*)stringsAnkor;
return strings;
}

int main(int argc, char* argv[])
{
string* regexpTest = regexp("int(string)\n", "*(*)\n");
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