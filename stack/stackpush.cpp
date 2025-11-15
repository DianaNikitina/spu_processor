#include "stack.h"


int stackPush(stack_t* stack, int number)
{
    //stackErr_t error;
    //STACK_OK(stack, error);
    stack->data[stack->item++] = number;
    //STACK_OK(stack, error);
    return 0;
}