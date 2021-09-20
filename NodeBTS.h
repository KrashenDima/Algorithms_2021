#pragma once
#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* new_node(int data);

Node* insert(Node* node, int data);