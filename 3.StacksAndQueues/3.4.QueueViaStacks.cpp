/**
 * 3.4. Queue Via Stacks
 *
 * Implement a MyQueue class which implements a queue using two stacks.
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
};

template<typename T>
class MyQueue {
private:
    MyStack<T>* stackNewest;
    MyStack<T>* stackLastest;

public:
    MyQueue() {
        stackNewest = new MyStack<T>();
        stackLastest = new MyStack<T>();
    }

    int getSize() {
        return this->stackLastest->getSize() + this->stackNewest->getSize();
    }

    void enqueue(T value) {
        stackNewest->push(value);
    }

    void shift() {
        if (stackLastest->isEmpty()) {
            while (!stackNewest->isEmpty()) {
                stackLastest->push(stackNewest->pop());
            }
        }
    }
    
    T peek() {
        shift();
        return stackLastest->peek();
    }

    T dequeue() {
        shift();
        return stackLastest->pop();
    }
};



int main()
{
    MyQueue<int>* queue = new MyQueue<int>();
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);
    queue->dequeue();
    std::cout << queue->peek();

    return 0;
}   