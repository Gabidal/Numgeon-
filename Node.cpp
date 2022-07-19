#include "Node.h"

Node::Node(double in)
{
    Bias = 1;
    ownWeight = Rand::getRand(-0.30, 1.30);

}