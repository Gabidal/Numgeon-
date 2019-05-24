#ifndef _NODE_H_
#define _NODE_H_
#include <vector>
#include "Rand.h"
using namespace std;
class Node
{
public:
    Node(double in);
    double activate(double in);
    double returnVal() { return holdedValue;}
    vector<double> connectedWeights;
    vector<double> connectedNodes;
    double Bias;
    double ownWeight;
    double holdedValue;
};

#endif