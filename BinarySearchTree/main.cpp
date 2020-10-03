#include <iostream>
#include "bst.h"
using namespace std;

int main(int argc, char const *argv[])
{
    BSTree<int> *bstree = new BSTree<int>();
    int val, ns;
    bstree->insert(20);
    bstree->insert(15);
    bstree->insert(8);
    bstree->insert(25);
    bstree->insert(18);
    bstree->insert(30);
    bstree->insert(28);

    char option = argv[1][0];

    switch (option)
    {
    case '1':
        bstree->displayInOrder();
        break;
    case '2':
        bstree->displayPreOrder();
        break;
    case '3':
        bstree->displayPostOrder();
        break;
    case '4':
        cout << bstree->height();
        break;
    case '5':
        cout << bstree->minValue();
        break;
    case '6':
        cout << bstree->maxValue();
        break;
    case '7':
        cout << bstree->isBalanced();
        break;
    case '8':
        cout << bstree->size();
        break;
    case '9':
        ns = bstree->size();
        bstree->remove(bstree->minValue());
        bstree->remove(bstree->maxValue());
        cout << ns - bstree->size();
        break;
    default:
        cout << "option not found";
        break;
    }
    cout<<endl;
}
