#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "table.h"

Table** tables = NULL;
int numTables = 0;
int tableCapacity = 5;
char *tableName = NULL; // Utilisation de char * pour un nom de table dynamique

void resizeTableArray() {
    tableCapacity = (tableCapacity == 0) ? 1 : tableCapacity * 2;
    tables = (Table**)realloc(tables, tableCapacity * sizeof(Table*));
}

void createTable(const char *table_name) {
    if (numTables == tableCapacity) {
        resizeTableArray();
    }
    tables[numTables] = (Table *)malloc(sizeof(Table));

    // Allocation dynamique pour le nom de la table
    tables[numTables]->name = (char *)malloc(strlen(table_name) + 1);
    strcpy(tables[numTables]->name, table_name);

    tables[numTables]->tree = NULL;
    numTables++;
    printf("Table %s created.\n", table_name);
}

Table* getTable(const char* tableName) {
    for (int i = 0; i < numTables; i++) {
        if (strcmp(tables[i]->name, tableName) == 0) {
            return tables[i];
        }
    }
    return NULL;
}

void deleteTable(const char* tableName) {
    for (int i = 0; i < numTables; i++) {
        if (strcmp(tables[i]->name, tableName) == 0) {
            free(tables[i]->tree); // Assuming tree is dynamically allocated
            free(tables[i]->name); // Libération de l'allocation dynamique pour le nom
            free(tables[i]);
            for (int j = i; j < numTables - 1; j++) {
                tables[j] = tables[j + 1];
            }
            numTables--;
            printf("Table %s deleted.\n", tableName);
            return;
        }
    }
    printf("Table %s not found.\n", tableName);
}

void showTables() {
    if (numTables == 0) {
        printf("No tables available.\n");
        return;
    }
    printf("Tables:\n");
    for (int i = 0; i < numTables; i++) {
        printf("- %s\n", tables[i]->name);
    }
}
