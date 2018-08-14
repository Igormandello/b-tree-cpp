#include <stdlib.h>
#include "Node.h"

Node::Node(unsigned int n)
{
    this->order = n;
    this->elements = 0;

    this->infoArr = (Info**) malloc((n - 1) * sizeof(Info*));
    this->ptrArr = (Node**) malloc(n * sizeof(Node*));
}

void Node::addInfo(Info* i)
{
    if (this->elements < this->order - 1)
    {
        bool added = false;
        for (int n = 0; n < this->elements; n++)
        {
            if (this->infoArr[n]->compareTo(i) > 0)
            {
                for (int i = this->elements - 1; i >= n; i--)
                    this->infoArr[i] = this->infoArr[i - 1];

                added = true;
                this->infoArr[n] = i;
                break;
            }
        }

        if (!added)
            this->infoArr[this->elements] = i;

        this->elements++;
    }
}

ostream& operator<<(ostream& os, const Node& node)
{
    os << '[';
    if (node.elements > 0)
        node.infoArr[0]->print(os);

    for (int n = 1; n < node.elements; n++)
    {
        os << ", ";
        node.infoArr[0]->print(os);
    }

    os << ']';

    return os;
}
