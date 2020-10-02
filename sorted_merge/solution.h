#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// TODO: implement here

void push_front(Node* &head, int val) {
    Node* nodo = new Node();
    nodo->data = val;
    nodo->next = head;
    head = nodo;
}

void push_back(Node* &head, int val) {
    Node* nodo = new Node();
    nodo->data = val;
    if (head == nullptr) {
        head = nodo;
        return;
    }
    Node* temp = head;
    while(temp->next != nullptr) 
        temp = temp->next;    
    temp->next = nodo;
    nodo->next = nullptr;
}

Node* reverse(Node* head) {
    Node* temp = head;
    Node* rev = nullptr;
    while(temp!=nullptr) {
        push_front(rev, temp->data);
        temp = temp->next;
    }
    return rev;
}
// L1:  3 -> 5 -> 7 -> null
//                     t1
// L2:  4 -> 5 -> 6 ->10 -> 15 -> null
//                    t2
// L3:  15 -> 10 -> 7 -> 6 -> 5 -> 5 -> 4 -> 3 
Node* SortedMergeRec(Node* l1, Node* l2) {
    // caso base    
    if(l1 == nullptr) 
        return l2;
    if(l2 == nullptr)   
        return l1;
    // caso recursivo
    if(l1->data < l2->data)
    {
        l1->next = SortedMergeRec(l1->next, l2);
        return l1;
    } else {
        l2->next = SortedMergeRec(l1, l2->next);
        return l2;
    }    
}

Node* SortedMerge(Node* l1, Node* l2) {
    Node* l3 = nullptr;
    Node* t1 = l1;
    Node* t2 = l2;
    while(t1 != nullptr && t2 != nullptr) {        
        if (t1->data < t2->data) {
            push_front(l3, t1->data);
            t1 = t1->next;
        }
        else {
            push_front(l3, t2->data);
            t2 = t2->next;
        }
    }
    while(t1 != nullptr){
        push_front(l3, t1->data);
        t1 = t1->next;
    }
    while(t2 != nullptr){
        push_front(l3, t2->data);
        t2 = t2->next;
    }
    l3 = reverse(l3);
    return l3;
}



void display(Node* head) {
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}