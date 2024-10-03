// main.h
#ifndef MAIN_H
#define MAIN_H
#include "structure.h"

char *getInput(char *input);
void handleInsertCommand(char* command, Node** root);
void handleDeleteCommand(char* command, Node** root);
void handleSelectCommand(char* command, Node* root);
void deleteAll(Node** root);
void selectAll(Node* root);
int main();


#endif
