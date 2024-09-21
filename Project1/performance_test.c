#include <stdio.h>
#include <time.h>
#include "timingComparison.h"
#include "bst.h"
#include "zoo.h"

// function to convert time into seconds 
double getTimeInSeconds(clock_t start, clock_t end) {
	return ((double)(end - start)) / CLOCKS_PER_SEC;
}

/* Function that will test the performance/speed of insertion of the data structures */
void testInsertionPerformance(EnclosureBSTNode* root, HashTable *hashTable, int numEnclosures) {
	clock_t start, end;

	printf("Initiating insertion testing.\n");

	// BST Insertion Timing Test

	start = clock();
	for (int i = 1; i <= numEnclosures; i++) {
		char name[20];
		sprintf_s(name, sizeof(name), "Enclosure %d", i);
		root = insertIntoEnclosureBST(root, i, name);
	}
	end = clock();
	printf("Time taken for the BST insertion: %lf seconds\n", getTimeInSeconds(start, end));

	// Hash Table Insertion Timing Test

	start = clock();
	for (int i = 0; i <= numEnclosures; i++) {
		char name[20];
		sprintf_s(name, sizeof(name), "Enclosure %d", i);
		insertEnclosure(hashTable, i, name);
	}
	end = clock();
	printf("Time taken for the HaSH tABLE insertion: %lf seconds\n", getTimeInSeconds(start, end));
}

void testSearchPerformance(EnclosureBSTNode* root, HashTable* hashTable, int searchID, int numSearches) {
	clock_t start, end;

	printf("Initiating searching test.\n");

	// Testing the BST search function timing
	start = clock();
	for (int i = 0; i < numSearches; i++) {
		printAnimalsInEnclosureBST(root, searchID);
	}
	end = clock();
	printf("Time taken for BST search: %lf seconds\n", getTimeInSeconds(start, end));

	// Testing for the Hash Table search function timing
	start = clock();
	for (int i = 0; i < numSearches; i++) {
		printAnimalsInEnclosure(hashTable, searchID);
	}
	end = clock();
	printf("Time taken for Hash Table search: %lf seconds\n", getTimeInSeconds(start, end));
}

void testPrintingPerformance(EnclosureBSTNode* root, HashTable* hashTable) {
	clock_t start, end;
	start = clock();
	printf("Testing Printing timing.\n");

	// Testing the timing of BST printing
	
	printAllEnclosuresBST(root);
	end = clock();
	printf("Time taken for the BST print: %lf seconds.\n", getTimeInSeconds(start, end));

	// Testing for the timing of the Hash Table print

	start = clock();
	printAllEnclosures(hashTable);
	end = clock();
	printf("Time taken for Hash Table print: %lf seconds.\n", getTimeInSeconds(start, end));
}