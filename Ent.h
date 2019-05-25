#ifndef _ENT_H_
#define _ENT_H_

#include "Rand.h"
#include "Matrix.h"
#include <vector>
using namespace std;

class Ent
{
public:
    Ent(bool ai, bool block, bool alive, int x, int y);
    Ent *getEnt() {return this;}
    void getStats(Ent *e, vector<vector <double> > *modable, int x, int y);
    void feedFoward(Ent *e);
    void initializeNN(Ent *e);

private:
    bool AI;
    bool Block;
    bool Alive;
    int ID;
    int HP;
    int DEF;
    int ATC;
    int SPE;
    int STA;
    int X;
    int Y;

    vector<vector <double> > *Nodes;
    vector<vector <double> > *Weights;
    Matrix *m = &Matrix(Nodes);
};



#endif