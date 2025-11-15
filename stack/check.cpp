#include "stack.h"
#include "spu.h"

int checkEmpty(stack_t *stk1)
{
    stk1->capacity = 2*stk1->capacity;
    int* ptr = (int*) realloc (stk1->data, size_t(stk1->capacity));
    if (checkptr(ptr))
    { 
        printf("Ошибка аллоцирования памяти ptr\n");
        return 1;
    }
    printf("Успешное аллоцирование памяти ptr\n");
    stk1->data = ptr;
    return 0;
}

int checkdata(stack_t *stk1)
{
    if (stk1->data == NULL)
        return 1;
    return 0;
}

int checkptr(int *ptr)
{
    if (ptr == NULL)
        return 1;
    return 0;
}

int checkfile(FILE* file)
{
    if (file == NULL)
        return 1;
    return 0;
}

