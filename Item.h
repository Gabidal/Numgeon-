#ifndef _ITEM_H_
#define _ITEM_H_


class Item
{
public:
    Item(int hp, int def, int atc, int spe, int sta, int id, int cost, int rank);
    int affectHP;
    int affectDEF;
    int affectATC;
    int affectSPE;
    int affectSTA;
    int COST;
    int RANK;
    int getID() { return ID;}
protected:
    int ID;
};

#endif