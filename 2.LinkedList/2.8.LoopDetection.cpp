/*
2.7.LoopDetection : 
Given a circular linked list, implement an algorithm that
returns the node at the beginning of the loop.
Example:
A -> B -> C -> D -> E -> C [the same C as earlier]
Return C
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
    Node()
    {      
        this->next = nullptr;
    }
};

// Floyd’s Cycle-Finding Algorithm:  
template<typename T>
Node<T>* loopDetection(Node<T>* list){
    Node<T>* slow_pointer = list;
    Node<T>* fast_pointer = list;
    
    for(;;){
        if(slow_pointer == nullptr || fast_pointer == nullptr){
            return nullptr;
        }
        slow_pointer = slow_pointer->next;
        fast_pointer = fast_pointer->next->next;
        if(slow_pointer == fast_pointer) break;
    }

    slow_pointer = list;
    
    for(;;){
        slow_pointer= slow_pointer->next;
        fast_pointer= fast_pointer->next;
        if(slow_pointer == fast_pointer) break;
    }

    return slow_pointer;

}

int main(){

    #ifndef GENERATE_INPUT
    Node<char>* list = new Node<char>('A');
    list->next = new Node<char>('B');
    list->next->next = new Node<char>('C');
    list->next->next->next = new Node<char>('D');
    list->next->next->next->next = new Node<char>('E');
    list->next->next->next->next->next = new Node<char>('C');
    list->next->next->next->next->next->next =  list->next->next;
    #endif 

    Node<char>* t = loopDetection(list);
    std::cout << t->data;
  



 
    return 0;
}