#include "binarytree.h"
#include <iostream>
#include <climits>

int BinaryTree::searchHeight(Node* node)
{
    int ll, rr, height = 0;
    if (node)
    {
        ll = searchHeight(node->left);
        rr = searchHeight(node->right);
        height = ((ll > rr) ? ll : rr)+ 1;
    }
    return height;
}
BinaryTree& BinaryTree::operator=(const BinaryTree& node)
{
    if (this != &node)
    {
        if (node.is_Empty())
        {
            root = nullptr;
        }
        else
        {
            deleteTree();
            root = new Node(node.getRoot()->getValue());
            private_copyTree(root, node.getRoot()->left, true);
            private_copyTree(root,node.getRoot()->right,false);
        }
    }
    return *this;
}

bool BinaryTree::is_Empty() const
{
    return root == nullptr;
}

bool BinaryTree::private_deleteTree(Node*node)
{
    if (node)
    {
        private_deleteTree(node->left);
        private_deleteTree(node->right);
        delete node;
    }
    return true;
}

BinaryTree::~BinaryTree()
{
    deleteTree();
}

bool BinaryTree::deleteTree()
{
    if (!is_Empty())
    {
        private_deleteTree(getRoot()->left);
        private_deleteTree(getRoot()->right);
        delete root;
    }
    root = nullptr;
    return true;
}

void BinaryTree::private_copyTree(Node*tt, Node*node, bool flag)
{
    if (node)
    {
        Node* temp = new Node(node->getValue (),tt);
        flag ? tt->left = temp : tt->right = temp;
        private_copyTree(temp,node->left ,true);
        private_copyTree(temp,node->right, false);
    }
}

BinaryTree::BinaryTree(BinaryTree& node)
{
    if (node.is_Empty())
    {
        root = nullptr;
    }
    else
    {
        root = new Node(node.getRoot()->getValue());
        private_copyTree(root, node.getRoot()->left, true);
        private_copyTree(root,node.getRoot()->right,false);
    }

}

int BinaryTree::private_searchMin(Node*pr,int _current) const
{
    if (pr->getValue() < _current)
        _current = pr->getValue();
    if (pr->left)
        _current = private_searchMin(pr->left, _current);
    if (pr->right)
        _current = private_searchMin(pr->right, _current);
    return _current;
}
int BinaryTree::searchMin() const
{
    if (!is_Empty())
        return private_searchMin(root, getRoot()->getValue());
    return INT_MAX;
}
int BinaryTree::private_searchMax(Node* pr, int _current) const
{
    if (pr->getValue() > _current)
        _current = pr->getValue();
    if (pr->left)
        _current = private_searchMax(pr->left, _current);
    if (pr->right)
        _current = private_searchMax(pr->right, _current);
    return _current;
}
int BinaryTree::searchMax() const
{
    if (!is_Empty())
        return private_searchMax(root, getRoot()->getValue());
    return INT_MIN;
}
Node* BinaryTree::private_createWithArray(int*a, int n, Node* node)
{
    static int i = 0;
    Node* temp = new Node(a[i++],node);
    int nl = (n-1)/2;
    int nr = n-1-nl;
    if (nl) {
        temp->left = private_createWithArray(a, nl, temp);
    }
    if (nr) {
        temp->right = private_createWithArray(a, nr, temp);
    }
    return temp;
}
Node* BinaryTree::private_SearchValue(int localVariable, Node* pr)
{
    Node* node = nullptr;
    if (pr->getValue() == localVariable)
    {
        return pr;
    }
    if (pr->left) node = private_SearchValue(localVariable, pr->left);
    if (node) return node;
    if (pr->right) node = private_SearchValue(localVariable,pr->right);
    return node;
}
bool BinaryTree::is_ValueInTree(int localVariable, Node* pr)
{
    bool flag = false;
    if (is_Empty())
        return flag;
    if (!pr && root)
    {
        if (getRoot()->getValue() == localVariable)
            return !flag;
        if (getRoot()->left)
            flag = is_ValueInTree(localVariable, getRoot()->left);
        if (flag)
            return flag;
        if (getRoot()->right)
            flag = is_ValueInTree(localVariable, getRoot()->right);
        return flag;
    }
    if (pr->getValue() == localVariable)
        return !flag;
    if (pr->left)
        flag = is_ValueInTree(localVariable, pr->left);
    if (flag)
        return flag;
    if (pr->right)
        flag = is_ValueInTree(localVariable, pr->right);
    return flag;
}
BinaryTree::BinaryTree(int*a, int n)
{
    root = private_createWithArray(a,n);
}
BinaryTree::BinaryTree()
{
    root = nullptr;
}
void BinaryTree::addValue(int localVariable)
{
    if (is_Empty())  {
        root = new Node(localVariable);
        return;
    }
    private_addValue(localVariable, root);
}
void BinaryTree::private_addValue(int localVariable, Node* pr)
{
    if (!pr->left) {
        pr->left = new Node(localVariable, pr);
        return;
    }
    if (!pr->right) {
        pr->right = new Node(localVariable, pr);
        return;
    }
    switch (rand() % 2)
    {
        case 0 : private_addValue(localVariable, pr->left);
        break;
        case 1 : private_addValue(localVariable, pr->right);
    }
}
void BinaryTree::rklTrip(Node* c) const
{
    if (c->right)
        rklTrip(c->right);
    std::cout << c->getValue() << std::endl;
    if (c->left)
        rklTrip(c->left);
}
struct elem
{
    Node* node;
    elem * next;
    elem(Node* _p, elem*_next = nullptr)
    {
        node = _p;
        next = _next;
    }
};
void BinaryTree::levelTrip(Node* _root) const
{
    if (!_root)
        return;
    elem* f = new elem(_root);
    elem* c = f;
    while (c)
    {
        elem* newElem = nullptr;
        if (c->node->left)
        {
            newElem = new elem(c->node->left);
        }
        if (c->node->right)
        {
            if (newElem) {
                newElem->next = new elem(c->node->right);
            } else {
                newElem = new elem(c->node->right);
            }
        }
        if (newElem)
        {
            elem* node = c;
            while(node->next)
            {
                node = node->next;
            }
            node->next = newElem;
        }
        std::cout << c->node->getValue() << std::endl;
        c = c->next;
    }
    while (f)
    {
        c = f;
        f = f->next;
        delete c;
    }
}

void BinaryTree::lkrTrip(Node* c) const
{
    if (c->left)
        lkrTrip(c->left);
    std::cout << c->getValue()<< std::endl;
    if (c->right)
        lkrTrip(c->right);
}

void BinaryTree::displayTree(Node*c, int level) const
{
    if (c)
    {
        displayTree(c->right, level + 3);
        for (int i = 0; i < level; ++i)
            std::cout << " ";
        std::cout << c->getValue() << std::endl;
        displayTree(c->left, level + 3);
    }
}
void BinaryTree::private_deleteV1(Node*node, bool checkDirection)
{
    if (!node->left && !node->right)
    {

        checkDirection ? node->pr->left = nullptr : node->pr->right = nullptr;
        return;
    }
    if (checkDirection)
    {
        if (node->left)
        {
            node->pr->left = node->left;
            node->left->pr = node->pr;
        }
        else
        {
            node->pr->left = node->right;
            node->right->pr = node->pr;
        }
    }
    else
    {
        if (node->left)
        {
            node->pr->right = node->left;
            node->left->pr = node->pr;
        }
        else
        {
            node->pr->right = node->right;
            node->right->pr = node->pr;
        }
    }
}
void BinaryTree::private_deleteV2(Node* node, bool checkDirection)
{
    Node*qNode = node->right;
    if (!qNode->left)
    {
        qNode->left = node->left;
        qNode->pr = node->pr;
        node->left->pr = qNode;
    }  else {
        while (qNode->left) qNode = qNode -> left;
        private_deleteV1(qNode,qNode->pr->left == qNode);
        qNode->pr = node->pr;
        qNode->left = node->left;
        qNode->right = node->right;
        qNode->left->pr = qNode;
        qNode->right->pr =qNode;
    }
    checkDirection ? node->pr->left = qNode : node->pr-> right = qNode;
}
bool BinaryTree::deleteValue(int localVariable)
{
    if (!is_Empty())
    {
        Node* node = private_SearchValue(localVariable, getRoot());
        if (node == getRoot())
        {
            private_deleteRoot();
        }
        else
        {
            if (node)
            {
                bool checkDirection = (node->pr->left == node ? true : false);
                if (node->left && node->right)
                {
                    private_deleteV2(node, checkDirection);
                }
                else
                {
                    private_deleteV1(node, checkDirection);
                }
                return true;
            }
        }
    }
    return false;
}
void BinaryTree::private_deleteRoot()
{

    Node*node = root;
    if (!node->left && !node->right)
    {
        delete root;
        root = nullptr;
        return;
    }
    Node*qNode = node->right;
    if (qNode) {
        if (qNode->left) {
            while (qNode->left) qNode = qNode->left;
            if (qNode->right) {
                qNode->pr->left = qNode->right;
                qNode->right->pr = qNode->pr;
            } else {
                qNode->pr->left = nullptr;
            }
        } else {
            if (qNode->right) {
                qNode->pr->right = qNode->right;
                qNode->right->pr = qNode->pr;
            } else {
                qNode->pr->right = nullptr;
            }
        }
        getRoot()->getValue() = qNode->getValue();
        delete qNode;
        return;
    }
    qNode = node->left;
    if (qNode)
    {
        if (qNode->right) {
            while (qNode->right) qNode = qNode->right;
            if (qNode->left) {
                qNode->pr->right = qNode->left;
                qNode->left->pr = qNode->pr;
            } else {
                qNode->pr->right = nullptr;
            }
        } else {
            if (qNode->left)
            {
                qNode->pr->left = qNode->left;
                qNode->left->pr = qNode->pr;
            }
            else
            {
                qNode->pr->left = nullptr;
            }
            }
        getRoot()->getValue() = qNode->getValue();
        delete qNode;
    } else {
        delete root;
        root = nullptr;
    }

}
