#include "spu.h"
#define SIZE_REG 6


#define DEFINE_OPERATION(name, operation, check_zero)    \
int name(spu_t* spu)                                     \
{                                                        \
    int num2 = stackPop(&spu->stack);                    \
    int num1 = stackPop(&spu->stack);                    \
    if (check_zero && num2 == 0)                         \
    {                                                    \
        printf("ERROR " #name " on null\n");             \
        return 1;                                        \
    }                                                    \
    stackPush(&spu->stack, abs(num1 operation num2));    \
    return 0;                                            \
}



#define DEFINE_JUMP(namefunc, operationjump)             \
int namefunc(spu_t* spu)                                 \
{                                                        \
    int num1 = stackPop(&spu->stack);                    \
    int num2 = stackPop(&spu->stack);                    \
    if (num1 operationjump num2)                         \
    {                                                    \
        spu->ip = spu->labels[spu->code[spu->ip+1]] + 1; \
    }                                                    \
    else                                                 \
        spu->ip += 2;                                    \
    return 0;                                            \
}

DEFINE_OPERATION(div, /, 1)
DEFINE_OPERATION(add, +, 0)
DEFINE_OPERATION(sub, -, 0)
DEFINE_OPERATION(mul, *, 0)

DEFINE_JUMP(ja, >)
DEFINE_JUMP(jae, >=)
DEFINE_JUMP(jb, <)
DEFINE_JUMP(jbe, <=)
DEFINE_JUMP(je, ==)
DEFINE_JUMP(jne, !=)

#undef DEFINE_OPERATION
#undef DEFINE_JUMP


regs_t reg[] = { AX, BX, CX, DX, EX, FX };

int in(spu_t* spu)
{
    scanf("%d", &spu->stack.data[spu->stack.item++]);
    return 0;
}

int pop(spu_t* spu)
{
    stackPop(&spu->stack);
    return 0;
}

int out(spu_t* spu)
{
    int i = 0;
    for (i = 0; i < spu->stack.item; i++)
    {
        printf("%d ", spu->stack.data[i]);
    }
    printf("\n\n");
    return 0;
}

int halt(spu_t* spu)
{
    return 1;
}

int jump(spu_t* spu)
{
    spu->ip = spu->code[spu->ip+1];
    return 0;
}

int two_dot(spu_t* spu)
{
    //printf("spu ip = %d\n", spu->ip);
    spu->labels[spu->code[spu->ip]] = spu->ip;
    spu->ip++;
    return 0;
}

int popr(spu_t* spu)
{
    for (int index = 0; index < SIZE_REG; index++)
    {
        //printf(">%d\n*%d\n", spu->code[spu->ip], reg[index]);
        if (spu->code[spu->ip] == index + 1)
        {
            spu->regs[index] = stackPop(&spu->stack);
            //printf("%d...%d\n", spu->regs[index], index);
            break;
        }
    }
    spu->ip++;
    return 0;
}

int push(spu_t* spu)
{
    int number = spu->code[spu->ip++];
    stackPush(&spu->stack, number);
    return 0;
}

int pushr(spu_t* spu)
{
    for (int index = 0; index < SIZE_REG; index++)
    {
        //printf("*%d\n>%d\n", spu->code[spu->ip], spu->ip);
        if (spu->code[spu->ip] == index + 1)
        {
            stackPush(&spu->stack, spu->regs[index]);
            break;
        }
    }
    spu->ip++;
    return 0;
}

int call(spu_t* spu)
{
    return 0;
}

int ret(spu_t* spu)
{
    spu->ip = spu->labels[spu->ip_labels];
    return 0;
}