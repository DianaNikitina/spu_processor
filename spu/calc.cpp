#include "spu.h"

func_t opTable[] = 
{
    {ADD, add, "add two last elements in stack\n"},
    {SUB, sub, "subtraction two last elements in stack\n"},
    {MUL, mul, "multiplication two elements in stack\n"},
    {DIV, div, "division two elements in stack\n"},
    {PUSH, push, "push element in stack\n"},
    {POP, pop, "pop element out of stack\n"},
    {IN, in, "enter element in stack\n"},
    {OUT, out, "out in consol element in stack\n"},
    {PUSHR, pushr, "push the last element of stack in register\n"},
    {POPR, popr, "pop element out of stack and push in register\n"},
    {HALT, halt, "stop\n"},
    {JMP, jump, "jump on index\n"},
    {JA, ja, "jump on index if >\n"},
    {JAE, jae, "jump on index if >=\n"},
    {JB, jb, "jump on index if <\n"},
    {JBE, jbe, "jump on index if <=\n"},
    {JNE, jne, "jump on index if !=\n"},
    {JE, je, "jump on index if ==\n"},
    {TWO_DOT, two_dot, "sign metka!\n"},
    {CALL, call, "func\n"},
    {RET, ret, "end func\n"}
};


int calc(spu_t* spu, int count_elements)
{
    int capacity = 100;

    printf("construct stack\n");
    printf("------------\n\n");
    stackInit(&spu->stack, capacity);

    //printf("%d\n", count_elements);

    int table_size = sizeof(opTable)/sizeof(opTable[0]);
    
    /*find_labels(spu, count_elements);
    printf("correct find labels\n");
    printf("------------\n\n");*/
    
    printf("do comands\n");
    printf("------------\n\n");
    while (spu->ip < count_elements)
    {
        //printf("cmd = %d\n", spu->code[spu->ip]);
        int cmd = spu->code[spu->ip++];

        for (int i = 0; i < table_size; i++)
        {
            if (cmd == opTable[i].cmd_id)
            {
                printf("%s", opTable[i].description);
                opTable[i].func(spu);
            }
        }
    }
    return 0;
}