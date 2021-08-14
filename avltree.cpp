#include "avltree.h"
avlTree::avlTree()
{
    root = nullptr;
}
avlTree::avlTree(int*a, int n)
{
    for (int i = 0; i < n; ++i)
        addValue(a[i]);
}
void avlTree::addValue(int localVariable)
{
    if (is_Empty())
    {
        root = new Node(localVariable);
        return;
    }
    _private_addValue(localVariable, getRoot());
}

bool avlTree::deleteValue(int localVariable)
{
    Node* temp = private_SearchValue(localVariable, getRoot());
    if (!getRoot() || !temp)
    {
        return false;
    }
    Node* toBalance = nullptr;
    if (temp == getRoot())
    {
        Node* qNode = temp->right;
        if (qNode) {
            if (qNode->left) {
            while (qNode->left) qNode = qNode->left;
                getRoot()->getValue() = qNode->getValue();
                if (qNode->right) {
                    qNode->pr->left = qNode->right;
                    qNode->right->pr = qNode->pr;
                } else {
                    qNode->pr->left = nullptr;
                }
                ++qNode->pr->getBlnc();
            } else {
            	getRoot()->getValue() = qNode->getValue();
                if (qNode->right) {
                    qNode->pr->right = qNode->right;
                    qNode->right->pr = qNode->pr;
                } else {
                    qNode->pr->right = nullptr;
                }
                --qNode->pr->getBlnc();
            }
            toBalance = qNode->pr;
            temp = qNode;
        } else if (temp->left) {
            getRoot()->getValue() = temp->left->getValue();
            delete temp->left;
            getRoot()->left = nullptr;
            return true;
        } else {
            delete getRoot();
            root = nullptr;
            return true;
        }
    }
    else if (!temp->left && !temp->right)  
    {
        if (temp->pr->left == temp)
        {
            temp->pr->left = nullptr;
            ++temp->pr->getBlnc();
        }

        else
        {
            temp->pr->right = nullptr;
            --temp->pr->getBlnc(); }
        toBalance = temp->pr;
    }
    else if (temp->left && temp->right)
    {
        Node* qNode = temp->right;
        if (!qNode->left) 
        {
            qNode->left = temp->left;
            temp->left->pr = qNode;
            qNode->pr = temp->pr;
            if (temp->pr->left == temp)
                temp->pr->left = qNode;
            else
                temp->pr->right = qNode;
            qNode->getBlnc() = --temp->getBlnc();
            toBalance = qNode;
        } else
        {
            while (qNode->left) qNode = qNode-> left;
            Node* qq = qNode->pr;
            if (qNode->right) {
                qNode->pr->left = qNode->right;
                qNode->right->pr = qNode->pr;
            } else
            {
                qq->left = nullptr;
            }
            ++qq->getBlnc();
            qNode->pr = temp->pr;
            qNode->left = temp->left;
            qNode->right = temp->right;
            qNode->left->pr = qNode;
            qNode->right->pr = qNode;
            if (qNode->pr->left == temp)
                qNode->pr->left = qNode;
            else
                qNode->pr->right = qNode;
            qNode->getBlnc() = temp->getBlnc();
            toBalance = qq;
        }
    }
    else
    {
        bool checkDirection = temp->pr->left == temp ? true : false;
        if (checkDirection)
        {
            if (temp->left)
            {
                temp->pr->left = temp->left;
                temp->left->pr = temp->pr;
            }
            else
            {
                temp->pr->left = temp->right;
                temp->right->pr = temp->pr;
            }
            toBalance = temp->pr->left;
        }
        else
       {
            if (temp->left)
            {
                temp->pr->right = temp->left;
                temp->left->pr = temp->pr;
            }
            else
            {
                temp->pr->right = temp->right;
                temp->right->pr = temp->pr;
            }
            toBalance = temp->pr->right;
        }
    }
    toBalance = balanceTree(toBalance);
    while (toBalance->getBlnc() == 0)
    {
        if (toBalance->pr) {
            if (toBalance->pr->left == toBalance)
            {
                ++toBalance->pr->getBlnc();
            } else
            {
                --toBalance->pr->getBlnc();
            }
            toBalance = toBalance->pr;
            toBalance = balanceTree (toBalance);
        } else {
            break;
        }
    }
    delete temp;
    return true;

}
Node* avlTree::balanceTree(Node* node)
{
    if (node->getBlnc() == -2)
    {
        if (node->left->getBlnc() >= 1)
        {
            Node* temp = node->left->right; 
            node->getBlnc() = 0;
            node->left->getBlnc() = 0; 
            if (temp->getBlnc() == -1)
            {
                ++node->getBlnc();
            }
            if (temp->getBlnc() == 1)
            {
                --node->left->getBlnc();
            }
            temp->getBlnc() = 0;
            leftRotate(node->left);
            return rightRotate(node);
        }
        else
        {
            if (node->left->getBlnc() == 0 && node->left->left)
            {
                node->left->getBlnc() = 1;
                node->getBlnc() = -1;
            } else
            {
                node->left->getBlnc()= 0;
                node->getBlnc() = 0;
            }
            return rightRotate(node);
        }
    }
    if (node->getBlnc() == 2)
    {
        if (node->right->getBlnc() < 0)
        {
            Node* temp = node->right->left;
            node->getBlnc() = 0;
            node->right->getBlnc() = 0;
            if (temp->getBlnc() == 1)
            {
                --node->getBlnc();
            }
            if (temp->getBlnc() == -1)
            {
                ++node->right->getBlnc();
            }
            temp->getBlnc() = 0;
            rightRotate(node->right);
            return leftRotate(node);
        }
        else
        {
            if (node->right->getBlnc() == 0 && node->right->right)
            {
                node->right->getBlnc() =-1;
                node->getBlnc() = 1;
            } else
            {
                node->right->getBlnc() = 0;
                node->getBlnc() = 0;
            }
            return leftRotate(node);
        }
    }
    return node;
}
void avlTree::display_avlTree(Node* c, int level)
{
    if (c)
    {
        display_avlTree(c->right, level + 3);
        for (int i = 0; i < level; ++i)
            std::cout << " ";
        std::cout << c->getValue() << "_" << c->getBlnc() <<  std::endl;
        display_avlTree(c->left, level + 3);
    }
}

Node* avlTree::rightRotate(Node* node)
{
    Node* s = node->left;
    node->left = s->right;
    if (s->right)
        s->right->pr = node;
    s->right = node;
    if (node->pr) {
        node->pr->right == node ? node->pr->right = s : node->pr->left = s;
    } else {
        root = s;
    }
    s->pr = node->pr;
    node->pr = s;
    return s;
}
Node* avlTree::leftRotate(Node* node)
{
    Node*s = node->right;
    node->right = s->left;
    if (s->left)
        s->left->pr = node;
    s->left =  node;
    if (node->pr)
    {
        node->pr->right == node ? node->pr->right = s : node->pr->left = s;
    }
    else {
        root = s;
    }
    s->pr = node->pr;
    node->pr = s;
    return s;
}
void avlTree::fix_height(Node* node)
{
    node->getBlnc() = bl_calculation(node);
}
int avlTree::bl_calculation(Node* node) const
{
    return searchHeight(node->right)-searchHeight(node->left);
}
std::pair<bool,bool> avlTree::_private_addValue(int localVariable, Node *node)
{
    std::pair<bool, bool> res;
    res.first = false;
    res.second = true;
    if (node->getValue() >= localVariable)
    {
        if (!node->left)
        {
            node->left = new Node(localVariable, node);
            res.first = true;
        }
        else
        {
            res =_private_addValue(localVariable, node->left);
        }
    }
    else
    {
        if (!node->right)
        {
            node->right = new Node(localVariable, node);
            res.first = false;
        }
        else
        {
            res = _private_addValue(localVariable, node->right);
        }
    }
    if (res.first)
    {
        if (res.second)
            --node->getBlnc();
        if (node->getBlnc() == 0) {
            res.second = false;
        }
        if (node->getBlnc() == -2)
        {
            balanceTree(node);
            res.second = false;
        }
    } else
    {
        if (res.second)
            ++node->getBlnc();
        if (node->getBlnc() == 0) {
            res.second = false;
        }
        if (node->getBlnc() == 2)
        {
            balanceTree(node);
            res.second = false;
        }
    }
    if (node->pr){
        if (node->pr->left == node)
            res.first = true;
        else
            res.first = false;
    }
    return res;
}
void avlTree::_private_addValue_(int localVariable, Node* node)
{
    if (node->getValue() >= localVariable)

    {
        if (!node->left)
        {
            node->left = new Node(localVariable, node);
        }
        else
        {
            _private_addValue_(localVariable, node->left);
        }
    }
    else
    {
        if (!node->right)
        {
            node->right = new Node(localVariable, node);
        }
        else
        {
            _private_addValue_(localVariable, node->right);
        }
    }
    fix_height(node);
    balanceTree(node);
}
