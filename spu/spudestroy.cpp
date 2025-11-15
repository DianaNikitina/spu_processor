#include "spu.h"

void spu_destroy(spu_t *spu)
{
    stackDestroy(&spu->stack);
    free(spu->code);
    free(spu->regs);
    free(spu->labels);
    spu->ip = 0;
}