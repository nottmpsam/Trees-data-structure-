#ifndef NODE_H
#define NODE_H
#include "binarytree.h"
class Node
{
    int key;
    int blnc;
public:
    Node *left, *right, *pr;
    Node(int _key, Node* _pr = nullptr, Node* _right = nullptr, Node* _left = nullptr);
    int& getValue();
    int& getBlnc();
    friend class BinTree;
};


#endif // NODE_H
