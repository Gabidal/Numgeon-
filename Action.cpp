#include "Action.h"
#include "console.h"

Action::Action(Ent *a, Ent *b)
{
	cout << R << "An Action has occurred..." << endl;
	cout << M << b->getName() << " has made it´s path to you!" << endl;
	
	vector<int> amoves;
	vector<int> bmoves;

	int move;
	
	while(true)
	{
		if (a->getHP() < 1)
		{
    	cout << Y << a->getName() << " lost the game! " << R << b->getName() << " wins!" << endl;
			if (0 < a->items.size())
			{
				b->addItem(a->items.at(0));
			}
			else
			{
				cout << R << "No items to loot :(" << endl;
			}
			a->setHP(1000);
			return;
			break;
		}
		if (b->getHP() < 1)
		{			
      cout << Y << b->getName() << " lost the game! " << R << a->getName() << " wins!" << endl;
			if (0 < b->items.size())
			{
				a->addItem(b->items.at(0));
			}
			else
			{
				cout << R << "No items to loot :(" << endl;
			}
			b->setHP(1000);
			return;
			break;
		}
		//PLAYER-_-_-_-_-_-_-_-_-_-_-_-
		if (a->isAI()) //AI
		{
			move = a->getAI(a, b);
		}
		else if (a->getEx()) //ONLINE
		{
			
		}
		else //LOCAL
		{
			cout << G << "what will " << a->getName() << " do?" << endl;
			cin >> move;
		}

		a->moves.push_back(move);


		//BOT -_-_-_-_-_-_-_-_-_-_-_-_-_-_-
		if (b->isAI()) //AI
		{
			move = b->getAI(b, a);
		}
		else if (b->getEx()) //ONLINE
		{
			
		}
		else  //LOCAL
		{
			cout << BLU << "what will " << b->getName() << " do?" << endl;
			cin >> move;
		}

		b->moves.push_back(move);

		if (a->getSPE() != b->getSPE())
		{
			Ent* e = (a->getSPE() > b->getSPE()) ? a : b;

			if (e->isAI())
			{
				move = e->getAI(a, b);
			}
			else
			{
				cout << C << "It seems that " << e->getName() << " has some more time." << endl;
				cout << BLU << "what will you do?\n: ";
				cin >> move;
			}
			
			e->moves.push_back(move);
		}

		for (int amove : a->moves)
		{
		fight(a, b, amove);
		}
		for (int bmove : b->moves)
		{
		fight(b, a, bmove);
		}
		cout << a->getName() << " stats\n: ";
		a->printStats();
		cout << b->getName() << " stats\n: ";
		b->printStats();
    
		a->moves.clear();
		b->moves.clear();
	}
}

void Action::fight(Ent *a, Ent *b, int amove)
{
		if (amove <= a->getSTA())
		{
			if (amove < 0 && amove > -33)
			{
				cout << Y << a->getName() << " tryed to encourage " << b->getName() << endl;
			}
			else if (amove < 11)  //a turn fight.
			{
				b->setHP(b->getHP() - ((a->getATC() + amove ) / b->getDEF()));
				a->setSTA(a->getSTA() - amove);
				cout << C << a->getName() << " was able to do: " << a->getATC() + amove << ", Of damage;" << endl;
			}
		}
		else
		{
			cout << M << "Try hard. lose like a boss... said " << a->getName() << endl; 
		}

			if (amove < 20 && amove > 10) //rest turn amount.
			{
				a->setSTA(a->getSTA() + amove + a->getFIT());
				cout << BLU << a->getName() << " tooke a nap to heal it´s self." << endl;
			} 
			else if (amove > 19)  //try items that are in inv by index.
			{
				if ((amove-20) < a->items.size())
				{
				cout << a->getName() << " used: " << a->items[amove-20]->RANK << " ranked item!" << endl;
				a->useItem(amove-20);
				}
				else
				{
					if (a->isAI() != true)
					{
						cout << R << "That slot is empty!" << endl;
						cout << G << "Please choose again dear " << a->getName() << endl;
						if (a->isAI() != true && a->getEx() != true)
						{
						cin >> amove;
						}
						if (Rand::getRand(0, 2) == 0)
						{
							cout << C << "OPP´s youre out of time, better be smarter next time dude!" << endl;
						}
						else if (Rand::getRand(0, 2) == 1)
						{
							cout << Y << "Too slow!" << endl;
						}
						else
						{
							cout << M << "Better luck next time!" << endl;
						}
					}
					else
					{
						cout << R << a->getName() << " Tryed to use a item but, it faild!" << endl;
					}
					
				}
				
			}
}