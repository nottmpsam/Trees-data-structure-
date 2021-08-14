#ifndef BT_H
#define BT_H
#include "node.h"
#include "paint.h"
#include <QPainter>

class Node;
class BinaryTree
{
public:

    virtual void addValue(int);
    BinaryTree(int*, int);
    BinaryTree();
    BinaryTree(BinaryTree&);
    ~BinaryTree();

    virtual int searchMin() const;
    virtual int searchMax() const;
    virtual bool deleteValue(int);
    bool is_ValueInTree(int key, Node* pr = nullptr);
    void displayTree(Node*, int) const;
    void levelTrip(Node* node) const;
    bool is_Empty() const;
    bool deleteTree();
    Node* getRoot() const
    {
        return root;
    }
    void lkrTrip (Node*) const;
    void rklTrip(Node*) const;
    int searchHeight(Node* node);
    virtual Node* private_SearchValue(int key, Node* pr);
protected:
    Node* root;
    virtual void private_deleteV2(Node* node, bool checkDirection);
    virtual void private_deleteV1(Node* node, bool checkDirection);
    void private_deleteRoot();
    virtual void private_addValue(int localVariable, Node* pr);
    int private_searchMax(Node* pr, int _current) const;
    int private_searchMin (Node* pr, int _current) const;
    void private_copyTree(Node* fr,Node* to, bool);
    bool private_deleteTree(Node* node);
    Node* private_createWithArray(int*, int, Node* = nullptr);
    BinaryTree& operator=(const BinaryTree&  temp);
};

#endif // BT_H
