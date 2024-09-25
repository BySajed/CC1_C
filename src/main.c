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
    fgets(userInput, sizeof(userInput), stdin);

    // Remove the newline character at the end of the string, if it exists
    if (userInput[strlen(userInput) - 1] == '\n') {
        userInput[strlen(userInput) - 1] = '\0';
    }

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