/**
 * 3.5. Sort Stack
 * Write a program to sort a stack such that the smallest items
 * are on top of stack. You can use an additional temporary stack,
 * but you may not copy the elements into any other data structure
 * (such as array). The stack supports the following operations:
 * push, pop, peek and isEmpty.
 * 
 * 
 * @author VuDang
 */

#include <iostream>
#include <vector>

template <typename T>
struct MyStackNode
{
public:
    T data;
    MyStackNode<T>* next;
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
    int size = 0;

public:
    T pop()
    {
        if (top == nullptr)
        {
            return NULL;
        }
        T item = top->data;
        top = top->next;
        size--;
        return item;
    }

    void push(T item)
    {
        MyStackNode<T>* t = new MyStackNode<T>(item);
        t->next = top;
        top = t;
        size++;
    }

    T peek()
    {
        if (top == nullptr)
            return -1;
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int getSize()
    {
        return this->size;
    }
    void print() {
        auto t = top;
        while (t != nullptr) {
            std::cout << t->data << " ";
            t = t->next;
        }
    }

    void sort() {
        MyStack<T>* scale = new MyStack<T>();
        while (!this->isEmpty()) {
            T temp = this->pop();
            while (!scale->isEmpty() && scale->peek() > temp) {
                this->push(scale->pop());
            }
            scale->push(temp);
        }

        while (!scale->isEmpty()) {
            this->push(scale->pop());
        }
    };

};

int main()
{
    MyStack<int>* stack = new MyStack<int>();
    stack->push(4);
    stack->push(9);
    stack->push(11);
    stack->push(53);
    stack->push(3);
    stack->push(2);
    stack->print();
    stack->sort();
    std::cout << std::endl;
    stack->print();


    return 0;
}   