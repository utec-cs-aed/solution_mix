struct Node
{
	int data;
    Node* next;
    Node* prev;
    Node(){
        data=0;
        next=prev=nullptr;
    }
};

struct DoublyList
{
    Node* head;
    Node* tail;    
    DoublyList(){
        head = tail = nullptr;
    }
}; 

void push_back(DoublyList* list,int val)
{
    Node* nodo = new Node();
    nodo->data = val;    
    if(list->head == nullptr){
        list->head = nodo;
        list->tail = nodo;
    } else {
        list->tail->next = nodo;
        nodo->prev = list->tail;
        list->tail = nodo;
    }
}
// 1 <-> 2 <-> 2 <-> 1
bool is_palindrome(DoublyList* list){
    Node* ph = list->head;
    Node* pt = list->tail;
    while(ph != nullptr && pt != nullptr){              
        if(ph->data != pt->data)
            return false;
        if(ph->next == pt) // cantidad par
            break;
        ph = ph->next;
        pt = pt->prev;
    }
    return true;
}




