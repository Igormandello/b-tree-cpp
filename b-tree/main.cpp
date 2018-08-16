#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include "MyInfo.h"
#include "BTree.h"

using namespace std;

int main()
{
    try
    {
        BTree* tree = new BTree(2);

        int n;
        scanf("%i", &n);
        while (n != 1337)
        {
            MyInfo* i = new MyInfo(n);
            tree->add(i);

            cout << "Pre order: " << tree->preorder();
            cout << "In order: " << tree->inorder();
            cout << "Post order: " << tree->postorder();
            cout << endl;
            scanf("%i", &n);
        }
    }
    catch (invalid_argument err)
    {
        cerr << err.what();
    }

    return 0;
}
