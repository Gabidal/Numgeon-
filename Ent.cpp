#include "Ent.h"

Ent::Ent(int hp, int def, int atc, int spe, int sta, bool ai, bool ex) : AI(ai), LVL(0), external(ex), STA(sta)
{
    setHP(hp);
    setDEF(def);
    setATC(atc);
    setSPE(spe);
    if (ai)
    {
        for (int x = 0; x < 5; x++)
        {
            weights.push_back(vector<vector<double>>());
            nodes.push_back(vector<double>());

            for (int y = 0; y < 10; y++)
            {
                weights[x].push_back(vector<double>());
                nodes[x].push_back(0.0);

                for (int z = 0; z < 10; z++)
                {
                    weights[x][y].push_back(Rand::getRand(0.01, 1.30));
                }
            }
        }
    }
}

void Ent::printStats()
{
    cout << "HP: " << getHP() << endl;
    cout << "DEF: " << getDEF() << endl;
    cout << "ATC: " << getATC() << endl;
    cout << "SPE: " << getSPE() << endl;
    cout << "STA: " << getSTA() << endl;
    cout << "\n\n" << endl;
}

int Ent::getAI(Ent *a, Ent *b)
{
    clear();

    nodes[0][0] = (double)a->getHP() / 100.0;
    nodes[0][1] = (double)a->getDEF() / 100.00;
    nodes[0][2] = (double)a->getATC() / 100.0;
    nodes[0][3] = (double)a->getSPE() / 100.0;
    nodes[0][4] = (double)a->getSTA() / 100.0;
    
    nodes[0][5] = (double)b->getHP() / 100.00;
    nodes[0][6] = (double)b->getDEF() / 100.00;
    nodes[0][7] = (double)b->getATC() / 100.00;
    nodes[0][8] = (double)b->getSPE() / 100.0;
    nodes[0][9] = (double)b->getSTA() / 100.0;


    for (int x = 0; x < 5 - 1; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            double value = nodes[x][y];

            for (int ny = 0; ny < 10; ny++)
            {
                double weight = weights[x][y][ny];
                nodes[x + 1][ny] += value * weight;
            }

            for (int ny = 0; ny < 10; ny++)
            {
                nodes[x + 1][ny] = tanh(nodes[x + 1][ny]);
            }
        }
    }

    double sum = 0.0;

    for (int i = 0; i < 10; i++)
    {
        sum += nodes[4][i];
    }
    
    sum /= 10.0;
    sum *= 20.0;

    return (Rand::getRand(-1, 21));
}

void Ent::clear()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        nodes[i][j] = 0;
    }
}

void Ent::useItem(int i)
{
    Item *item = items.at(i);
    setHP(getHP() + item->affectHP);
    setDEF(getDEF() + item->affectDEF);
    setATC(getATC() + item->affectATC);
    setSPE(getSPE() + item->affectSPE);
    setSTA(getSTA() + item->affectSTA);
    items.erase(items.begin() + i);
}