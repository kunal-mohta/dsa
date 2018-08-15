#include<iostream>

class TreeNode {
    public:
        int value;
        TreeNode *right = nullptr, *left = nullptr, *parent = nullptr;

        TreeNode (int val, TreeNode* p) {
            value = val;
            parent = p;
        }
};

class BinarySearchTree {
    public:
        TreeNode *root = nullptr;

        void insertNode (int val) {
            if (root == nullptr) {
                root = new TreeNode(val, nullptr);
            }
            else {
                TreeNode* tmp = root;

                while (1) {
                    if (val >= tmp->value) {
                        if (tmp->right) {
                            tmp = tmp->right;
                        }
                        else {
                            tmp->right = new TreeNode(val, tmp);
                            break;
                        }
                    }
                    else {
                        if (tmp->left) {
                            tmp = tmp->left;
                        }
                        else {
                            tmp->left = new TreeNode(val, tmp);
                            break;
                        }
                    }
                }
            }
        }

        TreeNode* minimum (TreeNode* node) {
            TreeNode* tmp = node;

            while (tmp->left) {
                tmp = tmp->left;
            }

            return tmp;
        }

        TreeNode* maximum (TreeNode* node) {
            TreeNode* tmp = node;

            while (tmp->right) {
                tmp = tmp->right;
            }

            return tmp;
        }

        TreeNode *predecessor (TreeNode *node) {
            if (node->left) {
                return maximum(node->left);
            }
            else {
                TreeNode *y = node->parent;
                while (y != nullptr && y->left == node) {
                    node = y;
                    y = y->parent;
                }
                return y;
            }
        }

        TreeNode *successor (TreeNode *node) {
            if (node->right) {
                return minimum(node->right);
            }
            else {
                TreeNode *y = node->parent;
                while (y != nullptr && y->right == node) {
                    node = y;
                    y = y->parent;
                }
                return y;
            }
        }
};

int main () {
    BinarySearchTree t;

    t.insertNode(6);
    t.insertNode(2);
    t.insertNode(5);
    t.insertNode(4);
    t.insertNode(3);
    t.insertNode(1);
    t.insertNode(9);
    t.insertNode(7);

    std::cout<<t.predecessor(t.root->right->left)->value<<std::endl;
    std::cout<<t.successor(t.root->left)->value<<std::endl;
}