/*
    2.2.ReturnKthToLast :
* Implement an algorithm to find K'th to 
 * last element of a singly linked list.
 * Note : Size of linked list is not known
*/

#include <iostream>

template <class T>
struct Node
{
public:
    Node *next = nullptr;
    T data;

    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

template <class T>
struct LinkedList
{
public:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

    LinkedList<T>()
    {
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void insertLast(Node<T> *node)
    {
        if (isEmpty())
            head = tail = node;
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    void insertFirst(Node<T> *node)
    {
        if (isEmpty())
            head = tail = node;
        else
        {
            node->next = head;
            head = node;
        }
    }

    void printLinkedList()
    {
        Node<int> *p = head;
        while (p != nullptr)
        {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << "nullptr";
    }
};

template <typename T>
void removeDuplicates(LinkedList<T> *list)
{
    if (list->head == nullptr)
        return;

    Node<T> *current = list->head;
    while (current != nullptr)
    {
        Node<T> *iterator = current;
        while (iterator->next != nullptr)
        {
            if (iterator->next->data == current->data)
            {
                iterator->next = iterator->next->next;
            }
            else
            {
                iterator = iterator->next;
            }
        }
        current = current->next;
    }
}

template <typename T>
int getLength(LinkedList<T> *list)
{
    int c = 0;
    Node<int> *p = list->head;
    while (p != nullptr)
    {
        c++;
        p = p->next;
    }
    return c;
}

template<typename T>
void kthToLast(LinkedList<T>* list,int len, int k)
{
    Node<int> *temp = list->head;
    for (int i = 0; i < len - k; i++)
        temp = temp->next;
    std::cout << temp->data;
}

int main()
{

    LinkedList<int> *list = new LinkedList<int>();
    Node<int> *n1 = new Node<int>(20);
    Node<int> *n2 = new Node<int>(4);
    Node<int> *n3 = new Node<int>(15);
    Node<int> *n4 = new Node<int>(35);
    list->insertFirst(n1);
    list->insertFirst(n2);
    list->insertFirst(n3);
    list->insertFirst(n4);
    kthToLast(list,getLength(list),4);


    return 0;
}