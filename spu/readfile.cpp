#include "spu.h"

int readfile(spu_t* spu)
{
    int count_elements = 0, i = 0;
    FILE* file = fopen("asm/bytecode.txt", "rb");
    if (!file)
    {
        printf("ERROR open file\n");
        return 1;
    }
    printf("CORRECT open file\n");
    printf("------------\n\n");
    

    size_t size = sizeFile(file);
    spu->code = (int*) calloc(sizeof(int), size_t(size));
    if(spu->code == NULL) 
    {
        printf("ERROR allocated code\n");
        return 1;
    }    
    printf("CORRECT allocated code\n");
    printf("------------\n\n");

    spu->regs = (int*) calloc(sizeof(int), size_t(size));
    if(spu->regs == NULL) 
    {
        printf("ERROR allocated regs\n");
        return 1;
    }    
    printf("CORRECT allocated regs\n");
    printf("------------\n\n");

    spu->labels = (int*) calloc(sizeof(int), size_t(size));
    if(spu->labels == NULL) 
    {
        printf("ERROR allocated labels\n");
        return 1;
    }    
    printf("CORRECT allocated labels\n");
    printf("------------\n\n");
    spu->ip = 0;

    fread(spu->code, size, sizeof(char), file);

    while (spu->code[i] != '\0')
    {
        count_elements++;
        i++;
    }
    //printf("%d\n", count_elements);
    return count_elements;

}