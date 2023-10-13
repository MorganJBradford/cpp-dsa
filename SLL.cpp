#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SinglyLinkedList {
public:
    Node *head, *tail;

    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    ~SinglyLinkedList() {
        Node *current = head;
        Node *next_node;
        while (current != nullptr) {
            next_node = current->next;
            delete current;
            current = next_node;
        }
    }

    void prepend(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void append(int value) {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAt(int pos, int value) {
        Node *prev = nullptr;
        Node *current = head;
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (pos < 1) {
            cout << "Position cannot be less than one" << endl;
            delete newNode;
            return;
        } else if (pos == 1) {
            prepend(value);
            return;
        } else {
            for (int i = 1; i < pos; ++i) {
                prev = current;
                current = current->next;
                if (current == nullptr) {
                    cout << "Invalid position" << endl;
                    delete newNode;
                    return;
                }
            }
            prev->next = newNode;
            newNode->next = current;
        }
    }
    void deleteNode(int value) {
        Node *current = head;
        Node *prev = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {  // Node to delete is head
                    head = current->next;
                    if (current == tail) {  // It's also the tail
                        tail = prev; // which will be nullptr here
                    }
                } else {  // Node to delete is not head
                    prev->next = current->next;
                    if (current == tail) {  // Node to delete is tail
                        tail = prev;
                    }
                }
                delete current;
                cout << "Element " << value << " deleted" << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Element " << value << " not found" << endl;
    }


    void search(int value) {
        Node *current = head;
        while(current != nullptr) {
            if (current->data == value) {
                cout << "Found: " << current->data << endl;
                return;
            }
            current = current->next;
        }
        cout<<"Element "<<value<<" not found"<<endl;
    }


    void printValues() {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main() {
    SinglyLinkedList list;
    list.prepend(1);
    list.printValues();
    return 0;
}

