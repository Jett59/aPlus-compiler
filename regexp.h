#ifndef include_regexp
#define include_regexp  0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef typedef_string
#define typedef_string  0
typedef char* string;
#endif

string* regexp(string input, string pattern);
#endif