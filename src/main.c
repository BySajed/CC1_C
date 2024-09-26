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

typedef struct table table;

void insert();
void select();

int menu(){
    printf("Bienvenue dans votre base de donnée !\nQue souhaitez-vous faire ? :\n");
    return 0;
}

char *getInput(char *input) {
    fgets(input, sizeof(input), stdin);
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }
    return input;
}

int main(int argc, char* argv[]) {
    char userInput[100];
    int choice;

    //init table
    struct table* first = (table *)malloc(sizeof(table));
    struct table* second = (table *)malloc(sizeof(table));
    struct table* third = (table *)malloc(sizeof(table));

    struct table *current = first;
    int id_node = 0;

    //auto increment id
    while (current != NULL) {
        current->id = ++id_node;
        current = current->next;
    }

    menu();
    getInput(userInput);

    if(strcmp(userInput, "insert into table values (1)") == 0) {
        choice = 1;
    }
    else if(strcmp(userInput, "select * from table") == 0) {
        choice = 2;
    }
    else {
        printf("Veuillez entrer une commande valide\n");
        return 1;
    }

    switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            select();
            break;
        default:
            printf("Veuillez entrer un choix valide\n");
            break;
    }

    return 0;
}