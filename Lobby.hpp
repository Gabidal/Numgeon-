#ifndef _LOBBY_HPP_
#define _LOBBY_HPP_

#include "Ent.h"
#include "Shop.h"
#include "Action.h"
#include "Map.h"
#include "console.h"
#include <vector>
#include <iostream>
using namespace std;


void lobby(Ent *player, int choose, vector<Shop*> conquested)
{
    cout << Y << "where do you want to go?" << endl;
    cout << BLU << "type:\n1 = campaing\n2 = shop\n3 = online\n4 = cmd" << endl;
    cin >> choose;
    if (choose == 1)
    {
        Map *m = new Map(100, 10);
        for (int i = 0; i < m->map.size(); i++)
        {
            for (int j = 0; j < m->map[i]->ent.size(); j++)
            {
                Ent *e = m->map[i]->ent[j];
                Action *Battle = new Action(player, e);
                cout << Y << "type;\n1 = continue\n2 = menu" << endl;
                cin >> choose;
                if (choose == 2)
                {
                    return;
                }
            }
            conquested.push_back(m->map[i]);
            cout << R << "congrats! You have liberate a new Shop from the corruption!" << endl;
            cout << Y << "type;\n1 = continue\n2 = menu" << endl;
            cin >> choose;
            if (choose == 2)
            {
                return;
            }
        }
    }
    else if (choose == 2)
    {
        cout << R << "You have: " << conquested.size() << " amount of Shops are avaiable." << endl;
        cout << Y << "Please now, tell me wich one of them?\n: ";
        cin >> choose;
        //call trading system.
        return;
    }
    else if (choose == 3)
    {
        cout << R << "SoRRY  but the online mode isnt complete jet!" << endl;
    }
    else if (choose == 4)
    {
        cout << BLU << "Password\n: ";
        cin >> choose;
        if (choose = 733)
        {
            //call cmd.
        }
    }
}

#endif