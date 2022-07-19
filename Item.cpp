#include "Item.h"

Item::Item(int hp, int def, int atc, int spe, int sta, int id, int cost, int rank)
{
    affectHP = hp;
    affectDEF = def;
    affectATC = atc;
    affectSPE = spe;
    affectSTA = sta;
    ID = id;
    COST = cost;
    RANK = rank;
};

