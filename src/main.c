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

void handleUserInput(char* userInput, Node** root) {
    char *token = strtok(userInput, " ");
    char *command = token;

    // Check if it's an INSERT command
    if (strcmp(command, "INSERT") == 0) {
        handleInsertCommand(userInput, root);
    }
    // Check if it's a DELETE command
    else if (strcmp(command, "DELETE") == 0) {
        handleDeleteCommand(userInput, root);
    }
    // Check if it's a SELECT command
    else if (strcmp(command, "SELECT") == 0) {
        handleSelectCommand(userInput, *root);
    }
    // Check if it's a CREATE TABLE command
    else if (strcmp(command, "CREATE TABLE") == 0) {
        handleCreateTableCommand(userInput);
    }
    // Check if it's a SHOW TABLES command
    else if (strcmp(command, "SHOW TABLES") == 0) {
        showTables();
    }
    // Exit loop on a quit command
    else if (strcmp(command, "QUIT") == 0) {
        exit(0);
    }
    else {
        printf("Invalid command.\n");
    }
}

void handleCreateTableCommand(char* command) {
    char *tableName = (char *)malloc(256);
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

void handleInsertCommand(char* command, Node** root) {
    char table[256];
    char values[256];
    sscanf(command, "INSERT INTO %s VALUES (%[^)])", table, values);

    // Check if the table name is correct
    //printf("table: %s\nvalues: %s\n tableName: %s\n", table, values, tableName);
    if (strcmp(table, tables[numTables]->name) != 0) {
        printf("Table name: %s\n", tableName);
        printf("%s\n", tables[numTables]->name);
        printf("Invalid table name 1.\n");
        return;
    }

    // Tokenize the values and insert each one
    char* token = strtok(values, ",");
    while (token != NULL) {
        int value = atoi(token);
        insertion(root, value);
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

void handleDeleteCommand(char* command, Node** root) {
    char table[256];
    int value;
    int numArgs = sscanf(command, "DELETE FROM %s WHERE VALUE=%d", table, &value);

    // Check if the table name is correct
    if (strcmp(table, tableName) != 0) {
        printf("Invalid table name 2.\n");
        return;
    }

    if (numArgs == 2) {
        // If a condition is provided, delete the specific value
        deletion(root, value);
        printf("Deleted value %d from the table %s.\n", value, table);
    } else {
        // If no condition is provided, delete all values
        deleteAll(root);
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

void handleSelectCommand(char* command, Node* root) {
    char table[256];
    int value;
    int numArgs = sscanf(command, "SELECT * FROM %s WHERE VALUE=%d", table, &value);

    // Check if the table name is correct
    if (strcmp(table, tableName) != 0) {
        printf("Invalid table name 3.\n");
        return;
    }

    if (numArgs == 2) {
        // If a condition is provided, select the specific value
        Node* result = selection(root, value);
        if (result != NULL) {
            printf("Found value %d in the table %s.\n", value, table);
        } else {
            printf("Value %d not found in the table %s.\n", value, table);
        }
    } else {
        // If no condition is provided, select all values
        selectAll(root);
    }
}

int main() {
    char command[256];
    Node* root = NULL;

    while (1) {
        printf("Enter SQL command: ");
        if (getInput(command) == NULL) {
            continue;
        }

        // Check if it's an INSERT command
        if (strncmp(command, "INSERT", 6) == 0) {
            handleInsertCommand(command, &root);
        }
        // Check if it's a DELETE command
        else if (strncmp(command, "DELETE", 6) == 0) {
            handleDeleteCommand(command, &root);
        }
        // Check if it's a SELECT command
        else if (strncmp(command, "SELECT", 6) == 0) {
            handleSelectCommand(command, root);
        }
        // Check if it's a CREATE TABLE command
        else if (strncmp(command, "CREATE TABLE", 12) == 0) {
            handleCreateTableCommand(command);
        }
            // Check if it's a SHOW TABLES command
        else if (strcmp(command, "SHOW TABLES") == 0) {
            showTables();
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