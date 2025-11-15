#include "stack.h"

void out_stack(spu_t* spu)
{
    int i = 0;
    printf("stack_data\n");
    for (i = 0; i < spu->stack.item; i++)
    {
        printf("%d ", spu->stack.data[i]);
    }
    printf("\n\n");
}