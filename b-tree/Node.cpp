#include <sstream>
#include <stdexcept>
#include "Node.h"

using namespace std;

Node::Node(unsigned int n)
{
    this->order = n;
    this->elements = 0;

    this->infoArr = new Info*[n - 1];
    this->ptrArr = new Node*[n];

    for (int i = 0; i < this->order; i++)
        this->ptrArr[i] = NULL;
}

void Node::addInfo(Info* i)
{
    int n = 0;
    for (; n < this->elements; n++)
        if (this->infoArr[n]->compareTo(i) == 0)
            throw std::invalid_argument("Elements cannot be equal");
        else if (this->infoArr[n]->compareTo(i) > 0)
            break;

    if (this->elements == this->order - 1) //The info array is full
    {
        //n is the index of the pointer array
        if (this->ptrArr[n] == NULL)
            this->ptrArr[n] = new Node(this->order);

        this->ptrArr[n]->addInfo(i);
    }
    else //There's space in the info array
    {
        if (n < this->elements) //The array need to be shifted
            for (int j = this->elements; j > n; j--)
                this->infoArr[j] = this->infoArr[j - 1];

        this->infoArr[n] = i;
        this->elements++;
    }
}

void Node::removeInfo(Info* i)
{
    int n = 0;
    for (; n < this->elements; n++)
        if (this->infoArr[n]->compareTo(i) >= 0)
            break;

    if (this->elements == this->order - 1 && !this->isLeaf()) //The info array is full
    {
        cout << "To Do";
    }
    else //The info array isn't full or it's a leaf, so the node can't have children
        if (this->infoArr[n]->compareTo(i) == 0) //The element is what we want to remove
        {
            delete this->infoArr[n];
            this->elements--;

            //Shifts the array
            for (int j = n; j < this->elements; j++)
            {
                cout << j;
                this->infoArr[j] = this->infoArr[j + 1];
            }
        }
}

bool Node::isLeaf()
{
    if (this->elements < this->order - 1)
        return true;

    bool leaf = true;
    for (int n = 0; n < this->order; n++)
        if (this->ptrArr[n] != NULL)
        {
            leaf = false;
            break;
        }

    return leaf;
}

int Node::getInfoAmount()
{
    return this->elements;
}

Node** Node::getChildren()
{
    return this->ptrArr;
}

string Node::preorder()
{
    stringstream ss;
    if (this->elements != this->order - 1) //The info array isn't full, so it can't have any children
        for (int n = 0; n < this->elements; n++)
        {
            this->infoArr[n]->print(ss);
            ss << ", ";
        }
    else
    {
        for (int n = 0; n < this->order - 1; n++)
        {
            this->infoArr[n]->print(ss);
            ss << ", ";

            if (this->ptrArr[n] != NULL)
                ss << this->ptrArr[n]->preorder();
        }

        if (this->ptrArr[this->order - 1] != NULL)
            ss << this->ptrArr[this->order - 1]->preorder();
    }

    return ss.str();
}

string Node::inorder()
{
    stringstream ss;
    if (this->elements != this->order - 1) //The info array isn't full, so it can't have any children
        for (int n = 0; n < this->elements; n++)
        {
            this->infoArr[n]->print(ss);
            ss << ", ";
        }
    else
    {
        for (int n = 0; n < this->order - 1; n++)
        {
            if (this->ptrArr[n] != NULL)
                ss << this->ptrArr[n]->inorder();

            this->infoArr[n]->print(ss);
            ss << ", ";
        }

        if (this->ptrArr[this->order - 1] != NULL)
            ss << this->ptrArr[this->order - 1]->inorder();
    }

    return ss.str();
}

string Node::postorder()
{
    stringstream ss;
    if (this->elements != this->order - 1) //The info array isn't full, so it can't have any children
        for (int n = 0; n < this->elements; n++)
        {
            this->infoArr[n]->print(ss);
            ss << ", ";
        }
    else
    {
        if (this->ptrArr[0] != NULL)
            ss << this->ptrArr[0]->postorder();

        for (int n = 0; n < this->order - 1; n++)
        {
            if (this->ptrArr[n + 1] != NULL)
                ss << this->ptrArr[n + 1]->postorder();

            this->infoArr[n]->print(ss);
            ss << ", ";
        }
    }

    return ss.str();
}

ostream& operator<<(ostream& os, const Node& node)
{
    os << "{ ";
    if (node.elements > 0)
        node.infoArr[0]->print(os);

    for (int n = 1; n < node.elements; n++)
    {
        os << ", ";
        node.infoArr[n]->print(os);
    }

    /*os << "], children: [";
    if (node.ptrArr[0] != NULL)
        os << *node.ptrArr[0];
    else
        os << "{}";

    for (int n = 1; n < node.order; n++)
        if (node.ptrArr[n] != NULL)
            os << ", " << *node.ptrArr[n];
        else
            os << ", {}";

    os << "] }";*/
    os << " }";
    return os;
}
