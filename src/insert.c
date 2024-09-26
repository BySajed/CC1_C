//
// Created by sajed on 25/09/2024.
//
#include <stdio.h>
#include "main.h"

extern char userInput[100];

void insert() {
    getInput(userInput);

    for (int i = 4; i < sizeof(userInput); ++i) {
        if (userInput[i] == ')') {
            break;
        }
        printf("%c", userInput[i]);
    }
}