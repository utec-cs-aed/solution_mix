#include <iostream>
#include "solution.h"

using namespace std;

int main() {
    Node* head = nullptr;
    int n, val;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val;
        push_front(head, val);
    }
    if(is_palindrome(head)){
        std::cout<<"palindrome\n";
    } else {
        std::cout<<"no palindrome\n";
    }
}