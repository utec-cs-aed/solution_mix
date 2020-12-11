#ifndef BTREE_H
#define BTREE_H
#include "node.h"

using namespace std;

template <typename T>
class BTree{
private:
    Node<T> *root;
    int M;
public:
    BTree() : root(nullptr) {}    
    BTree(int _M) : root(nullptr), M(_M) {}    

    Node* search(Node* node, T key){
        return search(root, key);
    }

    void insert(T key){
        insert(root, key);
    }

private:
    Node* search(Node* node, T key){        
        return nullptr;
    }
    void insert(Node* node, T key){        
        
    }
};

#endif