#ifndef _ENT_H_
#define _ENT_H_

#include <iostream>
#include <vector>
#include "Rand.h"
#include "Item.h"
using namespace std;

class Ent 
{
public:
    Ent(int hp, int def, int atc, int spe, int STA, bool ai, bool ex);
    ~Ent();
    void setHP(int h) { HP = h;}
    int getHP() { return HP;}
    void setDEF(int d) { DEF = d;}
    int getDEF() { return DEF;}
    void setATC(int a) { ATC = a;}
    int getATC() { return ATC;}
    void setSPE(int s) { SPE = s;}
    int getSPE() { return SPE;}
    void setName(const char *n) { name = n;}
    const char *getName() { return name;}
    void setSTA(int sta) { STA = sta;}
    int getSTA() { return STA;}
    void nextLVL(int l) { LVL += l;}
    int getLVL() { return LVL;}
    void setFIT(int fit) { FIT = fit;}
    int getFIT() { return FIT;}
    void addItem(Item *i) { items.push_back(i);}
    void useItem(int i);
    void printStats();
    bool isAI() { return AI;}
    int getAI(Ent *a, Ent *b);
    void setEx(bool *ex) { external = ex;}
    bool getEx() { return external;}
    void clear();
    public:
    vector<int> moves;
    vector<vector<double>> nodes;
    vector<vector<vector<double>>> weights;
    vector<Item*> items;

private:
    const char *name;
    int HP;
    int DEF;
    int ATC;
    int SPE;
    int STA;
    int LVL;
    int FIT;
    bool AI;
    bool external;
};

#endif
