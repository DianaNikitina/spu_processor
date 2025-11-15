#include "asm.h"

static cmd_t matrix_cmd[] = 
{
    {"PUSHR", PUSHR, 5}, 
    {"PUSH", PUSH, 4}, 
    {"POPR", POPR, 4},
    {"POP", POP, 3}, 
    {"ADD", ADD, 3}, 
    {"SUB", SUB, 3}, 
    {"MUL", MUL, 3}, 
    {"DIV", DIV, 3}, 
    {"SQRT", SQRT, 4}, 
    {"IN", IN, 2},
    {"OUT", OUT, 3},
    {"HALT", HALT, 4},
    {"CALL", CALL, 4},
    {"JBE", JBE, 3},
    {"JB", JB, 2}, 
    {"JAE", JAE, 3},
    {"JA", JA, 2},
    {"JE", JE, 2},
    {"JNE", JNE, 3},
    {"RET", RET, 3}
};

int asm_comands(char* cmd, files_t* files)
{
    assert(files);
    int index = 0, comand = 0, count = 0;

    for (index = 0; index < 20; index++)
    {
        if (strcmp(cmd, matrix_cmd[index].cmd_name) == 0)
        {
            comand = matrix_cmd[index].cmd_num;
            count++;
            break;
        }
        //printf("ok");
    }
    if (count == 0)
    {
        printf("ERROR invalid command\n");
        return 1;
    }
    fwrite(&comand, 1, sizeof(int), files->bytecode);
    return 0;
}