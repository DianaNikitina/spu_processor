#include "asm.h"


void checkasm(files_t* files)
{
    //int i = 0;
    size_t size_asmcode = sizeFile(files->asmcode);
    size_t size_disasmcode = sizeFile(files->disasmcode);
    printf("%d\n", int(size_asmcode));
    printf("%d\n", int(size_disasmcode));

    if (size_asmcode != size_disasmcode)
        printf("Failed. asmcode and disasmcode different\n");
    char* check_asmcode = (char*) calloc(size_asmcode + 1, sizeof(char));
    char* check_disasmcode = (char*) calloc(size_disasmcode + 1, sizeof(char));
    fread(check_asmcode, size_asmcode, sizeof(char), files->asmcode);
    fread(check_disasmcode, size_disasmcode, sizeof(char), files->disasmcode);



    //for(i = 0; i < )

    free(check_asmcode);
    free(check_disasmcode);

}