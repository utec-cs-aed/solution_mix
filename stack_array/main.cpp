#include <iostream>
#include <exception>
using namespace std;

class Stack {
  private:
      int* array;
      int capacity;
      int size;
  public:
	Stack(int _capacity){
        this->array = new int[_capacity];
        this->capacity = _capacity;
        this->size = 0;
    }
	void push(int data){
        this->array[this->size++] = data; 
        if(this->size == this->capacity)
            resize(this->capacity * 1.5);            
    }
	int pop() {
        if(this->size > 0){        
            return array[--this->size];    
            if(this->size <= 0.25 * this->capacity)                
                resize(this->size * 1.5);               
        }
        return 0;        
    }
    void resize(int new_capacity){
        this->capacity = new_capacity;
        int *temp = new int[this->capacity];
        for (int i = 0; i < size; i++)
            temp[i] = array[i];
        delete[] array;
        array = temp;
    }
    void display(){
        for (int i = this->size - 1; i >= 0; i--)
            cout<<array[i]<<endl;    
    }
};

int main(){
    Stack* stack = new Stack(2);
    stack->push(5);
    stack->push(10);
    stack->push(15);
    stack->push(20);
    stack->display(); // 20,15,10,5
    cout<<"---"<<endl;
    cout<<stack->pop()<<endl; //20
    cout<<stack->pop()<<endl; //15
    cout<<stack->pop()<<endl; //10
    cout<<stack->pop()<<endl; //5
}
