#include "stack.h"


int stackPop(stack_t *stack)
{
    //stackErr_t error;
    //STACK_OK(stack, error);
    //printf(">%d\n", stack->item);
    int element = stack->data[stack->item-1];
    stack->data[stack->item] = POIZON;
    stack->item--;
    //STACK_OK(stack, error);
    return element;
}