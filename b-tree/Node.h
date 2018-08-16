#ifndef _NODE_INCLUDED_

#define _NODE_INCLUDED_
#include "Info.h"
#include <iostream>

using namespace std;

class Node
{
    public:
        Node(unsigned int);
        void addInfo(Info*);
        Node** getChildren();
        string preorder();
        string inorder();
        string postorder();
        friend ostream& operator<<(ostream& os, const Node& dt);

    private:
        Info** infoArr;
        Node** ptrArr;
        unsigned int order;
        unsigned int elements;
};

#endif
