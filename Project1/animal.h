#pragma once

/* Data Structure that represents an animal */
typedef struct Animal {
    int animalID;
    char name[20];
    char species[20];
    int age;
    struct Animal* next; // This can be used for chaining in both linked list and BST
} Animal;