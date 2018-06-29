#include<iostream>

class SinglyLinkedListNode {
  public:
    int value;
    SinglyLinkedListNode *next = nullptr;
};

class SinglyLinkedList {
  public:
    int nodeCount = 0;

    SinglyLinkedListNode *head = nullptr;

    SinglyLinkedListNode* addNodeTail (int value) {
      SinglyLinkedListNode *node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode *)); 
      /* 
       * dynamic memory allocation was necessary here because 
       * there was a problem with using normal pointer notation
       * it was pointing to the same location as head
       * even after the first call to the addNode() method
       */
      
      node->value = value;
      
      nodeCount++;

      if (head == nullptr) {
        head = node;
        return head;
      }
      else {
        SinglyLinkedListNode *temp = head;
        while (temp->next != nullptr) {
          temp = temp->next;
        }
        temp->next = node;
        return temp->next;
      }
    }

    SinglyLinkedListNode* addNodeHead (int value) {
      SinglyLinkedListNode *node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode *));
      node->value = value;

      nodeCount++;

      if (head == nullptr) {
        head = node;
        return head;
      }
      else {
        SinglyLinkedListNode *temp = head;
        head = node;
        node->next = temp;
        return node;
      }
    }

    SinglyLinkedListNode* addNodeAtPosition (int value, int position) {
      //position can be [0,nodeCount]
      if (position > nodeCount || position < 0) {
        std::cout<<"Invalid position value"<<std::endl;
      }
      else {
        SinglyLinkedListNode *node = (SinglyLinkedListNode *)malloc(sizeof(SinglyLinkedListNode *));
        node->value = value;

        nodeCount++;

        SinglyLinkedListNode *temp = head;
        while (position > 1) {
          temp = temp->next;
          position--;
        }
        
        SinglyLinkedListNode *tempNext;
        if (temp->next != nullptr) tempNext = temp->next;
        else tempNext = nullptr;

        temp->next = node;
        node->next = tempNext;
      }
    }

    void printList () {
      if (head == nullptr) {
        std::cout<<"The list is empty"<<std::endl;
      }
      else {
        SinglyLinkedListNode *temp = head;
        
        while (temp != nullptr) {
          std::cout<<temp->value<<std::endl;
          temp = temp->next;
        }
      }
    }

    void deleteList () {
      SinglyLinkedListNode *temp = head;
      while (temp != nullptr) {
        SinglyLinkedListNode *next = temp->next;
        free(temp);
        temp = temp->next;
      }
      head = nullptr;
    }
};

int main () {
  SinglyLinkedList list;
  list.addNodeTail(3);
  list.addNodeTail(4);
  list.addNodeHead(10);
  list.addNodeAtPosition(14, 2);
  list.addNodeHead(15);
  list.addNodeAtPosition(7, 3);
  // list.printList();
  list.deleteList();
  list.printList();
}