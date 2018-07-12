#include<iostream>
#include<string>

const int hashTableSize = 10;

class TableElement {
  public:
    std::string key;
    int value;
    TableElement* next = nullptr;

    TableElement (std::string Key, int Val) {
      value = Val;
      key = Key;
    }
};

class HashTable {
  private:
    int hashFunction (std::string key) {
      int hash = 0;

      for (int i = 0; i < key.size(); i++) {
          hash += (int)key[i];
      }

      int index = hash % hashTableSize;

      return index;
    }

    bool isTableIndexOccupied (int index) {
      if (table[index]) return true;
      else return false;
    }

  public:
    TableElement* table[hashTableSize] = {nullptr};

    void insertElement (TableElement* elem) {
      int index = hashFunction(elem->key);

      if (isTableIndexOccupied(index)) {
        TableElement* temp = table[index];
        while(temp->next != nullptr) {
          if (temp->key == elem->key) {
            // std::cout<<"\nElements with the same keys are not allowed\n"<<std::endl;
            break;
          }
          else {
            temp = temp->next;
          }
        }

        if (temp->key == elem->key) {
          std::cout<<"\nElements with the same keys are not allowed\n"<<std::endl;
        }
        else {
          temp->next = elem;
        }
      }
      else {
        table[index] = elem;
      }
    }

    TableElement* searchElement (std::string key) {
      int index = hashFunction(key);

      TableElement* temp = table[index];
      while (temp != nullptr) {
        if (temp->key == key) {
          return temp;
        }
        else {
          temp = temp->next;
        }
      }

        std::cout<<"\nElement with the given key not found"<<std::endl;
        return nullptr;
    }

    void deleteElement (std::string key) {
      int index = hashFunction(key);

      TableElement* temp = table[index];
      TableElement* prev = nullptr;
      while(temp != nullptr) {
        if (temp->key == key) {
          if (prev == nullptr) {
            table[index] = temp->next;
            break;
          }
          else {
            prev->next = temp->next;
            break;
          }
        }
        else {
          prev = temp;
          temp = temp->next;
        }
      }
    }
};

int main () {
  TableElement elem("a", 3);
  TableElement elem2("k", 4);
  TableElement elem3("u", 5);
  TableElement elem4("b", 6);

  HashTable ht;
  ht.insertElement(&elem);
  ht.insertElement(&elem2);
  ht.insertElement(&elem3);
  ht.insertElement(&elem4);

  ht.deleteElement("u");
  std::cout<<ht.table[7]->next->value<<std::endl;
  // std::cout<<ht.table[7]->next->value<<std::endl;
  // std::cout<<ht.table[7]->next->next->value<<std::endl;

  // std::cout<<ht.searchElement("b")->value<<std::endl;
}