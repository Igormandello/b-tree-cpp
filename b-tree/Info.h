#ifndef _INFO_INCLUDED_

#define _INFO_INCLUDED_
#include <iostream>

using namespace std;

class Info
{
    public:
        virtual int compareTo(Info*) = 0;
};

#endif
