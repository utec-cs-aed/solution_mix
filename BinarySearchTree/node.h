#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename T>
struct NodeBT {
    T data;
    NodeBT* left; 
    NodeBT* right;
    NodeBT() : left(nullptr), right(nullptr) {}   
    NodeBT(T value) : data(value), left(nullptr), right(nullptr) {}   
};

#endif