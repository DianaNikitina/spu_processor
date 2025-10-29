#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("test_file", "wb");
    if (!fp) return 1;

    int bytecode[2] = {1, 150};

    fwrite(bytecode, 2, sizeof(int), fp);

    fclose(fp);

    return 0;
}