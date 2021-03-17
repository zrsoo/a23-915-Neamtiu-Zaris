#pragma once
#include "Service.h"
#include <assert.h>

typedef struct {
	Service service;

	int nrCountries;
	Country* pc;
}Test;

Test createTest(Repository* repo, UndoManager* um, Service s);
void testAdd(Test t);
void testDelete(Test t);
void testUpdate(Test t);
void testFilterByContinent(Test t);
void testFilterByName(Test t);
void testMigration(Test t);
void testFilterByContinentAsc(Test t);
void runTests();