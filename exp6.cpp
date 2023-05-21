#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Create the three lists.
  vector<pair<int, string>> list1 = {{1, "Alice"}, {2, "Bob"}, {3, "Carol"}};
  vector<pair<int, string>> list2 = {{1, "BE"}, {2, "BCA"}, {4, "BBA"}};
  vector<pair<int, double>> list3 = {{1, 3.9}, {2, 3.8}, {3, 3.7}};

  // Create a new list to store the common roll nos.
  vector<int> common_roll_nos;

  // Iterate over the first list.
  for (auto roll_no_name : list1) {
    // Check if the roll no is present in the second and third lists.
    bool found_in_second_list = false;
    bool found_in_third_list = false;
    for (auto roll_no_course : list2) {
      if (roll_no_name.first == roll_no_course.first) {
        found_in_second_list = true;
        break;
      }
    }
    for (auto roll_no_cgpa : list3) {
      if (roll_no_name.first == roll_no_cgpa.first) {
        found_in_third_list = true;
        break;
      }
    }

    // If the roll no is present in both the second and third lists, add it to the new list.
    if (found_in_second_list && found_in_third_list) {
      common_roll_nos.push_back(roll_no_name.first);
    }
  }

  // Print the common roll nos.
  for (int roll_no : common_roll_nos) {
    cout << roll_no << endl;
  }

  return 0;
}
