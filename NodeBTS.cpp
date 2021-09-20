#include "NodeBTS.h"

Node* new_node(int data)
{
	Node* node_ptr = new Node();
	node_ptr->data = data;
	node_ptr->left = node_ptr->right = NULL;
	return node_ptr;
}

// Insert a node
Node* insert(Node* node, int data) {
	// Return a new node if the tree is empty
	if (node == NULL) return new_node(data);

	// Traverse to the right place and insert the node
	if (data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

// Find the inorder successor 
Node* minValueNode(Node* node) {
	Node* current = node;

	// Find the leftmost leaf
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

Node* deleteNode(Node* root, int data) {
	//Return if the tree is empty
	if (root == NULL) return root;

	// Find the node to be deleted
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		// If the node is with only one child or no child
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		// If the node has two children
		struct node* temp = minValueNode(root->right);

		// Place the inorder successor in position of the node to be deleted
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}