#include "spu.h"


int main()
{
    spu_t spu = {};
    int count_elements = 0;

    printf("read bytecode\n");
    printf("------------\n\n");
    count_elements = readfile(&spu);
    printf("count_elements = %d\n", count_elements);

    for (int i = 0; i < count_elements; i++)
    {
        printf(">%d\n", spu.code[i]);
    }

    printf("command\n");
    printf("------------\n\n");
    calc(&spu, count_elements);

    printf("CORRECT do comand\n");
    printf("------------\n\n");

    //printf("%d\n", spu.stack.item);
    
    /*for (int i = 0; i < spu.stack.item; i++)
    {
        printf("%d\n", spu.stack.data[i]);
    }*/
    
    printf("free memory\n");
    printf("------------\n\n");
    spu_destroy(&spu);

}