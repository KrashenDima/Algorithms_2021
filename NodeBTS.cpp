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