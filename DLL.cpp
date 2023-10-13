#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Node {
public:
    T value;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;

    Node(): prev(nullptr), next(nullptr) {};

    Node(const T& val): value(val), prev(nullptr), next(nullptr) {};

    ~Node() {}
};

template <typename T, typename Compare = std::equal_to<>>
class DoublyLinkedList {

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node<T> *current = head;
        Node<T> *next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = tail = nullptr;
        length = 0;
    };

    void prepend(T item) {
        length++;
        Node<T>* node = new Node<T>(item);

        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }

    }

    void append(T item) {
        length++;
        Node<T>* node = new Node<T>(item);

        if (!tail) {
            tail = head = node;
        } else {
            node->prev = tail;
            tail->next = node;
            tail = node;
        }
    }



    T get(int idx) const {
        return getAt(idx)->value;
    }

    void insertAt(int idx, T item) {
        if (idx < 0 || idx > length) {
            throw out_of_range("Index out of range");
        }

        if (idx == 0) {
            prepend(item);
            return;
        }

        if (idx == length) {
            append(item);
            return;
        }

        length++;

        Node<T>* node = new Node<T>(item);
        Node<T>* curr = getAt(idx);

        node->next = curr;
        node->prev = curr->prev;
        if (node->prev != nullptr) {
            node->prev->next = node;
        }
        curr->prev = node;
    }

    T remove(T item, Compare compare = {}) {
        Node<T>* curr = head;

        for (int i = 0; curr && i < length; ++i) {
            if (compare(curr->value, item)) {
                break;
            }
            curr = curr->next;
        }

        if (!curr) {
            throw std::out_of_range("Item not found");
        }

        return removeNode(curr);
    }

    T removeAt(int idx) {
        Node<T>* curr = getAt(idx);
        return removeNode(curr);
    }

    void printValues() const {
        Node<T>* curr = head;

        while(curr) {
            std::cout << curr->value << std::endl;
            curr = curr->next;
        }
    }

    T peek() const {
        if (!head) {
            throw std::runtime_error("List is empty");
        } else {
            return head->value;
        }
    }

private:
    int length = 0;
    Node<T> *head, *tail;

    T removeNode(Node<T>* node) {
        if (!node) {
            throw std::invalid_argument("Node is null");
        }

        length--;

        T value = node->value;

        if (node->prev) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }

        if (node->next) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }

        delete node;
        return value;
    }

    Node<T>* getAt(int idx) const {
        if (idx < 0 || idx >= length) {
            throw out_of_range("Index out of range");
        }

        Node<T>* curr = head;
        for (int i = 0; i < idx; ++i) {
            curr = curr->next;
        }

        return curr;
    };
};

int main() {
    DoublyLinkedList<int> list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.prepend(0);
    list.insertAt(2, 10);
    list.removeAt(3);
    list.remove(10);
    list.printValues();
    exit(0);
};
