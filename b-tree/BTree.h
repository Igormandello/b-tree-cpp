#ifndef _BTREE_INCLUDED_

#define _BTREE_INCLUDED_
#include <iostream>
#include "Node.h"
#include "Info.h"

using namespace std;

class BTree
{
    public:
        BTree(unsigned int n);
        void add(Info* i);
        friend ostream& operator<<(ostream& os, const BTree& dt);
        string preorder();
        string inorder();
        string postorder();

    private:
        Node* root;
        unsigned int n;
};

#endif
