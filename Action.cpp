#include "Action.h"

Action::Action(Ent *a, Ent *b)
{
	cout << "An Action has occurred..." << endl;
	cout << b->getName() << " has made it´s path to you!" << endl;
	cout << " type -h for help." << endl;
	
	vector<int> amoves;
	vector<int> bmoves;

	int move;
	
	while(true)
	{
		if (a->getHP() < 1)
		{
			cout << a->getName() << " lost the game! " << b->getName() << " wins!" << endl;
			break;
		}
		if (b->getHP() < 1)
		{
			cout << b->getName() << " lost the game! " << a->getName() << " wins!" << endl;
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
			cout << "what will " << a->getName() << " do?" << endl;
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
			cout << "what will " << b->getName() << " do?" << endl;
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
				cout << "It seems that " << e->getName() << " has some more time." << endl;
				cout << "what will you do?\n: ";
				cin >> move;
			}
			
			e->moves.push_back(move);
		}


		fight(a, b);
		cout << a->getName() << " stats\n: ";
		a->printStats();
		cout << b->getName() << " stats\n: ";
		b->printStats();
	}
}

void Action::fight(Ent *a, Ent *b)
{
	for (int amove : a->moves)
	{
		if (amove < 0 && amove > -33)
		{
			b->setATC(b->getATC() - amove);
			a->setSTA(a->getSTA() + amove);
			cout << a->getName() << " tryed to encourage " << b->getName() << endl;
		}
		else if (amove < 11)  //a turn fight.
		{
			b->setHP(b->getHP() - ((a->getATC() + amove ) / b->getDEF()));
			a->setSTA(a->getSTA() - amove);
			cout << a->getName() << " was able to do: " << a->getATC() + amove << ", Of damage;" << endl;
		}
		else if (amove < 21) //rest turn amount.
		{
			a->setSTA(a->getSTA() + amove + a->getFIT());
			a->setHP(a->getHP() + 5);
			cout << a->getName() << " tooke a nap to heal it´s self." << endl;
		} 
		else  //try items that are in inv by index.
		{
			
		}
	}
	

	for (int bmove : b->moves)
	{
		if (bmove < 0 && bmove > -33)
		{
			a->setATC(a->getATC() - bmove);
			b->setSTA(b->getSTA() + bmove);
			cout << b->getName() << " tryed to encourage " << a->getName() << endl;
		}
		if (bmove < 11)  //a turn fight.
		{
			a->setHP(a->getHP() - ((b->getATC() + bmove ) / a->getDEF()));
			b->setSTA(b->getSTA() - bmove);
			cout << b->getName() << " was able to do: " << b->getATC() + bmove << ", Of damage;" << endl;
		}
		else if (bmove < 21) //rest turn amount.
		{
			b->setSTA(a->getSTA() + bmove + a->getFIT());
			b->setHP(b->getHP() + 5);
			cout << b->getName() << " tooke a nap to heal it´s self." << endl;
		}
		else  //try items that are in inv by index.
		{
			
		}
	}
}