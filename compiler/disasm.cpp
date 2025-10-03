#include "asm.h"

void disasm(buffer_t* buffer, files_t* files, size_t size)
{
    int i = 0, j = 0, k = 0, l = 0;
    files->disasmcode = fopen("disasmcode.txt", "w");
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
            //printf("%s\n", buffer->compare_digit_disasm);
            if(strcmp(buffer->compare_digit_disasm, "1") == 0)
            {
                fputs("PUSH ", files->disasmcode);
                fputs(buffer->compare_number_disasm, files->disasmcode);
                fputs("\n", files->disasmcode);
            }
            else
                if(strcmp(buffer->compare_digit_disasm, "2") == 0)
                {
                    fputs("POP\n", files->disasmcode);
                }
                else 
                    if(strcmp(buffer->compare_digit_disasm, "3") == 0)
                    {
                        fputs("ADD\n", files->disasmcode);
                    } 
                    else 
                        if(strcmp(buffer->compare_digit_disasm, "0") == 0)
                        {
                            fputs("OUT", files->disasmcode);
                        }
            j = 0;
            k = 0;
            l = 0;
            free(buffer->compare_digit_disasm);
            buffer->compare_digit_disasm = (char*) calloc(size + 1, sizeof(char));
            free(buffer->compare_number_disasm);
            buffer->compare_number_disasm = (char*) calloc(size + 1, sizeof(char));
        }
        
        i++;
    }
}