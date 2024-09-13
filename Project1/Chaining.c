#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TableSize 10000

/* Defining data structures */

typedef struct Animal {
	int animalID;
	char name[20];
	char species[20];
	int age;
	struct Animal* next; //Chaining in the linked list
}Animal;

typedef struct Enclosure {
	int enclosureID;
	char enclosureName[20];
	Animal* animals; // the Linked list of all the animals within the enclosure
	struct Enclosure* next; //Chaining for the hash table
}Enclosure;

typedef struct HashTable {
	Enclosure* table[TableSize];
} HashTable;
