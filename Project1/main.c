#include <stdio.h>
#include "zoo.h"
#include "bst.h"
#include "timingComparison.h"

void test() {
	printf("testing");
	return 0;
}

int main() {
	/*
	HashTable zoo;
	for (int i = 0; i < TableSize; i++) {
		zoo.table[i] = NULL;
	}
	insertEnclosure(&zoo, 1001, "Lion Enclosure");
	insertEnclosure(&zoo, 1999, "Monkey Enclosure");
	insertEnclosure(&zoo, 2539, "Gorilla Enclosure");
	insertAnimal(&zoo, 4444, 9, "bart", "elephant", 4); // TODO: Debug
	printAllEnclosures(&zoo); // Working
	printAnimalsInEnclosure(&zoo, 2539); // Working
	*/

	EnclosureBSTNode* zooBST = NULL;
	HashTable zooHashTable = { 0 };

	int numEnclosures = 10000;
	int searchID = 5000;
	int numSearches = 10000;

	testInsertionPerformance(zooBST, &zooHashTable, numEnclosures);
	testSearchPerformance(zooBST, &zooHashTable, searchID, numSearches);
	testPrintingPerformance(zooBST, &zooHashTable);

	return 0;
}