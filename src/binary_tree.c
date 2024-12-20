//
// Created by sajed on 28/09/2024.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "select.h"
#include "insert.h"
#include "delete.h"
#include "update.h"
#include "binary_tree.h"

char binary_tree(Node *root, int data){
    char *input = (char *)malloc(255 * sizeof(char));

    char * token = strtok(getInput(input), " ");
    if (strcmp(token, "select") == 0) {
        selection(root, data);
    } else if (strcmp(token, "insert") == 0) {
        insertion(&root, data);
    } else if (strcmp(token, "delete") == 0) {
        deletion(&root, data);
    } else if (strcmp(token, "update") == 0) {
        update();
    } else if (strcmp(token, "exit") == 0) {
        printf("exit\n");
    } else {
        printf("Erreur de synthaxe\n");
    }
    //*getInput(char *input);
    

    return *input;
}