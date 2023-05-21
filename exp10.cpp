#include <iostream>
#include <stack>

using namespace std;

void reverseArrays(int* arr1, int* arr2, int size) {
  // Create a stack to store the elements of the arrays.
  stack<int> s;

  // Push the elements of the arrays onto the stack.
  for (int i = 0; i < size; i++) {
    s.push(arr1[i]);
    s.push(arr2[i]);
  }

  // Pop the elements of the stack and store them back in the arrays.
  for (int i = 0; i < size; i++) {
    arr1[i] = s.top();
    s.pop();
    arr2[i] = s.top();
    s.pop();
  }
}

int main() {
  // Create two arrays.
  int arr1[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int arr2[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91};

  // Print the original arrays.
  cout << "Original arrays: " << endl;
  for (int i = 0; i < 10; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 10; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  // Reverse the arrays using the LIFO stack.
  reverseArrays(arr1, arr2, 10);

  // Print the reversed arrays.
  cout << "Reversed arrays: " << endl;
  for (int i = 0; i < 10; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 10; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;

  return 0;
}
