#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Table {
    char name[50];
    Node* tree;
} Table;

Node* createNode(int data);

#endif
