#include <iostream>
#include "heap.h"

using namespace std;

int main()
{
    try
    {
        MaxHeap<int> heap(20);
        heap.push(3);
        heap.push(2);
        heap.push(15);
        cout << "Size is " << heap.size() << endl;
        cout << heap.top() << " ";
        cout << heap.pop() << " ";
        heap.push(5);
        heap.push(4);
        heap.push(45);
        cout << endl
             << "Size is " << heap.size() << endl;
        cout << heap.pop() << " ";
        cout << heap.pop() << " ";
        cout << heap.pop() << " ";
        cout << heap.pop() << " ";
        cout << heap.pop() << " ";
        cout << endl
             << std::boolalpha << heap.empty()<<endl;        
        /////////////
        int arr[] = {12, 11, 13, 5, 6, 7}; 
        int n = 6;
        MaxHeap<int> heap2(arr, n);
        cout<<heap2.top()<<endl;
        MaxHeap<int>::sort(arr, n);
        for (int i = 0; i < n; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    catch (const out_of_range &oor)
    {
        cout << endl
             << oor.what();
    }

    return 0;
}