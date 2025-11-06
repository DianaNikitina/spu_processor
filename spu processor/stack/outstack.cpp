#include "stack.h"

void out_stack(stack_t* stack)
{
    int i = 0;
    printf("stack_data\n");
    for (i = 0; i < stack->item; i++)
    {
        printf("%d ", stack->data[i]);
    }
    printf("\n\n");
}