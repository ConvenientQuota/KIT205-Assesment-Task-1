#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

EnclosureBSTNode* createEnclosureNode(int enclosureID, char* name) {
	EnclosureBSTNode* newNode = (EnclosureBSTNode*)malloc(sizeof(EnclosureBSTNode));
	newNode->enclosureID = enclosureID;
	strcpy_s(newNode->name, sizeof(newNode->name), name);
	newNode->animals = NULL;
	newNode->left = newNode->right = NULL;
	return newNode;
}

/* Insert function for the BST */
EnclosureBSTNode* insertIntoEnclosureBST(EnclosureBSTNode* root, int enclosureID, char* name) {
	// If the tree is empty, create the root node
	if (root == NULL) {
		return createEnclosureNode(enclosureID, name);
	}

	// Otherwise, recursively find the correct spot to insert
	if (enclosureID < root->enclosureID) {
		root->left = insertIntoEnclosureBST(root->left, enclosureID, name);
	}
	else if (enclosureID > root->enclosureID) {
		root->right = insertIntoEnclosureBST(root->right, enclosureID, name);
	}

	return root;
}


/* Function for inserting enclosures into the BST 
EnclosureBSTNode* insertIntoEnclosureBST(EnclosureBSTNode* root, int enclosureID, char* name) {
	if (root == NULL) {
		EnclosureBSTNode* newEnclosure = (EnclosureBSTNode*)malloc(sizeof(EnclosureBSTNode));
		newEnclosure->enclosureID = enclosureID;
		strcpy(newEnclosure->name, name);
		newEnclosure->animals = NULL;
		newEnclosure->left = newEnclosure->right = NULL;
		return newEnclosure;
	}

	if (enclosureID < root->enclosureID) {
		root->left = insertIntoEnclosureBST(root->left, enclosureID, name);
	}
	else if (enclosureID > root->enclosureID) {
		root->right = insertIntoEnclosureBST(root->right, enclosureID, name);
	}
	return root;
}
 */
void InsertAnimalBST(EnclosureBSTNode* root, int enclosureID, int animalID, char* name, char* species, int age) {
	if (root == NULL) {
		return;
	}

	if (enclosureID < root->enclosureID) {
		InsertAnimalBST(root->left, enclosureID, animalID, name, species, age);
	}
	else if (enclosureID > root->enclosureID) {
		InsertAnimalBST(root->right, enclosureID, animalID, name, species, age);
	}
	else {
		Animal* newAnimal = (Animal*)malloc(sizeof(Animal));
		newAnimal->animalID = animalID;
		strcpy(newAnimal->name, name);
		strcpy(newAnimal->species, species);
		newAnimal->age = age;
		newAnimal->next = root->animals;
		root->animals = newAnimal;
	}
}

void printAnimalsInEnclosureBST(EnclosureBSTNode* root, int enclosureID) {
	if (root == NULL) {
		return;
	}

	if (enclosureID < root->enclosureID) {
		printAnimalsInEnclosureBST(root->left, enclosureID);
	}
	else if (enclosureID > root->enclosureID) {
		printAnimalsInEnclosureBST(root->right, enclosureID);
	}
	else {
		printf("Enclosure: %s\n", root->name);
		Animal* currentAnimal = root->animals;
		while (currentAnimal != NULL) {
			printf("Animal ID: %d, Name: %s, Species: %s, Age: %d\n", currentAnimal->animalID, currentAnimal->name, currentAnimal->species, currentAnimal->age);
			currentAnimal = currentAnimal->next;
		}
	}
}

/* Printing all enclosures in order of traversal of the BST */
void printAllEnclosuresBST(EnclosureBSTNode* root) {
	if (root == NULL) {
		return;
	}
	printAllEnclosuresBST(root->left);
	printf("Enclosure ID: %d, Name: %s\n", root->enclosureID, root->name);
	printAllEnclosuresBST(root->right);
}