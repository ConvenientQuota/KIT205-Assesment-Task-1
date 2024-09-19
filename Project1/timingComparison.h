#pragma once

#include "bst.h" // BST 
#include "zoo.h" // Hash Table 
#include <time.h>

/* Function to time and compare the two data satructures */
void testInsertionPerformance(EnclosureBSTNode* root, HashTable* hashTable, int numEnclosures);
void testSearchPerformance(EnclosureBSTNode* root, HashTable* hashTable, int searchID, int numSearches);
void testPrintingPerformance(EnclosureBSTNode* root, HashTable* hashTable);
double getTimeInSeconds(clock_t start, clock_t end);