#include<stdio.h>
#include<stdlib.h>

typedef struct _node node;
struct _node {
	node *parent;
	node *left;
	node *right;
	int lHeight;
	int rHeight;
	int val;
};

node *createNode (int val) {
	node *newNode = (node *) malloc(sizeof(node));
	newNode->val = val;
	newNode->parent = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->lHeight = -1;
	newNode->rHeight = -1;
}

int max (int a, int b) {
	return (a > b) ? a : b;
}

int getHeight (node *root) {
	// returns the height of the current node
	// NOTE: make sure that the heights of all the nodes
	// are updated before calling this

	return max(root->lHeight, root->rHeight) + 1;
}

int updateHeight (node *root) {
	// updates left and right subtree heights in all nodes
	// and returns the height of the current node
	if (root == NULL) return -1;
	else {
		root->lHeight = updateHeight(root->left);
		root->rHeight = updateHeight(root->right);
		return max(root->lHeight, root->rHeight) + 1;
	}
}

void insertNode (node **root, int val) {
	node *toInsert = createNode(val);

	if (*root == NULL) *root = toInsert;
	else {
		node *tmp = *root;
		while (1) {
			if (val < tmp->val) {
				if (tmp->left != NULL) {
					tmp = tmp->left;
				}
				else {
					tmp->left = toInsert;
					break;
				}
			}
			else {
				if (tmp->right != NULL) {
					tmp = tmp->right;
				}
				else {
					tmp->right = toInsert;
					break;
				}
			}
		}
		toInsert->parent = tmp;
	}

	updateHeight(*root);

	int isBalanced = 0;
	node *prepreunbalanced = NULL;
	node *preunbalanced = NULL;
	node *unbalanced = toInsert;

	while (abs(unbalanced->lHeight - unbalanced->rHeight) <= 1) {
		prepreunbalanced = preunbalanced;
		preunbalanced = unbalanced;
		unbalanced = unbalanced->parent;

		if (unbalanced == NULL) {
			isBalanced = 1;
			break;
		}
	}

	if (!isBalanced) {
		if (preunbalanced != NULL && prepreunbalanced != NULL) {
			if (preunbalanced == unbalanced->left && prepreunbalanced == preunbalanced->left) {
				// left left
				printf("\nleft left\n");
			}
			else if (preunbalanced == unbalanced->left && prepreunbalanced == preunbalanced->right) {
				// left right
				printf("\nleft right\n");
			}
			if (preunbalanced == unbalanced->right && prepreunbalanced == preunbalanced->right) {
				// right right
				printf("\nright right\n");
			}
			if (preunbalanced == unbalanced->right && prepreunbalanced == preunbalanced->left) {
				// right left
				printf("\nright left\n");
			}
		}
	}
}

void inorderTraversal (node *root) {
	if (root->left != NULL) inorderTraversal(root->left);
	printf("\n%d", root->val);
	if (root->right != NULL) inorderTraversal(root->right);
}

int main () {
	node *root;
	node **x = &root;
	*x = NULL;

	insertNode(x, 23);
//	insertNode(x, 34);
//	insertNode(x, 33);
//	insertNode(x, 6);
	insertNode(x, 12);
	insertNode(x, 13);

	inorderTraversal(root);

	printf("\n\n%d\n\n", abs(-43));
}
