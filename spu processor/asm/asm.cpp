#include "asm.h"

int main()
{
    //int i = 0;
    size_t size = 0;
    files_t files = {};
    files.asmcode = fopen("calc.txt", "r");
    if (files.asmcode == NULL)
    {
        printf("ERROR open file\n");
        return 1;
    }
    printf("CORRECT open file\n");
    printf("------------\n\n");

    size = sizeFile(files.asmcode);
    printf("CORRECT size\n");
    printf("------------\n\n");

    char* buffer = (char*) calloc(size + 1, sizeof(char));
    if(buffer == NULL)
    {
        printf("ERROR allocated buffer\n");
        return 1;
    }
    printf("CORRECT allocated buffer\n");
    printf("------------\n\n");

    char** pointer = (char**) calloc(size + 1, sizeof(char*));
    if(pointer == NULL) 
    {
        printf("ERROR allocated pointer\n");
        return 1;
    }    
    printf("CORRECT allocated pointer\n");
    printf("------------\n\n");


    fread(buffer, size, sizeof(char), files.asmcode);

    printf("CORRECT read file\n");
    printf("------------\n\n");

    int count_str = pointer_buf(buffer, pointer);
    printf("CORRECT pointers\n");
    printf("------------\n\n");

    
    asmtranslate(pointer, &files, &count_str);
    printf("CORRECT asmtranslate\n");
    printf("------------\n\n");
    
    free(buffer);
    free(pointer);
    fclose(files.asmcode);
    fclose(files.bytecode);

    printf("CORRECT destroy\n");
    printf("------------\n");
    
    FILE *fp = fopen("bytecode.txt", "rb");
    if (!fp) return 1;
    
    int bytecode[60] = {0};
    
    fread(bytecode, sizeof(int), 60, fp);
    
    for (int i = 0; i < count_str; i++)
    printf("> %d\n", bytecode[i]);
    
    fclose(fp);
}