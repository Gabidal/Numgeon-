#include "Matrix.h"


Matrix::Matrix(vector<vector <double> > *m)
{
    matrix = *m;
}

void Matrix::mulMatrix(vector<vector <double> > *a, vector<vector <double> > *b, vector<vector <double> > *c)
{
    
    for (int ay = 0; ay < a->size(); ay++)
    {
        for (int ax = 0; ax < a->at(ay).size(); ax++)
        {
            for (int bx = 0; bx < b->size(); bx++)
            {
                for (int by = 0; by < b->at(bx).size(); by++)
                {
                    matrix.at(ax).at(ay) = a->at(ax).at(ay) * b->at(bx).at(by);
                }
            }
        }
    }
}

double Matrix::getChild(int i, int j)
{
    double a = matrix.at(i).at(j);
    return a;
}