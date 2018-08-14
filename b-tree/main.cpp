#include <iostream>
#include "MyInfo.h"
#include "BTree.h"

using namespace std;

int main()
{
    MyInfo* i = new MyInfo(1);
    MyInfo* i2 = new MyInfo(2);

    Node* n = new Node(3);
    n->addInfo(i2);
    cout << *n;
    n->addInfo(i);
    cout << *n;

    return 0;
}
