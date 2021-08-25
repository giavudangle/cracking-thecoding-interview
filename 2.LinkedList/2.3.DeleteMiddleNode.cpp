
/**
 * 2.3.DeleteTheMiddleNode :
 * 
 * Implement an algorithm to delete a node
 * in the middle (i.e any node but the first
 * and last node. Not necessarily the exact middle)
 * of a singly linked list, given only access to 
 * first node.
 * 
 * ex. delete c from : a -> b -> c -> d -> e -> f
 * output : a -> b -> d -> e -> f
 * 
 * @author VuDang
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
        Node<T> *p = head;
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
    Node<T> *p = list->head;
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

template<typename T>
void deleteMiddleNode(LinkedList<T>* list,int len){
    int bound = len % 2 == 0 ? len / 2  - 1: len/2  ;
    Node<T> *temp = list->head;
    for(int i = 0; i <=bound;i++){
        if(i == bound - 1 ){
            temp->next = temp->next->next;
        }
        temp = temp->next;
    }






}

int main()
{

    LinkedList<char> *list = new LinkedList<char>();
    Node<char> *n1 = new Node<char>('a');
    Node<char> *n2 = new Node<char>('b');
    Node<char> *n3 = new Node<char>('c');
    Node<char> *n4 = new Node<char>('d');
    Node<char> *n5 = new Node<char>('e');
    Node<char> *n6 = new Node<char>('f');


    list->insertLast(n1);
    list->insertLast(n2);
    list->insertLast(n3);
    list->insertLast(n4);
    list->insertLast(n5);
    list->insertLast(n6);
    list->printLinkedList();
    std::cout << "\n";
    deleteMiddleNode(list,getLength(list));
        list->printLinkedList();

    return 0;
}