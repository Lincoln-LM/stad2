#include "common.h"

extern int gLCRNGState;

void seedLCRNG(int seed) {
    gLCRNGState = seed;
}

int randLCRNG(void)
{
  gLCRNGState = (gLCRNGState * 0x19660D) + 0x3C6EF35F;
  return gLCRNGState;
}

// vector operations
#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800356DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800356FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035724.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035748.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_8003576C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800357A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800357DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035814.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_8003584C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800359B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035A08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035A78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035AB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035AE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035B20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035C30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035C70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035CB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80035F9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800360EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80036224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800363D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80036558.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800366B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800368BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800369D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80036C0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80036D2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80036DD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80036EAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037044.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800370C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037154.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800371F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_8003726C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800372AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037300.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037370.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037580.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800375F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037920.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_800379D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037AA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/math/func_80037C20.s")
