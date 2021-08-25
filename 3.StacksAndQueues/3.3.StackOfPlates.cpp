/**
 * 3.3. Stack Of Plates
 * Imagine a stack of plates. If the stack gets too high, it might topple.
 * Therefore, in real life, we would literally start a new stack when the
 * previous stack exceeds some threshold. Implement a data structure,
 * SetOfStacks which mimics this. SetOfStacks should be composed of several
 * stacks and should create a new stack once the previous one exceeds capacity.
 * SetOfStacks.push() and SetOfStacks.pop() should behave identically to a
 * single stack (that is, pop() should return the same values as it would if
 * there were just a single stack.)
 *
 * FOLLOW UP : Implement a function popAt(int index) which performs a pop
 * function on a specific sub-stack.
 *
 * </br>
 *
 * @author Vudang
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
            return -1;
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

template <typename T>
class SetOfStacks
{
private:
    std::vector<MyStack<T>*> listOfStacks;
    const int THRESHOLD = 3;

    void createStackThenPush(T item)
    {
        MyStack<T>* stack = new MyStack<T>();
        stack->push(item);
        listOfStacks.emplace_back(stack);
    }

    MyStack<T>* getLastestStack()
    {
        if (!listOfStacks.empty())
            return listOfStacks[listOfStacks.size() - 1];
        
    }

    int getSetSize()
    {
        if (listOfStacks.empty())
        {
            return 0;
        }
        int total = 0;
        for (MyStack<T> x : listOfStacks)
        {
            total += x.getSize();
        }
        return total;
    }

public:
    SetOfStacks()
    {
    }

    void push(T item)
    {

        if (listOfStacks.size() == 0)
        {
            createStackThenPush(item);
        }
        else
        {
            MyStack<T>* lastestStack = getLastestStack();
            if (lastestStack->getSize() > 0) {
                if (lastestStack->getSize() >= THRESHOLD) {
                    createStackThenPush(item);
                }
                else {
                    lastestStack->push(item);
                }
            }
        }
    }

    int pop() {
        MyStack<T>* lastestStack = getLastestStack();
        if (lastestStack == nullptr) {
            return -1;
        }
        int v = lastestStack->pop();
        if (lastestStack->getSize() == 0) {
            listOfStacks.erase(listOfStacks.end() - 1);
        }
        return v;
    }
};

int main()
{
    SetOfStacks<int>* setOfStacks = new SetOfStacks<int>();
    setOfStacks->push(3);
    setOfStacks->push(4);
    setOfStacks->push(5);
    setOfStacks->push(5);
    setOfStacks->push(5);
    setOfStacks->push(5);
    setOfStacks->push(5);
    setOfStacks->push(5);
    setOfStacks->push(99);
    std::cout << setOfStacks->pop();


    return 0;
}