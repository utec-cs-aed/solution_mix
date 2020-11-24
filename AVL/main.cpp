#include <iostream>
#include "avl.h"
using namespace std;

int main(int argc, char const *argv[])
{
    AVLTree<int> *bstree = new AVLTree<int>();
    bstree->insert(20);
    bstree->insert(16);
    bstree->insert(2);
    bstree->insert(15);
    bstree->insert(8);
    bstree->insert(14);
    bstree->insert(22);
    bstree->insert(1);
    bstree->insert(25);
    bstree->insert(9);
    bstree->insert(30);
    bstree->insert(19);
    bstree->insert(6);
    bstree->displayPretty();
    cout<<"\n------------\n";
    bstree->remove(8);
    bstree->remove(20);
    bstree->displayPretty();
    cout<<endl;
}
