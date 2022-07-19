#include "Shop.h"

Shop::Shop(int itemList, vector<Item*> wantedItems)
{
    for (int i = 0; i < itemList; i++)
    {
        Item *item = new Item(Rand::getRand(0, 100), Rand::getRand(0, 100), Rand::getRand(0, 100), Rand::getRand(0, 100), Rand::getRand(0, 100), Rand::getRand(0, 100), Rand::getRand(0, 100), Rand::getRand(0, 100));
        selling.push_back(item);
    }
    wanted = move(wantedItems);
}

Item *Shop::trade(int money, int item)
{
    if (money >= wanted[item]->COST)
    {
        return wanted[item];
    }
}