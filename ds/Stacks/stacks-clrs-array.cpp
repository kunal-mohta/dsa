/* Stacks implementation using arrays (CLRS) */

#include<iostream>

using namespace std;

#include "../../utilities.cpp"

class Stack {
  private:
    static constexpr int maxStackSize = 100; //compile time variable

  public:
    int stack[maxStackSize];
    int stackSize = 0;
    void push(int);
    void pop();
};

void Stack::push (int element) {
  stack[stackSize] = element;
  stackSize++;
};

void Stack::pop () {
  if (stackSize > 0) stackSize--;
  else cout<<"Cannot pop, stack is empty"<<endl;
}

int main () {
  Stack x;
  x.push(2);
  x.push(3);
  x.pop();
  printIntArray(x.stack, 0, x.stackSize - 1);
}