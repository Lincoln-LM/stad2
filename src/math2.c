#include "common.h"

// partial atan2
#pragma GLOBAL_ASM("asm/nonmatchings/math2/func_8000B2F0.s")

// atan2
#pragma GLOBAL_ASM("asm/nonmatchings/math2/func_8000B350.s")

// [0, 2**16)
int randShort(void) {
    unsigned int rand = guRandom();
    if (1) {}
    return rand & 0xFFFF;
}

// [0.0, 1.0)
float randFloat(void) {
    return randShort() / 65536.0f;
}

