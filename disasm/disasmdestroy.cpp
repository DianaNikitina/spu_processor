#include "disasm.h"

void disasmdestroy(buffer_t *buffer)
{
    free(buffer->compare_digit_disasm);
    free(buffer->compare_number_disasm);
}