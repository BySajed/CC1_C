//
// Created by sajed on 20/10/2024.
//

#ifndef CC1_C_TABLE_H
#define CC1_C_TABLE_H

extern Table** tables;
extern int numTables;
extern int tableCapacity;
extern char *tableName;

void resizeTableArray();
void createTable(const char* tableName);
Table* getTable(const char* tableName);
void deleteTable(const char* tableName);
void showTables();

#endif //CC1_C_TABLE_H
