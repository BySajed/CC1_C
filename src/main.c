/*
 * CC 1 de C
 *
 * Objectif: Faire une base de donnée en incluant le principe d'arbre binaire
 * Permettre à l'utilisateur de faire des insert, des select et des delete
 *
 * Liste des commandes gérés:
 * - INSERT
 * - SELECT
 * - DELETE
 * - QUIT (pour quitter le programme)
 *
 * fait par BEN YOUSSEF Sajed 3SI2
 *
 * Début le 25/09/2024
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "main.h"
#include "structure.h"
#include "binary_tree.h"
#include "insert.h"
#include "select.h"
#include "delete.h"
#include "update.h"
#include "table.h"

typedef struct table table;
struct table *first = NULL;
char userInput[100];
void insert();
Node* selection();

char *getInput(char *input) {
    if (fgets(input, 255, stdin) == NULL) {
        printf("Error reading input.\n");
        return NULL;
    }
    if (input[strlen(input) - 1] == '\n') {
        input[strlen(input) - 1] = '\0';
    }

    // Convert the input to uppercase
    for(int i = 0; input[i]; i++){
        input[i] = toupper(input[i]);
    }

    return input;
}

void handleCreateTableCommand(char* command) {
    char tableName[256];
    sscanf(command, "CREATE TABLE %s", tableName);
    createTable(tableName);
}

void handleSelectTableCommand(char* command) {
    sscanf(command, "SELECT TABLE %s", tableName);
    Table* table = getTable(tableName);
    if (table != NULL) {
        printf("Table %s selected.\n", tableName);
    } else {
        printf("Table %s not found.\n", tableName);
    }
}

void handleDropTableCommand(char* command) {
    char tableName[256];
    sscanf(command, "DROP TABLE %s", tableName);
    deleteTable(tableName);
}


void handleInsertCommand(char* command) {
    char table[256];
    char values[256];
    sscanf(command, "INSERT INTO %s VALUES (%[^)])", table, values);

    // Recherche de la table par nom
    Table* currentTable = getTable(table);
    if (currentTable == NULL) {
        printf("Invalid table name.\n");
        return;
    }

    // Tokenize the values and insert each one
    char* token = strtok(values, ",");
    while (token != NULL) {
        int value = atoi(token);
        insertion(&currentTable->tree, value);
        printf("Inserted %d into the table %s.\n", value, table);
        token = strtok(NULL, ",");
    }
}


void deleteAll(Node** root) {
    if (*root == NULL) return;

    // delete both subtrees
    deleteAll(&(*root)->left);
    deleteAll(&(*root)->right);

    // then delete the node
    printf("Deleting node: %d\n", (*root)->data);
    free(*root);
    *root = NULL;
}

void handleDeleteCommand(char* command) {
    char table[256];
    int value;
    int numArgs = sscanf(command, "DELETE FROM %s WHERE VALUE=%d", table, &value);

    // Recherche de la table par nom
    Table* currentTable = getTable(table);
    if (currentTable == NULL) {
        printf("Invalid table name.\n");
        return;
    }

    if (numArgs == 2) {
        // Si une condition est fournie, supprimer la valeur spécifique
        deletion(&currentTable->tree, value);
        printf("Deleted value %d from the table %s.\n", value, table);
    } else {
        // Si aucune condition n'est fournie, supprimer tous les noeuds
        deleteAll(&currentTable->tree);
        printf("Deleted all values from the table %s.\n", table);
    }
}


void selectAll(Node* root) {
    if (root == NULL) return;

    // select both subtrees
    selectAll(root->left);
    printf("Selected node: %d\n", root->data);
    selectAll(root->right);
}

void handleSelectCommand(char* command) {
    char table[256];
    int value;
    int numArgs = sscanf(command, "SELECT * FROM %s WHERE VALUE=%d", table, &value);

    // Recherche de la table par nom
    Table* currentTable = getTable(table);
    if (currentTable == NULL) {
        printf("Invalid table name.\n");
        return;
    }

    if (numArgs == 2) {
        // If a condition is provided, select the specific value
        Node* result = selection(currentTable->tree, value);
        if (result != NULL) {
            printf("Found value %d in the table %s.\n", value, table);
        } else {
            printf("Value %d not found in the table %s.\n", value, table);
        }
    } else {
        // If no condition is provided, select all values
        selectAll(currentTable->tree);
    }
}

int main() {
    char command[256];
    //Node* root = NULL;

    while (1) {
        printf("Enter SQL command: ");
        if (getInput(command) == NULL) {
            continue;
        }

        // Check if it's an INSERT command
        if (strncmp(command, "INSERT", 6) == 0) {
            handleInsertCommand(command);
        }
        // Check if it's a DELETE command
        else if (strncmp(command, "DELETE", 6) == 0) {
            handleDeleteCommand(command);
        }
        // Check if it's a SELECT command
        else if (strncmp(command, "SELECT", 6) == 0) {
            handleSelectCommand(command);
        }
        // Check if it's a CREATE TABLE command
        else if (strncmp(command, "CREATE TABLE", 12) == 0) {
            handleCreateTableCommand(command);
        }
            // Check if it's a SHOW TABLES command
        else if (strcmp(command, "SHOW TABLES") == 0) {
            showTables();
        }
        // Check if it's a DELETE TABLE command
        else if (strncmp(command, "DROP TABLE", 10) == 0) {
            handleDropTableCommand(command);
        }
        // Exit loop on a quit command
        else if (strncmp(command, "QUIT", 4) == 0) {
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    // Free all tables
    for (int i = 0; i < numTables; i++) {
        deleteAll(&tables[i]->tree); // Libérer l'arbre de la table
        free(tables[i]->name); // Libérer le nom de la table
        free(tables[i]); // Libérer la structure Table elle-même
    }
    free(tables); // Libérer le tableau de pointeurs de tables

    return 0;
}