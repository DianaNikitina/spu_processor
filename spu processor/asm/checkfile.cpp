#include "asm.h"

int checkasm(int index)
{
    if (index == 0)
    {
        printf("ERROR. check your assembler\n");
        return 1;
    }
    return 0;
}