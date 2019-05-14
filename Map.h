#ifndef _MAP_H_
#define _MAP_H_

#include "Ent.h"
#include "Rand.h"
#include "Item.h"
#include <vector>
#include <iostream>
using namespace std;

class Map
{
public:
	Map(int size);
	~Map();
	void setToMap(int i, Ent *e);
	Ent *getFromMap(int i);
	void printMap();
	int getSize() { return map.size();}
private:
	vector<Ent*> map;
};

#endif
