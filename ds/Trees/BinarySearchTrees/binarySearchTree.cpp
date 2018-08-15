#include<iostream>

class TreeNode {
  public:
    int value;
    TreeNode *right = nullptr, *left = nullptr;

    TreeNode (int Value) {
      value = Value;
    }
};

class BinarySearchTree {
  public:
    TreeNode *root = nullptr;

    void insertNode (int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
        }
        else {
            TreeNode* tmp = root;

            while (1) {
                if (val >= tmp->value) {
                    if (tmp->right) {
                        tmp = tmp->right;
                    }
                    else {
                        tmp->right = new TreeNode(val);
                        break;
                    }
                }
                else {
                    if (tmp->left) {
                        tmp = tmp->left;
                    }
                    else {
                        tmp->left = new TreeNode(val);
                        break;
                    }
                }
            }
        }
    }

    TreeNode* minimum () {
        TreeNode* tmp = root;

        while (tmp->left) {
            tmp = tmp->left;
        }

        return tmp;
    }

    TreeNode* maximum () {
        TreeNode* tmp = root;

        while (tmp->right) {
            tmp = tmp->right;
        }

        return tmp;
    }

    TreeNode *recursiveSearch (TreeNode* start, int val) {
        if (start == nullptr) {
            std::cout<<"Value not found in the tree"<<std::endl;
            return nullptr;
        }
        else {
            if (val == start->value) {
                return start;
            }
            else if (val >= start->value) {
                return recursiveSearch(start->right, val);
            }
            else {
                return recursiveSearch(start->left, val);
            }
        }
    }

    TreeNode *iterativeSearch (int val) {
        TreeNode *tmp = root;

        while (tmp) {
            if (val == tmp->value) {
                return tmp;
            }
            else if (val >= tmp->value) {
                tmp = tmp->right;
            }
            else {
                tmp = tmp->left;
            }
        }

        std::cout<<"Value not found in the tree"<<std::endl;
        return nullptr;
    }
};

int main () {
    BinarySearchTree t;

    t.insertNode(1);
    t.insertNode(2);
    t.insertNode(1);
    t.insertNode(0);
    std::cout<<(t.root->left->value)<<std::endl;
    std::cout<<t.minimum()->value<<std::endl;
    std::cout<<t.maximum()->value<<std::endl;
    std::cout<<t.recursiveSearch(t.root, 1)->value<<std::endl;
    std::cout<<t.iterativeSearch(2)->value<<std::endl;
}