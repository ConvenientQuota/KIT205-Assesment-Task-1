#pragma once

/* Data Structure that represents an animal */
typedef struct Animal {
	int animalID;
	char name[20];
	char species[20];
	int age;
	struct Animal* next;
}Animal;

/* Data Structure that represents a node within the Binary search tree for the enclosures */
typedef struct EnclosureBSTNode {
	int enclosureID;
	char name[20];
	Animal* animals;
	struct EnclosureBSTNode* left; //pointer to the left child in the bst (smaller enclosureID)
	struct EnclosureBSTNode* right; //pointer to the right child in the bst (larger enclosureID)
} EnclosureBSTNode;

EnclosureBSTNode* insertIntoEnclosureBST(EnclosureBSTNode* root, int enclosureID, char* name);  // Note: returning EnclosureBSTNode*
void InsertAnimalBST(EnclosureBSTNode* root, int enclosureID, int animalID, char* name, char* species, int age);
void printAnimalsInEnclosureBST(EnclosureBSTNode* root, int enclosureID);
void printAllEnclosuresBST(EnclosureBSTNode* root);