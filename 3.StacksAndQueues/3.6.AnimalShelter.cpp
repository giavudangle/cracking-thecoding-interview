/**
 * 3.6. Animal Shelter
 * An animal shelter, which holds only dogs and cats, operates
 * on a strictly "first in, first out" basis. People must adopt
 * either the "oldest" (based on arrival time) of all animals at
 * the shelter, or they can select whether they would prefer a dog
 * or a cat (and will receive the oldest animal of that type). They
 * cannot select which specific animal they would like. Create a data
 * structure to maintain this system and implement operations such as
 * enqueue, dequeueAny, dequeueDog and dequeueCat. You may use the
 * built in linked list data structure.
 *
 *
 * @author VuDang
 */

#include <iostream>
#include <vector>


template <class T>
class Node
{
public:
    T data;
    Node<T>* next = nullptr;
    Node(T value) {
        this->data = value;
    }
    
};

enum ANIMAL_TYPE
{
    ABSTRACT,
    DOG,
    CAT
};



template <class T>
class MyLinkedList
{
public:
    Node<T>* first = nullptr;
    Node<T>* last = nullptr;
    int count = 0;
    MyLinkedList<T>()
    {
        first = nullptr;
        last = nullptr;
    }
    bool IsEmpty()
    {
        return first == nullptr;
    }

    T poll() {
        T value = first->data;
        first = first->next;
        count--;
        return value;
    }

    T peek() {
        return first->data;
    }

    void InsertLast(Node<T>* node)
    {
        count++;
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

    void InsertFirst(Node<T>* node)
    {
        count++;
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
        Node<int>* p = first;
        while (p != nullptr) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout << "NULL";
    }

    int getSize() {
        return this->count;
    }
};



class AbstractAnimal {
    
private:
    int order;
protected:
    std::string name;
public:
    ANIMAL_TYPE type;
    AbstractAnimal(std::string name) {
        this->name = name;
        this->type = ANIMAL_TYPE::ABSTRACT;
    }
    
    AbstractAnimal() {

    }
 
    
    void setOrder(int order) {
        this->order = order;
    }

    int getOrder() {
        return this->order;
    }

    std::string getName() {
        return this->name;
    }
    bool operator < (const AbstractAnimal& animal) {
        return this->order < animal.order;
    }
    
};

class Dog : public AbstractAnimal {
public:
    Dog(const std::string& name) : AbstractAnimal(name) {
        this->name = name;
        this->type = ANIMAL_TYPE::DOG;
    }
    Dog() {

    }
};

class Cat : public AbstractAnimal {
public:
    Cat(const std::string& name) : AbstractAnimal(name) {
        this->name = name;
        this->type = ANIMAL_TYPE::CAT;
    }

    Cat() {

    }
};

template<typename Base, typename T>
inline bool instanceOf(const T*) {
    return std::is_base_of<Base, T>::value;
}


class AnimalQueue : public AbstractAnimal {
private:
    int order = 0;
public:
    MyLinkedList<Dog>* dogs = new MyLinkedList<Dog>();
    MyLinkedList<Cat>* cats = new MyLinkedList<Cat>();

    void enqueue(AbstractAnimal* animal) {
       
        animal->setOrder(order);
        order++;
       
        if (animal->type == ANIMAL_TYPE::DOG)
        {
            //Node<Dog>* dogNode = new Node<Dog>(animal->getName());

            dogs->InsertLast(new Node<Dog>
                (static_cast<Dog*>(animal)->getName()));    
        }
        else if (animal->type == ANIMAL_TYPE::CAT) {
            cats->InsertLast(new Node<Cat>
                (static_cast<Cat*>(animal)->getName()));
        }

       
    }

    Dog dequeueDog() {
        return dogs->poll();
    }
    
    Cat dequeueCat() {
        return cats->poll();
    }

    AbstractAnimal dequeueAny() {
        if (dogs->getSize() == 0) {
            return dequeueCat();
        }
        else if (cats->getSize() == 0) {
            return dequeueDog();
        }
        Dog dog = dogs->peek();
        Cat cat = cats->peek();
        if (dog < cat) {
            return dequeueDog();
        }
        else {
            return dequeueCat();
        }
    };
};


int main()
{
    AnimalQueue* q = new AnimalQueue();


    q->enqueue(new Dog("Dog"));
    q->enqueue(new Cat("Cat"));
    q->enqueue(new Dog("Dog"));
    q->enqueue(new Cat("Cat"));
    q->enqueue(new Dog("Dog"));
    q->enqueue(new Cat("Cat"));

    q->dequeueAny();

    std::cout << "";

    return 0;
}   