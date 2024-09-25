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

int menu(){
    printf("Bienvenue dans votre base de donnée !\nVoici vos actions possibles:\n");
    printf("1- Insert\n2- Select\n3- Quitter\n");
    int choix;
    scanf("%d", &choix);

    return choix;
}


int main() {

    menu();

    return 0;
}
