#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data);

#endif
