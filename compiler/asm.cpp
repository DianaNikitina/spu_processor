#include "asm.h"

int main()
{
    size_t size = 0, size1 = 0;
    files_t files = {};
    buffer_t buffer = {};
    files.asmcode = fopen("asmcode.txt", "r");

    size = sizeFile(files.asmcode);

    //printf("%ld\n", size);

    printf("correct size\n");

    buffer.comand = (char*) calloc(size + 1, sizeof(char));

    buffer.compare_alpha = (char*) calloc(size + 1 , sizeof(char));

    buffer.compare_digit = (char*) calloc(size + 1, sizeof(char));

    printf("correct allocated\n");

    /*if (checktext(matrix))
    { 
        printf("Allocation Failed");
        return 1;
    }
    printf("Correct buffer text\n");*/

    fread(buffer.comand, size, sizeof(char), files.asmcode);

    /*for (i = 0; i < int(size); i++)
    {
        printf("%c", comand[i]);
    }*/


    printf("correct read file\n");

    translate(&buffer, &files, size);

    printf("correct translate\n");

    size1 = sizeFile(files.bitecode);

    buffer.comand_disasm = (char*) calloc(size1 + 1, sizeof(char));

    buffer.compare_digit_disasm = (char*) calloc(size1 + 1, sizeof(char));

    buffer.compare_number_disasm = (char*) calloc(size1 + 1, sizeof(char));

    printf("correct allocated disasm\n");

    files.bitecode = fopen("bitecode.txt", "r");

    fread(buffer.comand_disasm, size, sizeof(char), files.bitecode);

    disasm(&buffer, &files, size1);

    checkasm(&files);

    free(buffer.comand);
    free(buffer.compare_alpha);
    free(buffer.compare_digit);
    free(buffer.comand_disasm);
    free(buffer.compare_digit_disasm);
    free(buffer.compare_number_disasm);
    fclose(files.asmcode);
    fclose(files.bitecode);
    fclose(files.disasmcode);
}