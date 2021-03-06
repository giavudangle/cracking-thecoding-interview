#include <iostream>

template <typename T>
struct MyQueueNode
{
public:
    T data;
    MyQueueNode<T> *next;
    MyQueueNode(T data)
    {
        this->data = data;
    }
};

template <typename T>
class MyQueue
{
private:
    MyQueueNode<T>* first;
	MyQueueNode<T>* last;


public:
    T pop()
    {
        if(first == nullptr){
            return -1;
        }
		T data = first->data;
		first = first->next;
		if(first == nullptr){
			last = nullptr;
		}
		return data;
    }
    
    void push(T item){
        MyQueueNode<T>* t = new MyQueueNode<T>(item);
		if (last != nullptr){
			last->next = t;
		}
		last = t;
		if(first == nullptr){
			first = last;
		}

    }

    T peek(){
        if(first == nullptr) return -1;
        return first->data;
    }

    bool isEmpty(){
        return first == nullptr;
    }


};

int main(){
	MyQueue<int>* queue = new MyQueue<int>();
	queue->push(2);
	queue->push(99);
	queue->push(2);
	queue->pop();
	std::cout << queue->peek();
	return 0;
}

