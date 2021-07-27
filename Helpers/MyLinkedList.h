/*

*/
#include <bits/stdc++.h>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
};

template <class T>
class MyLinkedList
{
public:
    Node<T> *first = nullptr;
    Node<T> *last = nullptr;
    MyLinkedList<T>()
    {
        first = nullptr;
        last = nullptr;
    }
    bool IsEmpty()
    {
        return first == nullptr;
    }

    void InsertLast(Node<T> *node)
    {
        if (IsEmpty())
        {
            first = last = node;
        }
        else
        {
            last->next = node;
            last = node;
        }
    }

    void InsertFirst(Node<T> *node)
    {
        if (IsEmpty())
        {
            first = last = node;
        }
        else
        {
            node->next = first;
            first = node;
        }
    }

    void DisplayLinkedList() {
      Node<int> * p = first;
      while(p != nullptr){
          cout << p->data << " ";
          p= p->next;
      }
        cout << "NULL";
    }
};
