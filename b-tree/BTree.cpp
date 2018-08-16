#include <iostream>
#include <cmath>
#include <queue>
#include "Info.h"
#include "BTree.h"

BTree::BTree(unsigned int n)
{
    this->n = n;
    this->root = NULL;
}

void BTree::add(Info* i)
{
    if (this->root == NULL)
        this->root = new Node(this->n);

    this->root->addInfo(i);
}

ostream& operator<<(ostream& os, const BTree& tree)
{
    if (tree.root == NULL)
        return os;

    int actualDepth = 0, qtd = 0;

    queue<Node*> sequence;
    sequence.push(tree.root);
    while (!sequence.empty())
    {
        Node* actual = sequence.front();
        sequence.pop();
        qtd++;

        bool newLine = false;
        if (pow(tree.n, actualDepth) == qtd)
            newLine = true;

        if (actual == NULL)
        {
            os << "{}";
            if (newLine)
            {
                actualDepth++;
                qtd = 0;
                os << endl;
            }

            continue;
        }

        Node** children = actual->getChildren();
        for (int n = 0; n < tree.n; n++)
            sequence.push(children[n]);

        os << *actual;

        if (newLine)
        {
            actualDepth++;
            qtd = 0;
            os << endl;
        }
    }

    return os;
}
