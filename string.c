typedef char* string;

void seekTo(char chr, string* str)
{
    while(**str != chr && **str != 0)
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