#include "common.h"

int guRandom(void)
{
    static unsigned int gGlobalRNGState = 0xA6B99CD;

    unsigned int x = (gGlobalRNGState << 2) + 2;

    x *= (x + 1);
    x = x >> 2;

    gGlobalRNGState = x;

    return x;
}
