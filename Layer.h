#ifndef _LAYER_H_
#define _LAYER_H_

#include <vector>
#include "Node.h"
using namespace std;

class Layer
{
public:
    Layer(int size);
    vector<Node*> layer;
private:
};

#endif