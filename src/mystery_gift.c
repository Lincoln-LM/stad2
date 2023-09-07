#include "common.h"

typedef struct sGiftResult {
    unsigned char giftType;
    unsigned char itemIndex;
    unsigned char decorationIndex;
} sGiftResult;

typedef struct sUnk {
    int unk0;
    char unk4;
    char unk5;
} sUnk;

extern unsigned char MysteryGiftItems[37];
// 0 Berry
// 1 PRZCureBerry
// 2 Mint Berry
// 3 Ice Berry
// 4 Burnt Berry
// 5 PSNCureBerry
// 6 Guard Spec.
// 7 X Defend
// 8 X Attack
// 9 Bitter Berry
// 10 Dire Hit
// 11 X Special
// 12 X Accuracy
// 13 Eon Mail
// 14 Morph Mail
// 15 Music Mail
// 16 MiracleBerry
// 17 Gold Berry
// 18 Revive
// 19 Great Ball
// 20 Super Repel
// 21 Max Repel
// 22 Elixer
// 23 Ether
// 24 Water Stone
// 25 Fire Stone
// 26 Leaf Stone
// 27 Thunder Stone
// 28 Max Ether
// 29 Max Elixer
// 30 Max Revive
// 31 Scope Lens
// 32 HP Up
// 33 PP Up
// 34 Rare Candy
// 35 Bluesky Mail
// 36 Mirage Mail
extern unsigned char D_81C008C4[];
extern unsigned short D_81C008EA[];
extern sGiftResult D_81C00972;
extern sGiftResult D_81C00976;
extern sUnk D_81C00830[18];
extern sUnk D_81C00940[];
extern sUnk D_81C0094C[6];
extern sUnk D_81C00952[];

void func_8005DFD4(unsigned char, unsigned char, sGiftResult*);
int func_8005F790(unsigned char, unsigned char, sGiftResult*);
void func_8005F7B8(int, unsigned char);
void func_8005F9CC(int, int);
int func_81C00020(unsigned char);
char func_81C00174(unsigned char, unsigned char, unsigned char);
void func_8005D9E0(unsigned char, unsigned short*);
int func_8005E03C(unsigned char);
void func_8005E07C(unsigned char, int);
void func_8005E0BC(unsigned char, unsigned char, unsigned short);
void func_80060A84(void*, unsigned short);
int func_81C0034C(unsigned char, unsigned char);
short func_81C00408(unsigned char);
short func_81C004E4(int);
void func_81C00584(unsigned char);


#if NON_MATCHING
// non-matching register nonsense :( 365 https://decomp.me/scratch/Zccdn
char selectMysteryGiftItem(unsigned char trainerIdHigh, unsigned char trainerIdLow) {
    int rand;
    char temp;
    unsigned char resultIndex;

    if ((randLCRNG() & 0xFF) < 25u) {
        if ((randLCRNG() & 0xFF) < 50u) {
            if ((randLCRNG() & 0xFF) < 50u) {
                if ((trainerIdHigh & (1 << 7))){
                    resultIndex = 33;
                } else {
                    resultIndex = 32;
                }
            } else {
                resultIndex = ((unsigned char) (trainerIdHigh >> 4)) & 7;
                resultIndex = (resultIndex + 0x18ull) & 0xFF;
            }
        } else {
            rand = randLCRNG() & 3;
            temp = (trainerIdHigh & (1 << (rand & 0xFF))) ? 1 : 0;
            temp = (rand << 1) + temp;
            resultIndex = temp;
            resultIndex += 0x10ull;
        }
    } else {
        rand = randLCRNG() & 7;
        temp = (trainerIdLow & (1 << (rand & 0xFF))) ? 1 : 0;
        resultIndex = ((rand << 1) + temp) & 0xFF;
    }
    return resultIndex;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/mystery_gift/func_80436070.s")
#endif
char _selectMysteryGiftItem(unsigned char trainerIdHigh, unsigned char trainerIdLow);

// very similar to selectMysteryGiftItem
// non-matching register nonsense :( 475 https://decomp.me/scratch/1YJYh
#if NON_MATCHING
char selectMysteryGiftDecoration(unsigned char trainerIdLow, unsigned char trainerIdHigh, unsigned char roundTwoUnlocked) {
    int rand;
    char temp;
    unsigned char resultIndex;

    if ((randLCRNG() & 0xFF) < 36u) {
        if ((randLCRNG() & 0xFF) < 72u) {
            if ((randLCRNG() & 0xFF) < 72u) {
                rand = randLCRNG() & 0xFF;
                if (rand < 77) {
                    resultIndex = roundTwoUnlocked != 0 ? 34 : 36; 
                } else if (rand < 154) {
                    resultIndex = 36;
                } else if (trainerIdLow & (1 << 7)) {
                    resultIndex = 33;
                } else {
                    resultIndex = 32;
                }
            } else {
                resultIndex = ((unsigned char) (trainerIdLow >> 4)) & 7;
                resultIndex = resultIndex + 24ull;
            }
        } else {
            rand = randLCRNG() & 3;
            temp = (trainerIdLow & (1 << (rand & 0xFF))) ? 1 : 0;
            temp = (rand << 1) + temp;
            resultIndex = temp;
            resultIndex += 0x10ull;
        }
    } else {
        rand = randLCRNG() & 7;
        temp = (trainerIdHigh & (1 << (rand & 0xFF))) ? 1 : 0;
        resultIndex = ((rand << 1) + temp) & 0xFF;
    }
    return resultIndex;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/mystery_gift/func_80436194.s")
#endif
char _selectMysteryGiftDecoration(unsigned char trainerIdLow, unsigned char trainerIdHigh, unsigned char roundTwoUnlocked);


void selectMysteryGiftResult(unsigned char* trainerId, sGiftResult* giftResult, unsigned char roundTwoUnlocked) {
    giftResult->giftType = randLCRNG() & 1;
    giftResult->itemIndex = _selectMysteryGiftItem(trainerId[0], trainerId[1]);
    giftResult->decorationIndex = _selectMysteryGiftDecoration(trainerId[1], trainerId[0], roundTwoUnlocked);
}
void _selectMysteryGiftResult(unsigned char* trainerId, sGiftResult* giftResult, unsigned char roundTwoUnlocked);

#if NON_MATCHING
// 2007 equivalent(?) https://decomp.me/scratch/lQW4f
int generateMysteryGift(short arg0, unsigned short roundTwoUnlocked)
{
    int iVar2;
    unsigned char trainerId[2];
    unsigned short sp30[11];
    int giftRecieved;
    short connectionsToday;
    unsigned char temp_a1;
    giftRecieved = 0;
    seedLCRNG(osGetCount());
    func_8005D9E0(arg0, sp30);
    func_80060A84(&trainerId, sp30[0]);
    connectionsToday = func_8005E03C(temp_a1);
    temp_a1 = connectionsToday;
    if (connectionsToday < 5)
    {
        func_8005E0BC(temp_a1, temp_a1, sp30[0]);
        func_8005E07C(temp_a1, (temp_a1 + 1) & 0xFFull);
        selectMysteryGiftResult(&trainerId, &D_81C00972, roundTwoUnlocked);
        selectMysteryGiftResult(&trainerId, &D_81C00976, roundTwoUnlocked);
        giftRecieved = 1;
    }
    return giftRecieved;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/mystery_gift/func_8043636C.s")
#endif
int _generateMysteryGift(short arg0, unsigned short roundTwoUnlocked);

#if NON_MATCHING
// 482 equivalent https://decomp.me/scratch/cZuqK
unsigned char func_80436428(unsigned char arg0) {
    unsigned char sp2F;
    volatile int sp20;
    unsigned short var_s0;
    unsigned short var_v0;
    unsigned char temp_a1;

    var_s0 = 0;
    if ((D_81C00972.giftType != 0) && ((int) D_81C00972.decorationIndex < 37)) {
        temp_a1 = D_81C008C4[D_81C00972.decorationIndex];
        sp20 = (int) arg0;
        sp2F = temp_a1;
        if (func_8005F790(arg0, temp_a1, &D_81C00972) == 0) {
            var_s0 = D_81C008EA[temp_a1];
            sp2F = temp_a1;
            func_8005F7B8(sp20, temp_a1);
            func_8005F9CC(sp20, func_81C00020(sp2F) & 0xFFFF);
        }
    }
    var_v0 = var_s0;
    if ((var_s0 == 0) && ((int) D_81C00972.itemIndex < 37)) {
        var_s0 = (unsigned short) MysteryGiftItems[D_81C00972.itemIndex];
        func_8005DFD4(arg0, var_s0, &D_81C00972);
        var_v0 = var_s0;
    }
    if (var_v0 == 0) {
        var_s0 = 173;
    }
    return (unsigned char) var_s0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/mystery_gift/func_80436428.s")
#endif
unsigned char _func_80436428(unsigned char arg0);

#if NON_MATCHING
// 240 equivalent https://decomp.me/scratch/I9seX
unsigned char func_80436504(int arg0) {
    int temp_a0;
    unsigned char var_v0;
    unsigned char var_v1;

    var_v1 = 0;
    if ((D_81C00976.giftType != 0) && ((int) D_81C00976.decorationIndex < 37)) {
        temp_a0 = (D_81C008EA[D_81C008C4[D_81C00976.decorationIndex]] - 0x100) & 0xFF;
        if (*(char *)(temp_a0 + arg0) == 0) {
            var_v1 = (temp_a0 + 0x100) & 0xFFFF;
        }
    }
    var_v0 = var_v1;
    if ((var_v1 == 0) && ((int) D_81C00976.itemIndex < 37)) {
        var_v1 = MysteryGiftItems[D_81C00976.itemIndex];
        var_v0 = var_v1;
    }
    if (var_v0 == 0) {
        var_v1 = 173;
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/mystery_gift/func_80436504.s")
#endif
unsigned char _func_80436504(int arg0);

#if NON_MATCHING
// far from matching, probably equivalent 8755 https://decomp.me/scratch/jUr6t
void func_804365A4(unsigned char arg0) {
    int temp_lo;
    int temp_v0;
    sUnk temp_a1;
    sUnk* temp_v0_2;
    sUnk* temp_v1;

    func_80075630(D_81C00940, 0x32);
    func_80060EC8(D_81C00940, func_8004C874(0x3D, 0x3E));
    temp_v0 = func_8005D92C(arg0);
    switch (temp_v0) {
    case 5:
    case 7:
        D_81C00940[2].unk4 = 1;
        break;
    case 6:
        D_81C00940[2].unk4 = 2;
        break;
    }
    temp_v0 = (randLCRNG() % 3) * 6;
    D_81C0094C[0].unk0 = D_81C00830[temp_v0].unk0;
    D_81C0094C[0].unk4 = D_81C00830[temp_v0].unk4;
    D_81C0094C[0].unk5 = D_81C00830[temp_v0].unk5;

    D_81C0094C[1].unk0 = D_81C00830[temp_v0 + 1].unk0;
    D_81C0094C[1].unk4 = D_81C00830[temp_v0 + 1].unk4;
    D_81C0094C[1].unk5 = D_81C00830[temp_v0 + 1].unk5;

    D_81C0094C[2].unk0 = D_81C00830[temp_v0 + 2].unk0;
    D_81C0094C[2].unk4 = D_81C00830[temp_v0 + 2].unk4;
    D_81C0094C[2].unk5 = D_81C00830[temp_v0 + 2].unk5;

    D_81C0094C[3].unk0 = D_81C00830[temp_v0 + 3].unk0;
    D_81C0094C[3].unk4 = D_81C00830[temp_v0 + 3].unk4;
    D_81C0094C[3].unk5 = D_81C00830[temp_v0 + 3].unk5;

    D_81C0094C[4].unk0 = D_81C00830[temp_v0 + 4].unk0;
    D_81C0094C[4].unk4 = D_81C00830[temp_v0 + 4].unk4;
    D_81C0094C[4].unk5 = D_81C00830[temp_v0 + 4].unk5;

    D_81C0094C[5].unk0 = D_81C00830[temp_v0 + 5].unk0;
    D_81C0094C[5].unk4 = D_81C00830[temp_v0 + 5].unk4;
    D_81C0094C[5].unk5 = D_81C00830[temp_v0 + 5].unk5;

    D_81C00940[6].unk0 = 0xFF;
    func_8005E1F0(arg0, D_81C00940, 2, 6);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/mystery_gift/func_804365A4.s")
#endif
void _func_804365A4(unsigned char arg0);

void func_80436760(unsigned char arg0, short* arg1, short* arg2, int arg3, unsigned char roundTwoUnlocked) {
    // succeeds if < 5 gifts have been recieved
    if (_generateMysteryGift(arg0, roundTwoUnlocked) != 0) {
        _func_804365A4(arg0);
        *arg1 = _func_80436428(arg0);
        *arg2 = _func_80436504(arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/mystery_gift/func_804367C4.s")
