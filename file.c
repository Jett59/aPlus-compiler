#include <stdio.h>
#include <stdlib.h>

typedef char* string;

string readFile(string name)
{
    FILE* file;
 file = fopen(name, "r");
 if(file == NULL)
 {
     fprintf(stderr, "error while openning file %s\n", name);
     exit(-1);
 }
 unsigned int fileLength = 0;
 while(getc(file) != EOF)
 {
     fileLength++;
 }
 rewind(file);
 string content = malloc((fileLength+1)*sizeof(char));
 void* contentAnkor = (void*)content;
 while((*content = getc(file)) != EOF)
 {
     content++;
 }
 *content = '\0';
 content = (string)contentAnkor;
 fclose(file);
 return content;
}