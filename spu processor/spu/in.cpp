#include "spu.h"

void in(spu_t* spu)
{
    printf("This is option for enter numbers\n");
    scanf("%d", &spu->stack.data[spu->stack.item++]);
}