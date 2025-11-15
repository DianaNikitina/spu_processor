#include "stack.h"


int stackDump(stack_t *stk1, stackErr_t error, const char* file, const char* function, int line)
{
    int k = 0;

    printf("StackDump called from >%s >%s: >%d\n\n",file, function, line);

    if (error & not_enough_memory)
    {
        printf("ERR:not_enough_memory\n");
        printf("you need to realloc capacity\n\n");
        stk1->capacity = 1;
        checkEmpty(stk1);
        k++;
    }
    if (error & index_out_of_array)
    {
        printf("ERR:index_out_of_array\n");
        printf("you need to realloc capacity\n\n");
        checkEmpty(stk1);
        k++;
    }
    if (error & poizon_number)
    {
        printf("ERR:poizon_number\n");
        printf("you need to fill the gap\n\n");
        k++;
    }
    printf("адрес начала стека - %p\n", stk1);

    printf("конец указателя (item) - %d\n", stk1->item);

    printf("емкость стека (capacity) - %d\n", stk1->capacity);



   return 0;
}