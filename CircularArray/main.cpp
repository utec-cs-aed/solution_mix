#include <iostream>
#include "circulararray.cpp"
#include "tester.h"

using namespace std;

int main() {
  CircularArray<int>* array = new CircularArray<int>(3);
  ASSERT(array->is_empty() == true, "The function is_empty is not working");
  ASSERT(array->is_full() == false, "The function is_full is not working");
  ASSERT(array->size() == 0, "The function size is not working");
  array->push_front(5);
  array->push_front(10);
  ASSERT(array->pop_front() == 10, "The function push_front/pop_front is not working");
  array->push_back(20);
  array->push_back(15);
  ASSERT(array->pop_back() == 15, "The function push_back/pop_back is not working");
  array->push_back(30);
  ASSERT(array->is_full() == true, "The function is_full is not working");
  array->push_back(8);
  array->push_back(10);
  array->push_front(3);  
  ASSERT(array->pop_back() == 30, "The function push_back/pop_back is not working");
  array->display();
  ASSERT(array->get_front() == 5, "The function push_back/pop_back is not working");
  ASSERT(array->get_back() == 20, "The function push_back/pop_back is not working");

  array->insert(1, 2);

  array->display();
  array->sort();
  array->display();
  delete array;
  
  return 0;
}