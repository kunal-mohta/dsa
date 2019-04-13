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

void rotateRight (node **root, node *x) {
	node *xParent = x->parent; // original parent of x
	// parent stuff
	x->parent = x->parent->parent;
	if (xParent->parent != NULL) {
		if (xParent->parent->left == xParent) xParent->parent->left = x;
		else xParent->parent->right = x;
	}

	// right child stuff
	xParent->left = x->right;
	if (x->right != NULL) x->right->parent = xParent;
	x->right = xParent;
	xParent->parent = x;

	if (*root == xParent) {
		*root = x;
	}
}

void rotateLeft (node **root, node *x) {
//	printf("\n%d : %d", x->val, x->parent->parent->val);
	node *xParent = x->parent; // original parent of x

	// parent stuff
	x->parent = x->parent->parent;
	if (xParent->parent != NULL) {
		if (xParent->parent->left == xParent) xParent->parent->left = x;
		else xParent->parent->right = x;
	}

	// left child stuff
	xParent->right = x->left;
	if (x->left != NULL) x->left->parent = xParent;
	x->left = xParent;
	xParent->parent = x;

	if (*root == xParent) {
		*root = x;
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
				rotateRight(root, preunbalanced);
			}
			else if (preunbalanced == unbalanced->left && prepreunbalanced == preunbalanced->right) {
				// left right
				printf("\nleft right\n");
				rotateLeft(root, prepreunbalanced);
//				printf("\nhere %d", prepreunbalanced->parent->val);
				rotateRight(root, prepreunbalanced);
			}
			if (preunbalanced == unbalanced->right && prepreunbalanced == preunbalanced->right) {
				// right right
				printf("\nright right\n");
				rotateLeft(root, preunbalanced);
			}
			if (preunbalanced == unbalanced->right && prepreunbalanced == preunbalanced->left) {
				// right left
				printf("\nright left\n");
				rotateRight(root, prepreunbalanced);
				rotateLeft(root, prepreunbalanced);
			}

			updateHeight(*root);
		}
	}
}

node *findNode (node *root, int val) {
	node *tmp = root;

	while (tmp != NULL && tmp->val != val) {
		if (val < tmp->val) tmp = tmp->left;
		else tmp = tmp->right;
	}
	return tmp;
}

node *successor (node *root, int val) {
	node *succOf = findNode(root, val);

	if (succOf->right != NULL) return succOf->right;
	else {
		node *tmp = succOf;
		while (tmp != NULL && tmp->parent != NULL && tmp->parent->right == tmp) {
			tmp = tmp->parent;
		}
		if (tmp == NULL || tmp->parent == NULL) return NULL;
		else return tmp->parent;
	}
}

void deleteNode (node **root, int val) {
	node *toDelete = findNode(*root, val);

	if (toDelete != NULL) {
		node *startCheck;

		// no children
		if (toDelete->left == NULL && toDelete->right == NULL) {
			if (toDelete->parent->left == toDelete) toDelete->parent->left = NULL;
			else if (toDelete->parent->right == toDelete) toDelete->parent->right = NULL;
			startCheck = toDelete->parent;
			free(toDelete);
		}
		// one child
		else if (toDelete->left != NULL && toDelete->right == NULL) {
			if (toDelete->parent->left == toDelete) toDelete->parent->left = toDelete->left;
			else if (toDelete->parent->right == toDelete) toDelete->parent->right = toDelete->left;
			toDelete->left->parent = toDelete->parent;
			startCheck = toDelete->left;
			free(toDelete);
		}
		else if (toDelete->right != NULL && toDelete->left == NULL) {
			if (toDelete->parent->left == toDelete) toDelete->parent->left = toDelete->right;
			else if (toDelete->parent->right == toDelete) toDelete->parent->right = toDelete->right;
			toDelete->right->parent = toDelete->parent;
			startCheck = toDelete->right;
			free(toDelete);
		}
		// two children
		else {
			node *succ = successor(*root, val);
			int succVal = succ->val;
			deleteNode(root, succ->val);
			toDelete->val = succ->val;
			startCheck = toDelete;
		}

		updateHeight(*root);

		int isBalanced = 0;
//		node *prepreunbalanced = NULL;
//		node *preunbalanced = NULL;
		node *unbalanced = startCheck;

		while (abs(unbalanced->lHeight - unbalanced->rHeight) <= 1) {
//			prepreunbalanced = preunbalanced;
//			preunbalanced = unbalanced;
			unbalanced = unbalanced->parent;
			if (unbalanced == NULL) {
				isBalanced = 1;
				break;
			}
		}

		if (!isBalanced) {
			if (unbalanced->lHeight >= unbalanced->rHeight) {
				if (unbalanced->left->lHeight >= unbalanced->left->rHeight) {
					// left left
					printf("\ndel: left left\n");
					rotateRight(root, unbalanced->left);
				}
				else {
					// left right
					printf("\ndel: left right\n");
					rotateLeft(root, unbalanced->left->right);
					rotateRight(root, unbalanced->left);
				}
			}
			else {
				if (unbalanced->right->lHeight >= unbalanced->right->rHeight) {
					// right right
					printf("\ndel: right right\n");
					rotateLeft(root, unbalanced->right);
				}
				else {
					// right left
					printf("\ndel: right left\n");
					rotateRight(root, unbalanced->right->left);
					rotateLeft(root, unbalanced->right);
				}
			}
			updateHeight(*root);
		}
	}
	else {
		printf("\nNot found node to be deleted");
	}
}

void inorderTraversal (node *root) {
	if (root->left != NULL) inorderTraversal(root->left);
	printf("\n%d", root->val);
	if (root->right != NULL) inorderTraversal(root->right);
}

void preorderTraversal (node *root) {
	printf("\n%d", root->val);
	if (root->left != NULL) preorderTraversal(root->left);
	if (root->right != NULL) preorderTraversal(root->right);
}

int main () {
	node *root;
	node **x = &root;
	*x = NULL;

	insertNode(x, 23);
	insertNode(x, 34);
	insertNode(x, 33);
	insertNode(x, 6);
	insertNode(x, 13);
	insertNode(x, 12);

	deleteNode(x, 34);

	printf("\n\nin order");
	inorderTraversal(root);

	printf("\n\npre order");
	preorderTraversal(root);

//	printf("\n\n%d\n\n", successor(root, 33)->val);
}
