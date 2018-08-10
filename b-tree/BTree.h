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
        ostream& operator<< (ostream& os);
        void add(Info* i);

    private:
        Node* root;
        unsigned int n;
};

#endif
