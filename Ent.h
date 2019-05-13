#ifndef _ENT_H_
#define _ENT_H_

#include <iostream>
#include <vector>
#include "Rand.h"
using namespace std;

class Ent 
{
public:
    Ent(int hp, int def, int atc, int spe, bool ai, bool ex);
    ~Ent();
    void setHP(int h) { HP = h;}
    int getHP() { return HP;}
    void setDEF(int d) { DEF = d;}
    int getDEF() { return DEF;}
    void setATC(int a) { ATC = a;}
    int getATC() { return ATC;}
    void setSPE(int s) { SPE = s;}
    int getSPE() { return SPE;}
    void setName(char *n) { *name = *n;}
    char *getName() { return name;}
    void printStats();
    bool isAI() { return AI;}
    int getAI(Ent *a, Ent *b);
    void setEx(bool *ex) { external = ex;}
    bool getEx() { return external;}
private:
    char name[20];
    int HP;
    int DEF;
    int ATC;
    int SPE;
    bool AI;
    bool external;
    vector<double> nodes;
};

#endif
