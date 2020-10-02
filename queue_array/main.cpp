#include <iostream>
#include <exception>
using namespace std;

class Queue {
  private:
      int* array;
      int capacity;
      int rear, front;
  public:
	Queue(int _capacity){
        this->array = new int[_capacity];
        this->capacity = _capacity;
        this->front = this->rear = -1;
    }
	void enqueue(int data){
        if(isFull()) return;// TODO: resize considering the front and rear
        if(isEmpty())
            front = rear = 0;
        else if(rear == capacity - 1)  
            rear = 0;
        else
            rear++;
        array[rear] = data;
    }
	int dequeue() {
        if(isEmpty()) return INT_MIN;//TODO: exception
        int data = array[front];
        if(front == rear)
            front = rear = -1;
        else if(front == capacity -1)
            front = 0;
        else
            front++;
        return data;        
    }
    bool isFull(){
        return (front == 0 && rear == capacity - 1) || (rear == front - 1);
    }
    bool isEmpty(){
        return front == -1;
    }
   
    void display(){
        if(isEmpty()) return;
        if(rear >= front){
            for (int i = front; i <= rear; i++)
                cout<<array[i]<<", ";
            cout<<endl;            
        } else {
            for (int i = front; i < capacity; i++)
                cout<<array[i]<<", ";
            for (int i = 0; i <= rear; i++)
                cout<<array[i]<<", ";
            cout<<endl;
        }
    }
};

int main(){
    Queue* queue = new Queue(3);
    queue->enqueue(5);
    queue->enqueue(10);
    queue->enqueue(20);
    queue->display(); 
    queue->dequeue(); 
    queue->display(); 
    queue->enqueue(8);
    queue->enqueue(16);
    queue->display();   
}
