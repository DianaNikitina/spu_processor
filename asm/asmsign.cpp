#include "asm.h"

signs_t matrix_sign[] = 
{
    {":", TWO_DOT}, 
    {";", DOT_COMMA}
};

void asm_sign(char sign, files_t* files)
{
    int index = 0, sign_new = 0;
    for (index = 0; index < 2; index++)
    {
        if (strchr(matrix_sign[index].sign_name, sign))
        {
            sign_new = matrix_sign[index].sign_num;
            break;
        }
    }
    fwrite(&sign_new, 1, sizeof(int), files->bytecode);
}