#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename T>
struct Node {
    T* keys;
    Node* child; 
    bool isLeaf;
    int count;    
};

#endif