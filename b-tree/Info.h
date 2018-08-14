#ifndef _INFO_INCLUDED_

#define _INFO_INCLUDED_
#include <iostream>

using namespace std;

class Info
{
    public:
        virtual int compareTo(Info*) = 0;
        virtual void print(ostream&) = 0;
};

#endif
