/*
 
Given two singly linked lists, determine if the two lists intersect.Return the intersecting node.
Note that the intersection is defined based on reference, not value.That is, if the kth node of the
first linked list is the exact same node(by reference) as the jth node of the second linked list,
then they are intersecting.

*/


/**
 * 2.7.Intersection :
 * 
 * Given two singly linked list, determine if
 * the two lists intersect. Return the intersecting
 * node. Note that intersection is defined based 
 * on the reference and not value. That is, if K'th
 * node of the first linked list is the exact same node
 * (by reference) as the J'th node of the second
 * linked list, then they are intersecting.
 * 
 * Example:
 * 3 -> 1 -> 5 -> 9 -> 7 -> 2 -> 1
                ^
                |
 *          4 -> 6
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


// 3 -> 1 -> 5 -> 9 -> 7 -> 2 -> 1
//                     ^
//                     |
//                4 -> 6

template<typename T>
int getLength(Node<T>* p){
    int c = 0;
    while(p!=nullptr){
        c++;
        p=p->next;
    }
    return c;
}

template<typename T>
auto infer(Node<T>* list_one,Node<T>* list_two){
    int length_one = getLength(list_one);
    int length_two = getLength(list_two);

    if(length_one > length_two){
        int len = length_one - length_two;
        return intersection(len,list_one,list_two);
    } else {
        int len = length_two - length_one;
        return intersection(len,list_two,list_one);
    }
}


template<typename T>
Node<T>* intersection(int length,Node<T>* list_one,Node<T>* list_two){
    Node<T>* result = new Node<T>();
    Node<T>* current_one = list_one;
    Node<T>* current_two = list_two;

    for(int i =0;i<length;i++){
        if(current_one == nullptr){
            return result;
        } 
        current_one = current_one -> next;
    }

    while(current_one !=nullptr && current_two!=nullptr){
        if(current_one == current_two){
            result = current_one;
            return result;
        }
        current_one=current_one->next;
        current_two= current_two->next;
    }
    return result;
}

int main(){

    #ifndef GENERATE_INPUT
    Node<int>* list_one = new Node<int>(3);
    Node<int>* list_two = new Node<int>(4);

    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(5);
    Node<int>* n3 = new Node<int>(9);
    Node<int>* n4 = new Node<int>(7);
    Node<int>* n5 = new Node<int>(2);
    Node<int>* n6 = new Node<int>(1);


    Node<int>* m1 = new Node<int>(6);

    list_one->next = n1;
    list_two->next = m1;

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=nullptr;
    m1->next=n4;
  
    #endif 

    auto res = infer(list_one,list_two);
    res->data ? std::cout << res->data : std::cout << "Not Intersection";
  



 
    return 0;
}