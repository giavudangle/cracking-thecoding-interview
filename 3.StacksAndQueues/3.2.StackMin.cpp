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

template<typename T>
class MinStack : public MyStack<T>{
    private:
        MyStack<T> _minStack;
        MyStack<T> _superStack;

    public:
        MinStack(){
            _minStack = MyStack<T>();
        }

        void push(const T& data){
            if(_minStack.isEmpty() || data < _minStack.peek()){
                _minStack.push(data);
                _superStack.push(data);
            }
        }

        void pop(){
            if(_superStack.isEmpty() && _superStack.peek() <= _minStack.peek()){
                T temp = _minStack.pop();
            }
            _superStack.pop();
        }

        T getMin(){
            return _minStack.peek();
        }
};

int main() { 
    MinStack<int> myStack;
   
    myStack.push(-5);
    myStack.push(1);
    myStack.push(-6);
    myStack.push(-8);
    myStack.pop();

    std::cout << myStack.getMin();
    return 0;
}

