#include "common.h"

extern unsigned char farfetchdMove1;
extern unsigned char farfetchdMove2;
extern unsigned char farfetchdMove3;
extern unsigned char farfetchdMove4;
extern unsigned char gligarMove1;
extern unsigned char gligarMove2;
extern unsigned char gligarMove3;
extern unsigned char gligarMove4;

typedef struct Pokemon {
    char species;
    char heldItem;
    char moves[4];
    short trainerId;
    int experience;
    char unkC[10];
    unsigned short dvs16;
    char movesPP[4];
    char friendship;
    char level;
    char flags;
    char padding;
    char pokerus;
    char metLevel;
    char metLocation;
    char unk23[17];
    char nickname[12];
    char trainerName[12];
    char trainerNameCopy[12];
    char unk47[5];
} Pokemon;

struct sD_88104EA0 {
    char unk[0xA2];
    char partyCount;
    char giftSpecies;
    char unkA4[8];
    Pokemon partyPokemon[6];
};

void func_8000B580(void*, int);
// getSpeciesName
int func_8004B7A4(unsigned char);
int func_8004C874(unsigned long, unsigned long);
void func_80060D70(void*, void*);
void func_800619E8(void*);
// calculateExperience
int func_80061B88(int, int);
void func_80061F44(void*);
// getMovePP
char func_80062E10(unsigned char);
void func_80075630(Pokemon*, int);                          /* extern */

extern struct sD_88104EA0* D_88104EA0;

#define SPECIES_FARFETCHD 83
#define ITEM_GOLD_BERRY 174
#define ITEM_MYSTERY_BERRY 150

void createGiftPokemon(void) {
    int seed;
    int i;
    unsigned char movePP;
    long giftSpecies;
    Pokemon* giftPokemon;
    Pokemon* tempGiftPokemon;

    giftPokemon = &D_88104EA0->partyPokemon[D_88104EA0->partyCount];
    func_80075630(giftPokemon, 88);
    tempGiftPokemon = giftPokemon;
    if (D_88104EA0->giftSpecies == SPECIES_FARFETCHD) {
        giftPokemon->moves[0] = farfetchdMove1;
        giftPokemon->moves[1] = farfetchdMove2;
        giftPokemon->moves[2] = farfetchdMove3;
        giftPokemon->moves[3] = farfetchdMove4;
        giftPokemon->heldItem = ITEM_GOLD_BERRY;
    } else {
        giftPokemon->moves[0] = gligarMove1;
        giftPokemon->moves[1] = gligarMove2;
        giftPokemon->moves[2] = gligarMove3;
        giftPokemon->moves[3] = gligarMove4;
        giftPokemon->heldItem = ITEM_MYSTERY_BERRY;
    }
    for (i = 0; (i != 4) != 0;) {
        movePP = func_80062E10(giftPokemon->moves[i]);
        i++;
        tempGiftPokemon->movesPP[i - 1] = movePP;
    }
    seed = guRandom() + osGetCount();
    seedLCRNG(seed);
    giftPokemon->dvs16 = randLCRNG();
    giftSpecies = D_88104EA0->giftSpecies & 0xFF;
    giftPokemon->trainerId = 2000;
    giftPokemon->level = 5;
    giftPokemon->friendship = 70;
    giftPokemon->species = giftSpecies;
    giftPokemon->experience = func_80061B88(giftSpecies & 0xFF, giftPokemon->level);
    giftPokemon->metLevel = giftPokemon->level;
    giftPokemon->metLocation = 127;
    func_8000B580(giftPokemon->nickname, func_8004B7A4(giftPokemon->species));
    func_8000B580(giftPokemon->trainerName, func_8004C874(30, 26));
    func_80060D70(giftPokemon->trainerNameCopy, giftPokemon->trainerName);
    func_800619E8(giftPokemon);
    func_80061F44(giftPokemon);
}

#pragma GLOBAL_ASM("asm/nonmatchings/170D70/func_80170334.s")

#pragma GLOBAL_ASM("asm/nonmatchings/170D70/func_80170460.s")

#pragma GLOBAL_ASM("asm/nonmatchings/170D70/func_80170488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/170D70/func_8017057C.s")
