#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "table.h"
#include "main.h"

Table** tables = NULL;
int numTables = 0;
int tableCapacity = 0;
char *tableName = NULL; // Utilisation de char * pour un nom de table dynamique

void resizeTableArray() {
    tableCapacity = (tableCapacity == 0) ? 1 : tableCapacity * 2;
    //tables = (Table**)realloc(tables, tableCapacity * sizeof(Table*));
    Table** temp = (Table**)realloc(tables, tableCapacity * sizeof(Table*));
    if (temp == NULL) {
        printf("Error allocating memory for tables.\n");
        return;
    }
    tables = temp;
}

void createTable(const char *table_name) {
    if (numTables == tableCapacity) {
        resizeTableArray();
    }
    tables[numTables] = (Table *)malloc(sizeof(Table));
    if (tables[numTables] == NULL) {
        printf("Error allocating memory for table.\n");
        return;
    }

    // Allocation dynamique pour le nom de la table
    tables[numTables]->name = (char *)malloc(strlen(table_name) + 1);
    if (tables[numTables]->name == NULL) {
        printf("Error allocating memory for table name.\n");
        return;
    }
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
            // Libération de l'arbre de la table (si elle est allouée dynamiquement)
            deleteAll(&tables[i]->tree);
            free(tables[i]->name);
            free(tables[i]);

            // Déplacer les autres tables pour combler le vide
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
    printf("%d Tables:\n", numTables);
    for (int i = 0; i < numTables; i++) {
        if (tables[i] != NULL && tables[i]->name != NULL) {
            printf("- %s\n", tables[i]->name);
        }
    }
}
