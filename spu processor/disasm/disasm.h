#ifndef DISASM_H_INCLUDED
#define DISASM_H_INCLUDED


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct filess
{
    FILE *bitecode;
    FILE *disasmcode;
}files_t;

typedef struct buffers
{
    char* comand_disasm;
    char* compare_digit_disasm;
    char* compare_number_disasm;
}buffer_t;

size_t sizeFile(FILE *file);
void disasm(buffer_t* buffer, files_t* files, size_t size);
void disasmcomands(buffer_t* buffer, files_t* files);
void disasmdestroy(buffer_t *buffer);
int disasmcheckfile(files_t* files);
void disasmtranslate(buffer_t* buffer, files_t* files, size_t size);

#endif