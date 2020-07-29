typedef char* string;

void seekTo(char chr, string* str)
{
    while(**str != chr)
    {
        if(**str == '\"')
        {
            while(*(++(*str)) != '\"')
            {
                continue;
            }
        }
        (*str)++;
    }
}