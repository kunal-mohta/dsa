#include<iostream>

class Node {
  public:
    int data;
    Node* next = nullptr;

    Node (int val) {
      data = val;
    }
};

class Stack {
  public:
    Node* top = nullptr;

    void push (Node* node) {
      node->next = top;
      top = node;
    }

    Node *pop () {
      if (top != nullptr) {
        Node* removeElem = top;
        top = top->next;
        return removeElem;
      }
      else {
        return nullptr;
      }
    }

    void printStack () {
      Node *start = top;

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

  Stack s;
  s.push(&root);
  s.push(&two);
  s.push(&three);

  s.printStack();

  s.pop();
  s.pop();
  s.pop();
  s.pop();

  s.printStack();
}