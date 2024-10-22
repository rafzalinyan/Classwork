#include <iostream> 
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;


    LinkedList() {
        head = nullptr;
    }

    void add(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        cout << "Added " << val << " to the list." << endl;
    }

    void remove(int val) {
        if (head == nullptr) {
            cout << "List is empty, cannot remove " << val << endl;
            return;
        }


        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Removed " << val << " from the list." << endl;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }


        if (current->next == nullptr) {
            cout << "Value " << val << " not found in the list." << endl;
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Removed " << val << " from the list." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "null" << endl;
    }
};

int main() {
    LinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    cout << "Current List: ";
    list.display();

    list.remove(20);

    cout << "List after removal: ";
    list.display();

    list.remove(100);

    return 0;
}