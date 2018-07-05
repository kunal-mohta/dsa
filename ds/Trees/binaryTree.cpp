// Based on my own understanding, no implementation seen

// using classes

#include <iostream>

class TreeNode {
  public:
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    int Value;

    TreeNode (int value) {
      Value = value;
    }

    TreeNode* setLeftChild (TreeNode* leftChild) {
      left = leftChild;
      return left;
    }

    TreeNode* setRightChild (TreeNode* rightChild) {
      right = rightChild;
      return right;
    }
};

class BinaryTree {
  public:
    TreeNode* root = nullptr;

    void preOrderTraversal (TreeNode* node) {
      if (node != nullptr) {
        std::cout<<node->Value<<std::endl;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
      }
    }

    void postOrderTraversal (TreeNode* node) {
      if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout<<node->Value<<std::endl;
      }
    }

    void inOrderTraversal (TreeNode* node) {
      if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout<<node->Value<<std::endl;
        inOrderTraversal(node->right);
      }
    }
};

int main () {
  BinaryTree aTree;

  TreeNode rootNode(2);
  
  TreeNode leftChild(3);
  TreeNode rightChild(4);

  rootNode.setLeftChild(&leftChild);
  rootNode.setRightChild(&rightChild);

  TreeNode leftChildOne(5);
  TreeNode leftChildTwo(6);

  leftChild.setLeftChild(&leftChildOne);
  leftChild.setRightChild(&leftChildTwo);

  aTree.root = &rootNode;

  std::cout<<"\nPreOrder"<<std::endl;
  aTree.preOrderTraversal(aTree.root);

  std::cout<<"\nPostOrder"<<std::endl;
  aTree.postOrderTraversal(aTree.root);

  std::cout<<"\nInOrder"<<std::endl;
  aTree.inOrderTraversal(aTree.root);
}