/*
2.6.Palindrome : Implement a function to check if a linkedlist is a palindrome

Example:
Input: (6 -> 1 -> 6) 
Output: true
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


template<typename T>
bool isPalindrome(Node<T>* primitive,Node<T>* comparator){
    while(comparator!=nullptr ){
        if(comparator->data != primitive->data)
            return false;
        primitive = primitive->next;
        comparator = comparator->next;
    }
    return true;
}



template<typename T>
Node<T>* reverse(Node<T>* node){
    Node<T>* head = nullptr;

    while(node!=nullptr){
        Node<T>* newNode = new Node<T>(node->data);
        newNode->next = head;
        head = newNode;
        node = node->next;
    }
    return head;
}


int main(){
    Node<int>* n1 = new Node<int>(6);
    Node<int>* n2 = new Node<int>(1);
    Node<int>* n3 = new Node<int>(6);

    n1->next = n2;
    n2->next = n3;
    n3->next = nullptr;


  
    Node<int>* reversed = reverse(n1);


    isPalindrome(reversed,n1) 
    ? std::cout << "Palindrome" : std::cout << "Not Palindrome";
    return 0;
}