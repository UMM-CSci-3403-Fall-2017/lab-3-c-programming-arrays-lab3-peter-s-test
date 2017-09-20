#ifndef MERGESORT_H_GUARD
#define MERGESORT_H_GUARD

#include <stdbool.h>

#define UNIT_TESTING

void mergesort(int size, int values[]);
int* mergeRanges(int sizeA,int arrayA[],int sizeB,int arrayB[]);
void arrayCopy(int* arrayA, int* arrayB,int n);

#endif
