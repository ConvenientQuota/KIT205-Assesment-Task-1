#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zoo.h"
#include <time.h>

#define TableSize 10000


/* Mapping an enclosureID to a hash table index*/
int hashFunction(int enclosureID) {
	return enclosureID % TableSize;
}

/* function inserting new enclosure into hashtable */

void insertEnclosure(HashTable* zoo, int enclosureID, char* name) {
	int index = hashFunction(enclosureID); // Calculating the hash table index for the enclosureID
	Enclosure* newEnclosure = (Enclosure*)malloc(sizeof(Enclosure)); // Allocating memory for the enclosure
	newEnclosure->enclosureID = enclosureID; // setting the enclosureID of the new enclosure
	strcpy_s(newEnclosure->enclosureName, sizeof(newEnclosure->enclosureName), name); // copying the enclosure name in the new enclosures name field
	newEnclosure->animals = NULL; // initialising the animal linked list to NULL cause its a new enclosure
	newEnclosure->next = zoo->table[index]; // Setting the next pointer of the new enclosure to the current head of the list at the index and implementing chaining in case of collision
	zoo->table[index] = newEnclosure; //inserting the new enclosure at the beginning of the lsit in the table at given index
}

/* Function for inserting an Animal into an Enclosure */
void insertAnimal(HashTable* zoo, int enclosureID, int animalID, char* name, char* species, int age) {
	int index = hashFunction(enclosureID);
	Enclosure* enclosure = zoo->table[index];

	// Searching for the enclosure
	while (enclosure != NULL && enclosure->enclosureID != enclosureID) {
		enclosure = enclosure->next;
	}

	// If the enclosure doesnt exist
	if (enclosure == NULL) {
		printf("Enclosure not found. \n");
		return;
	}

	// Creating a new animal and then inserting it at the head of the animal linked list

	Animal* newAnimal = (Animal*)malloc(sizeof(Animal));
	newAnimal->animalID = animalID;
	strcpy_s(newAnimal->name, sizeof(newAnimal->name), name);
	strcpy_s(newAnimal->species, sizeof(newAnimal->species), species);
	newAnimal->age = age;
	newAnimal->next = enclosure->animals;
	enclosure->animals = newAnimal;
}

void printAnimalsInEnclosure(HashTable* zoo, int enclosureID) {
	int index = hashFunction(enclosureID);
	Enclosure* enclosure = zoo->table[index];

	while (enclosure != NULL && enclosure->enclosureID != enclosureID) {
		enclosure = enclosure->next;
	}
	if (enclosure == NULL) {
		printf("Enclosue wasnt found. \n");
		return;
	}

	printf("Enclosure: %s\n", enclosure->enclosureName);
	Animal* currentAnimal = enclosure->animals;
	while (currentAnimal != NULL) {
		printf("Animal ID: %d, Name: %s, Species: %s, Age: %d\n", currentAnimal->animalID, currentAnimal->name, currentAnimal->species, currentAnimal->age, currentAnimal);
		currentAnimal = currentAnimal->next;
	}
}

void printAllEnclosures(HashTable* zoo) {
	for (int i = 0; i < TableSize; i++) {
		Enclosure* enclosure = zoo->table[i];
		while (enclosure != NULL) {
			printf("Enclosure ID: %d, Name: %s\n", enclosure->enclosureID, enclosure->enclosureName);
			enclosure = enclosure->next;
		}
	}
}