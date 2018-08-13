#include "Info.h"
#include "MyInfo.h"

MyInfo::MyInfo(int i)
{
    this->info = i;
}

int MyInfo::compareTo(Info* info)
{
    MyInfo* i = (MyInfo*)info;

    if (this->info > i->info)
        return 1;
    else if (this->info < i->info)
        return -1;

    return 0;
}

int MyInfo::getInfo()
{
    return this->info;
}

ostream& operator<<(ostream& os, const MyInfo& info)
{
    os << info.info;
    return os;
}
