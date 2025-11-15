#include "disasm.h"


void disasmcomands(buffer_t* buffer, files_t* files)
{

    if(strcmp(buffer->compare_digit_disasm, "1") == 0)
    {
        fputs("PUSH ", files->disasmcode);
        fputs(buffer->compare_number_disasm, files->disasmcode);
        fputs("\n", files->disasmcode);
    }
    else if(strcmp(buffer->compare_digit_disasm, "2") == 0)
        {
            fputs("POP\n", files->disasmcode);
        }
    else if(strcmp(buffer->compare_digit_disasm, "3") == 0)
        {
            fputs("ADD\n", files->disasmcode);
        } 
    else if(strcmp(buffer->compare_digit_disasm, "0") == 0)
        {
            fputs("OUT", files->disasmcode);
        }
}
