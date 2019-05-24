#ifndef _ACTION_H_
#define _ACTION_H_

#include "Ent.h"
#include "Item.h"

class Action
{
public:
	Action(Ent *a, Ent *b);
	void setResult(bool r) {result = r;}
	bool getResult() {return result;}
	void fight(Ent *a, Ent *b, int amove);
private:
	bool result;
};

#endif
