#include "stack.h"

int stackInit(stack_t* stk1, const int capacity)
{
    stk1->data = (int*) calloc(sizeof(int), size_t(capacity));
    stk1->capacity = capacity;
    stackErr_t error = correct;
    STACK_OK(stk1, error);
    if (checkdata(stk1))
    { 
        printf("ERROR allocated data\n");
        return 1;
    }
    printf("CORRECT allocated data\n");
    printf("------------\n\n");
    stk1->item = 0;
    STACK_OK(stk1, error);
    return 0;
}

