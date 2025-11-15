#include "spu.h"

int find_label(spu_t* spu, int label)
{
    for (int i = 2; i < 29; i++) 
    {
        if (spu->code[i] == label && spu->code[i-2] != CALL)
            return i;
    }
    return -1;
}