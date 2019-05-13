#include "Action.h"

Action::Action(Ent *a, Ent *b)
{
	cout << "An Action has occurred..." << endl;
	cout << b->getName() << "has made it´s path to you!" << endl;
	cout << "type -h for help." << endl;
	int aMove = 0;
	int bMove = 0;
	while(true)
	{
		if (a->getHP() < 1)
		{
			cout << a->getName() << "lost the game!" << b->getName() << "wins!" << endl;
			break;
		}
		if (b->getHP() < 1)
		{
			cout << b->getName() << "lost the game!" << a->getName() << "wins!" << endl;
			break;
		}
		//PLAYER-_-_-_-_-_-_-_-_-_-_-_-
		if (a->isAI()) //AI
		{
			aMove = a->getAI(a, b);
		}
		else if (a->getEx()) //ONLINE
		{
			
		}
		else //LOCAL
		{
			cout << "what will" << a->getName() << "do?" << endl;
			cin >> aMove;
		}
		//BOT -_-_-_-_-_-_-_-_-_-_-_-_-_-_-
		if (b->isAI()) //AI
		{
			bMove = b->getAI(b, a);
		}
		else if (b->getEx()) //ONLINE
		{
			
		}
		else  //LOCAL
		{
			cout << "what will" << b->getName() << "do?" << endl;
			cin >> bMove;
		}
		fight(a, b, aMove, bMove);
	}
}

void Action::fight(Ent *a, Ent *b, int amove, int bmove)
{
	if (amove < 6)  //a turn fight.
	{

	}
	else if (amove < 11) //rest turn amount.
	{

	}
	else  //try items that are in inv by index.
	{
		
	}


	if (bmove < 6)  //a turn fight.
	{

	}
	else if (bmove < 11) //rest turn amount.
	{

	}
	else  //try items that are in inv by index.
	{
		
	}
}