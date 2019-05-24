#ifndef _MAP_H_
#define _MAP_H_

#include "Ent.h"
#include "Rand.h"
#include "Item.h"
#include "Shop.h"
#include <vector>
#include <iostream>
using namespace std;

class Map
{
public:
	Map(int x, int y);
	int getSize() {return map.size();}
	vector<Shop*> map;
private:
};

#endif
