/*
 * CC 1 de C
 *
 * Objectif: Faire une base de donnée en incluant le principe d'arbre binaire
 * Permettre à l'utilisateur de fairedes insert et des select
 *
 * fait par BEN YOUSSEF Sajed 3SI2
 *
 * Début le 25/09/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert();
void select();

typedef struct{
    int id;
    char nom[20];
    char prenom[20];
    int age;
}table;

int menu(){
    printf("Bienvenue dans votre base de donnée !\nQue souhaitez-vous faire ? :\n");
    return 0;
}

int main(int argc, char* argv[]) {
    char userInput[100];
    int choice;

    menu();
    scanf("%s", userInput);

    if(strcmp(userInput, "insert 1 from table") == 0) {
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
            printf("comparaison ok\n");
            insert();
            break;
        case 2:
            printf("comparaison ok\n");
            select();
            break;
        default:
            printf("Veuillez entrer un choix valide\n");
            break;
    }

    return 0;
}