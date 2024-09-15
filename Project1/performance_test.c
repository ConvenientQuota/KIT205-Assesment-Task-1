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
void testInsertionPerformance();