// structures.h
#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct table{
    int id;
    char nom[20];
    char prenom[20];
    int age;
    struct table *next;
};

#endif // STRUCTURES_H