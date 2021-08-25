/*

You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function
that adds the two numbers and returns the sum as a linked list.
Example:
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: (2 -> 1 -> 9). That is, 912.
*/

/**
 * 2.5.SumLists: 
 * 
 * You have two numbers represented by a linked list,
 * where each node contains a single digit. The digits
 * are stored in reverse order, such that 1's digit is 
 * at the head of the list. Write a function that adds
 * the two numbers and returns the sum as linked list
 * 
 * Ex: Input : (7 -> 1 -> 6) + (5 -> 9 -> 2). That's 617 + 295
 * Output : 2 -> 1 > 9. That is, 912
 * 
 * FOLLOW UP : Suppose the digits are stored in forward order.
 * Repeat the above problem.
 * 
 * Ex. Input : (6 -> 1 -> 7) + (2 -> 9 -> 5). That's 617 + 295
 * Output : 9 -> 1 > 2. That is, 912
 * 
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

template<typename T>
LinkedList<T>* sumList(LinkedList<T>* list_one, LinkedList<T>* list_two){
    LinkedList<int>* result = new LinkedList<int>();

    int carry = 0;
    int sum = 0;

    while(list_one->head != nullptr || list_two-> head != nullptr){
        sum = carry + (list_one->head->data) + (list_two ->head->data);
        carry = sum / 10;
        sum = sum % 10;
        Node<T>* newNode = new Node<T>(sum);
        result->insertLast(newNode);
        list_one->head = list_one->head->next;
        list_two->head = list_two->head->next;

    }

    return result;
} 



int main()
{
// Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
// Output: (2 -> 1 -> 9). That is, 912.

    LinkedList<int>* list_one = new LinkedList<int>();
    list_one->insertLast(new Node<int>(7));
    list_one->insertLast(new Node<int>(1));
    list_one->insertLast(new Node<int>(6));

    LinkedList<int>* list_two = new LinkedList<int>();
    list_two->insertLast(new Node<int>(5));
    list_two->insertLast(new Node<int>(9));
    list_two->insertLast(new Node<int>(2));

    LinkedList<int>* result = sumList(list_one,list_two);
    result->printLinkedList();


    return 0;
}