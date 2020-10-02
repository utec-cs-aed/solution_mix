#include "solution.h"

int main() {
  DoublyList* list = new DoublyList();
  SortedInsert(list, 2);
  displayRev(list); // 2
  SortedInsert(list, 5);
  displayRev(list); // 2, 5
  SortedInsert(list, 1);
  displayRev(list); // 1, 2, 5  
  SortedInsert(list, 10);
  displayRev(list); // 1, 2, 5, 10  
  SortedInsert(list, 4);
  displayRev(list); // 1, 2, 4, 5, 10  
}