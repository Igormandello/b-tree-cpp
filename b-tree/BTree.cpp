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
        this->root = i;
}

ostream& BTree::operator<<(ostream& os)
{
    os << '{' << this.n << '}';
}
