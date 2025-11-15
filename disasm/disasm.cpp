#include "disasm.h"

int main()
{
    size_t size = 0;
    files_t files = {};
    buffer_t buffer = {};

    files.bitecode = fopen("bitecode.txt", "r");

    if (checkfile(&files))
    {
        printf("error open file asm");
        return 1;
    }
    printf("correct open file asm");
    

    size = sizeFile(files.bitecode);
    
    buffer.comand_disasm = (char*) calloc(size + 1, sizeof(char));
    
    buffer.compare_digit_disasm = (char*) calloc(size1 + 1, sizeof(char));
    
    buffer.compare_number_disasm = (char*) calloc(size1 + 1, sizeof(char));
    
    printf("correct allocated disasm\n");
    
    files.bitecode = fopen("bitecode.txt", "r");
    
    fread(buffer.comand_disasm, size, sizeof(char), files.bitecode);
    
    printf("correct read file\n");

    disasmtranslate(&buffer, &files, size1);

    printf("correct disasmtranslate\n");

    free(buffer.comand_disasm);
    disasmdestroy(&buffer);
    fclose(files.disasmcode);
    fclose(files.bitecode);
    


}
