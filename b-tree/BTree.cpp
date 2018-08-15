#include <iostream>
#include "Info.h"
#include "BTree.h"

BTree::BTree(unsigned int n)
{
    this->n = n;
    this->root = NULL;
}

void BTree::add(Info* i)
{
    if (this->root == NULL)
        this->root = new Node(this->n);

    this->root->addInfo(i);
}

ostream& operator<<(ostream& os, const BTree& tree)
{
    os << tree.n;
    return os;
}
