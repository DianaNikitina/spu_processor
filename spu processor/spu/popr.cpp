#include "spu.h"

void popr(spu_t* spu)
{
    switch(spu->code[spu->ip++])
    {
        case AX:
        {
            //printf(">>%d", spu->regs[AX]);
            spu->regs[AX] = stackPop(&spu->stack);
            break;
        }
        case BX:
        {
            spu->regs[BX] = stackPop(&spu->stack);
            break;
        }
        case CX:
        {
            spu->regs[CX] = stackPop(&spu->stack);
            break;
        }
        case DX:
        {
            spu->regs[DX] = stackPop(&spu->stack);
            break;
        }
        case EX:
        {
            spu->regs[EX] = stackPop(&spu->stack);
            break;
        }
        case FX:
        {
            spu->regs[FX] = stackPop(&spu->stack);
            break;
        }
        default:
            break;
    }
}