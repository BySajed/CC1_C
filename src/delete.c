/*
 * Created by sajed on 29/09/2024.
 *
 * Function: getDeepestRightmostNode
 *
 * Finds the deepest and rightmost node in a binary tree using BFS traversal. This is useful for operations
 * such as replacing or deleting nodes in binary trees.
 *
 * Parameters:
 * - root: A pointer to the root node of the binary tree.
 *
 * Returns:
 * - A pointer to the deepest and rightmost node in the tree.
 *
 * ------------------------------------------------------------------------------------------------------------
 *
 * Function: deleteDeepestRightmostNode
 *
 * Deletes the deepest and rightmost node from a binary tree. this function is often used in cunjunction with
 * node deletion processes ton maintain tree structure
 *
 * Parameters:
 *  - root: A pointer to the root node of the binary tree.
 *  - dNode: A pointer to the derepest rightmost node to be deleted.
 *
 *  Returns:
 *  - Nothing (void). The function modifies the tree in place by removing the node.
 *
 * ------------------------------------------------------------------------------------------------------------
 *
 *  Function: delete
 *
 *  Deletes a node with a specified value from a binary tree. The node to be deleted is replaced by the deepest
 *  and rightmost node in the tree to maintain the structure. This function handles edge cases such as deleting 
 *  the root node or an empty tree.
 *
 *  Parameters:
 *   - root: A double pointer to the root node of the binary tree.
 *   - data: The integer value of the node to be deleted.
 *
 *   Returns:
 *   Nothing (void). The function modifies the tree in place by deleting the node.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "structure.h"
#include "delete.h"

Node* getDeepestRightmostNode(Node* root){
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;

    // Start BFS from the root node
    queue[++rear] = root;

    // Perform BFS until all nodes are processed
    while (front != rear) {
        temp = queue[++front];

	if (temp->left != NULL) {
	    queue[++rear] = temp->left;
	}

	if (temp->right != NULL) {
	    queue[++rear] = temp->right;
	}
    }

    // The last node processed is the deepest rightmost node
    return temp;
}

void deleteDeepestRightmostNode(Node* root, Node* dNode){
    Node* temp;
    Node* queue[100];
    int64_t front = -1, rear = -1;

    //Start BFS from the root node
    queue[++rear] = root;

    // Perform BFS to find and delete the deepest rightmost node
    while (front != rear) {
	temp = queue[++front];

	// Check if the current node is the node to be deleted
	if (temp == dNode) {
	    temp = NULL;
	    free(dNode);
	    return;
	}else{
	    queue[++rear] = temp->right;
	}
    }

    // If the right child exists, check if it's the node to delete
    if (temp->right != NULL) {
    	if (temp->right == dNode) {
	    temp->right = NULL;
	    free(dNode);
	    return;
	}else{
	    queue[++rear] = temp->right;
	}
    }

    // Same thing with the left child
    if (temp->left != NULL) {
	if (temp->left == dNode) {
	    temp->left = NULL;
	    free(dNode);
	    return;
	}else{
	    queue[++rear] = temp->left;
	}
    }
}

void deletion(Node** root, int data) {

    // Handle the case where the tree is empty
    if (*root == NULL) {
	printf("Database is empty");
	return;
    }

    // Handle the case where the tree has only one node
    if ((*root)->left == NULL && (*root)->right == NULL) {
	if ((*root)->data == data){
	free (*root);
	*root = NULL;
	return;
	} else {
	printf("Synthax error \n");
	return;
	}
     }

     // Perform BFS to find the node with the specified data and track the deepest node
     Node* temp;
     Node* queue[100];
     int front = -1, rear = -1;
     queue[++rear] = *root;
     Node* keyNode = NULL;

     // Perform BFS to find the target node
     while (front != rear) {
	temp = queue[++front];

	if (temp->data == data) {
	    keyNode = temp;
	}

	if (temp->left != NULL) {
	    queue[++rear] = temp->left;
	}

	if (temp->right != NULL) {
	    queue[++rear] = temp->right;
	}
     }

     // If the target node is found, replace it with the deepest node
     if (keyNode != NULL) {
	Node* deepestNode = getDeepestRightmostNode(*root);
	keyNode->data = deepestNode->data;
	deleteDeepestRightmostNode(*root, deepestNode);
     } else {
        printf("Synthax error\n");
     }
}
