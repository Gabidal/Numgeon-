#include "Map.h"

Map::Map(int x, int y)
{
	for (int i = 0; i < x;i++)
	{
		vector<Item*> items;
		Item *item = new Item(Rand::getRand(1, 100), Rand::getRand(1,10), Rand::getRand(1, 10), Rand::getRand(1, 10), Rand::getRand(1, 5), Rand::getRand(1, 100), Rand::getRand(1, 100), Rand::getRand(1, 100));
		items.push_back(item);
		Shop *s = new Shop(Rand::getRand(1, 5), items);
		for (int j = 0; j < y; j++)
		{
			Ent *e = new Ent(Rand::getRand(200, 1000), Rand::getRand(20, 40), Rand::getRand(20, 40), Rand::getRand(1, 3), Rand::getRand(100, 200), true, false);
			e->addItem(item);
			e->setName("Dungos");
			s->ent.push_back(e);
		}
		map.push_back(s);
	}
}
