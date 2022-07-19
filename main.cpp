#include <iostream>
#include "Ent.h"
#include "Map.h"
#include "Action.h"
#include <iostream>
using namespace std;

int main()
{
    char *name[20];
    Rand::initialize();
    Ent *e = new Ent(Rand::getRand(60, 100), Rand::getRand(10, 30), Rand::getRand(10, 50), Rand::getRand(1, 3), Rand::getRand(100, 200), false, false);
    cout << "what is youre name?\n: ";
    cin >> *name;
    e->setName(*name);

    e->printStats();
    Map *m = new Map(10);
    for (int i = 0; i < m->getSize(); i++)
    {
        Action *a = new Action(e, m->getFromMap(i));
    }
    
}
