#ifndef _SHOP_H_
#define _SHOP_H_

#include "Item.h"
#include "Rand.h"
#include "Ent.h"
#include <vector>
using namespace std;

class Shop
{
public:
    Shop(int itemList, vector<Item*> wantedItems);
    Item *trade(int money, int item);
    void addEnt(Ent *e) {ent.push_back(e);}
    Ent *getEnt(int i) {return ent[i];}
    vector<Ent*> ent;
private:
    const char *missions;
    const char *storyFact;
    vector<Item*> selling;
    vector<Item*> wanted;
};

#endif