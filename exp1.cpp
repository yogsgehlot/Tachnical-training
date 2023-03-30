#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() {
        head = NULL;
    }
    
    void add_at_position(int value, int position) {
        Node* new_node = new Node(value);
        
        if (position == 1) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* current_node = head;
            for (int i = 1; i < position - 1 && current_node != NULL; i++) {
                current_node = current_node->next;
            }
            if (current_node != NULL) {
                new_node->next = current_node->next;
                current_node->next = new_node;
            } else {
                cout << "Position out of range." << endl;
            }
        }
    }
    
    void print_all() {
        Node* current_node = head;
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
    
    void delete_at_position(int position) {
        if (position == 1) {
            Node* temp_node = head;
            head = head->next;
            delete temp_node;
        } else {
            Node* current_node = head;
            for (int i = 1; i < position - 1 && current_node != NULL; i++) {
                current_node = current_node->next;
            }
            if (current_node != NULL && current_node->next != NULL) {
                Node* temp_node = current_node->next;
                current_node->next = temp_node->next;
                delete temp_node;
            } else {
                cout << "Position out of range." << endl;
            }
        }
    }
};

int main() {
    LinkedList list;
    list.add_at_position(10, 1);
    list.add_at_position(20, 2);
    list.add_at_position(30, 3);
    list.add_at_position(40, 4);
    list.add_at_position(50, 5);
    list.add_at_position(60, 6);
    list.add_at_position(70, 7);
    list.add_at_position(80, 8);
    list.add_at_position(90, 9);
    list.add_at_position(100, 10);
    list.print_all();
    list.delete_at_position(6);
    list.print_all(); 
    return 0;
}
