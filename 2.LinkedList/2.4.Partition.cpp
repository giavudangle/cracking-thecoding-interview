

/**
 * 2.4.Partition :
 * 
 * Write code to partition a linked list around 
 * a value x, such that all nodes less then x
 * come before all node greater then or equal to x.
 * If x is contained within the list, the value of x
 * only need to be after the elements less then x (see below).
 * The partition element x can appear anywhere in the 
 * "right partition"; it does not need to appear between
 * the left and right partition.
 * 
 * Ex. Input : 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
 * Output : 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8
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

template<typename T>
void partition(LinkedList<T>* head,int x){

   Node<int> * tail = head->head;
   Node<int> * curr = head->head;
  while( curr != nullptr ) {
   Node<int> * nextNode = curr->next;
    if ( curr->data < x ) {
      //insert at head
      curr->next = head->head;
      head->head = curr;
    } else {
      // insert at tail
      tail->next = curr;
      tail = curr;
    }
    curr = nextNode;
  }
  tail->next = nullptr;


}

int main()
{

    LinkedList<int> *list = new LinkedList<int>();
    list->insertLast(new Node<int>(3));
    list->insertLast(new Node<int>(5));
    list->insertLast(new Node<int>(8));
    list->insertLast(new Node<int>(5));
    list->insertLast(new Node<int>(10));
    list->insertLast(new Node<int>(2));
    list->insertLast(new Node<int>(1));
    list->printLinkedList();
    std::cout<<std::endl;
    partition(list,5);
    list->printLinkedList();

    return 0;
}