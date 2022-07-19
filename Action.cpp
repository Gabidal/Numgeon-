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
			b->addItem(a->items.at(0));
			break;
		}
		if (b->getHP() < 1)
		{
			cout << b->getName() << " lost the game! " << a->getName() << " wins!" << endl;
      
			a->addItem(b->items.at(0));

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
		if (amove < a->getSTA())
		{
			if (amove < 0 && amove > -33)
			{
				cout << a->getName() << " tryed to encourage " << b->getName() << endl;
			}
			else if (amove < 11)  //a turn fight.
			{
				b->setHP(b->getHP() - ((a->getATC() + amove ) / b->getDEF()));
				a->setSTA(a->getSTA() - amove);
				cout << a->getName() << " was able to do: " << a->getATC() + amove << ", Of damage;" << endl;
			}
		}
		else
		{
			cout << "Try hard. lose like a boss... said " << a->getName() << endl; 
		}

			if (amove < 20 && amove > 10) //rest turn amount.
			{
				a->setSTA(a->getSTA() + amove + a->getFIT());
				cout << a->getName() << " tooke a nap to heal it´s self." << endl;
			} 
			else if (amove > 19)  //try items that are in inv by index.
			{
				if ((amove-20) < a->items.size())
				{
				cout << a->getName() << " used" << a->items.at(amove-20) << endl;
				a->useItem(amove-20);
				}
				else
				{
					cout << "That slot is empty!" << endl;
					cout << "Please choose again dear " << a->getName() << endl;
					cin >> amove;
					
					if (Rand::getRand(0, 2) == 0)
					{
						cout << "OPP´s youre out of time, better be smarter next time dude!" << endl;
					}
					else if (Rand::getRand(0, 2) == 1)
					{
						cout << "Too slow!" << endl;
					}
					else
					{
						cout << "Better luck next time!" << endl;
					}
					
				}
				
			}
}