#include "asm.h"

int asmtranslate(char** pointer, files_t* files, int* count_str)
{
    assert(pointer);
    int i = 0, index = 0;
    char cmd[10];
    char reg[3];
    int number = 0;
    char sign = 0;
    files->bytecode = fopen("bytecode.txt", "wb");
    if (files->bytecode == NULL)
    {
        printf("ERROR open file bytecode\n");
        return 1;
    }
    printf("CORRECT open file bytecode\n");
    printf("------------\n\n");

    int cnt_str = *count_str;

    for (i = 0; i < cnt_str; i++)
    {
        if (sscanf(pointer[i], "%c%d", &sign, &number) == 2)
        {
            asm_sign(sign, files);
            fwrite(&number, 1, sizeof(int), files->bytecode);
            (*count_str)++;
        }
        else if (sscanf(pointer[i], "%s :%d \n%n",cmd, &number, &index) == 2)
        {
            asm_comands(cmd, files);
            int sign_new = TWO_DOT;
            fwrite(&sign_new, 1, sizeof(int), files->bytecode);
            fwrite(&number, 1, sizeof(int), files->bytecode);
            (*count_str)+=2;
        }
        else if (sscanf(pointer[i], "%s %d \n%n",cmd, &number, &index) == 2)
        {
            asm_comands(cmd, files);
            fwrite(&number, 1, sizeof(int), files->bytecode);
            (*count_str)++;
        }
        else 
        {
            if (sscanf(pointer[i], "%s %s %n",cmd, reg, &index) == 2)
            {
                asm_comands(cmd, files);
                asm_arg(reg, files);
                (*count_str)++;
            }
            else
            {
                asm_comands(cmd, files);
            }
        }
             
    }
    return 0;
}