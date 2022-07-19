#include <iostream>
#include "Ent.h"
#include "Map.h"
#include "Action.h"
#include "Shop.h"
#include "console.h"
#include "Lobby.hpp"
#include <iostream>
using namespace std;


vector<Shop*> conquested;
Ent *player = new Ent(Rand::getRand(800, 1000), Rand::getRand(20, 40), Rand::getRand(20, 40), Rand::getRand(1, 3), Rand::getRand(100, 200), false, false);

int choose;

int main()
{
    char *name[20];
    Rand::initialize();
    cout << Y << "what is youre name?\n: " << RESET;
    cin >> *name;
    player->setName(*name);
    player->printStats();
    while (true)
    {
        lobby(player, choose, conquested);
    }
}


