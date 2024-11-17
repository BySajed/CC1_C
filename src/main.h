// main.h
#ifndef MAIN_H
#define MAIN_H
#include "structure.h"

char *getInput(char *input);
void handleCreateTableCommand(char* command);
void handleSelectTableCommand(char* command);
void handleInsertCommand(char* command);
void handleDeleteCommand(char* command);
void handleSelectCommand(char* command);
void deleteAll(Node** root);
void selectAll(Node* root);
int main();


#endif
