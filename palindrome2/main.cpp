#include <iostream>
#include "solution.h"

using namespace std;

int main() {
    DoublyList* list = new DoublyList();
    int n, val;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> val;
        push_back(list, val);
    }

    if(is_palindrome(list)){
        std::cout<<"palindrome\n";
    } else {
        std::cout<<"no palindrome\n";
    }
}