#include "asm.h"

reg_t matrix_reg[] = 
{
    {"AX", AX, 2}, 
    {"BX", BX, 2}, 
    {"CX", CX, 2}, 
    {"DX", DX, 2}, 
    {"EX", EX, 2}, 
    {"FX", FX, 2}
};
void asm_arg(char* reg, files_t* files)
{
    int index = 0, registr = 0;
    for (index = 0; index < 6; index++)
    {
        if (strcmp(reg, matrix_reg[index].reg_name) == 0)
        {
            registr = matrix_reg[index].reg_num;
            break;
        }
    }

    fwrite(&registr, 1, sizeof(int), files->bytecode);

}