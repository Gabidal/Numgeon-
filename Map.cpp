#include "Map.h"

Map::Map(int size)
{
	for (int i = 0; i < size;i++)
	{
		Ent *e = new Ent(Rand::getRand(20, 100), Rand::getRand(0, 20), Rand::getRand(10, 50), Rand::getRand(1, 10), true, false);	
		e->setName("a Dungos");
		map.push_back(e);
	}
}

void Map::setToMap(int i, Ent *e)
{
	map.at(i) = e;
}

Ent *Map::getFromMap(int i)
{
	return map.at(i);
}

void Map::printMap()
{
	for (int i = 0; i < map.size();i++)
	{
		map.at(i)->printStats(); 
	}
}
