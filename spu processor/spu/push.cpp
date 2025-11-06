#include "spu.h"

void push(spu_t* spu)
{
    int number = spu->code[spu->ip++];
    stackPush(&spu->stack, number);
}