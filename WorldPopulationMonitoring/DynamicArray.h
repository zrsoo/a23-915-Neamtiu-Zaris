#pragma once
#include "Country.h"

typedef struct {
	int cap; // The maximum number of elements that the array can contain.
	int nrElem; // The current number of elements in the array.
	Country* ptrarr; // Pointer to the first element of the array
} DynamicArray;

DynamicArray createDynamicArray(int cap);
int getSize(DynamicArray da);
Country getElement(DynamicArray da, int i);
void updateElement(DynamicArray* da, int i, Country ctrNew);
void addToEnd(DynamicArray* da, Country ctr);
void deleteElem(DynamicArray* da, int i);
int arrayFull(DynamicArray da);
void resizeArray(DynamicArray* da);
void Destroy(DynamicArray* da);