#include<iostream>

class Node {
  public:
    int data;
    Node *next = nullptr;

    Node (int val) {
      data = val;
    }
};

class Queue {
  public:
    Node *first = nullptr, *last = nullptr;

    void enqueue (Node *node) {
      if (first == nullptr) {
        first = node;
        last = node;
      }
      else {
        last->next = node;
        last = last->next;
      }
    }

    Node *dequeue () {
      if (first == nullptr) {
        return nullptr;
      }
      else {
        Node *removeElem = first;
        first = first->next;
        return removeElem;
      }
    }

    void printQueue () {
      Node *start = first;
      while (start) {
        std::cout<<start->data<<std::endl;
        start = start->next;
      }
    }
};

int main () {
  Node root(1);
  Node two(2);
  Node three(3);

  Queue s;
  s.enqueue(&root);
  s.enqueue(&two);
  s.enqueue(&three);

  s.printQueue();

  s.dequeue();
  s.dequeue();
  s.dequeue();
  s.dequeue();

  s.printQueue();
}