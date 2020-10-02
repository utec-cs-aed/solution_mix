struct Node{
	int data;
	Node* next;
};

// TODO: implement here

void push_front(Node*& head, int val) {
    Node* nodo = new Node();
    nodo->data = val;
    nodo->next = head;
    head = nodo;
}

Node* reverse(Node* head) {
    Node* temp = head;
    Node* rev = nullptr;
    while(temp != nullptr) {
        push_front(rev, temp->data);
        temp = temp->next;
    }
    return rev;
}

bool is_palindrome(Node* head) {
    Node* temp = reverse(head);
    while(head != nullptr) {
        if(head->data != temp->data)
            return false;
        head = head->next;
        temp = temp->next;
    }
    return true;
}
