#include "spu.h"

void pushr(spu_t* spu)
{
    switch(spu->code[spu->ip++])
    {
        case AX:
        {
            //printf(">%d", spu->regs[AX]);
            stackPush(&spu->stack, spu->regs[AX]);
            break;
        }
        case BX:
        {
            stackPush(&spu->stack, spu->regs[BX]);
            break;
        }
        case CX:
        {
            stackPush(&spu->stack, spu->regs[CX]);
            break;
        }
        case DX:
        {
            stackPush(&spu->stack, spu->regs[DX]);
            break;
        }
        case EX:
        {
            stackPush(&spu->stack, spu->regs[EX]);
            break;
        }
        case FX:
        {
            stackPush(&spu->stack, spu->regs[FX]);
            break;
        }
        default:
            break;
    }
}