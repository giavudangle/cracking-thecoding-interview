using System;

namespace DotnetWorkspace
{

    class MultiStack
    {
        private int stackNums = 3;
        private int stackCapacity;
        private int[] values;
        private int[] sizes;

        public MultiStack(int size)
        {
            this.stackCapacity = size;
            values = new int[size * stackNums];
            sizes = new int[stackNums];
        }

        private bool isEmpty(int stackNum)
        {
          return this.sizes[stackNum] == 0;
        }

        private bool isFull(int stackNum){
          return this.sizes[stackNum] == stackCapacity;
        }

        private int indexOfTop(int stackNum){
          // Divided into stackNum
          int offset = stackNum * stackCapacity;
          int size = sizes[stackNum];
          return offset + size - 1;
        }

        public void push(int stackNum,int value){
          if(isFull(stackNum)) {
            throw new FullCapacityStackException();
          }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
