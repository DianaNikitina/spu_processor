#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("test_file", "rb");
    if (!fp) return 1;

    int bytecode[2] = {0};

    fread(bytecode, sizeof(int), 2, fp);

    for (int i = 0; i < 2; i++)
        printf("> %d\n", bytecode[i]);

    fclose(fp);

    return 0;
}