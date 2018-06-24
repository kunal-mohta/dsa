/* Some what similar to CLRS' implementation */

#include<iostream>

using namespace std;

#include "../../utilities.cpp"

class Queue {
  public:
    int queueSize = 0; //Including the elements before head, which are not actually part of the queue
    int queue[3];
    int head = 0;
    int tail = 0;
    
    void enqueue (int element) {
      queue[tail] = element;

      tail++;
    }

    void dequeue () {
      if (head == tail) cout<<"underflow";
      else head++;
    }
};

int main () {
  Queue q;
  q.enqueue(3);
  q.enqueue(5);
  printIntArray(q.queue, q.head, q.tail - 1);
  q.dequeue();
  q.dequeue();
  printIntArray(q.queue, q.head, q.tail - 1);
  q.dequeue();
}