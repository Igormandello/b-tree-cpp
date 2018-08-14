#ifndef _MYINFO_INCLUDED_

#define _MYINFO_INCLUDED_
#include "Info.h"

class MyInfo : public Info
{
    public:
        MyInfo(int);
        int compareTo(Info*);
        int getInfo();
        void print(ostream&);

    private:
        int info;
};

#endif
