#include "spu.h"

void ja(spu_t* spu)
{
    int num1 = stackPop(&spu->stack);
    int num2 = stackPop(&spu->stack);
    if (num1 > num2)
        spu->ip = spu->labels[spu->ip+2];
    else
        spu->ip += 2;
}