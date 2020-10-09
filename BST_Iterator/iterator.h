#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>
#include <utility>

template <typename T>
class Iterator {
    public:
        enum Type {
            PreOrder, InOrder, PostOrder
        };
    private:
        NodeBT<T>* current;
        StackList<NodeBT<T>*> stack;        
        Type type;
      
    public:
        Iterator(): current(nullptr), type(InOrder) {};
        Iterator(NodeBT<T>* node, Type type=InOrder): type(type) {
            switch(this->type){
                case InOrder:{
                    if(node){
                        while(node){
                            this->stack.push(node);
                            node = node->left;
                        }
                        current = this->stack.top();
                    }else current = nullptr;
                    break;
                }
                case PreOrder:{
                    if(node){
                        this->stack.push(node);
                        current = this->stack.top();
                    }else current = nullptr;
                    break;
                }
                case PostOrder:{
                    if(node){
                        std::stack<NodeBT<T>*> aux;
                        NodeBT<T>* topNode = nullptr;
                        this->stack.push(node);
                        while(!this->stack.empty()){
                            topNode = this->stack.top();
                            this->stack.pop();
                            aux.push(topNode);
                            if(topNode->left) this->stack.push(topNode->left);
                            if(topNode->right) this->stack.push(topNode->right);
                        }
                        current = aux.top();
                        this->stack = aux;
                    }else current = nullptr;
                    break;
                }
            }
        };
             
        Iterator<T>& operator=(Iterator<T> other){
            this->current = other->current;
            this->stack = other.stack;
            return (*this);
        }
        bool operator!=(Iterator<T> other){
            return this->current != other.current;
        }
        T operator*(){
            if(this->current) return this->current->data;
            throw std::out_of_range("Current is NULL");
        }
        Iterator<T>& operator++(){
            if(this->stack.empty()) throw std::out_of_range("It's not possible");
            NodeBT<T>* topNode = this->stack.top();
            this->stack.pop();
            switch(this->type){
                case InOrder:{
                    if(topNode->right){
                        this->stack.push(topNode->right);
                        while(this->stack.top()->left) 
                            this->stack.push(this->stack.top()->left);
                    }
                    break;        
                }
                case PreOrder:{
                    if(topNode->right) this->stack.push(topNode->right);
                    if(topNode->left) this->stack.push(topNode->left);
                    break;
                }
                case PostOrder:{
                    break;
                }
            }
            this->current = this->stack.empty() ? nullptr : stack.top();
            return *this;
        }
};  

#endif