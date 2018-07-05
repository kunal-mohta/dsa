// Based on CLRS implementation - Representing rooted trees (10.4)
// mostly same as binaryTree.cpp only parent added to the TreeNode
#include<iostream>

class TreeNode {
  public:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode* parent = nullptr;
    int value;

    TreeNode (int value, TreeNode* parent) {
      value = value;
      parent = parent;
    }
};

class BinaryTree {
  public:
    TreeNode* root = nullptr;
};

int main() {
  TreeNode root(2, nullptr);

  BinaryTree aTree;
  aTree.root = &root;

  TreeNode leftChild(3, &root);
  aTree.root->left = &leftChild;
}