#include "disasm.h"

//isspace()

void disasmtranslate(buffer_t* buffer, files_t* files, size_t size)
{
    int i = 0, j = 0, k = 0, l = 0;
    files->disasmcode = fopen("disasm/disasmcode.txt", "w");

    if (checkfile(files))
    {
        printf("error open file bitecode\n");
        return 1;
    }
    printf("correct open file bitecode\n");


    while (buffer->comand_disasm[i] != '\0')
    {
        if (buffer->comand_disasm[i] == ' ') 
        {
            l++;
            i++;
        }
        if (l == 0 && isdigit(buffer->comand_disasm[i]))
        {
            buffer->compare_digit_disasm[k] = buffer->comand_disasm[i];
            k++;
        }

        if (l != 0 && isdigit(buffer->comand_disasm[i]))
        {
            buffer->compare_number_disasm[j] = buffer->comand_disasm[i];
            j++;
        }
        //printf("%s\n", compare_digit_disasm);
        if (buffer->comand_disasm[i] == '\n' || i == int(size-1))
        {   
            disasmcomands(buffer, files);


            j = 0;
            k = 0;
            l = 0;


            disasmdestroy(buffer);
            buffer->compare_digit_disasm = (char*) calloc(size + 1, sizeof(char));
            buffer->compare_number_disasm = (char*) calloc(size + 1, sizeof(char));
        }
        
        i++;
    }

    return 0;
}