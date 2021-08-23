#include <iostream>
#include <vector>

class MultiStack
{
private:
    const int NUMBER_OF_STACKS = 3;
    int stackCapacity;
    std::vector<int> sizes;
    std::vector<int> values;


    bool isEmpty(int stackIndex){
        return this->sizes[stackIndex] == 0;
    }

    bool isFull(int stackIndex){
        return this->sizes[stackIndex] == stackCapacity;
    }

    int getIndexOfTop(int stackIndex){
        int offset = stackIndex * stackCapacity; // get boundary
        int size = sizes[stackIndex];
        return offset + size - 1;
    }


   
public:
    MultiStack(int fullSize){
        this->stackCapacity = fullSize;
        this->values.resize(fullSize * NUMBER_OF_STACKS);
        this->sizes.resize(NUMBER_OF_STACKS);
    }

    ~MultiStack(){
       
        free(this);
    }

    void push(int stackIndex,int value) {
        if(isFull(stackIndex)) return;
        this->sizes[stackIndex]++;
        this->values[getIndexOfTop(stackIndex)] = value;
    }

    int peek(int stackIndex){
        if(isEmpty(stackIndex)) return -1;
        return this->values[getIndexOfTop(stackIndex)];
    }

    int pop(int stackIndex){
        if(isEmpty(stackIndex)) return -1;
        int topIndex = getIndexOfTop(stackIndex);
        int currentTopValue = values[topIndex];
        values[topIndex] = 0;
        sizes[stackIndex]--;
        return currentTopValue;
    }

    

};

int main()
{
    MultiStack* stack = new MultiStack(5);
    stack->push(1,1);
    stack->push(1,2);
    stack->push(1,3);
    stack->push(1,4);
    std::cout<<stack->pop(1);
    std::cout<<stack->peek(1);


    return 0;
}
