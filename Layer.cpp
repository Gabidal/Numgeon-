#include "Layer.h"

Layer::Layer(int size)
{
    for (int i = 0; i< size; i++)
    {
        Node *n = new Node();
        layer.push_back(n);
    }
}