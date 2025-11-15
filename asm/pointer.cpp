#include "asm.h"


int pointer_buf(char* buffer, char** pointer)
{
    int j = 1;
    char *point = buffer;
    pointer[0] = point;
    while ((point = strchr(point, '\n')) != NULL)
    {
        pointer[j] = point + 1;
        *point = '\0';
        point++;
        j++;
    }
    return j;
}