#ifndef ASM_H_INCLUDED
#define ASM_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct filess
{
    FILE *asmcode;
    FILE *bitecode;
    FILE *disasmcode;
}files_t;

typedef struct buffers
{
    char* comand;
    char* comand_disasm;
    char* compare_alpha;
    char* compare_digit_disasm;
    char* compare_digit;
    char* compare_number_disasm;
}buffer_t;

size_t sizeFile(FILE *file);
void disasm(buffer_t* buffer, files_t* files, size_t size);
void checkasm(files_t* files);
void translate(buffer_t* buffer, files_t* files, size_t size);

#endif

