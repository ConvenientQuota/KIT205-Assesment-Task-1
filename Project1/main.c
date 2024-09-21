#include <stdio.h>
#include "zoo.h"
#include "bst.h"
#include "timingComparison.h"

int main() {
	
	HashTable zoo;
	for (int i = 0; i < TableSize; i++) {
		zoo.table[i] = NULL;
	}
	insertEnclosure(&zoo, 11, "Lion Enclosure");
	insertEnclosure(&zoo, 10, "Eel Enclosure");
	insertEnclosure(&zoo, 19, "Monkey Enclosure");
	insertEnclosure(&zoo, 99, "Gorilla Enclosure");
	insertEnclosure(&zoo, 75, "Bat Enclosure");
	insertEnclosure(&zoo, 234, "Penguin Enclosure");
	insertEnclosure(&zoo, 876, "Kangaroo Enclosure");
	insertEnclosure(&zoo, 543, "Elephant Enclosure");
	insertEnclosure(&zoo, 321, "Tiger Enclosure");
	insertEnclosure(&zoo, 678, "Panda Enclosure");
	insertEnclosure(&zoo, 432, "Zebra Enclosure");
	insertEnclosure(&zoo, 987, "Giraffe Enclosure");
	insertEnclosure(&zoo, 111, "Koala Enclosure");
	insertEnclosure(&zoo, 555, "Crocodile Enclosure");
	insertEnclosure(&zoo, 789, "Flamingo Enclosure");
	insertEnclosure(&zoo, 654, "Ostrich Enclosure");

	insertAnimal(&zoo, 100, 9, "bart", "elephant", 4); // TODO: Debug
	//printAllEnclosures(&zoo); // Working
	//printAnimalsInEnclosure(&zoo, 2539); // Working
	

	EnclosureBSTNode* zooBST = NULL;
	HashTable zooHashTable = { 0 };

	// I didnt even initialise the bst thats why it wasnt working
	zooBST = insertIntoEnclosureBST(zooBST, 11, "Lion Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 10, "Eel Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 19, "Monkey Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 99, "Gorilla Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 75, "Bat Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 234, "Penguin Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 876, "Kangaroo Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 543, "Elephant Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 321, "Tiger Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 678, "Panda Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 432, "Zebra Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 987, "Giraffe Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 111, "Koala Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 555, "Crocodile Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 789, "Flamingo Enclosure");
	zooBST = insertIntoEnclosureBST(zooBST, 654, "Ostrich Enclosure");



	InsertAnimalBST(zooBST, 100, 9, "bart", "elephant", 4); // Ensure this matches the enclosure ID

	// reduces for testing, getting stack overflow error
	// variables used for comfirmation testing in respective order, 1000, 101, 101
	int numEnclosures = 1000; 
	int searchID = 19; 
	int numSearches = 1000; 

	/* Comparison Testing between the hash table and bst */

	/* Hash Table works fine, BST needs fixing */

	//testInsertionPerformance(zooBST, &zoo, numEnclosures);	// Working with reduced variables
	//testSearchPerformance(zooBST, &zoo, searchID, numSearches); // make sure searchID matches with animal
	testPrintingPerformance(zooBST, &zoo);


	

	return 0;
}