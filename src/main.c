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

typedef struct table table;
struct table *first = NULL;
char userInput[100];
void insert();
void selection();

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
    
    menu();

    //init table
    //first = (table *)malloc(sizeof(table));
    if (first == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    char input[25];
    char *condition = "select * from table";
    char* userInput = getInput(input);

    if(!strcmp(userInput, "test 1")) {
        insertion();
    }
    else if(!strcmp(userInput, condition)) {
        handleUserInput(userInput);
    }
    else {
        printf("Veuillez entrer une commande valide\n");
        return -1;
    }

    return 0;
}
