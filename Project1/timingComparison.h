#pragma once

#include "bst.h" // BST 
#include "zoo.h" // Hash Table 

/* Function to time and compare the two data satructures */
void testInsertionPerformance(EnclosureBSTNode* root, HashTable* hashTable, int numEnclosures);
void testSearchPerformance(EnclosureBSTNode* root, HashTable* hashTable, int searchID, int numSearches);
void testPrintingPerformance(EnclosureBSTNode* root, HashTable* hashTable);