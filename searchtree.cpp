#include "searchtree.h"

SearchTree::SearchTree()
{
    root = nullptr;
}
SearchTree::SearchTree(int*a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        addValue(a[i]);
    }
}
int SearchTree::searchMin() const
{
    Node* temp = getRoot();
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->getValue();
}
int SearchTree::searchMax() const
{
    Node* temp = getRoot();
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->getValue();
}
Node* SearchTree::private_SearchValue(int key, Node* pr)
{
    Node* temp = nullptr;
    if (pr)
    {
        if (pr->getValue() == key)
        {
            return pr;
        }
        if (pr->getValue() > key)
        {
           temp =  private_SearchValue(key, pr->left);
        }
        if (temp) {
            return temp;
        }
        else
        {
            temp = private_SearchValue(key, pr->right);
        }
    }
    return temp;
}
void SearchTree::private_addValue(int localVariable, Node* pr)
{
    if (pr->getValue() >= localVariable)
    {
        if (!pr->left)
        {
            pr->left = new Node(localVariable, pr);
        }
        else
        {
            private_addValue(localVariable, pr->left);
        }
    }
    else
    {
        if (!pr->right)
        {
            pr->right = new Node(localVariable, pr);
        }
        else
        {
            private_addValue(localVariable, pr->right);
        }
    }
}
void SearchTree::addValue(int localVariable)
{
    if (is_Empty())
    {
        root = new Node(localVariable);
        return;
    }
    private_addValue(localVariable, getRoot());
}
