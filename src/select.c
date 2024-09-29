//
// Created by sajed on 25/09/2024.
//
#include <stdio.h>
#include "main.h"
#include "structure.h"

extern struct table *first;

void selection() {
    struct table *current = first;

    while (current != NULL) {
        printf("id: %d\n", current->id);
        printf("nom: %s\n", current->nom);
        printf("prenom: %s\n", current->prenom);
        printf("age: %d\n", current->age);
        printf("\n");

        current = current->next;
    }
}
