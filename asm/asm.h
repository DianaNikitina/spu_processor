#ifndef ASM_H_INCLUDED
#define ASM_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>

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

typedef enum regs
{
    AX = 0x01, 
    BX = 0x02, 
    CX = 0x03, 
    DX = 0x04, 
    EX = 0x05, 
    FX = 0x06
} regs_t;

typedef enum sign
{
    TWO_DOT = 0x67,
    DOT_COMMA = 0x68
} sign_t;

typedef struct cmd
{
    const char* cmd_name;
    command_t cmd_num;
    size_t cmd_len;
} cmd_t;

typedef struct signs
{
    const char* sign_name;
    sign_t sign_num;
} signs_t;

typedef struct reg
{
    const char* reg_name;
    regs_t reg_num;
    size_t reg_len;
} reg_t;

typedef struct filess
{
    FILE* asmcode;
    FILE* bytecode;
}files_t;


int checkasm(int index);
int asmtranslate(char** pointer, files_t* files, int* count_str);
int asm_comands(char* cmd, files_t* files);
void asm_arg(char* reg, files_t* files);
void asm_sign(char sign, files_t* files);
size_t sizeFile(FILE *file);
int pointer_buf(char* buffer, char** pointer);
#endif

