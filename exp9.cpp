#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* createNode(int data) {
  Node* node = new Node();
  node->data = data;
  node->next = NULL;
  return node;
}

void bubbleSort(Node* head) {
  Node* current = head;
  Node* next = NULL;

  while (current != NULL) {
    next = current->next;
    while (next != NULL) {
      if (current->data > next->data) {
        int temp = current->data;
        current->data = next->data;
        next->data = temp;
      }
      current = current->next;
      next = next->next;
    }
  }
}

void printList(Node* head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  // Create a linked list of marks.
  Node* head = createNode(10);
  head->next = createNode(5);
  head->next->next = createNode(2);
  head->next->next->next = createNode(7);

  // Print the original list.
  cout << "Original list: ";
  printList(head);

  // Sort the list using bubble sort.
  bubbleSort(head);

  // Print the sorted list.
  cout << "Sorted list: ";
  printList(head);

  return 0;
}
