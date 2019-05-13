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
    Ent *e = new Ent(100, 5, 10, 10, false, false);
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
