#include "Ent.h"

Ent::Ent(int hp, int def, int atc, int spe, int sta, bool ai, bool ex) : AI(ai), LVL(0), external(ex)
{
    setHP(hp);
    setDEF(def);
    setATC(atc);
    setSPE(spe);
    if (ai)
    {
        for (int i = 0;i < 100; i++)
        {
            nodes.push_back(Rand::getRand(0.00, 1.00));
        }
    }
}

void Ent::printStats()
{
    cout << "HP: " << getHP() << endl;
    cout << "DEF: " << getDEF() << endl;
    cout << "ATC: " << getATC() << endl;
    cout << "SPE: " << getSPE() << endl;
    cout << "\n\n" << endl;
}

int Ent::getAI(Ent *a, Ent *b)
{
    nodes[0] = (double)a->getHP();
    nodes[1] = (double)a->getDEF();
    nodes[2] = (double)a->getATC();
    nodes[3] = (double)a->getSPE();
    
    nodes[4] = (double)b->getHP();
    nodes[5] = (double)b->getDEF();
    nodes[6] = (double)b->getATC();
    nodes[7] = (double)b->getSPE();
    
    int startL = 10;
    int endL = 19;
    int startN = 0;
    int endN = 9;

    for (int j = 0; j < 10; j++)
    {
        for (int i = startL;i < endL;i ++)
        {
            double w = nodes[i];
            nodes[i] = 0.00;
            for (int n = startN; n < endN; n++)
            {
               nodes[i] += nodes[n];
            } 
            nodes[i] *= w;
        }
        startL += 10;
        endL += 10;
        startN += 10;
        endN += 10;
    }

    return (int)nodes[99];
}