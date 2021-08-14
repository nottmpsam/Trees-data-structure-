#ifndef AVLTREE_H
#define AVLTREE_H
#include "searchtree.h"
#include "node.h"
#include <iostream>
class avlTree: public SearchTree
{
public:
    void display_avlTree(Node*, int);
    void addValue(int localVariable) override;
    bool deleteValue(int localVariable) override;
    avlTree();
    avlTree(int* array, int range);
protected:
    int bl_calculation(Node* node) const;
    void fix_height(Node* node);
    Node* leftRotate(Node* node);
    Node* rightRotate(Node* node);
    Node* balanceTree(Node* node);
    void _private_addValue_(int localVariable, Node* node);
    std::pair<bool,bool> _private_addValue(int key, Node* node);



};
#endif // AVLTREE_H
