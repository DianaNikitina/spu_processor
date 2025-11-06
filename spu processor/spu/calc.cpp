#include "spu.h"

// function for each command
// call ret, jmp
// 

int calc(spu_t* spu, int count_elements)
{
    int capacity = 100;

    printf("construct stack\n");
    printf("------------\n\n");
    stackInit(&spu->stack, capacity);

    //printf("%d\n", count_elements);

    printf("do comands\n");
    printf("------------\n\n");
    while (spu->ip < count_elements)
    {
        int cmd = spu->code[spu->ip++];
        //printf(">>>%d - %d\n", cmd, spu->ip);
        //printf("*%d\n", spu->code[spu->ip]);

        switch(cmd)
        {
            case PUSH:
                push(spu);
                break;
            case POP:
                stackPop(&spu->stack);
                break;
            case ADD:
                add(spu);
                break;
            case SUB:
                sub(spu);
                break;
            case MUL:
                mul(spu);
                break; 
            case DIV:
                div(spu);
                break; 
            case IN:
                in(spu);
                break;
            case OUT:
                out_stack(&spu->stack);
                break;
            case PUSHR:
                pushr(spu);
                break;
            case POPR:
                popr(spu);
                break;
            case HALT:
                return 1;
            case CALL:
                printf("%d", spu->stack.data[spu->stack.item++]);
                break;
            case JMP:
                spu->ip = spu->code[spu->ip+1];
                break;
            case JA:
                ja(spu);
                break;
            case JAE:
                jae(spu);
                break;
            case JB:
                jb(spu);
                break;
            case JBE:
                jbe(spu);
                break;
            case JE:
                je(spu);
                break;
            case JNE:
                jne(spu);
                break;
            case TWO_DOT:
            {
                spu->labels[spu->code[spu->ip]] = spu->ip;
                spu->ip++;
                break;
            }
            
            default:
                break;
        }
        //printf("*%d\n", spu->ip);
    }
    return 0;
}