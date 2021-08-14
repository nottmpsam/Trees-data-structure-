#ifndef SEARCHTREE_H
#define SEARCHTREE_H
#include "binarytree.h"
class SearchTree:public BinaryTree
{
public:
    void addValue(int) override;
    int searchMin() const  override;
    int searchMax() const override;
    SearchTree();
    SearchTree(int*a, int n);
protected:
    Node* private_SearchValue(int key, Node* pr) override;
    void private_addValue(int localVariable, Node* pr) override;
};

#endif // SEARCHTREE_H
