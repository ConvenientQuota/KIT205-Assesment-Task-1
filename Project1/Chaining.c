#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zoo.h"

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

/* Mapping an enclosureID to a hash table index*/
int hashFunction(int enclosureID) {
	return enclosureID % TableSize;
}

/* function inserting new enclosure into hashtable */

void insertEnclosure(HashTable* zoo, int enclosureID, char* name) {
	int index = hashFunction(enclosureID); // Calculating the hash table index for the enclosureID
	Enclosure* newEnclosure = (Enclosure*)malloc(sizeof(Enclosure)); // Allocating memory for the enclosure
	newEnclosure->enclosureID = enclosureID; // setting the enclosureID of the new enclosure
	strcpy(newEnclosure->enclosureName, name); // copying the enclosure name in the new enclosures name field
	newEnclosure->animals = NULL; // initialising the animal linked list to NULL cause its a new enclosure
	newEnclosure->next = zoo->table[index]; // Setting the next pointer of the new enclosure to the current head of the list at the index and implementing chaining in case of collision
	zoo->table[index] = newEnclosure; //inserting the new enclosure at the beginning of the lsit in the table at given index
}

void insertAnimal(HashTable* zoo, int enclosureID, int animalID, char* name, char* species, int age) {

}