#include "node.h"

Node::Node(int _key, Node* _pr, Node* _right, Node* _left)
{
        key = _key;
        pr = _pr;
        left = _left;
        right = _right;
        blnc = 0;
}
int& Node::getValue()
{
    return key;
}

int& Node::getBlnc()
{
        return blnc;
}
