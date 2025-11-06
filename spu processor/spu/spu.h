#ifndef SPU_H_INCLUDED
#define SPU_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "stack.h"


typedef struct spu
{
    stack_t stack;
    int* code;
    int ip;
    int* regs;
    int* labels;
} spu_t;

typedef enum command
{
    PUSH = 0x01,
    POP = 0x02,
    ADD = 0x03,     
    SUB = 0x04,     
    MUL = 0x05,     
    DIV = 0x06,
    SQRT = 0x07,

    PUSHR = 0x45,
    POPR = 0x46,

    IN = 0x08,     
    OUT = 0x09,
    HALT = 0x0A,     
    CALL = 0x0B,
    RET = 0x0C,
    
    JMP = 0x86,
    JB = 0x87,
    JBE = 0x88,
    JA = 0x89,
    JAE = 0x8A,
    JE = 0x8B,
    JNE = 0x8C 
} command_t;

typedef enum sign
{
    TWO_DOT = 0x67,
    DOT_COMMA = 0x68
} sign_t;

typedef enum regs
{
    AX = 0x01, 
    BX = 0x02, 
    CX = 0x03, 
    DX = 0x04, 
    EX = 0x05, 
    FX = 0x06
} regs_t;

int readfile(spu_t* spu);
int calc(spu_t* spu, int count_elements);
void add(spu_t* spu);
void div(spu_t* spu);
void in(spu_t* spu);
void ja(spu_t* spu);
void jae(spu_t* spu);
void jb(spu_t* spu);
void jbe(spu_t* spu);
void je(spu_t* spu);
void jne(spu_t* spu);
void mul(spu_t* spu);
void popr(spu_t* spu);
void push(spu_t* spu);
void pushr(spu_t* spu);
void sub(spu_t* spu);
size_t sizeFile(FILE *file);
int checkfile(FILE* file);
void spu_destroy(spu_t *spu);


#endif