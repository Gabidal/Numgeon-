#include "Map.h"

Map::Map(int size)
{
	for (int i = 0; i < size;i++)
	{
		Ent *e = new Ent(Rand::getRand(60, 100), Rand::getRand(10, 30), Rand::getRand(10, 50), Rand::getRand(1, 3), 100 , true, false);	
		e->setName("Dungos");
		Item *item = new Item(Rand::getRand(60, 100), Rand::getRand(10, 30), Rand::getRand(10, 50), Rand::getRand(1, 3), Rand::getRand(20, 60), Rand::getRand(0, 100), Rand::getRand(1, 100), Rand::getRand(0, 3));
		e->addItem(item);
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
