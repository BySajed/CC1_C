//
// Created by sajed on 25/09/2024.
//
#include <stdio.h>
#include "main.h"
#include "structure.h"

//extern struct table *first;

Node* selection(Node* root, int data) {
/*    struct table *current = first;

    while (current != NULL) {
        printf("id: %d\n", current->id);
        printf("nom: %s\n", current->nom);
        printf("prenom: %s\n", current->prenom);
        printf("age: %d\n", current->age);
        printf("\n");

        current = current->next;
    }*/
    if (root == NULL) {
	return NULL;
    }

    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = root;

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
    return NULL;
}
