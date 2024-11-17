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

void deleteDeepestRightmostNode(Node* root, Node* dNode) {
    Node* temp;
    Node* queue[100];
    int64_t front = -1, rear = -1;

    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

        if (temp == dNode) {
            // Supprime le nœud trouvé
            free(dNode);
            return;
        }

        if (temp->right) {
            if (temp->right == dNode) {
                free(temp->right);
                temp->right = NULL;
                return;
            } else {
                queue[++rear] = temp->right;
            }
        }

        if (temp->left) {
            if (temp->left == dNode) {
                free(temp->left);
                temp->left = NULL;
                return;
            } else {
                queue[++rear] = temp->left;
            }
        }
    }
}


void deletion(Node** root, int data) {
    if (*root == NULL) {
        printf("Database is empty\n");
        return;
    }

    if ((*root)->left == NULL && (*root)->right == NULL) {
        if ((*root)->data == data) {
            free(*root);
            *root = NULL;
        } else {
            printf("Syntax error\n");
        }
        return;
    }

    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;
    Node* keyNode = NULL;

    while (front != rear) {
        temp = queue[++front];

        if (temp->data == data) {
            keyNode = temp;
        }

        if (temp->left) queue[++rear] = temp->left;
        if (temp->right) queue[++rear] = temp->right;
    }

    if (keyNode != NULL) {
        Node* deepestNode = getDeepestRightmostNode(*root);
        keyNode->data = deepestNode->data;
        deleteDeepestRightmostNode(*root, deepestNode);
    } else {
        printf("Syntax error\n");
    }
}
