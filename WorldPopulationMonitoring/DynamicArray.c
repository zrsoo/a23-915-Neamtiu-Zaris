#include "DynamicArray.h"
#include <stdlib.h>
#include <math.h>

DynamicArray createDynamicArray(int cap)
{
	DynamicArray da;
	da.cap = cap;
	da.nrElem = 0;
	da.ptrarr = (Country*)malloc(cap * sizeof(Country));

	return da;
}

int getSize(DynamicArray da)
{
	// Returns the size of the dynamic array.
	return da.cap;
}

Country getElement(DynamicArray da, int i)
{
	// Returns the element from position "i" in the dynamic array.
	return (da.ptrarr)[i];
}

void updateElement(DynamicArray* da, int i, Country ctrNew)
{
	// Updates the element from position "i" to be "ctrNew".
	(da->ptrarr)[i] = ctrNew;
}

void addToEnd(DynamicArray* da, Country ctr)
{
	// Adds an alement to the end of the array.

	// If the array is full, resize it.
	if (arrayFull(*da) == 1)
		resizeArray(da);

	// Then, add the element.
	(da->ptrarr)[da->nrElem] = ctr;
	da->nrElem++;
}

void deleteElem(DynamicArray* da, int i)
{
	// Deletes the element from position "i" in the dynamic array.

	// If the element is on the last position, simply decrement "nrElem"
	if (i == da->nrElem - 1)
		da->nrElem--;
	// Otherwise, move all elements located after the one that needs to be deleted
	// one position to the left.
	else
	{
		for (int j = i; j < da->nrElem - 1; ++j)
			(da->ptrarr)[j] = (da->ptrarr)[j + 1];

		da->nrElem--;
	}
}

int arrayFull(DynamicArray da)
{
	// Returns 1 if the array is full, 0 otherwise.
	if (da.cap == da.nrElem)
		return 1;

	return 0;
}

void resizeArray(DynamicArray* da)
{
	// Resizes the array, doubling its capacity.
	da->cap = da->cap * 2;

	// Reallocating memory.
	Country* newptr = realloc(da->ptrarr, da->cap * sizeof(Country));

	// Pointing to bigger array.
	da->ptrarr = newptr;
}

void Destroy(DynamicArray* da)
{
	// Frees the space
	free(da->ptrarr);
}