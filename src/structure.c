//
// Created by sajed on 29/09/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
