#ifndef _NODE_INCLUDED_

#define _NODE_INCLUDED_
#include "Info.h"

class Node
{
    public:
        Node(int);
        void addInfo(Info*);
        int canAdd(Info*);

    private:
        Info** infoArr;
        Node** ptrArr;
        int order;
}

#endif
