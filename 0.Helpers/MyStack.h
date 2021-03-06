#include <iostream>

template <typename T>
struct MyStackNode
{
public:
    T data;
    MyStackNode<T> *next;
    MyStackNode(T data)
    {
        this->data = data;
    }
};

template <typename T>
class MyStack
{
private:
    MyStackNode<T>* top;

public:
    T pop()
    {
        if(top == nullptr){
            return -1;
        }
        T item = top->data;
        top = top->next;
        return item;
    }
    
    void push(T item){
        MyStackNode<T>* t = new MyStackNode<T>(item);
        t->next = top;
        top = t;
    }

    T peek(){
        if(top == nullptr) return -1;
        return top->data;
    }

    bool isEmpty(){
        return top == nullptr;
    }


};

