#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(){
        next = nullptr;
        prev = nullptr;
    }
};

struct DoublyList
{
    Node* head;
    Node* tail;
    DoublyList(){
        head = nullptr;
        tail = nullptr;
    }
};

void SortedInsert(DoublyList* &list, int val)
{
    Node* nodo = new Node();
    nodo->data = val;
    if(list->head == nullptr){
        list->head = nodo;
        list->tail = nodo;
    }
    else 
    {
        Node* temp = list->head;    
        while(temp!=nullptr && val > temp->data) temp = temp->next;                
        if(temp == list->head){
            nodo->next = list->head;  
            nodo->prev = nullptr;
            list->head->prev = nodo;        
            list->head = nodo;
        }
        else if(temp == nullptr){
            nodo->next = nullptr;  
            nodo->prev = list->tail;
            list->tail->next = nodo;        
            list->tail = nodo;
        } else {
            nodo->prev = temp->prev;  
            nodo->next = temp;
            nodo->prev = temp->prev;        
            temp->prev->next = nodo;
            temp->prev = nodo;
        }
    }
}

void display(DoublyList* &list)
{
    for (Node* temp = list->head; temp != nullptr; temp=temp->next)
        cout<<temp->data<<",";
    cout<<endl;
}
void displayRev(DoublyList* &list)
{
    for (Node* temp = list->tail; temp != nullptr; temp=temp->prev)
        cout<<temp->data<<",";
    cout<<endl;
}