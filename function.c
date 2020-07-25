#include <stdlib.h>
#include <string.h>
#include "regexp.h"

string compileFunction(string input)
{
    string* functionRegexp = regexp(input, "*(*);");
    if(functionRegexp == NULL)
    {
        return NULL;
    }
    string result = malloc((strlen("call ")+strlen(*functionRegexp)+1)*sizeof(char));
    strcpy(result, "call ");
    strcat(result, *functionRegexp);
    return result;
}