//
// Created by sajed on 29/09/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "structure.h"
#include "delete.h"

Node* getDeepestRightmostNode(Node* root){
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
        temp = queue[++front];

	if (temp->left != NULL) {
	    queue[++rear] = temp->left;
	}

	if (temp->right != NULL) {
	    queue[++rear] = temp->right;
	}
    }
    return temp;
}

void deleteDeepestRightmostNode(Node* root, Node* dNode){
    Node* temp;
    Node* queue[100];
    int64_t front = -1, rear = -1;
    queue[++rear] = root;

    while (front != rear) {
	temp = queue[++front];

	if (temp == dNode) {
	    temp = NULL;
	    free(dNode);
	    return;
	}else{
	    queue[++rear] = temp->right;
	}
    }

    if (temp->right != NULL) {
    	if (temp->right == dNode) {
	    temp->right = NULL;
	    free(dNode);
	    return;
	}else{
	    queue[++rear] = temp->right;
	}
    }

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

    if (*root == NULL) {
	printf("Database is empty");
	return;
    }

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

	if (temp->left != NULL) {
	    queue[++rear] = temp->left;
	}

	if (temp->right != NULL) {
	    queue[++rear] = temp->right;
	}
     }

     if (keyNode != NULL) {
	Node* deepestNode = getDeepestRightmostNode(*root);
	keyNode->data = deepestNode->data;
	deleteDeepestRightmostNode(*root, deepestNode);
     } else {
	     printf("Synthax error\n");
}
}
