/*
 * Created by sajed on 25/09/2024.
 *
 * Function: Selection
 *
 * Perform a BFS (Breadth-First Search) on a binary tree to find a node containing
 * the specified data. The BFS traversal explores the tree level by level using a queue.
 *
 * Parameters:
 *  - root: A pointer to the root node of the binary tree.
 *  - data: The integer value to search for within the tree.
 *
 *  Returns:
 *  - A pointer to the node containing the specified data if found.
 *  - NULL if the data is not found in the tree of the tree is empty.
*/
#include <stdio.h>
#include "main.h"
#include "structure.h"

Node* selection(Node* root, int data) {

// If the tree is empty, return NULL
    if (root == NULL) {
	return NULL;
    }

// Initialize a queue to store nodes for level-order traversal
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

// Perform BFS until the queue is empty of the node is found
    while (front != rear) {
	    temp = queue[++front];

	    if (temp->data == data) {
		    return temp;
	    }

	    if (temp ->left != NULL) {
		    queue[++rear] = temp->left;
	    }

	    if (temp->right != NULL) {
		    queue[++rear] = temp->right;
	    }
    }

// If the node wasn't found, return NULL
    return NULL;
}
