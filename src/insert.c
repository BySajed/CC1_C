//
// Created by sajed on 25/09/2024.
//
#include <stdio.h>
#include "main.h"
#include "structure.h"

extern char userInput[100];


void insertion(Node** root, int data){
    Node* newNode = createNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Level order traversal to find the appropriate place for insertion
    Node* temp;
    Node* queue[100];
    int front = -1, rear = -1;
    queue[++rear] = *root;
    while (front != rear) {
        temp = queue[++front];
        //  Insert new node as the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            return;
        }
        // if left child is not missing push it to the queue
        else {
            queue[++rear] = temp->left;
        }
        // Same thing with the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            return;
        }
        else {
            queue[++rear] = temp->right;
        }
    }
}
