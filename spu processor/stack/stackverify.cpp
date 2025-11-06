#include "stack.h"

stackErr_t stackVerify(stack_t *stk1)
{
    //if (stk1->item == stk1->capacity+1)
        //return index_out_of_array;
    if (stk1->capacity < 1)
        return not_enough_memory;
    if(stk1->data[stk1->item] == 13)
        return poizon_number;
    return correct;
}