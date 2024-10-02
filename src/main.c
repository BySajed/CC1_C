/*
 * CC 1 de C
 *
 * Objectif: Faire une base de donnée en incluant le principe d'arbre binaire
 * Permettre à l'utilisateur de faire des insert, des select et des delete
 *
 * fait par BEN YOUSSEF Sajed 3SI2
 *
 * Début le 25/09/2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "structure.h"
#include "binary_tree.h"
#include "insert.h"
#include "select.h"
#include "delete.h"
#include "update.h"

typedef struct table table;
struct table *first = NULL;
char userInput[100];
void insert();
Node* selection();

void menu(){
    printf("Bienvenue dans votre base de donnée !\nQue souhaitez-vous faire ? :\n");

}

char *getInput(char *input) {
    fgets(input, 255, stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    return input;
}

void handleUserInput(char* userInput) {
    char *token = strtok(userInput, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

void inorderTraversal(Node* root){
    if (root == NULL) {
	return;
    }
    
    inorderTraversal(root->left);
    printf("%d", root->data);
    inorderTraversal(root->right);
}

int main() {
    char command[256];
    Node* root = NULL;

    while (1) {
        printf("Enter SQL command: ");
        fgets(command, sizeof(command), stdin);

        // Check if it's an INSERT command
        if (strncmp(command, "INSERT", 6) == 0) {
            int value;
            sscanf(command, "INSERT INTO table VALUES (%d)", &value);
            insertion(&root, value);
            printf("Inserted %d into the tree.\n", value);
        }
            // Check if it's a DELETE command
        else if (strncmp(command, "DELETE", 6) == 0) {
            int value;
            sscanf(command, "DELETE FROM table WHERE value=%d", &value);
            deletion(&root, value);
            printf("Deleted %d from the tree.\n", value);
        }
            // Check if it's a SELECT command
        else if (strncmp(command, "SELECT", 6) == 0) {
            int value;
            sscanf(command, "SELECT * FROM table WHERE value=%d", &value);
            Node* result = selection(root, value);
            if (result != NULL) {
                printf("Found %d in the tree.\n", value);
            } else {
                printf("Value %d not found.\n", value);
            }
        }
            // Exit loop on a quit command
        else if (strncmp(command, "QUIT", 4) == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}