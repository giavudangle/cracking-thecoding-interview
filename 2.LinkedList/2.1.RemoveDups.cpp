/*
    2.1.Remove Dups : Write code to remove duplicates from an unsorted list
    Solve this problem if a temporary buffer is not allowed;
*/


#include <iostream>

template<class T>
struct Node {
public:
    Node* next = nullptr;
    T data;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

template<class T>
struct LinkedList {
public:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    LinkedList<T>() {
        head = nullptr;
        tail = nullptr;
    }


    bool isEmpty() {
        return head == nullptr;
    }

    void insertLast(Node<T>* node) {
        if (isEmpty()) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    void insertFirst(Node<T>* node) {
        if (isEmpty()) head = tail = node;
        else {
            node->next = head;
            head = node;
        }
    }

    void printLinkedList() {
        Node<int>* p = head;
        while (p != nullptr) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << "nullptr";
    }
};

template<typename T>
void removeDuplicates(LinkedList<T>* list) {
    if (list->head == nullptr) return;

    Node<T>* current = list->head;
    while (current != nullptr) {
        Node<T>* iterator = current;
        while (iterator->next != nullptr) {
            if (iterator->next->data == current->data) {
                iterator->next = iterator->next->next;
            }
            else {
                iterator = iterator->next;
            }
        }
        current = current->next;
    }
}

int main() {
   
    LinkedList<int>* list = new LinkedList<int>();
    Node<int>* n1 = new Node<int>(3);
    Node<int>* n2 = new Node<int>(1);
    Node<int>* n3 = new Node<int>(2);
    Node<int>* n4 = new Node<int>(1);
    Node<int>* n5 = new Node<int>(4);
    list->insertFirst(n1);
    list->insertFirst(n2);
    list->insertFirst(n3);
    list->insertFirst(n4);
    list->insertFirst(n5);
    list->printLinkedList();
    std::cout << std::endl;
    removeDuplicates(list);
    list->printLinkedList();

    return 0;
}