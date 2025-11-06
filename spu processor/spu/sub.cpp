#include "spu.h"

void sub(spu_t* spu)
{
    int num1 = stackPop(&spu->stack);
    int num2 = stackPop(&spu->stack);
    stackPush(&spu->stack, num1-num2);
}