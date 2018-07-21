#include<iostream>

class Node {
  public:
    int value;
    Node* next;

    Node (int v) {
      value = v;
    }
};

class LinkedList {
  public:
    Node* root = nullptr;
    Node* freeList = nullptr;

    void addNodeHead (int value) {
      if (freeList != nullptr) {
        Node* freeListRootPtr = freeList;
        freeList = freeList->next;

        freeListRootPtr->value = value;
        freeListRootPtr->next = root;
        root = freeListRootPtr;
      }
      else {
        Node* newNode = new Node(value);
        newNode->next = root;
        root = newNode;
      }
    }

    void deleteHeadNode () {
      Node *temp = root->next;

      root->next = freeList;
      freeList = root;

      root = temp;
    }

    void printList () {
      if (root == nullptr) {
        std::cout<<"The list is empty"<<std::endl;
      }
      else {
        Node *temp = root;

        while (temp != nullptr) {
          std::cout<<temp->value<<std::endl;
          temp = temp->next;
        }
      }
    }
};

int main () {
  LinkedList list;

  list.addNodeHead(1);
  list.addNodeHead(3);
  list.addNodeHead(5);
  list.deleteHeadNode();
  list.addNodeHead(2);
  
  list.printList();

}