#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>
using namespace std;

class Matrix
{
public:
    Matrix(vector<vector <double> > *m);
    vector<vector <double> > getMatrix() {return matrix;}
    void mulMatrix(vector<vector <double> > *a, vector<vector <double> > *b, vector<vector <double> > *c);
    double getChild(int i, int j);

private:
    vector<vector <double> > matrix;
    int x;
    int y;
};


#endif