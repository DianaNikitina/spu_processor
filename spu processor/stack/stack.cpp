#include "stack.h"


int main()
{
    stack_t stack = {};
    int i = 0, capacity = 10;

    printf("Инициализация стека\n");
    stackInit(&stack, capacity);

    for(i = 0; i < stack.item; i++)
    {
        printf("[%d] = %d\n", i+1, stack.data[i]);
    }

    printf("Освобождаем занятую память\n");
    stackDestroy(&stack);
}
