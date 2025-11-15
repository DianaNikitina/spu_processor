#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define POIZON 13;
#define STACK_OK(stk1, error) error = stackVerify(stk1); if (error) stackDump(stk1, error,  __FILE__, __FUNCTION__, __LINE__);

//typedef int type;

enum stackErr_t 
{
    correct = 0,
    index_out_of_array = 10,
    not_enough_memory = 100,
    poizon_number = 1000
};

typedef struct stack 
{
    int* data;
    int item;
    int capacity; 
} stack_t;

int stackInit(stack_t* stk1, const int capacity);

int stackPush(stack_t *stk1, int number);

int checkEmpty(stack_t *stk);

int checkdata(stack_t *stk1);

int checkptr(int *ptr);

stackErr_t stackVerify(stack_t *stk1);

int stackPop(stack_t *stk1);

int stackDump(stack_t *stk1, stackErr_t error, const char* file, const char* function, int line);

void stackDestroy(stack_t *stk1);

void out_stack(stack_t* stack);


#endif

