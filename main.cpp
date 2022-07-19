#include "Rand.h"
#include "Ent.h"
#include <iostream>
using namespace std;




int main()
{
    Rand::initialize();
    Ent *a;
    a = &Ent(true, false, false, 0, 0);
    Ent *b;
    b = &Ent(true, false, false, 0, 1);
    a->feedFoward(b);
    b->feedFoward(a);
    
}


