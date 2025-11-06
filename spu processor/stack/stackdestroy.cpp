#include "stack.h"

void stackDestroy(stack_t *stk1)
{
    free(stk1->data);
    stk1->data = NULL;
    stk1->capacity = 0;
    stk1->item = 0;
}