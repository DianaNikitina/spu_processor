#include "asm.h"

void translate(buffer_t* buffer, files_t* files, size_t size)
{
    int j = 0, k = 0, i = 0;
    files->bitecode = fopen("bitecode.txt", "w");
    while (buffer->comand[i] != '\0')
    {
        if (isalpha(buffer->comand[i]))
        {
            buffer->compare_alpha[j] = buffer->comand[i];
            j++;
        }
        if (isdigit(buffer->comand[i]))
        {
            buffer->compare_digit[k] = buffer->comand[i];
            k++;
        }
        if (buffer->comand[i] == '\n' || i == int(size-1))
        {   
            //printf("%s\n", buffer->compare_alpha);
            if(strcmp(buffer->compare_alpha, "PUSH") == 0)
            {
                fputs("1 ", files->bitecode);
                fputs(buffer->compare_digit, files->bitecode);
                fputs("\n", files->bitecode);
            }
            else
                if(strcmp(buffer->compare_alpha, "POP") == 0)
                {
                    fputs("2\n", files->bitecode);
                }
                else 
                    if(strcmp(buffer->compare_alpha, "ADD") == 0)
                    {
                        fputs("3\n", files->bitecode);
                    } 
                    else 
                        if(strcmp(buffer->compare_alpha, "OUT") == 0)
                        {
                            fputs("0", files->bitecode);
                        }
            j = 0;
            k = 0;
            free(buffer->compare_digit);
            buffer->compare_digit = (char*) calloc(size + 1, sizeof(char));
            free(buffer->compare_alpha);
            buffer->compare_alpha = (char*) calloc(size + 1, sizeof(char));
        }
        
        i++;
    }
}
