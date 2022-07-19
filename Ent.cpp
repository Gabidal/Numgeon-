#include "Ent.h"

Ent::Ent(bool ai, bool block, bool alive, int x, int y)
{
    AI = ai;
    Block = block;
    Alive = alive;
    if (ai)
    {
        for(int i = 0; i< Rand::getRand(3, 9); i++)
        {
            for(int j = 0; j < Rand::getRand(20, 60);j++)
            {
                Nodes->at(i).at(j) = 1.00;
                Weights->at(i).at(j) = Rand::getRand(-0.30, 1.30);
            }
        }
    }
    if (block)
    {
        SPE = 0;
    }
    if (alive)
    {
        ATC = 1;
    }
}

void Ent::getStats(Ent *e, vector<vector <double> > *modable, int x, int y)
{
    modable->at(0+x).at(0+y) += e->ID;
    modable->at(0+x).at(1+y) += e->HP;
    modable->at(0+x).at(2+y) += e->DEF;
    modable->at(0+x).at(3+y) += e->ATC;
    modable->at(0+x).at(4+y) += e->SPE;
    modable->at(0+x).at(5+y) += e->STA;
    modable->at(0+x).at(7+y) += e->X;
    modable->at(0+x).at(8+y) += e->Y;
}

void Ent::feedFoward(Ent *e)
{
    initializeNN(e);
    m->mulMatrix(Nodes, Weights, Nodes);
}

void Ent::initializeNN(Ent *e)
{
    //give the input nodes the input.
    getStats(this, Nodes, 0, 0);
    //opposites stats as well
    getStats(e, Nodes, 0, 9);
}