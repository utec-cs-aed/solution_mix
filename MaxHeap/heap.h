#include <iostream>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <typename T>
class MaxHeap
{
private:
    T *elements;
    int capacity;
    int n;

public:
    MaxHeap(T *elements, int n) : elements(elements), n(n)
    {
        capacity = n;
        for (int i = n / 2 - 1; i >= 0; i--) 
            heapify_down(i);
    }

    MaxHeap(int capacity) : capacity(capacity)
    {
        elements = new T[capacity];
        n = 0;
    }

    int size()
    {
        return n;
    }

    bool empty()
    {
        return n == 0;
    }

    void push(T value)
    {
        if (n == capacity)
            throw out_of_range("index is out of range (Heap overflow)");
        // insert the new element to the end
        int index = n++;
        elements[index] = value;
        heapify_up(index);
    }

    T pop()
    {
        if (n == 0)
            throw out_of_range("index is out of range (Heap underflow)");
        // replace the root of the heap with the last element
        T temp = elements[0];
        elements[0] = elements[--n];
        heapify_down(0);
        return temp;
    }

    T top()
    {
        if (n == 0)
            throw out_of_range("index is out of range (Heap underflow)");
        return elements[0];
    }

    static void sort(T* arr, int n){
        MaxHeap<T> heap(arr, n);
        for (int i=n-1; i>0; i--) 
        {
            //move to end
            swap(heap.elements[0], heap.elements[i]);
            //reduce heap  
            heap.n--;
            //call heapify
            heap.heapify_down(0);
        }
        arr = heap.elements;        
    }

private:
    // return parent of [i]
    int Parent(int i)
    {
        return (i - 1) / 2;
    }

    // return left child of [i]
    int Left(int i)
    {
        return (2 * i + 1);
    }

    // return right child of [i]
    int Right(int i)
    {
        return (2 * i + 2);
    }

    // Recursive Heapify-down algorithm
    void heapify_down(int i)
    {
        int left = Left(i);
        int right = Right(i);
        int largest = i;

        if (left < n && elements[i] < elements[left])
            largest = left;

        if (right < n && elements[largest] < elements[right])
            largest = right;

        if (largest != i)
        {
            swap(elements[i], elements[largest]);
            heapify_down(largest);
        }
    }

    // Recursive Heapify-up algorithm
    void heapify_up(int i)
    {
        if (i && elements[i] > elements[Parent(i)])
        {
            swap(elements[i], elements[Parent(i)]);
            heapify_up(Parent(i));
        }
    }
};